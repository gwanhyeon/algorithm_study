//
//  14226 이모티콘.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.

#include <stdio.h>
#include <cstring>
#include <iostream>
#include <queue>
using namespace std;

int check[2001][2001];
int main(void){
    
    int m;
    queue<pair<int,int>> q;
    cin >> m;
    memset(check,-1,sizeof(check));
    check[1][0] = 0;
    q.push({1,0});
    
    while(!q.empty()){
        int s = q.front().first;
        int c = q.front().second;
        q.pop();
        
        if(check[s][s] == -1){
            check[s][s] = check[s][c] + 1;
            q.push({s,s});
        }
        if(s+c <= m && check[s+c][c] == -1){
            check[s+c][c] = check[s][c] + 1;
            q.push({s+c,c});
        }
        if(s+c >= 0 && check[s-1][c] == -1){
            check[s-1][c] = check[s][c] + 1;
            q.push({s-1,c});
        }
    }
    int ans = -1;
    for(int i=0; i<=m; i++){
        if(check[m][i] != -1){
            if(ans == -1 || ans > check[m][i]){
                ans = check[m][i];
            }
        }
    }
    cout << ans;
    return 0;
}
