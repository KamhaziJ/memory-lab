#include <iostream>
#include <string>

using namespace std;

struct ListNode {
    int id;
    string name;
    ListNode* next;

    ListNode(int i, string n, ListNode* nx = nullptr)
        : id(i), name(n), next(nx) {}
};

class NodeList {
private:
    ListNode* head;
    int count;

public:
    NodeList() : head(nullptr), count(0) {}

    // Copy Constructor
    NodeList(const NodeList& other) : head(nullptr), count(0) {
        ListNode* curr = other.head;
        ListNode* tail = nullptr;

        while (curr) {
            ListNode* newNode = new ListNode(curr->id, curr->name);

            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            curr = curr->next;
            count++;
        }
    }

    // Assignment Operator
    NodeList& operator=(const NodeList& other) {
        if (this == &other) {
            return *this;
        }

        // Delete existing nodes
        ListNode* curr = head;
        while (curr) {
            ListNode* temp = curr;
            curr = curr->next;
            delete temp;
        }

        head = nullptr;
        count = 0;

        ListNode* otherCurr = other.head;
        ListNode* tail = nullptr;

        while (otherCurr) {
            ListNode* newNode = new ListNode(otherCurr->id, otherCurr->name);

            if (!head) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                tail = newNode;
            }

            otherCurr = otherCurr->next;
            count++;
        }

        return *this;
    }

    void addNode(int id, string name) {
        ListNode* n = new ListNode(id, name, head);
        head = n;
        count++;
    }

    void removeNode(int id) {
        ListNode* prev = nullptr;
        ListNode* curr = head;

        while (curr && curr->id != id) {
            prev = curr;
            curr = curr->next;
        }

        if (!curr) return;

        if (prev)
            prev->next = curr->next;
        else
            head = curr->next;

        delete curr;
        count--;
    }

    void display() const {
        ListNode* curr = head;

        while (curr) {
            cout << "[" << curr->id << ": "
                 << curr->name << "] -> ";
            curr = curr->next;
        }

        cout << "null" << endl;
    }

   // Destructor
~NodeList() {
    ListNode* curr = head;
    while (curr) {
        ListNode* temp = curr;
        curr = curr->next;
        delete temp;
    }
}
};

int main() {
    NodeList list;

    list.addNode(1, "Router");
    list.addNode(2, "Switch");
    list.addNode(3, "Firewall");

    list.display();

    list.removeNode(2);

    list.display();

    return 0;
}