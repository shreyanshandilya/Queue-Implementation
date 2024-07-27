#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Stack {
    T *arr;
    int capacity = 0;
    int size = 0;
    public:
        Stack() {
            capacity = 4;
            arr = new T[capacity];
        }
        bool isEmpty() {
            return size==0;
        }
        int getSize() {
            return size;
        }
        void push(int x) {
            if(size==capacity) {
                capacity *= 2;
                T* newArr = new T[2*capacity];
                for(int i=0; i<size; i++) {
                    newArr[i] = arr[i];
                }
                capacity = 2*capacity;
                delete []arr; 
                arr = newArr;
            }
            arr[size] = x;
            size++;
        }
        void pop() {
            if(isEmpty()) return;
            size--;
        }
        T top() {
            if(isEmpty()) {
                cout << "Stack empty" << endl;
                return -1;
            }
            return arr[size-1];
        }
};

int main() {
    Stack<int> s;
    for(int i=1; i<=10; i++) s.push(i);
    while(!s.isEmpty()) {
        cout << s.top() << endl;
        s.pop();
    }
    cout << s.getSize() << endl;
    return 0;
}




