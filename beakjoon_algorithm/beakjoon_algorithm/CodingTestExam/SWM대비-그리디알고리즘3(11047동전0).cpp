//
//  SWM대비-그리디알고리즘2(11047동전0).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int n = 0;      // 종류
int value = 0;


int main(void){
    /*
     준규 동전 총 N종류, 동전 많음
     동전을 적절히 사용해서 그 가치의 합을 K
     이때 필요한 동전 개수의 최솟값을 구하는 프로그램을 작성하시오.
     */
    
    cin >> n >> value;
    int arr[n];
    int result=0;
    // input
    for(int i=0; i<n; i++){
        cin >> arr[i];
        
    }
    // ** 참고 !!!!!!!! value를 나누는것을 잘생각했어야함 a[i]에다가 값을 / value로 나누고 있던 실수가 있었음.
    for(int i=n-1; i>=0; i--){
        result += (value / arr[i]);
        value = value % arr[i];
    }
    
    cout << result;
    
    
    return 0;
}
