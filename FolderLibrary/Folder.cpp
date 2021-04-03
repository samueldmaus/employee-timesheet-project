#include "Folder.h"

Folder::Folder(std::string title) : title_(std::move(title)), folder_(std::vector<std::unique_ptr<Card>>())
{
}

Folder& Folder::operator=(Folder&& rhs) noexcept
{
	swap(rhs);
	return *this;
}

Folder::Folder(Folder&& src) noexcept
	: title_(std::move(src.title_)), folder_(std::move(src.folder_))
{
}

void Folder::swap(Folder& other) noexcept
{
	title_.swap(other.title_);
	folder_.swap(other.folder_);
}

std::string Folder::getTitle() const
{
	return title_;
}

void Folder::setTitle(const std::string& t)
{
	title_ = t;
}

std::vector<std::unique_ptr<Card>>& Folder::getFolder()
{
	return folder_;
}

void Folder::add(std::unique_ptr<Card> c)
{
	folder_.push_back(std::move(c));
}

void Folder::remove()
{
	folder_.erase(folder_.end());
}

void Folder::print(std::ostream& os) const
{
	for(const auto& c : folder_)
	{
		os << *c;
	}
}

std::ostream& operator<<(std::ostream& os, const Folder& src)
{
	src.print(os);
	return os;
}
