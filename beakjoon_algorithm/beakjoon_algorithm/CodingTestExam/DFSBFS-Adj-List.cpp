//
//  DFSBFS-Adj-List.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
bool check[1001];
vector<int> map[100];
int n,m,v;  // 정점개수 , 간선 , 시작 정점 번호


void dfs(int v){
    // 첫번째 시작점을 true로 처리해준다.
    check[v] = true;
    cout << v << " ";
    // 내 시작점에서 연결된 값들을 계속해서 진입한다.
    // 진입하다가 빈부분으로 계속들어가게 된다 .그래서 recursive
    for(int i=0;i <map[v].size(); i++){
        int next = map[v][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}

void bfs(int v){
    // 시작점을 넣어준다.
    queue<int> q;
    check[v] = true;
    q.push(v);
    
    while(!q.empty()){
        // 내 node와 연결된 간선들의 정점에 도달하기 위해
        // 현재 내 노드의 값들을 queue에서 pop()을 시행해준다.
        int node = q.front();
        q.pop();
        cout << node<< " ";
        // 현재 map[node]에 값에 연결된 값들을 size()만큼 가져온다.
        // // map[node]에 연결된 값들을 체크해주고 다시 푸쉬를 해준다.
        for(int i=0; i<map[node].size(); i++){
            int next = map[node][i];
            
            // 다음의 연결된 값들을 모두 check처리하고 queue에 담아준다.
            if(check[next] == false){
                // dfs와 다르게 여기서 check point !
                check[next] = true;
                q.push(next);
            }
        }
    }
}


int main(void){
    
    
    
    cin >> n >> m >> v;
    
    for(int i=0; i<n; i++){
        int x,y;
        cin >> x >> y;
        map[x].push_back(y);
        map[y].push_back(x);
    }
    // 단, 방문할 수 있는 정점이 여러 개인 경우에는 정점 번호가 작은 것을 먼저 방문하고, 더 이상 방문할 수 있는 점이 없는 경우 종료한다. 1은시작점으로 제외
    // 정점은 현재 정렬이 되지 않고 마구잡이로 들어가있기때문에 정렬을 꼭해주어야함.
    
    for (int i=1; i<=n; i++) {
        sort(map[i].begin(), map[i].end());
    }
    cout << endl;
    check[v] = true;
    dfs(v);
    cout << "\n";
    bfs(v);
    
    return 0;
}
