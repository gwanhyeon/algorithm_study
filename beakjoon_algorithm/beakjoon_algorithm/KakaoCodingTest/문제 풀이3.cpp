//
//  풀이3.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 07/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int check1[23][23];
int check2[23][23];

int main(void){
    vector<vector<int>> key ={{0, 0, 0}, {1, 0, 0}, {0, 1, 1}};
    vector<vector<int>> lock ={{1, 1, 1}, {1, 1, 0}, {1, 0, 1}};
    bool answer = false;
    for(int i=0; i<key.size(); i++){
        for(int j=0; j<key[0].size(); j++){
            if(key[i][j] == 1){
                check1[i][j] = 1;
            }
        }
    }
    for(int i=0; i<lock.size(); i++){
        for(int j=0; j<lock[0].size(); j++){
            if(lock[i][j] == 1){
                check2[i][j] = 1;
            }
        }
    }
    
    // 회전하기
    
    for(int k=0; k<4; k++){
        for(int i=0; i<key.size(); i++){
            
            for(int j=0; j<key[0].size(); j++){
                if(key[i][j] == 1){
                    if(key[i][j+2] == 1 && check2[i][j+2] == 1){
                        check2[i][j+2] = 0;
                        check1[i][j+2] = 1;
                    }
                    
                    if(key[i+1][j+1] == 1 && check2[i+1][j+1] == 1){
                        check2[i+1][j+1] = 0;
                        check1[i+1][j+1] = 1;
                    }
                    
                    if(key[i+2][j] == 1 && check2[i+2][j] == 1){
                        check2[i+2][j] = 0;
                        check1[i+2][j] = 1;
                    }
                    if(key[i-1][j+1] == 1 && check2[i-1][j+1] == 1){
                        check2[i-1][j+1] = 0;
                        check1[i-1][j+1] = 1;
                    }
                    if(key[i][j] == 1 && check2[i][j] == 1){
                        check2[i][j] = 0;
                        check1[i][j] = 1;
                    }
                    if(key[i+1][j-1] ==1 && check2[i+1][j-1] == 1){
                        check2[i+1][j-1] = 0;
                        check1[i+1][j-1] = 1;
                    }
                    if(key[i-2][j] == 1 && check2[i-2][j] == 1){
                        check2[i-2][j] = 0;
                        check1[i-2][j] = 1;
                    }
                    if(key[i-1][j-1] == 1 && check2[i-1][j-1] == 1){
                        check2[i-1][j-1] = 0;
                        check1[i-1][j-1] = 1;
                    }
                    if(key[i][j-2] == 1 && check2[i][j-2] == 1){
                        check2[i][j-2] = 0;
                        check1[i][j-2] = 1;
                    }
                }

            }
        }
        int cnt = 0;
        for(int i=0; i<lock.size(); i++){
            for(int j=0; j<lock[0].size(); j++){
                
                if(check2[i][j] == 1){
                    answer = false;
                }else {
                    answer = true;
                }
            }
            
        }
        cout << answer;
        
        
    }
    
    
    
    
    
    return 0;
}
