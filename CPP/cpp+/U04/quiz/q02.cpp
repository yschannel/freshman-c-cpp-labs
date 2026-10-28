#include <iostream>
#include <string>

class DataHolder {
public:
    DataHolder(std::string val) : data(val) {
        std::cout << "[CTOR] DataHolder created with: " << data << "\n";
    }
    
    void update(std::string data) {
        // 注意此处
        data = data; 
        std::cout << "[UPDATE] Inside function, local data = " << data << "\n";
        std::cout << "[UPDATE] Member data is now: " << this->data << "\n";
    }
    
    void show() const {
        std::cout << "[SHOW] Final data: " << data << "\n";
    }

private:
    std::string data;
};

int main() {
    std::cout << "--- Start ---\n";
    DataHolder dh("Initial");
    dh.update("Modified");
    dh.show();
    std::cout << "--- End ---\n";
    return 0;
}