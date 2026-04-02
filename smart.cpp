#include <iostream>
#include <string>
#include <memory>

using namespace std;

struct SmartListNode {
    int id;
    string name;
    unique_ptr<SmartListNode> next;

    SmartListNode(int i, string n, unique_ptr<SmartListNode> nx = nullptr)
        : id(i), name(n), next(move(nx)) {}
};

class SmartNodeList {
private:
    unique_ptr<SmartListNode> head;
    int count;

public:
    SmartNodeList() : head(nullptr), count(0) {}

    void addNode(int id, string name) {
        head = make_unique<SmartListNode>(id, name, move(head));
        count++;
    }

    void display() const {
        SmartListNode* curr = head.get();

        while (curr) {
            cout << "[" << curr->id << ": "
                 << curr->name << "] -> ";
            curr = curr->next.get();
        }

        cout << "null" << endl;
    }
};

int main() {
    SmartNodeList list;

    list.addNode(1, "Router");
    list.addNode(2, "Switch");
    list.addNode(3, "Firewall");

    list.display();

    return 0;
}