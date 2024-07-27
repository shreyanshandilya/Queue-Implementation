#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Queue {
    T* arr;
    int capacity;
    int size;
    int nextIndex;
    int firstIndex;
    public:
        Queue() {
            capacity = 5;
            arr = new T[capacity];
            size = 0;
            nextIndex = 0;
            firstIndex = -1;
        }

        int getSize() {
            return size;
        }

        bool isEmpty() {
            return size==0;
        }

        void push(T x) {
            if(size==capacity) {
                T* newArr = new T[2*capacity];
                int j = 0;
                for(int i=firstIndex; i<size; i++) {
                    newArr[j++] = arr[i];
                }
                for(int i=0; i<firstIndex; i++) {
                    newArr[j++] = arr[i];
                }
                capacity *= 2;
                delete []arr;
                arr = newArr;
                firstIndex = 0;
                nextIndex = size;
            }
            arr[nextIndex] = x;
            nextIndex = (nextIndex+1)%capacity;
            if(size==0) firstIndex = 0;
            size++;
        }

        void pop() {
            if(isEmpty()) {
                cout << "Queue empty" << endl;
                return;
            }
            firstIndex = (firstIndex+1)%capacity;
            size--;
        }

        T front() {
            if(isEmpty()) {
                cout << "Queue empty" << endl;
                return 0;
            }
            return arr[firstIndex];
        }
};

int main() {
    Queue<char> q;
    for(int i=0; i<10; i++) q.push(i+'a');
    while(!q.isEmpty()) {
        cout << q.front() << endl;
        q.pop();
    }
    return 0;
}




