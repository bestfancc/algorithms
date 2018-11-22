/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */

#include <iostream>
#include <algorithm>
#include "Header/BinarySearch.h"
using namespace std;

    int BinarySearch::binarySearchRank(double key, double a[],int size) {

        for(int i;i < size;i++) {
            cout<<a[i]<<endl;
        }
        int lo = 0;
        int hi = size;
        while (lo <= hi) {
            int mid = (int)(lo + (hi - lo)/2);
            if (key < a[mid]) {
                hi = mid - 1;
            }
            else if (key > a[mid]) {
                lo = mid +1;
            }
            else {
                return mid;
            }
        }
        return -1;
    }
    void BinarySearch::binarySearch() {
        double a[] = {1.1,5.2,6.4,2.1,2.0,3.2,9.9,66.5,32.4};
        int size = sizeof(a)/ sizeof(a[0]);
        sort(a,a+size);
        double value;
        cin>>value;
        int key = BinarySearch::binarySearchRank(value, a, size);
        if(key < 0) {
            cout<<"not found "<<value<<" in the array!"<<endl;
        } else{
            cout<<"found it in array,the key of "<<value<<" is : "<<key<<" !"<<endl;
        }
    }



