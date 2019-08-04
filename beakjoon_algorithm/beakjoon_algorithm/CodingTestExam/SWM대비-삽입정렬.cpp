//
//  SWM대비-삽입정렬.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int i,j,temp;
    int number = 10;
    int arr[10] = {2,3,4,1,5,6,3,8,10,9};

    //**********************
    // number - 1확인 꼭하자 insertion정렬
    //**********************
    for(i=0; i<number-1; i++){
        j = i;
        while(arr[j] > arr[j+1]){
            temp = arr[j];
            arr[j] = arr[j+1];
            arr[j+1] = temp;
            j--;
        }
    }
    
    for(int i=0; i<number; i++){
        cout << arr[i];
    }
    
    
    return 0;
    
}
