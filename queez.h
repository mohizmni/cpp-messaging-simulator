#ifndef QUEZ_H
#define QUEZ_H

#include "Header.h"
#include "user.h"

class QuizMessage : public BaseMessage {
private:
	string Question;
	string options[10];
	int correctAnswerIndex;
	int optioncount;

public:
	QuizMessage(int date, int sender, const string& que, string opt[], int count, int correctAnswer) 
		:	BaseMessage(date, sender), Question(que), correctAnswerIndex(correctAnswer), optioncount(count) {
			for (int i = 0; i < count && i < 10; i++) {
			   options[i] = opt[i];
            }
	}

	void show(const User users[], int userCount) const override {
		printDate();
		cout << getUsernameById(senderId, users, userCount) << ": [Quiz] " << Question << endl;
    	for (int i = 0; i < optioncount; i++) {
            cout << "- " << (i + 1) << ". " << options[i];
            if (i == correctAnswerIndex) {
                cout << "(Correct)";
            }
            cout << endl;
		}
	}

};
#endif