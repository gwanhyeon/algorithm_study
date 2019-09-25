//
//  1,2,3더하기 recursive.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//  3^n

#include <stdio.h>
#include <iostream>
using namespace std;

int recursive(int sum, int goal){
    
    // 불가능한 경우
    if(sum > goal){
        return 0;
    }
    // 가능한 경우
    if(sum == goal){
        return 1;
    }
    // 재귀호출
    int count =0;
    for(int i=1; i<=3; i++){
        count += recursive(sum+i,goal);
    }
    return count;
    
    
    
}


int main(void){
    
    int t;
    cin >> t;
    while(t--){
        
        int n;
        cin >> n;
        cout << recursive(0,n) << '\n';
    }
    return 0;
}
