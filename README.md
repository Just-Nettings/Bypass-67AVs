# Memory-Moving Background Process with Ngrok Connection

This C++ program demonstrates a technique to move itself to memory, start a new background process, and establish a connection to an ngrok tunnel. The code is designed to work on Windows systems.

## Prerequisites

- Windows operating system
- `g++` compiler (part of GNU Compiler Collection) installed and properly configured

# Usage
To compile and run the program, you need to follow these steps:

git clone https://github.com/Just-Nettings/Bypass-67AVs.git
Create a new file using a text editor and copy the provided C++ code from the main.cpp file into the new file.

Save the file with a .cpp extension (e.g., main.cpp).

Open a command prompt or PowerShell window.

Navigate to the directory where the main.cpp file is located using the cd command.

Compile the C++ code using the following command:


g++ -o main.exe main.cpp
This command will generate an executable file named main.exe.

Start an ngrok http tunnel. For example:


ngrok http 80
Run the compiled executable by typing its name and pressing Enter:


main.exe
The program will execute and perform the following steps:

Move itself to memory.
Start a new background process named "AAAA".
Connect the new process to the specified ngrok tunnel.
Please note the following important points:

Exercise caution and use this code responsibly and in compliance with applicable laws and regulations.
Make sure you have the necessary dependencies and tools installed, such as the g++ compiler.
Modify the ngrokUrl variable in the code to match the actual ngrok tunnel URL you want to connect to.
The code provided in the repository is licensed under the MIT License, which allows you to use and modify it according to your needs.
