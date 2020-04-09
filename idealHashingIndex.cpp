#include<iostream>
using namespace std;

const int size_hashtable=21;   //Depends on range of elements in the input array
void insert_in_hashtable(int[][size_hashtable],int[],int);
int search(int[][size_hashtable],int);        // Returns true if present and false otherwise

int main(){
    int input_array[]={4,16,8,3,9,14,9,1,15,20,5}; //Inclusive Range 1-20 
    int size_input_array=sizeof(input_array)/sizeof(input_array[0]);

    int hashTable[2][size_hashtable];
    insert_in_hashtable(hashTable,input_array,size_input_array);
    int result = search(hashTable,17);
    if(result!=-1){
        cout<<"Present at index : "<<result<<" at position : "<<result+1;
    }
    else{
        cout<<"Not found";
    }
    return 0;
}

void insert_in_hashtable(int hashtable[2][size_hashtable],int input_array[], int size_input_array){
    
    for(int j=0;j<size_hashtable;j++){
        hashtable[0][j]=-1;    
    }
    for(int i=0;i<size_input_array;i++){              //Inserting elements
        hashtable[0][input_array[i]]=input_array[i];  //element in upper row
        hashtable[1][input_array[i]]=i;               //element in lower row
    }
}

int search(int hashtable[][size_hashtable],int key){
    if(key>20){                //Out of range
        return -1;
    }
    if(hashtable[0][key]==key){   
        return hashtable[1][key];
    }
    return -1;
}