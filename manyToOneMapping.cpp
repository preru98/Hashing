#include<iostream>
using namespace std;

/*

This is not a good approach since there are collisions.
Ex : at 16 and 6 : the resultant index is 6 so first 16 will be stored but soon 16 will be overwritten
and 6 will take its place.

Due to this 16 will not be found but 6 will, but space is halved as compared to ideal one to one 
hashing.

These collisions must be resolved.
Please refer other program for solution of this problem

*/
void insert_in_hashtable(int[],int[],int);
bool search(int[],int);        // Returns true if present and false otherwise
int hash_function(int);
const int size_hashtable=10;   //Depends on range of elements in the input array


int main(){
    int input_array[]={4,16,6,13,9}; //Inclusive Range 1-20 
    int size_input_array=sizeof(input_array)/sizeof(input_array[0]);

    int hashTable[size_hashtable];
    insert_in_hashtable(hashTable,input_array,size_input_array);
    cout<<search(hashTable,6);
    return 0;
}

void insert_in_hashtable(int hashtable[],int input_array[], int size_input_array){
    for(int i=0;i<size_hashtable;i++){    //Storing illegal values to hashtable
        hashtable[i]=-1;
    }

    for(int i=0;i<size_input_array;i++){  //Inserting elements
        int resultant_index=hash_function(input_array[i]); 
        hashtable[resultant_index]=input_array[i]; 
    }
}

bool search(int hashtable[],int key){
    if(key>20){                //Out of range
        return false;
    }
    int resultant_index=hash_function(key);
    if(hashtable[resultant_index]==key){   
        return true;
    }
    return false;
}

int hash_function(int element){
    return element%10;
}