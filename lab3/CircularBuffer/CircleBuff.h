//
// Created by blueblood on 23.04.2022.
//

#ifndef CIRCULARBUFFER_CIRCLEBUFF_H
#define CIRCULARBUFFER_CIRCLEBUFF_H


#include <iostream>
#include "CircleIterator.h"

template<typename T>
class CircleBuff {
private:
    T *buffer;
    unsigned int size;
    unsigned int start = 0;
    unsigned int last = 0;
    unsigned int numberOfElements = 0;

public:
    explicit CircleBuff(unsigned int size) : size(size) {
        buffer = new T[size];
    }
    friend class CircleIterator<T>;

    virtual ~CircleBuff() {
        delete[] buffer;
    }

    unsigned int decrement(unsigned int index) const{
        if (index == 0)
            return size - 1;
        else
            return --index;
    }

    unsigned int increment(unsigned int index) const{
        if (index + 1 < size)
            return ++index;
        else
            return 0;
    }

    T getBack() {
        return buffer[last];
    }

    T getFront() {
        return buffer[start];
    }

    const T &getFront() const {
        return operator[](start);
    }

    const T &getBack() const {
        return operator[](last);
    }

    unsigned int getBegin() const {
        return start;
    }

    unsigned int getEnd() const {
        return last;
    }

    void popBack() {
        if(numberOfElements == 0)
            std::cout << "You try to popBack() when buffer is already empty" << std::endl;
        else {
            if (last)
                last--;
            else
                last = size - 1;
            numberOfElements--;
        }
    }

    void popFront() {
        if(numberOfElements == 0)
            std::cout << "You try to popFront() when buffer is already empty" << std::endl;
        else {
            start = increment(start);
            numberOfElements--;
        }
    }

    void pushBack(T value) {
        if (numberOfElements == size) {
            resize();
            last = numberOfElements;
            start = 0;
        }
        buffer[last] = value;
        last = increment(last);
        numberOfElements++;
    }

    void pushFront(T value) {
        if (numberOfElements == size) {
            resize();
            start = 0;
            last = numberOfElements;
        }
        start = decrement(start);
        buffer[start] = value;
        numberOfElements++;
    }


    void resize() {
        int newSize = size * 1.5;
        T *newBuffer = new T[newSize];
        int counter = 0;
        for (int i = start; i < size; ++i) {
            newBuffer[counter++] = buffer[i];
        }

        for (int i = 0; i < last; ++i) {
            newBuffer[counter++] = buffer[i];
        }
        buffer = newBuffer;
        size = newSize;
        delete[] newBuffer;
    }

    void testPrint() {
        for (int i = 0; i < size; ++i) {
            std::cout << buffer[i] << " ";
        }
        std::cout << std::endl;
    }
    CircleIterator<T> begin(){
        return CircleIterator<T>(buffer, size, start, 0);
    }
    CircleIterator<T> end(){
        return CircleIterator<T>(buffer, size, start, numberOfElements);
    }

    T operator[](int index) {
        if (index > size - 1 || index < 0)
            throw std::invalid_argument("Wrong index passed");
        return buffer[index];
    }
};


#endif //CIRCULARBUFFER_CIRCLEBUFF_H
