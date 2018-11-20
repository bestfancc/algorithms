/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "Header/MergeSort.h"
//归并排序
//自顶向下的归并排序
void MergeSort::sort(double *a, int size) {
    sort(a,0,size - 1);
}
//自底向上的归并排序
void MergeSort::sortBU(double *a, int size) {
    double aux[10];
    for (int i = 1; i < size; i = i + i) {
        for (int j = 0; j < size - i; j = i + i + j) {
            int min = ((j+i+i-1) > (size-1)) ? size-1: (j+i+i-1);
            merge(a,j,j+i-1,min);
        }
    }
}
//原地合并
void MergeSort::merge(double *a, int lo, int mid, int hi) {
    double aux[10];
    int i = lo,j = mid + 1;
    for (int k = lo; k <= hi; ++k) {
        aux[k] = *(a+k);
    }
    for (int t = lo; t <= hi; ++t) {
        if (i > mid) {  //第一段数组取完了
            *(a+t) = aux[j++];
        } else if (j > hi) {  //第二段数组取完了
            *(a+t) = aux[i++];
        } else if (less(aux[j],aux[i])) {
            *(a+t) = aux[j++];
        } else {
            *(a+t) = aux[i++];
        }
    }
}
void MergeSort::sort(double *a, int lo, int hi) {
    if(lo >= hi) {
        return;
    }
    int mid = lo + (hi - lo)/2;
    sort(a,lo,mid);
    sort(a,mid + 1,hi);
    merge(a,lo,mid,hi);
}