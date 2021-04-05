#include "TimeFolder.h"

TimeFolder::TimeFolder(std::string title) : title_(std::move(title)), folder_(std::vector<std::unique_ptr<Card>>())
{
}

TimeFolder& TimeFolder::operator=(TimeFolder&& rhs) noexcept
{
	swap(rhs);
	return *this;
}

TimeFolder::TimeFolder(TimeFolder&& src) noexcept
	: current_card_(std::move(src.current_card_)), title_(std::move(src.title_)), folder_(std::move(std::vector<std::unique_ptr<Card>>()))
{
}

std::string TimeFolder::getTitle() const
{
	return title_;
}

size_t TimeFolder::size() const
{
	return folder_.size();
}

void TimeFolder::swap(TimeFolder& other) noexcept
{
	current_card_.swap(other.current_card_);
	title_.swap(other.title_);
	folder_.swap(other.folder_);
}

void TimeFolder::add()
{
	folder_.push_back(std::move(current_card_));
}

void TimeFolder::remove()
{
	folder_.pop_back();
}

void TimeFolder::print(std::ostream& os) const
{
	for(const auto& c : folder_)
	{
		os << *c << '\n';
	}
}

void TimeFolder::write()
{
	const auto now = TimeFolder::getDate();
	std::stringstream date;
	date << now.tm_mon << "/" << now.tm_mday << "/" << now.tm_year;
	current_card_ = std::make_unique<TimeCard>(date.str(), getTitle());
}

void TimeFolder::clockOut()
{
	current_card_->clockOut();
	add();
}

void TimeFolder::printCurrentCard(std::ostream& os) const
{
	os << *current_card_;
}

std::tm TimeFolder::getDate()
{
	const auto time_point = std::chrono::system_clock::now();
	const auto now_tm = TimeCard::makeTm(time_point);
	return now_tm;
}
