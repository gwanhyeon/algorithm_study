//
//  13549 숨바꼭질3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <queue>
#define MAX 100001
using namespace std;
int dist[100001];
int check[100001];
int n,m;
queue<int> q;
queue<int> next_q;

int main(void){
    cin >> n >> m;
    check[n] = 1;
    dist[n] = 0;
    q.push(n);
    
    while(!q.empty()){
        int dx = q.front();
        q.pop();
        if(dx * 2 < MAX){
            if(check[dx*2] == 0){
                check[dx*2] = 1;
                dist[dx*2] = dist[dx];
                q.push(dx*2);
            }
        }
        if(dx-1 >= 0){
            if(check[dx-1] == 0){
                check[dx-1] = 1;
                dist[dx-1] = dist[dx] + 1;
                next_q.push(dx-1);
            }
        }
        if(dx+1 < MAX){
            if(check[dx+1] == 0){
                check[dx+1] = 1;
                dist[dx+1] = dist[dx] +1;
                next_q.push(dx+1);
            }
        }
       
        if(q.empty()){
            q = next_q;
            next_q = queue<int>();
        }
    }
    cout << dist[m] << '\n';
    return 0;
}
