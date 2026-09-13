#include <iostream>
#include <string>
#include <conio.h>
#include <windows.h>
#include "src/menu/menu.h"
#include "src/utils/utils.h"

using namespace std;

string main_menu_items[] = {
    "Проверить ИДЗ",
    "Выход"
};
const int main_menu_size = 2;

int main() {
    SetConsoleCP(CP_UTF8);
    SetConsoleOutputCP(CP_UTF8);

    int current_item = 0;

    while (true) {
        show_menu(current_item, main_menu_size, main_menu_items, "МЕНЮ");

        int key = _getch();
        if (key == 224) {
            key = _getch();
        }

        if (key == 72 && current_item > 0) current_item--; 
        if (key == 80 && current_item < main_menu_size - 1) current_item++; 

        if (key == 13) {
            if (current_item == 0) {
                Algorithm_IDZ();
                clear();
            }
            else if (current_item == 1) {
                break;
            }
        }
    }
    return 0;
}