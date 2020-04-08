#include<iostream>
using namespace std;

void insert_in_hashtable(int[],int[],int);
bool search(int[],int);        // Returns true if present and false otherwise
const int size_hashtable=21;   //Depends on range of elements in the input array

int main(){
    int input_array[]={4,16,8,3,9,14,9,1,15,20,5}; //Inclusive Range 1-20 
    int size_input_array=sizeof(input_array)/sizeof(input_array[0]);

    int hashTable[size_hashtable];
    insert_in_hashtable(hashTable,input_array,size_input_array);
    cout<<search(hashTable,16);
    return 0;
}

void insert_in_hashtable(int hashtable[],int input_array[], int size_input_array){
    for(int i=0;i<size_hashtable;i++){    //Storing illegal values to hashtable
        hashtable[i]=-1;
    }

    for(int i=0;i<size_input_array;i++){  //Inserting elements
        hashtable[input_array[i]]=input_array[i]; 
    }
}

bool search(int hashtable[],int key){
    if(key>20){                //Out of range
        return false;
    }
    if(hashtable[key]==key){   
        return true;
    }
    return false;
}