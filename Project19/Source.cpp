#include <iostream>
using namespace std;

class Node {
public:

    string data;
    Node* next;
    Node(const string& data) : data(data), next(nullptr) {}

};

class SinglyList {
    Node* head = nullptr;
public:

    void AddFront(const string& value) {
        Node* newNode = new Node(value);
        newNode->next = head;
        head = newNode;
    }

    void AddEnd(const string& value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr)
            temp = temp->next;
        temp->next = newNode;
        temp = nullptr;
    }

    void DeleteFront() {
        if (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void DeleteEnd() {
        if (head != nullptr) {
            Node* temp = head;
            while (temp->next->next != nullptr) {
                temp = temp->next;
            }
            delete temp->next;
            temp->next = nullptr;
        }
    }

    void AddElementBefore(const string& x, const string& value) {
        Node* newNode = new Node(value);
        Node* currentNode = new Node(x);
        Node* temp = head;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        while (temp->next != currentNode->next)
            temp = temp->next;
        temp->next = newNode;
        temp = nullptr;
    }

    void AddElementAfter(const string& x, const string& value) {
        Node* newNode = new Node(value);
        Node* currentNode = new Node(x);
        Node* temp = head;
        if (head == nullptr) {
            head = newNode;
            return;
        }
        while (temp->next != currentNode->next)
            temp = temp->next;
        newNode = temp;
        temp = nullptr;
    }

    void DeleteByValue(const string& value) {
        Node* node = new Node(value);
        Node* temp = head;
        while (temp->next == node)
            temp = temp->next;
        delete temp;
    }

    void Print() {
        Node* temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};

void main() {

    SinglyList sl;       
    sl.AddFront("A");
    sl.AddFront("B"); 
    sl.AddEnd("C"); 
    sl.AddEnd("D"); 
    sl.AddElementBefore("B", "E");
    sl.AddElementAfter("D", "F");
    sl.Print();           

}
