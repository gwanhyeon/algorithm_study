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
    check[v] = true;
    cout << v << " ";
    for(int i=0;i <map[v].size(); i++){
        int next = map[v][i];
        if(check[next] == false){
            dfs(next);
        }
    }
}
void bfs(int v){
    memset(check,false,sizeof(check));
    queue<int> q;
    check[v] = true;
    q.push(v);
    
    while(!q.empty()){
        int node = q.front();
        q.pop();
        cout << node<< " ";
        
        for(int i=0; i<map[node].size(); i++){
            int next = map[node][i];
            if(check[next]== false){
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
