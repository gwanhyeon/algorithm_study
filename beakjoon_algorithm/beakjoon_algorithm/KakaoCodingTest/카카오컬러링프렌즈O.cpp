//
//  카카오컬러링프렌즈.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 30/08/2019.
//  Copyright © 2019 kgh. All rights reserved.
//
// https://programmers.co.kr/learn/courses/30/lessons/1829

#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

#include <algorithm>
#include <cstring>

using namespace std;
int check[101][101];
int dist[101][101];
int dir[4][2] = {{-1,0},{1,0},{0,1},{0,-1}};

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
vector<int> solution(int m, int n, vector<vector<int>> picture) {
    memset(dist,0,sizeof(dist));
    memset(check,0,sizeof(check));
    int number_of_area = 0;
    int max_size_of_one_area = 0;
    vector<int> answer(2);
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    vector<int> result;
    
    for(int x=0; x<m; x++){
        for(int y=0; y<n; y++){
            max_size_of_one_area = 0;
            if(picture[x][y] != 0 && check[x][y] == 0){
                queue<pair<int,int>> q;
                check[x][y] = true;
                dist[x][y] = 0;
                q.push({x,y});
                max_size_of_one_area += 1;
                
                while(!q.empty()){
                    
                    int dx = q.front().first;
                    int dy = q.front().second;
                    q.pop();
                    
                    for(int i=0; i<4; i++){
                        int mx = dx + dir[i][0];
                        int my = dy + dir[i][1];
                        if(mx >= 0 && mx < m && my >=0 && my < n){
                            if(check[mx][my] == 0 && picture[mx][my] == picture[dx][dy]){
                                check[mx][my] = 1;
                                dist[mx][my] = dist[dx][dy]+1;
                                max_size_of_one_area += 1;
                                q.push({mx,my});
                            }
                        }
                    }
                }
                result.push_back(max_size_of_one_area);
                number_of_area +=1;
                
            }
            
        }
    }
    int max = 0;
    //     for(int i=0; i<m; i++){
    //         for(int j=0; j<n; j++){
    //             if(dist[i][j] > max){
    //                 max = dist[i][j];
    //             }
    
    //         }
    
    //     }
    // for(int i=0; i<result.size(); i++){
    //         if(result[i] > max){
    //             max = result[i];
    //         }
    // }
    // max_size_of_one_area = max;
    max_size_of_one_area = *max_element(result.begin(), result.end());
    answer[0] = number_of_area;
    answer[1] = max_size_of_one_area;
    return answer;
}
