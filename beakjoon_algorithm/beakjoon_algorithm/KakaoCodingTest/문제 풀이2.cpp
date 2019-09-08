//
//  풀이2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
int check[101][101];
int dist[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};
using namespace std;
string answer = "";
stack<char> s;
int cnt = 0;
bool go(char &str, int len){
    
    
    if(cnt == 0){
        if(cnt == 0){
            return 1;
            //올바른문자열
        }else {
            return 0;
            //올바른문자열이아님 균형잡힌 문자열임
        }
        
    }
    
    if(str == '('){
        s.push('(');
        cnt +=1;
        answer += str;
        
    }else if(str == ')'){
        char a = s.top();
        s.pop();
        
        if(str != a){
            cnt -=1;
        }
    }
    return false;
}

int main(void){
    string p = "(()())()";
    int len = p.size();
    bool check = false;
    for(int i=0; i<len; i++){
        check = go(p[i],len);
    }
    cout << check;
    
    
    
    return 0;
}
