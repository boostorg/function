// Copyright (C) 2002
// Doug Gregor (gregod@cs.rpi.edu)
//
// Permission to use, copy, modify, distribute and sell this software
// and its documentation for any purpose is hereby granted without fee,
// provided that the above copyright notice appear in all copies and
// that both that copyright notice and this permission notice appear
// in supporting documentation.  William E. Kempf makes no representations
// about the suitability of this software for any purpose.
// It is provided "as is" without express or implied warranty.
#ifndef BOOST_THREAD_MODEL_DETAIL_MUTEX_MIXIN_HPP
#define BOOST_THREAD_MODEL_DETAIL_MUTEX_MIXIN_HPP

namespace boost {
namespace detail {

template<typename Mutex>
class mutex_mixin
{
public:
  mutex_mixin(const mutex_mixin&) {}
  mutex_mixin& operator=(const mutex_mixin&) { return *this; }

  operator const Mutex&() const { return mutex; }
  operator Mutex&() { return mutex; }

private:
  Mutex mutex;
};

template<typename Mutex>
class static_mutex_mixin
{
public:
  static_mutex_mixin(const mutex_mixin&) {}
  static_mutex_mixin& operator=(const mutex_mixin&) { return *this; }

  operator const Mutex&() const { return mutex; }
  operator Mutex&() { return mutex; }

private:
  static Mutex mutex;
};

} // end namespace detail
} // end namespace boost

#endif // BOOST_THREAD_MODEL_DETAIL_MUTEX_MIXIN_HPP
