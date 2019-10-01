//
//  NM시리즈(2).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
// 오른차순이므로 타겟값이하는 쳐다보지도 않는다는것을 확인
vector<int> v;
int check[10];
void go(int index, int cnt, int n, int m){
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
    }
    for(int i=index; i<=n; i++){
        if(check[i] == 1){
            continue;
        }
        check[i] = 1;
        v.push_back(i);
        go(i,cnt+1, n, m);
        check[i] = 0;
        v.pop_back();
    }
    
    
    
}

int main(void){
    int n,m = 0;
    memset(check,0,sizeof(check));
    cin >> n >> m;
    go(1,0,n,m);
    
    
}
