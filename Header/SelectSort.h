/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "BaseSort.h"
#ifndef SUANFA_SELECTSORT_H
#define SUANFA_SELECTSORT_H

//选择排序
class SelectSort :public BaseSort
{
public:
    virtual void sort(double *a,int size);
};

#endif //SUANFA_SELECTSORT_H
