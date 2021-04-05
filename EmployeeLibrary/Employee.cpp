#include "Employee.h"

Employee::Employee(const unsigned int id, std::string name, std::string email, std::string password)
        : id_(id), name_(std::move(name)), email_(std::move(email)), password_(std::move(password)),
			employee_folder_(std::make_unique<TimeFolder>(name))
{
}

Employee& Employee::operator=(Employee&& rhs) noexcept
{
    swap(rhs);
	return *this;
}

Employee::Employee(Employee&& other) noexcept
        : id_(other.id_), name_(std::move(other.name_)), email_(std::move(other.email_)), password_(std::move(other.password_))
{
}

void Employee::swap(Employee& src) noexcept
{
    std::swap(id_, src.id_);
    std::swap(name_, src.name_);
    std::swap(email_, src.email_);
    std::swap(password_, src.password_);
}

// getters and setters
unsigned int Employee::getId() const
{
    return id_;
}

const std::string Employee::getName() const
{
    return name_;
}

void Employee::setName(std::string name)
{
    name_ = std::move(name);
}

const std::string Employee::getEmail() const
{
    return email_;
}

void Employee::setEmail(std::string email)
{
    email_ = std::move(email);
}

const std::string Employee::getPassword() const
{
    return password_;
}

void Employee::setPassword(std::string password)
{
    password_ = std::move(password);
}

bool Employee::getAdmin() const
{
    return admin_;
}

void Employee::setAdmin()
{
	admin_ = !admin_;
}

void Employee::clockIn() const
{
    employee_folder_->clockIn();
}

void Employee::clockOut() const
{
	employee_folder_->clockOut();
}

void Employee::viewTimeSheet(std::ostream& os) const
{
	employee_folder_->print(os);
}

size_t Employee::size() const
{
	return employee_folder_->size();
}

std::ostream& operator<<(std::ostream& os, const Employee& src)
{
    os << "Employee: " << src.getId() << ", " << src.getName() << ", " << src.getEmail();
    return os;
}