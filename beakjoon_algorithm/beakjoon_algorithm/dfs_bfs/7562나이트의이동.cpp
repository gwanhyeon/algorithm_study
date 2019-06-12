//
//  7562나이트의이동.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 09/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int Map[301][301];      // MAP
bool check[301][301];   // CHECK
int dir[8][2] = {{-2,1},{-1,2},{1,2},{2,1},{-2,-1},{-1,-2},{-2,1},{2,-1}};

int main(void){
    
    int n;
    cin >> n;
    //TEST CASE n 입력
    while(--n){
        // 1. 길이 입력 size
        int size;
        cin >> size;
        // 해당 길이 만큼 초기화 시키기
        for(int i=0; i<size; i++){
            for(int j=0; j<size; j++){
                Map[i][j] = 0;
            }
        }
        // 2. 시작점 입력 start
        int r,c;
        cin >> r >> c;

        // 3. 도착지 입력 Destination
        int dest_r, dest_c;
        cin >> dest_r >> dest_c;
//        Map[r][c] = 1;
//        Map[dest_r][dest_c] = 1;
        queue<pair<int,int>> q;
        check[r][c] = true;
        q.push({r,c});
        int cnt = 0;
        
        while(!q.empty()){
            auto cur = q.front();
            q.pop();
            for(int z=0; z<8; z++){
                int dx = cur.first + dir[z][0];
                int dy = cur.second + dir[z][1];
                if(dx == dest_r && dy == dest_c){
                    cout << cnt << '\n';
                    break;
                }
                if(dx < 0 || dx >= size || dy < 0 || dy >= size){
                    continue;
                }
                if(check[dx][dy] || Map[dx][dy] != 0){
                    continue;
                }
                cnt++;
                check[dx][dy]  = true;
                q.push({dx,dy});
            }
        }
    }
    return 0;
}
