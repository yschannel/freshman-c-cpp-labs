#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // 写入阶段
    {
        ofstream out("data.bin", ios::binary);
        int val = 258; // 0x00000102
        out.write(reinterpret_cast<const char *>(&val), sizeof(val));
        out.close();
    }

    // 读取阶段
    {
        ifstream in("data.bin", ios::binary);
        char buffer[4] = {0};
        in.read(buffer, 3); // 只读3个字节
        cout << "Bytes read: ";
        for (int i = 0; i < 3; ++i)
        {
            printf("%02X ", (unsigned char)buffer[i]);
        }
        cout << endl;

        // 检查 eof 状态
        if (in.eof())
        {
            cout << "EOF flag is set." << endl;
        }
        else
        {
            cout << "EOF flag is NOT set." << endl;
        }
    }
    return 0;
}