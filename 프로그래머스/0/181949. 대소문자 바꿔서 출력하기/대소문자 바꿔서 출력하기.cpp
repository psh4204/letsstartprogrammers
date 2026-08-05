#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    int aDiff = 'a'-'A';
    cin >> str;
    for(auto & ch: str)
    {
        if(ch >='a' && ch <= 'z')
            ch -= aDiff;
        else if(ch >='A' && ch <= 'Z')
            ch += aDiff;
    }
    cout << str;
    return 0;
}