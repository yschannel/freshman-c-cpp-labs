# 《C++程序设计》Unit07-文件I/O作业题目（题目与答卷合一）

> 📌 说明（学生必读）
> 1. 本文档由你使用自选大语言模型（LLM）基于本单元课件生成；你**可以自由删除、合并、改写题目**，但需保持结构完整。
> 2. **所有解答必须写在本文档的“答题区”**（可粘贴代码、截图链接、运行日志、表格等）。
> 3. 提交物：本 Markdown 文件（或导出PDF）+ 代码工程目录（如有编程题）。
> 4. 如果你使用Markdown会导致格式错乱，也可以将本Markdown文件转换为Word文档之后完成作业。完成之后再将作业导出为PDF。
> 5. 学术诚信：允许使用 LLM 作为辅导与生成草稿，但你必须在“AI 使用记录”中如实记录，并确保自己能解释与复现结果。

---
## 0. 元信息（提交时必填）

- **课程**：C++程序设计
- **单元**：Unit07
- **主题**：文件I/O (File I/O) 与数据处理
- **学生姓名**：__STUDENT_NAME__ 学号：__STUDENT_ID__
- **使用的 LLM**：__qwen__（如 GPT/Claude/Qwen/GLM 等）
- **生成日期**：2026-04-27
- **预计投入**：2 小时；实际投入：_2_ 小时

---
## 1. AI 使用记录（必填）

### 1.1 生成用提示词与输入材料
- **我使用的提示词**：
  1.考点重点参照CPP-Unit07_cc.pptx，但是我希望你也参考pdf的额外内容，考试偏于实操
  2.自评一般，目标稳拿高分
  3.2h ，题目控制在5道
  4.我更喜欢数据向
  5.ide:vscode 编译器g++ ，可以到c++17；这次不用分离；需要包含
   
- **我提供给模型的材料**：
  - Unit07 课件/PPT：是（包含 std::filesystem, 文本I/O, 二进制I/O, 随机访问内容）
  - 其它材料：Unit07 补充PDF（关于流状态、格式化输出、文件模式的详细说明）

### 1.2 我对题目的人工修改（必填）
- **我删除/改写/新增了哪些题目**：
  删除题目四
- **我为何这样修改**：
  没时间

### 1.3 真实性声明（必选一）
- [x] 我确认：本文档中的答案均可由我本人解释、复现与现场演示
- [ ] 我确认：若使用了外部代码/同学讨论/网络资料，已在相应题目下标注来源

---
## 2. 本单元知识点对齐（由模型生成，学生可补充）

> 要求：列出 6–12 条“关键知识点”，并给出课件定位（Slide编号/标题/关键词）

| 序号 | 关键知识点                                              | 课件定位（Slide编号/标题/关键词）                    | 我当前掌握度（1-5） |
| :--- | :------------------------------------------------------ | :--------------------------------------------------- | :------------------ |
| 1    | `std::filesystem::path` 路径操作与属性查询              | PPT S03 / PDF 1-2页 (Path, File Size)                | 4                   |
| 2    | 文件流状态检测 (fail, eof, bad)                         | PPT S04 / PDF 13-15页 (Stream State)                 | 4                   |
| 3    | 文本I/O与数据格式化 (setw, setprecision, get/put)       | PPT S05, S06 / PDF 20-23页 (Formatting)              | 4                   |
| 4    | 二进制I/O (read/write) 与类型转换 (reinterpret_cast)    | PPT S08 / PDF 32-35页 (Binary I/O, reinterpret_cast) | 4                   |
| 5    | 随机访问 (seekg/seekp, tellg/tellp)                     | PPT S09, S15 / PDF 37-39页 (Random Access)           | 3                   |
| 6    | 文件打开模式 (ios::in, ios::out, ios::binary, ios::app) | PPT S04 / PDF 25页 (Open Mode)                       | 4                   |

---
## 3. 作业题目区（模型生成 + 学生可编辑）

> 题目建议总数：5 题
> 结构：概念/阅读/编程

### 题目 1：概念与规则核对（理解题）✅
**对应知识点**：文件流状态与打开模式
**课件定位**：PPT S04 / PDF 13-15页

**题干**：
请简述以下概念的区别，并说明在什么场景下使用：
1. `std::ios::trunc` 与 `std::ios::app` 的区别？
2. `std::ios::in` | `std::ios::out` 与 `std::ios::trunc` 同时使用时，文件的行为是怎样的？
3. 为什么在进行文件读取循环时，推荐使用 `while (input >> data)` 或 `while (getline(input, line))`，而不是 `while (!input.eof())`？

**答题区**：
- **我的答案**：
  1.前者是在打开文件的一瞬间清空原有内容，重新输入内容；后者是在每次写入操作前文件指针都会被强制移到文件末尾，追加内容。
  2.打开的文件具有读写功能，而且打开后清空原有信息，文件指针指向最开始。
  3.使用后者无法及时发现读取到末尾触发eof，导致再次进入循环体，容易触发未定义行为或逻辑错误；而前面两种方法可以及时判断读取是否成功。
- **我认为易错点是**：容易将eof当作判断条件
- **我用一句话总结**：要多模仿练习文件条件判断的标准代码

### 题目 2：代码阅读与推演（读码题）🔎
**对应知识点**：二进制 I/O 与 reinterpret_cast
**课件定位**：PPT S08 / PDF 32-35页

**题干**：
阅读以下 C++ 代码，假设程序运行环境为小端序（Little-Endian，如 x86 PC）。
1. 写出程序运行后控制台的输出结果。
2. 解释 `reinterpret_cast` 在此处的作用，以及为什么 `sizeof(int)` 是必要的？
3. 如果将 `ios::binary` 去掉，直接用文本模式写入，可能会出现什么问题？

**给定代码**：
```cpp
#include <iostream>
#include <fstream>
using namespace std;

int main() {
    // 写入阶段
    {
        ofstream out("data.bin", ios::binary);
        int val = 258; // 0x00000102
        out.write(reinterpret_cast<const char*>(&val), sizeof(val));
        out.close();
    }

    // 读取阶段
    {
        ifstream in("data.bin", ios::binary);
        char buffer[4] = {0};
        in.read(buffer, 3); // 只读3个字节
        cout << "Bytes read: ";
        for(int i = 0; i < 3; ++i) {
            printf("%02X ", (unsigned char)buffer[i]);
        }
        cout << endl;
        
        // 检查 eof 状态
        if (in.eof()) {
            cout << "EOF flag is set." << endl;
        } else {
            cout << "EOF flag is NOT set." << endl;
        }
    }
    return 0;
}
```

**答题区**：
- **我的答案**：
  1.
  Bytes read: 02 01 00
  EOF flag is NOT set.
  2.`reinterpret_cast`在此处的作用是强制进行内存重解释，让编译器直接把这块内存的地址当成char* 来使用；`sizeof(int)`，告诉当前平台下`int`类型占用了多少字节（不同平台可能会有所不同）。
  3.如果`int`的二进制数据中恰好包括`0x0A`(`\n`)，系统在写入的时候可能会自动将其转换为`\r\n`导致写入文件字节数变多；同理还有0x1A(EOF)



### 题目 3：编程题（必做）🛠️
**对应知识点**：文本 I/O 与数据清洗
**课件定位**：PPT S05, S06 / PDF 20-23页

**任务目标**：
编写一个程序，读取一个包含学生成绩的文本文件（CSV格式），进行数据清洗与统计，并输出格式化报告。

**规格**：
*   **输入**：`scores.txt` 文件。文件格式为：`姓名,成绩`（每行一条记录，成绩可能包含非数字字符，需要清洗）。
    *   示例内容：
        ```
        Alice,92.5
        Bob,87xx
        Charlie,absent
        David,76.8
        ```
*   **输出**：
    1.  屏幕输出：有效平均分（保留2位小数）。
    2.  文件输出：`report.txt`，包含所有有效成绩的列表及总平均分。
*   **边界条件**：处理文件不存在、成绩无法转换为数字的情况（跳过无效行）。
*   **禁止事项**：禁止使用 `C` 语言的 `fopen`/`fscanf`，必须使用 C++ Stream。

**推荐工程结构**：
*   单文件 `main.cpp`

**最低验收标准**：
1.  能编译通过（命令：`g++ -std=c++17 main.cpp -o main`）。
2.  至少包含 2 个测试用例（正常数据、包含无效数据）。
3.  关键输出截图/日志片段（贴在答题区）。

**答题区**：
*   **代码**：
    ```cpp
    #include <iostream>
    #include <fstream>
    #include <sstream>
    #include <stdexcept>
    #include <string>
    #include <vector>
    #include <iomanip>
    
    int main()
    {
    
        std::vector<std::pair<std::string, double>> validRecords;
        double totalScore = 0.0;
    
        std::ifstream scores("scores.txt");
        if (!scores.is_open())
        {
            std::cerr << "Error: could not open!" << std::endl;
            return 1;
        }
    
        std::string buffer;
        while (std::getline(scores, buffer))
        {
            if (buffer.empty())
                continue;
    
            auto commaPos = buffer.find(',');
            if (commaPos == std::string::npos)
                continue;
            std::string name = buffer.substr(0, commaPos);
            std::string scoreStr = buffer.substr(commaPos + 1);
    
            try
            {
                size_t pos;
                double score = std::stod(scoreStr, &pos);
    
                bool isValid = true;
                for (size_t i = pos; i < scoreStr.length(); ++i)
                {
                    if (!isspace(scoreStr[i]))
                    {
                        isValid = false;
                        break;
                    }
                }
    
                if (isValid)
                {
                    validRecords.push_back({name, score});
                    totalScore += score;
                }
            }
            catch (const std::invalid_argument &)
            {
                continue;
            }
            catch (const std::out_of_range &)
            {
                continue;
            }
        }
        scores.close();
    
        double average = 0.0;
        if (!validRecords.empty())
        {
            average = totalScore / validRecords.size();
        }
    
        std::cout << std::fixed << std::setprecision(2);
        std::cout << "valid aver scores: " << average << std::endl;
    
        std::ofstream outFile("report.txt");
        if (!outFile.is_open())
        {
            std::cerr << "error: could not open" << std::endl;
            return 1;
        }
    
        outFile << "=== 成绩分析报告 ===" << std::endl;
        outFile << "姓名\t成绩" << std::endl;
        for (const auto &record : validRecords)
        {
            outFile << record.first << "\t" << record.second << std::endl;
        }
        outFile << "--------------------" << std::endl;
        outFile << "总平均分: " << average << std::endl;
    
        outFile.close();
    
        return 0;
    }
    ```
*   **结果**：
   ```
   valid aver scores: 84.65
   ```
   ```
   === 成绩分析报告 ===
姓名	成绩
Alice	92.5
David	76.8
--------------------
总平均分: 84.65
```

### 题目 5：反思与迁移（简答）🧠
**对应知识点**：综合理解
**题干**：
1.  本单元我最容易混淆的 2 个点是什么？（例如：`tellg` vs `tellp`，或者 `seekg` 的偏移基准）。
2.  我用一个“反例/错误写法”说明它为什么错（可以是代码片段或文字描述）。
3.  我总结出 1 条可复用的编码规范/经验法则（例如：打开文件后必须立刻检查 `fail()`）。

**答题区**：
- **1. 最易混淆点**：
  `tellg`vs`tellp`，g 是读（get），p 是写（put）
  `seekg`偏移基准, 往回退，必须用负数
- **2. 反例说明**：
  ```cpp
  // 错误写法：在输出流中使用了 tellg
  ofstream outFile("data.txt");
  outFile << "Hello";
  // 此时想用 tellp 获取写入位置，却错写成了 tellg
  cout << "当前写入位置：" << outFile.tellg() << endl; // 编译报错或返回错误位置
  ```
- **3. 经验法则**：打开文件后必须立刻检查 `open()`

---
## 4. 提交清单（提交前自查）📦
*   [x] 本文档已填写元信息与 AI 使用记录
*   [x] 每题都有“答题区”内容（不会留空）
*   [x] 编程题工程可编译运行，README 写明步骤
*   [x] 至少包含 2 个测试/验证记录
*   [x] 若引用外部资料/代码，已标注来源