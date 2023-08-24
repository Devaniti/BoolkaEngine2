#pragma once

namespace RGParser {

// This struct does not own memory
struct Element {
  const char* field;
  const char* value;
  // Null terminated array
  Element** subelements;
};

}  // namespace RGParser
