#include <cstdlib>
#include <iostream>
#include "lists.hpp"

using namespace std;

bool has_cycle(Node* head) {
    if(head == NULL)
        return false;
    
    if(head->next == NULL)
        return false;
    
    Node *tail_pntr = head, *head_pntr = head->next;
    while(head_pntr){
        
        while(tail_pntr && head_pntr != tail_pntr){
            if(tail_pntr == head_pntr->next)
                return true;
            tail_pntr = tail_pntr->next;
        }
        
        head_pntr = head_pntr->next;
        tail_pntr = head;
    }
    return false;
}

bool has_cycle2(Node* head) {
    struct Node  *slow_p = head, *fast_p = head;
  
    while (slow_p && fast_p && fast_p->next )
    {
        slow_p = slow_p->next;
        fast_p  = fast_p->next->next;
        if (slow_p == fast_p)
        {
           printf("Found Loop");
           return 1;
        }
    }
    return 0;
}

Node* Insert(Node* head, int data)
{
  if (head == NULL){
      head = new Node ();
      head->data = data;
      return head;
  }

  Node *node = head;
  while (node->next)
  {
      node = node->next;
  }

  node->next = new Node();
  node->next->data = data;

  return head;
}

void Print(Node *head)
{
    while(head){
        cout<<head->data<<endl;
        head = head->next;
    }
}

