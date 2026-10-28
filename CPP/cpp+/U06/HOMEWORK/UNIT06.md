这是一份为您定制的**UNIT06**。我已移除了所有示例答案，保留了基于你提供的 **Unit06 课件 (PPT & PDF)** 生成的题目框架。

这份作业严格遵循了你提出的 **5个要求**：
1.  **考点**：基于 Unit06 课件，侧重实操。
2.  **难度**：针对一般水平，目标稳拿高分（包含基础必做+进阶选做）。
3.  **工作量**：控制在 4 小时内，共 5 道题。
4.  **风格**：融入了**游戏（角色技能）** 与 **算法（容器管理）** 场景。
5.  **约束**：强制 **.h/.cpp 分离**，要求 **C++17**，包含测试与日志。

---

### 0. 元信息（提交时必填）

| 项目           | 内容                                             |
| :------------- | :----------------------------------------------- |
| **课程**       | C++程序设计                                      |
| **单元**       | Unit06 继承与多态 (Inheritance and Polymorphism) |
| **主题**       | 游戏角色系统与多态容器管理                       |
| **学生姓名**   | STUDENT_NAME                                           |
| **学号**       | STUDENT_ID                                       |
| **使用的 LLM** | Qwen (千问)                                      |
| **生成日期**   | 2026-04-04                                       |
| **预计投入**   | 4 小时                                           |
| **实际投入**   | 4h                                               |

---

### 1. AI 使用记录（必填）

#### 1.1 生成用提示词与输入材料
*   **我使用的提示词**：
    1.考点重点参照CPP-Unit06_cc.pptx，但是我希望你也参考pdf的额外内容，考试偏于实操
    2.自评一般，目标稳拿高分
    3.4h ，题目控制在5道
    4.我更喜欢游戏和算法
    5. ide:vscode 编译器g++ ;可以到c++17；允许；必须分离；需要包含
*   **我提供给模型的材料**：
    *   Unit06 课件/PPT：是 (包含构造链、多态原理、RTTI等内容)
    *   其它材料：Unit06.pdf (补充了UML图示及访问控制细节)

#### 1.2 我对题目的人工修改（必填）
*   **我删除/改写/新增了哪些题目**：
    [例如：将第3题改写为游戏角色系统，以贴合我的兴趣]
*   **我为何这样修改**：
    [例如：为了通过游戏场景更好地理解多态，同时满足C++17和文件分离的练习要求]

#### 1.3 真实性声明（必选一）
*   [x] 我确认：本文档中的答案均可由我本人解释、复现与现场演示
*   [x] 我确认：若使用了外部代码/同学讨论/网络资料，已在相应题目下标注来源

---

### 2. 本单元知识点对齐（由模型生成，学生可补充）

> **依据：** 参考 `CPP-Unit06_cc.pptx` 及 `Unit006.pdf` 整理

| 序号 | 关键知识点                        | 课件定位（Slide编号/标题/关键词）    | 我当前掌握度（1-5） |
| :--- | :-------------------------------- | :----------------------------------- | :------------------ |
| 1    | 继承中的构造与析构链              | S06-S07 (构造父先子后，析构子先父后) | [4]                 |
| 2    | 名字隐藏 (Name Hiding) 与 `using` | S08-S09 (同名函数隐藏机制)           | [4]                 |
| 3    | 运行时多态与虚函数表              | S12 (多态发生的条件)                 | [4]                 |
| 4    | `override` 与 `final` 关键字      | S11 (显式覆写控制)                   | [4]                 |
| 5    | 抽象类与纯虚函数                  | S13 (抽象类的设计)                   | [4]                 |
| 6    | `dynamic_cast` 与 RTTI            | S14 (安全的向下转型)                 | [3]                 |

---

### 3. 作业题目区（模型生成 + 学生可编辑）

> **题目总数：5 题**
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
    1.  name hiding
    2.  无法匹配目标函数；
        因为编译器在Derived作用域内找到了func这个名字，于是停止向Base查找。接着它尝试进行重载解析，发现只有func(int)可用，而调用时无参，因此匹配失败导致编译错误。
    3.  加上 using Base::func();
*   **我认为易错点是**：
    混淆"name hiding"与"overload",以为obj.func()会自动寻找无参版本。
*   **我用一句话总结**：
    派生类同名函数会屏蔽所有同名函数，若想复用基类版本，必须使用using关键字显式引入

---

#### 题目 2：代码阅读与推演（读码题）
✅ **对应知识点**：构造/析构链、多态调用
✅ **课件定位**：S06-S07, S12 (构造链与多态演示)

**题干**：
阅读以下 C++17 代码，回答问题：
1.  写出程序的完整输出结果。
2.  解释为什么 `pBase->show()` 输出的是 "Derived"。
3.  如果去掉 `Base` 类中 `virtual` 关键字，`delete pBase` 可能会导致什么后果？

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
    -- Create Object --
    Base Ctor
    Derived Ctor
    Derived
    -- Delete Object --
    Derived Dtor
    Base Dtor
*   **生命周期说明**：
    编译器在编译`Base`类时，因为`show`是`virtual`, 会在内存中生成一张`虚函数表(vtable)`。当`new Deried()`时，对象内部会隐藏一个指针(vptr)指向这张表。调用`pBase->show()`时，程序不是看指针类型(Base*),而是通过vptr找到实际对象(Derived)的虚表，发现里面存的是`Derived::show`的地址，从而实现了`动态绑定`。
*   **风险与修正**(去掉virtual的后果)：
    原来的derived类中申请的资源将无法释放而导致内存泄漏或资源泄漏。

---

#### 题目 3：编程题（必做） - 游戏角色技能系统
✅ **对应知识点**：抽象类、纯虚函数、override、头文件分离
✅ **课件定位**：S13 (抽象类)、S11 (override 的使用)

**任务目标**：
设计一个简单的游戏技能系统，理解接口与实现的分离。

**规格**：
*   **输入**：无（在 `main` 中构造对象）。
*   **输出**：屏幕打印技能名称和伤害数值。
*   **约束**：
    1.  必须使用 **C++17** 标准。
    2.  必须严格分离 `.h` (声明) 和 `.cpp` (实现) 文件。
    3.  必须使用 `override` 关键字。
    4.  禁止使用全局变量。

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

**设计要求**：
1.  **抽象基类 `Character`**：
    *   包含纯虚函数 `virtual void Attack() = 0;` 和 `virtual void Skill() = 0;`。
    *   包含受保护的成员变量 `hp` (生命值) 和 `name` (角色名)。
    *   提供构造函数初始化 `name` 和 `hp`。
2.  **派生类 `Warrior` (战士)**：
    *   实现 `Attack` 输出 "[姓名] 使用了重斩！"。
    *   实现 `Skill` 输出 "[姓名] 使用了旋风斩！"。
3.  **派生类 `Mage` (法师)**：
    *   实现 `Attack` 输出 "[姓名] 使用了普攻"。
    *   实现 `Skill` 输出 "[姓名] 释放了火球术！"。
4.  **`main` 函数测试**：
    *   创建 `Warrior` 和 `Mage` 对象。
    *   使用 `Character*` 数组或指针分别指向这两个对象，并调用其 `Attack` 和 `Skill` 方法。

**最低验收标准**：
1.  能编译通过（命令：`g++ -std=c++17 *.cpp -o game`）。
2.  至少包含 2 个测试用例（战士和法师各一个）。
3.  关键输出截图贴在下方。

**答题区**：
*   **代码（可粘贴关键部分，完整代码放工程目录）**：
    ```
    //main.cpp
    #include "Mage.h"
    #include "Warrior.h"
    #include "Character.h"
    #include <iostream>
    #include <string>
    
    int main()
    {
        Warrior warrior(100, "W");
        Character *W_ptr = &warrior;
    
        Character *M_ptr = new Mage(50, "M");
    
        W_ptr->Attack();
        W_ptr->Skill();
    
        M_ptr->Attack();
        M_ptr->Skill();
    
        return 0;
    }
    ```
    ```
    //Character.h
    #ifndef CHARACTER_H
    #define CHARACTER_H
    #include <string>
    class Character
    {
    protected:
        int hp;
        std::string name;
    
    public:
        virtual void Attack() = 0;
        virtual void Skill() = 0;
        Character(int _hp, const std::string &_name);
        virtual ~Character() = default;
    };
    #endif
    ```
    ```
    //Character.cpp
    #include "Character.h"
    #include <string>
    
    Character::Character(int _hp, const std::string &_name) : hp(_hp), name    (_name) {};
    ```
    ```
    //Warrior.h
    #ifndef WARRIOR_H
    #define WARRIOR_H
    #include "Character.h"
    
    class Warrior : public Character
    {
    public:
        Warrior(int _hp, const std::string &_name);
        void Attack() override;
        void Skill() override;
    };
    
    #endif
    ```
    ```
    //Warrior.cpp
    #include "Warrior.h"
    #include <iostream>
    
    Warrior::Warrior(int _hp, const std::string &_name) : Character(_hp, _name)     {};
    void Warrior::Attack() { std::cout << this->name << " used a Heavy     Slash!\n"; }
    void Warrior::Skill()
    {
        std::cout << this->name << " used a Whirlwind Slash!\n";
    }
    ```
    ```
    //Mage.h
    #ifndef MAGE_H
    #define MAGE_H
    #include "Character.h"
    
    class Mage : public Character
    {
    public:
        Mage(int _hp, const std::string &_name);
        void Attack() override;
        void Skill() override;
    };
    
    #endif
    ```
    ```
    //Mage.cpp
    #include "Mage.h"
    #include <iostream>
    
    Mage::Mage(int _hp, const std::string &_name) : Character(_hp, _name) {};
    void Mage::Attack() { std::cout << this->name << " performed a Normal     Attack!\n"; }
    void Mage::Skill()
    {
        std::cout << this->name << " unleashed a Fireball!\n";
    }
    ```

*   **测试用例与结果**：
    ```
    W used a Heavy Slash!
    W used a Whirlwind Slash!
    M performed a Normal Attack!
    M unleashed a Fireball!
    ```
*   **我遇到的 bug 与修复记录（至少 1 条）**：
    忘记在派生类写初始化了.

---

#### 题目 4：编程题（选做/进阶） - 多态容器管理器
✅ **对应知识点**：`dynamic_cast`、容器管理
✅ **课件定位**：S14 (上转容易，下转要谨慎)

**题干**：
在题目 3 的基础上，增加一个“游戏大厅”功能。
1.  编写一个 `GameLobby` 类，内部维护一个 `std::vector<Character*>` 容器。
2.  实现 `AddCharacter(Character* c)` 方法，将角色加入容器。
3.  实现 `ExecuteAllAttack()` 方法，遍历容器调用所有角色的 `Attack()`。
4.  **进阶挑战（必做部分）**：实现 `ExecuteMageSkillOnly()` 方法。
    *   该方法遍历容器，检查每个指针是否指向 `Mage` 对象。
    *   如果是 `Mage`，使用 `dynamic_cast` 将其转换为 `Mage*` 并调用 `Skill()`。
    *   **要求**：必须检查 `dynamic_cast` 的结果，防止空指针解引用。

**答题区**：
*   **关键代码与说明**：
    ```
    //GameLobby.h
    #ifndef GAMELOBBY_H
    #define GAMELOBBY_H
    
    #include <vector>
    #include <string>
    #include "Character.h"
    
    class GameLobby
    {
    private:
        std::vector<Character *> m_character;
    
    public:
        GameLobby();
        ~GameLobby();
        void AddCharacter(Character *c);
        void ExecuteAllAttack();
        void ExecuteMageSkillOnly();
    };
    
    #endif
    ```
    ```
    //GameLobby.cpp
    #include "GameLobby.h"
    #include <iostream>
    #include <vector>
    #include <string>
    #include <typeinfo>
    #include "Mage.h"
    
    GameLobby::GameLobby() {};
    GameLobby::~GameLobby()
    {
        for (Character *Cptr : m_character) // 清理容器元素
        {
            delete Cptr;
        }
    
        m_character.clear(); // 清理容器本身
    }
    
    void GameLobby::AddCharacter(Character *c)
    {
        if (c != nullptr)
        {
            m_character.push_back(c);
            std::cout << "Added a character to the lobby." << std::endl;
        }
    }
    
    void GameLobby::ExecuteAllAttack()
    {
        for (Character *Cptr : m_character)
        {
            Cptr->Attack();
        }
    }
    
    void GameLobby::ExecuteMageSkillOnly()
    {
        for (Character *Cptr : m_character)
        {
    
            if (typeid(*Cptr) == typeid(Mage))
            {
                Mage *Mptr = dynamic_cast<Mage *>(Cptr);
                if (Mptr != nullptr)
                {
                    Mptr->Skill();
                }
            }
        }
    }
    ```
    ```
    //main.cpp
    #include "Mage.h"
    #include "Warrior.h"
    #include "Character.h"
    #include "GameLobby.h"
    #include <iostream>
    #include <string>
    
    int main()
    {
    
        GameLobby Lobby;
    
        Character *W_ptr = new Warrior(100, "W");
        Lobby.AddCharacter(W_ptr);
        Character *M_ptr1 = new Mage(50, "M1");
        Lobby.AddCharacter(M_ptr1);
        Character *M_ptr2 = new Mage(675, "M2");
        Lobby.AddCharacter(M_ptr2);
    
        Lobby.ExecuteAllAttack();
        Lobby.ExecuteMageSkillOnly();
    
        return 0;
    }
    ```
*   **测试用例与结果**：
    ```
    Added a character to the lobby.
    Added a character to the lobby.
    Added a character to the lobby.
    W used a Heavy Slash!
    M1 performed a Normal Attack!
    M2 performed a Normal Attack!
    M1 unleashed a Fireball!
    M2 unleashed a Fireball!
    ```
*   **我如何验证正确性**：
    1.直接Cmake编译看输出。
    2.喂给ai查看是否达到题目要求。

---

#### 题目 5：反思与迁移（简答）
✅ **对应知识点**：综合理解

**题干**：
1.  本单元我最容易混淆的 2 个点是什么？（例如：隐藏与覆盖的区别、析构函数为什么要虚）。
2.  请写出一条你在本单元代码中必须遵守的“编码规范”（例如：凡是析构函数必加 virtual，凡是覆写必加 override）。

**答题区**：
*   **1. 最容易混淆的点**：
    1.  虚函数（Virtual）与非虚函数的调用区别：容易忘记基类析构函数必须是 virtual，否则通过基类指针删除派生类对象时，派生类的析构函数不会被调用，导致内存泄漏。
    2.  dynamic_cast 的返回值：容易搞混。指针转换失败返回 nullptr，但引用转换失败会抛出异常。在写游戏逻辑判断角色类型时，需要特别注意这一点。
*   **2. 我的编码规范**：
    在设计游戏实体基类（如 Character）时，必须将其设计为抽象类（包含纯虚函数），强制子类实现具体行为，防止实例化无意义的基类对象。

---

### 4. 提交清单（提交前自查）📦
*   [x] 本文档已填写元信息与 AI 使用记录
*   [x] 每题都有“答题区”内容（不会留空）
*   [x] 编程题工程可编译运行（g++ -std=c++17），且实现了 .h/.cpp 分离**
*   [x] 至少包含 **2** 个测试/验证记录
*   [x] 若引用外部资料/代码，已标注来源