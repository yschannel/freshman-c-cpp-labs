# 学习记录管理系统 (Portfolio)

这是一个用于处理、分析和导出学习记录（如练习、概念、Bug记录）的 C++ 命令行工具。程序能够读取配置文件和记录文件，对数据进行解析、校验、统计，并生成指定格式的报告和导出文件。

## 编译与运行环境

*   **操作系统**: Windows
*   **编译器**: g++ (支持 C++17 标准)
*   **构建方式**: 命令行直接编译

## 编译与运行命令

### 1. 编译命令

请确保你的目录结构如下：
```text
.
├── include/
│   ├── config.h
│   ├── record.h
│   ├── record_parser.h
│   ├── report_generator.h
│   └── utils.h
├── src/
│   ├── main.cpp
│   ├── config.cpp
│   ├── record.cpp
│   ├── record_parser.cpp
│   └── report_generator.cpp
└── sample/ (存放测试用的 config.cfg 和 records.txt)
```

在项目根目录下执行以下命令进行编译：
```bash
g++ -std=c++17 -Iinclude src/main.cpp src/config.cpp src/record.cpp src/record_parser.cpp src/report_generator.cpp -o portfolio
```

### 2.运行命令
```bash
./portfolio config=sample/config.cfg records=sample/records.txt report=report.txt export=export.txt
```

**参数说明：**
*   `config`: 配置文件路径。
*   `records`: 原始记录数据文件路径。
*   `report`: 生成的统计报告文件路径。
*   `export`: 生成的导出数据文件路径。
  
## 核心 C++ 特性设计说明

本项目大量使用了现代 C++ (C++17) 的特性来实现高内聚、低耦合的设计。

| C++ 特性          | 文件位置                   | 类/函数名                                      | 简要说明                                                                       |
| :---------------- | :------------------------- | :--------------------------------------------- | :----------------------------------------------------------------------------- |
| **抽象基类**      | `include/record.h`         | `class Record`                                 | 定义了 `toReportString` 和 `toExportString` 纯虚函数，作为所有记录类型的接口。 |
| **派生类**        | `include/record.h`         | `ExerciseRecord`, `ConceptRecord`, `BugRecord` | 继承自 `Record`，实现了具体的业务逻辑和格式化输出。                            |
| **运行时多态**    | `include/record.h`         | `RecordFactory::create`                        | 使用工厂模式，根据字符串类型返回基类指针，调用虚函数时表现出不同行为。         |
| **智能指针**      | `include/record.h`         | `std::unique_ptr<Record>`                      | 在 `RecordParser` 和 `ReportGenerator` 中使用，自动管理内存，防止泄漏。        |
| **Lambda 表达式** | `src/record.cpp`           | `RecordFactory` 构造函数                       | 在注册表中存储 Lambda 函数，用于创建不同类型的对象，简化了工厂实现。           |
| **自定义异常**    | `include/config.h`         | `class ConfigException`                        | 继承自 `std::exception`，用于处理配置文件读取和解析错误。                      |
| **自定义异常**    | `include/record_parser.h`  | `class ParseError`                             | 继承自 `std::runtime_error`，用于处理记录行解析错误。                          |
| **函数模板**      | `include/utils.h`          | `class TopKCollector<T>`                       | 一个通用的模板类，用于统计任意类型数据的 Top-K 频率。                          |
| **STL 容器**      | `include/record.h`         | `std::map`, `std::vector`                      | 使用 `map` 实现工厂注册表和配置键值对，使用 `vector` 存储记录列表。            |
| **STL 算法**      | `src/report_generator.cpp` | `std::sort`                                    | 在 `generateExport` 中对记录按时间进行排序。                                   |
| **运算符重载**    | `include/record.h`         | `operator<<`                                   | 重载输出流运算符，方便直接打印 `Record` 对象内容。                             |
| **移动语义**      | `src/main.cpp`             | `std::move(records)`                           | 在 `main` 函数中将解析好的记录所有权转移给生成器，避免深拷贝。                 |
```