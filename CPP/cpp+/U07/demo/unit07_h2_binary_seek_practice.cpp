#include <fstream>
#include <iostream>

int main() {
    const int id = 1001;
    const double score = 82.0;

    {
        std::ofstream out{"student.bin", std::ios::binary};
        // 这里在处理字节表示：int 与 double 按原始字节写入。
        out.write(reinterpret_cast<const char*>(&id), sizeof(id));
        out.write(reinterpret_cast<const char*>(&score), sizeof(score));
    }

    {
        std::fstream io{"student.bin", std::ios::in | std::ios::out | std::ios::binary};
        const std::streamoff score_offset = sizeof(id);
        // 这里在做位置移动：score 位于 id 后面，所以偏移依据是 sizeof(id)。
        io.seekp(score_offset, std::ios::beg);
        double revised = 95.0;
        io.write(reinterpret_cast<const char*>(&revised), sizeof(revised));
    }

    int id_read{};
    double score_read{};
    {
        std::ifstream in{"student.bin", std::ios::binary};
        in.read(reinterpret_cast<char*>(&id_read), sizeof(id_read));
        in.read(reinterpret_cast<char*>(&score_read), sizeof(score_read));
    }

    // 这里在验证修改结果：读回值必须体现 seek 后写入的位置。
    std::cout << "id=" << id_read << ", score=" << score_read << '\n';
    return 0;
}
