//
//  7576 토마토.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 20/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int map[201][201][201];
int check[201][201][201];
int dir[6][3] = {{0,1,0},{0,-1,0},{0,0,-1},{0,0,1},{1,0,0},{-1,0,0}};
int m,n,h;

void bfs(int x,int y,int h){
    
    queue<pair<int,int>> q_xy;
    queue<int> q_h;
    check[x][y][h] = true;
    q_xy.push({x,y});
    q_h.push(h);
    
    while(!q_xy.empty() && !q_h.empty()){
        
    }
    
    
    
    
    
    
}

int main(void){
    
    cin >> m >> n >> h;
    
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                cin >> map[k][i][j];
            }
        }
    }
    
    for(int k=0; k<h; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                bfs(1,1,1);
            }
        }
    }
    
    
    
    
    return 0;
}














//#include <stdio.h>
//#include <iostream>
//#include <queue>
//
//using namespace std;
//int map[101][101];
//int check[101][101];
//int dir[6][2] = {{-1,0},{0,-1},{1,0},{0,1}};
//int n,m,h;
//int cnt = 0;
//void bfs(int x,int y){
//    queue<pair<int,int>> q;
//    check[x][y] = true;
//    q.push({x,y});
//
//    while(!q.empty()){
//        int dx = q.front().first;
//        int dy = q.front().second;
//        q.pop();
//        bool tf = false;
//
//        for(int i=0; i<4; i++){
//            int mx = dx + dir[i][0];
//            int my = dy + dir[i][1];
//
//            if(map[mx][my] == -1 || map[mx][my] == 1){
//                continue;
//            }
//
//            if(mx >= 0 && mx<m*h && my >= 0 && my<n){
//                // 익은 경우
//
//                if(map[dx][dy] == 1 && map[mx][my] == 0 && check[mx][my] == 0){
//                    check[mx][my] = 1;
//                    map[mx][my] = map[dx][dy];
//                    q.push({mx,my});
//                    tf = true;
//
//                }
//            }
//        }
//        if(tf == true){
//            cnt +=1;
//        }
//    }
//}
//
//int main(void){
//
//
//    cin >> n >> m >> h;
//
//    for(int i=0; i<m; i++){
//        for(int j=0; j<n; j++){
//            cin >> map[i][j];
//        }
//    }
//
//    for(int i=0; i<m*h; i++){
//        for(int j=0; j<n; j++){
//            if(check[i][j] == 0 && map[i][j] == 1){
//                bfs(i,j);
////                cnt += 1;
//            }
//        }
//    }
//
//    cout << cnt;
//    return 0;
//}
