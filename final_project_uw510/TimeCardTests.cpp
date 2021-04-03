#include "TimeCard.h"
#include "TestHarness.h"

#include <sstream>
#include <Windows.h>

TEST(constructor, TimeCard)
{
	const auto time_point = std::chrono::system_clock::now();
	const auto now_tm = TimeCard::makeTm(time_point);
	std::stringstream date;
	date << now_tm.tm_mon << "/" << now_tm.tm_mday << "/" << now_tm.tm_year;
	
	const TimeCard card(date.str(), "Sam Maus");
	const auto clock_in_tm = TimeCard::makeTm(card.getClockIn());
	
	CHECK_EQUAL(now_tm.tm_hour, clock_in_tm.tm_hour);
	CHECK_EQUAL(now_tm.tm_min, clock_in_tm.tm_min);
	CHECK_EQUAL(now_tm.tm_mon, clock_in_tm.tm_mon);
	CHECK_EQUAL(now_tm.tm_mday, clock_in_tm.tm_mday);
}

TEST(stream, TimeCard)
{
	const auto time_point = std::chrono::system_clock::now();
	const auto now_tm = TimeCard::makeTm(time_point);
	std::stringstream date;
	date << now_tm.tm_mon << "/" << now_tm.tm_mday << "/" << now_tm.tm_year;
	std::stringstream ss;
	ss << "Date: " << now_tm.tm_mon << "/" << now_tm.tm_mday << "/" << now_tm.tm_year << " -- Clock In: " << now_tm.tm_hour << ":" << now_tm.tm_min << ":" << now_tm.tm_sec << " -- Clock Out: " << now_tm.tm_hour << ":" << now_tm.tm_min << ":" << now_tm.tm_sec;
	
	const TimeCard card(date.str(), "Sam Maus");
	std::stringstream os;
	card.print(os);
	
	CHECK_EQUAL(ss.str(), os.str());
}

TEST(clockOut, TimeCard)
{
	const auto time_point = std::chrono::system_clock::now();
	const auto now_tm = TimeCard::makeTm(time_point);
	std::stringstream date;
	date << now_tm.tm_mon << "/" << now_tm.tm_mday << "/" << now_tm.tm_year;
	
	TimeCard card(date.str(), "Sam Maus");
	Sleep(2000);
	card.clockOut();

	const auto clock_out_tm = TimeCard::makeTm(card.getClockOut());
	CHECK_EQUAL(now_tm.tm_sec + 2, clock_out_tm.tm_sec);
}