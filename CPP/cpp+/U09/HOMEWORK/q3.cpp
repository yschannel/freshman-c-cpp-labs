#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <stdexcept>

class input_error : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;

    const char *what() const noexcept override
    {
        return "input error!";
    }
};

int main()
{
    try
    {
        int n;
        std::cout << "n: ";
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw input_error{"input error"};
        }
        if (n <= 0)
        {
            throw n;
        }
        int m = n;
        double add = 0;
        while (m--)
        {
            int num;
            if (!(std::cin >> num))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw input_error{"input error"};
            }
            add += num;
        }
        std::cout << std::fixed << std::setprecision(2) << add / n << '\n';
    }
    catch (const input_error &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (int e)
    {
        std::cout << "Invalid: " << e << '\n';
    }
    catch (...)
    {
        std::cout << "Unknown error" << '\n';
    }
    return 0;
}