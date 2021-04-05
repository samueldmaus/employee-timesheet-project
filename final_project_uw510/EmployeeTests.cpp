#include "Employee.h"
#include "TestHarness.h"

TEST(setter, Employee)
{
	Employee sam(1, "Sam", "sam@email.com", "password");
	CHECK_EQUAL("Sam", sam.getName());
	
	sam.setName("Samuel");
	CHECK_EQUAL("Samuel", sam.getName());
}

TEST(checkAdmin, Employee)
{
	const Employee sam(1, "Sam", "sam@email.com", "password");
	CHECK(!sam.getAdmin());
}

TEST(clockInOut, Employee)
{
	const Employee sam(1, "Sam", "sam@email.com", "password");
	sam.clockIn();
	sam.clockOut();
	const size_t size = 1;

	CHECK_EQUAL(size, sam.size());
}

TEST(clockInOut2, Employee)
{
	const Employee sam(1, "Sam", "sam@email.com", "password");
	sam.clockIn();
	sam.clockOut();

	sam.clockIn();
	sam.clockOut();

	const size_t size = 2;

	CHECK_EQUAL(size, sam.size());
}

TEST(moveAssignment, Employee)
{
	Employee sam(1, "Sam", "sam@email.com", "password");
	sam.clockIn();
	sam.clockOut();
	const auto new_sam = std::move(sam);

	const size_t size = 1;
	CHECK_EQUAL("Sam", new_sam.getName());
	CHECK_EQUAL("sam@email.com", new_sam.getEmail());
	CHECK_EQUAL(size, new_sam.size());
}

TEST(moveConstructor, Employee)
{
	Employee sam(1, "Sam", "sam@email.com", "password");
	sam.clockIn();
	sam.clockOut();
	const auto new_sam(std::move(sam));
	
	const size_t size = 1;
	CHECK_EQUAL("Sam", new_sam.getName());
	CHECK_EQUAL("sam@email.com", new_sam.getEmail());
	CHECK_EQUAL(size, new_sam.size());
}
