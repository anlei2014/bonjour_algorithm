#include <iostream>
#include <stack>

using namespace std;

void test01()
{
    //特点：符合先进后出数据结构
    stack<int> s;

    //入栈
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    //只要栈不为空，查看栈顶，并且执行出栈操作
    while(!s.empty())
    {
        //查看栈顶元素
        cout<<s.top()<<endl;

        //出栈
        s.pop();
    }

    cout<<s.size()<<endl;
}

int main() {

    test01();
    std::cout << "我很好"<< std::endl;
    return 0;
}
