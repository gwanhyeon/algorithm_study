//
//  10451(순열사이클).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
int map[1001];
bool check[1001];
void dfs(int v){
    if(check[v]){
        return;
    }
    check[v] =true;
    dfs(map[v]);
}
int main(void){
    
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        for(int i=1; i<=n; i++){
            cin >> map[i];           // map value input
            check[i] = false;        // map에 값 넣어주고 false 값
        }
        int ans = 0;
        
        for(int i=1; i<=n; i++){
            if(check[i] == false){
            dfs(i);
            ans++;
            }
        }
        cout << ans << "\n";
        
    }
    return 0;
}
