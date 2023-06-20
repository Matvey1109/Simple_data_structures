#include <iostream>
#include <vector>

class AVLtree{
private:
    struct Node{
        int data;
        int height;
        Node* left;
        Node* right;

        Node(int data) : data(data), height(1), left(nullptr), right(nullptr) {}
    };
    Node* root;

    int height(Node* node){
        if (node == nullptr){
            return 0;
        }
        return node->height;
    }

    int max(int a, int b){
        return (a > b) ? a : b;
    }

    int getBalance(Node* node){
        if (node == nullptr){
            return 0;
        }
        return height(node->left) - height(node->right);
    }

    Node* leftRotate(Node* x){
        Node* y = x->right;
        Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->left)) + 1;
        y->height = max(height(y->left), height(y->left)) + 1;

        return y;
    }

    Node* rightRotate(Node* y){
        Node* x = y->left;
        Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return x;
    }

    Node* insert(Node* node, int data){
        if (node == nullptr){
            return new Node(data);
        }

        if (data < node->data){
            node->left = insert(node->left, data);
        } else if (data > node->data){
            node->right = insert(node->right, data);
        } else {
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);
        if (balance < -1 && data > node->right->data){
            return leftRotate(node);
        }
        if (balance > 1 && data < node->left->data){
            return rightRotate(node);
        }
        if (balance > 1 && data > node->left->data){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && data < node->right->data){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    Node* remove(Node* node, int data){
        if (node == nullptr){
            return node;
        }

        if (data < node->data){
            node->left = remove(node->left, data);
        } else if (data > node->data){
            node->right = remove(node->right, data);
        } else {
            if (node->left == nullptr || node->right == nullptr){
                Node* temp = node->left ? node->left : node->right;
                if (temp == nullptr){
                    temp = node;
                    node = nullptr;
                } else {
                    *node = *temp;
                }
                delete temp;
            } else {
                Node* temp = node->right;
                while (temp->left != nullptr){
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        if (node == nullptr){
            return node;
        }

        node->height = max(height(node->left), height(node->right)) + 1;

        int balance = getBalance(node);
        if (balance > 1 && getBalance(node->left) >= 0){
            return rightRotate(node);
        }
        if (balance > 1 && getBalance(node->left) < 0){
            node->left = leftRotate(node->left);
            return rightRotate(node);
        }
        if (balance < -1 && getBalance(node->right) <= 0){
            return leftRotate(node);
        }
        if (balance < -1 && getBalance(node->right) > 0){
            node->right = rightRotate(node->right);
            return leftRotate(node);
        }

        return node;
    }

    bool find(Node* node, int data){
        if (node == nullptr){
            return false;
        }

        if (data < node->data){
            return find(node->left, data);
        } else if (data > node->data){
            return find(node->right, data);
        } else {
            return true;
        }
    }

    void preorder(Node* node){
        if (node == nullptr){
            return;
        }

        std::cout << node->data << ' ';
        preorder(node->left);
        preorder(node->right);
    }

public:
    AVLtree() : root(nullptr) {}

    void print(){
        preorder(root);
        std::cout << std::endl;
    }

    void insert(int value){
        root = insert(root, value);
    }

    void remove(int value){
        root = remove(root, value);
    }

    void find(int value){
        if (find(root, value)){
            std::cout << "YES";
        } else{
            std::cout << "NO";
        }
        std::cout << std::endl;
    }
};


class BinaryTree{
private:
    struct Node{
        int data;
        Node* left;
        Node* right;

        Node(int data) : data(data), left(nullptr), right(nullptr) {}
    };

    Node* root;

    Node* insert(Node* node, int data){
        if (node == nullptr){
            return new Node(data);
        }

        if (data < node->data){
            node->left = insert(node->left, data);
        } else if (data > node->data){
            node->right = insert(node->right, data);
        } else {
            return node;
        }

        return node;
    }

    Node* remove(Node* node, int data){
        if (node == nullptr){
            return nullptr;
        }

        if (data < node->data){
            node->left = remove(node->left, data);
        } else if (data > node->data){
            node->right = remove(node->right, data);
        } else {
            if (node->left == nullptr && node->right == nullptr){
                delete node;
                return nullptr;
            } else if (node->left == nullptr) {
                Node* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (node->right == nullptr) {
                Node* leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                Node* temp = node->right;
                while (temp->left != nullptr){
                    temp = temp->left;
                }
                node->data = temp->data;
                node->right = remove(node->right, temp->data);
            }
        }

        return node;
    }

    bool find(Node* node, int data){
        if (node == nullptr){
            return false;
        }

        if (data < node->data){
            return find(node->left, data);
        } else if (data > node->data){
            return find(node->right, data);
        } else {
            return true;
        }
    }

    void preorder(Node* node){
        if (node == nullptr){
            return;
        }

        std::cout << node->data << ' ';
        preorder(node->left);
        preorder(node->right);
    }

public:
    BinaryTree() : root(nullptr) {}

    void print(){
        preorder(root);
        std::cout << std::endl;
    }

    void insert(int value){
        root = insert(root, value);
    }

    void remove(int value){
        root = remove(root, value);
    }

    void find(int value){
        if (find(root, value)){
            std::cout << "YES";
        } else{
            std::cout << "NO";
        }
        std::cout << std::endl;
    }
};


class Tree{
public:
    struct Node{
        std::vector<Node*> children;
        int data;

        Node(int data) : data(data) {}
    };

    Node* root;

    Tree(int data) : root(new Node(data)) {}

    void insert(Node* parent, int data){
        Node* newnode = new Node(data);
        parent->children.push_back(newnode);
    }

    void print(Node* node){
        std::cout << node->data << " ";
        for (int i = 0; i < node->children.size(); i++) {
            print(node->children[i]);
        }
    }
};