//
//  9019 DSLR.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 24/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <deque>
#include <vector>
using namespace std;
int t;
int check[10001];


deque<int> a;
deque<int> b;

void bfs(vector<int> &x, vector<int> &y){
    
    while(!a.empty() && !b.empty()){
        
    }
    
    
}
int main(void){
    
    cin >> t;
    while(t--){
        int x,y;
        for(int i=0; i<4; i++){
            scanf("%1d ",&x);
            a.push_back(x);
        }
        for(int i=0; i<4; i++){
            scanf("%1d",&y);
            b.push_back(y);
        }
        bfs();
        a.clear();
        b.clear();
    }
    
    return 0;
    
}
