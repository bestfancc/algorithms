/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/21
 */
#include "BaseSort.h"
#ifndef ALGORITHMS_MAXPQ_H
#define ALGORITHMS_MAXPQ_H
//优先队列
class MaxPQ :public BaseSort
{
public:
    int N;
    double *pq;
    MaxPQ(int maxN);
    bool isEmpty();
    int size();
    bool less(int i, int j);
    void exch(int i, int j);
    void swim(int k);
    void sink(int k);
    void insert(double v);
    double delMax();
    static void run();
};
#endif //ALGORITHMS_MAXPQ_H
