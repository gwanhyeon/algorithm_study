//
//  1920 수찾기(이분탐색).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
// keyword : 이분탐색은 정렬 / 범위 중간을 나눈값을 갱신하면서 계속진행

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

int a[100005];
int n;
using namespace std;
int big_search(int target,int len){
    int start = 0;
    int end = len-1;
    
    while(start <= end){
        int mid =(start + end) / 2;
        
        if(a[mid] < target){
            start = mid+1;
        }else if(a[mid] > target){
            end = mid-1;
            
        }else {
            return mid;
        }
    }
    return -1;
    
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> a[i];
    }
    int m = 0;
    cin >> m;
    sort(a,a+n);        // 정렬하고 진행하여야함
    while(m--){
        int x;
        cin >>x;
        if(big_search(x,n) == -1){
            cout << "0\n";
        }else {
            cout << "1\n";
        }
    }
    
    
    return 0;
    
    
}
