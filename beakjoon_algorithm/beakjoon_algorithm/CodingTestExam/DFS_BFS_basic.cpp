//
//  DFS_BFS_basic.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 06/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;

int map[1001][1001];
int check[1001];
int n;

void dfs(int v){
    cout << v << " ";
    // stack, recursive 사용해서 가자
    // 1) 가장먼저 방문을 해야 되는데 -> 노드!!의 개수를 확인해서 방문해야한다.
    for(int i=1; i<=n; i++){
        if(map[v][i] && check[i] == 0){
            check[i] = 1;
            dfs(i);
        }
    }
}
void bfs(int v){
    // 여기는 큐를 이용하면 된다.
    queue<int> q;
    
    // check point init
    for(int i=1; i<=n; i++){
        check[i] = 0;
    }
    // 초기값 넣어주기
    q.push(v);
    check[v] = 1;
    while(!q.empty()){
        int num = q.front();
        cout << num << " ";
        q.pop();
        
        for(int i=1; i<=n; i++){
            if(map[num][i] && check[i] ==0){
                q.push(i);
                check[i] = 1;
            }
        }
    }
}
int main(void){
    int m,v;
    int x,y;
    // 정점, 간선, 탐색시작 정점의 번호
    cin >> n >> m >> v;
    
    for(int i=0; i<m; i++){
        // 정점 두개 입력받은후에 map에 간선을 연결해준다.
        scanf("%d %d",&x,&y);
        map[x][y] = 1;
        map[y][x] = 1;
    }
    //시작하는 정점을 1로 초기화 시켜주기. 시작점 체크
    check[v] = 1;
    
    dfs(v);
    cout << endl;
    // 결과출력
    bfs(v);
    return 0;
}
