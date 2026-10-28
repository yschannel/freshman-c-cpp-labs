#include <iostream>
#include <string>

class FileHandler {
private:
  std::string filename;
  bool isOpen;

public:
  // 1.ctor
  FileHandler(const std::string &name) : filename(name), isOpen(true) {
    std::cout << "[ctor] opening file: " << filename << "..." << std::endl;
    // 这里通常会执行：filePtr = fopen(name, "r");
  }

  // 2. dtor
  ~FileHandler() {
    if (isOpen) {
      std::cout << "[dtor] closing file: " << filename << "(delete source)"
                << std::endl;
      // 这里通常会执行：fclose(filePtr);
      isOpen = false;
    }
  }

  // 一个简单的成员函数，用来证明对象还活着
    void read() {
        if (isOpen) {
            std::cout << "[读取] 正在从 " << filename << " 读取数据..." << std::endl;
        }
    }
};

// --- 辅助函数：演示局部变量的生命周期 ---
void processFile() {
    std::cout << "\n>>> 进入 processFile 函数" << std::endl;
    
    // 在这里创建对象 (调用构造函数)
    FileHandler myFile("data.txt");
    
    myFile.read();
    
    std::cout << ">>> 即将离开 processFile 函数" << std::endl;
    // 当函数结束时，myFile 超出作用域 (Scope)
    // 此时会自动调用 ~FileHandler()
} 
// <<< myFile 在这里被销毁

// --- 主函数 ---
int main() {
    std::cout << "=== 程序开始 ===" << std::endl;

    // 场景 1: 栈上的对象 (最常用)
    processFile(); 

    std::cout << "\n=== 程序结束前 ===" << std::endl;

    // 场景 2: 动态分配的对象 (需要手动 delete)
    std::cout << "\n>>> 创建堆对象" << std::endl;
    FileHandler* heapFile = new FileHandler("heap_data.csv");
    heapFile->read();

    std::cout << ">>> 准备删除堆对象" << std::endl;
    delete heapFile; // <--- 关键点：手动 delete 会触发析构函数
    
    std::cout << "=== 程序结束 ===" << std::endl;
    return 0;
}
