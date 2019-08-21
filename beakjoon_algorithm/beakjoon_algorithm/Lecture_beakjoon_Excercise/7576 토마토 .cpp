//
//  토마토 7576.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int check[1001][1001];
int m,n;
int dir[4][2] ={{-1,0},{1,0},{0,1},{0,-1}};
int ans[1001*1001];
int cnt;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    
    while(!q.empty()){
        int dx = x+q.front().first;
        int dy = y+q.front().second;
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == -1 && map[mx][my] == 0){
                q.push({mx,my});
                check[mx][my] = 1;
                map[mx][my] = 1;
                cnt +=1;
                }
            }
        }
    }
}

int main(void){
    
    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            check[i][j] = -1;
            cin >> map[i][j];
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(map[i][j] == 1 && check[i][j] == -1){
                bfs(i,j);
            }
        }
    }
    cout << cnt;

    return 0;
    
}
