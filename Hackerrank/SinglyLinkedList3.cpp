#include <iostream>
using namespace std;

struct node {
    int data;
    node *next = NULL;
};

typedef struct node node_t;

node_t *createNodeTop(int value, node_t *currentHead){
   // node_t *node = (node_t*) malloc (sizeof(node_t));
    node_t *node = new node_t;
    node->data = value;
    node->next = currentHead;

    return node;
}

void printList(node_t *headNode){
    while(headNode->next != nullptr){
        cout<<headNode->data<<" - ";
        headNode = headNode->next;
    }
}

void printReverse(node_t  *headNode){
    if(headNode->next != nullptr){
        printReverse(headNode->next);
        cout<<headNode->data<<" - ";
    }
}

int count10(int n){
    if(n <= 10){
        count10(n+1);
        cout<<n<<" - ";
    }
}

int findFactorial(int n){
    if(n > 1){
        return n * findFactorial(n-1);
    }
}
int main()
{
    //create head
    //node_t *headNode = (node_t*) malloc (sizeof(node_t));
    node_t *headNode = new node_t;

    //add new nodes to top
    headNode = createNodeTop(3, headNode);

    //add more
    for(int i=4; i<20; i++){
        headNode = createNodeTop(i, headNode);
    }

    printList(headNode);
    cout<<"\n\n";
    printReverse(headNode);
    cout<<"\n\n";
    count10(0);
    cout<<"\n\n";
    cout<<findFactorial(5)<<endl;
    return 0;
}
