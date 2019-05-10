//
//  링크드리스트벡터형식.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 11/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pre[MX];
int nxt[MX];
int unused = 1;

// INSERT
int insert(int idx, char val){
    dat[unused] = val;
    pre[unused] = idx;
    nxt[unused] = nxt[idx];
    
    if(nxt[idx] != -1){
        pre[nxt[idx]] = unused;
        nxt[idx] = unused;
        unused++;
        return nxt[idx];
    }
}
// DELETE
int erase(int idx){
    nxt[pre[idx]]= nxt[idx];
    if(nxt[id] != -1 ){
        pre[nxt[idx]] = pre[idx];
    }
    return pre[idx];
    
}
// TRAVERSAL
void traversal(){
    int cur = nxt[0];
    while(cur != -1){
        cout << dat[cur];
        cur = nxt[cur];
    }
}
int main(void){
    
    fill(pre,pre+MX,-1);
    fill(nxt,nxt+MX,-1);
    
    
    
    
}
