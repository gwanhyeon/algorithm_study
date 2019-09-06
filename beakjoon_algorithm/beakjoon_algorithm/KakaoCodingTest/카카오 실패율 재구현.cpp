//
//  카카오 실패율 재구현.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;

bool compare(pair<int,double> &a, pair<int,double> &b){
    if(a.second == b.second){
        return a.first <b.first;
    }
    return a.second > b.second;
}
using namespace std;
int main(void){
    vector<int> stages = {2, 1, 2, 6, 2, 4, 3, 3};
//    vector<int> stages = {4,4,4,4,4};
    vector<int> answer;
    int n = 5;
    vector<pair<int,double>> v;
        int check =0;
    for(int i=1; i<=n; i++){
        int clear_num = 0;
        int none_clear_num = 0;
        double result = 0.0;
        for(int j=0; j<stages.size(); j++){
            // 한 사람이 스테이지에 도달한놈
            if(stages[j] == i){
                clear_num +=1;
                none_clear_num +=1;
            }if(stages[j] > i){
                clear_num +=1;
            }
            
            // 스테이지 도달은 했으나 클리어를 못한놈들 같은놈들
        }
        if(clear_num == 0){
            result = 0;
            v.push_back({i,result});
        }else if(clear_num == n){
            check +=1;
        }
        else {
            result = ((double)none_clear_num /(double)clear_num) * 100;
            v.push_back({i,result});
        }
    }
    if(check == n){
        v.clear();
        for(int i=1; i<=n; i++){
            if(i == n){
                v.push_back({i,1});
            }else{
                v.push_back({i,0});
            }
            
        }
    }
    sort(v.begin(),v.end(),compare);
    
    for(int i=0; i<v.size(); i++){
        answer.push_back(v[i].first);
     
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i];
    }
    
    
    
    
}
