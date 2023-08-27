#pragma once

namespace BoolkaEngine::RGParser {

// This struct does not own memory
struct Element {
  const char* field;
  const char* value;
  // Null terminated array
  Element** subelements;
};

}  // namespace BoolkaEngine::RGParser
