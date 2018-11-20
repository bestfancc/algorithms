/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */

#include <iostream>
#include "Header/SelectSort.h"
using namespace std;

 void SelectSort::sort(double *a,int size) {
    for (int i = 0; i < size - 1; i++) {
        int minKey = i;
        for (int j = i+1; j < size; j++) {
            if(less(*(a + j),*(a + minKey))) {
                minKey = j;
            }
        }
        exch(a,i,minKey);
    }
}