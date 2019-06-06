//
//  test.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 28/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
//float function(int *array);

double function(double );


int main(void){
    char arr[3][3] = {0,};
    double num = 0;
    double *ptr = &num;
    double **ptr1 = &ptr;
    
    
    printf("%lf %lf",*ptr,**ptr1);
    for(int i=0; i<3; i++){
        
        for(int j=0; j<3; j++){
            printf("array[%d][%d]: %p\n", i , j, &arr[i][j]);
            
        }
    }
    printf("%p",arr[1]);
    printf("%p",arr[2]);
    printf("%d",arr[1][0]);
    return 0;
}
