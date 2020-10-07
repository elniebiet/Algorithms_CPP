//#include <iostream>
//#include <queue>
//using namespace std;

//struct node {
//    int data;
//    node *left = nullptr;
//    node *right = nullptr;
//};
//typedef struct node node_t;
//
//node_t *createNewNode(int data){
//    node_t *newNode = new node_t;
//    newNode->data = data;
//    return newNode;
//}
//
//node_t *insertNode(node_t *rootNode, int data){
//    if(rootNode == NULL){
//        rootNode = createNewNode(data);
//        return rootNode;
//    } if(data == rootNode->data){
//        return rootNode;
//    } else if(data < rootNode->data){
//        rootNode->left = insertNode(rootNode->left, data);
//        return rootNode;
//    } else {
//        rootNode->right = insertNode(rootNode->right, data);
//        return rootNode;
//    }
//}
//
//bool searchNode(node_t *rootNode, int data){
//    if(rootNode == nullptr){
//        return false;
//    } else if(data == rootNode->data){
//        return true;
//    } else if(data < rootNode->data){
//        return searchNode(rootNode->left, data);
//    } else {
//        return searchNode(rootNode->right, data);
//    }
//}
//
//node_t *findMinIter(node_t *root){
//    if(root == NULL){
//        return NULL;
//    }
//    while(root->left != NULL){
//        root = root->left;
//    }
//    return root;
//}
//
//node_t *findMaxIter(node_t *root){
//    if(root == NULL){
//        return NULL;
//    }
//    while(root->right != NULL){
//        root = root->right;
//    }
//    return root;
//}
//
//node_t *findMinRecur(node_t *root){
//    if(root->left == NULL){
//        return root;
//    }
//
//    if(root->left != NULL){
//        findMinRecur(root->left);
//    }
//}
//
//node_t *findMaxRecur(node_t *root){
//    if(root->right == NULL){
//        return root;
//    }
//
//    if(root->right != NULL){
//        findMaxRecur(root->right);
//    }
//}
//
//int findHeight(node_t *rootNode){
//    if(rootNode == NULL){
//        return -1;
//    } else {
//        int leftHeight = findHeight(rootNode->left);
//        int rightHeight = findHeight(rootNode->right);
//        return max(leftHeight, rightHeight) + 1;
//    }
//}
//
//void levelOrderTraversal(node_t *rootNode){
//
//    if(rootNode == NULL){
//        return;
//    }
//
//    queue<node_t*> children;
//    //put root element in queue
//    children.push(rootNode);
//    //while queue is not empty, get front element, print it, add its children to queue, pop it off
//    while(children.empty() == false){
//        node_t *current = children.front();
//        cout<<current->data<<" - ";
//        if(current->left != NULL){
//            children.push(current->left);
//        }
//        if(current->right != NULL){
//            children.push(current->right);
//        }
//        children.pop();
//    }
//
//}
//
//void preOrder(node_t *root){
//    if(root == NULL) {
//        return;
//    }
//    cout<<root->data<<" - ";
//    preOrder(root->left);
//    preOrder(root->right);
//}
//
//void inOrder(node_t *root){
//    if(root == NULL){
//        return;
//    }
//    inOrder(root->left);
//    cout<<root->data<<" - ";
//    inOrder(root->right);
//}
//
//void postOrder(node_t *root){
//    if(root == NULL){
//        return;
//    }
//    postOrder(root->left);
//    postOrder(root->right);
//    cout<<root->data<<" - ";
//}
//
//
//bool isSubTreeLesser(node_t *root, int data){
//    if(root == NULL)
//        return true;
//    if(root->data <= data && isSubTreeLesser(root->left, data) && isSubTreeLesser(root->right, data))
//        return true;
//    else
//        return false;
//}
//
//bool isBinarySearchTree3(node_t *rootNode, int prev, int current){
//    if(rootNode == NULL){
//        return true;
//    }
//    isBinarySearchTree3(rootNode->left, prev, current);
//    prev = current;
//    current = rootNode->data;
//    cout<<prev<<" && "<<current<<endl;
//    if(prev > current){
//        return false;
//    }
//    //cout<<rootNode->data<<" - ";
//    isBinarySearchTree3(rootNode->right, prev, current);
//}
//
//node_t *deleteNode(node_t *rootNode, int data){
//    if(rootNode == NULL){
//        return rootNode;
//    } else if(data < rootNode->data){ //keep searching
//        deleteNode(rootNode->left, data); //keep searching
//    } else if(data > rootNode->data){
//        deleteNode(rootNode->right, data);
//    } else {
//        //if root has only one child
//        if(rootNode->left == NULL && rootNode->right == NULL){
//            delete rootNode;
//            rootNode = NULL;
//            return rootNode;
//        } else if(rootNode->left == NULL){ //has only right child
//            node_t *temp = rootNode; //copy root
//            rootNode = rootNode->right;
//            delete temp;
//            return rootNode;
//        } else if(rootNode->right == NULL){ //has only left child
//            node_t *temp = rootNode;
//            rootNode = rootNode->left;
//            delete temp;
//            return rootNode;
//        } else { //has both left and right
//            node_t *minRight = findMinIter(rootNode->right); //findMin
//            rootNode->data = minRight->data; //set rootNodes data
//            rootNode->right = deleteNode(rootNode->right, minRight->data); //delete rightNode
//            return rootNode;
//        }
//    }
//}
//
//int main()
//{
//    node_t *root = NULL;
//    root = insertNode(root, 10);
//    cout<<root<<endl;
//    cout<<root->data<<endl;
//    root = insertNode(root, 8);
//    cout<<root->data<<endl;
//    root = insertNode(root, 15);
//    cout<<root->data<<endl;
//    root = insertNode(root, 9);
//    cout<<root->data<<endl;
//    cout<<searchNode(root, 10);
//    cout<<root<<endl;
//
//    node_t *minNode = findMinIter(root);
//    cout<<minNode->data<<endl;
//    node_t *maxNode = findMaxIter(root);
//    cout<<maxNode->data<<endl;
//
//    node_t *minNodeRecur = findMinRecur(root);
//    cout<<minNodeRecur->data<<endl;
//    node_t *maxNodeRecur = findMaxRecur(root);
//    cout<<maxNodeRecur->data<<endl;
//
//    cout<<findHeight(root)<<endl;
//    levelOrderTraversal(root);
//    cout<<endl;
//    preOrder(root);
//    cout<<endl;
//    inOrder(root);
//    cout<<endl;
//    postOrder(root);
//    cout<<endl;
//
//    //JUST DO INORDER TRAVERSAL AND SEE IF NUMBERS ARE SORTED
////    cout<<isBinarySearchTree(root)<<endl;
//    bool resp = isBinarySearchTree3(root, 0, 0);
//    cout<<"\n\n"<<resp<<endl;
//    inOrder(root);
//    cout<<endl;
//    deleteNode(root, 9);
//    inOrder(root);
//
//    return 0;
//}

#include <iostream>
using namespace std;

struct node {
    int data;
    node *left = nullptr;
    node *right = nullptr;
};
typedef struct node node_t;

node_t *insertNode(int data, node_t *rootNode){
    if(rootNode == nullptr){
        node_t *newNode = new node_t;
        newNode->data = data;
        return newNode;
    } else if(data == rootNode->data){
        return rootNode;
    } else if(data < rootNode->data){
        rootNode->left = insertNode(data, rootNode->left);
        return rootNode;
    } else {
        rootNode->right = insertNode(data, rootNode->right);
        return rootNode;
    }
}

bool searchNode(int data, node_t *rootNode){
    if(rootNode == nullptr){
        return false;
    } else if(data == rootNode->data){
        return true;
    } else if(data < rootNode->data){
        searchNode(data, rootNode->left);
    } else if(data > rootNode->data){
        searchNode(data, rootNode->right);
    }
}

node_t *findMinIter(node_t *rootNode){
    if(rootNode == nullptr){
        return rootNode;
    } else {
        while(rootNode->left != nullptr){
            rootNode = rootNode->left;
        }
        return rootNode;
    }
}

int findHeight(node_t *rootNode){
    if(rootNode == nullptr){
        return -1;
    } else {
        int leftHeight = findHeight(rootNode->left);
        int rightHeight = findHeight(rootNode->right);
        return max(leftHeight, rightHeight) + 1;
    }
}

node_t *findMinRecur(node_t *rootNode){
    if(rootNode->left == nullptr){
        return rootNode;
    } else if(rootNode->left != nullptr){
        findMinRecur(rootNode->left);
    }
}

void invertTree(node_t *rootNode){
    if(rootNode == NULL){
        return;
    }
    invertTree(rootNode->left);
    invertTree(rootNode->right);
    node_t *temp = rootNode->left;
    rootNode->left = rootNode->right;
    rootNode->right = temp;
}

void inOrder(node_t *rootNode){
    if(rootNode == nullptr){
        return;
    } else {
        inOrder(rootNode->left);
        cout<<rootNode->data<<" - ";
        inOrder(rootNode->right);
    }
}
int main()
{
    //create root node
    node_t *rootNode = nullptr;

    rootNode = insertNode(3, rootNode);

    rootNode = insertNode(4, rootNode);
    rootNode = insertNode(2, rootNode);
    rootNode = insertNode(1, rootNode);
    rootNode = insertNode(5, rootNode);
    rootNode = insertNode(7, rootNode);
    rootNode = insertNode(6, rootNode);
    rootNode = insertNode(9, rootNode);
    rootNode = insertNode(10, rootNode);

    cout<<searchNode(20, rootNode)<<endl;
    cout<<searchNode(2, rootNode)<<endl;

    node_t *minIter = findMinIter(rootNode);
    cout<<minIter->data<<endl;
    node_t *minRecur = findMinRecur(rootNode);
    cout<<minRecur->data<<endl;
    cout<<findHeight(rootNode)<<endl;
    //invertTree(root);
    inOrder(rootNode);
    return 0;
}
