//
//  1261 알고스팟.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <deque>


int map[100][100];
int check[100][100];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int n,m;
int cnt = 0;
using namespace std;

void bfs(int x,int y){
    deque<pair<int,int>> q;
    check[x][y] = 0;
    q.push_back({x,y});
    
    while(!q.empty()){
        int dx = x + q.front().first;
        int dy = y + q.front().second;
        q.pop_front();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my] == -1){
                    if(map[mx][my] == 0){
                        check[mx][my] = check[dx][dy];
                        q.push_front({mx,my});
                    }else {
                        check[mx][my] = check[dx][dy] + 1;
                        q.push_back({mx,my});
                    }
                }
            }
        }
    }
    
}
int main(void){
    
    cin >> m >> n;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            scanf("%1d",&map[i][j]);
            check[i][j] = -1;
        }
    }
    bfs(0,0);
    cout << check[n-1][m-1] << '\n';
    
    return 0;
}
