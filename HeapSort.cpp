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
    while (2*k+1 < size) {
        int j = 2*k+1;
        if(j < (size-1) && less(*(a+j),*(a+j+1))) j++;
        if(!less(*(a+k),*(a+j))) break;
        exch(a,k,j);
        cout<<k<<" "<<j<<endl;
        show(a,size);
        k = j;
    }
}
void HeapSort::sort(double *a,int size) {
    for (int k = size/2; k >= 0 ; k--) {
        sink(a,size,k);
        cout<<k<<endl;
    }
    while (size > 0) {
        exch(a,0,--size);
        sink(a,size,0);
    }
}