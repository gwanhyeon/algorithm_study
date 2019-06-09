//
//  적록색약.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

// 적록색 아닌사람 - 4가지(빨,초,파) , 적록인사람 - 3가지(빨-초,파)
// 적록색인사람, 적록색이 아닌사람이 봤을때 구역의 개수를 구하는 알고리즘을 구하시오.

#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
using namespace std;
string Maze[101];
int check[101][101];
int dir[4][2] = {{-1,0}, {1,0}, {0,1}, {0,-1}};

int main(void){
    
    
    
    //#1 적록색약 정상인 경우
    // N * N
    int n;
    cin >>n;
    
    // 맵 초기화
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> Maze[i][j];
        }
    }
    int num_ungreen = 0;        // 정상
    int num_ingreen = 0;        // 비정상
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            queue<pair<int,int>> q;
            q.push({i,j});
            check[i][j] = 1;
            while(!q.empty()){
                num_ungreen++;
                auto cur = q.front();
                q.pop();
                
                for(int z=0; z<4; z++){
                    int cur_x = cur.first + dir[z][0];
                    int cur_y = cur.second + dir[z][1];
                    
                    if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= n){
                        continue;
                    }
                    if(check[cur_x][cur_y] >= 0 || Maze[cur_x][cur_y] != '1'){
                        continue;
                    }
                    q.push({cur_x,cur_y});
                    check[cur_x][cur_y] = 1;
                    
                }
            }
        }
    }
    //#2 비 정상인 경우
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(Maze[i][j] == 'R'){
                Maze[i][j] = 'G';
            }
        }
    }

    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            queue<pair<int,int>> q;
            q.push({i,j});
            check[i][j] = 1;
            
            while(!q.empty()){
                num_ingreen++;
                auto cur = q.front();
                q.pop();
                
                for(int z=0; z<4; z++){
                    int cur_x = cur.first + dir[z][0];
                    int cur_y = cur.second + dir[z][1];
                    if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= n){
                        continue;
                    }
                    if(check[cur_x][cur_y] >= 0 || Maze[cur_x][cur_y]!= '1'){
                        continue;
                    }
                    q.push({cur_x,cur_y});
                    check[cur_x][cur_y] = 1;
                    
                }
            }
        }
    }
    
    cout << num_ungreen << ' ' << num_ingreen;
    return 0;
}
