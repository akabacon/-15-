#include <iostream>
#include <vector>
#include <string>

struct term
{
    int coefficient;
    unsigned exponent;
    term(int c, unsigned e) : coefficient(c), exponent(e) {};
};

class Polynomial
{
  public:
    Polynomial() = default;
    Polynomial(const Polynomial&) = default;
    Polynomial(const std::vector<int>& c) : coefficient(c) {};
    Polynomial(const term t);
    Polynomial(const std::vector<term>& t);

    std::string print() const;

    Polynomial& operator=(const Polynomial& other) = default;
//  ↓↓↓Too lazy to do that
//    Polynomial& operator*=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator+=(const Polynomial& other);
  private:
    std::vector<int> coefficient;
};

Polynomial::Polynomial(const term t) : coefficient(t.exponent + 1)
{
    coefficient[t.exponent] = t.coefficient;
}

Polynomial::Polynomial(const std::vector<term>& t)
{
    for(auto term: t)
        *this += term;
}

std::string Polynomial::print() const
{
    std::string temp;
    for(signed long long i = coefficient.size() - 1; i >= 0; --i) {
        if (coefficient[i] == 0)
            continue;
        if (temp != "")
            temp += " + ";
        if (coefficient[i] != 1 || i == 0)
            temp += std::to_string(coefficient[i]);
        if (i != 0)
            temp += "x^" + std::to_string(i);
    }
    return temp;
}

Polynomial& Polynomial::operator+=(const Polynomial& other)
{
    if(coefficient.size() < other.coefficient.size())
        coefficient.resize(other.coefficient.size());
    for(unsigned i = 0; i < std::min(coefficient.size(), other.coefficient.size()); ++i) {
        coefficient[i] += other.coefficient[i];
    }
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other)
{
    if(coefficient.size() < other.coefficient.size())
        coefficient.resize(other.coefficient.size());
    for(unsigned i = 0; i < std::min(coefficient.size(), other.coefficient.size()); ++i) {
        coefficient[i] -= other.coefficient[i];
    }
    return *this;
}

const Polynomial operator+(const Polynomial& lhs, const Polynomial& rhs)
{
    Polynomial tmp(lhs);
    tmp += rhs;
    return tmp;
}

const Polynomial operator-(const Polynomial& lhs, const Polynomial& rhs)
{
    Polynomial tmp(lhs);
    tmp -= rhs;
    return tmp;
}

std::ostream& operator<<(std::ostream& lhs, const Polynomial& rhs)
{
    return lhs << rhs.print();
}
