/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "BaseSort.h"
#ifndef SUANFA_MERGESORT_H
#define SUANFA_MERGESORT_H
//归并排序
class MergeSort :public BaseSort
{
public:
    //自顶向下的归并排序
    virtual void sort(double *a, int size);
    //自底向上的归并排序
    static void sortBU(double *a, int size);
    //原地合并
    static void merge(double *a, int lo, int mid, int hi);
    static void sort(double *a, int lo, int hi);
};
#endif //SUANFA_MERGESORT_H
