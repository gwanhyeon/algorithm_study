//
//  6603 로또.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int check[6];
vector<int> lotto;

void recursive(vector<int> &v,int idx,int cnt){
    
    
    if(cnt == 6){
        for(int i=0; i<lotto.size(); i++){
            cout << lotto[i] << ' ';
        }
        cout << '\n';
        return;
    }
    
    int num = v.size();
    
    if(num == idx){
        return;
    }
    lotto.push_back(v[idx]);
    recursive(v,idx+1,cnt+1);
    lotto.pop_back();
    recursive(v,idx+1,cnt);
    
    
    
}
int main(void){
    while(true){
        int n;
        cin >> n;
        if(n == 0){
            break;
        }
        vector<int> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }
   
        recursive(v,0,0);
        cout << '\n';
    }
    
    return 0;
}
