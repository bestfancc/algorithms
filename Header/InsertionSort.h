/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "BaseSort.h"
#ifndef SUANFA_INSERTIONSORT_H
#define SUANFA_INSERTIONSORT_H
//插入排序
class InsertionSort :public BaseSort
{
public:
    virtual void sort(double *a, int size);
};
#endif //SUANFA_INSERTIONSORT_H
