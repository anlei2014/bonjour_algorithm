#include <iostream>// std::cout
#include <thread>// std::thread
#include <mutex>// std::mutex

using namespace std;

std::mutex mtx;  // mutex for critical section
void print_block(int n, char c) {
// critical section (exclusive access to std::cout signaled by locking mtx):
    mtx.lock();
    for (int i = 0; i < n; i++) {
        std::cout << c;
    }
    std::cout << '\n';
    mtx.unlock();
}

int main() {
    std::thread th1(print_block, 50, '*');//线程1：打印*
    std::thread th2(print_block, 50, '$');//线程2：打印$
    std::thread th3(print_block, 50, '#');//线程2：打印#

    th1.join();
    th2.join();
    th3.join();
    return 0;
}
