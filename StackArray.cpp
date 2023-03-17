#include "StackArray.h"

template<class T>
StackArray<T>::StackArray(int size) //конструктор
{
    if (size <= 0) throw WrongStackArraySize(); //проверка на верное указание размера
    //создание стека с размером size
    this->size = size;
    this->array = new T[this->size];
}
template StackArray<int>::StackArray(int size);
template StackArray<char>::StackArray(int size);

template<class T>
StackArray<T>::~StackArray() //деструктор
{
    delete this->array;
}
template StackArray<int>::~StackArray();
template StackArray<char>::~StackArray();

template<class T>
void StackArray<T>::push(const T& element) //вставка
{
    if (this->index >= this->size) throw StackArrayOverflow();//если текущая вершина >= размеру - ошибка

    this->array[this->index] = element; // верхний элемент стека = вставляемому элементу 

    this->index += 1; // верхушка выше
}
template void StackArray<int>::push(const int& element);
template void StackArray<char>::push(const char& element);

template<class T>
T StackArray<T>::pop()
{
    if (this->isEmpty()) throw StackArrayUnderflow(); // если стек пустой - исключение 

    this->index -= 1; //уменьшаем высоту 

    return this->array[this->index];//возвращаем верхний элемент
}
template int StackArray<int>::pop();
template char StackArray<char>::pop();

template<class T>
bool StackArray<T>::isEmpty() // пустой если индекс верхнего = 0
{
    return this->index == 0;
}
template bool StackArray<int>::isEmpty();
template bool StackArray<char>::isEmpty();

template<class T>
bool StackArray<T>::isFull() // метод проверки на переполнение стека
{
    return this->index >= this->size;
}
template bool StackArray<int>::isFull();
template bool StackArray<char>::isFull();
