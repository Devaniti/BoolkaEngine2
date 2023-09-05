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
#define NOCRYPT
#define NOMINMAX
#define WIN32_LEAN_AND_MEAN
#include <Windows.h>
#undef NOGDI
#undef NOCRYPT
#undef NOMINMAX
#undef WIN32_LEAN_AND_MEAN

#ifdef CONST
#undef CONST
#endif

#include "helpers.h"
#include "math_vector.h"
