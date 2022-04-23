//
// Created by blueblood on 23.04.2022.
//
#ifndef CIRCULARBUFFER_CIRCLEITERATOR_H
#define CIRCULARBUFFER_CIRCLEITERATOR_H

template <class T>
class CircleIterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T *array;
    unsigned long numberOfElements, index, start;
public:
    using DifferenceType =  typename std::iterator<std::random_access_iterator_tag, T>::difference_type;
    explicit CircleIterator(T *values, unsigned long length, unsigned long head, unsigned long index): index(index), array(values), numberOfElements(length), start(head){
    }
    ~CircleIterator() = default;
    T &operator*() const {return array[(start + index) % numberOfElements];};
    T *operator->() const {return array + (start + index) % numberOfElements;};
    CircleIterator &operator++() {index++; return *this;}
    CircleIterator &operator--() {index--; return *this;}
    CircleIterator operator--(int){ CircleIterator obj(*this); operator--(); return obj;}
    CircleIterator operator++(int){ CircleIterator obj(*this); operator++(); return obj;}
    CircleIterator operator-(DifferenceType df) {return CircleIterator(array, numberOfElements, start, index - df);}
    CircleIterator operator+(DifferenceType df) {return CircleIterator(array, numberOfElements, start, index + df);}
    CircleIterator &operator-=(DifferenceType df) { index -= df; return *this;}
    CircleIterator &operator+=(DifferenceType df) { index += df; return *this;}
    DifferenceType operator-(const CircleIterator<T> &df) {return index - df.index;}
    DifferenceType operator+(const CircleIterator<T> &df) {return index + df.index;}
    bool operator==(const CircleIterator &other) const {return index == other.index;}
    bool operator!=(const CircleIterator &other) const {return index != other.index;}
    bool operator<=(const CircleIterator &other) const {return index <= other.index;}
    bool operator>=(const CircleIterator &other) const {return index >= other.index;}
    bool operator<(const CircleIterator &other) const {return index < other.index;}
    bool operator>(const CircleIterator &other) const {return index > other.index;}
    bool operator<=(T *another) const {return index <= another;}
    bool operator>=(T *another) const {return index >= another;}
    bool operator<(T *another) const {return index < another;}
    bool operator>(T *another) const {return index > another;}
};


#endif //CIRCULARBUFFER_CIRCLEITERATOR_H
