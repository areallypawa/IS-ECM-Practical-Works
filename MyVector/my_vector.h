#pragma once

template <typename T>
struct MyVector {
    T* arr;
    int capacity;
    int current;

    // Инициализация 
    void init() {
        capacity = 1;
        current = 0;
        arr = new T[capacity];
    }

    // Добавление элемента с динамическим расширением
    void push_back(T value) {
        if (current == capacity) {
            capacity *= 2;
            T* temp = new T[capacity];
            for (int i = 0; i < current; i++) {
                temp[i] = arr[i];
            }
            delete[] arr;
            arr = temp;
        }
        arr[current] = value;
        current++;
    }

    // Очистка памяти 
    void free_memory() {
        delete[] arr;
    }

    // Получить размер
    int size() {
        return current;
    }

    // Перегрузка оператора доступа
    T& operator[](int index) {
        return arr[index];
    }
};