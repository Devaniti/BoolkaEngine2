
#define BLK_DEBUG

#ifdef BLK_DEBUG
#define BLK_ENABLE_ASSERTS
#endif

#ifdef BLK_ENABLE_ASSERTS
#include <cassert>

#define BLK_ASSERT(a) (assert((a)))
#else
#define BLK_ASSERT(a)
#endif
