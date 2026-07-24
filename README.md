# C++ OOP Messaging Simulator

A feature-rich command-line messaging platform implemented in C++ showcasing core **Object-Oriented Programming (OOP)** paradigms—including dynamic polymorphism, inheritance hierarchies, and memory management.

---

## Core OOP Concepts Demonstrated

* **Inheritance:** A polymorphic `BaseMessage` class serves as the parent to specialized message derived types.
* **Polymorphism:** Runtime dynamic dispatch for rendering varied message payloads (Text, Media Posts, Polls, and Quizzes).
* **Encapsulation:** User identity states, credentials, and message histories encapsulated within dedicated class boundaries.

---

## Supported Message Types

| Message Type | Derived Class | Key Attributes & Features |
| :--- | :--- | :--- |
| **Simple Text** | `SimpleMessage` | Standard string-based text transmission |
| **Post** | `PostMessage` | Text content combined with an associated media/image file path |
| **Vote / Poll** | `VoteMessage` | Interactive poll title with multiple selectable options |
| **Quiz** | `QuizMessage` | Question setup, candidate options, and indexed correct answers |

---

## Repository Structure

```text
.
├── main.cpp     # Execution entry point and CLI menu interface
├── Header.h     # BaseMessage abstract/parent class & utility functions
├── user.h       # User entity class and credential validation
├── simple.h     # SimpleMessage class declaration
├── post.h       # PostMessage class declaration
├── vote.h       # VoteMessage class declaration
└── queez.h      # QuizMessage class declaration

```
---

## Pre-configured Test Accounts

​Since dynamic user registration is out of scope for this version, use the following pre-loaded credentials for testing runtime user switching:

| Username | Password | Role / Access Level |
| :--- | :--- | :--- |
| `Anita` | `123` | Standard User |
| `Foad` | `456` | Standard User |

---

## Compilation & Execution

​### Prerequisites
  - Any standard C++ compiler supporting C++11 or higher (g++, clang++, MSVC).
​  
​### Building the Executable
  - Compile all header and source files into a single binary:
  ```bash
  # Compile using Gcc
  g++ main.cpp -o messenger

  # Run executable (Linux/macOS)
  ./messenger

  # Run executable (Windows)
  messenger.exe
  ```

---

## Future Enhancements & Roadmap
​  - [ ] Transition hardcoded users to file-based / database storage.
​  - [ ] Implement smart pointers (std::shared_ptr / std::unique_ptr) for safer memory management.
​  - [ ] Add real-time network sockets for multi-threaded multi-client communication.
