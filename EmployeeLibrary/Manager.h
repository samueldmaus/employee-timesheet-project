#ifndef MANAGER_H
#define MANAGER_H

#include "Employee.h"

class Manager : public Employee
{
public:
    Manager(unsigned int i, std::string n, std::string e, std::string p);

    void createEmployee(unsigned int i, std::string name, std::string email, std::string password) const;

	// void addEmployee();
};

#endif