//
//  SWM대비-그리디알고리즘2(11339ATM).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


// ATM 1-N 사람 줄
// 줄 서는 순서에 따라 기다리느 시간
//줄을 서 있는 사람의 수 N과 각 사람이 돈을 인출하는데 걸리는 시간 Pi가 주어졌을 때, 각 사람이 돈을 인출하는데 필요한 시간의 합의 최솟값을 구하는 프로그램을 작성


#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(void){
    int n;
    
    int sum=0;
    cin >> n;
    int arr[n];
    
    for(int i=0; i<n; i++){
        
        cin >> arr[i];

    }
    // 중요!!!!!!!!! sort를 통해 최소값으로 정렬한후 풀어주면 된다.!
    sort(arr,arr+n);
    for(int i=0; i<n; i++){
        for(int j=0; j<=i; j++){
            sum += arr[j];
        }
    }
    cout << sum;
    
    return 0;
    
    
}
