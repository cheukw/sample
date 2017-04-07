#pragma once

#include <cassert>

#ifdef _DEBUG
#define ASSERT(exp) assert(exp)

#else
#define ASSERT(exp)

#endif /// _DEBUG


