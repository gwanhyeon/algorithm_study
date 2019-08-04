//
//  Level1-완주하지못한선수(Hash).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;
int main(void){
    
    string answer = "";
    vector<string> participant;
    vector<string> completion;
    participant.push_back("leo");
    participant.push_back("kiki");
    participant.push_back("eden");
    completion.push_back("leo");
    completion.push_back("kiki");
    
    // hash, unordered_map
    unordered_map<string,int> strMap;
    
    for(auto element : completion){
        if(strMap.end() == strMap.find(element)){
            strMap.insert({element,1});
        }else{
            strMap[element]++;
        }
    }
    
    for(auto element: participant){
        if(strMap.end() == strMap.find(element)){
            answer = element;
            break;
        }else{
            strMap[element]--;
            if(strMap[element] < 0){
                answer = element;
                break;
            }
        }
    }
    
    
    cout << answer;
    
}
