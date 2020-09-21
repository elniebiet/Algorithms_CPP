#include <iostream>
#include <queue>
using namespace std;

struct node {
    int data;
    node *left = nullptr;
    node *right = nullptr;
};
typedef struct node node_t;

node_t *createNewNode(int data){
    node_t *newNode = new node_t;
    newNode->data = data;
    return newNode;
}

node_t *insertNode(node_t *rootNode, int data){
    if(rootNode == NULL){
        rootNode = createNewNode(data);
        return rootNode;
    } if(data == rootNode->data){
        return rootNode;
    } else if(data < rootNode->data){
        rootNode->left = insertNode(rootNode->left, data);
        return rootNode;
    } else {
        rootNode->right = insertNode(rootNode->right, data);
        return rootNode;
    }
}

bool searchNode(node_t *rootNode, int data){
    if(rootNode == nullptr){
        return false;
    } else if(data == rootNode->data){
        return true;
    } else if(data < rootNode->data){
        return searchNode(rootNode->left, data);
    } else {
        return searchNode(rootNode->right, data);
    }
}

node_t *findMinIter(node_t *root){
    if(root == NULL){
        return NULL;
    }
    while(root->left != NULL){
        root = root->left;
    }
    return root;
}

node_t *findMaxIter(node_t *root){
    if(root == NULL){
        return NULL;
    }
    while(root->right != NULL){
        root = root->right;
    }
    return root;
}

node_t *findMinRecur(node_t *root){
    if(root->left == NULL){
        return root;
    }

    if(root->left != NULL){
        findMinRecur(root->left);
    }
}

node_t *findMaxRecur(node_t *root){
    if(root->right == NULL){
        return root;
    }

    if(root->right != NULL){
        findMaxRecur(root->right);
    }
}

int findHeight(node_t *rootNode){
    if(rootNode == NULL){
        return -1;
    } else {
        int leftHeight = findHeight(rootNode->left);
        int rightHeight = findHeight(rootNode->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

void levelOrderTraversal(node_t *rootNode){

    if(rootNode == NULL){
        return;
    }

    queue<node_t*> children;
    //put root element in queue
    children.push(rootNode);
    //while queue is not empty, get front element, print it, add its children to queue, pop it off
    while(children.empty() == false){
        node_t *current = children.front();
        cout<<current->data<<" - ";
        if(current->left != NULL){
            children.push(current->left);
        }
        if(current->right != NULL){
            children.push(current->right);
        }
        children.pop();
    }

}

void preOrder(node_t *root){
    if(root == NULL) {
        return;
    }
    cout<<root->data<<" - ";
    preOrder(root->left);
    preOrder(root->right);
}

void inOrder(node_t *root){
    if(root == NULL){
        return;
    }
    inOrder(root->left);
    cout<<root->data<<" - ";
    inOrder(root->right);
}

void postOrder(node_t *root){
    if(root == NULL){
        return;
    }
    postOrder(root->left);
    postOrder(root->right);
    cout<<root->data<<" - ";
}

bool isSubTreeLesser(node_t *root, int data){
    if(root == NULL)
        return true;
    if(root->data <= data && isSubTreeLesser(root->left, data) && isSubTreeLesser(root->right, data))
        return true;
    else
        return false;
}

bool isSubTreeGreater(node_t *root, int data){
    if(root == NULL)
        return true;
    if(root->data > data && isSubTreeGreater(root->left, data) && isSubTreeGreater(root->right, data))
        return true;
    else
        return false;
}

bool isBinarySearchTree(node_t *root){
    if(root == NULL){
        return true;
    }
    if(isSubTreeLesser(root->left, root->data) && isSubTreeGreater(root->right, root->data)
    && isBinarySearchTree(root->left) && isBinarySearchTree(root->right)){
        return true;
    } else {
        return false;
    }
}

bool isBinarySearchTree2(node_t *root, int minValue, int maxValue){
    if(root == NULL){
        return true;
    }
    if(root->data < minValue && root->data > maxValue
    && isBinarySearchTree2(root->left, minValue, root->data)
    && isBinarySearchTree2(root->right, root->data, maxValue)){
        return true;
    } else return false;
}


int main()
{
    node_t *root = NULL;
    root = insertNode(root, 10);
    cout<<root<<endl;
    cout<<root->data<<endl;
    root = insertNode(root, 8);
    cout<<root->data<<endl;
    root = insertNode(root, 15);
    cout<<root->data<<endl;
    root = insertNode(root, 9);
    cout<<root->data<<endl;
    cout<<searchNode(root, 10);
    cout<<root<<endl;

    node_t *minNode = findMinIter(root);
    cout<<minNode->data<<endl;
    node_t *maxNode = findMaxIter(root);
    cout<<maxNode->data<<endl;

    node_t *minNodeRecur = findMinRecur(root);
    cout<<minNodeRecur->data<<endl;
    node_t *maxNodeRecur = findMaxRecur(root);
    cout<<maxNodeRecur->data<<endl;

    cout<<findHeight(root)<<endl;
    levelOrderTraversal(root);
    cout<<endl;
    preOrder(root);
    cout<<endl;
    inOrder(root);
    cout<<endl;
    postOrder(root);
    cout<<endl;
    //JUST DO INORDER TRAVERSAL AND SEE IF NUMBERS ARE SEQUENTIAL
    cout<<isBinarySearchTree(root)<<endl;
    cout<<isBinarySearchTree2(root, 8, 14)<<endl;

    return 0;
}
