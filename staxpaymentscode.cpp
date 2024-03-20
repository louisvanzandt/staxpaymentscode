// Louis Van Zandt
// vanzandt.louis@gmail.com
// 630-279-3833
//
// Stax C++ Opportunity (Coding Assessment)
// Create a C++ program that implements a doubly linked list.
//
// To see this code run.
// You can copy and paste this code exactly as is to:
// https://www.onlinegdb.com/online_c++_compiler
//
//


#include <iostream>

// Node class definition
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int value) : data(value), next(nullptr) {}
};

// Linked list class definition
class LinkedList {
private:
    Node* head;

public:
    // Constructor
    LinkedList() : head(nullptr) {}

    // Destructor
    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Method to add a node at the end of the list
    void addNode(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Method to delete a node from the list
    void deleteNode(int value) {
        if (head == nullptr) {
            std::cout << "Empty list!\n";
            return;
        }

        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* prev = head;
        Node* curr = head->next;
        while (curr != nullptr) {
            if (curr->data == value) {
                prev->next = curr->next;
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        std::cout << "No such value!\n";
    }

    // Output list contents
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
};

int main() 
{
    LinkedList list;

    // Unit Testing #1. Adding nodes to the list
    list.addNode(100);
    list.addNode(200);
    list.addNode(300);
    list.addNode(400);
    list.addNode(500);


    // output default list
    std::cout << "Output of Unit Testing #1 Adding nodes to the list-> ";
    list.display();

    //  Unit Testing #2. Delete a note
    list.deleteNode(300);


    std::cout << "Output of Unit Testing #2 Deleting a node from the list-> ";
    list.display();

    //  Unit Testing #3. Adding a node to the list
    list.addNode(600);

    std::cout << "Output of Unit Testing #3 Adding a node to the list-> ";
    list.display();


    return 0;
}
