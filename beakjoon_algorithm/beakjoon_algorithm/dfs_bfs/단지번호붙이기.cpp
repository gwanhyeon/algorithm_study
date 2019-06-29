
//
//  단지번호붙이기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 29/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int Map[30][30];
int Check[30][30];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
int Result[625];
int n;
void bfs(int cur_x,int cur_y, int cnt){
    // 들어온 값 넣기
    queue<pair<int,int>> q;
    q.push(make_pair(cur_x,cur_y));
    Check[cur_x][cur_y] = cnt;
    
    while(!q.empty()){
        cur_x = q.front().first;
        cur_y = q.front().second;
        q.pop();
        for(int k=0; k<4; k++){
            int dx = cur_x+dir[k][0];
            int dy = cur_y+dir[k][1];
            if(dx >= 0 && dx < n && dy >= 0 && dy < n){
                if(Map[dx][dy] == 1 && Check[dx][dy] == 0){
                    q.push(make_pair(dx,dy));
                    Check[dx][dy] = cnt;
                }
            }
        }
    }
}
int main(void){
    
    cin >> n;
    
    // 입력된 값들 맵에 저장
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d",&Map[i][j]);
//            cin >> Map[i][j];
        }
    }
    // bfs
    int cnt=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 갈수있는 경로고 체크된곳이 아닐경우 bfs수행
            if(Map[i][j] == 1 && Check[i][j] == 0){
                // 단지의 개수를 증가해서 들어가게 되면 1번째 단지부터 시작한다.
                bfs(i,j,++cnt);
            }
        }
    }
    // 총 단지의 개수
    cout << cnt << '\n';
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            // 해당하는 단지의 수를 체크한다
            // 예를 들면, Result[0] = 1번째 단지, Result[1] = 2번째 단지
            Result[Check[i][j]] += 1;
        }
    }
    // 오름 차순 정렬
    sort(Result+1, Result+cnt+1); // TestCase 1: 결과에 저장된 1~3단지의 개수 정렬
    
    for(int i=1; i<=cnt; i++){
        cout << Result[i] << '\n';
    }
    return 0;
}
