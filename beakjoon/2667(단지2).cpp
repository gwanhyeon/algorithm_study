//
//  2667(단지2).cpp
//  Algorigm_Study
//
//  Created by kgh on 2018. 8. 6..
//  Copyright © 2018년 kgh. All rights reserved.
//

/*
 첫번째 줄 (i=0)에서부터 탐색을 시작하여, map[i][j] ==1 인 부분이 나타나면
 
 
 
 단지가 시작되는 부분이므로 단지의 개수(cnt)를 하나 증가시킨 후
 
 
 
 그 점부터 이어진 모든 곳에 대해 DFS(깊이 우선 탐색)을 시작합니다.
 
 
 
 단지의 개수로 map[i][j]의 인자를 바꾸어 줍니다. (key)
 
 
 
 연결되어있는 여러 집이 한 단지 안에 있으므로.
 
 
 
 그런식으로 탐색을 하여 단지의 개수와 그 단지안의 집의 개수를 구합니다.
 
 
 
 
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>         // sort
#include<cstdio>
using namespace std;

int map[25][25];    //정사각형 모양의 지도
int size[625];  // 단지집 사이즈
int dir[4][2] = { {-1, 0}, {1, 0}, {0, -1}, {0, 1}}; // 동서남북
int cnt;            // map 단지 수
int n;              // Square number

// Size Check
bool Check(int a, int b){
    return (a>=0 && a<n) && (b>=0 && b<n);
}

// DFS
void dfs(int v1, int v2, int next_cnt){
    map[v1][v2] = next_cnt;
    
    for(int i=0; i<4; i++){
        int dy = v1 + dir[i][0];
        int dx = v2 + dir[i][1];
        
        if(Check(dy, dx) && map[dy][dx] == 1){
            dfs(dy, dx, next_cnt);
        }
    }
}

// Search
void Search(int n){
    for(int i=0; i<n; i++){ //맵을 탐색하면서 1인 부분을 찾으면
        for(int j=0; j<n; j++) {
            if (map[i][j] == 1) {   //dfs로 보낸다
                cnt++;
                dfs(i, j, cnt + 1);
            }
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(map[i][j] >1){   // 단지수 확인
                size[map[i][j] - 2]++;
            }
        }
    }
}

int main(void){
    // Input
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n;j++) {
            scanf("%1d", &map[i][j]);
        }
    }
    // Search
    Search(n);
    
    // Array Sort
    sort(size, size + cnt);
    
    // Size Output
    cout << cnt << endl;
    for(int i=0; i<cnt; i++){
        cout << size[i] << endl;
    }
    return 0;
}

