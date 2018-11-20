/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "BaseSort.h"
#ifndef SUANFA_SHELLSORT_H
#define SUANFA_SHELLSORT_H
//希尔排序
class ShellSort :public BaseSort
{
public:
    virtual void sort(double *a,int size);
};
#endif //SUANFA_SHELLSORT_H
