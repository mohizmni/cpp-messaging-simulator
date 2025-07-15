#ifndef SIMPLE_H
#define SIMPLE_H

#include "Header.h"

class SimpleMessage : public BaseMessage {
private:
	string content;
public:
	SimpleMessage(int sender, int date, const string& msg)
		: BaseMessage(date, sender), content(msg){}
	void show(const User user[], int userCount) const override {
		printDate();
		cout << getUsernameById(senderId, users, 2) << ": " << content << endl;
	}
	
};
#endif
