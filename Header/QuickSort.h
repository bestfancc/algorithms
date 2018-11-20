/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "BaseSort.h"
#ifndef SUANFA_QUICKSORT_H
#define SUANFA_QUICKSORT_H
//快速排序
class QuickSort :public BaseSort
{
public:
    virtual void sort(double *a, int size);
    void sort(double *a, int lo, int hi);
    int partition(double *a, int lo, int hi);
};
#endif //SUANFA_QUICKSORT_H
