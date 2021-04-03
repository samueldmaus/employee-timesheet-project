#ifndef CARD_H
#define CARD_H

#include <string>
#include <ostream>

class Card
{
public:
	Card(std::string t, std::string a);

	virtual ~Card() = default;

	[[nodiscard]] std::string getTitle() const;

	void setTitle(const std::string& t);

	[[nodiscard]] std::string getAuthor() const;

	void setAuthor(const std::string& a);

	virtual void print(std::ostream& os) const = 0;

private:
	friend std::ostream& operator<<(std::ostream& os, const Card& src);
	
	std::string title_;

	std::string author_;
};

#endif