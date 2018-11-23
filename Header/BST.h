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
    Node *root;
    BST();
    int size(Node *x);
    int size();
    double get(double key);
    double get(Node *& x, double key);
    void put(double key, double val);
    Node* put(Node *& x, double key, double val);
    double min();
    Node*  min(Node * x);
    double max();
    Node* max(Node *x);
    double floor(double key);
    Node* floor(Node *x, double key);
    double select(int k);
    Node* select(Node *x,int k);
    int rank(double key);
    int rank(double key,Node *x);
    void deleteMin();
    Node* deleteMin(Node *x);
    void deleteOne(double key);
    Node* deleteOne(Node *x, double key);
    //范围查找操作
    queue <double > keys();
    queue <double > keys(double lo, double hi);
    void keys(Node *& x, queue<double > & queue, double lo, double hi);
    void print(Node *x);
    //深度优先遍历 -》前序遍历
    void preOrderTraversal();
    //深度优先遍历 -》中序遍历
    void inOrderTraversal(queue<double> &s,int num);
    //深度优先遍历 -》后序遍历
    void postOrderTraversal();
    //广度优先遍历
    void layerTraversal();
    static void run();
};
#endif //ALGORITHMS_BST_H
