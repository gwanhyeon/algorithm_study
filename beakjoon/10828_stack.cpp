//
//  10828_stack.cpp
//  Algorigm_CodingTest
//
//  Created by kgh on 2018. 4. 9..
//  Copyright © 2018년 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(void){
    
    int n;
    cin >> n;
    
    // 범위가 주어지지않았으므로, n값을 입력을 받아서 문제를 푼다
    
    // STL stack Using
    stack<int> s;
    
    while(n--){
        string cmd;
        cin >> cmd;
        if(cmd == "push"){
            int num;
            cin >> num;
            s.push(num);
            
        }else if(cmd=="top"){
            cout << (s.empty() ? -1 : s.top()) << endl;
            
        }else if(cmd=="size"){
            cout << (s.size()) << endl;
            
        }else if(cmd=="empty"){
            cout << (s.empty()) << endl;
            
        }else if(cmd =="pop"){
            cout << (s.empty() ? -1 : s.top()) <<endl;
            
            // pop을 할때 이값을 출력을 할 수 는 없는것같다. 그렇기 때문에
            // s.top값을 출력한 이후에 s.pop만 실행한다.
            
            if(!s.empty()){
                s.pop();
            }
        }
        
        
    }
    
    
    
    
    
    
    
    
    
    
    
    
    
//
//    while (n--) {
//        string cmd;
//        cin >> cmd;
//        if (cmd == "push") {
//            int num;
//            cin >> num;
//            s.push(num);
//        } else if (cmd == "top") {
//            cout << (s.empty() ? -1 : s.top()) << '\n';
//        } else if (cmd == "size") {
//            cout << s.size() << '\n';
//        } else if (cmd == "empty") {
//            cout << s.empty() << '\n';
//        } else if (cmd == "pop") {
//            cout << (s.empty() ? -1 : s.top()) << '\n';
//            if (!s.empty()) {
//                s.pop();
//            }
//        }
//    }

}
