#include <iostream>
using namespace std;

struct tree {
    int data;
    tree *left = NULL;
    tree *right = NULL;
};

typedef struct tree tree_t;

tree_t *insertNode(int data, tree_t *rootNode){
    if(rootNode == NULL){
        tree_t *newNode = new tree_t;
        newNode->data = data;
        return newNode;
    } else if(data == rootNode->data){
        return rootNode;
    } else if(data < rootNode->data){
        rootNode->left = insertNode(data, rootNode->left);
        return rootNode;
    } else if(data > rootNode->data){
        rootNode->right = insertNode(data, rootNode->right);
        return rootNode;
    }
}

bool findNode(int data, tree_t *rootNode){
    if(rootNode == NULL){
        return false;
    } else if(data == rootNode->data){
        return true;
    } else if(data < rootNode->data){
        findNode(data, rootNode->left);
    } else if(data > rootNode->data){
        findNode(data, rootNode->right);
    }
}

tree_t *findMinIter(tree_t *rootNode){
    if(rootNode == NULL){
        return NULL;
    }
    while(rootNode->left != NULL){
        rootNode = rootNode->left;
    }
    //rootNode = rootNode->left;
    return rootNode;
}

tree_t *findMinRecur(tree_t *rootNode){
    if(rootNode == NULL){
        return rootNode;
    } else if(rootNode->left != NULL){
        rootNode = rootNode->left;
        findMinRecur(rootNode);
    } else {
        return rootNode;
    }
}

tree_t *findMaxIter(tree_t *rootNode){
    if(rootNode == NULL){
        return rootNode;
    } else {
        while(rootNode->right != NULL){
            rootNode = rootNode->right;
        }
        return rootNode;
    }
}

tree_t *findMaxRecur(tree_t *rootNode){
    if(rootNode == NULL){
        return rootNode;
    } else if(rootNode->right != NULL){
        rootNode = rootNode->right;
        findMaxRecur(rootNode);
    } else {
        return rootNode;
    }
}

int findHeight(tree_t *rootNode){
    if(rootNode == NULL){
        return 0;
    } else {
        int left = findHeight(rootNode->left);
        int right = findHeight(rootNode->right);
        return max(left, right) + 1;
    }
}

bool isValid(tree_t *rootNode, int prev, int next){
//print inorder and check for error
    if(rootNode == NULL){
        return true;
    } else {
        isValid(rootNode->left, prev, next);
        prev = next;
        next = rootNode->data;
        cout<<prev<<" & "<<next<<endl;
        if(prev >= next){
            return false;
        }
        //check that prev is not > next
        //cout<<rootNode->data<<" - ";
        isValid(rootNode->right, prev, next);
    }
}

tree_t *invertTree(tree_t *rootNode){
    //print post order, swap left and right
    if(rootNode == NULL){
        return rootNode;
    } else {
        invertTree(rootNode->left);
        invertTree(rootNode->right);
        tree_t *temp = rootNode->left;
        rootNode->left = rootNode->right;
        rootNode->right = temp;
    }

}

void inOrderPrint(tree_t *rootNode){
    if(rootNode == NULL){
        return;
    } else {
        inOrderPrint(rootNode->left);
        cout<<rootNode->data<<" - ";
        inOrderPrint(rootNode->right);
    }
}

int main()
{
    tree_t *rootNode =  NULL;
    rootNode = insertNode(4, rootNode);
    rootNode = insertNode(5, rootNode);
    rootNode = insertNode(3, rootNode);
    rootNode = insertNode(10, rootNode);
    rootNode = insertNode(8, rootNode);
    rootNode = insertNode(7, rootNode);
    rootNode = insertNode(2, rootNode);
    rootNode = insertNode(1, rootNode);
    rootNode = insertNode(11, rootNode);
    rootNode = insertNode(12, rootNode);
    rootNode = insertNode(13, rootNode);
    rootNode = insertNode(14, rootNode);
    rootNode = insertNode(15, rootNode);

    cout<<"findNode: "<<findNode(12, rootNode)<<endl;

    tree_t *minimum = findMinIter(rootNode);
    cout<<"minimum iter: "<<minimum->data<<endl;
    minimum = findMinRecur(rootNode);
    cout<<"minimum recur: "<<minimum->data<<endl;

    tree_t *maximum = findMaxIter(rootNode);
    cout<<"maximum iter: "<<maximum->data<<endl;
    maximum = findMaxIter(rootNode);
    cout<<"maximum recur: "<<maximum->data<<endl;

    cout<<"height: "<<findHeight(rootNode)-1<<endl;

    cout<<"is valid: "<<isValid(rootNode, 0, 0)<<endl;

    invertTree(rootNode);
    inOrderPrint(rootNode);

    return 0;
}
