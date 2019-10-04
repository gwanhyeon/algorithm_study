//
//  14499 주사위굴리기.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 01/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;

int map[20][20];
int sqaure_map[6];
int cmd[1001];
int n,m;
int start,last;
int cmd_num;

int main(void){
    
    cin >> n >> m >> start >> last >> cmd_num;

    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            cin >> map[i][j];
        }
    }
    for(int i=0; i<cmd_num; i++){
        cin >> cmd[i];
    }
    

    for(int i=0; i<cmd_num; i++){

       
        if(start < 0 || start >= n || last < 0 || last >= m){
            continue;
        }
        // 동
        if(cmd[i] == 1){
            last++;
            if(last < 0 || last >= m){
                last--;
                continue;
            }
            int temp = sqaure_map[4];
            sqaure_map[4] = sqaure_map[0];
            sqaure_map[0] = sqaure_map[5];
            sqaure_map[5] = sqaure_map[1];
            sqaure_map[1] = temp;
        }
        // 서
        else if(cmd[i] == 2){
            last--;
            if(last < 0 || last >= m){
                last++;
                continue;
            }
            int temp = sqaure_map[4];
            sqaure_map[4] = sqaure_map[1];
            sqaure_map[1] = sqaure_map[5];
            sqaure_map[5] = sqaure_map[0];
            sqaure_map[0] = temp;
            
        }
       

        // 북
        else if(cmd[i] == 3){
            start--;
            if(start < 0 || start >= n){
                start++;
                continue;
            }
            int temp= sqaure_map[2];
            sqaure_map[2] = sqaure_map[5];
            sqaure_map[5] = sqaure_map[3];
            sqaure_map[3] = sqaure_map[4];
            sqaure_map[4] = temp;
            
        }
        // 남
        else if(cmd[i] == 4){
            start++;
            if(start < 0 || start >= n){
                start--;
                continue;
            }
            int temp = sqaure_map[5];
            sqaure_map[5] = sqaure_map[2];
            sqaure_map[2] = sqaure_map[4];
            sqaure_map[4] = sqaure_map[3];
            sqaure_map[3] = temp;
            
            
        }

        
        if(map[start][last] == 0){
            map[start][last] = sqaure_map[4];
        }else {
            sqaure_map[4] = map[start][last];
            map[start][last] = 0;
        }
        
        cout << sqaure_map[5] << '\n';
   
    }

    return 0;
}
