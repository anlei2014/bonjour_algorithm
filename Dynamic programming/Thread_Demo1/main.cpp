#include <iostream>
// 该头文件主要声明了std::thread类，另外std::this_thread命名空间也在该头文件中
#include <thread>

using namespace std;

void thread_1()
{
    cout<<"子线程1"<<endl;
}

void thread_2(int x)
{
    cout<<"x:"<<x<<endl;
    cout<<"子线程2"<<endl;
}

int main() {
    std::cout << "Hello, World!" << std::endl;

    //创建子线程1，指定线程执行入口是thread_1；(2)执行线程
    thread myThread1(thread_1);

    //阻塞主线程，当子线程1执行完毕再开始执行
    myThread1.join();

    //子线程1结束后创建子线程2，指定线程执行入口是myPrint；(2)执行线程
    thread myThread2(thread_2,100);

    //detach后，子线程和主线程失去关联，独立运行，
    //如果主线程先结束，则子线程驻留在后台，由C++运行时库接管
    //所以子线程2的打印不一定可以出现在终端上，取决于它和主线程执行的快慢
    myThread2.detach();

    return 0;
}
