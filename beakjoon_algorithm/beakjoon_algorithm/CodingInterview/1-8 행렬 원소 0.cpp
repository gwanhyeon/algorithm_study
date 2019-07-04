//
//  1-8 행렬 원소 0.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int arr[4][4] = {
        {1,2,3,3},
        {0,1,6,4},
        {3,8,2,9},
        {1,2,3,3}
    };
    int arr_copy[4][4];
    int col_size= sizeof(arr[0]) / sizeof(int);
    int row_size = sizeof(arr) / sizeof(arr[0]);
    memcpy(arr_copy, arr, sizeof(arr)); // memcpy(arr_copy, arr, sizeof(int) * sizeof(arr));

    // 1) 행, 열 반복문 시작
    for(int i=0; i<row_size; i++){
        for(int j=0; j<col_size; j++){
            // 발견한 해당하는 i와 j
            if(arr[i][j] == 0){
                int row = i;
                 int col = j;
                int k= 0;
                while(k < row_size){
                        arr_copy[row][k] = 0;
                        k++;
                }
                k=0;
                while(k < col_size){
                        arr_copy[k][col] = 0;
                        k++;
                }
                break;
            }
        }
    }
    for(int i=0; i<row_size; i++){
        for(int j=0; j<col_size; j++){
            cout << arr_copy[i][j];
        }
        cout << '\n';
    }
    return 0;
}
