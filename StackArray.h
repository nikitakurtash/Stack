#pragma once

#include "Stack.h"
#include "StackException.h"

template<class T>
class StackArray : public Stack<T>
{
private:
    int size = 0;
    int index = 0;
    T* array;
public:
    StackArray(int size);
    ~StackArray();

    void push(const T& element);
    T pop();
    bool isEmpty();
    bool isFull();
};