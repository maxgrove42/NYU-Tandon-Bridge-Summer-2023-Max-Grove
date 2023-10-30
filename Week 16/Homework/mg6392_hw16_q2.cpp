//
//  main.cpp
//  mg6392_hw16_q2
//
//  Created by Max Grove on 10/30/23.
//

#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Queue {
    private:
        vector<T> queue;
        int front;
        int size;
    public:
        Queue();
        Queue(const Queue& newQueue);
        ~Queue();
        void push(T item);
        T pop();
        bool empty() const;
        int getSize() const;
};

int main()
{
    Queue<int> myQueue;
    myQueue.push(3);
    myQueue.push(4);
    myQueue.push(5);
    cout << myQueue.getSize() << endl;
    cout << myQueue.pop() << endl;
    cout << myQueue.getSize() << endl;
    cout << myQueue.pop() << endl;
    cout << myQueue.getSize() << endl;
    myQueue.push(6);
    cout << myQueue.pop() << " " << myQueue.pop() << endl;
    cout << myQueue.getSize() << endl;
    cout << myQueue.pop() << endl;
    return 0;
}

template <class T>
Queue<T>::Queue() : front(0), size(0) {}

template <class T>
Queue<T>::~Queue() {
    while (!empty())
        pop();
}

template<class T>
void Queue<T>::push(T item) {
    queue.push_back(item);
    size++;
}

template<class T>
T Queue<T>::pop() {
    if (empty()) {
        cout << "Attempting to pop an empty queue." << endl;
        exit(1);
    }
    T temp = queue[front++];
    size--;
    if (empty()) {
        queue.clear();
        front = 0;
    }
    return temp;
}

template<class T>
bool Queue<T>::empty() const {
    return (size == 0);
}

template<class T>
int Queue<T>::getSize() const {
    return size;
}
