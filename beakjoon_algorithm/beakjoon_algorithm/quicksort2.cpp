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
    int pivot = start;
    int i = start + 1;
    int j = end;
    int temp;
    
    if(start >= end){
        return;
    }
    
    while(i <= j){
        // 왼 -> 오 작을경우
        while(arr[i] <= arr[pivot]){
            i++;
        }
        while(arr[j] >= arr[pivot] && j > start){
            j--;
        }
        // 현재 엇갈린상태면 키값과 교체
        
        if(i > j){
            temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        }
        // 엇갈리지 않았으면
        else {
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


//
//
//#include <stdio.h>
//#include <iostream>
//using namespace std;
//
//int number = 10;
//int arr[10] = {2,3,5,6,1,6,5,8,3,2};
//
//// return X
//void quicksort(int *arr, int start , int end){
//    // quick sort => pivot
//    int pivot = start; // 맨앞에 있는것을 피봇으로 본다.
//    int i = start + 1;
//    int j = end;
//    int temp;
//    // 1. 첫번째 조건 start점이 end점보다 크다? 이러면 => 프로그램이 종료될 수 밖에 없어. 로직이 안맞아.
//    if(start >= end){
//        return;
//    }
//    
//    // 2. i 값과 j 값에 대한 비교인데 , i <= j 일때만! 퀵소트가 성립을 해요. 겹치는것 포함하기때문에
//    // = 들어간다.
//    while(i <= j){
//        // 왼쪽 진행 경우 ->  값이 작으면 그대로 진행 swap X-> 피봇보다 값이 커야한다-> swap O
//        
//        while(arr[i] <= arr[pivot]){
//            i++;
//        }
//        // 오른쪽에서 진행 경우 -> 값이 크면 그대로 진행.Swap X -> 피봇보다 값이 작아야한다.-> swap O
//        while(arr[j] >= arr[pivot] && j > pivot){
//            j--;
//        }
//        // 엇갈린상태면 교체
//        if(i > j){
//            temp = arr[j];
//            arr[j] = arr[pivot];
//            arr[pivot] = temp;
//            
//        }
//        // 엇갈리지 않고 값 단지 바꿔줄때.
//        else{
//            temp = arr[i];
//            arr[i] = arr[j];
//            arr[j] = temp;
//            
//        }
//        
//        
//    }
//    quicksort(arr,start,j-1);
//    quicksort(arr,j+1,end);
//    
//    
//}
//int main(void){
//    // 기존에 가지고 있는 배열에 대한 상태를 넘겨주는것.
//    quicksort(arr,0,number);
//    
//    for(int i=0; i<number; i++){
//        cout << arr[i];
//    }
//    return 0;
//}
