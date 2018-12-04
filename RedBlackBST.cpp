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
RedBlackBST::Node RedBlackBST::rotateLeft(RedBlackBST::Node h) {

}
RedBlackBST::Node RedBlackBST::rotateRight(RedBlackBST::Node h) {

}
void RedBlackBST::flipColors(RedBlackBST::Node h) {

}
int RedBlackBST::size() {

}
void RedBlackBST::put(double key, double val) {

}
RedBlackBST::Node RedBlackBST::put(RedBlackBST::Node h, double key, double val) {

    
}