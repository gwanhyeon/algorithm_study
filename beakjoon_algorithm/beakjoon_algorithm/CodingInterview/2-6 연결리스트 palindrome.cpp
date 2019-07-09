//
//  2-6 연결리스트 palindrome.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 08/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct NODE{
    int data;
    struct NODE* next;
}node;

void insert_node(NODE* head, int data){
    
    if(head->next==NULL){
        head->data = data;
        head->next = NULL;
    }
    
    node* curr = (NODE*)malloc(sizeof(node));
    curr->data = data;
    curr->next = head->next;
    head->next = curr;
}
void print_node(NODE* head){
    
    node* curr = head->next;
    while(curr != NULL){
        cout << curr->data;
        curr = curr->next;
    }
}

node* partition(NODE* curr,int x){
    node* head = curr;
    node* tail = curr;
    
    while(curr != NULL){
        node* next = curr->next;
        
        if(curr->data < x){
            curr->next = head;
            head = curr;
        }else{
            tail->next = curr;
            tail = curr;
        }
        curr = next;
    }
    tail->next = NULL;
    return head;
}


int main(void){
    node* head = (node*)malloc(sizeof(node));
    node* temp = (node*)malloc(sizeof(node));
    
    head->next = NULL;
    
    insert_node(head,3);
    insert_node(head,5);
    insert_node(head,8);
    insert_node(head,5);
    insert_node(head,10);
    insert_node(head,2);
    insert_node(head,1);
    temp = partition(head,5);
    print_node(temp);
    
    return 0;
}
