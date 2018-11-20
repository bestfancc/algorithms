/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */

#ifndef SUANFA_BASESORT_H
#define SUANFA_BASESORT_H
//排序基类
class BaseSort
{
public:
    typedef void (BaseSort::*parentSort)();
    static bool isSorted(double a[],int size);
    static int less(double v, double w);
    static void exch(double *a,int i, int j);
    static void show(double *a,int size);
    virtual void sort(double *a,int size);
    void run();

private:
    parentSort pSort;
};
#endif //SUANFA_BASESORT_H
