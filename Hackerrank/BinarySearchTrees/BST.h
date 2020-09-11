#ifndef BST_H_INCLUDED
#define BST_H_INCLUDED


class BST {
    private:
        struct node {
            int key;
            node *left;
            node *right;
        };

        node * root;
    public:
        BST();
        node* creatLeaf(int key);
};



#endif // BST_H_INCLUDED
