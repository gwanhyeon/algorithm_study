//
//  BFSDFS.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int check[1001];
int map[1001][1001];
int n,m,v;      // n=정점개수 , m= 간선 개수, 탐색 시작 정점 번호
void dfs(int v){
    
    check[v] = 1;
    cout << v << " ";
    
    for(int i=1; i<=n; i++){
        if(map[v][i] == 1 && check[i] ==0){
            dfs(i);
        }
    }
}
void bfs(int v){
    // 처음에 들어온 값들 초기화 시켜주기
    queue<int> q;
    // 맨 처음 값 초기화!!!
    q.push(v);
    check[v] = 1;
    
    // q가 비지 않았을 경우
    while(!q.empty()){
        int num = q.front();
        q.pop();
        cout << num << " ";
        for(int i=1; i<=n; i++){
            // 맨처음에 있는 값들 팝해주고-> 연결된 정점들 다 넣어주기
            // map에 갈 수 있는 값이면
            if(map[num][i] == 1 && check[i] == 0){
                check[i] = 1;
                q.push(i);
            }
        }
    }
    
}

int main(void){
    
    cin >> n >> m >> v;
    
    // 연결된 간선 초기화
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        map[x][y] = 1;
        map[y][x] = 1;
    }
    check[v] = 1;
    
    dfs(v);
    cout << "\n";
    
    // 이렇게 초기화 하는것보다
    
    memset(check, false, sizeof(check));
//    for(int i=1; i<=n; i++){
//        check[i] = 0;
//    }
    bfs(v);
    return 0;
}
