// Boost.Function library

// Copyright (C) 2001 Doug Gregor (gregod@cs.rpi.edu)
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
// Note: this header is a header template and must NOT have multiple-inclusion
// protection. 

#ifdef BOOST_COMPILER_HOOKS

#ifndef BOOST_FUNCTION_ERRORS_HPP
#  include <boost/config.hpp>
#  include <boost/preprocessor/enum_params.hpp>
#  include <boost/preprocessor/stringize.hpp>
#  include <ext/compiler>
#endif // BOOST_FUNCTION_ERRORS_HPP

#define BOOST_F_BAD_ARGS \
  BOOST_PP_CAT(incompatible_args_msg,BOOST_FUNCTION_NUM_ARGS)

#define BOOST_F_CHECK_ARGS \
  BOOST_PP_CAT(check_args,BOOST_FUNCTION_NUM_ARGS)

#define BOOST_F_BAD_RETURN \
  BOOST_PP_CAT(incompatible_return_msg,BOOST_FUNCTION_NUM_ARGS)

#define BOOST_F_CHECK_RETURN \
  BOOST_PP_CAT(check_return,BOOST_FUNCTION_NUM_ARGS)

#define BOOST_F_CHECK_TARGET \
  BOOST_PP_CAT(check_target,BOOST_FUNCTION_NUM_ARGS)

// Comma if nonzero number of arguments
#define BOOST_F_COMMA BOOST_PP_COMMA_IF(BOOST_FUNCTION_NUM_ARGS)

#define BOOST_F_TYPE_PLACEHOLDER(I,P) \
  BOOST_PP_IF(I, ", ",) BOOST_PP_STRINGIZE(%t)

#define BOOST_F_ARG_TYPE(I,P) \
  BOOST_PP_COMMA_IF(I) arg< type<T##I> 

#define BOOST_F_CLOSE_TMPL(I, P) >

namespace boost {
  namespace detail {
    namespace function {
#ifndef BOOST_FUNCTION_ERRORS_HPP
      template<bool> struct truth {};
      template<int> struct int_value {};

      using __gnu_cxx::arg;
      using __gnu_cxx::type;
      using __gnu_cxx::can_instantiate;
      using __gnu_cxx::error;

      template<typename T, void (T::*p)()>
      struct pmf {};

      template<typename Constraint>
      struct constraint {
        typedef pmf<Constraint, &Constraint::constraints> force;
      };

      template<bool, typename Error> struct maybe_emit_error;
      template<typename Error> struct maybe_emit_error<true, Error> {};

      template<typename Error> 
      struct maybe_emit_error<false, Error> {
        BOOST_STATIC_CONSTANT(int, junk = sizeof(Error));
      };
      
      // Check the given constraint. If it is not satisfied, emit an error
      // message suppressing N instantiation levels (not including the levels
      // deeper than this instantiation).
      template<typename Constraint, int N = 0>
      struct check_constraint
      {
        // True if the constraint is met
        BOOST_STATIC_CONSTANT(bool, 
                              value = can_instantiate<constraint<Constraint> >
                                        ::value);
      private:
        // Possibly emit an error message
        typedef typename Constraint::msg error_msg;
        typedef typename error_msg::args error_msg_args;
        typedef error<error_msg, error_msg_args, N+2> actual_error;
        typedef maybe_emit_error<value, actual_error> possible_error;
        BOOST_STATIC_CONSTANT(int, junk = sizeof(possible_error));
      };

      // Help suppress redundant error messages
      template<bool, typename Check> struct maybe_check;

      template<typename Check>
      struct maybe_check<false, Check>
      {
        BOOST_STATIC_CONSTANT(bool, value = false);
      };

      template<typename Check>
      struct maybe_check<true, Check>
      {
        BOOST_STATIC_CONSTANT(bool, value = Check::value);
      };

#endif // !BOOST_FUNCTION_ERRORS_HPP

      // Error message when the arguments are not compatible
      template<typename F BOOST_F_COMMA BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T)>
      struct BOOST_F_BAD_ARGS {
        // Construct the argument list
        typedef arg<type<F> BOOST_F_COMMA BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS, BOOST_F_ARG_TYPE, x) BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS, BOOST_F_CLOSE_TMPL, x) > args;

        // The error message text
        static const char* text;
      };

#if BOOST_FUNCTION_NUM_ARGS == 0
      template<typename F>
      const char* BOOST_F_BAD_ARGS<F>::text 
        = "objects of type '%t' cannot be invoked with no arguments";
#else
      // Construct the error message when arguments are not compatible
      template<typename F BOOST_F_COMMA BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T)>
      const char* BOOST_F_BAD_ARGS<
                    F BOOST_F_COMMA
                    BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T)>
        ::text = "objects of type '%t' cannot be invoked with Boost.Function "
                 "argument types '("
                 BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS,
                                 BOOST_F_TYPE_PLACEHOLDER,x)
                 ")'";
#endif // BOOST_FUNCTION_NUM_ARGS != 0

      // Concept check to determine if argument types are compatible
      template<typename F BOOST_F_COMMA
               BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T)>
      struct BOOST_F_CHECK_ARGS {
        typedef BOOST_F_BAD_ARGS<F BOOST_F_COMMA BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T)> msg;

        F f;
#define BOOST_F_ARG(I,P) T##I a##I;
        BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS,BOOST_F_ARG,)
#undef BOOST_F_ARG

        void constraints() 
        {
          f(BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,a));
        }
      };

      // Error message when the return types are compatible
      template<typename F, typename R BOOST_F_COMMA
               BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T)>
      struct BOOST_F_BAD_RETURN {
        // Arguments to format the error message
        typedef arg<type<F> BOOST_F_COMMA BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS, BOOST_F_ARG_TYPE, x) , arg<type<R> > BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS, BOOST_F_CLOSE_TMPL, x) > args;

        // Error message text
        static const char* text;
      };

#if BOOST_FUNCTION_NUM_ARGS == 0
      template<typename F, typename R>
      const char* BOOST_F_BAD_RETURN<F, R>::text = 
        "return type when invoking object of type '%t' with no arguments is "
        "not convertible to Boost.Function declared return type '%t'";
#else
      // Construct the error message when return types are not compatible
      template<typename F, typename R BOOST_F_COMMA
               BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T)>
      const char* BOOST_F_BAD_RETURN<
                    F, R BOOST_F_COMMA
                    BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T)>
        ::text = "return type when invoking object of type '%t' with argument"
                 " types '("
                 BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS,
                                 BOOST_F_TYPE_PLACEHOLDER,x)
                 ")' is not convertible to Boost.Function declared return "
                 "type '%t'";
#endif // BOOST_FUNCTION_NUM_ARGS != 0

      // Concept check to determine if return types are compatible
      template<typename F, typename R BOOST_F_COMMA
               BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T)>
      struct BOOST_F_CHECK_RETURN {
        typedef BOOST_F_BAD_RETURN<
                  F, R BOOST_F_COMMA
                  BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T)> msg;

        F f;
#define BOOST_F_ARG(I,P) T##I a##I;
        BOOST_PP_REPEAT(BOOST_FUNCTION_NUM_ARGS,BOOST_F_ARG,)
#undef BOOST_F_ARG

        R foo()
        {
          return f(BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,a));
        }

        void constraints()
        {
          R (BOOST_F_CHECK_RETURN::*p)() = &BOOST_F_CHECK_RETURN::foo;
        }
      };

      template<typename F, typename R BOOST_F_COMMA
               BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,typename T), 
               int N=0>
      struct BOOST_F_CHECK_TARGET {
        typedef check_constraint<BOOST_F_CHECK_ARGS<F BOOST_F_COMMA BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T)>,N+1> check_args;
        typedef check_constraint<BOOST_F_CHECK_RETURN<F, R BOOST_F_COMMA BOOST_PP_ENUM_PARAMS(BOOST_FUNCTION_NUM_ARGS,T)>,N+2> check_return;

        BOOST_STATIC_CONSTANT(bool, args_ok = check_args::value);
        BOOST_STATIC_CONSTANT(bool, 
                              value = 
                                (maybe_check<args_ok, check_return>::value));
      };
    } // end namespace function
  } // end namespace function
} // end namespace function

#undef BOOST_F_COMMA
#undef BOOST_F_BAD_ARGS
#undef BOOST_F_CHECK_ARGS
#undef BOOST_F_BAD_RETURN
#undef BOOST_F_CHECK_RETURN
#undef BOOST_F_CHECK_TARGET
#undef BOOST_F_TYPE_PLACEHOLDER
#undef BOOST_F_ARG_TYPE
#undef BOOST_F_CLOSE_TMPL

#endif // BOOST_COMPILER_HOOKS

// Don't redo work done in the first inclusion
#ifndef BOOST_FUNCTION_ERRORS_HPP
#  define BOOST_FUNCTION_ERRORS_HPP
#endif // BOOST_FUNCTION_ERRORS_HPP
