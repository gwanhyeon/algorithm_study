//
//  3055 탈출 풀이 1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 23/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
//
//  3055 탈출.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 23/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <cstring>


using namespace std;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
//char map[51][51];
int dist[51][51];
int check[51][51];
int r,c;
int a_x,a_y;
int b_x,b_y;
queue<pair<int,int>> q;
vector<string> map(51);
void water_bfs(){
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < r && my >= 0 && my < c){
                if(map[mx][my]=='X'){
                    continue;
                }
                if(map[mx][my]=='D'){
                    continue;
                }
                if(check[mx][my]==-1 && map[mx][my]=='.'){
                    check[mx][my] = check[dx][dy] + 1;
                    q.push({mx,my});
                }
            }
        }
    }
}
void hed_bfs(int x,int y){
    q.push({x,y});
    dist[x][y] = 0;
    
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < r && my >= 0 && my < c){
                if(map[mx][my] == 'X'){
                    continue;
                }
                if (dist[mx][my] != -1){
                    continue;
                }
                if (check[mx][my] != -1 && dist[dx][dy]+1 >= check[mx][my]){
                    continue;
                }
                dist[mx][my] = dist[dx][dy] + 1;
                q.push({mx,my});
            }
        }
    }
}
int main(void){
//    scanf("%d %d ",&r,&c);
    cin >> r >> c;
    memset(check,-1,sizeof(check));
    for(int i=0; i<r; i++){
        
        cin >> map[i];
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf("%1c",&map[i][j]);
        }
    }
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            if(map[i][j] == '*'){
                check[i][j] = 0;
                q.push({i,j});
            }
            if(map[i][j] == 'S'){
                a_x = i;
                a_y = j;
            }
            if(map[i][j] == 'D'){
                b_x = i;
                b_y = j;
            }
        }
    }
    water_bfs();
    memset(dist,-1,sizeof(dist));
    hed_bfs(a_x,a_y);
    
    if(dist[b_x][b_y] == -1){
        cout << "KAKTUS\n";
        
    }else {
        cout << dist[b_x][b_y] << '\n';
    }
    
    return 0;
    
}

