//
//  Level1-서울에서김서방찾기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

using namespace std;
int main(void){
    
    string str[1001] = {"Jane","kim"};
    int size = sizeof(str)/sizeof(str[0]);
    
    string answer = "";
    vector<string> seoul;
    seoul.push_back("Jane");
    seoul.push_back("kim");
    
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i] == "kim"){
            string str = to_string(i);
            answer += "김서방은" + to_string(i) + "에 있다";
            
        }
    }
    cout << answer;
    

    
    
    
    return 0;
}
#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "";
    answer += "김서방은";
    for(int i=0; i<seoul.size(); i++){
        if(seoul[i] == "Kim"){
            answer += to_string(i);
        }
    }
    answer += "에 있다";
    
    
    return answer;
}
