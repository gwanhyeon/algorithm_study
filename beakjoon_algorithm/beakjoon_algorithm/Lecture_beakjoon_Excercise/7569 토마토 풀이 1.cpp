//
//  7579 토마토 풀이 1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int map[201][201][201];
int check[201][201][201];
int dir[6][3] = {{0,0,1},{0,-1,0},{0,1,0},{0,0,-1},{1,0,0},{-1,0,0}};

int n, m, h;
queue<pair<int,int>> q_xy;
queue<int> q_h;

void bfs(){
    while(!q_xy.empty()){
        int dh = q_h.front();
        int dx = q_xy.front().first;
        int dy = q_xy.front().second;
        q_h.pop();
        q_xy.pop();
        for(int i=0; i<6; i++){
            int mh = dh + dir[i][0];
            int mx = dx + dir[i][1];
            int my = dy + dir[i][2];
            if(mh >= 0 && mh < h && mx >= 0 && mx < n && my >=0 && my < m){
                if(check[mh][mx][my] == -1 && map[mh][mx][my] == 0){
                    check[mh][mx][my] = check[dh][dx][dy] + 1;
                    q_xy.push({mx,my});
                    q_h.push(mh);
                }
            }
        }
    }
}

int main(void){
    cin >> m >> n >> h;
    
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                check[k][i][j] = -1;
                cin >> map[k][i][j];
                if(map[k][i][j] == 1){
                    check[k][i][j] = 0;
                    q_xy.push({i,j});
                    q_h.push(k);
                }
            }
        }
    }
    bfs();
    int ans = 0;
    
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(ans < check[k][i][j]){
                    ans = check[k][i][j];
                }
            }
        }
    }
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(check[k][i][j] == -1 && map[k][i][j] == 0){
                    ans = -1;
                }
            }
        }
    }
    cout << ans << '\n';
    return 0;
}
