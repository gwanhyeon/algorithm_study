//
//  14888 연산자끼워넣기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> cal;
vector<int> ans;
void recursive(vector<int> v, int sum, int cnt){
    // 1. 정답
    if(cnt == n){
        ans.push_back(sum);
        return;
    }
    // 2. 비정답
    if(cnt > n){
        return;
    }
    // 3. 재귀 조건 2개
   
//    for(int i=cnt; i<v.size(); i++){
        // 덧셈
    for(int i=0; i<=cal.size(); i++){
        if(cal[i] == 0){
            recursive(v,sum+v[cnt], cnt+1);
            
            // 뺄셈
        }else if(cal[i] == 1){
            recursive(v,sum-v[cnt], cnt+1);
        
            // 곱셈
        }else if(cal[i] == 2){
            recursive(v,sum*v[cnt], cnt+1);
        
            // 나눗셈
        }else {
            recursive(v,sum/v[cnt],cnt+1);
        }
    }

//    }
}

int main(void){
    
    cin >> n;
    vector<int> v(n);
    
    
    for(int i=0;i<n; i++){
        cin >> v[i];
    }

    // 0 덧셈 1 뺄셈 2 나눗셈 3곱셈
    for(int i=0; i<4; i++){
        int a;
        cin >> a;
        for(int j=0; j<a; j++){
            cal.push_back(i);
        }
    }
    sort(v.begin(), v.end());
    recursive(v,v[0],1);
    
    cout << *min_element(ans.begin(), ans.end())<< '\n';
    cout << *max_element(ans.begin(), ans.end()) << '\n';

}
