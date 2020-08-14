// header file for the templated DLList

#ifndef TEMPLATEDDLLIST_H
#define TEMPLATEDDLLIST_H
#include <stdexcept>
#include <iostream>

using namespace std;


template <class T> class DLList;

// doubly linked list node
template<class T>
struct DLListNode {
    T obj;
    DLListNode<T> *prev, * next;
    // constructor
    DLListNode<T>(T e = T(), DLListNode<T>* p = nullptr, DLListNode<T>* n = nullptr)
        : obj(e), prev(p), next(n) {}
    T getElem() const { return obj; }
    DLListNode<T>* getNext() const { return next; }
    DLListNode<T>* getPrev() const { return prev; }
};

// doubly linked list class
template <class T> class DLList {
private:
    DLListNode<T> header, trailer;
public:
    DLList() : header(T()), trailer(T()) // default constructor
    {
        header.next = &trailer; trailer.prev = &header;
    }
    DLList<T>(const DLList<T>& dll); // copy constructor
    DLList<T>(DLList<T>&& dll); // move constructor
    ~DLList<T>(); // destructor
    DLList<T>& operator=(const DLList<T>& dll); // copy assignment operator
    DLList<T>& operator=(DLList<T>&& dll); // move assignment operator
    // return the pointer to the first node
    DLListNode<T>* first_node() const { return header.next; }
    // return the pointer to the trailer
    const DLListNode<T>* after_last_node() const { return &trailer; }
    // return if the list is empty
    bool is_empty() const { return header.next == &trailer; }
    T first() const; // return the first object
    T last() const; // return the last object
    void insert_first(T obj); // insert to the first node
    T remove_first(); // remove the first node
    void insert_last(T obj); // insert to the last node
    T remove_last(); // remove the last node
    void insert_after(DLListNode<T>& p, T obj);
    void insert_before(DLListNode<T>& p, T obj);
    T remove_after(DLListNode<T>& p);
    T remove_before(DLListNode<T>& p);
    DLListNode<T>* insertOrdered(const T& obj);
};

// output operator
template<class T>
ostream& operator<<(ostream& out, const DLList<T>& dll);

// extend runtime_error from <stdexcept>
struct EmptyDLList : public std::runtime_error {
    explicit EmptyDLList(char const* msg = nullptr) : runtime_error(msg) {}
};

// copy constructor
template<class T>
DLList<T>::DLList(const DLList<T>& dll) //O(n)=n
{
    // Initialize the list
    header.next = &trailer;
    trailer.prev = &header;
    if (!dll.is_empty()) {
        DLListNode<T>* node;
        node = dll.first_node();
        while (node != dll.after_last_node()) { //O(n)=n
            insert_last(node->getElem());
            node = node->getNext();
        }
    }
}
// move constructor
template<class T>
DLList<T>::DLList(DLList<T> && dll) //O(n)=1
{
    header.next = dll.header.next;
    trailer.prev = dll.trailer.prev;

    dll.header.next->prev = &header;
    trailer.prev->next = &trailer;

    dll.header.next = &dll.trailer;
    dll.trailer.prev = &dll.header;
}

// copy assignment operator
template<class T>
DLList<T>& DLList<T>::operator=(const DLList<T>& dll) //O(n)=n
{
    while (!(this->is_empty())) {

        this->remove_last();
    }
    // Copy from dll

    header.next = &trailer;
    trailer.prev = &header;

    DLListNode<T>* newNode = dll.first_node();
    header.next = trailer.prev = new DLListNode<T>(newNode->getElem(), &header, &trailer);
    newNode = newNode->getNext();
    while (newNode != dll.after_last_node()) { //O(n)=n
        //O(n)
        insert_last(newNode->getElem());
        newNode = newNode->getNext();
    }
    return *this;
}

// move assignment operator
template<class T>
DLList<T>& DLList<T>::operator=(DLList<T>&& dll) //O(n)=n
{

    DLListNode<T>* prev_node, * node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
    // Copy from dll
    if (!dll.is_empty()) {
        node = dll.first_node();
        while (node != dll.after_last_node()) { //O(n)=n
            insert_last(node->getElem());//insert new element
            node = node->getNext();//set node to next node
        }
    }
    return *this;
}

// destructor
template<class T>
DLList<T>::~DLList<T>() //O(n)=n
{
    DLListNode<T>* prev_node, * node = header.next;
    while (node != &trailer) {
        prev_node = node;
        node = node->next;
        delete prev_node;
    }
    header.next = &trailer;
    trailer.prev = &header;
}

// insert a new object as the first one
template<class T>
void DLList<T>::insert_first(T obj) //O(n)=1
{
    DLListNode<T>* newNode = new DLListNode<T>(obj, &header, header.next);
    header.next->prev = newNode;
    header.next = newNode;
}

// insert a new object as the last one
template<class T>
void DLList<T>::insert_last(T obj) //O(n)=1
{
    DLListNode<T>* newNode = new DLListNode<T>(obj, trailer.prev, &trailer);
    trailer.prev->next = newNode;
    trailer.prev = newNode;
}

// remove the first node from the list
template<class T>
T DLList<T>::remove_first() //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    DLListNode<T>* node = header.next;
    node->next->prev = &header;
    header.next = node->next;
    T obj = node->obj;
    delete node;
    return obj;
}

// remove the last node from the list
template<class T>
T DLList<T>::remove_last() //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    DLListNode<T>* node = trailer.prev;
    node->prev->next = &trailer;
    trailer.prev = node->prev;
    T obj = node->obj;
    delete node;
    return obj;
}

// return the first object (do not remove)
template<class T>
T DLList<T>::first() const //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    return header.next->obj;
}

// return the last object (do not remove)
template<class T>
T DLList<T>::last() const //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    return trailer.prev->obj;
}

// insert a new node after the node p
template<class T>
void DLList<T>::insert_after(DLListNode<T>& p, T obj) //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    DLListNode<T>* newNode = new DLListNode<T>(obj);
    p.next->prev = newNode;
    newNode->prev = &p;
    newNode->next = p.next;
    p.next = newNode;


}

// insert a new node before the node p
template<class T>
void DLList<T>::insert_before(DLListNode<T>& p, T obj) //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    DLListNode<T>* newNode = new DLListNode<T>(obj);
    p.prev->next = newNode;
    newNode->prev = p.prev;
    newNode->next = &p;
    p.prev = newNode;
}

// remove the node after the node p
template<class T>
T DLList<T>::remove_after(DLListNode<T>& p) //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");

    DLListNode<T>* temp = p.next;
    temp->next->prev = &p;
    p.next = temp->next;
    T value = temp->obj;
    delete temp;
    return value;
}

// remove the node before the node p
template<class T>
T DLList<T>::remove_before(DLListNode<T>& p) //O(n)=1
{
    if (is_empty())
        throw EmptyDLList("Empty Doubly Linked List");
    DLListNode<T>* temp = p.prev;
    temp->prev->next = &p;
    p.prev = temp->prev;
    T value = temp->obj;
    delete temp;
    return value;
}

// output operator
template<class T>
ostream& operator<<(ostream& out, const DLList<T>& dll) //O(n)=n
{
    DLListNode<T>* temp = dll.first_node();
    while (temp != dll.after_last_node()) {//use address to compare pointers 
        out << temp->getElem() << " ";
        temp = temp->getNext();
    }
    return out;
}

template<class T>
DLListNode<T>* DLList<T>::insertOrdered(const T& obj) {
    DLListNode<T>* tmp = header.getNext();
    while (tmp != this->after_last_node()) {
        if (obj < tmp->getElem()) {
            DLListNode<T>* node = new DLListNode<T>(obj, tmp->getPrev(), tmp);
            tmp->prev->next = node;
            tmp->prev = node;
            return node;
        }
        tmp = tmp->getNext();
    }

    DLListNode<T>* node = new DLListNode<T>(obj, trailer.prev, &trailer);
    trailer.prev->next = node;
    trailer.prev = node;
    return  node;

}


#endif
