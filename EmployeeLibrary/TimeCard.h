#ifndef TIME_CARD_H
#define TIME_CARD_H

#include <chrono>
#include <ostream>

#include "../FolderLibrary/Card.h"

class TimeCard : public Card
{
public:
    // constructor serves as the clock in func, bc TimeCard obj does not need to be created until clock in happens
    TimeCard(std::string title, std::string author);

    void clockOut();

	void print(std::ostream& os) const override;

    static std::tm makeTm(std::chrono::system_clock::time_point t);

	[[nodiscard]] std::chrono::system_clock::time_point getClockIn() const;

	[[nodiscard]] std::chrono::system_clock::time_point getClockOut() const;

private:

    std::chrono::system_clock::time_point clock_in_;

    std::chrono::system_clock::time_point clock_out_;
};

#endif