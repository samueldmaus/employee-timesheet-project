#ifndef TIME_FOLDER_H
#define TIME_FOLDER_H

#include "TimeCard.h"
#include "../FolderLibrary/Folder.h"

class TimeFolder : public Folder
{
public:
	TimeFolder(std::string title);
	
	void clockIn(std::string date, std::string employee);

    void clockOut();

	void printCurrentCard(std::ostream& os) const;

private:
	std::unique_ptr<TimeCard> current_card_;
};

#endif