#include <iostream>
#include <chrono>
using namespace std;
using namespace std::chrono;



class Stack {
private:

    int arr[100];
    int top;
public:
    Stack() {
        top = -1;
    }

    bool is_empty() {
        return top == -1;
    }

    bool is_full() {
        return top == 100 - 1;
    }

    void push(int data) {
        if (is_full()) {
            cout << "Error: Stack is full" << endl;
            return;
        }
        arr[++top] = data;
    }

    int pop() {
        if (is_empty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top--];
    }

    int StackTop() {
        if (is_empty()) {
            cout << "Error: Stack is empty" << endl;
            return -1;
        }
        return arr[top];
    }

    void display() {
        if (is_empty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements are: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
  
    Stack s;auto start = high_resolution_clock::now();
    s.push(8);
    s.push(10);
    s.push(5);
    s.push(11);
    s.push(15);
    s.push(23);
    s.push(6);
    s.push(18);
    s.push(20);
    s.push(17);
    s.display();
    cout << "Popping 5 elements from the stack: ";
    for (int i = 0; i < 5; i++) {
        cout << s.pop() << " ";
    }
    cout << endl;
    s.display();
    s.push(4);
    s.push(30);
    s.push(3);
    s.push(1);
    s.display();
  auto stop = high_resolution_clock::now();
  auto duration = duration_cast<microseconds>(stop - start);
 
cout << "Time taken by function: "<< duration.count() << " microseconds" << endl;
}

