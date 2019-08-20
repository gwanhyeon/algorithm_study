//
//  2178 미로찾기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int map[201][201];
int check[201][201];
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int n,m;

void bfs(int x,int y){
    queue<pair<int,int>> q;
    check[x][y] = true;
    q.push({x,y});
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx == n && my == m){
                break;
            }
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(map[mx][my] == 1 && check[mx][my] == 0){
                    map[mx][my] = map[dx][dy]+1;
                    check[mx][my] = true;
                    q.push({mx,my});
                    
                }
            }
        }
    }

    
}

int main(void){
    
    scanf("%d %d",&n,&m);
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
        }
    }
    bfs(0,0);
    
    cout << map[n-1][m-1] << '\n';
    
    return 0;
}
