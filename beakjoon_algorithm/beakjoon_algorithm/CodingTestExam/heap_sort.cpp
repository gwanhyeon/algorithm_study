//
//  heap_sort.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>

int number = 10;
int arr[10] = {4,5,2,1,6,1,3,7,9,10};
int main(void){
    
    // 전체 트리구조를 힙 구조로 변경하자
    for(int i=0; i<number; i++){
        int c = i;
    // 내부적으로 부모와 자식간의 힙구조로 변경하는 구간
    // root 를 구하는 공식 ( c - 1) / 2;
        
        do{
            int root = (c -1) / 2;
            if(arr[root] < arr[c]){
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
            }
            c = root;
        }while(c != 0);
    }
    
    // 루트랑 값 변경 자식이랑
    for(int i= number-1; i >= 0; i--){
        
        int temp = arr[i];
        arr[i] = arr[0];
        arr[0] = temp;
        
        int root =0;
        int c = 1;
        do {
            c = (2 * root) + 1;
            // 자식중에 더 큰값 찾기
            if(arr[c] < arr[c+1] && c < i -1){
                c++;
            }
            // 루트보다 자식이 더 크다면 교환
            if(arr[root] < arr[c] && c < i){
                int temp = arr[root];
                arr[root] = arr[c];
                arr[c] = temp;
                
            }
            root = c;
        }while(c < i);
    }
    for(int i=0; i < number; i++){
        printf("%d",arr[i]);
    }

    
}
