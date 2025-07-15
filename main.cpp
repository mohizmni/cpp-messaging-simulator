#include "Header.h"
#include "post.h"
#include "simple.h"
#include "vote.h"
#include "user.h"
#include "queez.h"
#include <iostream>
#include <string>

using namespace std;

User users[2] = { {"Anita", 123}, {"Foad", 456} };

string getUsernameById(int id,const User users[], int userCount);
int login(User user[], int userCoount);

int main()
{
	
	//loging:
	int userindex = login(users, 2);
	
	// while (userindex == -1) {
	// 	cout << "Enter username : " << endl;
	// 	cin >> username;

	// 	cout << "Enter password: \n";
	// 	cin >> password;

	// 	for (int i = 0; i < 2; i++) {
	// 		if (users[i].getuser() == username && users[i].getpass() == password) {
	// 			userindex = i;
	// 			break;
	// 		}
	// 	}

	// 	if (userindex == -1) {            
	// 		cout << "Invalid username or password. Try again.\n";
    //     }
	// }	
		
	//main menu:
	BaseMessage* allMessage[100];
	int messageCount = 0;

	while (true) {
		cout << "\nMain Menu:\n";
		cout << "1. Send Simple Message\n";
		cout << "2. Send Post\n";
		cout << "3. Send Vote\n";
		cout << "4. send Queez\n";
		cout << "5. Show Chat\n";
		cout << "6. Switch User\n";
		cout << "7. Exit\n";
		cout << "Chose an option\n";

		int choice;
		cin >> choice;
		cin.ignore();

		if (choice == 1) {
			if (messageCount >= 100) {
                cout << "Message limit reached.\n";
				continue;
			}

			string message;
			cout << "Enter Message: ";
			getline(cin, message);

			allMessage[messageCount++] = new SimpleMessage(userindex,20220312, message);

		}
		else if (choice == 2) {
			if (messageCount >= 100) {
                cout << "Message limit reached.\n";
				continue;
			}

			string msg, path;
			cout << "Enter Post Message: ";
			getline(cin, msg);
			cout << "Enter image Path: \n";
			getline(cin, path);

			allMessage[messageCount++] = new PostMessage(20231208, userindex, msg, path);

		}
		else if (choice == 3) {
			if (messageCount >= 100) {
                cout << "Message limit reached.\n";
				continue;
			}

			string title;
			cout << "Enter Vote Title\n";
			getline(cin, title);

			string Voteoptions[10];
			int optionCount;

			cout << "Enter number of options (max 10): ";
			cin >> optionCount;
			cin.ignore();

			for (int i = 0; i < optionCount; i++) {
				cin.ignore();
				getline(cin, Voteoptions[i]);
			}

			allMessage[messageCount++] = new VoteMessage(20231014, userindex, title, Voteoptions, optionCount);
		}
		else if (choice == 4) {
			if (messageCount >= 100) {
                cout << "Message limit reached.\n";
				continue;
			}

			string Question;
			cout << "Enetr Quiz:\n";
			getline(cin, Question);

			string options[10];
			int optionCount;

			cout << "Enter number of options: (max 10" << endl;
			cin >> optionCount;
			cin.ignore();

			for (int i = 0; i < optionCount; i++) {
				cout << "Enter option " << (i + 1) << ":";
				getline(cin, options[i]);
			}

			int correctindex;
			cout << "Enter correct option index (1 to " << optionCount << "): ";           
			cin >> correctindex;
			cin.ignore();

			allMessage[messageCount++] = new QuizMessage(20240908, userindex, Question, options, optionCount, correctindex - 1);
		}

		else if (choice == 5) {
			cout << "\nChat History:\n";
			for (int i = 0; i < messageCount; i++) {
				allMessage[i]->show(users, 2);
			}
		}
		else if (choice == 7) {
            cout << "Exiting program...\n";
			break;
		}
		else if (choice == 6) {
    		userindex = login(users, 2);
		}
		else {
            cout << "Invalid input. Please try again.\n";
		}
	}

	//clear Dinamic Memory:
	for (int i = 0; i < messageCount; i++) {
		delete allMessage[i];
	}
	return 0;
}

int login(User users[], int userCount) {
    string username;
    int password;
    int index = -1;

    while (index == -1) {
        cout << "\nSwitching user...\n";
        cout << "Enter username: ";
        cin >> username;
        cout << "Enter password: ";
        cin >> password;

        for (int i = 0; i < userCount; i++) {
            if (users[i].getuser() == username && users[i].getpass() == password) {
                index = i;
                cout << "Logged in successfully as " << username << endl;
                break;
            }
        }

        if (index == -1) {
            cout << "Invalid username or password. Try again.\n";
        }
    }
    return index;
}

string getUsernameById(int id,const User users[], int userCount) {
    if (id >= 0 && id < userCount) {
        return users[id].getuser();
    }
    return "Unknown";
}
