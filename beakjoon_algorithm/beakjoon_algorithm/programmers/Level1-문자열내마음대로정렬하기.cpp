//
//  Level1-문자열내마음대로정렬하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int index;

bool compare(string a, string b){
    if(a[index] != b[index]){
        return a[index] < b[index];
    }else {
        return a < b;
    }
}
int main(void){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    vector<string> str;
    str.push_back("sun");
    str.push_back("bed");
    str.push_back("car");
    
    
    sort(str.begin(), str.end(), compare);
    
    for(auto a : str){
        cout << a;
    }
    
    
    
    
    
    
    
}
