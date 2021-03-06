/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/21
 */
#include <iostream>
#include <queue>
using namespace std;

#ifndef ALGORITHMS_BST_H
#define ALGORITHMS_BST_H
//二叉查找树
class BST
{
public:
    //结点类
    class Node
    {
    public:
        double key;
        double val;
        int N;
        BST::Node *left;
        BST::Node *right;
        Node();
        Node(double key, double val, int N);
        bool operator == (Node x);
        bool isNull();
        bool operator != (Node x);

    };
    BST::Node *root;
    BST();
    int size(BST::Node *x);
    int size();
    double get(double key);
    double get(BST::Node *& x, double key);
    void put(double key, double val);
    BST::Node* put(BST::Node *& x, double key, double val);
    double min();
    BST::Node*  min(BST::Node * x);
    double max();
    BST::Node* max(BST::Node *x);
    double floor(double key);
    BST::Node* floor(BST::Node *x, double key);
    double select(int k);
    BST::Node* select(BST::Node *x,int k);
    int rank(double key);
    int rank(double key,BST::Node *x);
    void deleteMin();
    BST::Node* deleteMin(BST::Node *x);
    void deleteOne(double key);
    BST::Node* deleteOne(BST::Node *x, double key);
    //范围查找操作
    queue <double > keys();
    queue <double > keys(double lo, double hi);
    void keys(BST::Node *& x, queue<double > & queue, double lo, double hi);
    //深度优先遍历 -》前序遍历
    void preOrderTraversal(BST::Node *x);
    //深度优先遍历 -》中序遍历
    void inOrderTraversal(BST::Node *x);
    //深度优先遍历 -》后序遍历
    void postOrderTraversal(BST::Node *x);
    //广度优先遍历
    void layerTraversal(BST::Node *x);
    static void run();
};
#endif //ALGORITHMS_BST_H
