#pragma once

#include <iostream>

using namespace std;

template<class T>
class Stack {
public:
    virtual ~Stack() {}; // деструктор
    virtual void push(const T& element) = 0; //добавление элементов в стек
    virtual T pop() = 0;// Удаление и возвращение верхнего элемента. 
    virtual bool isEmpty() = 0;// Проверка стека на пустоту
};