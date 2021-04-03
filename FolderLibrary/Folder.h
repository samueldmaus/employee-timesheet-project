#ifndef FOLDER_H
#define FOLDER_H

#include <memory>
#include <string>
#include <vector>
#include <ostream>

#include "Card.h"

class Folder
{
public:
	explicit Folder(std::string title);

	Folder(const Folder& src) = delete;

	Folder& operator=(Folder rhs) = delete;

	Folder& operator=(Folder&& rhs) noexcept;

	Folder(Folder&& src) noexcept;

	virtual ~Folder() = default;

	void swap(Folder& other) noexcept;
	
	[[nodiscard]] std::string getTitle() const;

	void setTitle(const std::string& t);

	std::vector<std::unique_ptr<Card>>& getFolder();

	void add(std::unique_ptr<Card> c);

	void remove();

	void print(std::ostream& os) const;

private:
	friend std::ostream& operator<<(std::ostream& os, const Folder& src);
	
	std::string title_;

	std::vector<std::unique_ptr<Card>> folder_;
};

#endif