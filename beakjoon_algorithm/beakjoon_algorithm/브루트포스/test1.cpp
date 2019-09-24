//
//  test1.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 22/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <sstream>
#include <vector>
#include <string>
#include <iostream>
#include <regex>
#include <stack>

using namespace std;
int main(void){
    
    stack<string> s;
    vector<string> result;
    string a;
    int check = -1;
    vector<string> input= {"RECEIVE abcd@naver.com","RECEIVE zzkn@naver.com", "DELETE", "RECEIVE qwerty@naver.com", "SAVE", "RECEIVE QwerTY@naver.com"};
    
    for(int i=0; i<input.size(); i++){
        for(int j=0; j<input[i].size(); j++){
            if(input[i][0] == 'R'){
                if(input[i][j] == ' '){
                    string q = input[i].substr(j+1,input[i].size()-j);
                    s.push(q);
                }
                
            }
            if(input[i][0] == 'D' && !s.empty()){
                s.pop();
                break;
            }
            if(input[i][0] == 'S' && !s.empty()){
                int s_size=s.size();
                for(int k=0;k<s_size; k++){
                    result.push_back(s.top());
                    s.pop();
                }
                s.empty();
                
            }
        }
    }
    for(int i=0; i<result.size(); i++){
        cout << result[i] << '\n';
    }
}

//        for(int i=0; i<input.size(); i++){
//
//
//        stringstream ss(input[i]);
//        string item;
//
//        int len = input[i].size();
//        int cnt =0;
//
//            while(getline(ss,item,' ')){
//                // 기능 처리
//                if(item == "RECEIVE"){
//                    check = 1;
//                    continue;
//                }else if(item == "DELETE"){
//                    check = 2;
//                    break;
//                }else if(item == "SAVE"){
//                    check = 3;
//                    break;
//                }
//                if(check == 1){
//                    s.push(item);
//                    check = 0;
//                }else if(check == 2){
//                    s.pop();
//                    check = 0;
//                }else if(check == 3){
//                    for(int i=0; i<s.size(); i++){
//                        result.push_back(s.top());
//                        s.pop();
//                    }
//                    check = 0;
//                }
//            }
//        }
//
//}

        
//        // 공백처리
//        if(item[0]== '['){
//            std::string s(1,item[1]);
//            result.push_back(s);
//            continue;
//        }else if(item[1]==']'){
//            std::string s1(1,item[0]);
//            result.push_back(s1);
//            continue;
//        }
//
//        result.push_back(item);
    
    
    
//
//
//    stringstream ss(input);
//    string item;
//    vector<string> result;
//    while(getline(ss,item,' ')){
//
//        cout << item;
//        getline(ss,item,'[');
//
//        cout << item;
//        getline(ss,item,']');
//
//        result.push_back(item);
//        cout << item;
//        cout << '\n';
//    }
//    }
//}
