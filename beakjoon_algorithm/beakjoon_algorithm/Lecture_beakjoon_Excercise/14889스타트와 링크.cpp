//
//  14889스타트와 링크.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 10/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
using namespace std;
int s[20][20];
int n;
// main go(0,first,second);
//
//int go(int index, vector<int> first, vector<int> second){
//    // 정답까지 찾은경우
//    int t1,t2 = 0;
//    if(index == n){
//        if(first.size() != n/2){
//            return -1;
//        }
//        if(second.size() != n/2){
//            return -1;
//        }
//
//        for(int i=0; i<n/2; i++){
//            for(int j=0; j<n/2; j++){
//                if(i == j){
//                    continue;
//                }
//                t1 += s[first[i]][first[j]];
//                t2 += s[second[i]][second[j]];
//            }
//        }
//        int diff;
//        diff = t1 - t2;
//        if(diff < 0){
//            diff = -diff;
//        }
//        return diff;
//
//    }
//    if(first.size() == n/2){
//        return -1;
//    }
//    if(second.size() == n/2){
//        return -1;
//    }
//    int ans = -1;
//    first.push_back(index);
//    go(index+1,first,second);
//    if(ans != -1 || (t1 != -1 && ans > t1)){
//        ans = t1;
//    }
//    first.pop_back();
//
//    second.push_back(index);
//    go(index+1, first, second);
//
//    if(ans != -1 || (t2 != -1 && ans > t2)){
//        ans = t2;
//
//    }
//    second.pop_back();
//
//    return ans;
//
//
//}
int go(int index, vector<int> first, vector<int> second){
    //정답찾은경우
    if(index == n){
        if(first.size() != n/2){
            return -1;
        }
        if(second.size() != n/2){
            return -1;
        }
        int t1 = 0;
        int t2 = 0;
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n/2; j++){
                if(i == j){
                    continue;
                }
                t1 += s[first[i]][first[j]];
                t2 += s[second[i]][second[j]];
            }
        }
        int diff =t1-t2;
        if(diff < 0){
            diff = -diff;
        }
        return diff;
    }
    if(first.size() > n/2){
        return -1;
    }
    if(second.size() > n/2){
        return -1;
    }
    int ans = -1;
    //첫번쨰 사람 넣고 뺴주는 과정임
    first.push_back(index);
    int t1 = go(index+1,first,second);
    if(ans == -1 || (t1 != -1 && ans > t1)){
        ans = t1;
    }
    // 두번째 사람 넣고 빼주는 과정
    first.pop_back();
    second.push_back(index);
    int t2 = go(index+1, first, second);
    if(ans == -1 || (t2 != -1 && ans > t2)){
        ans = t2;
    }
    second.pop_back();
    return ans;
    
    
    
}

int main(void){
    
    cin >> n;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            cin >> s[i][j];
        }
    }
    vector<int> first, second;
    cout << go(0,first,second);
//  사람이 0명일떄

}


