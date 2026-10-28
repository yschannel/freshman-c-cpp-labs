#include <cstring>
#include <fstream>
#include <iostream>

struct StudentRecord {
    char name[16];
    int id;
    double score;
};

int main() {
    StudentRecord records[2]{};
    std::strncpy(records[0].name, "Alice", sizeof(records[0].name) - 1);
    records[0].id = 1001;
    records[0].score = 91.0;
    std::strncpy(records[1].name, "Bob", sizeof(records[1].name) - 1);
    records[1].id = 1002;
    records[1].score = 88.5;

    {
        std::ofstream out{"students.dat", std::ios::binary};
        out.write(reinterpret_cast<const char*>(records), sizeof(records));
    }

    StudentRecord second{};
    {
        std::ifstream in{"students.dat", std::ios::binary};
        const std::streamoff second_offset = sizeof(StudentRecord);
        // 固定长度记录边界稳定，因此比复杂对象更适合作为本单元随机访问示例。
        in.seekg(second_offset, std::ios::beg);
        in.read(reinterpret_cast<char*>(&second), sizeof(second));
    }

    std::cout << second.name << " " << second.id << " " << second.score << '\n';
    return 0;
}
