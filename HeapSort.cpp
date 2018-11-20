/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "Header/HeapSort.h"

//堆排序
void HeapSort::sink(double *a, int size, int k) {
    while (2*k <= size) {
        int j = 2*k;
        if(j < size && less(*(a+j),*(a+j+1))) j++;
        if(!less(*(a+k),*(a+j))) break;
        exch(a,k,j);
        show(a,size);
        k = j;
    }
}
void HeapSort::sort(double *a,int size) {
    for (int k = size/2; k >= 1 ; k--) {
        sink(a,size,k-1);
    }
    while (size > 1) {
        exch(a,1,--size);
        show(a,size);
        sink(a,size,1);
    }
}