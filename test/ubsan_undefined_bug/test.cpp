#define BOOST_TEST_MAIN
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( ubsan_tests )

BOOST_AUTO_TEST_CASE( test1 )
{
    BOOST_CHECK(true);
}

BOOST_AUTO_TEST_SUITE_END()
