//
//  2178미로.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
string Maze[101];
//int Maze[101][101];
int check[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;

    // input공백으로 받냐 못받냐에 차이에따라 string, int로 받는게 달라진다.
    for(int i=0; i<n; i++){
            cin >> Maze[i];
    }
    
    for(int i=0; i<n; i++){
        
        fill(check[i], check[i]+m, -1);
    }
    queue<pair<int,int>> q;
    // (0,0) 출발
    check[0][0] = 0;
    q.push({0,0});


    while(!q.empty()){
        auto cur = q.front();
        q.pop();
        
        for(int z=0; z<4; z++){
            
            int cur_x = cur.first + dir[z][0];
            int cur_y = cur.second + dir[z][1];
            
            if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m){
                continue;
            }
            if(check[cur_x][cur_y] >= 0 || Maze[cur_x][cur_y] != '1'){
                continue;
            }
            check[cur_x][cur_y] = check[cur.first][cur.second] + 1;
            q.push({cur_x,cur_y});

        }
    }
    cout << check[n-1][m-1]+1 << '\n';
    
    
    return 0;
}
