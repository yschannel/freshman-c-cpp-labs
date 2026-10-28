#include <iostream>
#include <filesystem>
#include <fstream>

int main()
{
    namespace fs = std::filesystem;

    fs::path input{"012.json"};
    fs::path output{"out.txt"};

    std::cout << fs::current_path() << '\n';

    if (!fs::exists(input))
    {
        std::cerr << "missing out: " << input;
        return 1;
    }

    std::ifstream in{input};
    if (in.fail())
    {
        std::cerr << "cannot open input\n";
        return 1;
    }

    const auto bytes = fs::file_size(input);
    const auto gib = static_cast<double>(bytes) / (1024.0 * 1024.0 * 1024.0);

    std::ofstream out{output};
    if (out.fail())
    {
        std::cerr << "CANNOT OPEN 012.json.";
        return 1;
    }

    out << "file: " << input << '\n';
    out << "bytes: " << bytes << '\n';
    out << std::fixed << std::setprecision(6);
    out << "GiB: " << std::setw(14) << std::setfill('_') << gib << '\n';

    std::cout << "wrote " << output << '\n';
    return 0;
}
