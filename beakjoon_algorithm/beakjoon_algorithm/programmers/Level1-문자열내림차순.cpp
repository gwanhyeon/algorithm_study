//
//  Level1-문자열내림차순.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>

#include <string>
#include <vector>
using namespace std;

// char
bool compare(char a, char b){
    if(a==b){
        return a > b;
    }
    
    return a>b;
    // string
//    if(a.length() != b.length()){
//        return a.length() < b.length();
//    }else {
//        return a < b;
//    }s
}
int main(void){
    string str = "Zbcdefg";
    sort(str.begin(),str.end(),compare);    // 내림차순
    cout << str;
    return 0;
    
}
