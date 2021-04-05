#ifndef TIME_FOLDER_H
#define TIME_FOLDER_H

#include <vector>

#include "TimeCard.h"
#include "../FolderLibrary/Folder.h"

class TimeFolder : public Folder
{
public:
	TimeFolder(std::string title);

	TimeFolder(const TimeFolder& src) = delete;

	TimeFolder& operator=(TimeFolder rhs) = delete;

	TimeFolder& operator=(TimeFolder&& rhs) noexcept;

	TimeFolder(TimeFolder&& src) noexcept;

	~TimeFolder() override = default;

	[[nodiscard]] std::string getTitle() const;

	[[nodiscard]] size_t size() const override;

	void swap(TimeFolder& other) noexcept;
	
	void add() override;
	
	void remove() override;

	void print(std::ostream& os) const override;
	
	void clockIn();

	void clockOut();

	void printCurrentCard(std::ostream& os) const;

	static std::tm getDate();

private:
	std::unique_ptr<TimeCard> current_card_;

	std::string title_;

	std::vector<std::unique_ptr<Card>> folder_;
};

#endif