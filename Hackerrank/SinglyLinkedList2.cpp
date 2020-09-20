#include <iostream>
using namespace std;

struct node  {
    int data;
    node *next = NULL;
};

typedef struct node node_t;

node_t *createNodeTop(int data, node_t *headNode){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = headNode;
    return newNode; //new headNode
}

void printFromTop(node_t *headNode){
    while(headNode->next != nullptr){
        cout<<headNode->data<<" - ";
        headNode = headNode->next;
    }
    cout<<"\n\n";
}

void printReverse(node_t *headNode){

    if(headNode->next != NULL){
        printReverse(headNode->next);
        cout<<headNode->data<<" - ";
    }
}

node_t *findNodeWithValue(int data, node_t *headNode){
    //traverse the list from head
    while(headNode->next != nullptr){
        if(headNode->data == data){
            return headNode;
        }
        headNode = headNode->next;
    }

    return nullptr;
}

node_t *createNodeBottom(int data, node_t *tailNode){
    node_t *newTail = (node_t*)malloc(sizeof(node_t));
    tailNode->data = data;
    tailNode->next = newTail;
    return tailNode->next;

}

node_t *createNodeAfter(int data, node_t *nodeBefore){
    node_t *newNode = (node_t*)malloc(sizeof(node_t));
    newNode->data = data;
    newNode->next = nodeBefore->next;
    nodeBefore->next = newNode;

    return newNode;
}

node_t *deleteFromTop(node_t *headNode){
    node_t *nextHead = (node_t*)malloc(sizeof(node_t));
    nextHead = headNode->next;
    free(headNode);
    return nextHead;
}


void deleteAfter(node_t *nodeBefore){
    node_t *nodeToDelete = (node_t*)malloc(sizeof(node_t));
    nodeToDelete = nodeBefore->next;
    nodeBefore->next = nodeBefore->next->next;
    free(nodeToDelete);
}

node_t *reverseList(node_t *headNode){
    node_t *headCopy = headNode;

    //save head data
    int data = headCopy->data;

    node_t *prev1 = nullptr, *prev2 = nullptr;

    while(headNode->next != NULL){
        prev2 = prev1;
        prev1 = headNode;
        headNode = headNode->next;
        prev1->next = prev2;
    }
    node_t *nn = new node_t;
    nn->data = data;

    headCopy->next = nn;
    return prev1; //new head
}

node_t *reverseRecursive(node_t *headNode){
    if(headNode->next != NULL){
        printReverse(headNode->next);
        headNode->next->next = headNode;
        //headNode->next = nullptr;
    }
    //else {
        node_t *nn = new node_t;
        headNode->next = nn;
        return headNode;
    //}
}

int main()
{
    //create head Node
    node_t *headNode = (node_t*)malloc(sizeof(node_t));
    node_t *tailNode = headNode; //save tail

    //add node to top
    headNode = createNodeTop(2, headNode);

    for(int i=0; i<20; i++){
        headNode = createNodeTop(i, headNode);
    }
    printFromTop(headNode);

    printReverse(headNode);
    cout<<"\n\n";

    //find node with value
    node_t *node = findNodeWithValue(19, headNode);
    if(node == nullptr){
        cout<<"not found"<<endl;
    } else {
        cout<<"found "<<node->data<<endl;
    }
    cout<<"\n\n";
    //add node to tail
    tailNode = createNodeBottom(100, tailNode); //new tail
    printFromTop(headNode);
    cout<<"\n\n";
    //add node after
    node_t *newNode = createNodeAfter(200, node);
    printFromTop(headNode);
    cout<<"\n\n";
    //delete from top
    headNode = deleteFromTop(headNode);
    printFromTop(headNode);
    cout<<"\n\n";


    //delete after
//    cout<<"deleting after..."<<endl;
//    deleteAfter(findNodeWithValue(14, headNode));
//    printFromTop(headNode);

    //delete tail: to delete tail, not very efficient, but we can get the node before the tail
    //otherwise we will need the previous node before the tail
//    cout<<"\n\n";

    //Reverse linkedList
//    tailNode = headNode; //new tail
//    headNode = reverseList(headNode);
//    printFromTop(headNode);

    cout<<"Reversing recursive "<<endl;
    headNode = reverseRecursive(headNode);
    // tailNode->next = nullptr;
   // headNode->next
    printFromTop(tailNode);
    cout<<" "<<tailNode->next<<endl;
    int hello;
    cin>>hello;

    return 0;
}
