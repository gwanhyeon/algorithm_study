//  4673(셀프넘버).cpp
//  beakjoon_algorithm
//  Created by kgh on 07/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//  앞에 부분이 생성자 n(75) =  75 + 7 + 5 = 87
#include <stdio.h>
#include <iostream>
#define N 10001
bool arr[N];


using namespace std;

int solution(int n){
    // 자기자신을 더해준다
    int sum = n;
    while(1){
        if(n == 0){
            break; // 종료
        }
        sum += n % 10; // 나머지 1의 자리수
        n = n/10;       // 한자리씩 없애기
    }
    return sum;
    
}
int main(void){
    
    // solution
    for(int i=1; i<N; i++){
        int idx = solution(i);
        
        // 셀프넘버가 아닌것들이니까
        if(idx < N){
            arr[idx] = true;
        }
    }
    // printf
    for(int i=1; i<N; i++){
        if(!arr[i]){
            cout << i << endl;
        }
    }
    return 0;
}
