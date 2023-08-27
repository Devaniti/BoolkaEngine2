#pragma once

#include <bit>
#include <cctype>
#include <cstdint>
#include <filesystem>
#include <fstream>
#include <ios>
#include <queue>
#include <vector>

// Special windows specific stuff
#define NOGDI
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef NOGDI
#undef NOMINMAX
#undef WIN32_LEAN_AND_MEAN

#include "helpers.h"
#include "math_vector.h"
