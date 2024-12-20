# C++ UNIX Programs

This repository contains several C++ programs demonstrating fundamental concepts of system programming in UNIX. Each program is designed to showcase specific functionalities, such as inter-process communication, file handling, client-server architecture, and basic web server implementation.

---

## Programs Overview

| Program                  | Description                                     |
|--------------------------|-------------------------------------------------|
| `ChildUsingFork.cpp`     | Demonstrates process creation using `fork()`.   |
| `ClientSide.cpp`         | Implements a client-side socket communication. |
| `ProducerNConsumer.cpp`  | Simulates the producer-consumer problem.        |
| `ServerSide.cpp`         | Implements a server-side socket communication. |
| `copyfile.cpp`           | Copies content from one file to another.       |
| `cpp-web-server.cpp`     | Implements a basic web server in C++.           |

---

## System Requirements

- **Operating System**: Any UNIX-based OS (e.g., Linux, macOS)
- **Compiler**: `g++` (GNU Compiler Collection)
- **Tools**: 
  - Terminal with basic UNIX utilities (e.g., `bash`, `make`)
  - Sockets library (pre-installed on most UNIX systems)
- **Memory Requirements**: Minimum 512MB RAM (for small-scale testing)

---

## How to Compile and Run

### Compilation
Each program can be compiled using `g++` on a UNIX system. For example:
```bash
g++ -o ChildUsingFork ChildUsingFork.cpp
g++ -o ClientSide ClientSide.cpp
g++ -o ProducerNConsumer ProducerNConsumer.cpp
g++ -o ServerSide ServerSide.cpp
g++ -o copyfile copyfile.cpp
g++ -o cpp-web-server cpp-web-server.cpp
