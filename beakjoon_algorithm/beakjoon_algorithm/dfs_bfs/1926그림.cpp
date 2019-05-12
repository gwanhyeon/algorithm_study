//
//  1926그림.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int n,m;
int maze[501][501];
int check[501][501];

int dir[4][2]={ {-1,0},{1,0},{0,1},{0,-1} };

int main(void){
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n >> m;
    // Initualize
    for(int i=0; i< n; i++){
        for(int j=0; j< m; j++){
            cin >> maze[i][j];
        }
    }
    
    int picture_num = 0;
    int num_max = 0;
    
    for(int i=0; i<n; i++){
        
        for(int j=0; j<m; j++){
            if(maze[i][j] == 0 || check[i][j] ){
                continue;
            }
            
            queue<pair<int,int>> Q;
            check[i][j] = 1;
            Q.push({i,j});
            picture_num++;
            int area = 0;
            while(!Q.empty()){
                area++;
                auto cur = Q.front();
                Q.pop();
                
                for(int i=0; i<4; i++){
                    int cur_x = cur.first + dir[i][0];
                    int cur_y = cur.second + dir[i][1];
                    
                    if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m){
                        continue;
                    }
                    if(check[cur_x][cur_y] || maze[cur_x][cur_y] != 1 ){
                        continue;
                    }
                    check[cur_x][cur_y] = 1;
                    Q.push({cur_x, cur_y});
                
                }
            }
            num_max = max(num_max,area);
        }
        
    }
    cout << picture_num << '\n' << num_max;
    
    return 0;
}
