//
//  merge_sort.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>

int number = 8;
int sorted[8];

void merge(int arr[], int m, int middle, int n){
    
    int i = m;
    int j = middle + 1;
    int k = m;
    
    // 1. 작은 순서대로 배열에 삽입
    while(i <= middle && j <= n){
        // i 보다 j가 작을경우 값이 제대로 확인된것이므로 sorted 함수에 값을 넣어준다
        if(arr[i] <= arr[j]){
            sorted[k] = arr[i];
            i++;
        }else {
            sorted[k] = arr[j];
            j++;
        }
        k++;
    }
    // 2. 남은 데이터 삽입
    // i가 먼저 끝났을경우
    if(i > middle){
        for(int t=j; t <= n; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    // j가 먼저 끝났을 경우
    else {
        for(int t=i; t<= middle; t++){
            sorted[k] = arr[t];
            k++;
        }
    }
    //3. 정렬된 배열로 삽입
    for(int t=m; t <=n; t++){
        arr[t] = sorted[t];
    }
    
}

void mergeSort(int arr[], int m, int n){
    if(m < n){
        int middle = (m+n) / 2;
        mergeSort(arr,m,middle);
        mergeSort(arr,middle+1,n);
        merge(arr,m,middle,n);
    }
}

int main(void){
    
    int arr[8] = {7,6,5,8,3,5,9,1};
    mergeSort(arr,0 , number-1);
    
    for(int i=0; i<8; i++){
        printf("%d ",arr[i]);
        
    }
}
