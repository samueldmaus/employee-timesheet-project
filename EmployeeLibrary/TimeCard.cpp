#include "TimeCard.h"

#include <ctime>

TimeCard::TimeCard(std::string title, std::string author)
        : Card(std::move(title), std::move(author)), clock_in_(std::chrono::system_clock::now()), clock_out_(std::chrono::system_clock::now())
{
}

void TimeCard::clockOut()
{
    clock_out_ = std::chrono::system_clock::now();
}

void TimeCard::print(std::ostream& os) const
{
	const auto in = TimeCard::makeTm(clock_in_);
    const auto out = TimeCard::makeTm(clock_out_);
    os << "Date: " << in.tm_mon << "/" << in.tm_mday << "/" << in.tm_year << " -- Clock In: " << in.tm_hour << ":" << in.tm_min << ":" << in.tm_sec << " -- Clock Out: " << out.tm_hour << ":" << out.tm_min << ":" << out.tm_sec;
}

std::tm TimeCard::makeTm(const std::chrono::system_clock::time_point t)
{
    struct tm rt {};
    auto new_time = std::chrono::system_clock::to_time_t(t);
    localtime_s(&rt, &new_time);
    ++rt.tm_mon;
    rt.tm_year += 1900;
    return rt;
}

std::chrono::system_clock::time_point TimeCard::getClockIn() const
{
    return clock_in_;
}

std::chrono::system_clock::time_point TimeCard::getClockOut() const
{
    return clock_out_;
}