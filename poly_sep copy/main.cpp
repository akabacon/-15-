#include "class_poly.cpp"
int main()
{
    Polynomial s({5, 1, 7}); //3x^2 + x + 3;
    std::cout << s << std::endl;
    Polynomial x(term(2, 3)); //8x^10
    std::cout << x << std::endl;
    Polynomial r = s - x;
    std::cout << r << std::endl;
    r += term(5, 7);
    std::cout << r;
}