/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "Header/HeapSort.h"
#include <iostream>
using namespace std;

//堆排序
void HeapSort::sink(double *a, int size, int k) {
    while (2*k+1 <= size) {
        int j = 2*k+1;
        if(*(a+j) == '\0') break;
        if(j < size && less(*(a+j),*(a+j+1))) j++;
        if(*(a+j) == '\0') break;
        if(!less(*(a+k),*(a+j))) break;
        exch(a,k,j);
        k = j;
    }
}
void HeapSort::sort(double *a,int size) {
    for (int k = size/2; k >= 0 ; k--) {
        sink(a,size,k);
    }
    while (size > 0) {
        exch(a,0,--size);
        sink(a,size-1,0);
    }
}