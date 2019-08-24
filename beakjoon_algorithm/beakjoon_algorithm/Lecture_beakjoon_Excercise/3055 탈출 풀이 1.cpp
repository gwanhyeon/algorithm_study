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
char map[51][51];
int check[51][51];
int r,c;
int a_x,a_y;
int b_x,b_y;
queue<pair<int,int>> q;


void water_bfs(int x,int y){
    
    while(!q.empty()){
        int dx = x + q.front().first;
        int dy = y + q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            
            if(mx >= 0 && mx < r && my >= 0 && my < c){
                if(map[mx][my] == 'X'){
                    continue;
                }
                if(map[mx][my] == 'D'){
                    continue;
                }
                if(check[mx][my] == -1 && map[dx][dy] == '*'){
                    check[mx][my] = check[dx][dy] + 1;
                    q.push({mx,my});
                }
            }
        }
    }
}
void hed_bfs(int x,int y){
    

}
int main(void){
    //    cin >> r >> c;
    scanf("%d %d",&r,&c);
    memset(check,-1,sizeof(check));
    
    for(int i=0; i<r; i++){
        for(int j=0; j<c; j++){
            scanf(" %1c",&map[i][j]);
            
            if(map[i][j] == '*' && check[i][j] == 0){
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
    
    water_bfs(a_x,a_y);
    hed_bfs(b_x,b_y);
    
    
    return 0;
    
}

