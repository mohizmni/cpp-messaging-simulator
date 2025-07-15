#ifndef VOTE_H
#define VOTE_H

#include "Header.h"

class VoteMessage : public BaseMessage {
private:
	string voteTitle;
	string options[10];
	int optionCount;
public:
	VoteMessage(int date, int sender, const string& title, string opt[], int count)
		: BaseMessage(date, sender), voteTitle(title), optionCount(count) {
		for (int i = 0; i < count && i < 10; i++) {
			options[i] = opt[i];
		}
	}

	void show(const User users[], int userCount) const override{
		printDate();
		cout << getUsernameById(senderId, users, userCount) << ": [Vote] " << voteTitle << endl;
		for (int i = 0; i < optionCount; i++) { 
			cout << "- " << (i + 1) << ". " << options[i] << endl;
		}
	}

};
#endif
