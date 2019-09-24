//
//  exam5.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


#include <stdio.h>
#include <queue>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;
int map[25][25];
int check[25][25];
int dir[4][2] = {{0,-1},{1,0},{0,1},{-1,0}};
int n,m;
int x,y;
int hidden_x;
int hidden_y;
void bfs(int x,int y){
    queue<pair<int,int>> q;
    check[x][y] = true;
    q.push({x,y});
    
    hidden_y += 1;
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx == x && my == y){
                hidden_x +=1;
           
            }
            if(mx == n && my == m){
                break;
            }
            if(mx >= 0 && mx < n && my >= 0 && my < m){
                
                if(map[mx][my] == 1 && check[mx][my] == 0){
                    map[mx][my] = map[dx][dy]+1;
                    check[mx][my] = true;
                    q.push({mx,my});
                    
                    hidden_y += 1;
                    
                }
            }
        }
    }
    
    
}

int main(void){
    
    scanf("%d %d",&n,&m);
    scanf("%d %d",&x,&y);
    map[x][y] = 1;
    check[x][y] = 1;
    hidden_x = 0;
    hidden_y = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i][j] = 0;
            check[i][j] = 0;
            
            
        }
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            map[i][j] = 0;
            check[i][j] = 0;
            bfs(i,j);
            
        }
    }
    
//    cout << map[n-1][m-1] << '\n';
    cout << hidden_x << hidden_y;
    
    return 0;
}
