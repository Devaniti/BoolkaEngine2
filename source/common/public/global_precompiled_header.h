#pragma once

#include <bit>
#include <cctype>
#include <condition_variable>
#include <cstdint>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <ios>
#include <mutex>
#include <queue>
#include <unordered_map>
#include <vector>

#if defined(_WIN32) || defined(WIN32)
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
#ifdef TRUE
#undef TRUE
#endif
#ifdef FALSE
#undef FALSE
#endif
#elif __unix__
#include <pthread.h>
#include <sched.h>
#include <sys/mman.h>
#include <sys/sysinfo.h>
#include <unistd.h>
#else
#error Unknown platform
#endif

#include "helpers.h"
#include "math_vector.h"
