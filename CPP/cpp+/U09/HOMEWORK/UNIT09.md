根据你提供的Unit09课件（异常处理）及教学大纲要求，结合你“自评一般、目标高分、偏好算法、C++17”的设定，为你生成的《Unit09-自定单元作业题目》如下。

**设计说明：**
1.  **结构**：共6题（2概念+2读码+2编程），符合6题/4h工作量。
2.  **难度梯度**：题目3为算法基础（求平均值），题目4为进阶（矩阵类），题目5为脚手架形式（Vec3D下标重载），题目6为异常传播机制。
3.  **技术栈**：使用C++17标准，允许STL，不要求分离声明实现，但要求可编译运行。
4.  **脚手架**：题目5（进阶编程题）采用脚手架形式，挖空核心逻辑。

---

### 0. 元信息（提交时必填）

-   **课程**：C++程序设计
-   **单元**：Unit09
-   **主题**：异常处理 (Exception Handling)
-   **学生姓名**：_STUDENT_NAME_ 学号：_STUDENT_ID_
-   **使用的 LLM**：Qwen (通义千问)
-   **生成日期**：2026-05-28
-   **预计投入**：4 小时；**实际投入**：_4_ 小时

---

### 1. AI 使用记录（必填）

#### 1.1 生成用提示词与输入材料
-   **我使用的提示词（粘贴关键提示词即可，不必全部对话）：**
    -   "C++异常处理作业生成，难度适中，目标高分，偏好算法，C++17，6道题，包含脚手架题目"
    -   "基于Unit09 PPT生成概念题：异常匹配顺序、noexcept"
    -   "生成算法题：使用try-catch处理数组越界和除零错误"
    -   "生成Vec3D类异常处理脚手架代码"
-   **我提供给模型的材料：**
    -   Unit09 课件/PPT：是
    -   其它材料（可选）：Unit09.pdf

#### 1.2 我对题目的人工修改（必填）
-   **我删除/改写/新增了题目：**
    -   新增题目 3（算法求平均值）和题目 4（矩阵类）以贴合“偏好算法”。
    -   将题目 5 改写为脚手架形式，挖空 `operator[]` 和 `divide` 函数的核心逻辑。
    -   删除了原模板中关于“文件IO”的题目，聚焦异常机制本身。
-   **我为何这样修改（与个人薄弱点/兴趣/时间约束相关）：**
    -   个人对算法实现更有兴趣，且通过算法题更能锻炼异常捕获的逻辑。
    -   脚手架形式能让我专注于异常处理逻辑，而不是类的基本语法，提高效率。

#### 1.3 真实性声明（必选一）
-   [x] 我确认：本文档中的答案均可由我本人解释、复现与现场演示
-   [x] 我确认：若使用了外部代码/同学讨论/网络资料，已在相应题目下标注来源

---

### 2. 本单元知识点对齐（由模型生成，学生可补充）

| 序号 | 关键知识点                                    | 课件定位（Slide编号/标题/关键词）     | 我当前掌握度（1-5） |
| :--- | :-------------------------------------------- | :------------------------------------ | :------------------ |
| 1    | 异常处理基本语法 (try/throw/catch)            | Slide 5-8 / Syntax Minimal Package    | 4                   |
| 2    | 异常匹配与捕获顺序 (派生类在前)               | Slide 10-11 / Exception Match & Order | 4                   |
| 3    | 标准异常类体系 (std::exception, out_of_range) | Slide 9 / Standard Exception Base     | 4                   |
| 4    | noexcept 与异常传播                           | Slide 17 / noexcept & Propagation     | 3                   |
| 5    | 自定义异常类                                  | Slide 15 / MyBadAlloc                 | 3                   |
| 6    | 异常处理的使用边界 (When to use)              | Slide 4 / Usage Boundary              | 4                   |

---

### 3. 作业题目区（模型生成 + 学生可编辑）

#### 题目 1：概念与规则核对（理解题）
**对应知识点**：异常匹配与捕获顺序
**课件定位**：Slide 10-11 (Exception Match & Order)

**题干**：
请阅读以下代码片段，并回答问题。
```cpp
#include <iostream>
#include <exception>
using namespace std;

class MyException : public exception {};
class DerivedException : public MyException {};

int main() {
    try {
        throw DerivedException();
    } catch (const exception& e) {
        cout << "Caught base exception" << endl;
    } catch (const MyException& e) {
        cout << "Caught MyException" << endl;
    } catch (...) {
        cout << "Caught unknown" << endl;
    }
    return 0;
}
```
1.  上述代码的输出是什么？
2.  如果交换 `catch (const exception& e)` 和 `catch (const MyException& e)` 的位置，输出会改变吗？为什么？
3.  `catch (...)` 的作用是什么？

**答题区**：
-   **我的答案**：
    1.Caught base exception
    2.会改变为Caught MyException；因为C++的异常捕获是严格自上而下顺序匹配的。交换后，`MyException&`被放在了基类`exception`前。当抛出`DerivedException`时，编译器发现它可以隐式转换为`const MyException&`，于是优先在这里完成捕获，就不会再往下匹配`exception`了。
    3.全捕获机制。用来捕获前面特有类型的`catch`块都无法匹配的、任何未知的异常。
-   **我认为易错点是**：捕获顺序与继承关系的匹配规则。
-   **我用一句话总结**：派生异常类，具体异常放在基础异常类型前面

---

#### 题目 2：代码阅读与推演（读码题）
**对应知识点**：异常传播与栈展开
**课件定位**：Slide 12-13 (Exception Propagation)

**题干**：
请分析以下程序的执行流程和输出。
1.  `function3` 抛出 `int` 类型异常后，`function2` 和 `function1` 中的 `statement` 哪些会执行，哪些会被跳过？
2.  最终由哪个 `catch` 块处理？
3.  程序最后输出的 "End" 是在异常处理前还是后？

**给定代码**：
```cpp
#include <iostream>
using namespace std;

void function3() {
    cout << "In function3, throwing int..." << endl;
    throw 42; // 抛出异常
}

void function2() {
    cout << "Enter function2" << endl;
    try {
        function3();
        cout << "Exit function2 normally"; // Q: 这行会执行吗？
    } catch (double d) {
        cout << "Caught double in function2" << endl;
    }
    cout << "Leave function2" << endl;
}

void function1() {
    cout << "Enter function1" << endl;
    try {
        function2();
        cout << "Exit function1 normally" << endl;
    } catch (int i) {
        cout << "Caught int in function1: " << i << endl;
    }
    cout << "Leave function1" << endl;
}

int main() {
    cout << "Start" << endl;
    function1();
    cout << "End" << endl;
    return 0;
}
```

**答题区**：
-   1.会被执行："Enter function1" -> "Enter function2" -> "In function3, throwing int..." -> "Caught int in function1: 42" -> "Leave function1" 被跳过的："Exit function2 normally" "Leave function2" 
"Exit function1 normally"
-   2.`catch (int i)`
-   3.异常处理后

---

#### 题目 3：编程题（必做-算法基础）
**对应知识点**：基本异常处理与算法逻辑
**课件定位**：Slide 5-8 (Syntax Minimal Package)

**任务目标（必须可验收）**：
*   **功能**：编写一个程序，计算用户输入的一组整数的平均值。要求使用异常处理机制。
*   **约束**：
    *   [x] 必须使用 `try`/`throw`/`catch` 结构。
    *   [x] 必须处理除零错误（当输入数量为0时）。
    *   [x] 必须处理非整数输入（使用 `cin.fail()` 检查）。

**规格（由模型给出，必须清晰）**：
*   **输入**：首先输入一个整数 `n` (数量)，然后输入 `n` 个整数。
*   **输出**：如果输入合法，输出平均值（保留两位小数）；如果非法，输出错误信息。
*   **边界条件**：`n <= 0` 或者输入非数字。
*   **禁止事项**：禁止使用 `exit(0)` 直接退出，必须用异常处理流程控制。

**推荐工程结构**：
*   `main.cpp` (单一文件即可)

**最低验收标准（至少满足这些）**：
1.  能编译通过（命令：`g++ -std=c++17 main.cpp -o main`）。
2.  至少 3 个测试用例：
    *   测试1：正常输入（如 n=3, 数字 1 2 3） -> 期望输出 2.00。
    *   测试2：n=0 -> 期望捕获除零/逻辑错误。
    *   测试3：输入非数字（如 n=2, 然后输入 a b） -> 期望捕获输入错误。
3.  关键输出截图/日志片段（贴在答题区）。

**答题区**：
*   **代码**：
```cpp
#include <iomanip>
#include <ios>
#include <iostream>
#include <limits>
#include <stdexcept>

class input_error : public std::runtime_error
{
public:
    using std::runtime_error::runtime_error;

    const char *what() const noexcept override
    {
        return "input error!";
    }
};

int main()
{
    try
    {
        int n;
        std::cout << "n: ";
        std::cin >> n;
        if (std::cin.fail())
        {
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            throw input_error{"input error"};
        }
        if (n <= 0)
        {
            throw n;
        }
        int m = n;
        double add = 0;
        while (m--)
        {
            int num;
            if (!(std::cin >> num))
            {
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                throw input_error{"input error"};
            }
            add += num;
        }
        std::cout << std::fixed << std::setprecision(2) << add / n << '\n';
    }
    catch (const input_error &e)
    {
        std::cout << e.what() << '\n';
    }
    catch (int e)
    {
        std::cout << "Invalid: " << e << '\n';
    }
    catch (...)
    {
        std::cout << "Unknown error" << '\n';
    }
    return 0;
}
```    
*   **测试用例与结果**：
例1.
n: 3
1 2 3
2.00
例2.
n: 0
Invalid: 0
例3.
n: 2
a b
input error!
*   **我遇到的 bug 与修复记录（至少 1 条）**：
   构造异常类未加上using std::runtime_error::runtime_error;导致报错（类中无构造函数）

---

#### 题目 4：编程题（必做-算法进阶）
**对应知识点**：标准异常类与数组越界
**课件定位**：Slide 9, 15 (Standard Exception & MyBadAlloc)

**任务目标**：
*   **功能**：实现一个简单的 `Matrix`（矩阵）类，支持构造、析构和元素访问。在元素访问时进行边界检查。
*   **约束**：
    *   [x] 使用 `std::vector` 存储数据（C++17允许）。
    *   [x] `at(int row, int col)` 方法在越界时抛出 `std::out_of_range` 异常。
    *   [x] 构造函数参数为行数和列数。

**规格**：
*   **输入**：无（在 `main` 中构造对象并测试）。
*   **输出**：正常访问输出值；越界访问捕获异常并输出信息。
*   **边界条件**：行或列索引超出范围。

**推荐工程结构**：
*   `matrix.cpp`

**最低验收标准**：
1.  能编译通过。
2.  至少 2 个测试用例：
    *   测试1：正常访问 `mat.at(0,0)`。
    *   测试2：越界访问 `mat.at(10,10)` -> 捕获 `out_of_range`。
3.  代码中必须包含 `#include <stdexcept>` 和 `#include <vector>`。

**答题区**：
*   **代码**：
```cpp
#include <iostream>
#include <stdexcept>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> m;
    int row;
    int col;

public:
    Matrix(int row = 0, int col = 0) : row(row), col(col)
    {
        if (this->row < 0 || this->col < 0)
        {
            this->row = 0;
            this->col = 0;
        }
        m.assign(row, std::vector<double>(col, 0.0));
    }

    ~Matrix() = default;

    void input()
    {
        if (row > 0 && col > 0)
        {
            for (int i = 0; i < row; i++)
            {
                std::cout << "Row" << i << " (e.g. 1.0 2.0 3.0): ";
                for (int j = 0; j < col; j++)
                {
                    std::cin >> m[i][j];
                }
            }
        }
    }

    double &operator()(int r, int c)
    {
        if (r < 0 || r > row || c < 0 || c > col)
        {
            throw std::out_of_range{"Matrix index out of range !"};
        }
        return m[r][c];
    }
};

int main()
{
    Matrix mat(2, 2);
    try
    {
        std::cout << mat(0, 0) << '\n';
        std::cout << mat(10, 10) << '\n';
    }
    catch (const std::out_of_range &e)
    {
        std::cout << e.what() << '\n';
    }

    return 0;
}
```
*   **测试用例与结果**：
   0
   Matrix index out of range !
*   **我遇到的 bug 与修复记录**：
   std::out_of_range{};  忘记传参了。
---

#### 题目 5：编程题（选做/进阶-脚手架形式）
**对应知识点**：自定义异常类与运算符重载
**课件定位**：Slide 15 (MyBadAlloc) & Slide 7 (Vec3D)

**题干**：
基于课件中的 `Vec3D` 示例，我们扩展为 `VectorN`（N维向量），并使用自定义异常类。
**任务**：补全代码中的 `TODO` 部分。
1.  在 `VectorN::operator[]` 中，如果索引越界，抛出 `IndexOutOfBoundsException`。
2.  在 `main` 函数中，捕获该异常并打印信息。

**脚手架代码（补全以下逻辑）**：
```cpp
#include <iostream>
#include <vector>
#include <string>

// TODO 1: 定义自定义异常类 IndexOutOfBoundsException
// 要求：公有继承 std::exception
// 要求：重写 what() 方法，返回 "Index out of range"

// ==========================================
// VectorN 类定义
// ==========================================
class VectorN {
private:
    std::vector<double> data_;
    size_t size_;

public:
    VectorN(size_t n) : size_(n), data_(n, 0.0) {}

    // TODO 2: 实现 operator[] (非const版本)
    // 逻辑：检查 index >= size_，如果是，抛出 TODO 1 定义的异常
    // 否则，返回 data_[index]
};

// ==========================================
// 主函数
// ==========================================
int main() {
    VectorN vec(3); // 创建3维向量

    try {
        // 这行应该正常
        vec[0] = 1.0;
        std::cout << "vec[0] assigned." << std::endl;

        // 这行应该抛出异常
        vec[5] = 5.0; 
        std::cout << "vec[5] assigned." << std::endl;

    } 
    // TODO 3: 捕获 TODO 1 定义的异常类型
    // 逻辑：打印 "Caught exception: " << e.what()
    catch (const std::exception& e) {
        std::cout << "Caught std::exception: " << e.what() << std::endl;
    }

    return 0;
}
```

**答题区**：
*   **我补全的代码逻辑（粘贴替换部分）**：
```cpp
// TODO 1: 定义自定义异常类 IndexOutOfBoundsException
// 要求：公有继承 std::exception
// 要求：重写 what() 方法，返回 "Index out of range"
class IndexOutOfBoundsException : public std::exception
{
public:
    const char *what() const noexcept override
    {
        return "Index out of range";
    }
};

    // TODO 2: 实现 operator[] (非const版本)
    // 逻辑：检查 index >= size_，如果是，抛出 TODO 1 定义的异常
    // 否则，返回 data_[index]
    double &operator[](size_t index)
    {
        if (index >= size_)
        {
            throw IndexOutOfBoundsException{};
        }
        return data_[index];
    }

    // TODO 3: 捕获 TODO 1 定义的异常类型
    // 逻辑：打印 "Caught exception: " << e.what()
    catch (const IndexOutOfBoundsException &e)
    {
        std::cout << "Caught exception: " << e.what() << std::endl;
    }
```
*   **运行结果**：
vec[0] assigned.
Caught exception: Index out of range

---

#### 题目 6：反思与迁移（简答）
**对应知识点**：异常安全与 noexcept
**课件定位**：Slide 17 (noexcept)

**题干**：
1.  什么是 `noexcept` 规约？如果一个被声明为 `noexcept` 的函数内部抛出了异常，会发生什么？
2.  为什么说“异常处理不应用于普通的控制流程（如循环终止）”？请结合算法题（题目3或4）说明，如果用 `throw` 来代替 `if (n <= 0)` 判断，会有什么坏处？

**答题区**：
1. 显示承诺一个函数不会抛出异常；如果该异常没有在函数内被捕获，程序会直接调用`std::terminate()`强制崩溃终止，而且外层的`try-catch`也无法捕获。
2.  应用于普通的控制流程会有以下坏处：1.因分配对象和进行栈展开导致开销极大，性能极大；2.异常只用于意料之外的致命错误，不适用于普通的判断；3.强行用`throw`代替`if`导致必须编写`try-catch`块来捕获，导致可读性下降。

---

### 4. 提交清单（提交前自查）📦
*   [x] 本文档已填写元信息与 AI 使用记录
*   [x] 每题都有“答题区”内容（不会留空）
*   [x] 编程题工程可编译运行，README 写明步骤
*   [x] 至少包含 5 个测试/验证记录（题目3、4、5合计）
*   [x] 若引用外部资料/代码，已标注来源