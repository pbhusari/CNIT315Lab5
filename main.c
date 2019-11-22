#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

// Definition of Node Structure
typedef struct Node {
    char *firstName;
    char *lastName;
    int puid;
    int age;
    struct Node *next;
};

// LAB SPECIFIED: Creates a list with no nodes
struct Node *CreateListNoNodes() {
    struct Node *start;
    return start;
};

// LAB SPECIFIED: Creates a list with a single node
struct Node *CreateListNode(char *firstName, char *lastName, int age, int puid) {
    struct Node *headNode = CreateListNoNodes();
    headNode = (struct Node *) malloc(sizeof(struct Node));
    headNode->firstName = firstName;
    headNode->lastName = lastName;
    headNode->puid = puid;
    headNode->age = age;
    headNode->next = NULL;
    return headNode;
}

// Returns the length of the linked list
int size(struct Node *stackTop) {

    int len = 0;

    struct Node *tempNode = stackTop;
    while (tempNode != NULL) {
        tempNode = tempNode->next;
        len++;
    }
    return len;

}

_Bool empty(struct Node *stackTop) {
    if (stackTop == NULL) {
        return true;
    }
    else {
        return false;
    }

}

// LAB SPECIFIED: Inserts an item at the end of the linked list
struct Node *push(struct Node *stackTop, char *firstName, char *lastName, int age, int puid) {
    struct Node *newNode = CreateListNode(firstName, lastName, age, puid);
    newNode->next=stackTop;
    stackTop = newNode;
    return stackTop;
}


struct Node *pop(struct Node*topNode) {
    printf("Name: %s, %s \n", topNode->firstName, topNode->lastName);
    printf("PUID: %i \n", topNode->puid);
    printf("Age: %i \n", topNode->age);

    topNode=topNode->next;

}

// Pretty list printing
void printList(struct Node *headNode) {

    struct Node *tempNode = headNode;
    while (tempNode != NULL) {
        printf("[ %s ]-->", tempNode->firstName);
        tempNode = tempNode->next;
    }
    printf("NULL\n");
    //printf("Length of list: %i\n", FindLength(headNode));
}

// LAB SPECIFIED: Inserts an item at the end of the linked list
struct Node *enqueue(struct Node *queueFront, char *firstName, char *lastName, int age, int puid) {
    struct Node *newNode = CreateListNode(firstName, lastName, age, puid);
    newNode->next=queueFront;
    queueFront = newNode;
    return queueFront;
}

// LAB SPECIFIED: Deletes an item at the end of a linked list
struct Node *dequeue(struct Node *queueFront) {
    int deleteIndex = size(queueFront);

    struct Node *tempNode = queueFront;

    // Traverses to the end of the linked list
    for (int i = 0; i < deleteIndex - 2; i++) {
        tempNode = tempNode->next;
    }

    // Deletes the value
    tempNode->next = NULL;

    return queueFront;


}

struct Node *emptyStack(struct Node *stackTop) {
    while (!empty(stackTop)) {
        stackTop = pop(stackTop);
    }

    return stackTop;
}

struct Node *emptyQueue(struct Node *queueFront) {
    while (!empty(queueFront)) {
        queueFront = dequeue(queueFront);
    }

    return queueFront;
}


int main() {

    // LIFO
    struct Node *stackTop = CreateListNode("AAAA", "aaa", 11, 1111);
    stackTop = push(stackTop, "BBBB", "bbb", 22, 2222);
    stackTop = push(stackTop, "CCCC", "ccc", 33, 3333);
    stackTop = pop(stackTop);
    stackTop = emptyStack(stackTop);

    // FIFO
    struct Node *queueFront = CreateListNode("AAAA", "aaa", 11, 1111);
    queueFront = enqueue(queueFront, "BBBB", "bbb", 22, 2222);
    queueFront = enqueue(queueFront, "CCCC", "ccc", 33, 3333);
    queueFront = dequeue(queueFront);
    queueFront = emptyQueue(queueFront);




}