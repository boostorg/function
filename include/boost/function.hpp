// Boost.Function library

//  Copyright Douglas Gregor 2001-2003. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org/libs/function

// William Kempf, Jesse Jones and Karl Nelson were all very helpful in the
// design of this library.

// No include guards to allow include again with bigger
// BOOST_FUNCTION_MAX_ARGS

#ifndef BOOST_FUNCTION_MAX_ARGS_DEFINED
#  include <boost/function/detail/function_expand.hpp>
#else
#  ifndef BOOST_FUNCTION_MAX_ARGS
#    include <boost/function/detail/function_expand.hpp>
#  else
#    if BOOST_FUNCTION_MAX_ARGS > BOOST_FUNCTION_MAX_ARGS_DEFINED
#      include <boost/function/detail/function_expand.hpp>
#    endif
#  endif
#endif

