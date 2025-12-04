🏦 Bank Management System in C

A simple and modular Bank Management System written in C.
This project demonstrates file handling, modular programming, and structured record management.
It allows users to create accounts, deposit/withdraw money, check balances, and view all customer records.

✨ Features

✔ Create a new bank account
✔ Auto-incrementing account number
✔ Deposit money
✔ Withdraw money with balance validation
✔ Check account balance
✔ View all saved accounts
✔ Persistent storage in a binary file accounts.dat
✔ Modular design using separate .c and .h files

🧠 Concepts Demonstrated
🔷 Structures & Functions

Used to define and manage customer account records.

🔷 Binary File Operations

Uses:

fopen, fread, fwrite

fseek, rewind

Keeps persistent data across program runs.

🔷 Modular Programming

Organized as:

banking.h → Function declarations + struct

banking.c → Logic implementation

main.c → User interface + menu

🔷 Pointers & File Positioning

Used to modify specific records efficiently.

📁 Directory Structure
docs/
  -ProjectReport.pdf
include/
  -banking.h
src/
  -main.c
  -banking.c
README.md

🧾 How to Compile & Run
Using GCC
gcc -Iinclude src/main.c src/banking.c -o bank


Then run:

./bank

🕹️ How to Use

After running the program, choose from the menu:

1️⃣ Create a new bank account
2️⃣ Deposit money
3️⃣ Withdraw money
4️⃣ Check balance
5️⃣ Display all accounts

All account data is saved automatically in accounts.dat (binary format).

🔒 Notes

Data is stored in a binary file, making it fast and compact.

No encryption is used (simple educational system).


👤 Author

Ayush Joshi


📄 Project Report

A detailed write-up is available in:

docs/ProjectReport.pdf


Includes:

Objective

System design

Flowchart

Implementation details

Screenshots

Testing & output

Future improvements
