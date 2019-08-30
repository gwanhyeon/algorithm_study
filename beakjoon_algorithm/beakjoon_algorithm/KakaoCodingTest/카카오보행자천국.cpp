//
//  카카오보행자천국.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <vector>
#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
int ans[501*510];
int check[501][501];
int dist[501][501];
int dir[4][2] = {{-1,0},{1,0},{0,1},{-1,0}};




int MOD = 20170805;

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int m, int n, vector<vector<int>> city_map) {
    memset(ans,0,sizeof(ans));
    memset(check,0,sizeof(check));
    memset(dist,0,sizeof(dist));
    
    int answer = 0;
    
    
    queue<pair<int,int>> q;
    check[0][0] = 1;
    dist[0][0] = 0;
    q.push({0,0});
    ans[0] = 1;
    int cnt = 0;
    while(!q.empty()){
        int dx = q.front().first;
        int dy = q.front().second;
        q.pop();
        
        for(int i=0; i<4; i++){
            int mx = dx + dir[i][0];
            int my = dy + dir[i][1];
            if(mx >= 0 && mx < m && my >= 0 && my < n){
                if(check[mx][my] == 0 && city_map[mx][my] == 0 && ans[mx*my] == 0){
                    ans[mx*my] = 1;
                    dist[mx][my] = dist[dx][dy] + 1;
                    check[mx][my] = 1;
                    q.push({mx,my});
                }
                //위
                if(check[mx][my] == 0 && city_map[dx][dy] == 2 && dy > my && ans[mx*my] == 0){
                    ans[dx*(dy-1)] = 1;
                    dist[dx][dy-1] = dist[dx][dy] + 1;
                    check[dx][dy-1] = 1;
                    q.push({dx,dy-1});
                    break;
                }
                //왼쪽
                if(check[mx][my] == 0 && city_map[dx][dy] == 2 && dx < mx && ans[mx*my] == 0){
                    ans[(dx+1)*dy] = 1;
                    dist[dx+1][dy] = dist[dx][dy] + 1;
                    check[dx+1][dy] = 1;
                    q.push({dx+1,dy});
                    break;
                    
                }
                
            }
        }
        ans[0] = 0;
        cnt++;
        memset(check,0,sizeof(check));
    }
    answer = cnt % MOD;
    return answer;
}
