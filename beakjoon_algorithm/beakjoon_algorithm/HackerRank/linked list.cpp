//
//  linked list.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 02/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

/*
 Insert a node at a specific position in a linked list
 This challenge is part of a tutorial track by MyCodeSchool and is accompanied by a video lesson.
 
 You’re given the pointer to the head node of a linked list, an integer to add to the list and the position at which the integer must be inserted. Create a new node with the given integer, insert this node at the desired position and return the head node.
 
 A position of 0 indicates head, a position of 1 indicates one node away from the head and so on. The head pointer given may be null meaning that the initial list is empty.
 
 As an example, if your list starts as  and you want to insert a node at position  with , your new list should be
 
 Function Description Complete the function insertNodeAtPosition in the editor below. It must return a reference to the head node of your finished list.
 
 insertNodeAtPosition has the following parameters:
 
 head: a SinglyLinkedListNode pointer to the head of the list
 data: an integer value to insert as data in your new node
 position: an integer position to insert the new node, zero based indexing
 Input Format
 
 The first line contains an integer , the number of elements in the linked list.
 Each of the next  lines contains an integer SinglyLinkedListNode[i].data.
 The last line contains an integer .
 
 Constraints
 
 , where  is the  element of the linked list.
 .
 Output Format
 
 Return a reference to the list head. Locked code prints the list for you.
 
 Sample Input
 
 3
 16
 13
 7
 1
 2
 Sample Output
 
 16 13 1 7
 Explanation
 
 The initial linked list is 16 13 7. We have to insert  at the position  which currently has  in it. The updated linked list will be 16 13 1 7
 */


#include <stdio.h>
#include <iostream>
#include <forward_list>
using namespace std;

int main(void){
    
    forward_list <int> f_list;
    auto iter = f_list.before_begin();
    // 정방향 목록에서 첫 번째 요소 앞의 위치에 주소를 지정하는 이터레이터 반환합니다.
    int n;  // 리스트를 구성 할 노드의 개수
    cin >> n;
    
    int data;   // 리스트에 넣을 값
    int position;
    
    for(int i=0; i<n; i++){
        cin >> data;
        iter = f_list.insert_after(iter,data);
            // 이터레이터 현재위치에서 data값 삽입
            // 이터레이터의 position이 초기화되는 것이 아니다.
    }
    
    cin >> data;        // 삽입할 데이터 입력
    cin >> position;    // 삽입 위치 입력

    iter = f_list.begin(); // 리스트의 첫번째 이터레이터 위치 반환
    
    // 해당 포지션까지 이터레이터 위치 변경
    for(int i=0; i<position-1; i++){
        *iter++;
    }
    // 이터레이터 데이터 삽입
    iter = f_list.insert_after(iter,data);
    
    // 모든 리스트를 순회하면서 출력하기
    for(iter = f_list.begin(); iter != f_list.end(); iter++){
        cout << *iter <<"\n";
    }
    return 0;
}
