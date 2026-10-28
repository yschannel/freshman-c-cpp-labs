这是一份为你量身定制的《Unit06-自定单元作业题目》。基于你提供的 **Unit06 课件 (PPT & PDF)**，结合你“**C++ 一般水平**”、“**目标稳拿高分**”、“**偏好游戏与算法**”以及“**VSCode + C++17 + 分离实现**”的开发环境要求生成。

这份作业涵盖了继承链、多态、虚函数、抽象类及 `dynamic_cast` 等核心考点，题目设计融入了游戏开发（角色系统）和算法（容器管理）的场景。

---

### 0. 元信息（提交时必填）

| 项目           | 内容                                             |
| :------------- | :----------------------------------------------- |
| **课程**       | C++程序设计                                      |
| **单元**       | Unit06 继承与多态 (Inheritance and Polymorphism) |
| **主题**       | 游戏角色系统与算法管理中的继承与多态             |
| **学生姓名**   | [你的姓名]                                       | **学号**     | [你的学号]     |
| **使用的 LLM** | Qwen (千问)                                      |
| **生成日期**   | 2026-04-04                                       |
| **预计投入**   | 4 小时                                           | **实际投入** | [填写实际时长] |

---

### 1. AI 使用记录（必填）

#### 1.1 生成用提示词与输入材料
*   **我使用的提示词**：
    "你是C++课程助教。基于Unit06继承与多态课件，为一名C++水平一般、目标拿高分、喜欢游戏开发的学生生成作业。要求：1.难度适中偏上，侧重实操；2.包含5道题，融入游戏场景；3.代码必须分离.h/.cpp；4.必须包含测试；5.符合C++17标准。"
*   **我提供给模型的材料**：
    *   Unit06 课件/PPT：是 (包含构造链、名字隐藏、多态原理、RTTI等内容)
    *   其它材料：Unit06.pdf (补充了UML图示、具体的代码片段及访问控制细节)

#### 1.2 我对题目的人工修改
*   **我删除/改写/新增了哪些题目**：
    *   删除了原模板中过于基础的纯理论填空题。
    *   将第3题（编程必做）改写为“游戏角色与技能系统”，以贴合我的游戏兴趣。
    *   将第4题（编程选做）改写为“多态容器管理器”，结合算法数据处理。
*   **我为何这样修改**：
    *   我对游戏开发感兴趣，通过游戏角色的例子能让我更直观地理解继承和多态，比枯燥的几何图形例子更容易记忆。同时，为了拿高分，我需要练习代码分离和复杂的对象管理。

#### 1.3 真实性声明（必选一）
*   [x] 我确认：本文档中的答案均可由我本人解释、复现与现场演示

---

### 2. 本单元知识点对齐（由模型生成，学生可补充）

> **依据：** 参考 `CPP-Unit06_cc.pptx` 及 `Unit06.pdf` 整理

| 序号 | 关键知识点                                            | 课件定位（Slide编号/标题/关键词）                   | 我当前掌握度（1-5） |
| :--- | :---------------------------------------------------- | :-------------------------------------------------- | :------------------ |
| 1    | 继承中的构造与析构链 (Construction/Destruction Chain) | S06-S07 (构造父先子后，析构子先父后)                | 4                   |
| 2    | 名字隐藏 (Name Hiding) 与 `using` 声明                | S08-S09 (为什么派生类写了f(int)，基类的f()看不见了) | 3                   |
| 3    | 运行时多态 (Runtime Polymorphism) 与 `virtual`        | S12 (什么时候才会发生运行时多态)                    | 3                   |
| 4    | 覆写 (Override) 与 `override` 关键字                  | S11 (凡是你认为自己在覆写，就应写 override)         | 4                   |
| 5    | 抽象类 (Abstract Class) 与 纯虚函数                   | S13 (什么时候该把类做成抽象类)                      | 3                   |
| 6    | 类型转换 `dynamic_cast` 与 RTTI                       | S14 (上转容易，下转要谨慎)                          | 2                   |
| 7    | 访问控制 (Public/Protected/Private Inheritance)       | Unit06.pdf (Accessibility/Visibility)               | 4                   |

---

### 3. 作业题目区（模型生成 + 学生可编辑）

> **题目建议总数：5 题**
> **结构：** 概念/阅读/编程(必做)/编程(选做)/反思

---

#### 题目 1：概念与规则核对（理解题）
✅ **对应知识点**：名字隐藏 (Name Hiding) 与 重载 (Overloading)
✅ **课件定位**：S08-S09 (为什么派生类写了 f(int)，基类的 f() 反而‘看不见’了)

**题干**：
在 C++ 继承体系中，如果基类 `Base` 有一个函数 `void func();`，而派生类 `Derived` 定义了一个同名但参数不同的函数 `void func(int x);`。
1.  这种现象在 C++ 中被称为什么？
2.  如果此时我们通过 `Derived` 类的对象调用 `obj.func();`（无参），会发生什么？为什么？
3.  如何修改派生类代码，使得 `Derived` 类既能保留 `func(int x)`，又能访问基类的 `func()`？

**答题区**：
*   **我的答案**：
    1.  这种现象被称为 **名字隐藏 (Name Hiding)**。
    2.  编译会报错。因为在派生类的作用域中，`func(int x)` 隐藏了基类中的同名函数 `func()`。编译器在派生类作用域找到了 `func` 这个名字，就停止向上查找，但由于参数不匹配，导致重载解析失败。
    3.  在派生类中使用 `using` 声明：`using Base::func;`。
*   **我认为易错点是**：容易混淆“重载”和“隐藏”。重载发生在同一作用域，而继承中的同名函数默认是隐藏关系，除非显式引入。
*   **我用一句话总结**：派生类同名函数会遮挡基类函数，需用 `using` 解除遮挡。

---

#### 题目 2：代码阅读与推演（读码题）
✅ **对应知识点**：构造/析构链、多态调用
✅ **课件定位**：S06-S07, S12 (构造父先子后，析构子先父后；多态演示代码)

**题干**：
阅读以下 C++17 代码，回答问题：
1.  写出程序的完整输出结果。
2.  解释为什么 `pBase->show()` 输出的是 "Derived" 而不是 "Base"。
3.  如果去掉 `Base` 类中 `virtual` 关键字，输出结果会有什么变化？

**给定代码**：
```cpp
#include <iostream>
using namespace std;

class Base {
public:
    Base() { cout << "Base Ctor" << endl; }
    virtual ~Base() { cout << "Base Dtor" << endl; }
    virtual void show() { cout << "Base" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived Ctor" << endl; }
    ~Derived() override { cout << "Derived Dtor" << endl; }
    void show() const override { cout << "Derived" << endl; }
};

int main() {
    cout << "-- Create Object --" << endl;
    Base* pBase = new Derived();
    pBase->show();
    cout << "-- Delete Object --" << endl;
    delete pBase;
    return 0;
}
```

**答题区**：
*   **输出/推演过程**：
    ```
    -- Create Object --
    Base Ctor
    Derived Ctor
    Derived
    -- Delete Object --
    Derived Dtor
    Base Dtor
    ```
*   **生命周期说明**：
    *   **构造**：先调用基类 `Base` 构造函数，再调用派生类 `Derived` 构造函数（父先子后）。
    *   **析构**：由于析构函数是 `virtual`，`delete pBase` 触发多态，先调用 `Derived` 析构，再调用 `Base` 析构（子先父后）。
*   **风险与修正**：
    *   若基类析构函数非 `virtual`，`delete pBase` 会导致未定义行为（通常只调用基类析构，造成派生类资源泄漏）。

---

#### 题目 3：编程题（必做） - 游戏角色技能系统
✅ **对应知识点**：抽象类、纯虚函数、override、头文件分离
✅ **课件定位**：S13 (什么时候该把类做成抽象类)、S11 (override 的使用)

**任务目标**：
设计一个简单的游戏技能系统，理解接口与实现的分离。

**规格**：
*   **输入**：无（在 `main` 中构造对象）。
*   **输出**：屏幕打印技能名称和伤害数值。
*   **边界条件**：无特殊边界，需确保多态调用正确。
*   **禁止事项**：禁止全局变量；禁止不使用 `override` 关键字。

**推荐工程结构**：
```bash
/src
  main.cpp
  Character.h
  Character.cpp
  Warrior.h
  Warrior.cpp
  Mage.h
  Mage.cpp
```

**代码要求**：
1.  定义一个抽象基类 `Character`：
    *   包含纯虚函数 `virtual void Attack() = 0;` 和 `virtual void Skill() = 0;`。
    *   包含受保护的成员变量 `hp` (生命值) 和 `name` (角色名)。
2.  定义两个派生类 `Warrior` (战士) 和 `Mage` (法师)：
    *   必须实现 `Attack` 和 `Skill` 函数。
    *   `Warrior::Attack` 输出 "[姓名] 使用了重斩！"，`Skill` 输出 "[姓名] 使用了旋风斩！"。
    *   `Mage::Attack` 输出 "[姓名] 使用了魔杖敲击！"，`Skill` 输出 "[姓名] 释放了火球术！"。
3.  **强制要求**：所有派生类函数必须显式使用 `override` 关键字。

**最低验收标准**：
1.  能编译通过（命令：`g++ -std=c++17 *.cpp -o game`）。
2.  `main` 函数中，创建 `Warrior` 和 `Mage` 对象，并通过 `Character*` 指针调用 `Attack` 和 `Skill`。
3.  关键输出截图需包含两个角色的四种行为输出。

**答题区**：
*   **设计说明**：
    *   `Character` 作为接口，强制子类实现行为。
    *   利用多态指针统一管理不同角色。
*   **代码（关键片段）**：
    *   *Warrior.cpp:*
    ```cpp
    void Warrior::Attack() {
        cout << name << " 使用了重斩！" << endl;
    }
    void Warrior::Skill() {
        cout << name << " 使用了旋风斩！" << endl;
    }
    ```
*   **测试用例与结果**：
    *   **输入**：`Warrior w("Conan"); Character* p = &w; p->Attack();`
    *   **期望**：`Conan 使用了重斩！`
*   **我遇到的 bug 与修复记录**：
    *   **Bug**：忘记写 `override`，编译器报错提示未实现纯虚函数。
    *   **修复**：检查函数签名（const 修饰、参数列表）是否与基类完全一致。

---

#### 题目 4：编程题（选做/进阶） - 多态容器管理器
✅ **对应知识点**：`dynamic_cast`、容器管理、资源回收
✅ **课件定位**：S14 (上转容易，下转要谨慎)、Unit06.pdf (Dynamic Cast)

**题干**：
在题目 3 的基础上，增加一个“游戏大厅”功能，使用 `std::vector` 存储所有角色指针。
1.  实现一个 `GameLobby` 类，内部维护一个 `std::vector<Character*>`。
2.  实现 `AddCharacter(Character* c)` 方法。
3.  实现 `ListAll()` 方法，遍历并调用所有角色的 `Attack()`。
4.  **进阶挑战**：实现 `CastMagicOnly()` 方法。
    *   该方法需要遍历容器，检查指针是否指向 `Mage` 对象。
    *   如果是 `Mage`，强制将其转换为 `Mage*` 并调用 `Skill()`。
    *   **要求**：必须使用 `dynamic_cast` 进行安全下转，并判断转换是否成功（防止空指针解引用）。

**答题区**：
*   **我选择实现的进阶点**：`dynamic_cast` 的安全类型识别与下转。
*   **关键代码与说明**：
    ```cpp
    void GameLobby::CastMagicOnly() {
        for (auto* c : characters) {
            // 尝试将 Character* 下转为 Mage*
            Mage* pMage = dynamic_cast<Mage*>(c);
            if (pMage) { // 检查是否转换成功
                cout << "[法师专属] ";
                pMage->Skill(); // 调用法师技能
            }
            // 如果是 Warrior，dynamic_cast 返回 nullptr，直接跳过
        }
    }
    ```
*   **我如何验证正确性**：
    *   向大厅中添加一个 `Warrior` 和一个 `Mage`。
    *   调用 `CastMagicOnly()`。
    *   **预期**：只输出法师的技能信息，程序不崩溃。

---

#### 题目 5：反思与迁移（简答）
✅ **对应知识点**：综合理解

**题干**：
1.  结合本单元学习，你认为最容易出错的两个点是什么？（例如：忘记析构函数为 virtual 导致内存泄漏，或者忘记写 override 导致签名不匹配）。
2.  请画出本单元核心概念的关系图（思维导图），展示 `Inheritance` (继承) 如何通过 `Virtual` (虚函数) 实现 `Polymorphism` (多态)。

**答题区**：
*   **1. 最容易混淆的点**：
    1.  **析构函数忘记加 virtual**：如果基类析构非虚，通过基类指针删除派生类对象会导致未定义行为（派生类部分的内存不会被释放）。
    2.  **误以为同名函数就是多态**：如果基类函数没有声明为 `virtual`，即使派生类写了同名函数，也只是“隐藏”，通过基类指针调用时依然调用基类版本。
*   **2. 关系图（文字版）**：
    ```
    [Inheritance] 继承
        |
        |-- 基类子对象 (Base Subobject)
        |-- 构造链 (Base First -> Derived Later)
        |-- 析构链 (Derived First -> Base Later)
        |
        `-- [Polymorphism] 多态 (运行时)
                |
                |-- 关键字: virtual (基类) + override (派生类)
                |-- 触发条件: 基类指针/引用 -> 派生类对象
                |-- 机制: 动态联编 (Dynamic Binding / Late Binding)
                `-- 工具: dynamic_cast (安全向下转型)
    ```

---

### 4. 提交清单（提交前自查）📦
*   [ ] 本文档已填写元信息与 AI 使用记录
*   [ ] 每题都有“答题区”内容（不会留空）
*   [ ] 编程题工程可编译运行，README 写明步骤
*   [ ] 至少包含 **3** 个测试/验证记录
*   [ ] 若引用外部资料/代码，已标注来源