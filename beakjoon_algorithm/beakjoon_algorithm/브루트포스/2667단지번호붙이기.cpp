//
//  2667단지번호붙이기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 27/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int map[25][25];
int check[25][25];
int dist[25*25];
int n;

using namespace std;
void bfs(int x,int y,int cnt){
    queue<pair<int,int>> q;
    check[x][y] = cnt;
    q.push(make_pair(x,y));
    
    while(!q.empty()){
        int dx=q.front().first;
        int dy=q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx+dir[i][0];
            int my = dy+dir[i][1];
            
            if(mx >= 0 && mx < n && my >=0 && my < n){
                if(check[mx][my] == 0 && map[mx][my] == 1){
                    q.push(make_pair(mx,my));
                    check[mx][my] = cnt;
                }
            }
        }
    }
}
int main(void){
    
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    memset(check,0,sizeof(check));

    int cnt = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(check[i][j] == 0 && map[i][j] == 1){
                bfs(i,j,++cnt);
            }
        }
    }
    cout << cnt << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            dist[check[i][j]] += 1;
        }
    }
    sort(dist+1, dist+cnt+1);
    
    for(int i=1; i<=cnt; i++){
        cout << dist[i] << '\n';
    }
    
    return 0;
}
