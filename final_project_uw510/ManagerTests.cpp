#include "Manager.h"
#include "TestHarness.h"

TEST(setter, Manager)
{
	Manager sam(1, "Sam", "sam@email.com", "password");
	CHECK_EQUAL("Sam", sam.getName());
	
	sam.setName("Samuel");
	CHECK_EQUAL("Samuel", sam.getName());
}

TEST(checkAdmin, Manager)
{
	const Manager sam(1, "Sam", "sam@email.com", "password");
	CHECK(sam.getAdmin());
}