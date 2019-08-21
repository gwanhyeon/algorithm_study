//
//  섬머코딩 영어 끝말잇기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 21/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void){
    vector<string> v;
    vector<string> s[10];
    
    int n = 3;
    
    v.push_back("tank");v.push_back("kick");v.push_back("know");
    v.push_back("wheel");v.push_back("land");v.push_back("dream");
    int cnt = 0;
    
    for(int i=0; i<v.size(); i++){
        if(cnt + 1 % n == 0){
            cnt = 0;
        }
        s[cnt].push_back(v[i]);
        cnt++;
        
        s[i].at(s[i].size());
        
        
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<s[i].size(); j++){
            cout << s[i][j];
            
        }
    }
    return 0;
}
    
    
