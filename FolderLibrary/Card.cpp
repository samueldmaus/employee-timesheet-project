#include "Card.h"

Card::Card(std::string title, std::string author) : title_(std::move(title)), author_(std::move(author))
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