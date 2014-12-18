#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
    cout.setf(ios::unitbuf); // set unbuffered out stream
    for (int i = 0; i < 101; i++) {
        cout << "Progress: " << i << "%\r" ;
        for (int j = 0; j < 100000000; j++); //delay
    }
    cout << endl;

    return 0;
}
