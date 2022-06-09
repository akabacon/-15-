#include <iostream>
#include <vector>
#include <string>

struct Term
{
    int coeff;
    unsigned exp;
    Term(int c, unsigned e) : coeff(c), exp(e) {};
};

class Polynomial
{
  public:
    Polynomial() = default;
    Polynomial(const Polynomial&) = default;
    Polynomial(const std::vector<int>& c) : coeff(c) {};
    Polynomial(const Term t);
    Polynomial(const std::vector<Term>& t);

    std::string print() const;

    Polynomial& operator=(const Polynomial& other) = default;
//  ↓↓↓Too lazy to do that
//    Polynomial& operator*=(const Polynomial& other);
    Polynomial& operator-=(const Polynomial& other);
    Polynomial& operator+=(const Polynomial& other);
  private:
    std::vector<int> coeff;
};

Polynomial::Polynomial(const Term t) : coeff(t.exp + 1)
{
    coeff[t.exp] = t.coeff;
}

Polynomial::Polynomial(const std::vector<Term>& t)
{
    for(auto term: t)
        *this += term;
}

std::string Polynomial::print() const
{
    std::string temp;
    for(signed long long i = coeff.size() - 1; i >= 0; --i) {
        if (coeff[i] == 0)
            continue;
        if (temp != "")
            temp += " + ";
        if (coeff[i] != 1 || i == 0)
            temp += std::to_string(coeff[i]);
        if (i != 0)
            temp += "x^" + std::to_string(i);
    }
    return temp;
}

Polynomial& Polynomial::operator+=(const Polynomial& other)
{
    if(coeff.size() < other.coeff.size())
        coeff.resize(other.coeff.size());
    for(unsigned i = 0; i < std::min(coeff.size(), other.coeff.size()); ++i) {
        coeff[i] += other.coeff[i];
    }
    return *this;
}

Polynomial& Polynomial::operator-=(const Polynomial& other)
{
    if(coeff.size() < other.coeff.size())
        coeff.resize(other.coeff.size());
    for(unsigned i = 0; i < std::min(coeff.size(), other.coeff.size()); ++i) {
        coeff[i] -= other.coeff[i];
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


int main()
{
    Polynomial s({2, 1, 3}); //3x^2 + x + 3;
    std::cout << s << std::endl;
    Polynomial x(Term(8, 10)); //8x^10
    std::cout << x << std::endl;
    Polynomial r = s - x;
    std::cout << r << std::endl;
    r += Term(8, 10);
    std::cout << r;
}