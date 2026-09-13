#include "bitwise_logic.h"
#include "../utils/utils.h"
#include "../../../MyVector/my_vector.h"
#include <iostream>

using namespace std;

MyFuncUnion myFuncUnion;

void Print_int_bits() {
    cout << "\nBIN: ";
    unsigned int mask = 1U << (BITS - 1);

    for (int i = 0; i < BITS; i++) {
        if (((i == 1) || (i % 4 == 0)) && i != 0) {
            cout << ' ';
        }
        if (i == 0) { cout << "\033[31m"; }
        else { cout << "\033[36m"; }
        cout << ((myFuncUnion.tool & mask) ? '1' : '0');
        mask >>= 1;
    }
    cout << "\033[0m" << endl;
}

void Print_double_bits() {
    cout << "\nBIN: ";
    for (int j = 1; j >= 0; j--) {
        unsigned int mask = 1 << (BITS - 1);
        for (int i = 0; i < BITS; i++) {
            int global_bit_index = (1 - j) * 32 + i;
            if (global_bit_index == 1 || global_bit_index == 12) { cout << "\033[0m|"; }
            else if (i % 4 == 0 && !(global_bit_index == 1 || global_bit_index == 12)) { cout << ' '; }
            if (global_bit_index == 0) { cout << "\033[31m"; }
            else if (global_bit_index >= 1 && global_bit_index <= 11) { cout << "\033[33m"; }
            else { cout << "\033[36m"; }
            cout << ((myFuncUnion.tools[j] & mask) ? '1' : '0');
            mask >>= 1;
        }
    }
    cout << "\033[0m" << endl;
}

int Zero_one_quest(int number, int idx, bool is_double) {
    if (!is_double) {
        unsigned int mask = 1 << (BITS - 1);
        for (int i(0); i < BITS; i++) {
            if (i == (BITS - idx - 1)) { return (number & mask ? 1 : 0); }
            mask >>= 1;
        }
    }
    else {
        if (idx > 31) { number = myFuncUnion.tools[1]; idx -= 32; }
        else { number = myFuncUnion.tools[0]; }
        unsigned int mask = 1 << (BITS - 1);
        for (int i(0); i < BITS; i++) {
            if (i == (BITS - idx - 1)) { return (number & mask ? 1 : 0); }
            mask >>= 1;
        }
    }
    return -1;
}

void Create_mask(int idx, int flag) {
    int modify_num; int number(myFuncUnion.tool);

    if (flag != 3) {
        if (Zero_one_quest(number, idx, 0)) {
            unsigned int mask = (1U << BITS) - 1 - (1 << idx);
            modify_num = number & mask;
        }
        else {
            unsigned int mask = (1 << idx);
            modify_num = number | mask;
        }
        myFuncUnion.tool = modify_num;
    }
    else {
        if (Zero_one_quest(number, idx, 1)) {
            if (idx > 31) {
                unsigned int mask = (1 << BITS) - 1 - (1 << idx - 32);
                modify_num = myFuncUnion.tools[1] & mask;
                myFuncUnion.tools[1] = modify_num;
            }
            else {
                unsigned int mask = (1 << BITS) - 1 - (1 << idx);
                modify_num = myFuncUnion.tools[0] & mask;
                myFuncUnion.tools[0] = modify_num;
            }
        }
        else {
            if (idx > 31) {
                unsigned int mask = (1 << (idx - 32));
                modify_num = myFuncUnion.tools[1] | mask;
                myFuncUnion.tools[1] = modify_num;
            }
            else {
                unsigned int mask = (1 << (idx));
                modify_num = myFuncUnion.tools[0] | mask;
                myFuncUnion.tools[0] = modify_num;
            }
        }
    }
}

void Inversion_bit(int flag) {
    short N, idx;
    cout << "\nВведи количество, сколько хочешь битов поменять? : ";
    cin >> N;

    MyVector<int> arr_idx;
    arr_idx.init();

    cout << "Введи " << N << " индексов через Enter\n";
    for (int i = 0; i < N; i++) {
        cin >> idx;
        arr_idx.push_back(idx);
        Create_mask(arr_idx[i], flag);
    }

    switch (flag) {
    case 1:
        cout << "Стало число " << myFuncUnion.tool;
        Print_int_bits();
        break;
    case 2:
        cout << "Стало число " << myFuncUnion.num_float;
        Print_int_bits();
        break;
    case 3:
        cout << "Стало число " << myFuncUnion.num_double;
        Print_double_bits();
        break;
    }
    arr_idx.free_memory();

    pause();
}