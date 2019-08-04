//
//  Level1-완주하지못한선수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
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
    
    sort(participant.begin(), participant.end());
    sort(completion.begin(), completion.end());
    
    for(int i=0; i<participant.size(); i++){
        if(participant[i] != completion[i]){
            answer.append(participant[i]);
            break;
        }
    }
    cout << answer;
    
//    for(int i=0; i<participant.size(); i++){
//        for(int j=0; j<completion.size(); j++){
//            if(participant[i] == completion[j]){
//                continue;
//            }else {
//                answer.append(completion[i]);
//            }
//        }
//    }
//    for(int i=0; i<answer.size(); i++){
//        cout << answer[i];
//    }
//
    return 0;
}
