/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include "Header/InsertionSort.h"

void InsertionSort::sort(double *a, int size) {
    for (int i = 1; i < size; ++i) {
        for (int j = i; j > 0; j--) {
            if(less(*(a + j),*(a + j - 1))) {
                exch(a,j,j - 1);
            }
        }
    }
}

