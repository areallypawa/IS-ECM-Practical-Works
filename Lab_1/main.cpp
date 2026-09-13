#include "./src/menu/menu.h"
#include "./src/utils/utils.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(0, "RU");

    while (true) {
        clear();
        short choice;
        cout << "Выбор действия:\n1 - проверить ИДЗ\n0 - Выход\n";
        cin >> choice;

        switch (choice) {
        case 1:
            clear();
            Algorithm_IDZ();
            break;
        case 0:
            return 0;
        }
    }
}