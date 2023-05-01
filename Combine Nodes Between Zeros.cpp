#include <iostream>

using namespace std;

template <class T>
class node
{
public:
    T data;
    node *next;
};



template <class T>
class single_linked_list
{
private:
    node<T> *head;
public:
    int length;
    single_linked_list();
    ~single_linked_list();
    void insertAtHead(T);
    void insertAtTail(T);
    void insertAt(int,T);
    void removeTail();
    void removeHead();
    void removeAt(int);
    void retrieveAt(int);
    void replaceAt(T,int);
    bool isExist(T);
    bool isItemAtEqual(T,int);
    bool isEmpty();
    void listSize();
    void swap(int,int);
    void clear();
    void display_all();
    node<T>*GetHead();
    node<T>* setHead(node<T>* Head) ;
    void SumBetweenZeros(single_linked_list<T> obj);

};

template <class T>
node<T>* single_linked_list<T>::GetHead() {
    return head;
}

template <class T>
node<T>* single_linked_list<T>::setHead(node<T>* Head) {
    head=Head;
}

template <class T>
void single_linked_list<T>:: SumBetweenZeros(single_linked_list<T> ob)
{
    if(ob.GetHead()->data==0)
    {
        ob.setHead(ob.GetHead()->next);
    }
    node<T>* result = ob.GetHead();
    node<T>* temp = ob.GetHead();
    int sum = 0;

    while(temp)
    {

        if(temp->data != 0)
        {
            sum += temp->data;
            temp = temp->next;
        }

        else
        {
            result->data = sum;
            result->next = temp->next;
            temp = temp->next;
            result = temp;
            sum = 0;
        }
    }
    ob.display_all();
}

template <class T>
single_linked_list<T>::single_linked_list()
{
    this->length = 0;
    this->head = NULL;
}

template <class T>
single_linked_list<T>::~single_linked_list(){}

template <class T>
void single_linked_list<T>::insertAt(int pos,T n)
{
    node <T>*pre = new node<T>;
    node <T>*cur = new node<T>;
    node <T>*temp = new node<T>;

    if(pos==0)
    {
        temp->data = n;
        temp->next = this->head;
        this->head = temp;
    }
    else
    {
        cur=this->head;
        for (int i = 0; i < pos ; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        temp->data = n;
        temp->next = cur;
        pre->next = temp;
    }
    this->length++;
}

template <class T>
void single_linked_list<T>::insertAtHead(T n)
{
    insertAt(0,n);
}

template <class T>
void single_linked_list<T>::insertAtTail(T n)
{
    insertAt(this->length,n);
}

template <class T>
void single_linked_list<T>::removeAt(int pos)
{
    node <T>*pre = new node<T>;
    node <T>*cur = new node<T>;
    cur = this->head;

    if(pos == 0)
    {
        pre = this->head;
        head = head->next;
    }
    else
    {
        for (int i = 0; i < pos; i++)
        {
            pre = cur;
            cur = cur->next;
        }
        pre->next = cur->next;
    }
    this->length--;
}

template <class T>
void single_linked_list<T>::removeHead()
{
    removeAt(0);
}

template <class T>
void single_linked_list<T>::removeTail()
{
    removeAt(this->length-1);
}

template <class T>
void single_linked_list<T>::retrieveAt(int n)
{
    node<T> *new_node = this->head;
    for (int i = 0; i < n; i++)
        new_node = new_node->next;
    cout <<"The value at index "<<n<<" = "<< new_node->data << "\n";
    cout<<endl;
}

template <class T>
void single_linked_list<T>::replaceAt(T n,int pos)
{
    node <T>*new_node = this->head;
    for (int i = 0; i < pos; i++)
        new_node = new_node->next;
    new_node->data=n;
}

template <class T>
bool single_linked_list<T>::isExist(T n){
    node<T> *new_node = this->head;
    while(new_node)
    {
        if(n==new_node->data)return true;
        new_node = new_node->next;
    }
    return false;
}

template <class T>
void single_linked_list<T>::listSize(){
    node <T>*new_node = this->head;
    int count=0;
    while(new_node)
    {
        new_node=new_node->next;
        count++;
    }
    cout<<"List size = "<<count<<endl<<endl;
}

template <class T>
bool single_linked_list<T>::isEmpty(){
    if (head == NULL) {
        return 1;
    }
    return 0;
}

template <class T>
void single_linked_list<T>::clear(){
    head=NULL;
}

template <class T>
bool single_linked_list<T>::isItemAtEqual(T n,int pos){
    node <T>*new_node = this->head;
    for (int i = 0; i < pos; i++)
        new_node = new_node->next;
    if(n==new_node->data)return true;
    else return false;
//    int l;
//   l= new_node->data;
//   cout<<l<<endl;
//    if(ans==n)return 1;
}

template <class T>
void single_linked_list<T>::swap(int n1,int n2){
    node<T> *prevNode1 = NULL, *prevNode2 = NULL, *node1 = this->head, *node2 = this->head, *temp = NULL;
    if(isEmpty())return;
    if(n1==n2)return;
    for (int i = 0; i < n1; ++i) {
        prevNode1 = node1;
        node1 = node1->next;
    }
    for (int i = 0; i < n2; ++i) {
        prevNode2 = node2;
        node2 = node2->next;
    }

//    while(node2 != NULL && node2->data != n2){
//        prevNode2 = node2;
//        node2 = node2->next;
//    }
    //cout<<head<<" "<<node2<<endl;
    if(node1 !=NULL&& node2!=NULL) {
        if(prevNode1 != NULL)
            prevNode1->next = node2;
        else
            head  = node2;
        if(prevNode2 != NULL)
            prevNode2->next = node1;
        else
            head  = node1;
        temp = node1->next;
        node1->next = node2->next;
        node2->next = temp;
    }
    else{
        printf("Swapping is not possible\n");
    }
}

template <class T>
void single_linked_list<T>::display_all()
{
    node <T>*new_node = this->head;
    int i = 1;
    while(new_node)
    {
        cout << new_node->data << " ";
        new_node=new_node->next;
        i++;
    }
}



int main(){
    single_linked_list<int> ob;
    ob.insertAtTail(0);
    ob.insertAtTail(3);
    ob.insertAtTail(1);
    ob.insertAtTail(0);
    ob.insertAtTail(4);
    ob.insertAtTail(5);
    ob.insertAtTail(2);
    ob.insertAtTail(0);
    cout<<"linked list after insert"<<endl;
    ob.display_all();
    cout<<endl;
    ob.SumBetweenZeros(ob);

}