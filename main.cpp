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

    if(hour >= 14 && min >= 30 || hour <= 5){
        std::system("shutdown /s /t 300 /c \"turnin off ur pc in 5 min :P \nenter shutdown /a to ignore\"");
    }
}

void throw_to_startup_apps(){
    char buffer[255];
    HMODULE hmodule = GetModuleHandle(NULL);
    GetModuleFileName(hmodule, buffer, sizeof(buffer));
    string exePath = str(buffer);

    cout << exePath << endl;
    // std::string command = "schtasks /create /tn MyApp /tr " + exePath + "/sc daily /st 21:30";
}

int main(){
    throw_to_startup_apps();
}