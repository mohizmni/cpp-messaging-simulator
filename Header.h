#ifndef HEADER_H
#define HEADER_H

#include <iostream>
#include <iomanip>
#include <ctime>
using namespace std;

class BaseMessage {
protected:
	int sentDate;
	int senderId;
public:
	BaseMessage(int date, int sender) : sentDate(date), senderId(sender) {}
	
	virtual void show(const User users[], int userCount) const = 0;
	
	virtual void printDate() const{
		int year = sentDate / 10000;
        int month = (sentDate / 100) % 100;
        int day = sentDate % 100;

		tm timeStruct = {};
        timeStruct.tm_year = year - 1900;
        timeStruct.tm_mon = month - 1;
        timeStruct.tm_mday = day;
		mktime(&timeStruct);

		const char* weekdays[] = { "Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat" };
        const char* months[] = {
            "January", "February", "March", "April", "May", "June",
            "July", "August", "September", "October", "November", "December"
        };
		cout << "[Date: " << weekdays[timeStruct.tm_wday] << ", "
             << timeStruct.tm_mday << " " << months[timeStruct.tm_mon]
             << " " << (timeStruct.tm_year + 1900) << "] ";
    }

	virtual ~BaseMessage() {}
};

#endif
