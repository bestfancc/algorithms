/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/30
 */
#include <iostream>
#include <queue>
#include "Header/Comparable.h"
#include "Header/RedBlackBST.h"
using namespace std;

//红黑树
RedBlackBST::Node::Node() {}
RedBlackBST::Node::Node(double key, double val, int N, bool color) {
    this->key = key;
    this->val = val;
    this->N = N;
    this->color = color;
}
bool RedBlackBST::Node::operator==(RedBlackBST::Node x) {
    if (this->key == x.key && this->val == x.val && this->N == x.N && this->color == x.color) return true;
    return false;
}
bool RedBlackBST::Node::isNull() {
    if (this == NULL) return true;
    return false;
}
bool RedBlackBST::isRed(Node *h) {
    if (h->isNull()) return false;
    return h->color == RED;
}
RedBlackBST::Node *RedBlackBST::rotateLeft(RedBlackBST::Node *h) {
    RedBlackBST::Node *x = h->right;
    h->right = x->left;
    x->left = h;
    x->color = RED;
    x->N = h->N;
    h->N = 1 + size(h->left) + size(h->right);
    return x;
}
RedBlackBST::Node *RedBlackBST::rotateRight(RedBlackBST::Node *h) {
    RedBlackBST::Node *x = h->left;
    h->left = x->left;
    x->right = h;
    x->color = h->color;
    h->color = RED;
    x->N = h->N;
    h->N = 1 + size(h->left) + size(h->right);
    return x;
}
void RedBlackBST::flipColors(RedBlackBST::Node *h) {
    h->color = RED;
    h->left->color = BLACK;
    h->right->color = BLACK;
}
int RedBlackBST::size(RedBlackBST::Node *x) {
    if (x->isNull()) {
        return 0;
    }else{
        return x->N;
    }
}
int RedBlackBST::size() {
    return size(root);
}
void RedBlackBST::put(double key, double val) {
    //查找key，找到则更新其值，否则为它新建一个结点
    root = put(root,key,val);
    root->color = BLACK;
}
RedBlackBST::Node *RedBlackBST::put(RedBlackBST::Node *h, double key, double val) {
    if (h->isNull()) {
        return new RedBlackBST::Node(key,val,1,RED);
    }
    Comparable V(key);
    if (V.compareTo(h->key) < 0) h->left = put(h->left, key, val);
    else if (V.compareTo(h->right > 0)) h->right = put(h->right, key, val);
    else h->val = val;

    if (isRed(h->right) && !isRed(h->left)) h = rotateLeft(h);
    if (isRed(h->left) && isRed(h->left->left)) h = rotateRight(h);
    if (isRed(h->left)  && isRed(h->right)) flipColors(h);
    h->N = size(h->left) + size(h->right) + 1;
    return h;
}
void static RedBlackBST::run() {

}