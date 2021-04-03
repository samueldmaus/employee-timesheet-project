#include "Employee.h"
#include "TestHarness.h"

TEST(constructor, Employee)
{
	const Employee sam(1, "Sam", "sam@email.com", "password");
	CHECK_EQUAL("Sam", sam.getName());
}

TEST(setter, Employee)
{
	Employee sam(1, "Sam", "sam@email.com", "password");
	sam.setEmail("maus@email.com");
	CHECK_EQUAL("maus@email.com", sam.getEmail());
}