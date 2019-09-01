//
//  카카오 다트게임.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 31/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;


int main(void){
    string dartResult = "1D2S3T*";
    vector<int> v;
    int answer = 0;
    int n = 0;
    int check = 0;
    int star = 0;
    int hidden = 0;
    for(int i=0; i<dartResult.size(); i++){
        if(dartResult[i]-'0' == 1 && dartResult[i+1]-'0' == 0){
            n = 10;
            check = 1;
            continue;
        }
        if(dartResult[i]-'0' >= 0 && dartResult[i]-'0' <=9 && check == 0){
            n=dartResult[i]-'0';
        }
        if(dartResult[i] == 'S'){
            v.push_back(pow(n,1));
        }
        if(dartResult[i] == 'D'){
            v.push_back(pow(n,2));
        }
        if(dartResult[i] == 'T'){
            v.push_back(pow(n,3));
        }
        if(dartResult[i] == '*'){
            
            for(int i=1; i<v.size()-1; i++){
                v[i] = v[i] * 2;
            }
            v.push_back(n*2);
    
        }
        if(dartResult[i] == '#'){
            v[v.size()-1] = v[v.size()-1] * -1;
            for(int i=0; i<v.size()-1; i++){
                v[i] = v[i] * 2;
            }
//            v.push_back(v[v.size()-1]*(-1));
        }
    }
    
    for(int i=0; i<v.size(); i++){
        answer += v[i];
        
    }
    cout << answer << ' ';
    
    return 0;
}
