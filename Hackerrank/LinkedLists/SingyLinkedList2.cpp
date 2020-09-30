#include <iostream>
using namespace std;

struct node {
    int data;
    node *next = NULL;
};
typedef struct node node_t;

node_t *createNodeTop(int data, node_t *headNode){
    if(headNode == NULL){
        node_t *newNode = new node_t;
        newNode->data = data;
        return newNode;
    }

    node_t *newNode = new node_t;
    newNode->data = data;
    newNode->next = headNode;
    return newNode;
}

void printNodes(node_t *headNode){
    while(headNode != NULL){
        cout<< headNode->data << " - ";
        headNode = headNode->next;
    }
}

node_t *createNodeNPos(int data, int n, node_t *headNode){
    int i = 0;
    while(headNode != NULL){
        if(i == n){
            node_t *temp = headNode->next;
            node_t *newNode = new node_t;
            newNode->data = data;
            newNode->next = temp;
            headNode->next = newNode;
            return newNode;
        }
        i++;
    }

}
void printReverse(node_t *headNode){
    if(headNode == NULL){
        return;
    }
    if(headNode != NULL){
       printReverse(headNode->next);
       cout<<headNode->data<<" - ";
    }
}

node_t *reverseListIter(node_t *headNode){
    node_t *prev1 = nullptr, *prev2 = nullptr;
    while(headNode != nullptr){
        prev2 = prev1;
        prev1 = headNode;
        headNode = headNode->next;
        prev1->next = prev2;
    }
    return prev2;
}

void reverseListRecur(node_t *headNode, node_t **headNodePtr){

   if(headNode->next == nullptr){
        *headNodePtr = headNode;
        return;
    }
    reverseListRecur(headNode->next, headNodePtr);
    headNode->next->next = headNode;
    headNode->next = nullptr;
}



int main()
{
    node_t *headNode = NULL;
    headNode = createNodeTop(3, headNode);
    printNodes(headNode);
    cout<<endl;
    for(int i=4; i<10; i++){
        headNode = createNodeTop(i, headNode);
    }
    printNodes(headNode);
    cout<<endl;
    printReverse(headNode);
    cout<<endl;
    node_t *newNode = createNodeNPos(5, 5, headNode);
    printNodes(headNode);
    cout<<"\n";
    headNode = reverseListIter(headNode);
    printNodes(headNode);
    cout<<endl;
    node_t** headNodePtr = (node_t**) malloc(sizeof(node_t*));
    reverseListRecur(headNode, headNodePtr);
//    headNode = *headNodePtr;
    printNodes(*headNodePtr);
    return 0;
}
