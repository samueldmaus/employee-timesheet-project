#include "Manager.h"

Manager::Manager(const unsigned int i, std::string n, std::string e, std::string p)
 : Employee(i, std::move(n), std::move(e), std::move(p))
{
	setAdmin();
}

void Manager::createEmployee(const unsigned int i, std::string name, std::string email, std::string password) const
{
    Employee e(i, std::move(name), std::move(email), std::move(password));
}