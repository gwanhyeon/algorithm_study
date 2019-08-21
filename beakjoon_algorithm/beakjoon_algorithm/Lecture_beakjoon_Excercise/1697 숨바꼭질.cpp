//
//  1697 숨바꼭질.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200000;
int dist[MAX+1];
int check[MAX+1];
int m,n;
int dir[3] = {1,-1,2};
queue<int> q;
int cnt = 0;

void bfs(int x){
    dist[x] = 0;
    q.push(x);
    check[x] = 1;
    
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        
        for(int i=0; i<3; i++){
            int mx;
            if(i == 2){
                mx = (dx * dir[i]);
            }else if(i == 1){
                mx = (dx + dir[i]);
            }else{
                mx = (dx + dir[i]);
            }
            if(mx >= 0 && mx < MAX){
                if(check[mx] == 0){
                    dist[mx] = dist[dx] + 1;
                    check[mx] = 1;
                    q.push(mx);
                }
            }
        }
    }
}
int main(void){
    
    cin >> m >> n;
    bfs(m);
    cout << dist[n] << '\n';
    return 0;
}

