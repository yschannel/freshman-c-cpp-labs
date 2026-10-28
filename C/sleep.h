#pragma once
#ifdef _WIN32
#include <windows.h>
void sleep_us(unsigned int microseconds) {
    Sleep(microseconds / 1000);  // Windows 的 Sleep 以毫秒为单位
}
#else
#include <unistd.h>
void sleep_us(unsigned int microseconds) { usleep(microseconds); }
#endif