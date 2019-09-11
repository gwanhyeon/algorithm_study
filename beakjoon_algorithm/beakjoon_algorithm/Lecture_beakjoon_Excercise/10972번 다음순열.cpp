//
//  10972번 순열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void swap(int *arr1, int *arr2){
    
    int temp = *arr1;
    *arr1 = *arr2;
    *arr2 = temp;
    
    
}
bool nxt_permutation(vector<int> &arr,int n){
    
    int i = n-1;
    while(i > 0 && arr[i-1] >= arr[i]){
        i -= 1;
    }
    if(i <= 0){
        return false;
    }
    int j = n-1;
    while(arr[j] <= arr[i-1]){
        j -= 1;
    }
    swap(arr[i-1],arr[j]);
    j = n-1;
    while(i < j){
        swap(arr[i],arr[j]);
        i += 1;
        j -= 1;
    }
    return true;
    
}
int main(void){
    
    int n;
    cin >> n;
    vector<int> v(n);
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    
    if(nxt_permutation(v,n)){
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
    }else {
        cout << "-1" << '\n';
    }
    
    return 0;
}
