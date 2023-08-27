#pragma once

#include "precompiled_header.h"

namespace BoolkaEngine::TaskSystem {

class TaskSystem;

struct Task {
  void (*entrypoint)(TaskSystem*, void*);
  void* user_data;
};
}  // namespace BoolkaEngine::TaskSystem
