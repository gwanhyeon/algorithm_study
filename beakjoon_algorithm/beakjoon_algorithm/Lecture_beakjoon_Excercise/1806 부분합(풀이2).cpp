//
//  1806 부분합(풀이2).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int main(void){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n,s;
    vector<int> v;
    cin >> n >> s;
    
    for(int i=0; i<n; i++){
        int num=0;
        cin >> num;
        v.push_back(num);
    }
    // Two Point to Point
    int left = 0;
    int right = 0;
    int sum= v[0];
    int min = n+1;
    while(right < n && left <= right){
        
        //오른쪽 포인터 으로 진행한다.
        if(sum < s){
            right += 1;
            sum += v[right];
        
        }else if(sum == s){
            if(right-left+1 < min){
                min = right-left+1;
            }
            right += 1;
            sum += v[right];
            
       // 왼쪽 포인터 으로 진행한다.
        }else if(sum > s){
            if(right-left+1 < min){
                min = right-left+1;
            }
            sum -=v[left];
            left++;
        }
    }
    if(min > n){
        min = 0;
    }
    cout << min << '\n';
    return 0;
}
