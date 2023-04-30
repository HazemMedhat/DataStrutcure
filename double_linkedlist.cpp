#include<iostream>
using namespace std;

template <class T>
class doublyLinkedList
{
private:
    struct Node
    {
        T item;
        Node* next;
        Node* prev;
    };
    Node* first;
    Node* last;
    int count;

public:
    doublyLinkedList()
    {
        first = NULL;
        last = NULL;
        count = 0;
    }
    bool isEmpty()
    {
        return (first == NULL);
    }
    void clear()
    {
        Node *temp;
        while (first != NULL)
        {
            temp = first;
            first = first->next;
            delete temp;
        }
        last = NULL;
        count = 0;
    }

    void insertAtlast(T val)
    {
        Node* newNode = new Node;
        newNode->item = val;
        if (count == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = NULL;
            newNode->prev = last;
            last->next = newNode;
            last = newNode;
        }
        count++;
    }



    void insertAtfirst(T item)
    {
        Node*newNode = new Node;
        newNode->item = item;
        if (count == 0)
        {
            first = last = newNode;
            newNode->next = newNode->prev = NULL;
        }
        else
        {
            newNode->next = first;
            newNode->prev = NULL;
            first->prev = newNode;
            first = newNode;

        }
        count++;
    }


    void insertAt(int pos, T item)
    {
        if (pos < 0 || pos > count)
            cout << "Out Of Range ...!" << endl;
        else
        {
            Node *newNode = new Node;
            newNode->item = item;
            if (pos == 0)
                insertAtfirst(item);
            else if (pos == count)
                insertAtlast(item);
            else
            {
                Node *current = first;
                for (int i = 1; i < pos; i++)
                {
                    current = current->next;
                }

                newNode->next = current->next;
                newNode->prev = current;
                current->next->prev = newNode;
                current->next = newNode;
                count++;
            }

        }
    }

    void removeAtfirst()
    {
        if (count == 0)
            cout << "Empty List" << endl;
        else if (count == 1)//first == last
        {
            delete first;
            last = first = NULL;
        }
        else
        {
            Node* current = first;
            first = first->next;
            first->prev = NULL;
            delete current;

        }
        count--;
    }

    void removeAt(int pos)
    {
        if (pos < 0 || pos >= count)
        {
            cout << "Out Of Range" << endl;
            return;
        }
        else if (pos == 0)
        {
            removeAtfirst();
        }
        else if (pos == count - 1)
        {
            removeAtlast();
        }
        else
        {
            Node *current = first->next;


            for (int i = 1; i < pos; i++)
            {
                current = current->next;
            }
            current->prev->next = current->next;
            current->next->prev = current->prev;
            delete current;
        }
        count--;
    }
    void  removeAtlast()
    {
        if (count == 0)
            cout << "Empty List" << endl;
        else if (count == 1)
        {
            delete first;
            last = first = NULL;
            count--;
        }
        else
        {
            Node *current = last;
            last = last->prev;
            last->next = NULL;
            delete current;
            count--;
        }
    }

    void remove(int item)
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Remove ";
            return;
        }
        Node*current = first->next;

        if (first->item == item)//delete the first element, special case
        {
            removeAtfirst();
            return;
        }
        else
        {
            while (current != NULL)//current->item!=element
            {
                if (current->item == item)
                    break;
                current = current->next;
            }

            if (current == NULL)
            {
                cout << "The item is not there\n";
                return;
            }
            else if (current->next == NULL)
            {
                removeAtlast();
                return;
            }

            else
            {
                current->prev->next = current->next;
                //if (current->next != NULL)
                current->next->prev = current->prev;
                delete current;
                count--;
            }

        }


    }

    void forwardTraversal()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Display...!";
        }
        else
        {
            Node* temp = first;
            while (temp != nullptr)
            {
                cout << temp->item << " ";
                temp = temp->next;
            }
        }
        cout << endl;

    }

    void backwardTraversal()
    {
        if (isEmpty())
        {
            cout << "Empty List Can't Display Reverse...!";
        }
        else
        {
            Node* temp = last;
            while (temp != NULL)
            {
                cout << temp->item << " ";
                temp = temp->prev;
            }
        }

    }

   void retrieveAt(int pos)
    {
        if (pos < 0 || pos > count)
            cout << "Out Of Range ...!" << endl;
        Node *current = first->next;
        for (int i = 1; i < pos-1; i++)
        {
            current = current->next;
        }
       cout<<current->item<<endl;
    }

   void replaceAt(T n,int pos){
       if (pos < 0 || pos > count)
           cout << "Out Of Range ...!" << endl;
       Node *current = first;
       for (int i = 0; i < pos-1; i++)
       {
           current = current->next;
       }
       current->item=n;
    }
    bool isExist(T n){
        Node *current = first;
        while(current)
        {
            if(n==current->item)return true;
            current = current->next;
        }
        return false;
    }
    bool isItemAtEqual(T n,int pos){
        Node *current = first;
        for (int i = 0; i < pos-1; i++)
        {
            current = current->next;
        }
        if(n==current->item)return true;
        return false;
    }
    int size(){
        return count;
    }
    void reverse(){
        if(first != NULL) {
            Node* prevNode = first;
            Node* tempNode = first;
            Node* curNode = first->next;

            prevNode->next = NULL;
            prevNode->prev = NULL;

            while(curNode != NULL) {
                tempNode = curNode->next;
                curNode->next = prevNode;
                prevNode->prev = curNode;
                prevNode = curNode;
                curNode = tempNode;
            }
            first = prevNode;
        }
    }
    void swap(int node1, int node2) {

        Node* temp = first;
        int N = 0;
        while(temp != NULL) {
            N++;
            temp = temp->next;
        }

        if(node1 < 1 || node1 > N || node2 < 1 || node2 > N)
            return;

        Node* pos1 = first;
        Node* pos2 = first;
        for(int i = 1; i < node1; i++) {
            pos1 = pos1->next;
        }
        for(int i = 1; i < node2; i++) {
            pos2 = pos2->next;
        }

        int val = pos1->item;
        pos1->item = pos2->item;
        pos2->item = val;
    }

    void insertAfter(T old, int element)
    {
         Node* newItem;
        newItem=new Node;
         Node* temp;
        temp=first;
        if(first==NULL)
        {
            cout<<"could not insert"<<endl;
            return;
        }
        if(first==last)
        {
            if(first->item!=old)
            {
                cout<<"could not insert"<<endl;
                return;
            }
            newItem->item=element;
            first->next=newItem;
            newItem->next=NULL;
            first->prev=NULL;
            newItem->prev=first;
            last=newItem;
            return;
        }
        if(last->item==element)
        {
            newItem->next=NULL;
            newItem->prev=last;
            last->next=newItem;
            last=newItem;
            return;
        }
        while(temp->item!=old)
        {
            temp=temp->next;
            if(temp==NULL)
            {
                cout<<"Could not insert"<<endl;
                cout<<"element not found"<<endl;
                return;
            }
        }
        newItem->next=temp->next;
        newItem->prev=temp;
        newItem->item=element;
        temp->next->prev=newItem;
        temp->next=newItem;
    }
};
int main()
{
    doublyLinkedList<int> dl;
    dl.insertAt(0, 4);
    dl.insertAt(1, 6);
    dl.insertAt(2, 7);
    dl.insertAtfirst(2);
    dl.insertAtlast(10);
    dl.forwardTraversal();
    dl.remove(7);
    dl.insertAfter(6,5);
    dl.retrieveAt(2);
    dl.forwardTraversal();
    dl.replaceAt(5,1);
    dl.swap(2,3);
    dl.forwardTraversal();
    dl.reverse();
    dl.forwardTraversal();
    if(dl.isExist(5))cout<<"YES"<<endl;
    else cout<<"No"<<endl;
    if(dl.isItemAtEqual(10,4))cout<<"YES"<<endl;
    else cout<<"No"<<endl;
    cout<<dl.size()<<endl;
    dl.clear();
    dl.backwardTraversal();
}
