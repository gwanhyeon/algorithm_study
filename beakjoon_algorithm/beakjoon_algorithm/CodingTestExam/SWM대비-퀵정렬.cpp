//
//  SWM대비-퀵정렬.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int arr[10] = {2, 3, 4, 5, 6, 7, 1, 2, 3, 4};
int number = 10;

void quick_sort(int *arr, int start, int end){
    int temp;
    int pivot = start;
    int i = start + 1;
    int j = end;
    
    if(start >= end){
        return;
    }
    
    while(i <= j){
        while(arr[i] <= arr[pivot]){
            i++;
        }
        //**********************
        // quick 정렬 j > start 이조건 엄청 중요해!!!!!무조건 알고가 까먹을 수 있음.
        //**********************
        while(arr[j] >= arr[pivot] && j > start){
            j--;
        }
        if(i > j){
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
            
        }else{
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            
        }
    }
    quick_sort(arr,start, j-1);
    quick_sort(arr,j+1,end);
    
}

int main(void){
    
    quick_sort(arr, 0 , number-1);
    for(int i=0; i<number; i++){
        cout << arr[i];
    }
    return 0;
}
