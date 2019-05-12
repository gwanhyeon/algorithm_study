//
//  10866덱.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 12/05/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <bits/stdc++.h>
using namespace std;
const int MX = 1000007;
int dat[2*MX];
int head = MX;
int tail = MX;
void push_front(int val){
        dat[--head] = val;
    
}
void push_back(int val){
//    if(tail != 0){
        dat[tail++] = val;
        
//    }
    
}
void pop_front(){
    head++;
}
void pop_back(){
    tail--;
    
}
int front(){
    return dat[head];
}
int back(){
    return dat[tail-1];
}
int main(void){
    ios::sync_with_stdio(0);cin.tie(0);
    /*
     push_front, push_back, pop_front, pop_back
     size, empty, front, back
    */
    int n;
    cin >> n;
    // TC
    while(n--){
        // str input
        
        string str;
        cin >> str;
        
        if(str == "push_front"){
            int num;
            cin >> num;
            push_front(num);
        }else if(str == "push_back"){
            int num;
            cin >> num;
            push_back(num);
        }else if(str == "pop_front"){
            if(head == tail){
                cout << -1 <<'\n';
            }else{
                cout << front() << '\n';
                pop_front();
            }
        }else if(str == "pop_back"){
            if(tail == head){
                cout << -1 << '\n';
            }else{
                cout << back() << '\n';
                pop_back();
            }
        }else if(str == "size"){
            cout << tail-head << '\n';
        }else if(str == "empty"){
            cout << (tail==head) << '\n';

        }else if(str == "front"){
            if(tail==head){
                cout << -1 << '\n';
            }else{
            cout << front() << '\n';
            }
        }else if(str == "back"){
            if(tail==head){
                cout << -1 << '\n';
            }else{
            cout << back() << '\n';
            }
        }
    }
    
    return 0;
}
