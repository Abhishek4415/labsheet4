// Name  Abhishke kumar
// ROLLNO 2301010322
// SUBJECT DATASTRUCTURE 

#include <iostream>
#include <stack>
#include <queue>
#include <sstream>
#include <vector>
using namespace std;

// Singly Linked List
class SinglyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    SinglyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
        }
    }

    void deleteNode(int value) {
        if (!head) return;
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }
        Node* temp = head;
        while (temp->next && temp->next->data != value)
            temp = temp->next;
        if (temp->next) {
            Node* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
    }

    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Doubly Linked List
class DoublyLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node* prev;
        Node(int val) : data(val), next(nullptr), prev(nullptr) {}
    };
    Node* head;

public:
    DoublyLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next)
                temp = temp->next;
            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    void deleteNode(int value) {
        if (!head) return;
        Node* temp = head;
        while (temp && temp->data != value)
            temp = temp->next;
        if (temp) {
            if (temp->prev)
                temp->prev->next = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            if (temp == head)
                head = temp->next;
            delete temp;
        }
    }

    void traverse() {
        Node* temp = head;
        while (temp) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

// Circular Linked List
class CircularLinkedList {
private:
    struct Node {
        int data;
        Node* next;
        Node(int val) : data(val), next(nullptr) {}
    };
    Node* head;

public:
    CircularLinkedList() : head(nullptr) {}

    void insert(int value) {
        Node* newNode = new Node(value);
        if (!head) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = newNode;
            newNode->next = head;
        }
    }

    void deleteNode(int value) {
        if (!head) return;
        Node* temp = head;
        Node* prev = nullptr;
        do {
            if (temp->data == value) break;
            prev = temp;
            temp = temp->next;
        } while (temp != head);

        if (temp->data == value) {
            if (prev) {
                prev->next = temp->next;
                if (temp == head)
                    head = head->next;
            } else {
                Node* tail = head;
                while (tail->next != head)
                    tail = tail->next;
                head = head->next;
                tail->next = head;
            }
            delete temp;
        }
    }

    void traverse() {
        if (!head) return;
        Node* temp = head;
        do {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
};

// Postfix Calculator class
class PostfixCalculator {
public:
    int evaluate(const string& expression) {
        stack<int> stk;
        stringstream ss(expression);
        string token;

        while (ss >> token) {
            if (isdigit(token[0])) {
                stk.push(stoi(token));
            } else {
                int b = stk.top(); stk.pop();
                int a = stk.top(); stk.pop();
                switch (token[0]) {
                    case '+': stk.push(a + b); break;
                    case '-': stk.push(a - b); break;
                    case '*': stk.push(a * b); break;
                    case '/': stk.push(a / b); break;
                }
            }
        }
        return stk.top();
    }
};

// Queue-Based Ticketing System
class TicketQueue {
private:
    queue<int> ticketQueue;
    int ticketNumber = 1;

public:
    void addTicket() {
        ticketQueue.push(ticketNumber++);
        cout << "Ticket " << ticketNumber - 1 << " added to queue.\n";
    }

    void processTicket() {
        if (!ticketQueue.empty()) {
            cout << "Processing ticket " << ticketQueue.front() << endl;
            ticketQueue.pop();
        } else {
            cout << "No tickets to process.\n";
        }
    }

    void displayQueue() {
        queue<int> tempQueue = ticketQueue;
        while (!tempQueue.empty()) {
            cout << tempQueue.front() << " ";
            tempQueue.pop();
        }
        cout << endl;
    }
};

// Priority Queue Using Heap
class PriorityQueue {
private:
    priority_queue<int> pq;

public:
    void insert(int value) {
        pq.push(value);
    }

    void deleteMax() {
        if (!pq.empty()) pq.pop();
    }

    int getMax() {
        return pq.top();
    }

    void display() {
        priority_queue<int> temp = pq;
        while (!temp.empty()) {
            cout << temp.top() << " ";
            temp.pop();
        }
        cout << endl;
    }
};

// Main Function
int main() {
    // Test Singly Linked List
    SinglyLinkedList sll;
    sll.insert(10);
    sll.insert(20);
    sll.insert(30);
    sll.traverse();
    sll.deleteNode(20);
    sll.traverse();

    // Test Postfix Calculator
    PostfixCalculator calc;
    cout << "Postfix Result: " << calc.evaluate("3 4 + 2 * 7 /") << endl;

    // Test Ticket Queue
    TicketQueue tq;
    tq.addTicket();
    tq.addTicket();
    tq.processTicket();
    tq.displayQueue();

    // Test Priority Queue
    PriorityQueue pq;
    pq.insert(15);
    pq.insert(5);
    pq.insert(30);
    pq.display();
    return 0;
}
