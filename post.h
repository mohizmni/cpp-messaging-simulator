#ifndef POST_H
#define POST_H

#include "simple.h"

class PostMessage : public SimpleMessage {
private:
	string caption;
	string imgPath;
public:
	PostMessage(int date, int sender, const string& msg, const string& path)
    : SimpleMessage(sender, date, msg), imgPath(path) {}

	void show(const User users[], int userCount) const override {
		printDate();
		cout << getUsernameById(senderId, users, userCount) << ": [Post] " << caption << "\nImage: " << imgPath << endl;
	}
};

#endif