#include <iostream>
using namespace std;

struct node {
  int key;
  struct node *left, *right;
};

// Inorder traversal
void traverseInOrder(struct node *root) {
    if (root){
        traverseInOrder(root->left);
        cout<< (root->key) << " ";
        traverseInOrder(root->right);
    }
}


//create new node and assign values to the attributes
node* createNode(int key){
    node * newNode = new node();
    newNode->key=key;
    newNode->left= nullptr;
    newNode->right=nullptr;
    return newNode;
}

// Insert a node
struct node *insertNode(struct node *node, int key) {
    if (!node){ //base case
        return createNode(key);
    }
    if (key < node->key) {
        node->left = insertNode(node->left, key);
    }
    else{
        node->right = insertNode(node->right, key);
    }
    return node;

}

// Deleting a node
//
struct node *deleteNode(struct node *root, int key) {
    if (!root) return root; //if the value doesn't exist in the tree

    //choosing the sub trees
    if (key < root->key) root->left= deleteNode (root->left, key);

    else if (key>root->key) root->right= deleteNode (root->right, key);

    else{ //key found and need to be deleted
        if (!root->left) return root->right;
        if (!root->right) return root->left;

        node* temp= root->right;
        while (temp->left) temp=temp->left;
        root->key=temp->key;
        root->right=deleteNode(root->right,root->key);
        }
    return root;

}

// Driver code
int main() {
  struct node *root = NULL;

  int operation;
  int operand;
  cin >> operation;

  while (operation != -1) {
    switch(operation) {
      case 1: // insert
        cin >> operand;
        root = insertNode(root, operand);
        cin >> operation;
        break;
      case 2: // delete
        cin >> operand;
        root = deleteNode(root, operand);
        cin >> operation;
        break;
      default:
        cout << "Invalid Operator!\n";
        return 0;
    }
  }

  traverseInOrder(root);
}
