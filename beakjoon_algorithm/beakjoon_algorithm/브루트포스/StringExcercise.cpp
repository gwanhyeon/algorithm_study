//
//  StringExcercise.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 24/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>
using namespace std;
int main(void){
    
    
    string str = "abaaaa";
    
    vector<int> v;
    int index = 0;
    for(int i=0; i<str.size(); i++){
        for(int j=i; j<str.size(); j++){
            
            if(str[j] == str[j+1] && str[j+1] == str[j+2]){
                string a = str.substr(i,j+2-i);
                int b = a.length();
                v.push_back(b);
                index++;
                break;
            }
        }
    }
    if(index == 0){
        string c = str.substr(0,str.size());
        int d = c.length();
        v.push_back(d);
    }
    
    int ans = -1;
    for(auto a : v){
        if(a > ans){
            ans = a;
        }
    }
    cout << ans;
}

