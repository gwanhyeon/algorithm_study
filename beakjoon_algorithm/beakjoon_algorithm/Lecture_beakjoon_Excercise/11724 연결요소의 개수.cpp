//
//  11724 연결요소의 개수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

using namespace std;
int n,m;
vector<int> map[1001];
bool check[1001];
int cnt = 0;
void bfs(int node){
    queue<int> q;
    check[node] = true;
    q.push(node);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int i=0; i<map[x].size(); i++){
            int y = map[x][i];
            if(check[y] == false){
                check[y] = true;
                q.push(y);
            }
        }
    }
}
int main(void){
    cin >> n >> m;
    
    for(int i=0; i<m; i++){
        int u,v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    
    for(int i=1; i<=n; i++){
        if(check[i] == false){
            bfs(i);
            cnt +=1;
        }
    }
    cout << cnt << '\n';
    return 0;
    
}
