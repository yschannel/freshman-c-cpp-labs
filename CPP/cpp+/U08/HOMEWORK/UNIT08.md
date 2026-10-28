# 《C++程序设计》Unit08-运算符重载作业题目（题目与答卷合一）

> **📌 说明（学生必读）**
> 1. 本文档由你使用自选大语言模型（LLM）基于本单元课件生成；你**可以自由删除、合并、改写题目**，但需保持结构完整。
> 2. **所有解答必须写在本文档的“答题区”**（可粘贴代码、截图链接、运行日志、表格等）。
> 3. 提交物：本 Markdown 文件（或导出PDF）+ 代码工程目录（如有编程题）。
> 4. 如果你使用Markdown会导致格式错乱，也可以将本Markdown文件转换为Word文档之后完成作业。完成之后再将作业导出为PDF。
> 5. 学术诚信：允许使用 LLM 作为辅导与生成草稿，但你必须在“AI 使用记录”中如实记录，并确保自己能解释与复现结果。

---

## 0. 元信息（提交时必填）

- **课程**：C++程序设计
- **单元**：Unit08（运算符重载）
- **主题**：Operator Overloading & Mathematical Abstractions
- **学生姓名**：__STUDENT_NAME__ 学号：__STUDENT_ID__
- **使用的 LLM**：Qwen (本模型)
- **生成日期**：2026-05-01
- **预计投入**：6 小时；**实际投入**：_8_ 小时

---

## 1. AI 使用记录（必填）

### 1.1 生成用提示词与输入材料
- **我使用的提示词（粘贴关键提示词即可，不必全部对话）：**
    - 1.是；考试倾向请参考我发给你的单元pptx；
      2.自评为一般；目标是冲刺挑战
      3.预计投入6h；希望题目数量为7题
      4.我更喜欢算法风格，这个单元我想更贴合类似ppt数学上的概念实现
      5. 编译器g++17; 必须；允许；不用分离；是
- **我提供给模型的材料：**
    - Unit08 课件/PPT：是（基于提供的Unit08.pdf及CPP-Unit08_cc.pptx内容）
    - 其它材料（可选）：无

### 1.2 我对题目的人工修改（必填）
- **我删除/改写/新增了哪些题目：**
    - 将基础的Vector题目改为了Matrix矩阵题目
- **我为何这样修改（与个人薄弱点/兴趣/时间约束相关）：**
    - 为了挑战更复杂的内存管理和深拷贝逻辑

### 1.3 真实性声明（必选一）
- [x] 我确认：本文档中的答案均可由我本人解释、复现与现场演示
- [x] 我确认：若使用了外部代码/同学讨论/网络资料，已在相应题目下标注来源

---

## 2. 本单元知识点对齐（由模型生成，学生可补充）

> **要求**：列出 6–12 条“关键知识点”，并给出课件定位（Slide编号/标题/关键词）

| 序号 | 关键知识点                                       | 课件定位（Slide编号/标题/关键词）    | 我当前掌握度（1-5） |
| :--- | :----------------------------------------------- | :----------------------------------- | :------------------ |
| 1    | 运算符重载的本质（表达式 -> 函数调用）           | PPT S01-S03 (Expression to Function) | 3                   |
| 2    | 二元算术运算符 (`+`, `+=`) 的原型与实现          | PPT S06 (Operator+, Operator+=)      | 4                   |
| 3    | 下标运算符 `[]` 的读写特性与引用返回             | PPT S08 (Operator[])                 | 4                   |
| 4    | 流插入/提取运算符 (`<<`, `>>`) 的非成员/友元实现 | PPT S18 (Operator<<)                 | 4                   |
| 5    | 自增/自减运算符 (前置/后置) 的区分与实现         | PPT S17 (Prefix/Postfix ++)          | 4                   |
| 6    | 赋值运算符 `=` 与深拷贝 (虽然默认足够，但需掌握) | PPT S19 (Operator=)                  | 5                   |
| 7    | 类型转换运算符 (Type Conversion)                 | PPT (补充/扩展点)                    | 5                   |
| 8    | 左值与右值引用在运算符重载中的应用 (C++11)       | PPT (补充/扩展点)                    | 4                   |

---

## 3. 作业题目区（模型生成 + 学生可编辑）

> **题目建议总数**：7 题
> **结构建议**：概念/阅读/编程 各至少 1 题；编程题至少 2 题（必做 + 选做）

### 题目 1：概念与规则核对（理解题）✅
**对应知识点**：运算符重载限制与语义
**课件定位**：PPT S02 (Why Operator Overloading), S04 (Restrictions)

**题干**：
根据Unit08课件内容，判断以下说法是否正确，并解释原因：
1.  我可以重载 `**` 运算符来表示矩阵的乘方运算。
2.  重载运算符 `+` 时，为了提高效率，我应该返回一个引用 `T&`。
3.  运算符重载可以改变运算符的优先级。

**答题区**：
- **我的答案**：
  1.错误；不可以重载C++中不存在的内置运算符。
  2.错误；重载+运算符时通常会在函数内部创建一个局部对象来返回运算结果，如果返回局部对象的引用，当函数执行结束时，这个对象将会被析构，此时返回的引用就会变成悬空引用，导致程序出现未定义行为。
  3.错误；运算符的优先级不能被改变，重载运算符只能改变行为。
- **我认为易错点是**：误重载不存在运算符；未考虑返回对象生命周期。
- **我用一句话总结**：运算符重载需重点分析返回值的性质。

---

### 题目 2：代码阅读与推演（读码题）🔎
**对应知识点**：前置与后置自增运算符、对象生命周期
**课件定位**：PPT S17 (Prefix/Postfix ++)

**题干**：
1.  写出程序的输出结果。
2.  解释 `MyComplex& operator++()` 和 `MyComplex operator++(int)` 的区别是如何在输出中体现的。

**给定代码**：
```cpp
#include <iostream>
using namespace std;

class Counter {
    int val;
public:
    Counter(int v=0): val(v) {}
    Counter& operator++() { // 前置
        ++val;
        cout << "Prefix: " << val << " ";
        return *this;
    }
    Counter operator++(int) { // 后置
        Counter old = *this;
        ++(*this); // 复用前置
        cout << "Postfix(temp): " << old.val << " ";
        return old;
    }
    int get() const { return val; }
};

int main() {
    Counter c(5);
    cout << (c++).get() << endl;
    cout << (++c).get() << endl;
    return 0;
}
```

**答题区**：
- **我的答案**：
  1.
  Prefix: 6 Postfix(temp): 5 5
  Prefix: 7 7
  2.前置输出自增后对象的本身；后置输出自增前对象状态
  


  


### 题目 3：编程题（必做）- 矩阵类 (Matrix) 的基础实现

**对应知识点**：二元算术运算符 (+)、流插入运算符 (<<)、构造函数
**课件定位**：PPT S06 (Overloading General Binary Arithmetic Operators), S18 (Overloading <<)

**任务目标**：
实现一个动态二维矩阵类 `Matrix`，支持矩阵的加法和输出。

**规格**：
*   **功能**：实现 `Matrix` 类，包含构造函数、析构函数（若用裸指针）、`operator+` 和 `operator<<`。
*   **约束**：
    *   使用 `std::vector<std::vector<double>>` 作为底层存储（符合C++17且更安全）。
    *   `operator+` 需检查矩阵维度是否一致，不一致时抛出异常或输出错误。
*   **输入**：矩阵的行数、列数，以及初始化数据（默认构造为0矩阵）。
*   **输出**：重载 `<<` 输出矩阵，重载 `+` 实现矩阵加法。

**推荐工程结构**：
*   单文件实现（main.cpp）

**最低验收标准**：
1.  **能编译通过**：`g++ -std=c++17 -o matrix main.cpp`
2.  **至少 2 个测试用例**：
    *   Test 1: 创建两个 2x2 矩阵并相加，打印结果。
    *   Test 2: 尝试将 2x2 矩阵与 3x3 矩阵相加，验证错误处理。

**答题区**：
*   **代码**：
```cpp
#include <iostream>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> mat;
    int row;
    int column;

public:
    Matrix(int row = 0, int column = 0) : row(row), column(column)
    {

        // 隐式处理异常
        if (this->row < 0 || this->column < 0)
        {
            this->row = 0;
            this->column = 0;
        }

        mat = std::vector<std::vector<double>>(this->row, std::vector<double>(this->column));
    }

    void input()
    {
        if (row > 0 && column > 0)
        {
            for (int i = 0; i < row; i++)
            {
                std::cout << "Row" << i << " (e.g. 1.0 2.0 3.0): ";
                for (int j = 0; j < column; j++)
                {
                    std::cin >> mat[i][j];
                }
            }
        }
    }

    bool is_equal(const Matrix &other) const
    {
        if (this->row == other.row && this->column == other.column)
        {
            return true;
        }

        return false;
    }

    Matrix operator+(const Matrix &other) const
    {
        if (!is_equal(other))
        {
            std::cerr << "row or column Not equal!!! output default:{}" << std::endl;
            return Matrix(0, 0);
        }

        Matrix m(this->row, this->column);

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                m.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }

        return m;
    }

    friend std::ostream &operator<<(std::ostream &e, const Matrix &m);
};

std::ostream &operator<<(std::ostream &e, const Matrix &m)
{
    if (m.row <= 0 || m.column <= 0)
    {
        e << "{0}";
        return e;
    }

    for (int i = 0; i < m.row; i++)
    {
        e << "{";
        for (int j = 0; j < m.column; j++)
        {
            e << m.mat[i][j];
            if (j != m.column - 1)
            {
                e << ",";
            }
            else
            {
                e << "}";
                e << "\n";
            }
        }
    }

    return e;
}

int main()
{
    std::cout << "---Test 1---" << std::endl;
    Matrix m1(2, 2);
    m1.input();
    Matrix m2(2, 2);
    m2.input();
    Matrix m3 = m1 + m2;
    std::cout << "result:\n"
              << m3 << std::endl;

    std::cout << "---Test 2---" << std::endl;
    Matrix m4(3, 3);
    Matrix m5 = m3 + m4;
}
```
*   **测试用例与结果**：
    ---Test 1---
    Row0 (e.g. 1.0 2.0 3.0): 0 3
    Row1 (e.g. 1.0 2.0 3.0): 5 7
    Row0 (e.g. 1.0 2.0 3.0): 1 5
    Row1 (e.g. 1.0 2.0 3.0): 9 8
    result:
    {1,8}
    {14,15}
    
    ---Test 2---
    row or column Not equal!!! output default:{}
*   **我遇到的 bug 与修复记录（至少 1 条）**：
  写Matrix operator+(const Matrix &other) const最后没加const报错
  m.mat[i][j] = this->mat[i][j] + other.mat[i][j];写成m.mat[i][j] += other.mat[i][j];
  

### 题目 4：编程题（必做）- 下标访问与赋值

**对应知识点**：下标运算符 `[]`、赋值运算符 `=`
**课件定位**：PPT S08 (Overloading [] Operator), S19 (Overloading the = Operator)

**任务目标**：
在题目3的 `Matrix` 类基础上，增加下标访问和赋值功能。

**规格**：
*   **功能**：
    *   重载 `operator()`（推荐，因为 `operator[]` 返回引用在二维数组中较复杂），使其支持 `mat(i, j) = value` 的访问。
    *   显式重载赋值运算符 `operator=`，打印日志 "Assignment Operator Called"，并实现深拷贝逻辑。
*   **验证**：证明赋值后的两个对象内存独立（修改B不影响A）。

**最低验收标准**：
1.  **能编译运行**。
2.  **验证步骤**：
    *   创建 Matrix A (2x2)。
    *   Matrix B = A。
    *   修改 B(0,0) 的值。
    *   打印 A(0,0)，确认 A 未改变。

**答题区**：
*   **设计说明**：
  见 double &operator()(int r, int c) 
    double operator()(int r, int c) const 
    Matrix &operator=(const Matrix &other)
*   **代码**：
```cpp
#include <iostream>
#include <vector>

class Matrix
{
private:
    std::vector<std::vector<double>> mat;
    int row;
    int column;

public:
    Matrix(int row = 0, int column = 0) : row(row), column(column)
    {

        // 隐式处理异常
        if (this->row < 0 || this->column < 0)
        {
            this->row = 0;
            this->column = 0;
        }

        mat = std::vector<std::vector<double>>(this->row, std::vector<double>(this->column));
    }

    void input()
    {
        if (row > 0 && column > 0)
        {
            for (int i = 0; i < row; i++)
            {
                std::cout << "Row" << i << " (e.g. 1.0 2.0 3.0): ";
                for (int j = 0; j < column; j++)
                {
                    std::cin >> mat[i][j];
                }
            }
        }
    }

    bool is_equal(const Matrix &other) const
    {
        if (this->row == other.row && this->column == other.column)
        {
            return true;
        }

        return false;
    }

    Matrix operator+(const Matrix &other) const
    {
        if (!is_equal(other))
        {
            std::cerr << "row or column Not equal!!! output default:{}" << std::endl;
            return Matrix(0, 0);
        }

        Matrix m(this->row, this->column);

        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                m.mat[i][j] = this->mat[i][j] + other.mat[i][j];
            }
        }

        return m;
    }

    friend std::ostream &operator<<(std::ostream &e, const Matrix &m);

    double &operator()(int r, int c) { return mat[r][c]; }      // 读写
    double operator()(int r, int c) const { return mat[r][c]; } // 只读

    Matrix &operator=(const Matrix &other)
    {
        std::cout << "Assignment Operator Called" << std::endl;
        if (this != &other)
        {
            this->row = other.row;
            this->column = other.column;
            mat = other.mat; // vector自动深拷贝
        }

        /*this->row = other.row;
        this->column = other.column;
        mat = std::vector<std::vector<double>>(
            this->row, std::vector<double>(this->column, 0.0));
        for (int i = 0; i < this->row; i++)
        {
            for (int j = 0; j < this->column; j++)
            {
                this->mat[i][j] = other.mat[i][j];
            }
        }
        */

        return *this;
    }
};

std::ostream &operator<<(std::ostream &e, const Matrix &m)
{
    if (m.row <= 0 || m.column <= 0)
    {
        e << "{0}";
        return e;
    }

    for (int i = 0; i < m.row; i++)
    {
        e << "{";
        for (int j = 0; j < m.column; j++)
        {
            e << m.mat[i][j];
            if (j != m.column - 1)
            {
                e << ",";
            }
        }
        e << "}";
        e << "\n";
    }

    return e;
}

int main()
{
    Matrix A(2, 2);
    A.input();
    Matrix B(2, 2);
    B = A;
    B(0, 0) = -1;
    std::cout << B << std::endl;
    std::cout << A << std::endl;
    return 0;
}
```
*   **测试结果与日志**：
    Row0 (e.g. 1.0 2.0 3.0): 1 2
    Row1 (e.g. 1.0 2.0 3.0): 3 4
    Assignment Operator Called
    {-1,2}
    {3,4}
    
    {1,2}
    {3,4}
  

### 题目 5：编程题（选做/进阶）- 有理数类与类型转换

**对应知识点**：类型转换运算符、算术运算符、GCD
**课件定位**：PPT (扩展点：Overloading Object Converting Operator)

**任务目标**：
实现一个有理数类 `Rational`（分数），支持自动约分和类型转换。

**规格**：
*   **功能**：
    *   构造函数接收分子分母，自动计算最大公约数（GCD）进行约分。
    *   重载 `operator double()`，将分数转换为小数。
    *   重载 `operator+` 支持分数加分数。
*   **约束**：分母不能为0，需处理负数情况（负号统一在分子）。

**最低验收标准**：
1.  `Rational r(2, 4); cout << r;` 输出 `1/2`。
2.  `double d = r;` 能正确转换为 `0.5`。

**答题区**：
*   **代码**：
```cpp
#include <iostream>
#include <sstream>

class Rational
{
private:
    int Numerator;
    int Denominator;

public:
    Rational(int N, int D)
    {
        if (D == 0)
        {
            throw std::invalid_argument("Denominator could not be 0!");
        }

        bool is_negative = false;
        if (N < 0)
        {
            N = -N;
            is_negative = !is_negative;
        }

        if (D < 0)
        {
            D = -D;
            is_negative = !is_negative;
        }

        int n = N, d = D;
        while (d != 0)
        {
            int temp = d;
            d = n % d;
            n = temp;
        }

        if (n != 0)
        {
            N /= n;
            D /= n;
        }

        if (is_negative)
        {
            N = -N;
        }

        Numerator = N;
        Denominator = D;
    }

    operator double() const
    {
        return static_cast<double>(Numerator) / static_cast<double>(Denominator);
    }

    Rational operator+(const Rational &other) const
    {
        int N = this->Numerator * other.Denominator +
                this->Denominator * other.Numerator;
        int D = this->Denominator * other.Denominator;
        Rational r(N, D);
        return r;
    }

    std::string toString() const
    {
        std::ostringstream out;
        out << this->Numerator << "/" << this->Denominator;
        return out.str();
    }
};

int main()
{
    Rational r(2, -4);
    std::cout << static_cast<double>(r) << std::endl;
    double d = r;
    std::cout << d << std::endl;

    Rational r1(5, 3), r2(3, 5), r3(1, 15);
    Rational r4 = r1 + r2 + r3;
    std::cout << r1.toString() << " + " << r2.toString() << " + "
              << r3.toString() << " = " << r4.toString() << std::endl;
    return 0;
}
```
*   **测试结果**：
-0.52.5
5/3 + 3/5 + 1/15 = 7/3
  

### 题目 6：编程题（选做/挑战）- 流提取与异常处理

**对应知识点**：流提取 `>>`、异常处理 (try-catch)
**课件定位**：PPT S18 (Overloading << and >>), PPT (补充：异常)

**任务目标**：
完善 `Matrix` 类，支持从标准输入读取矩阵。

**规格**：
*   **功能**：重载 `operator>>`。
*   **约束**：
    *   输入时先输入行和列，再输入数据。
    *   如果输入的数据个数不足，抛出异常并被捕获。
*   **要求**：`operator>>` 必须是友元函数。

**最低验收标准**：
1.  能通过 `cin >> mat` 构建矩阵。
2.  能捕获并处理输入错误（如输入非数字字符）。

**答题区**：
*   **代码**：
```cpp
#include <iostream>
#include <vector>
#include <stdexcept>

class Matrix
{
private:
    std::vector<std::vector<double>> mat;
    int row;
    int column;

public:
    Matrix(int row = 0, int column = 0) : row(row), column(column)
    {

        // 隐式处理异常
        if (this->row < 0 || this->column < 0)
        {
            this->row = 0;
            this->column = 0;
        }

        mat = std::vector<std::vector<double>>(this->row, std::vector<double>(this->column));
    }

    friend std::istream &operator>>(std::istream &is, Matrix &m);

    friend std::ostream &operator<<(std::ostream &e, const Matrix &m);

    Matrix &operator=(const Matrix &other)
    {
        std::cout << "Assignment Operator Called" << std::endl;
        if (this != &other)
        {
            this->row = other.row;
            this->column = other.column;
            mat = other.mat;
        }

        return *this;
    }
};

std::istream &operator>>(std::istream &is, Matrix &m)
{
    std::cout << "input row and column(e.g. 2 2): ";

    if (!(is >> m.row >> m.column))
    {
        throw std::invalid_argument("error: row or column format!");
    }

    m.mat.resize(m.row);
    for (int i = 0; i < m.row; ++i)
    {
        m.mat[i].resize(m.column);
    }

    std::cout << "input " << m.row * m.column
              << " element(s) (use "
                 " to devide)"
              << std::endl;
    for (int i = 0; i < m.row; ++i)
    {
        for (int j = 0; j < m.column; ++j)
        {
            if (!(is >> m.mat[i][j]))
            {
                throw std::invalid_argument("invalid input!");
            }
        }
    }

    return is;
}

std::ostream &operator<<(std::ostream &e, const Matrix &m)
{
    if (m.row <= 0 || m.column <= 0)
    {
        e << "{0}";
        return e;
    }

    for (int i = 0; i < m.row; i++)
    {
        e << "{";
        for (int j = 0; j < m.column; j++)
        {
            e << m.mat[i][j];
            if (j != m.column - 1)
            {
                e << ",";
            }
        }
        e << "}";
        e << "\n";
    }

    return e;
}

int main()
{
    Matrix mat;

    try
    {
        std::cin >> mat;
        std::cout << "found successfully! the matrix:\n"
                  << mat << std::endl;
    }
    catch (const std::invalid_argument &e)
    {
        std::cerr << "\n input error: " << e.what() << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
    }

    std::cout << "\nProgram continues running. Enter any character to exit:";
    char end;
    std::cin >> end;

    return 0;
}
```
*   **测试结果**：
```
结果一：
input row and column(e.g. 2 2): 2 3
input 6 element(s) (use  to devide)
1.5 2.0 3
4 5.5 6
found successfully! the matrix:
{1.5,2,3}
{4,5.5,6}


Program continues running. Enter any character to exit:r

请按任意键继续. . .
```
```
结果二：
input row and column(e.g. 2 2): a 2

 input error: error: row or column format!

Program continues running. Enter any character to exit:
```

  

### 题目 7：反思与迁移（简答）
**对应知识点**：运算符重载设计哲学、引用语义
**题干**：
1.  为什么 `operator[]` 或 `operator()` 通常需要返回引用（`T&`）才能支持赋值操作（如 `mat[0]=1`）？
2.  为什么 `operator<<` 通常被重载为非成员函数（友元）而不是成员函数？
3.  在实现 `operator+` 时，为什么推荐利用 `operator+=` 来实现（即 `T operator+(T a, const T& b) { return a += b; }`）？

**答题区**：
- **1.**返回引用就是返回内存别名，自然就可支持赋值操作，如果是返回`T`则是返回了一个临时拷贝的右值
- **2.**成员函数写法调用时违背使用习惯（mat << cout）;cout 是 std::ostream 类的对象，我们无法去修改便准库源码把`Matrix`的成员函数塞进`ostream`里 
- **3.**利用 `operator+=` 来实现 `operator+`，可以确保加法和复合赋法的逻辑完全一致。而且未来维护成本和出错概率也被降低，只需关注修改`operator+`这一处
  

---
## 4. 提交清单（提交前自查）📦
*   [x] 本文档已填写元信息与 AI 使用记录
*   [x] 每题都有“答题区”内容（不会留空）
*   [x] 编程题工程可编译运行，README 写明步骤
*   [x] 至少包含 2 个测试/验证记录
*   [x] 若引用外部资料/代码，已标注来源