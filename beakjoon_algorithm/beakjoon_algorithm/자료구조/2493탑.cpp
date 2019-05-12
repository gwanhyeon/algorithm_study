//
//  2493탑.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//https://casterian.net/archives/120
//https://yaaaajk.tistory.com/4


// 한번 다시 풀어볼 것 권장!
// stack<int,int> 를 써야 할경우 첫번쨰, 두번째 값에 대한 인덱스 값을 가지고 있어야 할경우 stack 으로 처리 하면 간단하게 처리 할 수 있음.
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

int main(void){
    int n;
    cin >> n;
    // index
    stack<pair<int,int>> S;
    vector<int> v;
    
    // 하나의 벡터에 모든값들을 넣어준다.
    for(int i=0; i<n; i++){
        int h;
        cin >> h;
        v.push_back(h);
    }
    
    for(int i=0; i<n; i++){
        if(S.empty()){
            cout << "0 ";
            S.push(make_pair(v[i],i+1));
        }else{
            while(S.top().first < v[i]){
                S.pop();
                if(S.empty()){
                    break;
                }
            }
            if(S.empty()){
                cout << "0 ";
            }else{
                cout << S.top().second << " ";
                
            }
            S.push(make_pair(v[i],i+1));
        }
        
    }
    return 0;
}
/*
 stack<pair<int,int>> S;
 // 레이저를 쏜 위치와 값을 중에서 몇번째 레이저 인지 저장시켜놓아야하므로,
 // stack Pair를 사용한다.
 
 Test Case
 5
 6 9 5 7 4
 */
