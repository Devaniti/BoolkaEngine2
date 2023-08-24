#include "precompiled_header.h"

#include "parser.h"

namespace RGParser {

class ParserInternal {
 public:
  ParserInternal();
  ~ParserInternal() = default;

  ParserInternal(const ParserInternal& other) = delete;
  ParserInternal(ParserInternal&& other) = delete;
  ParserInternal& operator=(const ParserInternal& other) = delete;
  ParserInternal& operator=(ParserInternal&& other) = delete;

  [[nodiscard]] Element* Parse(const MemoryManager::MemoryBlock& data,
                               LinearAllocator& allocator);

 private:
  size_t ParseIndentation();
  void SkipToWhitespace();
  void SkipWhitespace();
  void SkipToNewLine();
  void SkipNewLine();

  char* Substring(LinearAllocator& allocator, const char* src_begin,
                  const char* src_end);

  void ParseLine(LinearAllocator& allocator);
  void SwitchLevel(LinearAllocator& allocator, size_t level);
  void WriteSubelements(LinearAllocator& allocator, size_t level);
  void PushElement(Element* element);

  struct NestingLevel {
    Element* element;
    std::vector<Element*> subelements_list;

    NestingLevel() = default;
    NestingLevel(Element* element);
  };

  std::vector<NestingLevel> elements_stack;

  const char* begin;
  const char* end;
  const char* i;
};

ParserInternal::NestingLevel::NestingLevel(Element* element)
    : element(element) {
  subelements_list.reserve(8);
}

ParserInternal::ParserInternal() : begin(nullptr), end(nullptr), i(nullptr) {}

Element* ParserInternal::Parse(const MemoryManager::MemoryBlock& data,
                               LinearAllocator& allocator) {
  Element* root_element = allocator.Emplace<Element>();
  root_element->field = "";
  root_element->value = "";

  elements_stack.reserve(8);
  elements_stack.push_back(root_element);

  begin = (const char*)data.data;
  end = begin + data.size;
  i = begin;

  while (i < end) {
    ParseLine(allocator);
  }

  SwitchLevel(allocator, 0);

  return root_element;
}

size_t ParserInternal::ParseIndentation() {
  size_t result = 0;
  while (i < end && *i == '\t') {
    ++result;
    ++i;
  }
  return result;
}

void ParserInternal::SkipToWhitespace() {
  while (i < end && !std::isspace(*i)) {
    ++i;
  }
}

void ParserInternal::SkipWhitespace() {
  while (i < end && std::isspace(*i)) {
    ++i;
  }
}

void ParserInternal::SkipToNewLine() {
  while (i < end && *i != '\r' && *i != '\n') {
    ++i;
  }
}

void ParserInternal::SkipNewLine() {
  while (i < end && (*i == '\r' || *i == '\n')) {
    ++i;
  }
}

char* ParserInternal::Substring(LinearAllocator& allocator,
                                const char* src_begin, const char* src_end) {
  char* result = (char*)allocator.Allocate(src_end - src_begin + 1);
  std::memcpy(result, src_begin, src_end - src_begin);
  result[src_end - src_begin] = '\0';
  return result;
}

void ParserInternal::ParseLine(LinearAllocator& allocator) {
  size_t indentation = ParseIndentation();

  const char* field_begin = i;
  SkipToWhitespace();
  const char* field_end = i;
  SkipWhitespace();
  const char* value_begin = i;
  SkipToNewLine();
  const char* value_end = i;
  SkipNewLine();

  Element* new_element = allocator.Emplace<Element>();
  new_element->field = Substring(allocator, field_begin, field_end);
  new_element->value = Substring(allocator, value_begin, value_end);

  SwitchLevel(allocator, indentation + 1);
  PushElement(new_element);
}

void ParserInternal::SwitchLevel(LinearAllocator& allocator, size_t level) {
  BLK_ASSERT(level <= elements_stack.size() + 1);
  for (size_t i = level; i < elements_stack.size(); ++i) {
    WriteSubelements(allocator, i);
  }
  elements_stack.resize(level);
}

void ParserInternal::WriteSubelements(LinearAllocator& allocator,
                                      size_t level) {
  NestingLevel& level_data = elements_stack[level];
  size_t subelement_count = level_data.subelements_list.size();
  Element** subelement_array =
      (Element**)allocator.Allocate(sizeof(Element*) * (subelement_count + 1));
  std::copy(level_data.subelements_list.begin(),
            level_data.subelements_list.end(), subelement_array);
  subelement_array[subelement_count] = nullptr;
  level_data.element->subelements = subelement_array;
}

void ParserInternal::PushElement(Element* element) {
  elements_stack.back().subelements_list.push_back(element);
  elements_stack.push_back(element);
}

Element* Parser::Parse(const MemoryManager::MemoryBlock& data,
                       LinearAllocator& allocator) {
  ParserInternal parser;
  return parser.Parse(data, allocator);
}

}  // namespace RGParser
