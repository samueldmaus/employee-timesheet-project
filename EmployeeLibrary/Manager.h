#ifndef MANAGER_H
#define MANAGER_H

#include "Department.h"
#include "Employee.h"

class Manager : public Employee
{
public:
    Manager(unsigned int id, std::string name, std::string email, std::string password);

	Manager& operator=(Manager&& rhs) noexcept;

	Manager(Manager&& src) noexcept;

	std::shared_ptr<Department> getDepartment(const std::string& department);

	void addEmployee(unsigned int id, const std::string& name, const std::string& email, const std::string& password, const std::string& name_of_department) const;

	void createDepartment(std::string name);

	void addDepartment(Department& department);

private:
	std::vector<std::shared_ptr<Department>> departments_;
};

#endif