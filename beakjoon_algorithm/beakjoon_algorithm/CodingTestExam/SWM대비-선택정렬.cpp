//
//  SWM대비-선택정렬.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int number =10;
int arr[10] = {3,4,5,6,1,2,3,4,7,10};

int main(void){
    
    int min, temp, index = 0;
    for(int i=0; i<number; i++){
        min = 99999;
        for(int j=i; j<number; j++){
            if(min > arr[j]){
                min = arr[j];
                index = j;
            }
        }
        temp = arr[i];
        arr[i] = arr[index];
        arr[index] = temp;
    }
    for(int i=0; i<number; i++){
        cout << arr[i];
    }
}
