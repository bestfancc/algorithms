/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "Header/QuickSort.h"
#include <iostream>
#include <algorithm>
using namespace std;

//快速排序
void QuickSort::sort(double *a, int size) {
    srand(time(0));
    std::random_shuffle(a, a + size);
    QuickSort::sort(a,0,size-1);
}
void QuickSort::sort(double *a, int lo, int hi) {
    if(lo >= hi) {
        return;
    }
    int j = QuickSort::partition(a,lo,hi);
    QuickSort::sort(a,lo,j-1);
    QuickSort::sort(a,j+1,hi);
}
int QuickSort::partition(double *a, int lo, int hi) {
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