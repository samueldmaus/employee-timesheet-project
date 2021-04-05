#include "Department.h"
#include "TestHarness.h"

TEST(getter, Department)
{
	const Department account("Accounting");

	CHECK_EQUAL("Accounting", account.getName());
}

TEST(addRemove, Department)
{
	Department account("Accounting");
	account.createEmployee(1, "sam", "sam@email.com", "password");
	size_t size = 1;
	CHECK_EQUAL(size, account.size());

	account.remove();
	size = 0;
	CHECK_EQUAL(size, account.size());
}
