#pragma once

const int BITS = sizeof(int) * 8;

union MyFuncUnion {
    int tool;
    float num_float;
    int tools[2];
    double num_double;
};

extern MyFuncUnion myFuncUnion;

void Print_int_bits();
void Print_double_bits();
int Zero_one_quest(int number, int idx, bool is_double);
void Create_mask(int idx, int flag);
void Inversion_bit(int flag);