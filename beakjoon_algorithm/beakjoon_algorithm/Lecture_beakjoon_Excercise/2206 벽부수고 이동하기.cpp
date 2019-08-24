//
//  벽부수고 이동하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#include <tuple>
int map[1001][1001];
int check[1001][1001][2];
int dir[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};


int n,m;
using namespace std;
void bfs(int x,int y,int z){
    
    queue<tuple<int,int,int>> q;
    check[x][y][z] = 1;
    q.push(make_tuple(x,y,z));

    while(!q.empty()){
        int dx,dy,dz;
        tie(dx,dy,dz) = q.front();
        q.pop();
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                if(check[mx][my][dz] == 0 && map[mx][my] == 0){
                    check[mx][my][dz] = check[dx][dy][dz] + 1;
                    q.push(make_tuple(mx,my,dz));
                }
                if(dz == 0 && check[mx][my][dz] == 0 && map[mx][my] == 1){
                    check[mx][my][dz+1] = check[dx][dy][dz] + 1;
                    q.push(make_tuple(mx,my,dz+1));
                    
                }
            }
        }
    }
    
}

int main(void){

    cin >> n >> m;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
               scanf("%1d",&map[i][j]);
        }
    }
    
    bfs(0,0,0);
    int ans = 0;
    if(check[n-1][m-1][0] != 0 && check[n-1][m-1][1] != 0){
        ans= min(check[n-1][m-1][0],check[n-1][m-1][1]);
    }else if(check[n-1][m-1][0] != 0){
        ans = check[n-1][m-1][0];
    }else if(check[n-1][m-1][1] != 0){
        ans = check[n-1][m-1][1];
    }else {
        ans = -1;
    }
    
    cout << ans << '\n';
    return 0;
    
}

