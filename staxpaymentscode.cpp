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


template <typename T>
struct Node {
    T data;
    Node<T>* prev;
    Node<T>* next;

    Node(const T& newData) : data(newData), prev(nullptr), next(nullptr) {}
};


template <typename T>
class DoubleLinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    DoubleLinkedList () : head(nullptr), tail(nullptr), size(0) {}

    ~DoubleLinkedList () {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void addNode(const T& newData) {
        Node<T>* newNode = new Node<T>(newData);
        if (head == nullptr) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void deleteNode(const T& dataToRemove) {
        Node<T>* current = head;
        while (current != nullptr) {
            if (current->data == dataToRemove) {
                if (current == head && current == tail) {
                    head = tail = nullptr;
                } else if (current == head) {
                    head = head->next;
                    head->prev = nullptr;
                } else if (current == tail) {
                    tail = tail->prev;
                    tail->next = nullptr;
                } else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                delete current;
                size--;
                return;
            }
            current = current->next;
        }
        std::cout << "Node with data " << dataToRemove << " not found in the list." << std::endl;
    }

    void displayForward() {
        Node<T>* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }

    void displayBackward() {
        Node<T>* current = tail;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->prev;
        }
        std::cout << std::endl;
    }

    int getSize() {
        return size;
    }
};

// Main function for Unit testing
int main() {
    DoubleLinkedList <int> myList;

    myList.addNode(100);
    myList.addNode(200);
    myList.addNode(300);
    myList.addNode(400);
    myList.addNode(500);


    std::cout << "List forward: ";
    myList.displayForward();

    std::cout << "List backward: ";
    myList.displayBackward();

    myList.deleteNode(300);

    std::cout << "List after removing 300: ";
    myList.displayForward();

    std::cout << "List size: " << myList.getSize() << std::endl;

    return 0;
}


