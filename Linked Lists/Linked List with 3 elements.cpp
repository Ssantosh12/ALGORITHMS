#include <bits/stdc++.h>
using namespace std;

class node{   //learning from geeksforgeeks 
    public:
    int data;
    node *next;
};

void display(node *head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<"\n";
}

int main(){
    //creating a linked list of 3 elements

    node *head = NULL;
    node *second = NULL;
    node *third = NULL;


    head=new node();
    second=new node();
    third=new  node();

    head->data=12;
    head->next=second;

    second->data=44;
    second->next=third;

    third->data=05;
    third->next=NULL;

    display(head);
}
