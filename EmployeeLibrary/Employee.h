#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "TimeFolder.h"

#include <string>

class Employee
{
	public:
    Employee(unsigned int id, std::string name, std::string email, std::string password);

    Employee(const Employee& src) = delete;

    Employee& operator=(Employee rhs) = delete;
	
    Employee(Employee&& other) noexcept;

    ~Employee() = default;

    void swap(Employee& src) noexcept;

    [[nodiscard]] unsigned int getId() const;

    [[nodiscard]] const std::string getName() const;

    void setName(std::string name);

    [[nodiscard]] const std::string getEmail() const;

    void setEmail(std::string email);

    [[nodiscard]] const std::string getPassword() const;

    void setPassword(std::string password);

	[[nodiscard]] bool getAdmin() const;

	void setAdmin();

    void clockIn() const;

    void clockOut() const;

    void viewTimeSheet(std::ostream& os) const;

	[[nodiscard]] size_t size() const;

	[[nodiscard]] bool signIn() const;

private:
    friend std::ostream& operator<<(std::ostream& os, const Employee& src);

    unsigned int id_;

    std::string name_;

    std::string email_;

    std::string password_;

	bool admin_ = false;
	
	std::unique_ptr<TimeFolder> employee_folder_;
};

#endif