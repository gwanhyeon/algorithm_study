//
//  프로그래머스 큰수 만들기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/06/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <string>
#include <vector>
#include <iostream>
using namespace std;

string solution(string number, int k) {
    string answer = "";
    string str_k =to_string(k);
    
    int start = number.find(str_k);
    number.erase(start,1);
    
    string v[10];
    for(int i=0; i<number.size(); i++){
        for(int j=0; j<number.size(); j++){
            if(i == j){
                continue;
            }
            v[i] = number[i] + number[j]);
        }
    }
    for(int i=0; i<v.size(); i++){
        cout << str(v[i]);
    }
    return answer;
}
