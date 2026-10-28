#include <iostream>
using namespace std;

class Counter {
private:
    static int count; // Declaration
    int id;
public:
    Counter() {
        id = ++count; 
        cout << "Object " << id << " created. Total: " << count << endl;
    }
    ~Counter() {
        cout << "Object " << id << " destroyed. Total remains: " << count << endl;
    }
    static int getCount() { return count; }
};

int Counter::count = 0; // Definition & Initialization

int main() {
    cout << "Start Main" << endl;
    Counter c1, c2;
    {
        Counter c3;
        cout << "Mid-Scope Count: " << Counter::getCount() << endl;
    } // c3 Dtor here
    cout << "End Main" << endl;
    return 0;
}