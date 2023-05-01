#include <iostream>
#include <bits/stdc++.h>
using namespace std;

//#define SIZE 1000  ///default capacity of a queue

template<typename T>
class Queue
{
    T *arr;
    int capacity;
    int Front;
    int End;
    int counter;

public:
//    Queue()
//    {
//        arr = new T ;
//        capacity ;
//        Front = 0;
//        End = -1;
//        counter = 0;
//    }
    Queue(int size)
    {
        arr = new T[size];
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

//        cout << "Inserting " << item << endl;
//
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

    int x = front();
//    cout << "Removing " << x << endl;

    Front = (Front + 1) % capacity;
    counter--;

    return x;
    }


//    void enqueue(T val) {
//        if (isFull()) {
//            cout << "Queue is full" << endl;
//            return;
//        }
//
//        if (isEmpty()) {
//            Front = 0;
//            End = 0;
//        } else {
//            End++;
//        }
//
//        arr[End] = val;
//    }
//
//    int dequeue()  {
//        if (isEmpty()) {
//            cout << "Queue is empty" << endl;
//            exit(EXIT_FAILURE);
//        }
//
//        T x = arr[Front];
//        Front = (Front + 1) % capacity;
//        End--;
//        return x;
//    }

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

    void print()
    {
        for(int i =0; i < counter; i++)
        {
            cout<<"Element [ "<<i+1<<" ] -> "<<arr[i]<<endl;
        }
    }
};


int minIndex(Queue<int> &q, int sortedIndex)
{
    int min_index = -1;
    int min_val = INT_MAX;
    int n = q.queueSize();
    for (int i=0; i<n; i++)
    {
        int curr = q.front();
        q.dequeue();
        if (curr <= min_val && i <= sortedIndex)
        {
            min_index = i;
            min_val = curr;
        }
        q.enqueue(curr);
    }
    return min_index;
}

void insertMinToRear(Queue<int> &q, int min_index)
{
    int min_val;
    int n = q.queueSize();
    for (int i = 0; i < n; i++)
    {
        int curr = q.front();
        q.dequeue();
        if (i != min_index)
            q.enqueue(curr);
        else
            min_val = curr;
    }
    q.enqueue(min_val);
    q.print();
}

void sortQueue(Queue<int> &q)
{
    int n = q.queueSize();
    for(int i=0;i<n;i++)      // n iterations for sorting n elements
    {
        int minIndex = -1;
        int minValue = INT_MAX;
        for(int j=0;j<n-i;i++)  // this loop picks the min elt in the queue
        {
            if(q.front() < minValue)
            {
                minValue = q.front();
                minIndex = j;
            }
            q.enqueue(q.dequeue());
        }

        for(int k=0;k<minIndex;k++) // removes the elements occuring before min elt and adds them at the end of the queue
        {
            q.enqueue(q.dequeue());
        }
        int minElt = q.dequeue(); // removes the minElt from the queue and stores it for later use
        for(int k = minIndex+1;k<n;k++) // removes the elts occuring after minElt from the front of queue and adds them at the queue
        {
            q.enqueue(q.dequeue());
        }
        q.enqueue(minElt);   // finally add the minELt at the end of the queue
    }
//    q.print();
}

int main()
{

    Queue<int> q(4);
    q.enqueue(30);
    q.enqueue(12);
    q.enqueue(16);
    q.enqueue(2);
    q.print();
    sortQueue(q);
//    q.print();
//    while (!q.isEmpty()) {
//        cout << q.front() << " ";
//        q.dequeue();
//    }
}
