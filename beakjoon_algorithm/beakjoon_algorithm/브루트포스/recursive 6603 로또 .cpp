//
//  6603 로또 재귀.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 25/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
 v: 입력 수
 index: 선택할지말지 결정해야하는 인덱스
 cnt: 현재까지 포함한 수의 개수
 
 a
 
 */
#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int n;
vector<int> lotto;

void recursive(vector<int> &v, int index, int cnt){
    
    // 가능
    if(cnt == 6){
        for(int i=0; i<lotto.size(); i++){
            cout <<lotto[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    // 불가능
    if(v.size() == index){
        return;
    }
    // 재귀(선택,비선택)
    lotto.push_back(v[index]);
    recursive(v, index+1, cnt+1);
    lotto.pop_back();
    recursive(v, index+1, cnt);
    
}
int main(void){
    
    while(true){
        cin >> n;
        
        vector<int> v(n);
        if(n == 0){
            break;
        }
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
        recursive(v,0,0);
        cout << '\n';
    }
        
        
        
    return 0;
}
