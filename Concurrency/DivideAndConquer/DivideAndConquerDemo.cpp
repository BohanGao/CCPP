//
// Created by Bohan Gao on 9/14/20.
//

#include <future>

#include "DivideAndConquerDemo.h"

void DivideAndConquerDemo::test() {
    unsigned long long total = getSum(0, 1000000000, 0);
    printf("Sum is %lld.\n", total);
}

unsigned long long DivideAndConquerDemo::getSum(int low, int high, int depth) {
    if(depth>3){
        unsigned long long sum = 0;
        for(auto i=low;i<=high; i++){
            sum+=i;
        }
        return sum;
    } else {
        auto mid = (low+high)/2;
        auto left_sum = std::async(std::launch::async, getSum, low, mid, depth+1);
        auto right_sum = getSum(mid+1, high, depth+1);
        return left_sum.get()+right_sum;
    }
}
