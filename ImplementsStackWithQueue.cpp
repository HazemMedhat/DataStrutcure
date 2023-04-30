#include <bits/stdc++.h>
using namespace std;

#define SIZE 1000  ///default capacity of a queue

template<typename T>
class Queue
{
    T *arr;
    int capacity;
    int Front;
    int End;
    int counter;

public:
//    Queue(){
//        arr = new int [SIZE];
//        capacity = SIZE;
//        Front = 0;
//        End = -1;
//        counter = 0;
//    }
    Queue(int size = SIZE)
    {
        arr = new int[size];
        capacity = size;
        Front = 0;
        End = -1;
        counter = 0;
    }

    ~Queue()
    {
        delete[] arr;
    }

    void enqueue(T item)
    {
        if (isFull())
        {
            cout << "Overflow\nthe queue is full\n";
            exit(EXIT_FAILURE);
        }

        // cout << "Inserting " << item << endl;

        End = (End + 1) % capacity;
        arr[End] = item;
        counter++;
    }

    int dequeue()
    {
        if (isEmpty())
        {
            cout << "Error!!The queue is empty\n";
            exit(EXIT_FAILURE);
        }

        int x = arr[Front];
        //  cout << "Removing " << x << endl;

        Front = (Front + 1) % capacity;
        counter--;

        return x;
    }

    int front()
    {
        if (isEmpty())
        {
            cout << "Error!!The queue is empty\n";
            exit(EXIT_FAILURE);
        }
        return arr[Front];
    }

    int queueSize()
    {
        return counter;
    }

    bool isEmpty()
    {
        return (queueSize() == 0);
    }

    bool isFull()
    {
        return (queueSize() == capacity);
    }

    void print(){
        for(int i =0;i < counter;i++){
            cout<<"Element [ "<<i+1<<" ] -> "<<arr[i]<<endl;
        }
    }
};
template<typename T>
class Stack {
private:
    Queue<T> q;
public:
    // enqueue element onto the stack
    void enqueue(T x) {
        q.enqueue(x);
        int n = q.queueSize();
        // Rotate the queue to make the recently added element the top of the stack
        for (int i = 0; i < n - 1; i++) {
            int temp = q.front();
            q.dequeue();
            q.enqueue(temp);
        }
    }
    // Remove and return the top element of the stack
    int dequeue() {
        if (q.isEmpty()) {
            return -1; // Stack is empty
        }
        int top = q.front();
        q.dequeue();
        return top;
    }

    // Returns the top element of the stack without removing it
    int top() {
        if (q.isEmpty()) {
            return -1; // Stack is empty
        }
        // cout<<q.front()<<endl;
        return q.front();
    }

    // Returns true if the stack is empty
    bool empty() {
        return q.isEmpty();
    }
};

int main()
{
    Stack <int>obj;
    obj.enqueue(5);
    obj.enqueue(6);
    obj.enqueue(7);
    cout<<obj.top()<<endl;
    obj.dequeue();
    cout<<obj.top()<<endl;
    return 0;
}