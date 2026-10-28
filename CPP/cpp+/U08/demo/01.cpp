#include <iostream>
#include <sstream>
#include <stdexcept>

class Mycomplex
{
private:
    double real{0.0};
    double image{0.0};

public:
    Mycomplex() = default;
    Mycomplex(double r, double i) : real(r), image(i) {}
    // toString()
    std::string toString() const
    {
        std::ostringstream out;
        out << real << (image >= 0 ? "+" : "") << image << "i";
        return out.str();
    }
    // add()
    Mycomplex add(const Mycomplex &c) const
    {
        return Mycomplex(this->real + c.real, this->image + c.image);
    }
    //+ 重载: operator + ()
    Mycomplex operator+(const Mycomplex &c) const { return add(c); }
    // 函数 foo() 和函数 foo const()  这里要不要加const呢，回去试一下

    Mycomplex &operator+=(const Mycomplex &c)
    {
        this->real += c.real;
        this->image += c.image;
        return *this;
    }

    double &operator[](unsigned int index)
    {
        if (0 == index)
        {
            return real;
        }
        else if (1 == index)
        {
            return image;
        }
        else
        { // 此处存在问题return -1
            std::cerr << "Error : wrong index!" << std::endl;
            // return -1;
            // std::exit(-1);
            // std::terminate();
            throw std::out_of_range("index out of range.");
        }
    }
};

int main()
{
    Mycomplex c1, c2;
    auto c3 = c1 + c2; // c1.add(c2);
    Mycomplex c4(1, 3);
    c4 += c2 += c3;

    std::cout << c4.toString() << std::endl;

    std::cout << "c4: " << c4[0] << " + " << c4[1] << "i" << std::endl;

    c4[0] = 8; // 将实部设为8.0；
    std::cout << "c4: " << c4[0] << " + " << c4[1] << "i" << std::endl;
    return 0;
}