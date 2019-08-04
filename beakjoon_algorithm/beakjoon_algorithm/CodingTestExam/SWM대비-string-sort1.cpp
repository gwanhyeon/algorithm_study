//
//  SWM대비-string-sort1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
string str[1001];

bool compare(string a,string b){
    int sum_a =0;
    int sum_b =0;
    if(a.length() != b.length()){
        if(a.length() < b.length()){
            return 1;
        }else if(a.length() > b.length()){
            return 0;
        }
    }else if(a.length() == b.length()){
        for(int i=0; i<a.length(); i++){
            if(a[i]-'0' <= 9 && a[i]-'0'>= 0){
                sum_a += a[i]-'0';
            }
            
        }
        for(int i=0; i<b.length(); i++){
            if(b[i]-'0' <= 9 && b[i]-'0' >=0){
                sum_b += b[i]-'0';
            }
        }
        if(sum_a < sum_b){
            return 1;
        }else if(sum_a > sum_b){
            return 0;
        }
    }
    return a<b;
}
int main(void){
    
    int n;
    cin >> n;
    
    for(int i=0; i<n; i++){
        cin >> str[i];
    }
    
    sort(str,str+n,compare);
    for(int i=0; i<n; i++){
        cout << str[i] << '\n';
    }

    return 0;
}
