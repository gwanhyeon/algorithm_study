//
//  merge-sort-swm.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int number = 8;
int sorted[8];
void merge(int *arr,int m,int middle, int n){
    int i = m;
    int j = middle + 1;
    int k = m;
    
    // 작은 순서대로 배열 삽입.
    while(i <= middle && j <= n){
        if(arr[i] <= arr[j]){
            sorted[k] = arr[i];
            i++;
        }else{
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    // 남은 데이터도 삽입
    if(i > middle){
        for(int t = j; t <=n; t++){
            sorted[k]=arr[t];
            k++;
        }
    }else{
        for(int t=i; t<=m; t++){
            sorted[k] = arr[t];
        }
            
    }
    
    // 정렬된 배열을 삽입
    for(int t = m; t <=n; t++){
        arr[t] = sorted[t];
    }
    
}

// 1. mergesort
void mergeSort(int *arr,int m, int n){
    
    // m < n 조건 충족시
    if(m < n){
        //middle = m+n / 2;
        int middle = (m + n) / 2;
        //정렬후

        mergeSort(arr,m,middle);
        mergeSort(arr,middle+1,n);
        // 최종 합병
        merge(arr,m,middle,n);
    }
    
}

int main(void){
    int arr[8]= {4,1,2,3,6,8,3,5};
    mergeSort(arr, 0 , number-1);
    
    for(int i=0; i<number; i++){
        cout << arr[i];
    }
    
    
    
}
