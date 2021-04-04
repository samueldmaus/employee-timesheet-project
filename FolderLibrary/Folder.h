#ifndef FOLDER_H
#define FOLDER_H

#include <memory>
#include <ostream>

#include "Card.h"

class Folder
{
public:

	virtual ~Folder() = default;

	virtual void add() = 0;

	virtual void remove() = 0;

	virtual void print(std::ostream& os) const = 0;

	virtual void write() = 0;

};

inline std::ostream& operator<<(std::ostream& os, const Folder& src)
{
	src.print(os);
	return os;
}

#endif