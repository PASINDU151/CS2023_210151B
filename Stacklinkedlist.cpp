#include <iostream>
#include <chrono>
using namespace std::chrono; 
using namespace std;

struct Node {
    int data;
    Node* next;
};

class Stack {
private:
    Node* head;
public:
    Stack() {
        head = nullptr;
    }

    void Push(int value) {
        Node* newNode = new Node;
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    
    int Pop() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        int popValue = head->data;
        Node* temp = head;
        head = head->next;
        delete temp;
        return popValue;
    }

    int StackTop() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        return head->data;
    }

    
    bool isEmpty() {
        return (head == nullptr);
    }

    
    void Display() {
        if (head == nullptr) {
            cout << "Stack is empty!" << endl;
            return;
        }
        Node* temp = head;
        cout << "Stack elements: ";
        while (temp != nullptr) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};



int main() {
  
    Stack s;auto start = high_resolution_clock::now();
    s.Push(8);
    s.Push(10);
    s.Push(5);
    s.Push(11);
    s.Push(15);
    s.Push(23);
    s.Push(6);
    s.Push(18);
    s.Push(20);
    s.Push(17);
    s.Display();
    cout << "Popped elements: ";
  for (int i=0;i<5;i++){
    cout << s.Pop() << " ";
  }
    cout << endl;
    s.Display();
    s.Push(4);
    s.Push(30);
    s.Push(3);
    s.Push(1);
    s.Display();auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
 
cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
  
}