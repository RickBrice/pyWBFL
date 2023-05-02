// pch.h: This is a precompiled header file.
// Files listed below are compiled only once, improving build performance for future builds.
// This also affects IntelliSense performance, including code completion and many code browsing features.
// However, files listed here are ALL re-compiled if any one of them is updated between builds.
// Do not add files here that you will be updating frequently as this negates the performance advantage.

#ifndef PCH_H
#define PCH_H

// add headers that you want to pre-compile here
#include "framework.h"


// these macros are required for proper linking to the debugging versions of python and the associated boost.python libraries
#if defined _DEBUG
#define BOOST_DEBUG_PYTHON
#define BOOST_LINKING_PYTHON
#endif
#include <boost/python.hpp>

#include <System/System.h>

#endif //PCH_H
