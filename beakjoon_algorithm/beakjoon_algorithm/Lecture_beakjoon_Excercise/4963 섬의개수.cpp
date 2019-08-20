//
//  4963 섬의개수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int map[50][50];
int check[50][50];
int dir[8][2] = {{-1,1},{1,1},{1,-1},{-1,-1},{0,1},{1,0},{0,-1},{-1,0}};
int w,h;
int cnt=0;

void bfs(int x, int y){
    queue<pair<int,int>> q;
    map[x][y] = true;
    q.push({x,y});
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        for(int i=0; i<8; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < h && my >= 0 && my < w){
                if(check[mx][my] == 0 && map[mx][my] == 1){
                    check[mx][my] = 1;
                    q.push({mx,my});
                }
            }
        }
    }
}

int main(void){
    
    while(true){
        cin >> w >> h;
        if(w == 0 && h == 0){
            break;
        }
       
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                scanf("%d",&map[i][j]);
            }
        }
        
        for(int i=0; i<h; i++){
            for(int j=0; j<w; j++){
                if(map[i][j] == 1 && check[i][j] == 0){
                    bfs(i,j);
                    cnt += 1;
                }
            }
        }
        cout << cnt << "\n";
        memset(check,0,sizeof(check));
        memset(map,0,sizeof(map));
        cnt = 0;
        
    }

    return 0;
    
}
