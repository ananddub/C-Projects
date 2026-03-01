// in C
#ifndef DEFER_H
#define DEFER_H
#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)
#define defer(code) \
    auto void CONCAT(__defer_func_, __LINE__)(void *_ __attribute__((unused))); \
    __attribute__((cleanup(CONCAT(__defer_func_, __LINE__)))) int CONCAT(__defer_var_, __LINE__) = 0; \
    void CONCAT(__defer_func_, __LINE__)(void *_ __attribute__((unused))) { code; }
#endif
// C++
#include <functional>

struct _Defer {
    std::function<void()> fn;
    ~_Defer() { fn(); }
};

#define CONCAT_(a, b) a##b
#define CONCAT(a, b) CONCAT_(a, b)
#define defer(code) _Defer CONCAT(_defer_var_, __LINE__){[&]{ code; }}
