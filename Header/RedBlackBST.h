/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/30
 */
#ifndef ALGORITHMS_REDBLACKBST_H
#define ALGORITHMS_REDBLACKBST_H
class RedBlackBST
{
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
        bool isRed();
        bool isNull();
        bool operator != (Node x);
    };
};
#endif //ALGORITHMS_REDBLACKBST_H
