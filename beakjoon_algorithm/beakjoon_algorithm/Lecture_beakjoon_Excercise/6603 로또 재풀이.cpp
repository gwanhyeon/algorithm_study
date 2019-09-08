//
//  6603 로또 재풀이.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
vector<int> lotto;
int check[12];
int n;
void recursive(vector<int> &v, int idx, int cnt){
    
    if(cnt == 6){
        for(int i=0; lotto.size(); i++){
            cout << lotto[i] << ' ';
        }
        cout << '\n';
    }
    
    for(int i=0; i<n; i++){
        if(check[i] == true){
            continue;
        }
        
        check[i] = true;
        lotto.push_back(v[i]);
        recursive(v,i, cnt+1);
        lotto.pop_back();
        check[i] = false;
        
    }
    
    
    
    
}

int main(void){
    
    while(true){
        
        cin >> n;
        vector<int> v(n);
        
        if(n == 0){
            return 0;
        }
    
        for(int i=0; i<n; i++){
            cin >> v[i];
            
        }
        
        recursive(v,0,0);
        
        
        
        
        
    }
    
    return 0;
}
