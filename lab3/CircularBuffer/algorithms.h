//
// Created by blueblood on 23.04.2022.
//
#ifndef CIRCULARBUFFER_ALGORITHMS_H
#define CIRCULARBUFFER_ALGORITHMS_H

#include <vector>
#include  <iostream>
#include  <algorithm>

namespace Algs {
    template<class iter, class predic>
    bool any_of(iter begin, iter end, predic p) {
        for (; begin != end; begin++)
            if (p(*begin))
                return true;
        return false;
    }

    template<class iter, class predic>
    bool none_of(iter begin, iter end, predic p) {
        for (; begin != end; begin++)
            if (p(*begin))
                return false;
        return true;
    }

    template<class iter, class T>
    iter find_not(iter begin, iter end, const T &value) {
        for (; begin != end; begin++) {
            if (*begin != value)
                return begin;
        }
        return begin;
    }

    template<class iter, class predic>
    bool one_of(iter begin, iter end, predic p) {
        int counter = 0;
        for (; begin != end; begin++) {
            if (p(*begin)) {
                counter++;
                if (counter > 1)
                    return false;
            }
        }
        return true;
    }

    template<class iter, class predic>
    bool all_of(iter begin, iter end, predic p) {
        for (; begin != end; begin++)
            if (!p(*begin))
                return false;
        return true;
    }

    template<class iter, class T>
    iter find_backwards(iter begin, iter end, const T &value) {
        iter temp = end;
        for (; begin != end; begin++)
            if (*begin == value)
                temp = begin;
        return temp;
    }

    template<class iter, class compareFunc>
    bool is_palindrome(iter begin, iter end, compareFunc comp) {
        if (begin == end)
            return true;
        end--;
        while (begin != end) {
            if (comp(*begin)!=comp(*end))
                return false;
            ++begin;
            if (begin == end)
                break;
            --end;
        }
        return true;
    }

    template<class iter, class predic>
    bool is_partitioned(iter begin, iter end, predic p) {
        for (; begin != end; begin++)
            if (!p(*begin))
                break;
        for (; begin != end; begin++)
            if (p(*begin))
                return false;

        return true;
    }

//with cmp
    template<class iter, class compareFunc>
    bool is_sorted(iter begin, iter end, compareFunc compare) {
        if (begin != end) {
            iter next = begin;
            while (++next != end) {
                if (compare(*next, *begin))
                    return false;
                begin = next;
            }
        }
        return true;
    }

    template<class iter>
    bool is_sorted(iter begin, iter end) {
        if (begin != end) {
            iter nextElement = begin;
            while (++nextElement != end) {
                if (*nextElement < *begin)
                    return false;
                begin = nextElement;
            }
        }
        return true;
    }
}

#endif //CIRCULARBUFFER_ALGORITHMS_H
