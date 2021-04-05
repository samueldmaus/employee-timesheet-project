#include <iostream>
#include <Windows.h>


#include "TimeFolder.h"
#include "TestHarness.h"
#include "TimeCard.h"

TEST(constructor, TimeFolder)
{
	const TimeFolder t("test");
	CHECK_EQUAL("test", t.getTitle());
}

TEST(clockIn, TimeFolder)
{
	const auto time_point = std::chrono::system_clock::now();
	const auto now_tm = TimeCard::makeTm(time_point);
	std::stringstream date;
	date << now_tm.tm_mon << "/" << now_tm.tm_mday << "/" << now_tm.tm_year;
	std::stringstream ss;
	ss << "Date: " << now_tm.tm_mon << "/" << now_tm.tm_mday << "/" << now_tm.tm_year << " -- Clock In: " << now_tm.tm_hour << ":" << now_tm.tm_min << ":" << now_tm.tm_sec << " -- Clock Out: " << now_tm.tm_hour << ":" << now_tm.tm_min << ":" << now_tm.tm_sec;

	TimeFolder t("test");
	t.clockIn();
	std::stringstream os;
	t.printCurrentCard(os);

	CHECK_EQUAL(ss.str(), os.str());
}

TEST(clockOut, TimeFolder)
{
	const auto time_point = std::chrono::system_clock::now();
	const auto now_tm = TimeCard::makeTm(time_point);
	TimeFolder t("test");
	t.clockIn();
	Sleep(2000);
	t.clockOut();

	std::stringstream ss;
	ss <<  t.size();

	CHECK_EQUAL("1", ss.str());
}

TEST(moveAssignment, TimeFolder)
{
	TimeFolder t("test");
	const auto t2 = std::move(t);

	CHECK_EQUAL("test", t2.getTitle());
}

TEST(moveConstructor, TimeFolder)
{
	TimeFolder t("test");
	t.clockIn();
	t.clockOut();
	auto t2(std::move(t));
	t2.clockIn();
	t2.clockOut();
	
	const size_t size = 2;
	CHECK_EQUAL("test", t2.getTitle());
	CHECK_EQUAL(size, t2.size());
}