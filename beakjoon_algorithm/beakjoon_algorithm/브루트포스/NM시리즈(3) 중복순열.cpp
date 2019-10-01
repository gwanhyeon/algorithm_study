//
//  NM시리즈(3).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
// 중복순열
vector<int> v;
int n,m;

void go(int cnt){
    if(cnt == m){
        for(int i=0; i<v.size(); i++){
            cout << v[i] << ' ';
        }
        cout << '\n';
        return;
    }
    for(int i=0; i<n; i++){
        v.push_back(i+1);
        go(cnt+1);
        v.pop_back();
    }
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    go(0);
    return 0;
}
