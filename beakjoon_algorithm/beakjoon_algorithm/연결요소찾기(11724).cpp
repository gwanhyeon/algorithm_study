//
//  연결요소찾기(11724).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/04/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;
vector<int> map[1001];
bool check[1001];
void dfs(int v){
    check[v] = true;
    for(int i=0; i<map[v].size(); i++){
        int next = map[v][i];
        if(check[next]==false){
            dfs(next);
        }
    }
}
int main(void){
    int n,m;
    cin >> n >> m;
    // 간선의 길이 만큼 정점 u, 정점 v
    for(int i=0; i< m; i++){
        int u,v;
        cin >> u >> v;
        map[u].push_back(v);
        map[v].push_back(u);
    }
    int cnt=0;
    for(int i=1; i<=n; i++){
        /*
         간선의 개수를 구하기 위해서는 dfs호출시에 check==false일경우 간선의 개수가 하나씩증가하는것을 알 수 있다
         단, dfs함수 안에서 if(check[next]==false) dfs(next);를 처리하면 값이 정확하게 반환이 안될 수 있음.
         */
        if(check[i] == false){
            dfs(i); //값 체크
            cnt++;
        }
    }
    cout << cnt;
}
