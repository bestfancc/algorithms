/**
 * User: bestfancc
 * Email：bestfancc@gmail.com
 * Date: 2018/11/20
 */
#include <iostream>
#include "Header/Comparable.h"
    Comparable::Comparable(double v) {
        this->v = v;
    }
    int Comparable::compareTo(double w) {
        if(this->v < w) return -1;
        if(this->v == w) return 0;
        if(this->v > w) return 1;
    }


