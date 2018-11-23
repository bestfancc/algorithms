/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/21
 */
#include <iostream>
#include <queue>
#include "Header/Comparable.h"
#include "Header/BST.h"
using namespace std;

//二叉查找树
BST::Node::Node() :left(NULL),right(NULL) {

}
BST::Node::Node(double key, double val, int N) :left(NULL),right(NULL) {
    this->key = key;
    this->val = val;
    this->N = N;
}
bool BST::Node::operator == (Node x) {
    if (this->key == x.key && this->val == x.val && this->N == x.N) return true;
    return false;
}
bool BST::Node::isNull() {
    if (this == NULL) return true;
    return false;
}
bool BST::Node::operator != (Node x) {
    if (this->key == x.key && this->val == x.val && this->N == x.N) return false;
    return true;
}

BST::BST() :root(NULL) {

}
int BST::size(Node *x) {
    if(x->isNull()) {
        return 0;
    }else{
        return x->N;
    }
}
int BST::size() {
    return size(root);
}
double BST::get(double key) {
    return get(root,key);
}
double BST::get(Node *& x, double key) {
    //在以x为跟结点的子树中查找并返回key对应的值
    //如果找不到就返回NULL
    if(x->isNull()) return 0;
    Comparable compareKey(key);
    int cmp = compareKey.compareTo((*x).key);
    if(cmp < 0) return get(x->left,key);
    else if(cmp > 0) return get(x->right,key);
    else return x->val;
}
void BST::put(double key, double val) {
    //查找key，找到则更新它的值，否则为它创建一个新的结点
    root = put(root,key,val);
}
BST::Node* BST::put(BST::Node *& x, double key, double val)   {
    //如果key存在于以x为根结点的自述中则更新它的值；
    //否则将以key和val为键值对的新结点插入到该子树中
    if(x->isNull()) {
        Node *y = new Node(key,val,1);
        x = y;
        return x;
    }
    Comparable compareKey(key);
    int cmp = compareKey.compareTo(x->key);
    if(cmp < 0) x->left = put(x->left,key,val);
    else if(cmp > 0) x->right = put(x->right,key,val);
    else x->val = val;
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}
double BST::min() {
    return min(root)->key;
}
BST::Node*  BST::min(Node * x) {
    if(x->left->isNull()) return x;
    return min(x->left);
}
double BST::max() {
    return max(root)->key;
}
BST::Node* BST::max(BST::Node *x) {
    if((x->right)->isNull()) return x;
    return max(x->right);
}
double BST::floor(double key) {
    //返回小于
    Node *x = floor(root,key);
    if(x->isNull()) return 0;
    return x->key;
}
BST::Node* BST::floor(Node *x, double key) {
    if(x->isNull()) return NULL;
    Comparable compareKey(key);
    int cmp = compareKey.compareTo(x->key);
    if(cmp == 0) return NULL;
    if(cmp < 0) return floor(x->left,key);
    Node *t = floor(x->right,key);
    if(!t->isNull()) return t;
    else return x;
}
double BST::select(int k) {
    return select(root,k)->key;
}
BST::Node* BST::select(Node *x,int k) {
    //返回排名为k的结点
    if(x->isNull()) return NULL;
    int t = size(x->left);
    if(t > k) return select(x->left,k);
    else if(t < k) return select(x->right, k-t-1);
    else return x;
}
int BST::rank(double key) {
    return rank(key,root);
}
int BST::rank(double key,Node *x) {
    //返回以x为根结点的子树中小于x.key的键的数量
    if(x->isNull()) return 0;
    Comparable compareKey(key);
    int cmp = compareKey.compareTo(x->key);
    if(cmp < 0) return rank(key, x->left);
    else if(cmp > 0) return 1 + size(x->left) + rank(key, x->right);
    else return size(x->left);
}
void BST::deleteMin() {
    root = deleteMin(root);
}
BST::Node* BST::deleteMin(BST::Node *x) {
    if(x->left->isNull()) return x->right;
    x->left = deleteMin(x->left);
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}
void BST::deleteOne(double key) {
    root = deleteOne(root, key);
}
BST::Node* BST::deleteOne(BST::Node *x, double key) {
    if(x->isNull()) return NULL;
    Comparable compareKey(key);
    int cmp = compareKey.compareTo(x->key);
    if(cmp < 0) x->left = deleteOne(x->left, key);
    else if(cmp > 0) x->right = deleteOne(x->right, key);
    else{
        if((x->right)->isNull()) return x->left;
        if((x->left)->isNull()) return x->right;
        Node* t = x;
        x = min(x->right);
        x->right = deleteMin(t->right);
        x->left = t->left;
    }
    x->N = size(x->left) + size(x->right) + 1;
    return x;
}
//范围查找操作
queue <double > BST::keys() {
    return keys(min(), max());
}
queue <double > BST::keys(double lo, double hi) {
    queue< double > queue;
    keys(root, queue, lo, hi);
    return queue;
}

void BST::keys(BST::Node *& x, queue<double > & queue, double lo, double hi) {
    if(x->isNull()) return;
    Comparable comparableLo(lo);
    int cmplo = comparableLo.compareTo(x->key);
    Comparable comparableHi(hi);
    int cmphi = comparableHi.compareTo(x->key);
    if(cmplo < 0) {
        if(!x->left->isNull()) {
            keys(x->left, queue, lo, hi);
        }
    }
    if(cmplo <=0 && cmphi >= 0) {
        queue.push(x->key);
    }
    if(cmphi > 0) {
        if(!x->right->isNull()) {
            keys(x->right, queue, lo, hi);
        }
    }
}
void BST::print(BST::Node *x) {
    if(x->isNull()) return;
    BST::print(x->left);
    std::cout<<"key为"<<x->key<<"结点 N的值为"<<x->N<<" val的值为"<<x->val<<endl;
    BST::print(x->right);
}
void BST::preOrderTraversal(BST::Node *x) {
    if(x->isNull()) return;
    std::cout<<"key为"<<x->key<<"结点 N的值为"<<x->N<<" val的值为"<<x->val<<endl;
    BST::preOrderTraversal(x->left);
    BST::preOrderTraversal(x->right);
}
void BST::inOrderTraversal(BST::Node *x) {
    if(x->isNull()) return;
    BST::inOrderTraversal(x->left);
    std::cout<<"key为"<<x->key<<"结点 N的值为"<<x->N<<" val的值为"<<x->val<<endl;
    BST::inOrderTraversal(x->right);
}
void BST::postOrderTraversal(BST::Node *x) {
    if(x->isNull()) return;
    BST::postOrderTraversal(x->left);
    BST::postOrderTraversal(x->right);
    std::cout<<"key为"<<x->key<<"结点 N的值为"<<x->N<<" val的值为"<<x->val<<endl;
}
void BST::layerTraversal(BST::Node *x) {
    queue< BST::Node * > queue ;
    queue.push(x);
    while (!queue.empty()) {
        BST::Node * current = queue.front();
        queue.pop();
        std::cout<<"key为"<<current->key<<"结点 N的值为"<<current->N<<" val的值为"<<current->val<<endl;
        if(!current->left->isNull()) {
            queue.push(current->left);
        }
        if(!current->right->isNull()) {
            queue.push(current->right);
        }
    }
}
void BST::run() {
    //查找
    BST bst;
    bst.put(3.1, 3);
    bst.put(2.1, 5);
    bst.put(1.1, 6);
    bst.put(6.1, 1);
    bst.put(7.1, 9);
    bst.put(3.5, 10);
    bst.put(2.9, 0);
    std::cout <<"打印二叉树开始"<<endl;
    bst.print(bst.root);
    std::cout <<"打印二叉树结束"<<endl;
    std::cout <<"测试get方法开始"<<endl;
    std::cout <<"key为1.1的结点的val为"<<bst.get(1.1)<<endl;
    std::cout <<"key为6.1的结点的val为"<<bst.get(6.1)<<endl;
    std::cout <<"测试get方法结束"<<endl;
    std::cout <<"二叉查找树中最小（最左边）的键为"<<bst.min()<<endl;
    std::cout <<"二叉查找树中最大（最右边）的键为"<<bst.max()<<endl;
    std::cout <<"二叉查找树中小于等于5的最大的键为"<<bst.floor(5)<<endl;

    std::cout <<"二叉查找树中排名为3(从0开始)的键为"<<bst.select(3)<<endl;
    std::cout <<"二叉查找树中key小于7的最大值的排名（key小于7的个数）为"<<bst.rank(7)<<endl;
    std::cout<<"先序遍历开始"<<endl;
    bst.preOrderTraversal(bst.root);  //先序遍历
    std::cout<<"先序遍历结束"<<endl;
    std::cout<<"中序遍历开始"<<endl;
    bst.inOrderTraversal(bst.root);  //中序遍历
    std::cout<<"中序遍历结束"<<endl;
    std::cout<<"后序遍历开始"<<endl;
    bst.postOrderTraversal(bst.root);  //后序遍历
    std::cout<<"后序遍历结束"<<endl;
    std::cout<<"层次遍历开始"<<endl;
    bst.layerTraversal(bst.root);  //层次遍历
    std::cout<<"层次遍历结束"<<endl;
    cout<<"删除key最小的结点"<<endl;
    bst.deleteMin();
    std::cout <<"打印二叉树开始"<<endl;
    bst.print(bst.root);
    std::cout <<"打印二叉树结束"<<endl;
    bst.deleteOne(3.1);
    std::cout <<"打印二叉树开始"<<endl;
    bst.print(bst.root);
    std::cout <<"打印二叉树结束"<<endl;
}