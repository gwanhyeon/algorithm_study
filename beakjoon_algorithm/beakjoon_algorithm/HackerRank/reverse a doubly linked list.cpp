//
//  reverse a doubly linked list.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;

int main(void){
    // # input : testcase, link number, value, insert value
    list<int> llist;
    list<int>::iterator iter;
    
    int t; //
    int n; // number
    cin >> t;
    cin >> n;
    
    // Test Case
    while(t--){
        int value;
        for(int i=0; i<n; i++){
            cin >> value;
            llist.push_back(value);
        }
    }
    llist.reverse();
    for(iter = llist.begin(); iter != llist.end(); iter++){
        cout << *iter <<"\n";
    }
    return 0;
}
