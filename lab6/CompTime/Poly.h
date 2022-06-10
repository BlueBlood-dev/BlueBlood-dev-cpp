//
// Created by blueblood on 10.06.2022.
//

#ifndef COMPTIME_POLY_H
#define COMPTIME_POLY_H

#include <vector>
#include <valarray>


template<const int size>
class Poly {
private:
     std::array<int, size> polynomial;
public:
    constexpr explicit Poly(const std::array<int, size> &input) : polynomial(input) {
        if (polynomial.empty())
            throw std::invalid_argument("wrong input passed");
    }

    friend std::ostream &operator<<(std::ostream &out, const Poly &temp) {

        if (size == 1 && temp.polynomial[0] == 0) {
            out << "0\n";
            return out;
        }

        int counter = 0;
        for (int i = 0; i < size; ++i) {
            char operand = temp.polynomial[i] > 0 ? '+' : '-';
            if (counter == 0 && temp.polynomial[i]) {
                out << temp.polynomial[i] << "x^" << counter << " ";
                ++counter;
            } else if (temp.polynomial[i])
                out << operand << " " << temp.polynomial[i] << "x^" << counter++ << " ";
        }
        out<<"\n";

        return out;
    }


    constexpr int power(int value, int degree) {
        if (degree == 0)
            return 1;
        else
            return value * power(value, degree - 1);
    }


    constexpr int countValue(int dotValue, int degree) {
        if (degree == -1)
            return 0;
        else
            return polynomial[degree] * power(dotValue, degree) + countValue(dotValue, degree - 1);
    }

};


#endif //COMPTIME_POLY_H
