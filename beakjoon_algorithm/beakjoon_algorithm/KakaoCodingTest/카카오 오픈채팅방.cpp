//
//  카카오 오픈채팅방.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main(void){
    vector<string> answer;
    vector<string> v = {"Enter uid1234 Muzi","Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    map<string,string> m;
    queue<pair<string,string>> q;
    
    for(int i=0; i<v.size(); i++){
        vector<string> result;
        string str;
        
        for(int j=0; j<v[i].size(); j++){
            if(v[i][j] ==' '){
                result.push_back(str);
                str.clear();
            }else {
                str += v[i][j];
            }
        }
        result.push_back(str);
        
        if(result[0] == "Enter"){
            q.push({result[0],result[1]});
            m[result[1]] = result[2];
        }else if(result[0] == "Leave"){
            q.push({result[0],result[1]});
        }else if(result[0] == "Change"){
            m[result[1]] = result[2];
        }
    }
        
    while(!q.empty()){
        string x = q.front().first;
        string y = q.front().second;
        string all;
        q.pop();
        if(x == "Enter"){
            all += (m[y] +"님이 들어왔습니다.");
        }else if(x == "Leave"){
            all += (m[y] +"님이 나갔습니다.");
        }
        answer.push_back(all);
        
    }
    for(int i=0; i<answer.size(); i++){
        cout << answer[i] << '\n';
    }
    return 0;
}
