//
//  플러드필.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// 시작점으로의 거리를 잴때 사용한다.
// 1만큼 더 떨어져있다는 성질이 성립되지 않는다.

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int board[502][502] =
    {
    {1,1,1,0,1,0,0,0,0,0},
    {1,0,0,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
    };
bool check[502][502];
int n = 7;
int m = 10;
int dir[4][2]= {{0,1}, {0,-1}, {1,0}, {1,-1}};


int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    queue<pair<int,int>> Q;
    // check -> push
    check[0][0] = 1;
    Q.push({0,0});

    while(!Q.empty()){
        auto cur = Q.front();
        Q.pop();
        cout << '(' << cur.first << ',' << cur.second << ")->";
        // four direction
        for(int i=0; i<4; i++){
            int nx = cur.first + dir[i][0];
            int ny = cur.second + dir[i][1];
            
            if(nx < 0 || nx >= n || ny < 0 || ny >= m){
                continue;
            }
            if(check[nx][ny] || board[nx][ny] !=1){
                continue;
            }
            check[nx][ny] = 1;
            Q.push({nx,ny});
        }
        
    }
    
    return 0;
}
