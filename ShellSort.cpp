/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "Header/ShellSort.h"

//希尔排序
void ShellSort::sort(double *a,int size) {
    int h = 1;
    while (h < size / 3) {
        h = 3 * h + 1;
    }
    while (h >= 1) {
        for (int i = h; i < size; ++i) {
            for (int j = i; j >= h  ;j -= h) {
                if(less(*(a+j),*(a+j-h))) {
                    exch(a,j,j-h);
                }
            }
        }
        h = h/3;
    }
}