////
//// Created by blueblood on 27.05.2022.
////
//
#ifndef ALLOCATOR_MYALLOCATOR_H
#define ALLOCATOR_MYALLOCATOR_H

#include <map>
#include <memory>

template<typename T>
class MyAllocator {
public:
    typedef T value_type;
    typedef T *pointer;

    MyAllocator(std::map<unsigned int, unsigned int>::const_iterator b,
                std::map<unsigned int, unsigned int>::const_iterator e) : begin(b), end(e) {
        int counter = 0;
        while (begin != end) {
            if (begin->first != 0 && begin->second != 0) {
                memoryDiv.insert(std::make_pair(begin->first, createList(begin->first, begin->second)));
                ++counter;
            } else
                throw std::invalid_argument("size and amount must be > 0");
            begin++;
        }
        if (counter == 0)
            throw std::invalid_argument("wrong map was passed");
    }

    ~MyAllocator() {
        auto start = memoryDiv.begin();
        auto finish = memoryDiv.end();
        while (start != finish) {
            auto ptr = start->second.first;
            while(ptr!=start->second.last) {
                auto ptrToDEL = ptr->pointer.get();
                delete (ptrToDEL);
                ptr = ptr->next;
            }
            start++;
        }
    }

    template<typename U>
    explicit MyAllocator(const MyAllocator<U> &a) {
        int counter = 0;
        while (a.begin != a.end) {
            if (a.begin->first != 0 && a.begin->second != 0) {
                a.memoryDiv.insert(std::make_pair(a.begin->first, createList(a.begin->first, a.begin->second)));
                ++counter;
            } else
                throw std::invalid_argument("size and amount must be > 0");
            a.begin++;
        }
        if (counter == 0)
            throw std::invalid_argument("wrong map was passed");
    }

    pointer allocate(int N) {
        auto start = memoryDiv.begin();
        auto finish = memoryDiv.end();
        while (start != finish) {
            if (start->second.first->size >= N * sizeof(T) && start->second.first->counter != start->second.first->mustBe) {
                auto ptr = start->second.first;
                while(ptr != start->second.last){
                    if(ptr->empty == true) {
                        ptr->empty = false;
                        ptr->counter++;
                        return ptr->pointer.get();
                    }
                    ptr = ptr->next;
                }
//                for (int i = 0; i < start->second.first->counter; ++i) {
//                    ptr = ptr->next;
//                }
//                ptr->empty = false;
//                ptr->counter++;
//                return ptr->pointer.get();
            }
            start++;
        }
        throw std::invalid_argument("No chunks with enough size remaining");
    }


    template<typename U>
    struct rebind {
        typedef MyAllocator<U> other;
    };

    template<typename U>
    void deallocate(U *p, int N) {
        auto start = memoryDiv.begin();
        auto finish = memoryDiv.end();
        while (start != finish) {
            if (start->second.first->size >= N * sizeof(T)) {
                auto ptr = start->second.first;
                while(ptr != start->second.last){
                    if(ptr->pointer.get() == p) {
                        ptr->empty == true;
                        start->second.first->counter--;
                        return;
                    }
                    ptr = ptr->next;
                }
            }
            start++;
        }
        throw std::invalid_argument("no such place to deallocate");
    }

private:
    struct Node {
        std::shared_ptr<T> pointer = nullptr;
        Node *next = nullptr;
        int mustBe = 0;
        int counter = 0;
        bool empty = true;
        std::size_t size = 0;
    };

    struct list {
        Node *first = nullptr;
        Node *last = nullptr;


        [[nodiscard]] bool isEmpty() const {
            return first == nullptr;
        }

        void add(Node *value) {
            if (isEmpty()) {
                first = value;
                last = value;

            } else {
                last->next = value;
                last = value;
            }
        }
    };

    std::map<unsigned int, unsigned int>::const_iterator begin;
    std::map<unsigned int, unsigned int>::const_iterator end;
    std::map<unsigned int, list> memoryDiv;

    list createList(int size, int amount) {
        list l;
        for (int i = 0; i < amount; ++i) {
            Node *chunk = new Node;
            chunk->pointer = static_cast<std::shared_ptr<T>>(new T(size));
            chunk->size = size;
            chunk->mustBe = amount;
            l.add(chunk);
        }
        return l;
    }

};

#endif //ALLOCATOR_MYALLOCATOR_H

