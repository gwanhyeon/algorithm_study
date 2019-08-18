//
//  bitcalculation.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int main(void){
    int arr1[5] = {9,20,28,18,11};
    int arr2[5] = {30,1,21,17,28};
    int n = 5;
    vector<string> ans(n);
    for(int i=0; i<n; i++){
        arr1[i] |= arr2[i];
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[i] += (arr1[i] % 2 == 1 ? "#" : " ") ;
            arr1[i] >>= 1;
        }
    }
    
    for(int i=0; i<n; i++){
        cout << ans[i];
    }
    return 0;
}
