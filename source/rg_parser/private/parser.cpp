#include "precompiled_header.h"

#include "parser.h"

namespace BoolkaEngine::RGParser {

class ParserInternal {
 public:
  ParserInternal();
  ~ParserInternal() = default;

  ParserInternal(const ParserInternal& other) = delete;
  ParserInternal(ParserInternal&& other) = delete;
  ParserInternal& operator=(const ParserInternal& other) = delete;
  ParserInternal& operator=(ParserInternal&& other) = delete;

  [[nodiscard]] Element* Parse(const MemoryManager::MemoryBlock& data,
                               Allocator::LinearAllocator& allocator);

 private:
  size_t ParseIndentation();
  void SkipToWhitespace();
  void SkipWhitespace();
  void SkipToNewLine();
  void SkipNewLine();

  static char* Substring(Allocator::LinearAllocator& allocator,
                         const char* src_begin, const char* src_end);

  void ParseLine(Allocator::LinearAllocator& allocator);
  void SwitchLevel(Allocator::LinearAllocator& allocator, size_t level);
  void WriteSubelements(Allocator::LinearAllocator& allocator, size_t level);
  void PushElement(Element* element);

  struct NestingLevel {
    Element* element;
    std::vector<Element*> subelements_list;

    NestingLevel() = default;
    explicit NestingLevel(Element* element);
  };

  std::vector<NestingLevel> elements_stack_;

  const char* begin_{nullptr};
  const char* end_{nullptr};
  const char* i_{nullptr};
};

ParserInternal::NestingLevel::NestingLevel(Element* element)
    : element(element) {
  subelements_list.reserve(8);
}

ParserInternal::ParserInternal() = default;

Element* ParserInternal::Parse(const MemoryManager::MemoryBlock& data,
                               Allocator::LinearAllocator& allocator) {
  auto* root_element = allocator.Emplace<Element>();
  root_element->field = "";
  root_element->value = "";

  elements_stack_.reserve(8);
  elements_stack_.emplace_back(root_element);

  begin_ = static_cast<const char*>(data.data);
  end_ = begin_ + data.size;
  i_ = begin_;

  while (i_ < end_) {
    ParseLine(allocator);
  }

  SwitchLevel(allocator, 0);

  return root_element;
}

size_t ParserInternal::ParseIndentation() {
  size_t result = 0;
  while (i_ < end_ && *i_ == '\t') {
    ++result;
    ++i_;
  }
  return result;
}

void ParserInternal::SkipToWhitespace() {
  while (i_ < end_ && !std::isspace(*i_)) {
    ++i_;
  }
}

void ParserInternal::SkipWhitespace() {
  while (i_ < end_ && std::isspace(*i_)) {
    ++i_;
  }
}

void ParserInternal::SkipToNewLine() {
  while (i_ < end_ && *i_ != '\r' && *i_ != '\n') {
    ++i_;
  }
}

void ParserInternal::SkipNewLine() {
  while (i_ < end_ && (*i_ == '\r' || *i_ == '\n')) {
    ++i_;
  }
}

char* ParserInternal::Substring(Allocator::LinearAllocator& allocator,
                                const char* src_begin, const char* src_end) {
  char* result =
      static_cast<char*>(allocator.Allocate(src_end - src_begin + 1));
  std::memcpy(result, src_begin, src_end - src_begin);
  result[src_end - src_begin] = '\0';
  return result;
}

void ParserInternal::ParseLine(Allocator::LinearAllocator& allocator) {
  size_t indentation = ParseIndentation();

  const char* field_begin = i_;
  SkipToWhitespace();
  const char* field_end = i_;
  SkipWhitespace();
  const char* value_begin = i_;
  SkipToNewLine();
  const char* value_end = i_;
  SkipNewLine();

  auto* new_element = allocator.Emplace<Element>();
  new_element->field = Substring(allocator, field_begin, field_end);
  new_element->value = Substring(allocator, value_begin, value_end);

  SwitchLevel(allocator, indentation + 1);
  PushElement(new_element);
}

void ParserInternal::SwitchLevel(Allocator::LinearAllocator& allocator,
                                 size_t level) {
  BLK_ASSERT(level <= elements_stack_.size() + 1);
  for (size_t i = level; i < elements_stack_.size(); ++i) {
    WriteSubelements(allocator, i);
  }
  elements_stack_.resize(level);
}

void ParserInternal::WriteSubelements(Allocator::LinearAllocator& allocator,
                                      size_t level) {
  NestingLevel& level_data = elements_stack_[level];
  size_t subelement_count = level_data.subelements_list.size();
  auto** subelement_array = static_cast<Element**>(
      allocator.Allocate(sizeof(Element*) * (subelement_count + 1)));
  std::copy(level_data.subelements_list.begin(),
            level_data.subelements_list.end(), subelement_array);
  subelement_array[subelement_count] = nullptr;
  level_data.element->subelements = subelement_array;
}

void ParserInternal::PushElement(Element* element) {
  elements_stack_.back().subelements_list.push_back(element);
  elements_stack_.emplace_back(element);
}

Element* Parser::Parse(const MemoryManager::MemoryBlock& data,
                       Allocator::LinearAllocator& allocator) {
  ParserInternal parser;
  return parser.Parse(data, allocator);
}

}  // namespace BoolkaEngine::RGParser
