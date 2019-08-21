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
int cnt = 0;
int ans[201*201*201];
void bfs(int x,int y,int h1){
    
    queue<pair<int,int>> q_xy;
    queue<int> q_h;
    check[h1][x][y] = 1;
    map[h1][x][y] = 1;
    q_xy.push({x,y});
    q_h.push(h1);
    
    while(!q_xy.empty() && !q_h.empty()){
        int dx = x + q_xy.front().first;
        int dy = y + q_xy.front().second;
        int dh = h1 + q_h.front();
        q_xy.pop();
        q_h.pop();
        for(int i=0; i<6; i++){
            int mh = dh + dir[i][0];
            int mx = dx + dir[i][1];
            int my = dy + dir[i][2];
            if(mx >= 0 && mx < n && my >= 0 && my < m && mh >= 0 && mh < h){
                if(check[mh][mx][my] == 0 && map[mh][mx][my] == 0 && map[dh][dx][dy] == 1){
                    map[mh][mx][my] = 1;
                    check[mh][mx][my] = map[dh][dx][dy] + 1;
                    q_xy.push({mx,my});
                    q_h.push(mh);
                }
            }
        }
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
                if(check[k][i][j] == 0 && map[k][i][j] == 1){
                    bfs(i,j,k);
                    cnt+=1;
                }
            }
        }
    }

    cout << cnt;
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
