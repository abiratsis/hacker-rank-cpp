#ifndef LISTS_HPP
#define LISTS_HPP

struct Node{
    int data;
    struct Node* next;
};

bool has_cycle(Node* head);
bool has_cycle2(Node* head);
Node* Insert(Node* head, int data);
void Print(Node *head);

#endif /* LISTS_HPP */

