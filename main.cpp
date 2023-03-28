#include <iostream>

using namespace std;

class Node {
public:

    int data;
    Node* next;
};

class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    void enqueue(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = nullptr;
        if (isEmpty()) {
            front = newNode;
            rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Cannot dequeue! Empty Queue" << endl;
            return;
        }
        Node* temp = front;
        front = front->next;
        delete temp;
    }

    int top() {
        if (isEmpty()) {
            cout << "None, Empty !" ;
            return 0;
        }
        return front->data;
    }

    bool isEmpty() {
        return (front == nullptr);
    }

    int size() {
        Node* temp = front;
        int count = 0;
        while (temp != nullptr) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

int main() {
    Queue queue;
    queue.enqueue(10);
    queue.enqueue(20);
    queue.enqueue(30);
    queue.enqueue(40);

    cout << "Top element : " << queue.top() << endl;
    cout << " Size: " << queue.size() << endl;


    queue.dequeue();

    cout << "Top element: " << queue.top() << endl;
    cout << "Size: " << queue.size() << endl;

    queue.dequeue();

    cout << "Top element: " << queue.top() << endl;
    cout << "Size: " << queue.size() << endl;

    queue.dequeue();


    cout << "Top element: " << queue.top() << endl;
    cout << "Size: " << queue.size() << endl;

    queue.dequeue();

    cout << "Top element: " << queue.top() << endl;
    cout << "Size: " << queue.size() << endl;

    queue.dequeue();

    queue.enqueue(10);
    cout << "Top element: " << queue.top() << endl;
    cout << "Size: " << queue.size() << endl;

    queue.enqueue(20);
    cout << "Top element: " << queue.top() << endl;
    cout << "Size: " << queue.size() << endl;





    return 0;
}