//
//  2667 단지 번호 붙이기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int map[25][25];
int check[25][25];
int n;
int dir[4][2] ={{0,1},{1,0},{-1,0},{0,-1}};
int ans[25*25];

void bfs(int x,int y,int cnt){
    queue<pair<int,int>> q;
    check[x][y] = cnt;
    q.push({x,y});

    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int a = dx+dir[i][0];
            int b = dy+dir[i][1];
            
            if(a >=0 && a < n && b >=0 && b < n){
                if(check[a][b] == 0 && map[a][b] == 1){
                    check[a][b] = cnt;
                    q.push({a,b});
                }
            }
        }
    }
}

int main(void){
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] == 1 && check[i][j] == 0){
                bfs(i,j,++cnt);
            }
        }
    }
    cout << cnt << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            ans[check[i][j]] += 1;
        }
    }
    sort(ans+1, ans+cnt+1);
    
    for(int i=1; i<=cnt; i++){
        cout << ans[i] << '\n';
    }
    

    return 0;

}
