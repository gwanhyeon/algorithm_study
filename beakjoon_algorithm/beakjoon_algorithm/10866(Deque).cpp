//
//  10866(Deque).cpp
//  Algorigm_Study
//
//  Created by kgh on 18/12/2018.
//  Copyright © 2018 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <deque>
#include <string>
using namespace std;

int main(void){
    // STL deque 선언
    deque<int> q;
    // cmd_cnt 변수 값 선언 및 입력
    int cmd_cnt = 0;
    cin >> cmd_cnt;
    // cmd_cnt 값만큼 while문 실행 시간복잡도: 빅오O(N)
    while(cmd_cnt--){
        string str;
        cin >> str;
        // push_front 명령일 경우
        if(str == "push_front"){
            int num =0;
            cin >> num;
            q.push_front(num);
        // push_back 명령일 경우
        }else if(str == "push_back"){
            int num =0;
            cin>>num;
            q.push_back(num);
        // pop_front 명령일 경우
        }else if(str == "pop_front"){
            if(!q.empty()){
                cout << q.front() << endl;
                q.pop_front();
            }else{
                cout << "-1" << endl;
            }
        // pop_back 명령일 경우
        }else if(str == "pop_back"){
            if(!q.empty()){
                cout << q.back() <<endl;
                q.pop_back();
            }else{
                cout << "-1" <<endl;
            }
        // size 명령일 경우
        }else if(str == "size"){
            cout << q.size() << endl;
        }else if(str == "empty"){
            if(!q.empty()){
                cout << "0" <<endl;
            }else{
                cout << "1" <<endl;
            }
        // empty 명령일 경우
        }else if(str == "empty"){
            if(!q.empty()){
                cout << "0" <<endl;
            }else{
                cout << "1" << endl;
            }
        }
        // front 명령일 경우
        else if(str == "front"){
            if(!q.empty()){
                cout << q.front() << endl;
            }else{
                cout << "-1" << endl;
            }
        // back 명령일 경우
        }else if(str == "back"){
            if(!q.empty()){
                cout << q.back() << endl;
            }else{
                cout << "-1" << endl;
            }
        }
    }
    return 0;

}
