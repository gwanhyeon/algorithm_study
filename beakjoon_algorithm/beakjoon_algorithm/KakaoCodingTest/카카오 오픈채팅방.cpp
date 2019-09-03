//
//  카카오 오픈채팅방.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <set>
#include <vector>
#include <stdlib.h>
#include <sstream>
#include <string>
using namespace std;
vector<string> split(const string& str){
    vector<string> splited;
    if(str.size() > 0) splited.push_back("");
    for(int i = 0; i < str.size(); i++){
        if(str[i] == ' '){
            if(splited.back() != "") splited.push_back("");
            continue;
        }
        splited.back().push_back(str[i]);
    }
    if(splited.back() == "") splited.pop_back();
    return splited;
}
int main(void){
    set<string> result;
    vector<string> s;
    vector<string> record;
    record = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
    
    
    for(int i=0; i<record.size(); i++){
        s = split(record[i]);
        
        string store;
        for(int j=0; j<s.size()-1; j++){
            
            if(s[j] == "Enter" || store == "Enter"){
                if(j == 0){
//                    cout << s[j+1] << "님이 들어왔습니다.\n";
                    store = s[j];
                }else {
                result.insert(s[j+1]);
                }
                
            }else if(s[j] == "Leave" || store == "Leave"){
                if(j ==0){
//                    cout << s[j+1] << "님이 나갔습니다.\n";
                    store = s[j];
                }else {
                    result.erase(s[j+1]);
                }
                
            }
        }
    }
    for(auto it = result.begin(); it !=result.end(); ++it){
        cout << *it << "님이 들어왔습니다.\n";
    }

    
    
    
    
    
    return 0;
}
