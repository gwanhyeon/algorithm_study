//
//  플러드필DFS.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;
int maze[502][502] = {{1,1,1,0,1,0,0,0,0,0},
    {1,0,1,0,1,0,0,0,0,0},
    {1,1,1,0,1,0,0,0,0,0},
    {1,1,0,0,1,0,0,0,0,0},
    {0,1,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0} };
int check[502][502];
int n =7;
int m = 10;
int dir[4][2] = {{0,1},{0,-1},{-1,0}, {1,0}};
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    stack<pair<int,int>> S;
    
    check[0][0] = 1;
    S.push({0,0});
    while(!S.empty()){
        auto cur = S.top();
        S.pop();
        cout << '(' << cur.first << ',' << cur.second <<  ")->";
        for(int k =0; k<4; k++){
            int cur_x = cur.first + dir[k][0];
            int cur_y = cur.second + dir[k][1];
            
            if(cur_x < 0 || cur_x >= n || cur_y < 0 || cur_y >= m){
                continue;
            }
            if(check[cur_x][cur_y] || maze[cur_x][cur_y] == 0){
                continue;
            }
            check[cur_x][cur_y] = 1;
            S.push({cur_x,cur_y});
        }
        
    }
    
    
    return 0;
}
