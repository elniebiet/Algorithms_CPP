#include <iostream>
#include <math.h>
using namespace std;

struct node {
    int data;
    node *next = NULL;
};
typedef struct node node_t;

node_t *insertNode(int data, node_t *headNode){
    if(headNode == NULL){
        node_t *newNode = new node_t;
        newNode->data = data;
        return newNode;
    } else {
        node_t *newNode = new node_t;
        newNode->data = data;
        newNode->next = headNode;
        return newNode;
    }
}

void printList(node_t *headNode){
    while(headNode != NULL){
        cout<<headNode->data<<" - ";
        headNode = headNode->next;
    }
}

node_t *findMiddle(node_t *headNode){
    if(headNode == NULL){
        return headNode;
    } else {
        int _size = 0;
        node_t *headCopy = headNode;
        while(headCopy != NULL){
            _size += 1;
            headCopy = headCopy->next;
        }
        cout<<_size<<endl;
        int middleElement = floor(_size/2);
        cout<<middleElement<<endl;
        int counter = 0;
        while(counter < middleElement){
            headNode = headNode->next;
            counter++;
        }
        return headNode;
    }

}

node_t *reverseListIter(node_t *headNode){
    node_t *prev1 = NULL, *prev2 = NULL;
    while(headNode != NULL){
        prev2 = prev1;
        prev1 = headNode;
        headNode = headNode->next;
        prev1->next = prev2;
    }
    return prev1;
}

void reverseListRecur(node_t *headNode, node_t **newHead){
    if(headNode->next == NULL){
        *newHead = headNode;
        return;
    }
    //if(headNode->next != NULL){
    reverseListRecur(headNode->next, newHead);
    headNode->next->next = headNode;
    headNode->next = NULL;
    //}

}

int main()
{
    node_t *headNode = NULL;
    headNode = insertNode(20, headNode);
    headNode = insertNode(21, headNode);
    headNode = insertNode(22, headNode);
    headNode = insertNode(23, headNode);
    headNode = insertNode(24, headNode);
    headNode = insertNode(25, headNode);
    headNode = insertNode(26, headNode);
    headNode = insertNode(27, headNode);
    headNode = insertNode(28, headNode);
    headNode = insertNode(29, headNode);
    headNode = insertNode(30, headNode);
    printList(headNode);
    cout<<endl;
    node_t *middleNode = findMiddle(headNode);
    cout<<middleNode->data<<endl;

    //reverse iter
    //node_t *newHead = reverseListIter(headNode);
    //printList(newHead);

    //reverse recur
    node_t **newHeadd = (node_t**)malloc(sizeof(node_t*));
    reverseListRecur(headNode, newHeadd);
    printList(*newHeadd);
    return 0;
}
