#include<iostream>
using namespace std;

struct Node {
    int data; // each node holds an integer data
    Node* previous; // pointer to the previous node
    Node* next; // pointer to the next node
    Node(int d = 0, Node* prv = NULL, Node* nxt = NULL) : data(d), previous(prv), next(nxt) {}
    Node* get_previous() const { return previous; }
    Node* get_next() const { return next; }
    Node* insert_before(int d); // insert the int before this node
                               // return a pointer to the inserted node
    Node* insert_after(int d); // insert the int after this node
                              // return a pointer to the inserted node
    void delete_before(); // delete the node before this node
    void delete_after(); // delete the node after this node
};

Node* Node::insert_before(int d) {
    Node* newNode = new Node(d);
    newNode->next = this;
    newNode->previous = this->previous;
    this->previous->next = newNode;
    this->previous = newNode;
    return newNode;
}
Node* Node::insert_after(int d) {
    Node* newNode = new Node(d);
    newNode->previous = this;
    newNode->next = this->next;
    this->next->previous = newNode;
    this->next = newNode;
    return newNode;
}

// delete the node before this node
void Node::delete_before()
{
    Node* newNode = previous;
    this->previous = newNode->previous;
    this->previous->next = this;
    delete newNode;

}

// delete the node after this node
void Node::delete_after()
{
    Node* newNode = next;
    this->next = newNode->next;
    this->next->previous = this;
    delete newNode;
}

// Display a doubly linked list
void display_list(Node* header, Node* trailer) {
    Node* p = header->get_next();

    while (p != trailer) {
        cout << p->data << ", ";
        p = p->get_next();
    }
    cout << endl;
}

// Test program
int main() {
    // Construct a doubly linked list with a header & trailer
    cout << "Create a new list" << endl;
    Node* header = new Node(-1);
    Node* trailer = new Node(-2);
    trailer->previous = header;
    header->next = trailer;
    cout << "list: ";
    display_list(header, trailer);
    cout << endl;

    // Insert 10 nodes with values 10,20,30,..,100
    cout << "Insert 10 nodes with values 10,20,30,..,100" << endl;
    for (int i = 10; i <= 100; i += 10) {
        trailer->insert_before(i);
    }
    cout << "list: ";
    display_list(header, trailer);
    cout << endl;

    // Insert 10 nodes at front with value 100,90,80,..,10
    cout << "Insert 10 nodes at front with value 100,90,80,..,10" << endl;
    for (int i = 10; i <= 100; i += 10) {
        header->insert_after(i);
    }
    cout << "list: ";
    display_list(header, trailer);
    cout << endl;

    // Delete the last 5 nodes
    cout << "Delete the last 5 nodes" << endl;
    for (int i = 0; i < 5; i++) {
        trailer->delete_before();
    }
    cout << "list: ";
    display_list(header, trailer);
    cout << endl;

    // Delete the first 5 nodes
    cout << "Delete the first 5 nodes" << endl;
    for (int i = 0; i < 5; i++) {
        header->delete_after();
    }
    cout << "list: ";
    display_list(header, trailer);

    return 0;
}