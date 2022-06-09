//#include <iostream>
//#include "BinaryTree.h"
//#include <queue>
//using namespace std;
//
//BinaryTree::BinaryTree()
//{
//    root = NULL;
//}
//
//BinaryTree::Node* BinaryTree::createNode(int data)
//{
//    Node* newNode = root;
//    if (!newNode) {
//        cout << "Memory error\n";
//        return NULL;
//    }
//    newNode->data = data;
//    newNode->left = newNode->right = NULL;
//    return newNode;
//}
//
//BinaryTree::Node* BinaryTree::insertNode(int data)
//{
//    // If the tree is empty, assign new node address to root
//    if(root == NULL) {
//        root = createNode(data);
//        return root;
//    }
//
//    // Else, do level order traversal until we find an empty
//    // place, i.e. either left child or right child of some
//    // node is pointing to NULL.
//    queue<Node*> q;
//    q.push(root);
//
//    while (!q.empty()) {
//        Node* temp = q.front();
//        q.pop();
//
//        if (temp->left != NULL)
//            q.push(temp->left);
//        else {
//            temp->left = createNode(data);
//            return root;
//        }
//
//        if (temp->right != NULL)
//            q.push(temp->right);
//        else {
//            temp->right = createNode(data);
//            return root;
//        }
//    }
//}
//
//void BinaryTree::search(int data)
//{
//    int depth = 0;
//    Node* temp = new Node(data);
//
//    while (temp != NULL) 
//    {
//        depth++;
//        if (temp->data == data) {
//            cout << "\nitem found at depth: " << depth;
//            return;
//        }
//        else if (temp->data > data)
//            temp = temp->left;
//        else
//            temp = temp->right;
//    }
//    cout << "\n item not found";
//    return;
//}
//
//void BinaryTree::print()
//{
//    if (root == NULL)
//        return;
//
//    print(temp->left);
//    cout << temp->data << ' ';
//    print(temp->right);
//}



