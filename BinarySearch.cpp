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
        int lo = 0;
        int hi = size;
        int count = 0;
        while (lo <= hi) {
            std::cout<<"查找了"<<++count<<"次"<<endl;
            int mid = lo + (hi - lo)/2;
            if (key < a[mid]) {
                hi = mid - 1;
            }
            else if (key > a[mid]) {
                lo = mid +1;
            }else{
                return mid;
            }
        }
        return -1;
    }
    void BinarySearch::binarySearch() {
        double a[] = {1.1,5.2,6.4,2.1,2.0,3.2,9.9,66.5,32.4};
        int size = sizeof(a)/ sizeof(a[0]);
        sort(a,a+size);
        std::cout<<"长度为9的double数组如下"<<endl;
        for(int i = 0;i < size;i++) {
            std::cout<<a[i]<<" ";
        }
        std::cout<<endl;
        std::cout<<"请输入你要查找的值"<<endl;
        double value;
        cin>>value;
        int key = BinarySearch::binarySearchRank(value, a, size);
        if(key < 0) {

            cout<<"not found "<<value<<" in the array!"<<endl;
        } else{
            cout<<"found it in array,the key of "<<value<<" is : "<<key<<" !"<<endl;
        }
    }



