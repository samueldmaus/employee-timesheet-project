#include "Card.h"

Card::Card(std::string t, std::string a) : title_(std::move(t)), author_(std::move(a))
{
}

std::string Card::getTitle() const
{
	return title_;
}

void Card::setTitle(const std::string& t)
{
	title_ = t;
}

std::string Card::getAuthor() const
{
	return author_;
}

void Card::setAuthor(const std::string& a)
{
	author_ = a;
}

std::ostream& operator<<(std::ostream& os, const Card& src)
{
	src.print(os);
	return os;
}