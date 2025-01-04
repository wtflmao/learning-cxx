#include "../exercise.h"

// READ: Trivial type <https://learn.microsoft.com/zh-cn/cpp/cpp/trivial-standard-layout-and-pod-types?view=msvc-170>

struct FibonacciCache {
    unsigned long long cache[16];
    int cached;
};

static unsigned long long fibonacci(FibonacciCache &cache, int i) {
    static int cached = 2;
    for (; i >= 2 && cache.cache[i] == 0; ++cached) {
        cache.cache[cached] = cache.cache[cached - 1] + cache.cache[cached - 2];
    }
    return cache.cache[i];
}

int main(int argc, char **argv) {
    // NOTICE: C/C++ 中，读取未初始化的变量（包括结构体变量）是未定义行为
    // READ: 初始化的各种写法 <https://zh.cppreference.com/w/cpp/language/initialization>
    FibonacciCache fib = FibonacciCache{{0, 1}, 2};
    ASSERT(fibonacci(fib, 10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fibonacci(fib, 10) << std::endl;
    return 0;
}
