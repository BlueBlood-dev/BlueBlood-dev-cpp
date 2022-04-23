//
// Created by blueblood on 23.04.2022.
//
#ifndef CIRCULARBUFFER_CIRCLEITERATOR_H
#define CIRCULARBUFFER_CIRCLEITERATOR_H

template <class T>
class CircleIterator : public std::iterator<std::random_access_iterator_tag, T> {
private:
    T *array = nullptr;
    unsigned long numberOfElements, index, start;
public:
    T *operator->(){return array + (start + index) % numberOfElements;};
    T &operator*(){return array[(start + index) % numberOfElements];};
    explicit CircleIterator(T *values, unsigned long length, unsigned long head, unsigned long index): index(index), array(values), numberOfElements(length), start(head){
    }
    ~CircleIterator() = default;
    CircleIterator &operator++() {index++; return *this;}
    CircleIterator &operator--() {index--; return *this;}
    CircleIterator operator--(int) { CircleIterator obj(*this); operator--(); return obj;}
    CircleIterator operator++(int) { CircleIterator obj(*this); operator++(); return obj;}
    CircleIterator operator-(typename std::iterator<std::random_access_iterator_tag, T>::difference_type df) {return CircleIterator(array, numberOfElements, start, index - df);}
    CircleIterator operator+(typename std::iterator<std::random_access_iterator_tag, T>::difference_type df) {return CircleIterator(array, numberOfElements, start, index + df);}
    typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator-(const CircleIterator<T> &df) {return index - df.index;}
    typename std::iterator<std::random_access_iterator_tag, T>::difference_type operator+(const CircleIterator<T> &df) {return index + df.index;}
    CircleIterator &operator-=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type df) { index -= df; return *this;}
    CircleIterator &operator+=(typename std::iterator<std::random_access_iterator_tag, T>::difference_type df) { index += df; return *this;}
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
