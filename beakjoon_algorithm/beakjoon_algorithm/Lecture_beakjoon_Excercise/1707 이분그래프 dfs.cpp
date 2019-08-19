//
//  1707 이분그래프 dfs.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 19/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> arr[20001];

int check[20001];
void dfs(int start,int c){
    check[start] = c;
    
    for(int i=0; i<arr[start].size(); i++){
        int x = arr[start][i];
        if(check[x] == false){
            dfs(x, 3-c);
        }
    }
}
int main(void)
{
    int t,v,e,a,b;
    scanf("%d", &t);
    
    while(t--) {
        bool ans=true;
        
        scanf("%d %d", &v, &e);
        for(int i=0; i<e; i++) {
            scanf("%d %d", &a, &b);
            arr[a].push_back(b);
            arr[b].push_back(a);
        }
        
        
        for(int i=1; i<=v; i++) {
            if(check[i]==0) {
                dfs(i,1);
            }
        }
        
        for(int i=1; i<=v; i++){
            for(int j=0; j<arr[i].size(); j++){
                int k = arr[i][j];
                if(check[i] == check[k]){
                    ans = false;
                }
            }
        }
        cout << (ans ? "YES" : "NO") << '\n';
        
        for(int i=0; i<=v; i++) arr[i].clear();
        memset(check,0,sizeof(check));
    }
    return 0;
}

