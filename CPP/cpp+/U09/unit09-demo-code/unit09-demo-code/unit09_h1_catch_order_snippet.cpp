#include <exception>
#include <new>

class MyBadAlloc : public std::bad_alloc {
public:
    const char* what() const noexcept override {
        return "MyBadAlloc: simulated failure";
    }
};

void correct_order() {
    try {
        throw MyBadAlloc{};
    } catch (const MyBadAlloc&) {
        // correct order: 最具体的派生类型先获得处理机会。
    } catch (const std::bad_alloc&) {
        // 基类处理在后，仍可处理普通 bad_alloc。
    } catch (const std::exception&) {
        // 更一般的标准异常兜底。
    }
}

// wrong order (仅供讲解，不编译该顺序)：
// catch (const std::exception&) { ... }  // 会先接收 MyBadAlloc
// catch (const MyBadAlloc&) { ... }      // 具体处理逻辑失去机会
