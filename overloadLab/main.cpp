#include <iostream>
#include <map>
#include <fstream>

class Polynomial {
private:
    std::map<int, double> pl;
public:

    Polynomial() {
        pl[0] = 0;
    }

    explicit Polynomial(std::map<int, double> pl) : pl(std::move(pl)) {
    }

    Polynomial(const Polynomial &other) {
        pl = other.pl;
    }

    virtual ~Polynomial() = default;

    Polynomial &operator=(const Polynomial &other) = default;

    bool operator==(const Polynomial &other) {
        return pl == other.pl;
    }

    bool operator!=(const Polynomial &other) {
        return pl != other.pl;
    }

    Polynomial &operator+=(const Polynomial &other) {
        for (auto &item: other.pl) {
            pl[item.first] += item.second;
            if (!pl[item.first])
                pl.erase(item.first);
        }
        if (pl.empty())
            pl[0] += 0;
        return *this;
    }

    Polynomial &operator-=(const Polynomial &other) {
        for (auto &item: other.pl) {
            pl[item.first] -= item.second;
            if (!pl[item.first])
                pl.erase(item.first);
        }
        if (pl.empty())
            pl[0] += 0;
        return *this;
    }

    Polynomial &operator-(const Polynomial &other) {
        Polynomial temp = *this;
        return temp -= other;
    }

    friend Polynomial operator-(const Polynomial &first, const Polynomial &second) {
        Polynomial temp = first;
        temp -= second;
        return temp;
    }

    friend Polynomial operator+(const Polynomial &first, const Polynomial &second) {
        Polynomial temp = first;
        temp += second;
        return temp;
    }

    Polynomial &operator*=(const Polynomial &other) {
        Polynomial tmp = Polynomial();
        for (const auto &item: other.pl) {
            for (const auto &element: pl) {
                tmp.pl[item.first + element.first] += item.second * element.second;
                if (!tmp.pl[item.first + element.first])
                    tmp.pl.erase(item.first + element.first);
            }
        }
        if (tmp.pl.empty())
            tmp.pl[0] += 0;
        return *this = tmp;
    }


    friend Polynomial

    operator*(const Polynomial &first, const Polynomial &second) {
        Polynomial temp = first;
        temp *= second;
        return temp;
    }

    Polynomial &operator*=(const double &value) {
        for (auto item: pl) {
            pl[item.first] *= value;
            if (!pl[item.first])
                pl.erase(item.first);
        }
        if (pl.empty())
            pl[0] += 0;
        return *this;
    }

    friend Polynomial operator*(const Polynomial &other, const double &value) {
        Polynomial temp = other;
        temp *= value;
        return temp;
    }

    friend Polynomial operator*(const double &value, const Polynomial &other) {
        Polynomial temp = other;
        temp *= value;
        return temp;
    }

    Polynomial &operator/=(const double &value) {
        if (value == 0)
            throw std::invalid_argument("zero division");
        for (const auto &item: pl) {
            pl[item.first] /= value;
        }
        return *this;
    }

    friend Polynomial operator/(const Polynomial &other, const double &value) {
        Polynomial temp = other;
        temp /= value;
        return temp;
    }

    double operator[](const int &index) {
        if (!pl.count(index))
            return 0;
        return pl[index];
    }

    friend std::ostream &operator<<(std::ostream &out, Polynomial &temp) {
        int counter = 0;
        if (temp.pl[0] == 0 && temp.pl.size() == 1) {
            out << "0\n";
            return out;
        }
        for (auto &item: temp.pl) {
            char oper = item.first > 0 ? '+' : '-';
            if (counter == 0 && item.second != 0) {
                out << item.second << "x^" << item.first << " ";
                counter++;
            } else if (item.second != 0) {
                out << oper << " " << item.second << "x^" << item.first << " ";
            }
        }
        out << "\n";
        return out;
    }

    friend Polynomial &operator>>(std::istream &in, Polynomial &temp) {
        temp.pl.clear();
        int degree;
        double k;
        while (in >> degree, in >> k) {
            temp.pl[degree] += k;
            if (!temp.pl[degree])
                temp.pl.erase(degree);
        }
        if (temp.pl.empty())
            temp.pl[0] += 0;
        return temp;
    }

};

int main() {
    Polynomial temporary = Polynomial();
    std::ifstream in("inp");
    in >> temporary;
    Polynomial tmp = temporary;
    temporary *= tmp;
    std::cout << temporary;
    temporary = temporary * 7;
    std::cout << temporary;
    double value = temporary[2];
    std::cout << value;

}