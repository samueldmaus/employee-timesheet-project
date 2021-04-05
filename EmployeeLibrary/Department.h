#ifndef DEPARTMENT_H
#define DEPARTMENT_H

#include <vector>
#include <memory>

#include "Employee.h"
#include "../FolderLibrary/Folder.h"

class Department : public Folder
{
public:
	explicit Department(std::string name);

	Department(const Department& src) = delete;

	Department& operator=(Department rhs) = delete;

	Department& operator=(Department&& rhs) noexcept;

	Department(Department&& rhs) noexcept;
	
	~Department() override = default;

	void swap(Department& other) noexcept;

	[[nodiscard]] const std::string& getName() const;

	void add() override;

	void remove() override;

	void print(std::ostream& os) const override;

	void sort();

	[[nodiscard]] size_t size() const override;

	[[nodiscard]] bool validateEmployee(const unsigned int left, const unsigned int right, const std::string& email, const std::string& password);

	void createEmployee(unsigned int id, std::string name, std::string email, std::string password);

	Employee& operator[](const int i) const;
	
	Employee& operator[](const int i);

private:
	std::string name_;

	std::unique_ptr<Employee> new_employee_;

	std::vector<std::unique_ptr<Employee>> employees_;
};

#endif