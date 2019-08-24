//
//  13913 숨바꼭질4.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 24/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
const int MAX = 200000;
using namespace std;
queue<int> q;
int check[200001];
int dist[200001];
int dir[200001];

void print(int n,int m){
    if(n != m){
        print(n,dir[m]);
    }
    cout << m << ' ';
}

void bfs(int x){
    q.push(x);
    check[x] = 1;
    dist[x] = 0;
    while(!q.empty()){
        int mx = q.front();
        q.pop();
        if(mx-1 >= 0){
            if(check[mx-1] == 0){
                q.push(mx-1);
                check[mx-1] = 1;
                dist[mx-1] = dist[mx] + 1;
                dir[mx-1] = mx;
            }
        }
        if(mx+1 < MAX){
            if(check[mx+1] == 0){
                q.push(mx+1);
                check[mx+1] = 1;
                dist[mx+1] =dist[mx] + 1;
                dir[mx+1] = mx;
            }
        }
        if(mx*2 < MAX){
            if(check[mx*2] == 0){
                q.push(mx*2);
                check[mx*2] = 1;
                dist[mx*2]= dist[mx]+1;
                dir[mx*2] = mx;
            }
        }
    }
}
int main(void){
    int m,n;
    cin >> m >> n;
    bfs(m);
    cout << dist[n] << '\n';
    print(m,n);
    cout << '\n';
    
    
    return 0;
}
