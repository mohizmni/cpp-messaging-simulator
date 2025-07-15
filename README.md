# Messaging Simulator in C++

A console-based messaging system written in C++ using object-oriented programming principles.  
This project demonstrates the use of classes, inheritance, polymorphism, and dynamic memory management in C++.

## Features

- User login with username and password  
- Send various message types:
  - Simple text messages
  - Post messages (text + image path)
  - Vote messages (title with multiple options)
  - Quiz messages (question, options, and correct answer)
- View chat history with sender names and date
- Switch between users during runtime

## Project Structure

/MessagingSimulator
├── main.cpp // Main program and menu
├── Header.h // BaseMessage class and printDate function
├── user.h // User class
├── simple.h // SimpleMessage class
├── post.h // PostMessage class
├── vote.h // VoteMessage class
├── queez.h // QuizMessage class
└──  README.md // Project documentation

## How to Compile

```bash
g++ main.cpp -o messenger

Usage

    At program start, login is required.

    Only two users are predefined:

        Username: Anita | Password: 123

        Username: Foad | Password: 456

    After login, choose from the menu to send messages, view chat history, or switch users.

    Select option 7 to exit the program.

Note: There is no user registration system in this version