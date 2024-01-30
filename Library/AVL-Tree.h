#pragma once

#include<iostream>
#include<cstdio>
#include<sstream>
#include<algorithm>
#include "Node.h"
#include "Book.h"

using namespace std;

template<typename T>
struct NodeAVL {
    T data;
    NodeAVL* left;
    NodeAVL* right;
};

template<typename T>
class AVLTree {
private:

public:
    NodeAVL<T>* root;
    AVLTree();
    AVLTree(Node<T>*);
    int height(NodeAVL<T>*);
    int difference(NodeAVL<T>*);
    NodeAVL<T>* right_right_rotat(NodeAVL<T>*);
    NodeAVL<T>* left_left_rotat(NodeAVL<T>*);
    NodeAVL<T>* left_right_rotat(NodeAVL<T>*);
    NodeAVL<T>* right_left_rotat(NodeAVL<T>*);
    NodeAVL<T>* balance(NodeAVL<T>*);
    NodeAVL<T>* insert(NodeAVL<T>*, T);
    T search(NodeAVL<T>*, string);
    NodeAVL<T>* get_root();
    void inorder(NodeAVL<T>*);
};

template<typename T>
AVLTree<T>::AVLTree()
{
    root = NULL;
}

template<typename T>
AVLTree<T>::AVLTree(Node<T>* input)
{
    Node<Book>* temp = input;
    while (temp != nullptr)
    {
        this->root = this->insert(this->get_root(), temp->getValue());
        temp = temp->getNext();
    }
}

template<typename T>
int AVLTree<T>::height(NodeAVL<T>* input)
{
    int h = 0;
    if (input != nullptr) {
        int l_height = height(input->left);
        int r_height = height(input->right);
        int max_height = max(l_height, r_height);
        h = max_height + 1;
    }
    return h;
}

template<typename T>
int AVLTree<T>::difference(NodeAVL<T>* input)
{
    int left_height = height(input->left);
    int right_height = height(input->right);
    int balance_factor = left_height - right_height;
    return balance_factor;
}

template<typename T>
NodeAVL<T>* AVLTree<T>::right_right_rotat(NodeAVL<T>* parent)
{
    NodeAVL<T>* temp;
    temp = parent->right;
    parent->right = temp->left;
    temp->left = parent;
    return temp;
}

template<typename T>
NodeAVL<T>* AVLTree<T>::left_left_rotat(NodeAVL<T>* parent)
{
    NodeAVL<T>* temp;
    temp = parent->left;
    parent->left = temp->right;
    temp->right = parent;
    return temp;
}

template<typename T>
NodeAVL<T>* AVLTree<T>::left_right_rotat(NodeAVL<T>* parent)
{
    NodeAVL<T>* temp;
    temp = parent->left;
    parent->left = right_right_rotat(temp);
    return left_left_rotat(parent);
}

template<typename T>
NodeAVL<T>* AVLTree<T>::right_left_rotat(NodeAVL<T>* parent)
{
    NodeAVL<T>* temp;
    temp = parent->right;
    parent->right = left_left_rotat(temp);
    return right_right_rotat(parent);
}

template<typename T>
NodeAVL<T>* AVLTree<T>::balance(NodeAVL<T>* input)
{
    int bal_factor = difference(input);
    if (bal_factor > 1) {
        if (difference(input->left) > 0)
            input = left_left_rotat(input);
        else
            input = left_right_rotat(input);
    }
    else if (bal_factor < -1) {
        if (difference(input->right) > 0)
            input = right_left_rotat(input);
        else
            input = right_right_rotat(input);
    }
    return input;
}

template<typename T>
NodeAVL<T>* AVLTree<T>::insert(NodeAVL<T>* r, T valu)
{
    if (r == nullptr) {
        r = new NodeAVL<T>;
        r->data = valu;
        r->left = nullptr;
        r->right = nullptr;
        return r;
    }
    else if (valu < r->data) {
        r->left = insert(r->left, valu);
        r = balance(r);
    }
    else if (valu >= r->data) {
        r->right = insert(r->right, valu);
        r = balance(r);
    } return r;
}

template<typename T>
void AVLTree<T>::inorder(NodeAVL<T>* r) {
    if (r == NULL)
        return;
    inorder(r->left);
    cout << r->data.getTitle() << " ";
    inorder(r->right);
}

void AVLTree<Book>::inorder(NodeAVL<Book>* r) {
    if (r == NULL)
        return;
    inorder(r->left);
    r->data.print();
    inorder(r->right);
}

template<typename T>
NodeAVL<T>* AVLTree<T>::get_root()
{
    return root;
}

template<typename T>
T AVLTree<T>::search(NodeAVL<T>* r, string title)
{
    while (r != nullptr)
    {
        if (r->data.getTitle() == title)
            return r->data;
        else if (r->data.getTitle() > title)
            r = r->left;
        else
            r = r->right;
    }
    return r->data;
}