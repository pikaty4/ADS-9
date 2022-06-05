// Copyright 2021 NNTU-CS
#ifndef INCLUDE_BST_H_
#define INCLUDE_BST_H_
#include <iostream>
#include <string>
#include  <fstream>

template <typename T>
struct Node {
    Node<T>* l = nullptr;
    Node<T>* r = nullptr;
    int amount = 0;
    T value = "";
};
template <typename T>
class BST {
 private:
    Node<T>* base = nullptr;
    int depthV = 0;

 public:
    BST() {
        base = nullptr;
        depthV = 0;
    }
    void printT(Node<T>* tree, int i) {
        std::cout << i << "-----" << tree->value <<"\n";
        ++i;
        if (tree->l != nullptr) {
            printTree(tree->l, i);
        }
        if (tree->r != nullptr) {
            printTree(tree->r, i);
        }
        return;
    }
    void getDepth(Node<T>* tree, int i) {
        ++i;
        if (tree->l != nullptr) {
            getDepth(tree->l, i);
        }
        if (tree->r != nullptr) {
            getDepth(tree->r, i);
        }
        if (i > depthV)
            depthV = i;
    }
    void Add(T v) {
        Node<T>* cur = base;
        if (cur == nullptr) {
            cur = new Node<T>;
            cur->l = nullptr;
            cur->r = nullptr;
            cur->value = v;
            cur->amount +=1;
            base = cur;
            return;
        } else {
            Node<T>* past = nullptr;
            bool isl = false;
            while (true) {
                if (cur == nullptr) {
                    cur = new Node<T>;
                    cur->l = nullptr;
                    cur->r = nullptr;
                    cur->value = v;
                    cur->amount += 1;
                    if (past != nullptr) {
                        if (isl == true) {
                            past->l = cur;
                        } else {
                            past->r = cur;
                        }
                        past = nullptr;
                    }
                    break;
                } else if (v == cur->value) {
                    cur->amount += 1;
                    break;
                } else if (v > cur->value) {
                    isl = false;
                    past = cur;
                    cur = cur->r;
                } else if (v < cur->value) {
                    isl = true;
                    past = cur;
                    cur = cur->l;
                }
            }
        }
    }
    int search(T v) {
        Node<T>* cur = base;
        while (true) {
            if (cur->value == v) {
                return cur->amount;
            } else if (v > cur->value) {
                cur = cur->r;
            } else if (v < cur->value) {
                cur = cur->l;
            }
        }
    }
    int depth() {
        Node<T>* cur = base;
        getDepth(cur, 0);
        return depthV - 1;
    }

    void printTree() {
        Node<T>* cur = base;
        printT(cur, 0);
    }
};
#endif  // INCLUDE_BST_H_
