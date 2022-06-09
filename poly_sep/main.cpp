#include "class_poly.cpp"
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