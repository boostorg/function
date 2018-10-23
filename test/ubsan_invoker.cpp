#include <boost/function.hpp>

BOOST_SYMBOL_IMPORT boost::function<void()> get_foo();

int main()
{
    get_foo()();
}
