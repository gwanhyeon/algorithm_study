//
//  Level1-문자열내p와y의개수.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>


using namespace std;
int main(void){
    string str = "pPooyY";
    bool answer = false;
    int cnt_p= 0;
    int cnt_y= 0;
    for(auto element : str){
        if(element=='p' || element == 'P'){
            cnt_p++;
        }else if(element == 'y' || element == 'Y'){
            cnt_y++;
        }
    }
//    for(int i=0; i<str.size(); i++){
//        if(str[i]=='p' || str[i] == 'P'){
//            cnt_p++;
//        }else if(str[i] == 'y' || str[i] == 'Y'){
//            cnt_y++;
//        }
//    }
    if(cnt_p == cnt_y){
        answer = true;
    }
    cout << answer;
    return 0;
    
}
