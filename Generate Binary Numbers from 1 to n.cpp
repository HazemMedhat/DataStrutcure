#include <iostream>
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
    Queue(){
        arr = new int [SIZE];
        capacity = SIZE;
        Front = 0;
        End = -1;
        counter = 0;
    }
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

        cout << "Inserting " << item << endl;

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
        cout << "Removing " << x << endl;

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

void generatePrintBinary(int n)
{
    for(int i=1;i<=n;i++){
        Queue <string> Q(n);
        string str="";
        int temp=i;
        while(temp){
            if(temp&1){str=to_string(1)+str;}
            else{str=to_string(0)+str;}
            Q.enqueue(str);
            temp=temp>>1;
        }
        Q.print();
    }
}


int main()
{
    generatePrintBinary(5);
}