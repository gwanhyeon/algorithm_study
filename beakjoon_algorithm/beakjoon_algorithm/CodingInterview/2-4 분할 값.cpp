//
//  2.cpp
//  beakjoon_algorithm
//
//  Created by kgh on 05/07/2019.
//  Copyright © 2019 kgh. All rights reserved.
//

#include <stdio.h>
#include <iostream>
using namespace std;
typedef struct NODE{
    int data;
    struct NODE* next;
}node;
void front_insert_node(NODE** head,NODE** tail, int data){
    NODE* curr = (NODE*)malloc(sizeof(node));
    curr->data = data;
    curr->next = NULL;
    
    
    
}

void back_insert_node(NODE** head,NODE** tail,int data){
    // New Node
    NODE* curr = (NODE*)malloc(sizeof(node));
    curr->data = data;
    curr->next = NULL;
    
    if((*head) == NULL){
        (*head) = curr;
        (*tail) = curr;
    }else{
        (*tail)->next = curr;
        (*tail) = curr;
        
    }
}
void print_node(NODE* head){
    
    NODE* curr = head;
    while(curr != NULL){
        cout << curr->data << ' ';
        curr = curr->next;
    }
    
}
int main(void){
    NODE* head = (NODE*)malloc(sizeof(node));
    NODE* tail = (NODE*)malloc(sizeof(node));
    
    head->next = NULL;
    tail->next = NULL;
    
    back_insert_node(&head,&tail,3);
    back_insert_node(&head,&tail,5);
    back_insert_node(&head,&tail,7);
    print_node(head);
    return 0;
}
