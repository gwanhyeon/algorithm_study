//
//  Sort_STL.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 04/03/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <algorithm>        // sort define
using namespace std;

bool compare(int a,int b){
    return a > b;
}
int main(void){
    
    int a[10] = {2,6,1,2,3,45,5,32,5,0};
    //sort(메모리주소,마지막 원소가 있는 메모리 주소를 넣어준다, 우리가 원하는 조건대로 작동시킬 수 있음)
    sort(a, a + 10,compare);
    
    for(int i=0; i<10; i++){
        printf("%d ",a[i]);
    }
}
