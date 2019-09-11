//
//  10973번 이전순열.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
bool previous_permutation(vector<int> &arr, int n){
    int i = n-1;
    while(i > 0 && arr[i-1] <= arr[i]){
        i--;
    }
    if(i <= 0){
        return false;
    }
    int j = n-1;
    
    while(arr[i-1] <= arr[j]){
        j--;
    }
    swap(arr[i-1], arr[j]);
    j = n-1;
    
    while(i < j){
        swap(arr[i], arr[j]);
        i++;
        j--;
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
    if(previous_permutation(v,n)){
        for(int i=0; i<n; i++){
            cout << v[i] << ' ';
        }
    }else {
        cout << "-1" << '\n';
    }
    cout << '\n';
    
    
    return 0;
}
