#include <fstream>
#include <iostream>

int main() {
    const int id = 7;
    double score = 93.5;

    {
        std::fstream file{"record.bin", std::ios::out | std::ios::binary};
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        file.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }

    {
        std::fstream file{"record.bin", std::ios::in | std::ios::out | std::ios::binary};
        const std::streamoff score_offset = sizeof(id);

        // 定位依据：前面先写入了一个 int，所以 double 从 sizeof(int) 处开始。
        file.seekp(score_offset, std::ios::beg);
        double new_score = 100.0;
        file.write(reinterpret_cast<const char*>(&new_score), sizeof(new_score));
    }

    int id2{};
    double score2{};
    {
        std::ifstream in{"record.bin", std::ios::binary};
        in.read(reinterpret_cast<char*>(&id2), sizeof(id2));
        in.read(reinterpret_cast<char*>(&score2), sizeof(score2));
    }

    std::cout << "id=" << id2 << ", score=" << score2 << '\n';
    return 0;
}
