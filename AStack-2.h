//*******************************************************************************************************
//
//        File:                   AStack.h
//
//        Student:                Lexi Corniello
//
//        Assignment:             Asssignment #9
//
//        Course Name:            Data Structures I
//
//        Course Number:          COSC 3050-10
//
//        Due:                    November 15th, 2021
//
//        This file define the functions used in the main.cpp
//
//        Other files required:
//        1. main.cpp
//
//*******************************************************************************************************

#ifndef AStack_h
#define AStack_h
using namespace std;

//*******************************************************************************************************

template <typename T>
class Stack
{
private:
    T * stack;
    int top,
    capacity;
    
public:
    Stack(int c = 100);
    ~Stack();
    bool push(const T &);
    bool pop(T &);
    bool peek(T &) const;
    bool isEmpty() const;
    bool isFull() const;
    int getSize() const;
    bool clearList();
};

//*******************************************************************************************************

template <typename T>
Stack<T>::Stack(int c)
{
    capacity = c;
    stack = new T[capacity];
    top = -1;
}

//*******************************************************************************************************

template <typename T>
Stack<T>::~Stack()
{
    delete [] stack;
    stack = nullptr;
    top = -1;
    capacity = 0;
}

//*******************************************************************************************************

template <typename T>
bool Stack<T>::push(const T &dataIn)
{
    bool success = false;
    
    if(top +1 < capacity)
    {
        top++;
        stack[top] = dataIn;
        success = true;
    }
    return success;
}

//*******************************************************************************************************

template <typename T>
bool Stack<T>::pop(T & dataOut)
{
    bool success = false;
    
    if(top > -1)
    {
        dataOut = stack[top];
        top--;
        success = true;
    }
    return success;
}

//*******************************************************************************************************

template <typename T>
bool Stack<T>::peek(T &dataOut) const
{
    bool success = false;
    
    if(top != -1)
    {
        dataOut = stack[top];
        success = true;
    }
    return success;
}

//*******************************************************************************************************

template <typename T>
bool Stack<T>::isEmpty() const
{
    return top == -1;
}

//*******************************************************************************************************

template <typename T>
bool Stack<T>::isFull() const
{
    return top + 1 == capacity;
}

//*******************************************************************************************************

template <typename T>
int Stack<T>::getSize() const
{
    return top + 1;
}

//*******************************************************************************************************

template <typename T>
bool Stack<T>::clearList()
{
    bool success = false;
    
    if (top > -1)
    {
        top = -1;
        success = true;
    }
    
    return success;
}

//*******************************************************************************************************

#endif
