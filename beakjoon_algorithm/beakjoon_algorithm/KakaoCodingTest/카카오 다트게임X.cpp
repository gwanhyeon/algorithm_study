//
//  카카오 다트게임.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 31/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <string>
#include <vector>
#include <math.h>
#include <iostream>
using namespace std;

10S
arr[i]*10 + arr[i+1]


int main(void){
    string dartResult = "1D2S3T*";
    int result[10];
    int answer = 0;
    int cnt = 0;
    int check = 0;
    for(int i=0; i<dartResult.size(); i++){
        
        if(dartResult[i]-'0' >= 0 && dartResult[i]-'0' <=9){
            if(dartResult[i+1]-'0' >= 0 && dartResult[i+1]-'0' <= 9){
                result[cnt] = ((dartResult[i]-'0') * 10) + (dartResult[i+1]-'0');
                cnt++;
                check = 1;
            }else {
                if(check == 1){
                    check = 0;
                    continue;
                }
                result[cnt] = dartResult[i] -'0';
                cnt++;
            }
        }else{
            if(dartResult[i] == 'S'){
                result[cnt-1] = result[cnt-1];
            }else if(dartResult[i] == 'D'){
                result[cnt-1] = result[cnt-1] * result[cnt-1];
            }else if(dartResult[i] == 'T'){
                result[cnt-1] = result[cnt-1] * result[cnt-1] * result[cnt-1];
            }else if(dartResult[i] == '*'){
                result[cnt-1] = result[cnt-1] * 2;
                result[cnt-2] = result[cnt-2] * 2;
            }else if(dartResult[i] == '#'){
                result[cnt-1] = -result[cnt-1];
            }
        }
    }
    for(int i=0; i<4; i++){
        answer += result[i];
    }
    cout << answer << '\n';
    return 0;
}






//
//string dartResult = "1D2S3T*";
//vector<int> v;
//int answer = 0;
//int n = 0;
//int check = 0;
//int star = 0;
//int hidden = 0;
//for(int i=0; i<dartResult.size(); i++){
//    if(dartResult[i]-'0' == 1 && dartResult[i+1]-'0' == 0){
//        n = 10;
//        check = 1;
//        continue;
//    }
//    if(dartResult[i]-'0' >= 0 && dartResult[i]-'0' <=9 && check == 0){
//        n=dartResult[i]-'0';
//    }
//    if(dartResult[i] == 'S'){
//        v.push_back(pow(n,1));
//    }
//    if(dartResult[i] == 'D'){
//        v.push_back(pow(n,2));
//    }
//    if(dartResult[i] == 'T'){
//        v.push_back(pow(n,3));
//    }
//    if(dartResult[i] == '*'){
//
//        for(int i=1; i<v.size()-1; i++){
//            v[i] = v[i] * 2;
//        }
//        v.push_back(n*2);
//
//    }
//    if(dartResult[i] == '#'){
//        v[v.size()-1] = v[v.size()-1] * -1;
//        for(int i=0; i<v.size()-1; i++){
//            v[i] = v[i] * 2;
//        }
//        //            v.push_back(v[v.size()-1]*(-1));
//    }
//}
//
//for(int i=0; i<v.size(); i++){
//    answer += v[i];
//
//}
//cout << answer << ' ';
