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
#ifndef BOOST_THREAD_MODEL_PER_CLASS_HPP
#define BOOST_THREAD_MODEL_PER_CLASS_HPP

#include <boost/thread/mutex.hpp>
#include <boost/thread/model/detail/mutex_mixin.hpp>

namespace boost {

  template<typename Mutex = boost::mutex>
  struct per_class_locking
  {
    typedef detail::static_mutex_mixin<Mutex> mixin;
    typedef typename Mutex::scoped_lock lock;
  };

} // end namespace boost

#endif // BOOST_THREAD_MODEL_PER_CLASS_HPP
