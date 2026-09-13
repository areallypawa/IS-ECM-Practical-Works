#include "menu.h"
#include "../utils/utils.h"
#include "../bitwise_logic/bitwise_logic.h"
#include <iostream>

using namespace std;

void show_menu(int current, int size_items, const string items[], const string str) {
    hideCursor();
    set_cords(0, 0);
    cout << "=============== " << str << " ===============\n";
    for (int i = 0; i < size_items; i++) {
        if (i == current)
            cout << " -> " << items[i] << "   \n";
        else
            cout << "    " << items[i] << "   \n";
    }
}

int auto_detect_type(const string& input) {
    if (input.find('.') != string::npos || input.find(',') != string::npos) {
        string temp = input;
        size_t pos = temp.find(',');
        if (pos != string::npos) temp[pos] = '.';

        myFuncUnion.num_double = stod(temp);
        return 3;
    }

    myFuncUnion.tool = stoi(input);
    return 1;
}

int Algorithm_IDZ() {
    clear();
    set_cords(0, 0);

    string user_input;
    cout << "Введи число (целое или вещественное): ";
    cin >> user_input;

    int flag = 0;
    try {
        flag = auto_detect_type(user_input);
    }
    catch (...) {
        cout << "Ошибка ввода! Введи корректное число.\n";
        pause();
        return -1;
    }

    if (flag == 1) {
        cout << "Определен тип: Целое число\n";
        cout << "Было число: " << myFuncUnion.tool;
        Print_int_bits();
    }
    else if (flag == 3) {
        cout << "Определен тип: Вещественное число (double)\n";
        cout << "Было число: " << myFuncUnion.num_double;
        Print_double_bits();
    }

    Inversion_bit(flag);
    return 0;
}