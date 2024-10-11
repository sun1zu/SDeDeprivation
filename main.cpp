#include <iostream>
#include <ctime>
#include <typeinfo>
#include <cstdlib>
#include <windows.h>

using namespace std;

void invoke_shutdown_timer(){
    time_t now = time(0);

    tm *ltm = localtime(&now);

    int hour = ltm->tm_hour;
    int min = ltm->tm_min;

    if(hour == 21 && min >= 30 || hour > 21 || hour <= 5){
        std::system("shutdown /s /t 300 /c \"turnin off ur pc in 5 min :P \nenter shutdown /a to ignore\"");
        cout << "Timer has started" << endl;
    }
}

//todo: make it run on system boot
void setup(){
    char buffer[255];
    HMODULE hmodule = GetModuleHandle(NULL);
    GetModuleFileName(hmodule, buffer, sizeof(buffer));
    string exePath = string(buffer);

    string command = "schtasks /create /tn SDeDeprivation /tr " + exePath + " /sc daily /st 21:30";
    system(command.c_str());

    cout << "Task created successfully" << endl;
}

int main(int argc, char* argv[]){
    if (argc > 1 && std::string(argv[1]) == "-setup") {
        setup();
    }
    invoke_shutdown_timer();
}