//
//  SWM대비-합병정렬.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


// 분할정복법 , 퀵정렬과 시간복잡도 O(N * logN)

// 병합정렬은 최악의 경우에도 O(N*logN)

// 2개의 메소드 merge, mergesort

#include <stdio.h>
int number = 8;
int size;
int sorted[8];
int count=0;

void merge(int *a, int m, int middle, int n){
    int i = m;
    int j = middle + 1;
    int k = m;
    
    while(i <= middle && j <= n){
        if(a[i] <= a[j]){
            sorted[k] = a[i];
            i++;
        }else{
            sorted[k] = a[j];
            j++;
        }
        k++;
    }
    
    if(i > middle){
        for(int t=j; t <= n; t++){
            sorted[k] = a[t];
            k++;
        }
    }else{
        for(int t = i; t<= middle; t++){
            sorted[k] = a[t];
            k++;
        }
    }
    
    for(int t = m; t <= n; i++){
        a[t] = sorted[t];
    }
}

void mergeSort(int *a, int m, int n){
    if(m < n){
        int middle = (m + n) / 2;
        mergeSort(a, m, middle);
        mergeSort(a, middle + 1, n);
        merge(a, m, middle, n);
    }
}

int main(void) {
    int arr[number] = {7, 6, 5, 8, 3, 5, 9, 1};
    
    
    
    
}
