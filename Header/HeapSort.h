/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "BaseSort.h"
#ifndef SUANFA_HEAPSORT_H
#define SUANFA_HEAPSORT_H
//堆排序
class HeapSort :public BaseSort
{
public:
    static void sink(double *a, int size, int k);
    virtual void sort(double *a,int size);
};
#endif //SUANFA_HEAPSORT_H
