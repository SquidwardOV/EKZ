#include <iostream>

struct Node {
    int data;
    Node* next;

    Node(int d) : data(d), next(nullptr) {}
};

void insert(Node*& head, int data) {
    if (head == nullptr) {
        head = new Node(data);
    }
    else {
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = new Node(data);
    }
}

void printList(const Node* head) {
    const Node* current = head;
    while (current != nullptr) {
        std::cout << current->data << " ";
        current = current->next;
    }
    std::cout << std::endl;
}

void doubleOccurrences(Node*& head, int E) {
    Node* current = head;
    while (current != nullptr) {
        if (current->data == E) {
            Node* newNode = new Node(E);
            newNode->next = current->next;
            current->next = newNode;
            current = newNode->next;
        }
        else {
            current = current->next;
        }
    }
}

void clearList(Node*& head) {
    while (head != nullptr) {
        Node* current = head;
        head = head->next;
        delete current;
    }
}

int main() {
    Node* head = nullptr;

    // Задаем исходный список L
    insert(head, 1);
    insert(head, 2);
    insert(head, 3);
    insert(head, 4);
    insert(head, 1);
    insert(head, 2);
    insert(head, 1);

    // Выводим исходный список
    std::cout << "Исходный список: ";
    printList(head);

    // Задаем элемент, который нужно удвоить
    int E = 1;

    // Удваиваем каждое вхождение элемента E
    doubleOccurrences(head, E);

    // Выводим обновленный список
    std::cout << "Обновленный список: ";
    printList(head);

    // Очищаем список
    clearList(head);

    return 0;
}
