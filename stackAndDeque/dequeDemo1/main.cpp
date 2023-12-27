#include <iostream>
#include <queue>
using namespace std;

void showQueue(string queueName, queue<int>& q) {
    cout << "队列" << queueName << "中元素的数量, 即size() = " << q.size()
         << endl;
    if (!q.empty()) {
        cout << "此时, 队列" << queueName << "不为空,即empty() = false" << endl;
        cout << "队列首位元素，即front() =  " << q.front() << endl;
        cout << "队列首位元素，即back() =  " << q.back() << endl;
    } else {
        cout << "此时, 队列" << queueName << "为空,即empty() = true" << endl;
    }
}

int main() {
    queue<int> q;

    // push()
    q.push(1);
    q.push(2);
    q.push(3);

    cout << "---按顺push元素1、2、3后:\n" << endl;
    showQueue("q", q);

    q.pop();  // 弹出队头元素
    cout << "\n---弹出队头元素3, 即pop()后:\n" << endl;
    showQueue("q", q);

    q.pop();
    cout << "\n---弹出队头元素2, 即pop()后:\n" << endl;
    showQueue("q", q);

    q.pop();
    cout << "\n---弹出队头元素1, 即pop()后:\n" << endl;
    showQueue("q", q);

    queue<int> q1;
    q1.emplace(1);
    q1.emplace(2);
    q1.emplace(3);

    cout << "\n-----------队列q和q1交换前----------" << endl;
    cout << "\nq的状态: " << endl;
    showQueue("q", q);

    cout << "\nq1的状态: " << endl;
    showQueue("q1", q1);

    q1.swap(q);  // s和s1进行交换

    cout << "\n-----------队列q和q1交换后----------\n" << endl;
    showQueue("q", q);

    cout << "\nq1的状态: " << endl;
    showQueue("q1", q1);

    return 0;
}

