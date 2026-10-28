#include <fstream>
#include <iostream>

int main() {
    const int id = 7;
    const double score = 93.5;

    {
        std::ofstream out{"values.bin", std::ios::binary};
        // 此处写入的是值的原始字节表示，不是字符形式的十进制文本。
        out.write(reinterpret_cast<const char*>(&id), sizeof(id));
        out.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }

    int id2{};
    double score2{};
    {
        std::ifstream in{"values.bin", std::ios::binary};
        in.read(reinterpret_cast<char*>(&id2), sizeof(id2));
        in.read(reinterpret_cast<char*>(&score2), sizeof(score2));
    }

    std::cout << "id=" << id2 << ", score=" << score2 << '\n';
    return 0;
}
