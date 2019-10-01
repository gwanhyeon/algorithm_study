//
//  NM시리즈(12).cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>


using namespace std;
// 중복 조합
int n,m;
int arr[10001];
vector<int> res;
set<string> s;


void go(int index,int cnt){
    
    if(cnt == m){
        
//        bool tf_acs = false;
//        if(m == 1){
//            tf_acs = true;
//        }else {
//            for(int i=0; i<res.size()-1; i++){
//                if(res[i] > res[i+1]){
//                    tf_acs = false;
//                }else if(res[i] <= res[i+1]){
//                    tf_acs = true;
//                }
//            }
//        }
        
        
        // 중복 체크
        bool tf = false;
        string str ="";
        for(int i=0; i<res.size(); i++){
            char a = res[i] + '0';
            str = str + a;
            
        }
        if(s.find(str) == s.end()){
            s.insert(str);
            tf = true;
        }else {
            tf = false;
            
        }
        
       
        if(tf == true){
            for(int i=0; i<res.size(); i++){
                cout << res[i] << ' ';
                
            }
            cout << '\n';
        }
        return;
    }
    for(int i=index; i<n; i++){
        res.push_back(arr[i]);
        go(i,cnt+1);
        res.pop_back();
        
    }
}

int main(void){
    cin >> n >> m;
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    sort(arr, arr+n);
    
    go(0,0);
    
    
    return 0;
}
