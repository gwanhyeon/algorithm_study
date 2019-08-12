//
//  9095 1,2,3 더하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int go(int sum,int target){
    // 불가능한 경우
    
    if(sum > target){
        return 0;
    }
    // 가능한 경우
    if(sum == target){
        return 1;
    }
    // 진행하는 경우
    int num = 0;
    for(int i=1; i<=3; i++){
        cout << "go(" << sum+i << "," << target <<
        ")"<< '\n';
        num += go(sum+i,target);
    }
    
    return num;
}
int main(void){

    int t;
    cin >> t;
    int target = 0;
    while(t--){
        int result = 0;
        cin >> target;
        result = go(0,target);
        cout << result << '\n';
    }
    
    return 0;
}
