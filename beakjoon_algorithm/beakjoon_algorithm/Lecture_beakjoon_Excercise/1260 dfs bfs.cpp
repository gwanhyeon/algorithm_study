//
//  1260 dfs bfs.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

vector<int> arr[1001];
bool check[1001];
int n,m,v;
void bfs(int node){
    
    
    for(int i=0; i<sizeof(check); i++){
        check[i] = 0;
    }
    queue<int> q;
    check[node] = true;
    q.push(node);
    
    while(!q.empty()){
        int x = q.front();
        q.pop();
        cout << x << ' ';
        //  1. 인접리스트 구현
        for(int i=0; i<arr[x].size(); i++){
            int next = arr[x][i];

            if(check[next] == false){
                check[next] = true;
                q.push(next);
            }
        }
        // 2. 인접행렬 구현
        for(int i=1; i<=n; i++){
            if(arr[x][i] && check[i] == false){
                check[i] = true;
                q.push(i);
            }
        }
        
    }
}

void dfs(int node){
    check[node] = true;
    cout << node << ' ';
    
  
    // 1.인접 리스트 구현
    for(int i=0; i<arr[node].size(); i++){
        int y = arr[node][i];
        if(check[y] == false){
            dfs(y);
        }
    }
    // 2.인접 행렬 구현
    for(int i=1; i<=n; i++){
        if(arr[node][i] && check[i] == false){
            check[i] = true;
            dfs(i);
        }
    }
}

int main(void){

    cin >> n >> m >> v;
    
    // 1.간선의 개수까지
    
    for(int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        //2. 입력으로 주어지는 간선은 양방향이다.
        // 이런형식으로 벡터를 넣어주게되면 뒤에 부분 [x][자동인덱스 ~ m까지]로 값이 들어가게된다.
        arr[x].push_back(y);
        arr[y].push_back(x);
    }
    //3. 정점 번호가 작은 것을 먼저 방문
    for(int i=0; i<n; i++){
        sort(arr[i].begin(), arr[i].end());
    }
    
    dfs(v);
    cout << '\n';
    bfs(v);
    cout << '\n';
    return 0;
}
