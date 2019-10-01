//
//  N2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 29/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//


/*
 빈도수 가장 높은것들
 특수 queue
 
 FQ에 저장
 
 */



#include <stdio.h>
#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int main(void){
    
    int n;
    cin >> n;
    vector<int> v1;
    map<int,int> m;
    int max=0;
    while(n--){
        string str = "";
        cin >> str;
        int num = 0;
        cin >> num;
        
      
        
        if(str == "enqueue"){
            v1.push_back(num);
            m[num]++;
        }else {
            
            for(auto it = m.begin(); it != m.end(); it++){
                if(max < it->second){
                    max = it->first;
                    
                }
    
            }
            
        
            
            for(int i=0; i<v1.size(); i++){
                if(v1[i] == max){
                    v1.erase(v1.begin()+i);
                    break;
                }
            }
        }
     
    }
    for(int i=0; i<v1.size(); i++){
        cout << v1[i] << ' ';
    }
    
    
    
    
    return 0;
}
