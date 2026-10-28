#include <iostream>
#include <sstream>

class Rational
{
private:
    int Numerator;
    int Denominator;

public:
    Rational(int N, int D)
    {
        if (D == 0)
        {
            throw std::invalid_argument("Denominator could not be 0!");
        }

        bool is_negative = false;
        if (N < 0)
        {
            N = -N;
            is_negative = !is_negative;
        }

        if (D < 0)
        {
            D = -D;
            is_negative = !is_negative;
        }

        int n = N, d = D;
        while (d != 0)
        {
            int temp = d;
            d = n % d;
            n = temp;
        }

        if (n != 0)
        {
            N /= n;
            D /= n;
        }

        if (is_negative)
        {
            N = -N;
        }

        Numerator = N;
        Denominator = D;
    }

    operator double() const
    {
        return static_cast<double>(Numerator) / static_cast<double>(Denominator);
    }

    Rational operator+(const Rational &other) const
    {
        int N = this->Numerator * other.Denominator +
                this->Denominator * other.Numerator;
        int D = this->Denominator * other.Denominator;
        Rational r(N, D);
        return r;
    }

    std::string toString() const
    {
        std::ostringstream out;
        out << this->Numerator << "/" << this->Denominator;
        return out.str();
    }
};

int main()
{
    Rational r(2, -4);
    std::cout << static_cast<double>(r) << std::endl;
    double d = r;
    std::cout << d << std::endl;

    Rational r1(5, 3), r2(3, 5), r3(1, 15);
    Rational r4 = r1 + r2 + r3;
    std::cout << r1.toString() << " + " << r2.toString() << " + "
              << r3.toString() << " = " << r4.toString() << std::endl;
    return 0;
}