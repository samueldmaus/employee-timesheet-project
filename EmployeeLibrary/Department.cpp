#include "Department.h"

#include <algorithm>

Department::Department(std::string name)
	: name_(std::move(name)), employees_(std::vector<std::unique_ptr<Employee>>())
{
}

const std::string& Department::getName() const
{
    return name_;
}

void Department::add()
{
	employees_.push_back(std::move(new_employee_));
}

void Department::remove()
{
	employees_.pop_back();
}

void Department::print(std::ostream& os) const
{
	if(size() == 1)
	{
		for(const auto& e : employees_)
		{
			os << *e;
		}	
	} else
    {
	    for(const auto& e : employees_)
		{
			os << *e << '\n';
		}	
    }
}

void Department::write()
{

}

void Department::sort()
{
	std::sort(employees_.begin(), employees_.end(), [](const std::unique_ptr<Employee>& a, const std::unique_ptr<Employee>& b)
    {
        return a->getEmail() < b->getEmail();
    });
}

size_t Department::size() const
{
    return employees_.size();
}

bool Department::validateEmployee(const unsigned int left, const unsigned int right, const std::string& email, const std::string& password)
{
	Department::sort();
    auto middle = 0;
    if(right >= left)
    {
        middle = (left + right) / 2;
        if(employees_[middle]->getEmail() == email && employees_[middle]->getPassword() == password)
        {
            return true;
        }
        else if(employees_[middle]->getEmail() < email)
        {
            return validateEmployee(middle + 1, right, email, password);
        }
        else
        {
            return validateEmployee(left, middle - 1, email, password);
        }
    }
    return false;
}

void Department::createEmployee(unsigned int id, std::string name, std::string email, std::string password)
{
	new_employee_ = std::make_unique<Employee>(id, std::move(name), std::move(email), std::move(password));
	add();
}
