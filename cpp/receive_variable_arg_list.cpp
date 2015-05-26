/****************************************************
 *  This program demonstrates how to receive variable 
 *  argument list.
 ****************************************************/

#include <iostream>
#include <stdarg.h>
#include <stdio.h>

using namespace std;

string convertToString(const char *fmt, ...)
{
    char msg[1024];

    va_list args;
    va_start(args, fmt);
    vsprintf(msg, fmt, args);
    va_end(args);

    return string(msg);
}

int main(int argc, char* argv[])
{
    int a = 1024;
    string s = convertToString("we have %d fans\n", a);
    cout << s;

    return 0;

}

