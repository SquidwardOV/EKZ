#include <iostream>

struct Node {
    int elem;
    Node* next;
};

Node* createList(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;

    for (int i = 0; i < size; i++) {
        Node* newNode = new Node;
        newNode->elem = arr[i];
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    return head;
}

void insertBefore(Node*& head, int target, int newValue) {
    Node* current = head;
    Node* previous = nullptr;

    while (current != nullptr) {
        if (current->elem == target) {
            Node* newNode = new Node;
            newNode->elem = newValue;

            if (previous == nullptr) {
                newNode->next = head;
                head = newNode;
            } else {
                newNode->next = current;
                previous->next = newNode;
            }
        }

        previous = current;
        current = current->next;
    }
}

void printList(Node* head) {
    Node* current = head;

    while (current != nullptr) {
        std::cout << current->elem << " ";
        current = current->next;
    }

    std::cout << std::endl;
}

int main() {
    // Создание списка
    int arr[] = {1, 2, 3, 2, 4, 2, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createList(arr, size);

    // Вставка нового элемента перед каждым вхождением элемента E
    int target = 2;
    int newValue = 6;
    insertBefore(head, target, newValue);

    // Вывод списка
    printList(head);

    return 0;
}
