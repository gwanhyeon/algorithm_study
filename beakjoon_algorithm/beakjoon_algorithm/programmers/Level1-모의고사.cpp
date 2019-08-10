//
//  Level1-모의고사.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>

int st1[5] = {1,2,3,4,5};
int st2[8] = {2,1,2,3,2,4,2,5};
int st3[10] = {3,3,1,1,2,2,4,4,5,5};

using namespace std;
int main(void){
    vector<int> answer;
    int winner;
    answer.push_back(1);answer.push_back(2);answer.push_back(3);answer.push_back(4);answer.push_back(5);
    vector<int> st_score(3);
    
    for(int i=0; i<answer.size(); i++){
        
        if(st1[i % 5] == answer[i]){
            st_score[0]++;
        }
        if(st2[i % 8] == answer[i]){
            st_score[1]++;
        }
        if(st3[i % 10] == answer[i]){
            st_score[2]++;
        }
    }
    winner = max(max(st_score[0], st_score[1]),st_score[2]);
    cout << winner;
    for(int i=0; i<st_score.size(); i++){
        if(winner == st_score[i]){
            cout << i+1;
        }
    }
    return 0;
}
