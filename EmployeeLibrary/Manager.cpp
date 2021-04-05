#include "Manager.h"

Manager::Manager(const unsigned int id, std::string name, std::string email, std::string password)
 : Employee(id, std::move(name), std::move(email), std::move(password))
{
	setAdmin();
}

Manager& Manager::operator=(Manager&& rhs) noexcept
{
	Employee::swap(rhs);
	departments_.swap(rhs.departments_);
	return *this;
}

Manager::Manager(Manager&& src) noexcept
	: Employee(std::move(src)), departments_(std::move(src.departments_))
{
}

std::shared_ptr<Department> Manager::getDepartment(const std::string& department)
{
	for(const auto& d : departments_)
	{
		if(department == d->getName())
		{
			return d;
		}
	}
	return std::make_shared<Department>(department);
}

void Manager::addEmployee(const unsigned int id, const std::string& name, const std::string& email, const std::string& password, const std::string& name_of_department) const
{
	for(const auto& d : departments_)
	{
		if(d->getName() == name_of_department)
		{
			d->createEmployee(id, name, email, password);
		}
	}
}

void Manager::createDepartment(std::string name)
{
	auto new_department = std::make_shared<Department>(std::move(name));
	departments_.push_back(std::move(new_department));
}

void Manager::addDepartment(Department& department)
{
	auto department_shared = std::make_shared<Department>(department.getName());
	departments_.push_back(std::move(department_shared));
}
