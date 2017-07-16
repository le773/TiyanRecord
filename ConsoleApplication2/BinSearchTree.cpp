#include "BinSearchTree.h"



BinSearchTree::BinSearchTree()
{
}


BinSearchTree::~BinSearchTree()
{
}


struct binary_tree {
    int data;
    struct binary_tree* left;
    struct binary_tree* right;
};

typedef struct binary_tree Node;

void insert(Node** node, int val) {
    Node* tmp = NULL;
    if (!(*node)) {
        tmp = (Node*)malloc(sizeof(Node));
        tmp->data = val;
        tmp->left = tmp->right = NULL;

        //node = &tmp;
        *node = tmp;
        return;
    }
    if ((*node)->data > val)
        insert(&(*node)->left, val);
    else if ((*node)->data < val)
    {
        insert(&(*node)->right, val);
    }
}

Node* insertNode(Node** node, int val) {
    Node* tmp = NULL;
    if (!(*node)) {
        tmp = (Node*)malloc(sizeof(Node));
        tmp->data = val;
        tmp->left = tmp->right = NULL;

        //node = &tmp; 
        *node = tmp;
        return *node;
    }

    if (val < (*node)->data) {
        (*node)->left = insertNode(&(*node)->left, val);
    }
    else if (val > (*node)->data) {
        (*node)->right = insertNode(&(*node)->right, val);
    }
    else
    {
        // duplicate
    }

    return *node; // 如果不返回，子递归的结果赋值给父类地址，最综，根节点左右子树为最后在左右子树开辟的地址

}
// 前 遍历二叉树
void ergodic(Node* root) {
    if (root == NULL)
        return;
    cout << root->data << endl;
    ergodic(root->left);
    ergodic(root->right);
}

void zhergodic(Node* root) {
    if (root == NULL)
        return;

    ergodic(root->left);
    cout << root->data << endl;
    ergodic(root->right);
}

// free tree
void deltree(Node* root) {
    if (root) {
        deltree(root->left);
        deltree(root->right);
        free(root);
    }
}

int deep(Node* node) {
    if (node == NULL)
        return 0;
    int left = deep(node->left);
    int right = deep(node->right);

    return 1 + ((left >= right) ? left : right);

}
// 最近公共祖先
Node* getLCA(Node* root, Node* node1, Node* node2) {
    if (root == NULL)
        return NULL;
    // 数值判断
    if (root->data == node1->data || root->data == node2->data) {
        return root;
    }
    /* error:
    if (root == node1  || root == node2) {
    return root;
    }
    */
    // 
    Node* left = getLCA(root->left, node1, node2);
    Node* right = getLCA(root->right, node1, node2);

    if (left != NULL && right != NULL)
        return root;
    if (left != NULL)
        return left;
    else if (right != NULL)
        return right;
    else
        return NULL;

}

int findNode(Node* node, int value) {
    if (node->data == value) {
        return 1;
    }
    else if (node->data > value)
    {
        findNode(node->right, value);
    }
    else
    {
        findNode(node->left, value);
    }
}

int findMax(Node* node) {
    if (node->right == NULL) {
        return node->data;
    }
    else
    {
        return findMax(node->right);
    }
}

int findMin(Node* node) {
    if (node->left == NULL) {
        return node->data;
    }
    else
    {
        return findMin(node->left);
    }
}

void delMin(Node** node) {
    Node* p = *node;
    if (p->left == NULL) {
        /* error:
        if (p->right == NULL) { // 
            free(p);
            p = NULL;
        }
        else {
            pNode = p->right;
            p->data = pNode->data;
            p->left = pNode->left;
            p->right = pNode->right;

            free(pNode);
            pNode = NULL;
        }
        */
        *node = (*node)->right;
        free(p);
    }
    else {
        delMin(&(*node)->left);
    }
}


void delMax(Node** node) {
    Node* p = *node;
    if (p->right == NULL) {
        *node = (*node)->left;
        free(p);
    }
    else {
        delMax(&(*node)->right);
    }
}

void delNode(Node** node, int val) {
    if (!(*node)) {
        cout << "not found" << endl;
    }
    if ((*node)->data > val) {
        delNode(&(*node)->left, val);
    }
    else if ((*node)->data < val) {
        delNode(&(*node)->right, val);
    }
    else if (
        (*node)->left != NULL &&
        (*node)->right != NULL
        ) {
        (*node)->data = findMin((*node)->right); // 当前右子树的的最小值赋给当前结点
        delMin(&(*node)->right); // 删除当前右子树的的最小结点
    }
    else {
        *node = (*node)->left != NULL ? (*node)->left : (*node)->right;
    }
}

// debug
int main_BinSearchTree() {
    cout << "hello" << endl;

    Node* root = NULL;
    int arr[11] = { 6, 5, 2, 11, 7, 3, 4, 8, 10, 1, 9};
    for (int i = 0; i < 11; i++) {
        insertNode(&root, arr[i]);
    }

    ergodic(root);
    cout << "------------" << endl;
    //zhergodic(root);

    /*Node* nodeA = new Node;
    Node* nodeB = new Node;
    nodeA->data = 6;
    nodeB->data = 8;

    Node* nodeC = getLCA(root, nodeA, nodeB);
    cout << nodeC->data << endl;*/

    int max = findMax(root);
    int min = findMin(root);
    cout << max << " " << min << endl;

    /*del max*/
    delMin(&root);
    delMax(&root);

    cout << findMax(root) << " " << findMin(root) << endl;

    delNode(&root, 7); // 删除结点
    ergodic(root);
    return -1;
}
