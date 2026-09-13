#include "utils.h"
#include <iostream>
#include <cstdlib>

using namespace std;

void clear() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

void pause() {
    cout << '\n';
    system("Pause");
}