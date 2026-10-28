# 《C++程序设计》Unit 05 - 自定单元作业题目（题目与答卷合一）

> **📌 说明（学生必读）**
> 1. 本文档由你使用自选大语言模型（LLM）基于本单元课件生成；你**可以自由删除、合并、改写题目**，但需保持结构完整。
> 2. **所有解答必须写在本文档的“答题区”**（可粘贴代码、截图链接、运行日志、表格等）。
> 3. 提交物：本 Markdown 文件（或导出PDF）+ 代码工程目录（如有编程题）。
> 4. 如果你使用Markdown会导致格式错乱，也可以将本Markdown文件转换为Word文档之后完成作业。完成之后再将作业导出为PDF。
> 5. 学术诚信：允许使用 LLM 作为辅导与生成草稿，但你必须在“AI 使用记录”中如实记录，并确保自己能解释与复现结果。

---

## 0. 元信息（提交时必填）

*   **课程**：C++程序设计 (Introduction to C++ Programming)
*   **单元**：Unit 05
*   **主题**：More on Classes & Objects (Deep Copy, Move Semantics, Static Members)
*   **学生姓名**：__STUDENT_NAME__ 学号：__STUDENT_ID__
*   **使用的 LLM**：Qwen3.5
*   **生成日期**：2026-03-27
*   **预计投入**：4 小时；实际投入：_5_ 小时

---

## 1. AI 使用记录（必填）

### 1.1 生成用提示词与输入材料
*   **我使用的提示词**：
    "你是C++助教。基于Unit05课件（PPT关于深拷贝/静态成员，PDF关于const/vectors），为自评一般的学生生成6道题。目标高分，偏好算法。使用C++17，需分离.h/.cpp，含单元测试。难度中高，含1道移动语义选做题。"
*   **我提供给模型的材料**：
    *   Unit05 课件/PPT：是 (CPP-Unit05-H2-v1.pptx)
    *   其它材料：是 (Unit05.pdf - Static Assert, Vector, Deep Copy)

### 1.2 我对题目的人工修改
*   **我删除/改写/新增了哪些题目**：
    *   新增了 **题目 5 (Move Semantics)**：虽然课件主要讲 Rule of Three，但为了冲刺高分和 C++17 环境，我要求增加了移动语义的挑战。
    *   改写了 **题目 4**：将纯工程的类设计改为了包含 `apply` 算法函数的 `IntArray`，以符合我的算法偏好。
*   **我为何这样修改**：
    *   为了在保证通过 PPT 核心考点（深拷贝、静态变量）的基础上，利用 C++17 特性拓宽知识面，提升代码效率。

### 1.3 真实性声明（必选一）
*   [x] 我确认：本文档中的答案均可由我本人解释、复现与现场演示
*   [ ] 我确认：若使用了外部代码/同学讨论/网络资料，已在相应题目下标注来源

---

## 2. 本单元知识点对齐（由模型生成，学生可补充）

> **要求**：列出 6–12 条“关键知识点”，并给出课件定位（Slide编号/标题/关键词）

| 序号 | 关键知识点                                                 | 课件定位（Slide编号/标题/关键词）             | 我当前掌握度（1-5） |
| :--- | :--------------------------------------------------------- | :-------------------------------------------- | :------------------ |
| 1    | **Static Members** (Shared state among objects)            | CPP-Unit05-H2-v1.pptx / S16 (Task A)          | 4                   |
| 2    | **Deep Copy vs Shallow Copy** (Resource Management)        | CPP-Unit05-H2-v1.pptx / S18 (Task B)          | 3                   |
| 3    | **Copy Constructor & Assignment Operator** (Rule of Three) | Unit05.pdf / Copy Constructor & Deep Copy     | 3                   |
| 4    | **Resource Acquisition Is Initialization (RAII)**          | CPP-Unit05-H2-v1.pptx / S17 (Dtor)            | 4                   |
| 5    | **C++17 Move Semantics** (Rvalue references, std::move)    | Unit05.pdf (Logic extension) / C++17 Standard | 2 (Learning)        |
| 6    | **Standard Library Containers** (Vector/Array usage)       | Unit05.pdf / The C++ vector class             | 4                   |

---

## 3. 作业题目区（模型生成 + 学生可编辑）

> **题目建议总数**：6 道
> **结构建议**：概念/阅读/编程 (2:1:3)

### 题目 1：Concept & Rule Check (Understanding) 
**对应知识点**：Deep Copy vs Shallow Copy
**课件定位**：Unit05.pdf / CPP-Unit05-H2-v1.pptx (S18)
**题干**：
In C++, when a class manages resources (e.g., a `std::string*` or raw pointer), the default copy operations provided by the compiler can lead to "Shallow Copy." Explain in your own words:
1.  What is the difference between Shallow Copy and Deep Copy?
2.  Why does Shallow Copy lead to "Double Free" errors or Dangling Pointers after the objects are destroyed? Please describe the memory state (Heap/Stack) changes.

**答题区**：
*   **My Answer**:
    > 1.`Shallow Copy`:
    >The compiler simply copies the value of the member variables. If a member is a pointer, it copies the memory address stored in that pointer. So they share the resource.
    > `Deep Copy`:
    >The class explicitly allcates new memory to on the HEAP for the copied object and then copies the actual data from source to the new location. They are completely independent.  
    > 2.`"Double Free"` errors:
    >(1)State: Object A and Object B (the copy) both hold a pointer to the same address 0x1000 on the heap.
    >(2)Destruction of A: Destructor executes `delete` on `0x1000`. The memory is returned to the system.
    >(3)Destruction of B: Destructor attempts to execute `delete` on `0x1000` again.
    >(4)Crash: Since `0x1000` is already freed, the memory manager detects corruption and terminates the program(Undefined Behavior).
    >`"The Dangling Pointer"`:
    >(1)State: Object A and Object B both point to `0x1000`
    >(2)Action: Object A is destroyed, freeing the memory at `0x1000`
    >(3)Result: Object B still holds the address `0x1000`, but that memory is no longer valid or allocated to your program.
    >(4)Consequence: If you try to read or write to Object B's pointer, you are accessing invalid memory, leading to data corruption or segmentation faults.

*   **易错点总结**:
    > When it comes to copy a pointer, you'd better use `new` or other ways to allocate a new memory for the actual data.

### 题目 2：Code Reading & Tracing (Readability) 
**对应知识点**：Static Members & Object Lifetime
**课件定位**：CPP-Unit05-H2-v1.pptx / S16 (Task A)
**题干**：
Analyze the following code snippet. What is the output of the program? Explain the initialization order of static members and why `count` is shared.

**给定代码**：
```cpp
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
```
**答题区**：
*   **Output/Tracing:**:
    > Start Main
    >Object 1 created. Total: 1
    >Object 2 created. Total: 2
    >Object 3 created. Total: 3
    >Mid-Scope Count: 3
    >Object 3 destroyed. Total remains: 3
    >End Main
    >Object 2 destroyed. Total remains: 3
    >Object 1 destroyed. Total remains: 3

*   **Lifecycle Explanation:**:
    > The static member `count` is initialized to `0` exactly once before the `main()` function begins execution. It is stored in static/global data area, not on the stack.Because it is shared among all instances of the class, every time a `Counter` object is constructed, the constructor increments this single, global `count` variable to assign a unique `id`.
    >Crucially, the destructor does not decrement `count`. Therefore, the value of `count` represents the total number of objects created so far, rather than the number of currently active objects. Even when `c3` goes out of scope and is destoryed, `count` remains at `3`. The static variable persists until the program terminates, retaining the highest value it reached during execution. 


---


### 题目 3：Programming (Basic - Static Members) ️
**对应知识点**：Static Members, Encapsulation
**课件定位**：CPP-Unit05-H2-v1.pptx / S16
**任务目标**：
Design a `BankAccount` class that tracks the total balance of all accounts in the bank.
**规格**：
*   **Input**: Initial balance for each account.
*   **Output**: Console log of transactions and final total balance.
*   **Constraints**:
    *   Must separate `.h` and `.cpp`.
    *   Must use `private static double totalBankReserve;`.
    *   Constructor adds to reserve, Destructor subtracts (simulating withdrawal/closure).
*   **验收标准**:
    1.  Compiles with g++17.
    2.  Write a test in `main()` creating 3 accounts with different balances. Print the static `totalBankReserve` before and after destroying one account.

**答题区**：
*   **Design**:
    > private包含账户信息和总金额（static double）,public包含ctor,dtor,get以及简单的账户存取函数 

*   **Code (Key Part)**:
    ```cpp
    //BankAccount.hpp
    #ifndef BANKACCOUNT_H
    #define BANKACCOUNT_H

    #include <iostream>

    class BankAccount {
    private:
      int id;
      double balance;
      static int defaultBankAccount;
      static double totalBankReserve;
    
    public:
      BankAccount();
      BankAccount(double initialbalance);
      ~BankAccount();
    
      void deposit(double amount);
      void withdraw(double amount);
    
      double getBalance() const;
      static double getTotalBankReserve();
    };
    
    #endif
    
    ```

    ```cpp
    //BankAccount.cpp
    #include"BankAccount.hpp"
    #include<iostream>
    
    int BankAccount::defaultBankAccount = 1000;
    double BankAccount::totalBankReserve = 0.0;
    
    BankAccount::BankAccount():id(defaultBankAccount++),balance(0.0){
        std::cout << "Account " << id << " created with initial balance: 0.0" <<     std::endl;
    }
    
    BankAccount::BankAccount(double initialbalance): id(defaultBankAccount++),    balance(initialbalance){
        totalBankReserve += initialbalance;
        std::cout << "Account " << id << " created with initial balance: " <<     initialbalance << std::endl;
    }
    
    BankAccount::~BankAccount(){
        totalBankReserve -= balance;
        std::cout << "Account " << id << " destroyed. Balance removed from bank     reserve." << std::endl;
        std::cout << "Now Total Bank Reserve: " << BankAccount::getTotalBankReserve    () << std::endl;
    }
    
    void BankAccount::deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            totalBankReserve += amount; 
            std::cout << "Deposited " << amount << " to account " << id << ". New     balance: " << balance << std::endl;
        }
    }
    
    void BankAccount::withdraw(double amount){
        if(amount > 0 && amount <= balance){
            balance -= amount;
            totalBankReserve -= amount;
            std::cout << "Withdrew " << amount << " from account " << id << ". New     balance: " << balance << std::endl;
        }else{
            std::cout << "Insufficient funds or invalid amount for account " << id     << "." << std::endl;
            return;
        }
    }
    
    double BankAccount::getBalance() const{
        return balance;
    }
    
    double BankAccount::getTotalBankReserve(){
        return totalBankReserve;
    }
    
    int main(){
        BankAccount acc1(6000.0);
        BankAccount acc2;
        BankAccount acc3{200.0};
    
        std::cout << "Total Bank Reserve after creating 3 accounts: " <<     BankAccount::getTotalBankReserve() << std::endl;
    
        {
            BankAccount Acc4(520.0);
            std::cout << "Total Bank Reserve with Acc4 account: " <<     BankAccount::getTotalBankReserve() << std::endl;
        }
    
        return 0;
    }
    ```

*   **Test Result**:
    > Account 1000 created with initial balance: 6000
    > Account 1001 created with initial balance: 0.0
    > Account 1002 created with initial balance: 200
    > Total Bank Reserve after creating 3 accounts: 6200
    > Account 1003 created with initial balance: 520
    > Total Bank Reserve with Acc4 account: 6720
    > Account 1003 destroyed. Balance removed from bank reserve.
    > Now Total Bank Reserve: 6200
    > Account 1002 destroyed. Balance removed from bank reserve.
    > Now Total Bank Reserve: 6000
    > Account 1001 destroyed. Balance removed from bank reserve.
    > Now Total Bank Reserve: 6000
    > Account 1000 destroyed. Balance removed from bank reserve.
    > Now Total Bank Reserve: 0

---

### 题目 4：Programming (Core - Deep Copy & Algorithm) 


**对应知识点**：Rule of Three, Dynamic Memory, Function Pointers
**课件定位**：Unit05.pdf (Deep Copy) / CPP-Unit05-H2-v1.pptx (S18)
**任务目标**：
Implement a `MathVector` class (similar to `std::vector<int>` but simplified) that manages a dynamic array. Additionally, implement a higher-order function to apply operations on all elements.
**规格**：
*   **Functionality**:
    *   **Rule of Three**: Must implement Destructor, Copy Constructor, and Copy Assignment Operator to prevent memory leaks/shallow copy.
    *   **Algorithm**: Implement `void transform(int (*func)(int))` that applies a given function (e.g., `square`, `increment`) to every element in the internal array.
*   **Constraints**:
    *   Use raw pointers (`int* data`) and `new/delete` (Do NOT use `std::vector` internally).
    *   Must separate `.h` and `.cpp`.
*   **验收标准**:
    1.  Code compiles and runs.
    2.  Write a test proving Deep Copy: Create `v1`, copy to `v2`, modify `v1`. `v2` should remain unchanged (prove different memory addresses).
    3.  Test the `transform` function with `int square(int x) { return x*x; }`.

**答题区**：
*   **Design**:
    > private: 数组指针与数组元素个数 public: rule of three, get, print, transform.
*   **Key Code (Copy Constructor)**:
    ```cpp
    //deepcopy.h
    #ifndef DEEPCOPY_H
    #define DEEPCOPY_H
    
    #include <iostream>
    
    class MathVector {
    private:
      int *data;
      int size;
    
    public:
      MathVector(int size);
      ~MathVector();
      MathVector(const MathVector &other);
      MathVector& operator=(const MathVector& other); //必须用&
    
      int getElement(int idx) const;
      void print();
    
      void transform(int (*func)(int)); //传入函数指针
    };
    
    
    #endif
    
    ```
    ```cpp
    //deepcopy.cpp
    #include "deepcopy.h"
    #include <iostream>
    #include <new>
    
    MathVector::MathVector(int size) : size(size) {
      this->data = new int[size]();
      for (int i = 0; i < size; i++) {
        std::cout << "Element" << i + 1 << ": ";
        std::cin >> this->data[i];
      }
    }
    
    MathVector::~MathVector() { delete[] this->data; }
    
    MathVector::MathVector(const MathVector &other) {
      this->size = other.size;
      this->data = new int[this->size];
      for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
      }
    }
    
    MathVector& MathVector::operator=(const MathVector &other) {
      if (this == &other) {
        return *this;
      }
    
      delete[] data;
    
      size = other.size;
      data = new int[size];
      for (int i = 0; i < size; i++) {
        data[i] = other.data[i];
      }
    
      return *this;
    }
    
    int MathVector::getElement(int idx) const {
      if (idx < 0 || idx >= size) {
        std::cout << "invalid input, return default val (0)\n";
        return 0;
      }
    
      return data[idx];
    }
    
    void MathVector::print() {
      std::cout << "content: ";
      for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
      }
      std::cout << "\n";
    }
    
    void MathVector::transform(int (*func)(int)) {
      for (int i = 0; i < size; i++) {
        data[i] = func(data[i]);
      }
    }
    
    int square(int x) { return x * x; }
    
    int main() {
      MathVector v1(3);
      MathVector v2 = v1;
      v1.transform(square);
      v1.print();
      v2.print();
    
      return 0;
    }

    ```

*   **Test Cases**:
    > Element1: 1
      Element2: 2
      Element3: 3
      content: 1 4 9
      content: 1 2 3
      
---

### 题目 5：Programming (Advanced - Move Semantics)  (Optional)
**对应知识点**：C++11/17 Move Semantics, Rule of Five
**课件定位**：C++17 Standard (Extension of Unit05 resource management)
**题干**：
Extend the `MathVector` class from Question 4 to support Move Semantics (Rule of Five).
**任务目标**：
1.  Implement a Move Constructor and Move Assignment Operator.
2.  The move operations should "steal" the resources from the source object (rvalue) without copying the data.
3.  Set the source object's pointer to `nullptr` after the move.
**验收标准**:
1.  The code must compile without errors.
2.  Demonstrate in `main()` that returning a large `MathVector` from a function does not trigger the Copy Constructor (use print statements to verify "Move" vs "Copy" is called).

**答题区**：
*   **My Implementation**:
    ```cpp
    //move.h
    #ifndef MOVE_H
    #define MOVE_H
    
    #include <iostream>
    
    class MathVector {
    private:
      int *data;
      int size;
    
    public:
      MathVector(int size);
      ~MathVector();
      MathVector(const MathVector &other);
      MathVector &operator=(const MathVector &other); // 必须用&
    
      MathVector(MathVector &&other) noexcept;
      MathVector &operator=(MathVector &&other) noexcept;
      void print_info() const;
    
      int getElement(int idx) const;
      void print();
    
      void transform(int (*func)(int)); //传入函数指针
    };
    
    
    #endif
    
    ```
    ```cpp
    //move.cpp
    #include "move.h"
    #include <iostream>
    #include <new>
    
    MathVector::MathVector(int size) : size(size) {
      this->data = new int[size]();
      for (int i = 0; i < size; i++) {
        std::cout << "Element" << i + 1 << ": ";
        std::cin >> this->data[i];
      }
    }
    
    MathVector::~MathVector() { delete[] this->data; }
    
    MathVector::MathVector(const MathVector &other) {
      this->size = other.size;
      this->data = new int[this->size];
      for (int i = 0; i < this->size; i++) {
        this->data[i] = other.data[i];
      }
    }
    
    MathVector& MathVector::operator=(const MathVector &other) {
      if (this == &other) {
        return *this;
      }
    
      int* new_data = new int[other.size];
      for(int i = 0; i < other.size; ++i) new_data[i] = other.data[i];
      delete[] data;
      data = new_data;
      size = other.size;
      return *this;
    }
    
    MathVector::MathVector(MathVector &&other) noexcept: size(other.size), data(other.data) {
      other.data = nullptr;
      other.size = 0;
      std::cout << "used move ctor" << std::endl;
    }
    
    MathVector &MathVector::operator=(MathVector &&other) noexcept{
      if (this == &other) {
        return *this;
      }
    
      delete[] data;
      data = other.data;
      size = other.size;
    
      other.data = nullptr;
      other.size = 0;
      std::cout << "used move assignment operator." << std::endl;
    }
    
    void MathVector::print_info() const {
       std::cout << "Vector size: " << size << ", data address: " << data << std::endl;
    }
    
    int MathVector::getElement(int idx) const {
      if (idx < 0 || idx >= size) {
        std::cout << "invalid input, return default val (0)\n";
        return 0;
      }
    
      return data[idx];
    }
    
    void MathVector::print() {
      std::cout << "content: ";
      for (int i = 0; i < size; i++) {
        std::cout << data[i] << " ";
      }
      std::cout << "\n";
    }
    
    void MathVector::transform(int (*func)(int)) {
      for (int i = 0; i < size; i++) {
        data[i] = func(data[i]);
      }
    }
    
    int square(int x) { return x * x; }
    
    int main() {
      MathVector v1(3);
      v1.print_info();
      std::cout << "\n";
      MathVector v2(std::move(v1));
      v2.print_info();
    
      std::cout << "\n";
      MathVector v3(2);
      v3.print_info();
      std::cout << "\n";
      v3 = std::move(v2);
      v3.print_info();
      
      return 0;
    }

    ```

*   **Verification**:
    > Element1: 1
    > Element2: 2
    > Element3: 3
    > Vector size: 3, data address: 0x288089b3a30
    > 
    > used move ctor
    > Vector size: 3, data address: 0x288089b3a30
    > 
    > Element1: 2
    > Element2: 4
    > Vector size: 2, data address: 0x288089a9ca0
    > 
    > used move assignment operator.

---

### 题目 6：Reflection & Migration (Short Answer) 
**对应知识点**：Memory Management, Debugging
**题干**：
1.  In the `MathVector` class (Q4), what is the consequence of not checking for self-assignment (`if (this == &other)`) in the Copy Assignment Operator?
2.  Using the concept of `const` (Unit05.pdf), explain why the parameter of the Copy Constructor is `const T&` and what would happen if it was `T&`.

**答题区**：
*   **1. Self-Assignment**:
    > 如果没有自赋值检查，在对象自赋值后，delete[] data 会释放掉源数据，导致后续copy读取已释放内存，从而导致程序崩溃或数据损坏

*   **2. Const in Copy Ctor**:
    > 1.const 保证了copy ctor内部不会意外修改源对象的数据
    > 2.如果去掉const， 该ctor 将无法接受临时对象(rvalue) 或字面量作为参数

---

### 4. 提交清单（提交前自查）
*   [x] 本文档已填写元信息与 AI 使用记录
*   [x] 每题都有“答题区”内容（不会留空）
*   [x] 编程题工程可编译运行，README 写明步骤
*   [x] 至少包含 **3** 个测试/验证记录 (Q3, Q4, Q5)
*   [x] 若引用外部资料/代码，已标注来源