#include <iostream>
#include <string>
using namespace std;

class CircularQueue {
public:
    CircularQueue(int capacity)
    : _capacity(capacity),
      _front(0),
      _rear(0),
      _size(0)
    {
        _queue = new int[_capacity + 1];
    }

    bool empty() {
        return _front == _rear;
    }

    bool full() {
        return _front == ((_rear + 1) % (_capacity + 1));
    }

    void push(int x) {
        if (full()) {
            std::cout << "full" << std::endl;
            return;
        }
        _size++;
        _queue[_rear] = x;
        _rear = (_rear + 1) % (_capacity + 1);
    }

    int pop() {
        if (empty()) {
            std::cout << "empty" << std::endl;
            return -1;
        }
        _size--;
        int res = _queue[_front];
        _front = (_front + 1) % (_capacity + 1);
        return res;
    }

    int front() {
        if (empty()) {
            std::cout << "empty" << std::endl;
            return -1;
        }

        return _queue[_front];
    }
private:
    int _front;
    int _rear;
    int _size;
    int _capacity;
    int *_queue;
};

int main() {
    int capacity, count;
    cin >> capacity >> count;

    CircularQueue q(capacity);
    std::string op;
    int val;
    while (count-- > 0) {
        cin >> op;
        if (op == "push") {
            cin >> val;
            q.push(val);
        } else if (op == "pop") {
            int res = q.pop();
            if (res > 0) {
                std::cout << res << std::endl;
            }
        } else if (op == "front") {
            int res = q.front();
            if (res > 0) {
                std::cout << res << std::endl;
            }
        } 
    }

    return 0;
}