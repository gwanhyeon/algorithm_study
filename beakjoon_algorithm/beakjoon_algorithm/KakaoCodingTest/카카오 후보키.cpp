//
//  카카오 후보키.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/09/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main(void){
    vector<vector<string>> relation = {{"100","ryan","music","2"},{"200","apeach","math","2"},{"300","tube","computer","3"},{"400","con","computer","4"},{"500","muzi","music","3"},{"600","apeach","music","2"}};
    
    int row = relation.size();
    int column = relation[0].size();
    
    int cnt = 0;
    int x,y = 0;
    
    for(int i=0; i<column; i++){
        for(int j=0; j<row; j++){
            // 값이 같다면 후보키 후보에서 일단 벗어나는거임
            if(relation[i][j] == relation[i][j+1]){
                cnt +=1;
            }
            // 값이 같지 않다면 후보키 확정임
            else if(relation[i][j] != relation[i][j+1]){
                
            }
            //
                
            
            
            
        }
    }
    
    
    return 0;
}
