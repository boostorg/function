// Boost.Function library

// Copyright (C) 2001-2002 Doug Gregor (gregod@cs.rpi.edu)
//
// Permission to copy, use, sell and distribute this software is granted
// provided this copyright notice appears in all copies.
// Permission to modify the code and to distribute modified code is granted
// provided this copyright notice appears in all copies, and a notice
// that the code was modified is included with the copyright notice.
//
// This software is provided "as is" without express or implied warranty,
// and with no claim as to its suitability for any purpose.
 
// For more information, see http://www.boost.org
 
// William Kempf, Jesse Jones and Karl Nelson were all very helpful in the
// design of this library.

#ifndef BOOST_FUNCTION_HPP
#define BOOST_FUNCTION_HPP

#include <boost/function/function_base.hpp>
#include <boost/function/function0.hpp>
#include <boost/function/function1.hpp>
#include <boost/function/function2.hpp>
#include <boost/function/function3.hpp>
#include <boost/function/function4.hpp>
#include <boost/function/function5.hpp>
#include <boost/function/function6.hpp>
#include <boost/function/function7.hpp>
#include <boost/function/function8.hpp>
#include <boost/function/function9.hpp>
#include <boost/function/function10.hpp>

namespace boost {
  namespace detail {
    namespace function {
      // Choose the appropriate underlying implementation
      template<int Args> struct real_get_function_impl {};

      template<>
      struct real_get_function_impl<0>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function0<R, ThreadingPolicy, Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<1>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function1<R, T1, ThreadingPolicy, Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<2>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function2<R, T1, T2, ThreadingPolicy, Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<3>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function3<R, T1, T2, T3, ThreadingPolicy, Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<4>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function4<R, T1, T2, T3, T4, ThreadingPolicy, Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<5>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function5<R, T1, T2, T3, T4, T5, ThreadingPolicy, Allocator> 
          type;
        };
      };

      template<>
      struct real_get_function_impl<6>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function6<R, T1, T2, T3, T4, T5, T6, ThreadingPolicy, Allocator>
          type;
        };
      };

      template<>
      struct real_get_function_impl<7>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function7<R, T1, T2, T3, T4, T5, T6, T7, ThreadingPolicy, 
                            Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<8>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function8<R, T1, T2, T3, T4, T5, T6, T7, T8, ThreadingPolicy, 
                            Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<9>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function9<R, T1, T2, T3, T4, T5, T6, T7, T8, T9, 
                            ThreadingPolicy, Allocator> type;
        };
      };

      template<>
      struct real_get_function_impl<10>
      {
        template<
          typename R, 
          typename T1,
          typename T2,
          typename T3,
          typename T4,
          typename T5,
          typename T6,
          typename T7,
          typename T8,
          typename T9,
          typename T10,
          typename ThreadingPolicy,
          typename Allocator
        >
        struct params
        {
          typedef function10<R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, 
                             ThreadingPolicy, Allocator> type;
        };
      };

      template<
        typename R, 
        typename T1, 
        typename T2, 
        typename T3, 
        typename T4,
        typename T5, 
        typename T6, 
        typename T7, 
        typename T8, 
        typename T9,
        typename T10,
        typename ThreadingPolicy = BOOST_FUNCTION_DEFAULT_THREADING_POLICY,
        typename Allocator = BOOST_FUNCTION_DEFAULT_ALLOCATOR 
      >
      struct get_function_impl
      {
        typedef typename real_get_function_impl<
          (count_used_args<T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>::value)
          >::template params<R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10, 
                             ThreadingPolicy, Allocator>::type
        type;
      };

  template<
    typename R, 
    typename T1, 
    typename T2, 
    typename T3, 
    typename T4,
    typename T5, 
    typename T6, 
    typename T7, 
    typename T8, 
    typename T9,
    typename T10,
    typename MyThreadingPolicy = BOOST_FUNCTION_DEFAULT_THREADING_POLICY,
    typename MyAllocator = BOOST_FUNCTION_DEFAULT_ALLOCATOR 
  >
  struct function_traits_builder
  {
    typedef typename get_function_impl<R, T1, T2, T3, T4, T5, T6, T7, 
                                       T8, T9, T10, MyThreadingPolicy,
                                       MyAllocator>::type
      type;

    typedef MyThreadingPolicy threading_policy_type;
    typedef MyAllocator allocator_type;

#ifndef BOOST_NO_DEPENDENT_NESTED_DERIVATIONS
    template<typename ThreadingPolicy>
    struct threading_policy : 
        public function_traits_builder<R, T1, T2, T3, T4, T5, T6, T7, T8, T9,
                                       T10, ThreadingPolicy,
                                       allocator_type> {};

    template<typename Allocator>
    struct allocator : 
        public function_traits_builder<R, T1, T2, T3, T4, T5, T6, T7, T8, T9,
                                       T10, threading_policy_type,
                                       Allocator> {};
#else
    template<typename ThreadingPolicy>
    struct threading_policy 
    {
      typedef typename function_traits_builder<R, T1, T2, T3, T4, T5, T6, T7,
                                               T8, T9, T10, ThreadingPolicy, 
                                               allocator_type>::type
        type;
    };

    template<typename Allocator>
    struct allocator
    {
      typedef typename function_traits_builder<R, T1, T2, T3, T4, T5, T6, T7,
                                               T8, T9, T10, 
                                               threading_policy_type, 
                                               Allocator>::type
        type;
    };
#endif
  };

    } // end namespace function
  } // end namespace detail

  template<
    typename R, 
    typename T1 = detail::function::unusable, 
    typename T2 = detail::function::unusable,
    typename T3 = detail::function::unusable,
    typename T4 = detail::function::unusable,
    typename T5 = detail::function::unusable,
    typename T6 = detail::function::unusable,
    typename T7 = detail::function::unusable,
    typename T8 = detail::function::unusable,
    typename T9 = detail::function::unusable,
    typename T10 = detail::function::unusable
  >
  class function :
    public detail::function::get_function_impl<R, T1, T2, T3, T4, T5, T6, T7, 
                                               T8, T9, T10>::type,
    public detail::function::function_traits_builder<R, T1, T2, T3, T4, T5, T6,
                                                     T7, T8, T9, T10>
  {
    typedef typename detail::function::get_function_impl<R, T1, T2, T3, T4, T5,
                                                         T6, T7, T8, T9, T10
                                                         >::type 
      base_type;

  public:
    typedef typename base_type::threading_policy_type policy_type;
    typedef typename base_type::allocator_type allocator_type;              
    typedef function self_type;                                     
                                                                            
    function() : base_type() {}                                     
                                                                            
    template<typename Functor>                                              
    function(Functor BOOST_FUNCTION_TARGET_FIX(const &) f) : base_type(f) {}
                      
    function(const self_type& f) : base_type(static_cast<const base_type&>(f)){}
         
    template<typename Functor>
    self_type& operator=(Functor BOOST_FUNCTION_TARGET_FIX(const &) f)
    {
      base_type::operator=(f);
      return *this;
    }

    self_type& operator=(const base_type& f)
    {
      base_type::operator=(f);
      return *this;
    }

    self_type& operator=(const self_type& f)
    {   
      base_type::operator=(static_cast<const base_type&>(f));
      return *this;
    }
  };

  template<typename R,
           typename T1, 
           typename T2,
           typename T3,
           typename T4,
           typename T5,
           typename T6,
           typename T7,
           typename T8,
           typename T9,
           typename T10>
  inline void swap(function<R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>& f1,
                   function<R, T1, T2, T3, T4, T5, T6, T7, T8, T9, T10>& f2)
  {
    f1.swap(f2);
  }
}

#endif
