//
//  quicksort2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

void quick_sort(int arr[],int start,int end){
    int key = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    if(start >= end){
        return;
    }
    
    while(i <= j){
        // 왼 -> 오 작을경우
        while(arr[i] <= arr[key]){
            i++;
        }
        while(arr[j] >= arr[key] && j > start){
            j--;
        }
        if(i > j){
            temp = arr[j];
            arr[j] = arr[key];
            arr[key] = temp;
        }else {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        
    }
    quick_sort(arr, start, j-1);
    quick_sort(arr,j+1, end);
    
}
int main(void){
    
    int arr[5] = {7,3,2,1,4};
    int size = sizeof(arr) / sizeof(int);
    
    quick_sort(arr,0,size-1);
    
    for(int i=0; i<size; i++){
        cout << arr[i];
    }
    
    
    
}
