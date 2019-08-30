//
//  1525 퍼즐.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

int map[3][3];
int check[3][3];
int dir[4][2] = {{0,-1},{0,1},{-1,0},{1,0}};
int dist[3][3];
int n = 3;
int m = 3;
using namespace std;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    q.push({x,y});
    check[x][y] = 1;
    dist[x][y] = 0;
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == 0 && map[mx][my] == 0){
                    int ax = mx + dir[i][0];
                    int by = my + dir[i][1];
                    
                    check[mx][my] = 1;
                    dist[mx][my] = dist[dx][dy] + 1;
                    map[mx][my] = map[dx][dy];
                    map[dx][dy] = 0;
                    check[dx][dy] = 0;
                    if(map[ax][by] < map[mx][my]){
                        int temp;
                        temp = map[ax][by];
                        map[ax][by] = map[mx][my];
                        map[mx][my] = temp;
                    }
                }
            }
        }
    }
}
int main(void){
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    bfs(0,0);

    return 0;
}
