#include "Employee.h"

Employee::Employee(const unsigned int i, std::string n, std::string e, std::string p)
        : id_(i), name_(std::move(n)), email_(std::move(e)), password_(std::move(p))
{
}

Employee::Employee(Employee&& other) noexcept
        : id_(other.id_), name_(std::move(other.name_)), email_(std::move(other.email_)), password_(std::move(other.password_))
{
}

Employee& Employee::operator=(Employee rhs)
{
    swap(rhs);
    return *this;
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

std::ostream& operator<<(std::ostream& os, const Employee& src)
{
    os << "Employee: " << src.getId() << ", " << src.getName() << ", " << src.getEmail();
    return os;
}