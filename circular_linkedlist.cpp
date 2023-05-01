#include <bits/stdc++.h>
using namespace std;

template<class T>
class CircularLinkedList
{
private:
    struct Node
    {
        T data;
        Node* next;
        Node* prev;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head;
    int size;

    Node* getNode(int index)
    {
        if (index < 0 || index >= size) return nullptr;
        if (index == 0) return head;
        Node* cur = head->next;
        for (int i = 1; i < index; i++)
        {
            cur = cur->next;
        }
        return cur;
    }

public:
    CircularLinkedList() : head(nullptr), size(0) {}

    // insert at head
    void insertAtHead(T element)
    {
        Node* newNode = new Node(element);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node* tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }
            newNode->next = head;
            tail->next = newNode;
            head = newNode;
        }
        size++;
    }

    // insert at end
    void insertAtEnd(T element)
    {
        Node* newNode = new Node(element);
        if (head == nullptr)
        {
            head = newNode;
            head->next = head;
        }
        else
        {
            Node* tail = head;
            while (tail->next != head)
            {
                tail = tail->next;
            }
            tail->next = newNode;
            newNode->next = head;
        }
        size++;
    }

    // insert at index
    void insertAt(T element, int index)
    {
        if (index < 0 || index > size) return;
        if (index == 0)
        {
            insertAtHead(element);
            return;
        }
        if (index == size)
        {
            insertAtEnd(element);
            return;
        }
        Node* prev = getNode(index - 1);
        Node* next = prev->next;
        Node* newNode = new Node(element);
        prev->next = newNode;
        newNode->next = next;
        size++;
    }

    // remove at head
    void removeAtHead()
    {
        if (head == nullptr) return;
        Node* tail = head;
        while (tail->next != head)
        {
            tail = tail->next;
        }
        Node* next = head->next;
        tail->next = next;
        delete head;
        head = next;
        size--;
    }

    // remove at end
    void removeAtEnd()
    {
        if (head == nullptr) return;
        Node* tail = head;
        Node* prev = nullptr;
        while (tail->next != head)
        {
            prev = tail;
            tail = tail->next;
        }
        prev->next = head;
        delete tail;
        size--;
    }

    // remove at index
    void removeAt(int index)
    {
        if (index < 0 || index >= size) return;
        if (index == 0)
        {
            removeAtHead();
            return;
        }
        if (index == size - 1)
        {
            removeAtEnd();
            return;
        }
        Node* prev = getNode(index - 1);
        Node* target = prev->next;
        Node* next = target->next;
        prev->next = next;
        delete target;
        size--;
    }

    T retrieveAt(int index)
    {
        if (head == nullptr)   // check if the list is empty
        {
            throw runtime_error("Error: List is empty.");
        }

        int i = 0;
        Node* current = head;

        do
        {
            if (i == index)
            {
                return current->data;
            }

            current = current->next;
            i++;
        }
        while (current != head);

        throw runtime_error("Error: Index out of bounds.");
    } void replaceAt(T newElement, int index)
    {
        if (head == nullptr)   // check if the list is empty
        {
            throw runtime_error("Error: List is empty.");
        }

        int i = 0;
        Node* current = head;

        do
        {
            if (i == index)
            {
                current->data = newElement;
                return;
            }

            current = current->next;
            i++;
        }
        while (current != head);

        throw runtime_error("Error: Index out of bounds.");
    }

    bool isExist(T element)
    {
        if (head == nullptr)   // check if the list is empty
        {
            return false;
        }

        Node* current = head;

        do
        {
            if (current->data == element)
            {
                return true;
            }

            current = current->next;
        }
        while (current != head);

        return false;
    }

    bool isItemAtEqual(T element, int index)
    {
        if (head == nullptr)   // check if the list is empty
        {
            throw runtime_error("Error: List is empty.");
        }

        int i = 0;
        Node* current = head;

        do
        {
            if (i == index && current->data == element)
            {
                return true;
            }

            current = current->next;
            i++;
        }
        while (current != head);

        return false;
    }

    void swap(int firstItemIdx, int secondItemIdx)
    {
        if (head == nullptr)   // check if the list is empty
        {
            throw runtime_error("Error: List is empty.");
        }

        if (firstItemIdx == secondItemIdx)   // check if both indices are the same
        {
            return;
        }

        if (firstItemIdx > secondItemIdx)   // swap indices if needed
        {
            swap(firstItemIdx, secondItemIdx);
        }

        int i = 0;
        Node* current = head;
        Node* firstItem = nullptr;
        Node* secondItem = nullptr;

        do
        {
            if (i == firstItemIdx)
            {
                firstItem = current;
            }
            else if (i == secondItemIdx)
            {
                secondItem = current;
                break;
            }

            current = current->next;
            i++;
        }
        while (current != head);

        if (firstItem == nullptr || secondItem == nullptr)   // check if indices are valid
        {
            throw runtime_error("Error: Invalid indices.");
        }

        // swap the nodes without swapping data
        Node* temp = firstItem->next;
        firstItem->next = secondItem->next;
        secondItem->next = temp;

        temp = firstItem->prev;
        firstItem->prev = secondItem->prev;
        secondItem->prev = temp;

        if (firstItemIdx == 0)   // update head if necessary
        {
            head = secondItem;
        }
        else if (secondItemIdx == 0)
        {
            head = firstItem;
        }
    }

    bool isEmpty()
    {
        return head == nullptr;
    }

    int circularLinkedListSize()
    {
        if (head == nullptr)   // check if list is empty
        {
            return 0;
        }

        int size = 1;
        Node* current = head->next;

        while (current != head)   // loop through the list and count nodes
        {
            size++;
            current = current->next;
        }

        return size;
    }

    void clear()
    {
        if (head == nullptr)   // check if list is already empty
        {
            return;
        }

        Node* current = head->next;

        while (current != head)   // loop through the list and delete nodes
        {
            Node* temp = current;
            current = current->next;
            delete temp;
        }

        delete head;
        head = nullptr;
    }

    void print()
    {
        if (head == nullptr)   // check if list is empty
        {
            cout << "List is empty." << endl;
            return;
        }

        Node* current = head;

        do   // loop through the list and print each node's data
        {
            cout << current->data << " ";
            current = current->next;
        }
        while (current != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList<int> myList;

    myList.insertAtEnd(10);
    myList.insertAtEnd(20);
    myList.insertAtEnd(30);

    cout << "Original List: ";
    myList.print(); // Output: Original List: 10 20 30

    myList.insertAtHead(5);
    myList.insertAt(15, 2);

    cout << "List after insertions: ";
    myList.print(); // Output: List after insertions: 5 10 15 20 30

    myList.removeAtEnd();
    myList.removeAt(2);

    cout << "List after removals: ";
    myList.print(); // Output: List after removals: 5 10 20

    cout << "Element at index 1: " << myList.retrieveAt(1) << endl; // Output: Element at index 1: 10

    myList.replaceAt(25, 1);
    cout << "List after replacement: ";
    myList.print(); // Output: List after replacement: 5 25 20

    cout << "Is 20 in the list? " << (myList.isExist(20) ? "Yes" : "No") << endl; // Output: Is 20 in the list? Yes
    cout << "Is 15 at index 1? " << (myList.isItemAtEqual(15, 1) ? "Yes" : "No") << endl; // Output: Is 15 at index 1? No

    myList.swap(0, 2);
    cout << "List after swap: ";
    myList.print(); // Output: List after swap: 20 25 5

    cout << "List size: " << myList.circularLinkedListSize() << endl; // Output: List size: 3

    myList.clear();
    cout << "List after clear: ";
    myList.print(); // Output: List after clear: List is empty.

    return 0;
}
