/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include <iostream>
#include "Header/Comparable.h"
#include "Header/BaseSort.h"

using namespace std;

bool BaseSort::isSorted(double a[],int size) {
    for (int i = 1; i < size; ++i) {
        if(less(a[i], a[i-1])) {
            return false;
        }
    }
    return true;
}
int BaseSort::less(double v, double w) {
    Comparable V(v);
    int result = V.compareTo(w);
    if(result >= 0) {
        return false;
    }else{
        return true;
    }
}
void BaseSort::exch(double *a,int i, int j) {
    double tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
void BaseSort::show(double *a,int size) {
    for (int i = 0; i < size; i++) {
        std::cout<<a[i]<<" ";
    }
    cout<<endl;
}
void BaseSort::sort(double *a, int size) {

}
void BaseSort::run() {
    double a[10];
    for (int i = 0; i < 10; ++i) {
        cin>>a[i];
    }
    int size = sizeof(a)/ sizeof(a[0]);
    cout<<"Before Sort：";
    BaseSort::show(a,size);
    sort(a,size);
    if(BaseSort::isSorted(a,size)) {
        cout<<"Array Is Sorted"<<endl;
    } else {
        cout<<"Array Is Not Sorted"<<endl;
    }
    cout<<"After Sort：";
    BaseSort::show(a,size);
}


