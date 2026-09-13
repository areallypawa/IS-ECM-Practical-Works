#include "menu.h"
#include "../bitwise_logic/bitwise_logic.h"
#include "../utils/utils.h"
#include <iostream>

using namespace std;

int Algorithm_IDZ() {
    short flag;
    cout << "Выбер типа данных:\n1 - int\n2 - float\n3 - double\n0 - Назад\n";
    cin >> flag;
    switch (flag) {
    case 0: return 0;
    case 1:
        clear();
        cout << "Введи целое число: ";
        cin >> myFuncUnion.tool;
        cout << "Было число: " << myFuncUnion.tool;
        Print_int_bits();
        Inversion_bit(flag);
        break;
    case 2:
        clear();
        cout << "Введи число float: ";
        cin >> myFuncUnion.num_float;
        cout << "Было число: " << myFuncUnion.num_float;
        Print_int_bits();
        Inversion_bit(flag);
        break;
    case 3:
        clear();
        cout << "Введи число double: ";
        cin >> myFuncUnion.num_double;
        cout << "Было число: " << myFuncUnion.num_double;
        Print_double_bits();
        Inversion_bit(flag);
        break;
    }
    return -1;
}