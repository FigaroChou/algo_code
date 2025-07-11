#include <iostream>
#include <string>
using namespace std;

class Queue
{
public:
    Queue(int capacity)
    : _capacity(capacity),
      _size(0),
      _front(0),
      _end(0) 
    {
        _queue = new int[capacity];
    };

    int push(int x) {
        if (_size == _capacity) return -1;
        _queue[_end++] = x;
        _size++;
        return 0;
    }

    int front() {
        if (_size == 0) return -1;
        return _queue[_front];
    }

    int pop() {
        if (_size == 0) return -1;
        _size--;
        return _queue[_front++];
    }
private:
    int _capacity;
    int _size;
    int _front;
    int _end;
    int *_queue;
};

#define N 100010
int main() {
    int count;
    cin >> count;

    Queue q(N);
    std::string op;
    int val;
    while (count-- > 0) {
        cin >> op;
        if (op == "push") {
            cin >> val;
            if (q.push(val) < 0) {
                std::cout << "error" << std::endl;
            }
        } else if (op == "pop") {
            int res = q.pop();
            if (res < 0) {
                std::cout << "error" << std::endl;
            } else {
                std::cout << res << std::endl;
            }
        } else if (op == "front") {
            int res = q.front();
            if (res < 0) {
                std::cout << "error" << std::endl;
            } else {
                std::cout << res << std::endl;
            }
        } 
    }

    return 0;
}
