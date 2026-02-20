#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = NULL;
    }
};

class CircularLinkedList {
private:
    Node* head;

public:
    CircularLinkedList() {
        head = NULL;
    }

    // Insert at Beginning
    void insertAtBeginning(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            newNode->next = head;
            temp->next = newNode;
            head = newNode;
        }
    }

    // Insert at End
    void insertAtEnd(int value) {
        Node* newNode = new Node(value);

        if (head == NULL) {
            head = newNode;
            newNode->next = head;
        } else {
            Node* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = newNode;
            newNode->next = head;
        }
    }

    // Insert at Position
    void insertAtPosition(int value, int pos) {
        if (pos == 1) {
            insertAtBeginning(value);
            return;
        }

        Node* newNode = new Node(value);
        Node* temp = head;

        for (int i = 1; i < pos - 1 && temp->next != head; i++) {
            temp = temp->next;
        }

        newNode->next = temp->next;
        temp->next = newNode;
    }

    // Delete from Beginning
    void deleteFromBeginning() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* last = head;

            while (last->next != head) {
                last = last->next;
            }

            head = head->next;
            last->next = head;
            delete temp;
        }
    }

    // Delete from End
    void deleteFromEnd() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (head->next == head) {
            delete head;
            head = NULL;
        } else {
            Node* temp = head;
            Node* prev = NULL;

            while (temp->next != head) {
                prev = temp;
                temp = temp->next;
            }

            prev->next = head;
            delete temp;
        }
    }

    // Delete from Position
    void deleteFromPosition(int pos) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        if (pos == 1) {
            deleteFromBeginning();
            return;
        }

        Node* temp = head;
        Node* prev = NULL;

        for (int i = 1; i < pos && temp->next != head; i++) {
            prev = temp;
            temp = temp->next;
        }

        prev->next = temp->next;
        delete temp;
    }

    // Search
    void search(int key) {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        int position = 1;

        do {
            if (temp->data == key) {
                cout << "Element found at position " << position << endl;
                return;
            }
            temp = temp->next;
            position++;
        } while (temp != head);

        cout << "Element not found\n";
    }

    // Display
    void display() {
        if (head == NULL) {
            cout << "List is empty\n";
            return;
        }

        Node* temp = head;
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != head);

        cout << "(back to head)\n";
    }
};

int main() {
    CircularLinkedList cll;

    cll.insertAtEnd(10);
    cll.insertAtEnd(20);
    cll.insertAtEnd(30);
    cll.display();

    cll.insertAtBeginning(5);
    cll.display();

    cll.insertAtPosition(15, 3);
    cll.display();

    cll.deleteFromBeginning();
    cll.display();

    cll.deleteFromEnd();
    cll.display();

    cll.deleteFromPosition(2);
    cll.display();

    cll.search(20);

    return 0;
}