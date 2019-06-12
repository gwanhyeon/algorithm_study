//
//  2468안전영역.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 09/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int Map[101][101];
bool Check[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,1}, {-1,0}};

int main(void){
    
    int n;
    cin >> n;
    
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> Map[i][j];
        }
    }
    
    int cnt = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            
            
            
            queue<pair<int,int>> q;
            Check[i][j] = 1;
            q.push({i,j});
//            if(Map[i][j] > n){
//                Check[i][j] = true;
//                cnt++;
//            }
         
            while(!q.empty()){
                auto cur = q.front();
                q.pop();
                
                for(int z=0; z<4; z++){
                 
                    int cur_x = cur.first + dir[z][0];
                    int cur_y = cur.second + dir[z][1];
                 
        
                    if(cur_x < 0 || cur_x >= n || cur_y || cur_y >= n){
                        continue;
                    }
                    if(Check[cur_x][cur_y] || Map[cur_x][cur_y] != 0){
                        continue;
                    }
                    Check[cur_x][cur_y] = true;
                    q.push({cur_x,cur_y});
                    
                }
            }
        }
        
        
    }
    cout << cnt << '\n';
    
    
    
    
    
}
