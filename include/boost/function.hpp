// Boost.Function library

//  Copyright Douglas Gregor 2001-2003. Use, modification and
//  distribution is subject to the Boost Software License, Version
//  1.0. (See accompanying file LICENSE_1_0.txt or copy at
//  http://www.boost.org/LICENSE_1_0.txt)

// For more information, see http://www.boost.org/libs/function

// William Kempf, Jesse Jones and Karl Nelson were all very helpful in the
// design of this library.

#include <boost/function/detail/config.hpp>

#if !BOOST_FUNCTION_ENABLE_CXX03

#ifndef BOOST_FUNCTION_HPP_INCLUDED
#define BOOST_FUNCTION_HPP_INCLUDED

#include <boost/ref.hpp>
#include <boost/function_equal.hpp>
#include <functional>
#include <type_traits>

namespace boost
{

#define BOOST_FUNCTION_TARGET_FIX(x)

using std::bad_function_call;

template<class S> class function: public std::function<S>
{
public:

    function() = default;

    function(function const&) = default;
    function(function&&) = default;

    using std::function<S>::function;

    template<class T> function( boost::reference_wrapper<T> rt ): std::function<S>( std::ref( rt.get() ) )
    {
    }

    function& operator=( function const& r ) = default;
    function& operator=( function&& r ) = default;

    template<class S2> function& operator=( function<S2> const& r )
    {
        std::function<S>::operator=( static_cast< std::function<S2> const& >( r ) );
        return *this;
    }

    template<class S2> function& operator=( function<S2>&& r )
    {
        std::function<S>::operator=( static_cast< std::function<S2>&& >( r ) );
        return *this;
    }

    template<class F, class E = typename std::enable_if< !std::is_integral<F>::value && !std::is_same<F, function>::value >::type > function& operator=( F f )
    {
        std::function<S>::operator=( std::move( f ) );
        return *this;
    }

    function& operator=( std::nullptr_t f )
    {
        std::function<S>::operator=( f );
        return *this;
    }

    template<class T> function& operator=( boost::reference_wrapper<T> rt )
    {
        std::function<S>::operator=( std::ref( rt.get() ) );
        return *this;
    }

    bool empty() const noexcept
    {
        return ! *this;
    }

    void clear()
    {
        *this = nullptr;
    }

    template<class F, class A> void assign( F f, A )
    {
        this->operator=( std::move( f ) );
    }

    template<class F> F * target() noexcept
    {
        if( F * p = std::function<S>::template target<F>() )
        {
            return p;
        }

        if( std::reference_wrapper<F> * p = std::function<S>::template target< std::reference_wrapper<F> >() )
        {
            return std::addressof( p->get() );
        }

        return nullptr;
    }

    template<class F> F const * target() const noexcept
    {
        if( F const * p = std::function<S>::template target<F>() )
        {
            return p;
        }

        if( std::reference_wrapper<F> const * p = std::function<S>::template target< std::reference_wrapper<F> >() )
        {
            return std::addressof( p->get() );
        }

        return nullptr;
    }

    template<class F> bool contains( F const& f ) const noexcept
    {
        if( F const * fp = this->template target<F>() )
        {
            return function_equal( *fp, f );
        }
        else
        {
            return false;
        }
    }
};

template<class S, class F, class E = typename std::enable_if< !std::is_integral<F>::value && !std::is_same<F, std::nullptr_t>::value>::type> inline bool operator==( function<S> const & g, F f )
{
    return g.contains( f );
}

template<class S, class F, class E = typename std::enable_if< !std::is_integral<F>::value && !std::is_same<F, std::nullptr_t>::value>::type> inline bool operator!=( function<S> const & g, F f )
{
    return !g.contains( f );
}

template<class S, class F> inline bool operator==( function<S> const & g, boost::reference_wrapper<F> rf )
{
    return g.template target<F>() == std::addressof( rf.get() );
}

template<class S, class F> inline bool operator!=( function<S> const & g, boost::reference_wrapper<F> rf )
{
    return g.template target<F>() != std::addressof( rf.get() );
}

template<class S, class F, class E = typename std::enable_if< !std::is_integral<F>::value && !std::is_same<F, std::nullptr_t>::value>::type> inline bool operator==( F f, function<S> const & g )
{
    return g.contains( f );
}

template<class S, class F, class E = typename std::enable_if< !std::is_integral<F>::value && !std::is_same<F, std::nullptr_t>::value>::type> inline bool operator!=( F f, function<S> const & g )
{
    return !g.contains( f );
}

template<class S, class F> inline bool operator==( boost::reference_wrapper<F> rf, function<S> const & g )
{
    return g.template target<F>() == std::addressof( rf.get() );
}

template<class S, class F> inline bool operator!=( boost::reference_wrapper<F> rf, function<S> const & g )
{
    return g.template target<F>() != std::addressof( rf.get() );
}

namespace detail
{

template<class T1, class T2> struct is_similar
{
    BOOST_STATIC_CONSTANT( bool, value = false );
};

template<template<class...> class L, class... T1, class... T2> struct is_similar< L<T1...>, L<T2...> >
{
    BOOST_STATIC_CONSTANT( bool, value = true );
};

} // namespace detail

#define BOOST_FUNCTION_N_COMMON \
\
    using base_type::base_type;\
\
    template<class F, class E = typename std::enable_if< !std::is_integral<F>::value && !detail::is_similar<F, this_type>::value >::type > this_type& operator=( F f )\
    {\
        base_type::operator=( std::move( f ) );\
        return *this;\
    }\
\
    this_type& operator=( std::nullptr_t f )\
    {\
        base_type::operator=( f );\
        return *this;\
    }\
\
    template<class S2> this_type& operator=( boost::function<S2> const& r )\
    {\
        base_type::operator=( r );\
        return *this;\
    }\
\
    template<class S2> this_type& operator=( boost::function<S2>&& r )\
    {\
        base_type::operator=( std::move( r ) );\
        return *this;\
    }

template<typename R> class function0: public function<R()>
{
private:

    typedef function0 this_type;
    typedef function<R()> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1> class function1: public function<R(T1)>
{
private:

    typedef function1 this_type;
    typedef function<R(T1)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2> class function2: public function<R(T1, T2)>
{
private:

    typedef function2 this_type;
    typedef function<R(T1, T2)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3> class function3: public function<R(T1, T2, T3)>
{
private:

    typedef function3 this_type;
    typedef function<R(T1, T2, T3)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4> class function4: public function<R(T1, T2, T3, T4)>
{
private:

    typedef function4 this_type;
    typedef function<R(T1, T2, T3, T4)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5> class function5: public function<R(T1, T2, T3, T4, T5)>
{
private:

    typedef function5 this_type;
    typedef function<R(T1, T2, T3, T4, T5)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6> class function6: public function<R(T1, T2, T3, T4, T5, T6)>
{
private:

    typedef function6 this_type;
    typedef function<R(T1, T2, T3, T4, T5, T6)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7> class function7: public function<R(T1, T2, T3, T4, T5, T6, T7)>
{
private:

    typedef function7 this_type;
    typedef function<R(T1, T2, T3, T4, T5, T6, T7)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8> class function8: public function<R(T1, T2, T3, T4, T5, T6, T7, T8)>
{
private:

    typedef function8 this_type;
    typedef function<R(T1, T2, T3, T4, T5, T6, T7, T8)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9> class function9: public function<R(T1, T2, T3, T4, T5, T6, T7, T8, T9)>
{
private:

    typedef function9 this_type;
    typedef function<R(T1, T2, T3, T4, T5, T6, T7, T8, T9)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename T1, typename T2, typename T3, typename T4, typename T5, typename T6, typename T7, typename T8, typename T9, typename T10> class function10: public function<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)>
{
private:

    typedef function10 this_type;
    typedef function<R(T1, T2, T3, T4, T5, T6, T7, T8, T9, T10)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

template<typename R, typename... A> class function30: public function<R(A...)>
{
private:

    typedef function30 this_type;
    typedef function<R(A...)> base_type;

public:

	BOOST_FUNCTION_N_COMMON
};

} // namespace boost

#endif // #ifndef BOOST_FUNCTION_HPP_INCLUDED

#else

#ifndef BOOST_FUNCTION_MAX_ARGS
#  define BOOST_FUNCTION_MAX_ARGS 10
#endif // BOOST_FUNCTION_MAX_ARGS

#if !defined(BOOST_FUNCTION_MAX_ARGS_DEFINED) || (BOOST_FUNCTION_MAX_ARGS_DEFINED != BOOST_FUNCTION_MAX_ARGS)

#if !defined(BOOST_FUNCTION_MAX_ARGS_DEFINED)
#define BOOST_FUNCTION_MAX_ARGS_DEFINED 0
#endif

#include <functional> // unary_function, binary_function

#include <boost/preprocessor/iterate.hpp>
#include <boost/config/workaround.hpp>

// Include the prologue here so that the use of file-level iteration
// in anything that may be included by function_template.hpp doesn't break
#include <boost/function/detail/prologue.hpp>

// Older Visual Age C++ version do not handle the file iteration well
#if BOOST_WORKAROUND(__IBMCPP__, >= 500) && BOOST_WORKAROUND(__IBMCPP__, < 800)
#  if BOOST_FUNCTION_MAX_ARGS >= 0
#    include <boost/function/function0.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 1
#    include <boost/function/function1.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 2
#    include <boost/function/function2.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 3
#    include <boost/function/function3.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 4
#    include <boost/function/function4.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 5
#    include <boost/function/function5.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 6
#    include <boost/function/function6.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 7
#    include <boost/function/function7.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 8
#    include <boost/function/function8.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 9
#    include <boost/function/function9.hpp>
#  endif
#  if BOOST_FUNCTION_MAX_ARGS >= 10
#    include <boost/function/function10.hpp>
#  endif
#else
// What is the '3' for?
#  define BOOST_PP_ITERATION_PARAMS_1 (3,(0,BOOST_FUNCTION_MAX_ARGS,<boost/function/detail/function_iterate.hpp>))
#  include BOOST_PP_ITERATE()
#  undef BOOST_PP_ITERATION_PARAMS_1
#endif

#endif // !defined(BOOST_FUNCTION_MAX_ARGS_DEFINED) || (BOOST_FUNCTION_MAX_ARGS_DEFINED != BOOST_FUNCTION_MAX_ARGS)

#endif
