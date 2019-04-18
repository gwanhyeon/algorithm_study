//
//  test.c
//  beakjoon_algorithm
//
//  Created by kgh on 15/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>

int main(void){
    
    int sum = 0;
    int i= 1;
    int cnt = 0;
    while(i < 10){
        sum += i;
        cnt++;
        i+=1;
    }
    
    printf("%d",cnt);
    
    
}
