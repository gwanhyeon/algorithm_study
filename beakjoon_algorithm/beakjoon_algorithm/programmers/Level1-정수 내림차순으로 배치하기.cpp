//
//  Level1-정수 내림차순으로 배치하기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 13/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
int main(void){
    long long answer = 0;
    long long n = 118372;
    int var = 1;
    int count = 0;
    vector <int>num;
    
    while(n > 0){
        num.push_back(n % 10);
        n /= 10;
    }
    sort(num.begin(),num.end());
    for(int i=0; i<num.size(); i++){
        answer += num[i] * var;
        var*= 10;
    }
    
//    int n=118372;
//    string str;
//    str = to_string(n);
//    vector<char> v;
//
//    for(int i=0; i<str.size(); i++){
//        v.push_back(str[i]);
//
//    }
//    str.clear();
//    sort(v.begin(),v.end());
//    reverse(v.begin(), v.end());
//    for(int i=0; i<v.size(); i++){
//        str += v[i];
//    }
//    long long answer = atoi(str.c_str());
//    cout << answer;

    return 0;
}
