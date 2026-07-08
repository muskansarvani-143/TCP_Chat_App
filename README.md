# TCP Chat Application

A simple TCP client-server chat application developed in **C** using **Linux socket programming**. This project demonstrates the fundamentals of TCP communication between a server and a client.

## Features

* Client-server communication using TCP sockets
* Reliable message exchange
* Simple command-line interface
* Demonstrates basic socket programming concepts

## Project Structure

```
TCP_Chat_App/
├── server.c
├── client.c
├── Makefile
└── README.md
```

## Requirements

* Linux Operating System
* GCC Compiler
* Make

## Build the Project

Compile the project using:

```bash
make
```

This creates two executables:

* `server`
* `client`

## Run the Server

```bash
./server
```

The server starts and waits for a client connection.

## Run the Client

Open another terminal and execute:

```bash
./client
```

The client connects to the server, and both can exchange messages.

## Clean the Project

To remove the compiled executables:

```bash
make clean
```

## Concepts Used

* Socket Programming
* TCP/IP Protocol
* Client-Server Architecture
* IPv4 Addressing
* Port Communication
* Linux System Calls

## Files

### `server.c`

Creates a TCP server, binds to a port, listens for incoming connections, accepts a client connection, and exchanges messages with the connected client.

### `client.c`

Creates a TCP client, connects to the server using the server's IP address and port number, and exchanges messages with the server.

### `Makefile`

Automates the compilation of the server and client programs and provides a clean target to remove the generated executables.

## Future Improvements

* Support multiple clients
* Add username-based chat
* Handle unexpected client disconnections
* Improve error handling
* Add logging functionality

## Author

**Muskan Sarvani**

GitHub: https://github.com/muskansarvani-143
