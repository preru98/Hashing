/*

Chaining : Open Addressing method for collision resolution.
It yields the relative position/index of the key in the input array.

*/

#include<iostream>
using namespace std;

const int size_hashtable=10; 
struct Node{
    int data;
    int index;
    Node* next;
}*hashtable[size_hashtable];

void insert_in_hashtable(int[],int);
int hash_function(int);
Node* create_node(int,int);
void insert(int, int,Node*);
void view();
int search(int);  

int main(){
    int input_array[]={4,10,0,14,16,6,13,9}; //Inclusive Range 1-20 
    int size_input_array=sizeof(input_array)/sizeof(input_array[0]);
    insert_in_hashtable(input_array,size_input_array);
    view();
    cout<<search(17);
    return 0;
}

void insert_in_hashtable(int input_array[], int size_input_array){
    for(int i=0;i<size_hashtable;i++){     //Storing illegal values to hashtable
        hashtable[i]=NULL;
    }

    for(int i=0;i<size_input_array;i++){   //Inserting elements
        Node* new_node=create_node(input_array[i],i);
        int resultant_index=hash_function(input_array[i]); 
        insert(resultant_index,i,new_node);
    }
}

int search(int key){
    if(key>20){                //Out of range
        return -1;
    }
    int resultant_index=hash_function(key);
    Node* traverse=hashtable[resultant_index];
    while(traverse){
        if(traverse->data>key){
            return -1;
        }
        if(traverse->data==key){
            return traverse->index;
        }
        traverse=traverse->next;
    }
    return -1;
}

int hash_function(int element){
    return element%10;
}

Node* create_node(int element,int pos){
    Node * new_node=new Node;
    new_node->data=element;
    new_node->index=pos;
    new_node->next=NULL;
    return new_node;
}

void insert(int start,int pos,Node * new_Node){
    
    if(!hashtable[start]){
        hashtable[start]=new_Node;
    }
    else{
        Node *traverse=hashtable[start],*tail=NULL;
        if(traverse->data>new_Node->data){
            new_Node->next=traverse;
            hashtable[start]=new_Node;
        }
        else{
            while(traverse){
                if(traverse->data<new_Node->data){
                    tail=traverse;
                    traverse=traverse->next;
                }
                else{
                    break;
                }
            }
            if(traverse!=NULL){
                tail->next=new_Node;
                new_Node->next=traverse;
            }
            else{
                tail->next=new_Node;
            }
        }
    }
}

void view(){
    Node* traverse;
    for(int i=0;i<size_hashtable;i++){
        cout<<"For i= "<<i<<"\n";
        traverse=hashtable[i];
        while(traverse){
            cout<<traverse->data<<"\t";
            traverse=traverse->next;
        }
        cout<<endl;
    }
}
