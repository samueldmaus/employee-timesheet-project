#include "Department.h"
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

TEST(clockInOut, Manager)
{
	const Manager sam(1, "Sam", "sam@email.com", "password");
	sam.clockIn();
	sam.clockOut();
	const size_t size = 1;

	CHECK_EQUAL(size, sam.size());
}

TEST(createEmployee, Manager)
{
	Manager sam(1, "Sam", "sam@email.com", "password");
	sam.createDepartment("Accounting");
	sam.addEmployee(2, "Sarah", "sarah@email.com", "password", "Accounting");
	const auto department = sam.getDepartment("Accounting");
	const size_t size = 1;
	CHECK_EQUAL(size, department->size());

	std::stringstream os;
	department->print(os);
	CHECK_EQUAL("Employee: 2, Sarah, sarah@email.com", os.str());
}

TEST(moveAssignment, Manager)
{
	Manager sam(1, "Sam", "sam@email.com", "password");
	sam.createDepartment("Sales");
	
	auto new_sam = std::move(sam);
	const auto department = new_sam.getDepartment("Sales");
	
	CHECK_EQUAL("Sam", new_sam.getName());
	CHECK_EQUAL("Sales", department->getName());
}

TEST(moveConstructor, Manager)
{
	Manager sam(1, "Sam", "sam@email.com", "password");
	auto new_sam(std::move(sam));
	new_sam.setName("Samuel");
	
	CHECK_EQUAL("Samuel", new_sam.getName());
}