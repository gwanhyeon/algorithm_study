//
//  SWM대비-버블정렬.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int main(void){
    int arr[10] = {3,4,5,1,3,4,6,7,10,9};
    int number = 10;
    
    for(int i=0; i<number; i++){
        for(int j=0; j<number-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    for(int i=0; i<number; i++){
        cout << arr[i];
    }
    
    return 0;
}
