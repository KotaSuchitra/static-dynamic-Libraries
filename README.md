🧩 Dynamic Library Demo(UNIX Domain Socket Server)

This project demonstrates how to create and use shared (dynamic) libraries in C, and how to dynamically load them at runtime using dlopen(), dlsym(), and dlclose().It also includes a basic UNIX domain socket server that dynamically loads handler functions (like handle_client, die, and on_signal) from a shared library at runtime.

## 📘 Overview

This project modularizes a simple **Key-Value Store** system using **Dynamic Linking** in C.  
It demonstrates how to split a program into:
- A **shared library** (`lib-kvstore.so`) that implements the key-value store functions.
- A **main executable** (`dynamic-kvstore`) that dynamically loads the library at runtime using `dlopen()`, retrieves symbols with `dlsym()`, and releases it using `dlclose()`.

This structure provides **modularity**, **flexibility**, and **runtime extensibility**, allowing the application to load updated logic without recompiling the main executable.

## 🧩 Project Structure

kvstore_project_M/
│
├── kvstore.h           # Header file (function declarations)
├── kvstore.c           # Implements the key-value store (set/get)
├── main-dlopen.c       # Demonstrates dynamic loading using dlopen()
├── kv-server.c            # Server side logic using Unix domain socket
├── kv-client.c            # Client side logic using Unix domain socket
├── lib-kvstore.so       # Shared library generated after compilation
└── README.md           # Project documentation (this file)

## 🔹 Step 1: Compile the dynamic library (Position Independent Code)
gcc -fPIC -c kvstore.c -o kvstore.o
gcc -shared -o lib-kvstore.so kvstore.o
gcc main-dlopen.c -o dynamic-kvstore -ldl
export LD_LIBRARY_PATH=.
./dynamic-kvstore

### Compile key-value store to PIC
gcc -fPIC -c kvstore.c -o kvstore.o

### Create shared library
gcc -shared -o lib-kvstore.so kvstore.o

### Compile main using dynamic loading
gcc main-dlopen.c -o dynamic-kvstore -ldl

### Allow runtime linker to find shared library
export LD_LIBRARY_PATH=.

### Run dynamically loaded program
./dynamic-kvstore

### Compile and run server
gcc -o kv-server kv-server.c -ldl
./kv-server

### Compile and run client
gcc -o kv-client kv-client.c
./client "SET name suchitra"
./client "GET name"
