# C++ 期末大作业：Learning Portfolio Processor（学习档案处理器）

## 0. 作业目标与允许范围
你需要实现一个**小型命令行程序**，读取个人配置文件和学习记录文件，生成统计报告和导出文件，并在程序中体现本课程要求的 C++ 核心特性。

* ✅ **允许使用大语言模型/AI 编程工具**辅助（如 Claude Code、Codex 等），但必须提交`AI-STATEMENT.md`
* ⚠️ **无法编译运行**的提交，不会获得自动评测分。但仍应提交源代码、在`README.md`中说明所遇到的困难，以便教师判断是否给予过程性或说明性分数
* 🏆 本作业包含自动评测、工程质量检查和闭卷纸笔核验。
* 为配合最后一次课的闭卷纸笔核验，学生需在最后一次课前提交一个可编译运行的程序版本。

---

## 1. 必须包含的 C++ 特性

项目中必须使用以下特性：

1. **面向对象 + 运行时多态**

* 必须有抽象基类（含虚函数）+ 至少 2 个派生类
* 必须通过`运行时`条件创建派生对象：可使用 `if/else`、 `switch/case`，推荐使用`工厂模式`。

>  注1: 工厂模式需要自学。

1. **异常处理**

* 必须自定义至少 2 个异常类型（例如 `ParseError`, `ConfigError`, `IOError`）
* 必须演示：抛出 → 捕获 → 生成可读错误信息 → 程序能够继续处理，或输出错误信息后正常结束

3. **文件流**

* 至少读取 `config` 和 `records` 两类输入文件；至少写出 `report` 和 `export` 两类输出文件。
* `report` 与 `export` 均为本作业必须生成的文件，不是二选一。

4. **运算符重载**（必须“有意义”）

* 例如：`operator<<` 用于输出领域对象；或 `operator<` 用于排序；或 `operator==` 用于去重
* 不接受“为了凑点”写一个毫无语义的重载

5. **模板（Template）**

* 必须写一个可复用的模板组件（如泛型统计器、TopK排序器、过滤器、打印器等）
* 不能只写 `template<typename T> void print(T)` 这种无实质收益的模板

6. **STL**

* 必须使用 ≥2 种 STL 容器（如 `vector/map/unordered_map` 等）
* 必须使用 ≥1 个 STL 算法（如 `stable_sort/transform/accumulate/find_if` 等）

>  注2：STL算法需要自学

---

## 2. 功能要求

你的程序只需支持 **一个主入口命令**：

### 2.1 命令行形式

程序必须支持以下命令行形式：
```bash
portfolio config=... records=... report=... export=...
```

例如：

```bash
bin/portfolio config=sample/config.cfg records=sample/records.txt report=report.txt export=export.txt
```
> 四个参数均必须提供。缺少参数、参数名未知或参数重复，均属于作业级致命错误。
> 不要求支持 `--config`、短参数或子命令格式。若实现了子命令，也必须保留上述标准形式，自动评测只使用该形式。

>  注3：命令行参数解析处理需要自行实现，不得使用除标准库外的任何第三方库

### 2.2 程序流程
```
读取 config.cfg → 按配置解析 records.txt → 生成 report.txt → 生成 export.txt
```
---

## 3. 输入文件规范

### 3.1 config.cfg（教师发放，每人唯一）

你必须读取并遵循该配置文件。文件采用 `key=value` 形式，一行一个键值对。

**语法规则：**

1. 空行允许；以 `#` 开头的整行视为注释（可忽略）。
2. `key` 仅包含字母、数字、下划线（如 `student_id`）。
3. `value` 两侧空白应被忽略。
4. **列表值**使用逗号分隔，例如：`required_types=CONCEPT,EXERCISE,BUG`；
5. `bool` 使用 `true/false`（不区分大小写也可，但建议按此规范输出）。
6. `delimiter` 可能是 `|`、`;` 之一。

**必须支持的键：**

* `student_id`：学号（字符串）
* `seed`：整数
* `delimiter`：记录分隔符（`|` /  `;`）
* `required_types`：至少出现的记录类型列表（逗号分隔）
* `sort_by`：导出排序字段（`time` / `difficulty` / `type`）
* `sort_order`：`asc` / `desc`
* `report_format`：`text` / `kvblock`
* `strict`：`true` / `false`

**示例（仅示意，你拿到的会不同）：**

```text
# per-student config
student_id=SAMPLE_ID
seed=184273
delimiter=|
required_types=CONCEPT,EXERCISE,BUG
sort_by=time
sort_order=desc
report_format=text
strict=false
```


> 重要：不读取 config 或忽略 config 导致行为固定，会被判为未完成。

---

### 3.2 records.txt（你自己写几条即可，10–30 条足够）

每行一条记录，字段用 `delimiter` 分隔。**固定 6 列**：

```
type | time | title | difficulty | tags | note
```

* `type`：`CONCEPT` / `EXERCISE` / `BUG` 
* `time`：`YYYY-MM-DD`（例如 2026-01-10）
* `title`：简短标题
* `difficulty`：整数 1–5
* `tags`：逗号分隔的标签列表（例如 `oop,template,stl`）
* `note`：自由文本，可为空；其他字段均不可为空

补充规则

* 空行可以忽略，不计入 `bad_lines`。
* `records.txt` 不支持注释行；所有非空行都按记录解析。字段不合法时，按记录级错误处理。
* **`title/note` 中不准包含当前记录分隔符字符**（由 config 指定）。
* `time` 应为合法日期
* `difficulty` 必须范围为 `1–5` 的整数。
* 解析字段时，应去除字段两侧空白。`title` 和 `note` 的内部空格应保留。

**示例（分隔符为 `|` 时）：**

```
CONCEPT|2026-01-10|Polymorphism basics|2|oop,polymorphism|virtual + override
EXERCISE|2026-01-11|Vector sort lab|3|stl,algorithm|sort + lambda
BUG|2026-01-12|File open failed|2|fstream,exception|fixed path handling
```

### 3.3 列表字段的约定

配置文件与记录文件中，部分字段采用“列表”表示（例如 required_types、tags）。列表一般使用逗号分隔书写。

对 `required_types` 和 `tags` 的列表解析，至少应做到：

> 1. 使用英文逗号分隔；
> 2. 每个列表项两侧空白应被忽略；
> 3. 空列表项视为非法：`required_types` 中的空项属于 config 错误，`tags` 中的空项属于记录级错误。
> 4. `required_types` 中只能出现 `CONCEPT / EXERCISE / BUG`；
> 5. `tag` 仅包含英文字母、数字、下划线或短横线；含其他字符的 `tag` 视为记录级错误。
> 6. `tags` 中在同一条记录重复出现的 tag 只计 1 次。

列表解析策略属于设计点之一：将纳入评分（可读性、鲁棒性、一致性、解释清晰度）。

---

## 4. 输出文件规范

### 4.1 report.txt（统计报告）

#### 4.1.1 必须包含的信息：

* 基本信息：`student_id`、`total_records`(成功记录数)、`bad_lines`(坏行数)。其中`bad_lines`为 0 也必须输出。
* `total_records` 表示成功解析并纳入统计的记录数，不包含坏行和空行。
* `bad_lines` 表示因格式或字段错误被跳过的记录行数。
* `bad_line_details`：有坏行时必须输出，无坏行时不输出。
* 统计：按 `type` 计数；按 `difficulty` 分布；按 `tags` Top-N（N=5）
* `top_tags` 按出现次数从高到低排列；次数相同按 tag 字典序升序排列。
* 校验摘要（checksum）：为必填输出项，格式固定为：
`S<seed>-R<total_records>-B<bad_lines>`

#### 4.1.2 必须遵守的格式

* `report.txt` 的格式必须由 `config.cfg` 中的 `report_format` 决定。
* 当 `report_format=text` 时，输出缩进的文本格式；当 `report_format=kvblock` 时，输出键值块格式。
* 不得忽略该配置项，也不得固定输出一种格式。

**report_format = text（示意）：**

```
student_id: SAMPLE_ID
total_records: 18
bad_lines: 2

count_by_type:
  CONCEPT: 6
  EXERCISE: 12
  BUG: 0

difficulty_hist:
  1: 2
  2: 5
  3: 0
  4: 3
  5: 1

top_tags:
  stl: 9
  exception: 4
  template: 3
  oop: 3
  fstream: 2

bad_line_details:
  line3: "invalid difficulty: 8"
  line17: "field count mismatch"

checksum: S184273-R18-B2
```

**report_format = kvblock（示意）：**

```
student_id=SAMPLE_ID
total_records=18
bad_lines=2
count_by_type.CONCEPT=6
count_by_type.EXERCISE=12
count_by_type.BUG=0
difficulty_hist.1=2
difficulty_hist.2=5
difficulty_hist.3=0
difficulty_hist.4=3
difficulty_hist.5=1
top_tags.stl=9
top_tags.exception=4
top_tags.template=3
top_tags.oop=3
top_tags.fstream=2
bad_line_details.line3="invalid difficulty: 8"
bad_line_details.line17="field count mismatch"
checksum=S184273-R18-B2
```


### 4.2 export.txt（导出文件）

* 将解析成功的记录按 `sort_by + sort_order` 排序后导出
* 排序须使用稳定排序类型的算法，保证比较相等元素时不交换位置
* `export.txt` 必须使用与 `records.txt` 相同的 6 列结构输出：
`type<delimiter>time<delimiter>title<delimiter>difficulty<delimiter>tags<delimiter>note`
* 分隔符必须使用 `config.cfg` 中的 `delimiter`。
*  `tags` 应使用解析后的规范化结果输出。
* 当 `sort_by=type` 时，按 字符串字典序排序：`BUG < CONCEPT < EXERCISE`。
* 只导出成功解析的记录，坏行不导出。

---

## 5. 错误处理要求（隐藏测例重点）

### 5.1 记录级错误（受 `strict` 影响）

典型记录级错误包括：坏行、字段缺失/多余、数字/日期解析失败、未知 `type`、字段越界、非法`tag`等。

* `strict=true`：遇到上述错误应立即报错退出
* `strict=false`：应跳过该行并计数（`bad_lines++`），最终仍生成report/export；坏行原因按`5.4节`示例写入 `report.txt`。

### 5.2 作业级致命错误（**不受 `strict` 影响**，必须终止）

以下情况无论 `strict` 取值如何，都应给出清晰错误信息并退出程序（返回非 0）：

1. **涉及config的错误，包括： 无法读取 / 格式非法 / 缺关键字段 / 字段值非法 / 未知或重复 key / 缺少 = / 等**
2. **文件操作失败等**

> **上述未列出的异常场景也应进行合理处理：输出明确错误信息、保证资源正确释放、以非 0 退出码结束。**

### 5.3 统一判定规则

1. 程序正常完成时，退出码应为 0。
2. 作业级致命错误应以非 0 退出，不要求生成 report/export。
3. `strict=true` 下遇到记录级错误，应以非 0 退出，不要求生成完整 report/export。
4. `strict=false` 下遇到记录级错误，应跳过坏行，继续处理其他记录，并最终生成 report/export。
5. 程序完成记录解析后，必须检查 `required_types` 是否被成功记录覆盖。
6.  排序必须稳定；排序字段相同时保持输入原始顺序。

### 5.4 strict=false 时坏行原因的`report`记录格式

参见 `4.1.2节` 的`bad_line_details`示例

### 5.5 required_types 覆盖检查

程序完成记录解析后，必须检查成功记录是否覆盖 `config.cfg` 中的全部 `required_types`。

若存在未覆盖的 required type：

* `strict=true`：视为集合级校验失败，输出错误信息并以非 0 退出，不要求生成完整 report/export。
* `strict=false`：继续生成 report/export，但必须在 report.txt 中输出 `missing_required_types`。
* 该问题不计入 `bad_lines`，因为它不是某一行的格式错误。

对应的report中的错误信息：

**text:**

```
missing_required_types:
  BUG
```
或者（缺多个时）
```
missing_required_types:
  BUG,EXERCISE
```

**kvblock:**

```
missing_required_types=BUG
```
或者（缺多个时）
```
missing_required_types=BUG,EXERCISE
```

---

## 6. 第三方库、C++标准以及编译环境

### 6.1 第三方库的约定

1. 只允许使用 C++ 标准库，**不得使用任何第三方库/框架**
2. 配置解析、命令行参数解析均需自行实现

### 6.2 关于使用的C++标准

1. 本项目可以使用`C++11`和`C++17`标准，但是建议使用`C++17`
2. 本项目不得依赖`C++20/C++23`的专有特性
3. 教师的自动评测将使用`-std=c++17`，编译器为 g++ 或 clang++

### 6.3 关于编译环境

* 只准使用 g++/clang++编译器，不准使用微软的C++编译器`cl.exe`
* 可以使用CMake，也可以提供明确的 g++/clang++ 编译命令。
* 使用微软Visual Studio开发的同学，可以使用VS的转换功能将VS项目转换为CMake项目；VS安装包中也带有clang编译器
* 若使用CMake，版本应不低于`CMake 3.25.0`，
* 自动评测环境的编译器版本不低于：`g++ 13.2.0`，或`clang 17.0.6`。
* 不得使用平台依赖的函数/类（比如scanf_s()是微软编译器特有的函数，g++/clang都不支持），确保程序在Windows/Linux/MacOS上均可不修改源代码即能编译

## 7. 提交物（统一打包 zip）

### 7.1 目录结构和文件命名

```
StudentID-YourName.zip
├── bin/                (可选：本机编译后的可执行文件)
|   └── portfolio       (Windows 可为 portfolio.exe)
├── include/            (可选)
├── src/                (源码)
├── AI-STATEMENT.md     (必交：是否使用AI及相关详述)
├── CMakeLists.txt       (使用 CMake 时必交；否则须在 README.md 中提供明确 g++/clang++ 编译命令)
├── README.md           (说明：操作系统、开发/编译环境、编译命令、命令行参数、需说明的设计等)
├── RUNLOG.txt          (必交：至少2次运行命令 + 关键输出片段)
├── export.txt          (必交：程序输出)
├── report.txt          (必交：程序输出)
└── sample/
    ├── records.txt     (必交：你根据config.cfg编写)
    └── config.cfg      (你拿到的那份)
```

> 注3: 自动评测以源码重新编译为准，提交的 bin/ 可执行文件仅用于人工快速查看，不作为唯一运行依据。

### 7.2 文件编写说明

* **AI-STATEMENT.md**

> 1. 是否使用 AI；
> 2. 如果使用 AI：说明使用在哪些环节，以及本人至少修改/确认的 3 个关键点；
> 3. 如果未使用 AI：写明“未使用 AI”，并说明本人完成的 3 个关键设计点。

* **README.md**

README.md 必须包含“C++ 特性定位表”，列出以下特性对应的文件、类名或函数名：

> * 抽象基类与派生类；
> * 运行时多态创建位置；
> * 自定义异常类型及抛出/捕获位置；
> * 文件读写位置；
> * 运算符重载位置；
> * 模板组件位置；
> * 使用的 STL 容器与算法。

---


# 评分规则

总分 100：

1. **自动评测（含隐藏边界测例）**：50

* 基本功能（读 config / 解析 records / 生成 report/export）
* 隐藏边界（坏行、缺文件、非法字段、required_types 缺失、strict 行为）

2. **工程质量与可读性**：25

* 结构清晰、命名合理、错误信息友好、注释不过量但关键处到位
* 提交物目录结构清晰、文件命名规范一致、没有缺失和多余文件
* 需遵守`6. 第三方库、C++标准以及编译环境`的约定
  
3. **线下闭卷纸笔（核验解释）**：25

* 5个关于你的程序的小问题
* 每条回答是否对得上你所写的代码
* 是否体现理解而非空话（尤其是多态、异常、文件读写、运算符重载）
> 备注：即使使用 AI，只要你能解释清楚并通过测例，依然能拿高分；反之“一键生成但不理解/不健壮”会在隐藏测例与 **线下闭卷纸笔小测** 上失分。

4. **关于及格线**

能够处理最小样例、基本满足工程质量要求，并在闭卷纸笔核验中达到及格水平，通常可初步达到及格要求。

---

# 附：最小样例 records.txt（仅供同学们参考）

> 这是样例格式说明，该样例假定 `delimiter=|`；每位同学最终以自己的 records + 自己的 config 为准。

```
CONCEPT|2026-01-10|Virtual dispatch|2|oop,polymorphism|vtable concept
EXERCISE|2026-01-11|Sort vector|3|stl,algorithm|sort + lambda
BUG|2026-01-12|Open file failed|2|fstream,exception|handle ios::fail
CONCEPT|2026-01-13|Templates|3|template,generic|function template
EXERCISE|2026-01-14|Operator<< overload|2|operator,io|pretty print
```

---