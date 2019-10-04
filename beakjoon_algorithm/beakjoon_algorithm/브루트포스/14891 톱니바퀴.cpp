//
//  14891 톱니바퀴.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 03/10/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;


// 시계방향 회전
void rotation(int map[]){
    int temp = map[0];
    //    map[0] = map[7];
    for(int i=7; i>0; i--){
        map[i] = map[i-1];
    }
    map[0] = temp;

//    map[7] = map[6];
//    map[6] = map[5];
//    map[5] = map[4];
//    map[4] = map[3];
//    map[3] = map[2];
//    map[2] = map[1];
    
}
// 반시계방향 회전
void reverse_rotation(int map[]){
    int temp = map[0];
    for(int i=0; i<7; i++){
        map[i] = map[i+1];
    }
    map[7] = temp;
//    int temp = map[0];
//    map[0] = map[1];
//    map[1] = map[2];
//    map[2] = map[3];
//    map[3] = map[4];
//    map[4] = map[5];
//    map[5] = map[6];
//    map[6] = map[7];
//    map[7] = temp;
}

int main(void){
    int map1[8];
    int map2[8];
    int map3[8];
    int map4[8];
    for(int i=0; i<8; i++){
        scanf("%1d",&map1[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d",&map2[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d",&map3[i]);
    }
    for(int i=0; i<8; i++){
        scanf("%1d",&map4[i]);
    }
    int k;
    cin >> k;
    
    for(int i=0; i<k; i++){
        int x,y = 0;
        cin >> x >> y;
        if(x == 1){
            // 같을 경우 1번만 회전 건너뛰기
            if(map1[2] == map2[6]){
                // 시계방향
                if(y == 1){
                    rotation(map1);
                }
                // 반시계 방향
                else {
                    reverse_rotation(map1);
                }
            }
            // 극이 서로 다를 경우 1번 회전 , 2번 반대방향 회전
            else {
                // 1번 시계방향 회전, 2번 반대방향 회전
                if(y == 1){
                    rotation(map1);
                    // 3,4번도 체크해야함
                    if(map2[2] != map3[6]){
                        reverse_rotation(map2);
                        if(map3[2] != map4[6]){
                            rotation(map3);
                            reverse_rotation(map4);
                        }else {
                            rotation(map3);
                        }
                    }else {
                        reverse_rotation(map2);
                    }
                }
                // 1번 반시계방향 회전, 2번 정방향 회전
                else {
                    reverse_rotation(map1);
                    if(map2[2] != map3[6]){
                        rotation(map2);
                        if(map3[2] != map4[6]){
                            reverse_rotation(map3);
                            rotation(map4);
                        }else {
                            reverse_rotation(map3);
                        }
                    }else {
                        rotation(map2);
                    }
                }
            }
            
        }else if(x == 2){
            
            // 1,2번 톱니와 2,3번 톱니가 같을 경우
            if(map1[2] == map2[6] && map2[2] == map3[6]){
                // 2번 톱니만 정방향 회전
                if(y == 1){
                    rotation(map2);
                }
                //2번 톱니만 반시계방향 회전
                else {
                    reverse_rotation(map2);
                }
            }
            // 1,2번 톱니만 같고, 2,3번 톱니가 다를 경우
            else if(map1[2] == map2[6] && map2[2] != map3[6]){
                //2번 정방향
                if(y == 1){
                    rotation(map2);
                    if(map3[2] != map4[6]){
                        reverse_rotation(map3);
                        rotation(map4);
                    }else{
                         reverse_rotation(map3);
                    }
                   
                }
                //2번 반시계방향
                else {
                    reverse_rotation(map2);
                    if(map3[2] != map4[6]){
                         rotation(map3);
                        reverse_rotation(map4);
                    }else {
                         rotation(map3);
                    }
                   
                }
            }else if(map1[2] != map2[6] && map2[2] == map3[6]){
                //2번 정방향
                if(y == 1){
                    
                    rotation(map2);
                    reverse_rotation(map1);
                    
                    
                }
                //2번 반시계방향
                else {
                    reverse_rotation(map2);
                    rotation(map1);
                    
                }
            }
            // 1,2번 톱니도 다르고, 2,3번 톱니도 다를 경우
            else if(map1[2] != map2[6] && map2[2] != map3[6]){
                // 2번 정방향
                if(y == 1){
                    rotation(map2);
                    reverse_rotation(map1);
                    
                    if(map3[2] != map4[6]){
                        reverse_rotation(map3);
                        rotation(map4);
                    }else{
                        reverse_rotation(map3);
                    }
                    
                }
                // 2번 반시계 방향
                else {
                    reverse_rotation(map2);
                    rotation(map1);
                    if(map3[2] != map4[6]){
                        rotation(map3);
                        reverse_rotation(map4);
                    }else {
                        rotation(map3);
                    }
                }
            }
        // 3번 톱니바퀴 로직
            
        }else if(x == 3){
            // 2,3번 톱니와 3,4번 톱니가 같을 경우
            if(map2[2] == map3[6] && map3[2] == map4[6]){
                // 2번 톱니만 정방향 회전
                if(y == 1){
                    rotation(map3);
                }
                //2번 톱니만 반시계방향 회전
                else {
                    reverse_rotation(map3);
                }
            }
            // 2,3번 톱니만 같고, 3,4번 톱니가 다를 경우
            else if(map2[2] == map3[6] && map3[2] != map4[6]){
                //2번 정방향
                if(y == 1){
                    rotation(map3);
                    reverse_rotation(map4);
                }
                //2번 반시계방향
                else {
                    reverse_rotation(map3);
                    rotation(map4);
                }
            }else if(map2[2] != map3[6] && map3[2] == map4[6]){
                // 2번 정방향
                if(y == 1){
                    rotation(map3);
                    if(map1[2] != map2[6]){
                        reverse_rotation(map2);
                        rotation(map1);
                    }else {
                        reverse_rotation(map2);
                    }
                    
                }
                // 2번 반시계 방향
                else {
                    reverse_rotation(map3);
                    if(map1[2] != map2[6]){
                        rotation(map2);
                        reverse_rotation(map1);
                        
                    }else {
                        rotation(map2);
                    }
                    
                }
            }
            // 2,3번 톱니도 다르고, 3,4번 톱니도 다를 경우
            else if(map2[2] != map3[6] && map3[2] != map4[6]){
                // 2번 정방향
                if(y == 1){
                    rotation(map3);
                    reverse_rotation(map4);
                    if(map1[2] != map2[6]){
                        reverse_rotation(map2);
                        rotation(map1);
                    }else {
                        reverse_rotation(map2);
                    }
                    
                }
                // 2번 반시계 방향
                else {
                    reverse_rotation(map3);
                    rotation(map4);
                    if(map1[2] != map2[6]){
                        rotation(map2);
                        reverse_rotation(map1);
                        
                    }else {
                        rotation(map2);
                    }
                    
                }
            }
            
 
        }else if(x == 4){
            // 같을 경우 1번만 회전 건너뛰기
            if(map3[2] == map4[6]){
                // 시계방향
                if(y == 1){
                    rotation(map4);
                }
                // 반시계 방향
                else {
                    reverse_rotation(map4);
                }
            }
            // 극이 서로 다를 경우 4번 회전 , 3번 반대방향 회전
            else {
                // 4번 시계방향 회전, 3번 반대방향 회전
                if(y == 1){
                    rotation(map4);
                    if(map2[2] !=map3[6]){
                        reverse_rotation(map3);
                        if(map1[2] != map2[6]){
                            rotation(map2);
                            reverse_rotation(map1);
                        }else {
                            rotation(map2);
                        }
                    }else {
                        reverse_rotation(map3);
                    }
                }
                // 4번 반시계방향 회전, 3번 정방향 회전
                else {
                    reverse_rotation(map4);
                    if(map2[2] !=map3[6]){
                        rotation(map3);
                        if(map1[2] != map2[6]){
                            reverse_rotation(map2);
                            rotation(map1);
                        }else {
                            reverse_rotation(map2);
                        }
                    }else {
                        rotation(map3);
                    }
                }
            }
        }
    }
    int sum = 0;
    if(map1[0] == 1) sum += 1;
    if(map2[0] == 1) sum += 2;
    if(map3[0] == 1) sum += 4;
    if(map4[0] == 1) sum += 8;
    
    cout << sum << '\n';
    return 0;
}
