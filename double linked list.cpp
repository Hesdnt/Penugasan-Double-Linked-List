#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *prev;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

Node* createNode(int data) {
    Node *baru = new Node();
    baru->data = data;
    baru->prev = NULL;
    baru->next = NULL;
    return baru;
}

void insertFirst(int data) {
    Node *baru = createNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
}

void insertLast(int data) {
    Node *baru = createNode(data);

    if (head == NULL) {
        head = tail = baru;
    } else {
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
}

void insertNext(int after, int data) {
    Node *temp = head;

    while (temp != NULL && temp->data != after) {
        temp = temp->next;
    }

    if (temp == NULL) {
        cout << "Node tidak ditemukan!\n";
        return;
    }

    Node *baru = createNode(data);

    baru->next = temp->next;
    baru->prev = temp;

    if (temp->next != NULL) {
        temp->next->prev = baru;
    } else {
        tail = baru;
    }

    temp->next = baru;
}

void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node *hapus = head;

    if (head == tail) {
        head = tail = NULL;
    } else {
        head = head->next;
        head->prev = NULL;
    }

    delete hapus;
}

void deleteLast() {
    if (tail == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node *hapus = tail;

    if (head == tail) {
        head = tail = NULL;
    } else {
        tail = tail->prev;
        tail->next = NULL;
    }

    delete hapus;
}

void display() {
    Node *temp = head;
    cout << "Isi Linked List: ";
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

int main() {
    insertFirst(10);
    insertFirst(5);
    insertLast(20);
    insertLast(25);

    display();

    insertNext(10, 15);
    display();

    deleteFirst();
    display();

    deleteLast();
    display();

    return 0;
}
