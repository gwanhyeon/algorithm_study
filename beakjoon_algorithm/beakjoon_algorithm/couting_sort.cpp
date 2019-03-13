//
//  couting_sort.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
// 계수정렬문제


#include <stdio.h>
#include <iostream>
using namespace std;

int main(void){
    
    int temp;
    int count[5];
    int array[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
    
    // 초기화 해주기
    for(int i=0; i<5; i++){
        count[i] = 0;
    }
    // Index init i = 0 에서 부터 시작하기 때문에 array[i] - 1 으로 처리 해준다.
    for(int i=0; i<30; i++){
        count[array[i] - 1]++;
    }
    
    // count에 저장된 값에 따라서 count[i] = 0이 아닐 조건을 처리한다음에
    // j부터 시작해서 count[i]에 저장된 값들의 개수 만큼 처리해준다
    // 예제 count[0] = 4 일경우 4444형식으로 출력하기 위한 내부에 for문
    for(int i=0; i<5; i++){
        if(count[i] != 0){
            for(int j=0; j<count[i]; j++){
                printf("%d ", i + 1);
            }
        }
    }
}
