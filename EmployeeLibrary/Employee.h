#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ostream>

class Employee
{
	public:
    Employee(unsigned int i, std::string n, std::string e, std::string p);

    Employee(const Employee& src) = delete;

    Employee(Employee&& other) noexcept;

    ~Employee() = default;

    Employee& operator=(Employee rhs);

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

	/*
    void clockIn() const;

    void clockOut() const;

    void viewTimeSheet() const;
    */
private:
    friend std::ostream& operator<<(std::ostream& os, const Employee& src);

    unsigned int id_;

    std::string name_;

    std::string email_;

    std::string password_;

	bool admin_ = false;
	
};

#endif