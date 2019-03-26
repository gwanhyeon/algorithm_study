//
//  fibonachi(2747).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 26/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
int arr[101];

int fibo(int n){
    if(n == 1){
        return 1;
    }else if(n == 2){
        return 1;
    }
    return arr[n] = fibo(n-1) + fibo(n-2);
    
}
int main(void){
    int n;
    cin >> n;
    
    int result = fibo(n);
    cout << result;
    
    return 0;
}
