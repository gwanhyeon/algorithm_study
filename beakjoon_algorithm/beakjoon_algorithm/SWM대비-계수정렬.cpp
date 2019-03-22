//
//  SWM대비-계수정렬.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int arr[30] = {1, 3, 2, 4, 3, 2, 5, 3, 1, 2,
        3, 4, 4, 3, 5, 1, 2, 3, 5, 2,
        3, 1, 4, 3, 5, 1, 2, 1, 1, 1};
    // 총 30개의 배열
    int sorted[6];
    int size = sizeof(arr) / sizeof(int);
    
    
    // init
    for(int i=1; i<=5; i++){
        sorted[i] = 0;
    }
    // 값이 맞으면 => 그해당값에 대한 value++
    for(int i=0; i<size; i++){
        sorted[arr[i]]++;
    }
    for(int i=1; i<=5; i++){
        if(sorted[i] != 0){
            for(int j=0; j<sorted[i]; j++){
                cout << i;
            }
        }
    }
    
    return 0;
    
}
