//
//  문자열 연습.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <iostream>
using namespace std;



bool find(string &a, string &b){
    if(a.size() < b.size()){
        return false;
    }
    
    for(int st=0; st<=a.size() - b.size(); st++){
        bool check = true;
        for(int i=st; i<st+b.size(); i++){
            
            if(a[i] != b[i-st]){
                check =false;
                break;
            }
            
        }
        if(check){
            return true;
        }
    }
    return false;
}


int main(void){
//
//    string str = "a b c d";
//
//    int result = str.find('b');
//    string a = str.substr(str.find('b'),3);
//    cout << a;
//
//
    string s = "aabbccdd";
    
    // a 시작 aa 말고 다른 문자 나올때 까지진행
    // i는 전체적인 문자열의 개수
    // j는 하나문자 비교 그이후에 2개씩 묶어서 비교
    // 1 = 0+1, 2 = 1+1, 3 = 2+1
    
    // 1,0 1,1 1,
//    for(int i=1; i<=s.size(); i++){
//        string store,curr = "";
//        int cnt=1;
//
//        for(int j=0; j<s.size(); j=j+i){
//            curr = s.substr(j,i);
//            if(j == 0){
//                store = s.substr(j,i);
//                continue;
//            }
//            if(curr == store){
//                cnt +=1;
//            }
//            if(curr !=store){
//                store = curr;
//
//            }
//        }
//        cout << '\n';
//    }
    string a = "AAAAB";
    string b = "AA";
    cout << find(a,b) << '\n';
    
    
}
