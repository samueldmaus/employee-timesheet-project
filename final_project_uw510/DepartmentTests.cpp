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

TEST(validateEmployeeTrue, Department)
{
	Department account("Accounting");
	account.createEmployee(1, "Sam", "sam@email.com", "password");
	account.createEmployee(2, "Abby", "abby@email.com", "password");
	account.createEmployee(3, "Zach", "zach@email.com", "password");
	const auto valid = account.validateEmployee(0, 3, "zach@email.com", "password");
	CHECK(valid);
}

TEST(validateEmployeeFalse, Department)
{
	Department account("Accounting");
	account.createEmployee(1, "Sam", "sam@email.com", "password");
	account.createEmployee(2, "Abby", "abby@email.com", "password");
	account.createEmployee(3, "Zach", "zach@email.com", "password");
	const auto valid = account.validateEmployee(0, 3, "zach@email.com", "nottherightpassword");
	CHECK(!valid);
}

TEST(sort, Department)
{
	Department account("Accounting");
	account.createEmployee(1, "Sam", "sam@email.com", "password");
	account.createEmployee(2, "Abby", "abby@email.com", "password");
	account.createEmployee(3, "Zach", "zach@email.com", "password");
	CHECK_EQUAL("Sam", account[0].getName());

	account.sort();
	CHECK_EQUAL("Abby", account[0].getName());
}

TEST(optOverload, Department)
{
	Department account("Accounting");
	account.createEmployee(1, "Sam", "sam@email.com", "password");
	account.createEmployee(2, "Abby", "abby@email.com", "password");
	account.createEmployee(3, "Zach", "zach@email.com", "password");
	account[0].setName("Samuel");

	CHECK_EQUAL("Samuel", account[0].getName());
}