#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User { 
	int password;
	string username;
public:
	User() = default;
	User(const string& name, int pass) : username(name), password(pass) {}
	string getuser() const { return username; }
	int getpass() const { return password; }
};

#endif
