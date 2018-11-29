/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/21
 */
#include "Header/MaxPQ.h"

MaxPQ::MaxPQ(int maxN) {
    N = maxN;
    double *pq = new double[N];
}
bool MaxPQ::isEmpty() {
    return N == 0;
}
int MaxPQ::size() {
    return N;
}
bool MaxPQ::less(int i, int j) {
    return pq[i] < pq[j];
}
void MaxPQ::exch(int i, int j) {
    double t = pq[i];
    pq[i] = pq[j];
    pq[j] = t;
}
void MaxPQ::swim(int k) {
    while (k > 1 && less(k/2, k))
    {
        exch(k/2, k);
        k = k/2;
    }
}
void MaxPQ::sink(int k) {
    while (2*k <= N) {
        int j = 2*k;
        if(j < N && less(j, j+1)) j++;
        if(!less(k, j));
        k = j;
    }
}
void MaxPQ::insert(double v) {
    pq[++N] = v;
    swim(N);
}
double MaxPQ::delMax() {
    double max = pq[1];
    exch(1, N--);
    pq[N+1] = '\0';
    sink(1);
    return max;
}
void run() {
    //构建一个优先队列
    //去掉最大值
}
