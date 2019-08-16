//
//  2003 수들의합.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 17/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> v;
int n,m;

int main(void){
    
    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        int s;
        cin >> s;
        v.push_back(s);
    }
    int sum;
    int ans=0;
    for(int i=0; i<n; i++){
        sum =0;
        for(int j=i; j<n; j++){
            sum += v[j];
            if(sum == m){
                ans += 1;
            }
            if(sum > m){
                break;
            }
        }
    }
    cout << ans;
    return 0;
    
}
