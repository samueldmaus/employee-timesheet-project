﻿#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <memory>

#include "Employee.h"
#include "../FolderLibrary/Folder.h"

//class Employee;

class Department : public Folder
{
public:
	Department(std::string name);
	
	~Department() override = default;

	void add() override;

	void remove() override;

	void print(std::ostream& os) const override;

	void write() override;

	void sort();

	[[nodiscard]] bool validateEmployee(const unsigned int left, const unsigned int right, const std::string& email, const std::string& password);

	void createEmployee(unsigned int id, std::string name, std::string email, std::string password);

private:
	std::string name_;

	std::unique_ptr<Employee> new_employee_;

	std::vector<std::unique_ptr<Employee>> employees_;
};

#endif