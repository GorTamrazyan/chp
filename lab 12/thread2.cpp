#include <iostream>
#include <thread>
#include <vector>
#include <chrono>

long long factorial(int n) {
    long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

void printNumbers(int n) {
    for (int i = 1; i <= n; ++i) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
}

void computeFactorial(int n) {
    std::cout << "Calculating factorial of " << n << " in thread " << std::this_thread::get_id() << "...\n";
    long long result = factorial(n);
    std::cout << "Factorial of " << n << " is " << result << std::endl;
}

void multiTaskingExample() {
    std::vector<std::thread> threads;

    threads.push_back(std::thread(computeFactorial, 5));
    threads.push_back(std::thread(computeFactorial, 7));

    threads.push_back(std::thread(printNumbers, 10));

    for (auto& t : threads) {
        t.join();
    }

    std::cout << "All tasks completed!" << std::endl;
}

int main() {
    std::cout << "Starting multi-tasking example..." << std::endl;
    multiTaskingExample();
    return 0;
}