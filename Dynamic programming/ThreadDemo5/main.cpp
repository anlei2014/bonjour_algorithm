#include <iostream>
#include <thread>
#include <mutex>

using namespace std;
mutex mtx_1;
mutex mtx_2;
int test_num = 1;

void print_block_1(int n, char c) {
// critical section (exclusive access to std::cout signaled by locking mtx):
    mtx_1.lock();
    for (int i = 0; i < n; i++) {
        //std::cout << c;
        test_num = 1;
        std::cout << "test_num" <<  test_num << endl;
    }
    std::cout << '\n';
    mtx_1.unlock();
}


void print_block_2(int n, char c) {// critical section (exclusive access to std::cout signaled by locking mtx):
    mtx_2.lock();
    test_num = 2;
    for (int i = 0; i < n; i++) {
        //std::cout << c;
        test_num = 2;
        std::cout << "test_num" <<  test_num << endl;
    }
    mtx_2.unlock();
}


int main() {
    std::cout << "Hello, World!" << std::endl;


    std::thread th1(print_block_1, 10000, '*');
    std::thread th2(print_block_2, 10000, '$');


    th1.join();
    th2.join();
    return 0;
}
