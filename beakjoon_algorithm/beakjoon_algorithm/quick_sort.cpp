//
//  quick_sort.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int partition(int arr[],int start,int end){
    // 피봇 정의
    int pivot = arr[(start+end)/2];
    // 처음부터 끝!
    while(start <= end){
        
        // 처음부터 중간
        while(arr[start] < pivot){
            start++;  // 계속 진행
        }
        // 중간부터 끝
        while(arr[end] > pivot){
            end--;      // 계속진행
        }
        
        if(start <=end){
            // swap
            int temp = arr[start];
            arr[start] = arr[end];
            arr[end] = temp;
            // 스왑한상태이니까 한번 start,end 계속 진행
            start++;
            end--;
            
        }
    }
    return start;
}
void quick_sort(int arr[],int start,int end){
    // 1) 파티션 함수 호출
    int part2 = partition(arr,start,end);
    
    // 2) 파티션함수에서 얻은 값을 가지고 재귀호출
    if(start < part2 -1){
        quick_sort(arr,start,part2-1);
    }
    if(part2 < end){
        quick_sort(arr,part2,end);
    }
    
}
int main(void){
    int arr[5] = {2,9,3,4,6};
    int size = sizeof(arr) / sizeof(int);
    
    quick_sort(arr,0,size);
    
    for(int i=0; i<size;i++){
        cout << arr[i];
    }

}
