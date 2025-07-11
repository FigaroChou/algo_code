#include <iostream>
#include <string>
using namespace std;

struct Node {
    int _val;
    struct Node * _next;

    Node(int val) : _val(val) {}
    Node() : _val(-1), _next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : _head(new Node()) {}

    void insert(int x, int y) {
        Node *prev = _head;
        Node *cur = _head->_next;
        while (cur != nullptr && cur->_val != x) {
            prev = cur;
            cur = cur->_next;
        }

        Node *newNode = new Node(y);
        newNode->_next = cur;
        prev->_next = newNode;
    }

    void deleteNode(int x) {
        Node *prev = _head;
        Node *cur = _head->_next;
        while (cur != nullptr && cur->_val != x) {
            prev = cur;
            cur = cur->_next;
        }

        if (cur == nullptr) {
            prev->_next = nullptr;
        } else {
            prev->_next = cur->_next;
        }
    }

    void print() {
        Node *cur = _head->_next;
        if (cur == nullptr) {
            std::cout << "NULL" << std::endl;
            return;
        }
        while (cur != nullptr) {
            std::cout << cur->_val << " ";
            cur = cur->_next;
        }
        std::cout << std::endl;
    }
private:
    Node *_head;
};

int main() {
    int cnt;
    cin >> cnt;

    LinkedList l;

    std::string op;
    int x, y;
    while (cnt-- > 0) {
        cin >> op;
        if (op == "insert") {
            cin >> x >> y;
            l.insert(x, y);
        } else if (op == "delete") {
            cin >> x;
            l.deleteNode(x);
        }
    }

    l.print();

    return 0;
}
