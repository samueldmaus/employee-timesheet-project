#include "TimeFolder.h"

TimeFolder::TimeFolder(std::string title) : Folder(std::move(title))
{
}

void TimeFolder::clockIn(std::string date, std::string employee)
{
	current_card_ = std::make_unique<TimeCard>(std::move(date), std::move(employee));
}

void TimeFolder::clockOut()
{
	current_card_->clockOut();
	add(std::move(current_card_));
}

void TimeFolder::printCurrentCard(std::ostream& os) const
{
	os << *current_card_;
}
