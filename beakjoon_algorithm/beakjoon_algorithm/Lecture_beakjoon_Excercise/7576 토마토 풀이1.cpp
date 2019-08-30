//
//  7576 토마토 풀이1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>

using namespace std;
int map[2001][2001];
int check[2001][2001];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int m,n;
queue<pair<int,int>> q;

void bfs(){
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == -1 && map[mx][my] == 0){
                    check[mx][my] = check[dx][dy] + 1;
                    q.push({mx,my});
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
            if(map[i][j] == 1){
                check[i][j] = 0;
                q.push({i,j});
            }
        }
    }
    bfs();
    
 
    int ans =0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(ans < check[i][j]){
                ans = check[i][j];
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(check[i][j] == -1 && map[i][j] == 0){
                ans = -1;
            }
        }
    }
    
    cout << ans << '\n';

    return 0;
}
