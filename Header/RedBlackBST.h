/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/30
 */
#include "Comparable.h"

#ifndef ALGORITHMS_REDBLACKBST_H
#define ALGORITHMS_REDBLACKBST_H
class RedBlackBST :public Comparable <double (v)>
{
private:
    static bool RED = true;
    static bool BLACK = false;
public:
    class Node
    {
    public:
        double key;
        double val;
        int N;
        RedBlackBST::Node *left;
        RedBlackBST::Node *right;
        bool color;
        Node();
        Node(double key, double val, int N, bool color);
        bool operator == (Node x);
        bool isNull();
    };
    RedBlackBST::Node *root;
    bool isRed(Node *h);
    RedBlackBST::Node *rotateLeft(Node *h);
    RedBlackBST::Node *rotateRight(Node *h);
    void flipColors(Node *h);
    int size(Node *x);
    int size();
    void put(double key, double val);

    RedBlackBST::Node *put(Node *h, double key, double val);

};
#endif //ALGORITHMS_REDBLACKBST_H
