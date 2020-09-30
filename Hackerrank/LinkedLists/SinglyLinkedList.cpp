#include <iostream>
#include <vector>
using namespace std;

struct node {
    int data;
    node *next = NULL;
};
typedef struct node node_t;

node_t *insertTop(int data, node_t *headNode){
    node_t *newNode = new node_t;
    newNode->data = data;
    newNode->next = headNode;

    return newNode; //return the new head
}

void printNodes(node_t *headNode){
    while(headNode != NULL){
        cout<<headNode->data<<" - ";
        headNode = headNode->next;
    }
}

node_t *insertNthPosition(int data, int position, node_t *headNode){
    int counter = 1;
    while(headNode->next != NULL){
        if(counter == position){
            node_t *newNode = new node_t;
            newNode->data = data;
            newNode->next = headNode->next;
            headNode->next = newNode;
            return newNode;
        }
        headNode = headNode->next;
        counter++;
    }

    return NULL;
}

node_t *insertBottom(int data, node_t *headNode){
    while(headNode != NULL){
        if(headNode->next == NULL){
            node_t *newNode = new node_t;
            newNode->data = data;
            headNode->next = newNode;
            return newNode;
        }
        headNode = headNode->next;
    }
}

void deleteTail(node_t *headNode){
    while(headNode != NULL){
        if(headNode->next->next == NULL){
            node_t *temp = headNode->next;
            headNode->next = NULL;
            delete(temp);
            return;
        }
        headNode = headNode->next;
    }
}
node_t *deleteHead(node_t *headNode){
    node_t *temp = headNode;
    headNode = headNode->next;
    delete(temp);
    return headNode;
}

void deleteNthPosition(int position, node_t *headNode){
    int counter = 1;
    while(headNode->next != NULL){
        if(counter == position){
            node_t *temp = headNode->next;
            headNode->next = headNode->next->next;
            delete(temp);
        }
        headNode = headNode->next;
        counter++;
    }
}
bool findNode(int data, node_t *headNode){
    while(headNode != NULL){
        if(headNode->data == data){
            return true;
        }

        headNode = headNode->next;
    }

    return false;
}

void printReverse(node_t *headNode){
    if(headNode == nullptr){
        return;
    }
    printReverse(headNode->next);
    cout<<headNode->data<<" - ";
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

void reverseListRecur(node_t *headNode, node_t** newHead){
    if(headNode->next == nullptr){
        *newHead = headNode;
        return;
    }
    reverseListRecur(headNode->next, newHead);
    headNode->next->next = headNode;
    headNode->next = nullptr;
}

int main()
{
    //create head Node
    node_t *headNode = NULL;

    //insert top
    headNode = insertTop(5, headNode);
    //add more nodes
    for(int i=6; i<=15; i++){
        headNode = insertTop(i, headNode);
    }
    printNodes(headNode);
    cout<<"\n";

    //insert Nth position
    node_t *newNode = insertNthPosition(6, 10, headNode);
    printNodes(headNode);
    cout<<"\n";

    //insert at tail
    newNode = insertBottom(100, headNode);
    printNodes(headNode);
    cout<<"\n";

    //find Node
    bool found = findNode(6, headNode);
    cout<<found;
    cout<<"\n";

    //delete head
    headNode = deleteHead(headNode);
    printNodes(headNode);
    cout<<"\n";

    //deletet nth position
    deleteNthPosition(5, headNode);
    printNodes(headNode);
    cout<<"\n";

    //delete tail
    deleteTail(headNode);
    printNodes(headNode);
    cout<<"\n";

    //print reverse recursively
    printReverse(headNode);
    cout<<"\n";

    //reverse list iteratively
    cout<<"reversing iteratively"<<endl;
    headNode = reverseListIter(headNode);
    printNodes(headNode);
    cout<<"\n";

    //reverse list recursively
    cout<<"reversing recursively"<<endl;
    node_t **newHead = (node_t**)malloc(sizeof(node_t*));
    reverseListRecur(headNode, newHead);
    printNodes(*newHead);

    return 0;
}
