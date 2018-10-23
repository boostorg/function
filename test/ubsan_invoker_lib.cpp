#include <boost/function.hpp>
#include <boost/config.hpp>

BOOST_SYMBOL_EXPORT void foo() {}

BOOST_SYMBOL_EXPORT boost::function<void()> get_foo()
{
    return boost::function<void()>(foo);
}
