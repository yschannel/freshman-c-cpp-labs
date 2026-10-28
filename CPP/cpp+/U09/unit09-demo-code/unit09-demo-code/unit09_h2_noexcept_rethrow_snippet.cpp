#include <stdexcept>

void may_fail() {
    throw std::runtime_error("simulated failure");
}

void boundary() noexcept {
    // noexcept 的承诺是不让异常逃出此函数，不是禁止调用可能抛异常的函数。
    try {
        may_fail();
    } catch (const std::exception&) {
        // 在边界内处理，避免异常逃出 noexcept 函数。
    }
}

void log_then_propagate() {
    try {
        may_fail();
    } catch (const std::exception&) {
        // throw; 只能在处理异常时重抛当前异常，交由外层调用者继续处理。
        throw;
    }
}
