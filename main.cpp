#include <iostream>
#include <algorithm>
#include <queue>
#include "Header/BinarySearch.h"
#include "Header/Comparable.h"
#include "Header/BaseSort.h"
#include "Header/SelectSort.h"
#include "Header/InsertionSort.h"
#include "Header/ShellSort.h"
#include "Header/MergeSort.h"
#include "Header/QuickSort.h"
#include "Header/HeapSort.h"
using namespace std;

/**
//优先队列
class MaxPQ :public BaseSort
{
public:
    int N;
    double *pq;
    MaxPQ(int maxN) {
        N = maxN;
        double *pq = new double[N];
    }
    bool isEmpty() {
        return N == 0;
    }
    int size() {
        return N;
    }
    bool less(int i, int j) {
        return pq[i] < pq[j];
    }
    void exch(int i, int j) {
        double t = pq[i];
        pq[i] = pq[j];
        pq[j] = t;
    }
    void swim(int k) {
        while (k > 1 && less(k/2, k))
        {
            exch(k/2, k);
            k = k/2;
        }
    }
    void sink(int k) {
        while (2*k <= N) {
            int j = 2*k;
            if(j < N && less(j, j+1)) j++;
            if(!less(k, j));
            k = j;
        }
    }
    void insert(double v) {
        pq[++N] = v;
        swim(N);
    }
    double delMax() {
        double max = pq[1];
        exch(1, N--);
        pq[N+1] = '\0';
        sink(1);
        return max;
    }
};
*/
/*
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
        Node() :left(NULL),right(NULL) {

        }
        Node(double key, double val, int N) :left(NULL),right(NULL) {
            this->key = key;
            this->val = val;
            this->N = N;
        }
        bool operator == (Node x) {
            if (this->key == x.key && this->val == x.val && this->N == x.N) return true;
            return false;
        }
        bool isNull() {
            if (this == NULL) return true;
            return false;
        }
        bool operator != (Node x) {
            if (this->key == x.key && this->val == x.val && this->N == x.N) return false;
            return true;
        }

    };
    Node *root;
    BST() :root(NULL) {

    }
    int size(Node *x) {
        if(x->isNull()) {
            return 0;
        }else{
            return x->N;
        }
    }
    int size() {
        return size(root);
    }
    double get(double key) {
        return get(root,key);
    }
    double get(Node *& x, double key) {
        //在以x为跟结点的子树中查找并返回key对应的值
        //如果找不到就返回NULL
        if(x->isNull()) return 0;
        Comparable compareKey(key);
        int cmp = compareKey.compareTo((*x).key);
        if(cmp < 0) return get(x->left,key);
        else if(cmp > 0) return get(x->right,key);
        else return x->val;
    }
    void put(double key, double val) {
        //查找key，找到则更新它的值，否则为它创建一个新的结点
        root = put(root,key,val);
    }
    Node* put(Node *& x, double key, double val)   {
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
    double min() {
        return min(root)->key;
    }
    Node*  min(Node * x) {
        if(x->left->isNull()) return x;
        return min(x->left);
    }
    double max() {
        return max(root)->key;
    }
    Node* max(Node *x) {
        if((x->right)->isNull()) return x;
        return max(x->right);
    }
    double floor(double key) {
        //返回小于
        Node *x = floor(root,key);
        if(x->isNull()) return 0;
        return x->key;
    }
    Node* floor(Node *x, double key) {
        if(x->isNull()) return NULL;
        Comparable compareKey(key);
        int cmp = compareKey.compareTo(x->key);
        if(cmp == 0) return NULL;
        if(cmp < 0) return floor(x->left,key);
        Node *t = floor(x->right,key);
        if(!t->isNull()) return t;
        else return x;
    }
    double select(int k) {
        return select(root,k)->key;
    }
    Node* select(Node *x,int k) {
        //返回排名为k的结点
        if(x->isNull()) return NULL;
        int t = size(x->left);
        if(t > k) return select(x->left,k);
        else if(t < k) return select(x->right, k-t-1);
        else return x;
    }
    int rank(double key) {
        return rank(key,root);
    }
    int rank(double key,Node *x) {
        //返回以x为根结点的子树中小于x.key的键的数量
        if(x->isNull()) return 0;
        Comparable compareKey(key);
        int cmp = compareKey.compareTo(x->key);
        if(cmp < 0) return rank(key, x->left);
        else if(cmp > 0) return 1 + size(x->left) + rank(key, x->right);
        else return size(x->left);
    }
    void deleteMin() {
        root = deleteMin(root);
    }
    Node* deleteMin(Node *x) {
        if(x->left->isNull()) return x->right;
        x->left = deleteMin(x->left);
        x->N = size(x->left) + size(x->right) + 1;
        return x;
    }
    void deleteOne(double key) {
        root = deleteOne(root, key);
    }
    Node* deleteOne(Node *x, double key) {
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
    queue <double > keys() {
        return keys(min(), max());
    }
    queue <double > keys(double lo, double hi) {
        queue< double > queue;
        keys(root, queue, lo, hi);
        return queue;
    }

    void keys(Node *& x, queue<double > & queue, double lo, double hi) {
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
    void print(Node *x) {
        if(x->isNull()) return;
        print(x->left);
        std::cout<<"key为"<<x->key<<"结点 N的值为"<<x->N<<" val的值为"<<x->val<<endl;
        print(x->right);
    }
};
//打印队列
void print(queue<double> &s,int num)
{
    if(!num)
    {
        cout << endl;
        return;
    }
    double x= s.front();
    s.pop();
    cout << x << " ";
    s.push(x);
    print(s,--num);
}
 */
int main() {
    //hello world
//    std::cout << "Hello, World!" << std::endl;
    //二分查找算法
//    BinarySearch::binarySearch();
//    binarySearch();
    //选择排序
//    SelectSort selectSort;
//    selectSort.run();
    //插入排序
//    InsertionSort insertionSort;
//    insertionSort.run();
//    希尔排序
//    ShellSort shellSort;
//    shellSort.run();
    //归并排序
//    MergeSort mergeSort;
//    mergeSort.run();
    //快速排序
//    QuickSort quickSort;
//    quickSort.run();
    //堆排序
//    HeapSort heapSort;
//    heapSort.run();
    /*
    //查找
    BST bst;
    bst.put(3.1, 3);
    bst.put(2.1, 5);
    bst.put(1.1, 6);
    bst.put(6.1, 1);
    bst.put(7.1, 9);
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
     */
//    cout<<"删除key最小的结点"<<endl;
//    bst.deleteMin();
//    std::cout <<"打印二叉树开始"<<endl;
//    bst.print(bst.root);
//    std::cout <<"打印二叉树结束"<<endl;
//    bst.deleteOne(3.1);
//    std::cout <<"打印二叉树开始"<<endl;
//    bst.print(bst.root);
//    std::cout <<"打印二叉树结束"<<endl;
//    queue< double > queue = bst.keys();
    
//    print(queue,queue.size());  //中序遍历
    //先序遍历
    //后序遍历
    //层次遍历

    return 0;
}



