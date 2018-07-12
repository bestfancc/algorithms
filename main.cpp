#include <iostream>
#include <algorithm>
using namespace std;
//二分查找
class BinarySearch
{
public:
    static int binarySearchRank(double key, double a[],int size) {

        for(int i;i < size;i++) {
            cout<<a[i]<<endl;
        }
        int lo = 0;
        int hi = size;
        while (lo <= hi) {
            int mid = (int)(lo + (hi - lo)/2);
            if (key < a[mid]) {
                hi = mid - 1;
            }
            else if (key > a[mid]) {
                lo = mid +1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }

    static void binarySearch() {
        double a[] = {1.1,5.2,6.4,2.1,2.0,3.2,9.9,66.5,32.4};
        int size = sizeof(a)/ sizeof(a[0]);
        sort(a,a+size);
        double key;
        cin>>key;
        int result = BinarySearch::binarySearchRank(key, a, size);
        if(result < 0) {
            cout<<"not found "<<key<<" in the array!"<<endl;
        } else{
            cout<<"found it in array,the key is : "<<result<<" !"<<endl;
        }
    }

};
//比较类
class Comparable
{
public:
    int v;
    Comparable(int v) {
        this->v = v;
    }
    int compareTo(int w) {
        if(this->v < w) return -1;
        if(this->v = w) return 0;
        if(this->v > w) return 1;
    }
};
//排序基类
class BaseSort
{
public:
    static bool isSorted(double a[],int size) {
        for (int i = 1; i < size; ++i) {
            if(less(a[i], a[i-1])) {
                return false;
            }
            return true;
        }
    }
    static bool less(int v, int w) {
        Comparable V(v);
        return V.compareTo(w);
    }
    static void exch(double *a,int i, int j) {
        double tmp = a[i];
        a[i] = a[j];
        a[j] = tmp;
    }
    static void show(double *a,int size) {
        for (int i = 0; i < size; i++) {
            std::cout<<a[i]<<" ";
        }
        cout<<endl;
    }
};
//选择排序
 class SelectSort :public BaseSort
{
public:
    static void sort(double *a,int size) {
        for (int i = 0; i < size - 1; i++) {
            int minKey = i;
            for (int j = i+1; j < size; j++) {
                if(less(*(a + j),*(a + minKey))) {
                    minKey = j;
                }
            }
            exch(a,i,minKey);
        }
    }
};
 //插入排序
class InsertionSort :public BaseSort
{
public:
    static void sort(double *a, int size) {
        for (int i = 1; i < size; ++i) {
            for (int j = i; j > 0; j--) {
                if(less(*(a + j),*(a + j - 1))) {
                    exch(a,j,j - 1);
                }
            }
        }
    }
    static void main() {
        double a[10];
        for (int i = 0; i < 10; ++i) {
            cin>>a[i];
        }
        int size = sizeof(a)/ sizeof(a[0]);
        sort(a,size);
        if(isSorted(a,size)) {
            cout<<"Is Sorted"<<endl;
        } else {
            cout<<"Not Sorted"<<endl;
        }

        show(a,size);
    }
};
//希尔排序
class ShellSort :public BaseSort
{
public:
    static void sort(double *a,int size) {
        int h = 1;
        while (h < size / 3) {
            h = 3 * h + 1;
        }
        while (h >= 1) {
            for (int i = h; i < size; ++i) {
                for (int j = i; j >= h  ;j -= h) {
                    if(less(*(a+j),*(a+j-h))) {
                        exch(a,j,j-h);
                    }
                }
            }
            show(a,size);
            h = h/3;
        }
    }
    static void main() {
        double a[10];
        for (int i = 0; i < 10; ++i) {
            cin>>a[i];
        }
        int size = sizeof(a)/ sizeof(a[0]);
        sort(a,size);
        if(isSorted(a,size)) {
            cout<<"Is Sorted"<<endl;
        } else {
            cout<<"Not Sorted"<<endl;
        }
        show(a,size);
    }
};
//归并排序
class MergeSort :public BaseSort
{
public:
    //自顶向下的归并排序
    static void sort(double *a, int size) {
        sort(a,0,size - 1);
    }
    //自底向上的归并排序
    static void sortBU(double *a, int size) {
        double aux[10];
        for (int i = 1; i < size; i = i + i) {
            for (int j = 0; j < size - i; j = i + i + j) {
                int min = ((j+i+i-1) > (size-1)) ? size-1: (j+i+i-1);
                merge(a,j,j+i-1,min);
            }
        }
    }
    //原地合并
    static void merge(double *a, int lo, int mid, int hi) {
        double aux[10];
        int i = lo,j = mid + 1;
        for (int k = lo; k <= hi; ++k) {
            aux[k] = *(a+k);
        }
        for (int t = lo; t <= hi; ++t) {
            if (i > mid) {  //第一段数组取完了
                *(a+t) = aux[j++];
            } else if (j > hi) {  //第二段数组取完了
                *(a+t) = aux[i++];
            } else if (less(aux[j],aux[i])) {
                *(a+t) = aux[j++];
            } else {
                *(a+t) = aux[i++];
            }
        }
    }
    static void sort(double *a, int lo, int hi) {
        if(lo >= hi) {
            return;
        }
        int mid = lo + (hi - lo)/2;
        sort(a,lo,mid);
        sort(a,mid + 1,hi);
        merge(a,lo,mid,hi);
    }
    static void main() {
        double a[] = {9,8,7,6,5,4,3,2,1,0};
//        double a[10];
//        for (int i = 0; i < 10; ++i) {
//            cin>>a[i];
//        }
        int size = sizeof(a)/ sizeof(a[0]);
        cout<<"输入：";
        show(a,size);
        //自顶向下的归并排序
        sort(a,size);
        //自底向上的归并排序
        sortBU(a,size);
        if(isSorted(a,size)) {
            cout<<"Is Sorted"<<endl;
        } else {
            cout<<"Not Sorted"<<endl;
        }
        show(a,size);
    }
};
//快速排序
class QuickSort :public BaseSort
{
public:
    static void sort(double *a, int size) {
        srand(time(0));
        std::random_shuffle(a, a + size);
        sort(a,0,size-1);
    }
    static void sort(double *a, int lo, int hi) {
        if(lo >= hi) {
            return;
        }
        int j = partition(a,lo,hi);
        sort(a,lo,j-1);
        sort(a,j+1,hi);
    }
    static int partition(double *a, int lo, int hi) {
        int i = lo,j = hi+1;
        double v = a[lo];
        while (true) {
            while (less(a[++i],v)) if (i == hi) break;
            while (less(v,a[--j])) if (j == lo) break;
            if (i >= j) break;
            exch(a,i,j);
        }
        exch(a,lo,j);
        return j;
    }
    static void main() {
        double a[] = {9,8,7,6,5,4,3,2,1,0};
//        double a[10];
//        for (int i = 0; i < 10; ++i) {
//            cin>>a[i];
//        }
        int size = sizeof(a)/ sizeof(a[0]);
        cout<<"输入：";
        show(a,size);
        sort(a,size);
        if(isSorted(a,size)) {
            cout<<"Is Sorted"<<endl;
        } else {
            cout<<"Not Sorted"<<endl;
        }
        show(a,size);
    }
};
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
//堆排序
class HeapSort :public BaseSort
{
public:
    static void sink(double *a, int size, int k) {
        while (2*k <= size) {
            int j = 2*k;
            if(j < size && less(*(a+j),*(a+j+1))) j++;
            if(!less(*(a+k),*(a+j))) break;
            exch(a,k,j);
            k = j;
        }
    }
    static void sort(double *a,int size) {
        for (int k = size/2; k >= 1 ; k--) {
            sink(a,size,k);
        }
        while (size > 1) {
            exch(a,1,size--);
            sink(a,size,1);
        }
    }
    static void main() {
        double a[] = {0,9,8,7,6,5,4,6,2,1,0};
//        double a[10];
//        for (int i = 0; i < 10; ++i) {
//            cin>>a[i];
//        }
        int size = sizeof(a)/ sizeof(a[0]);
        cout<<"输入：";
        show(a,size);
        sort(a,size-1);
        if(isSorted(a,size)) {
            cout<<"Is Sorted"<<endl;
        } else {
            cout<<"Not Sorted"<<endl;
        }
        show(a,size);
    }
};
//二叉查找树
class BST
{
public:
    class Node
    {
    public:
        double key;
        double val;
        Node left,right;
        int N;
        Node() {

        }
        Node(double key, double val, int N) {
            this->key = key;this->val = val;this->N = N;
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
    Node root;
    int size(Node x) {
        if(x.isNull()) {
            return 0;
        }else{
            return x.N;
        }
    }
    int size() {
        return size(root);
    }
    double get(double key) {
        return get(root,key);
    }
    double get(Node x, double key) {
        //在以x为跟结点的子树中查找并返回key对应的值
        //如果找不到就返回NULL
        if(x.isNull()) return NULL;
        Comparable compareKey(key);
        int cmp = compareKey.compareTo(x.key);
        if(cmp < 0) return get(x.left,key);
        else if(cmp > 0) return get(x.right,key);
        else return x.val;
    }
    void put(double key, double val) {
        //查找key，找到则更新它的值，否则为它创建一个新的结点
        root = put(root,key,val);
    }
    Node put(Node x, double key, double val) {
        //如果key存在于以x为根结点的自述中则更新它的值；
        //否则将以key和val为键值对的新结点插入到该子树中
        if(x.isNull()) return Node(key,val,1);
        Comparable compareKey(key);
        int cmp = compareKey.compareTo(x.key);
        if(cmp < 0) x.left = put(x.left,key,val);
        else if(cmp > 0) x.right = put(x.right,key,val);
        else x.val = val;
        x.N = size(x.left) + size(x.right) + 1;
        return x;
    }
};



int main() {
    //hello world
//    std::cout << "Hello, World!" << std::endl;
    //二分查找算法
//    BinarySearch::binarySearch();
//    binarySearch();
    //选择排序
//    SelectSort::main();
    //插入排序
//    InsertionSort::main();
    //希尔排序
//    ShellSort::main();
    //归并排序
//    MergeSort::main();
    //快速排序
//    QuickSort::main();
    //堆排序
//    HeapSort::main();
    //查找


    return 0;
}


