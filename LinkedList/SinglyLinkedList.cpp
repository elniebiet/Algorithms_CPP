#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


struct node {
    int value;
    node *next = NULL;
};

typedef struct node node_t;

void printNodes(node_t *headNode){
    node_t *temp = headNode;

    while(temp->next != NULL){
        cout<<temp->value<<" - ";
        temp = temp->next;
    }
//    cout<<temp->value<<" - "; //print last value
}

void printNodes(node_t *startNode, node_t *endNode){
    if(startNode->next != endNode->next){
        cout<<startNode->value<<" - ";
        printNodes(startNode->next, endNode);
    }
}

node_t *createNodeTop(int value, node_t *headNode){
    node_t *node = (node_t*) malloc(sizeof(node_t));
    node->value = value;
    node->next = headNode;
    return node; //return the new head
}

node_t *createNodeAfter(int value, node_t *nodeAfter){
    node_t *node = (node_t*)malloc(sizeof(node_t));
    node->value = value;
    node->next = nodeAfter->next;
    nodeAfter->next = node;

    return node;
}

node_t *findNodeWithValue(int value, node_t *headNode){
    while(headNode->next != NULL){
        if(headNode->value == value){
            return headNode;
        }
        headNode = headNode->next;
    }
    //check last value
    if(headNode->value == value)
        return headNode;

    //not found return empty node
    node_t *emptyNode = (node_t*)malloc(sizeof(node_t));
    emptyNode->value = NULL;
    emptyNode->next = NULL;

    return emptyNode;
}

node_t *findNode(node_t *headNode, node_t *nodeToFind){
    while(headNode->next != NULL){
        if(headNode->next == nodeToFind->next){
            cout<<"found Node"<<endl;
            return nodeToFind;
        }
        headNode = headNode->next;
    }
    cout<<"couldnt find node"<<endl;
    node_t *emptyNode = (node_t*)malloc(sizeof(node_t));
    emptyNode->value = NULL;
    emptyNode->next = NULL;

    return emptyNode;

}

node_t *createNodeBottom(int value, node_t *tailNode){ //return new tail
    node_t *newTail = (node_t*)malloc(sizeof(node_t));
    tailNode->value = value;
    tailNode->next = newTail;

    return newTail;
}

void printBackwards(node_t *head){
    if(head->next != NULL){
        // print the list after head node
        printBackwards(head->next);
        // After everything else is printed, print head
        cout << head->value << " - ";
    }

}

void printBackWards(node_t *startNode, node_t *stopNode){
    if(startNode->next != stopNode->next){
        printBackWards(startNode->next, stopNode);
        cout<<startNode->value<<" - ";
    }
}

node_t *deleteHead(node_t *headNode){
    headNode = headNode->next;
    return headNode; //return new head
}

void deleteNodeAfter(node_t *nodeBefore){
    cout<<"deleting node... "<<endl;
    nodeBefore->next = nodeBefore->next->next;
}
int main()
{
    node_t node1, node2, node3;
    node_t *headNode = (node_t*) malloc(sizeof(node_t));
    node_t *tailNode = headNode;
    //insert on top
    for(int i=50; i<=70; i++){
        node_t *newNode = createNodeTop(i, headNode);
        headNode = newNode;
    }
    cout<<"Adding nodes to top..."<<endl;
    printNodes(headNode);

    //find node with value
    cout<<"\n\nfinding value ..."<< endl;
    node_t *result = findNodeWithValue(62, headNode);
    if(result->next != NULL){
        cout<<result->value<<endl;
    } else {
        cout<<"not found!";
    }

    //find node
    cout<<"\nfinding node..."<<endl;
    findNode(headNode, findNodeWithValue(620, headNode));

    //insert after
    if(result != NULL){
        node_t *newNode = createNodeAfter(1000, result);
        cout<<"\nCreating node after..."<<endl;
        printNodes(headNode);
    }

    cout<<"\n\n"<<"Adding to tail..."<<endl;
    //insert at tail
    tailNode = createNodeBottom(3, tailNode); //returns new tail
    printNodes(headNode);

    //insert more at tail
    cout<<"\n\nAdding more to tail..."<<endl;
    for(int i=1; i<20; i++){
        tailNode = createNodeBottom(i, tailNode);
    }
    printNodes(headNode);

    //print backwards
    cout<<"\n\nPrinting backwards..."<<endl;
    printBackwards(headNode);

    cout<<"\n\nPrinting backwards..."<<endl;
    printBackWards(findNodeWithValue(12, headNode), findNodeWithValue(19, headNode));

    cout<<"\n\nPrinting backwards..."<<endl;
    printNodes(findNodeWithValue(12, headNode), findNodeWithValue(19, headNode));

    cout<<"\n\nDeleting head..."<<endl;
    headNode = deleteHead(headNode);
    printNodes(headNode);

    cout<<"\n\ndeleting node after..."<<endl;
    deleteNodeAfter(findNode(headNode, findNodeWithValue(65, headNode)));
    printNodes(headNode);

    return 0;
}
