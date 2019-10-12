#define BOOST_TEST_MODULE MyTest
#include "boost/test/unit_test.hpp"
//#include "..//Learn_Game/TibiaGameObiect.h"
#include "../Learn_Game/TibiaGameObiect.h"
BOOST_AUTO_TEST_CASE(my_boost_test)
{
	TGC::GameObiect go;
	TGC::GameObiect go1;
	BOOST_CHECK(go.getID() == 0);
	BOOST_CHECK(go1.getID() == 1);
}