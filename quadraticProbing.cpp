#include<iostream>
using namespace std;

void insert_in_hashtable(int[],int[],int);
bool search(int[],int);        // Returns true if present and false otherwise
int hash_function(int);
void view(int[]);
int probe(int[],int);
const int size_hashtable=10;   //Depends on range of elements in the input array


int main(){
    int input_array[]={4,16,6,13,9,36,48,98,102}; //Inclusive Range 1-20 
    int size_input_array=sizeof(input_array)/sizeof(input_array[0]);

    int hashTable[size_hashtable];
    insert_in_hashtable(hashTable,input_array,size_input_array);
    view(hashTable);
    cout<<search(hashTable,109);
    return 0;
}

void insert_in_hashtable(int hashtable[],int input_array[], int size_input_array){
    for(int i=0;i<size_hashtable;i++){    //Storing illegal values to hashtable
        hashtable[i]=-1;
    }

    for(int i=0;i<size_input_array;i++){  //Inserting elements
        int resultant_index=hash_function(input_array[i]); 
        if(hashtable[resultant_index]==-1){
            hashtable[resultant_index]=input_array[i];
        }
        else{
           resultant_index=probe(hashtable, input_array[i]);
           hashtable[resultant_index]=input_array[i]; 
        }
    }
}

bool search(int hashtable[],int key){
    int resultant_index=hash_function(key);
    if(hashtable[resultant_index]==-1){   
        return false;
    }
    else{
        int i=0;
        while(hashtable[(resultant_index+i*i)%10]!=key && hashtable[(resultant_index+i*i)%10]!=-1){
            i++;
        }
        if(hashtable[(resultant_index+i*i)%10]==key)
        return true;
    }
    return false;
}

int hash_function(int element){
    return element%10;
}

void view(int hashTable[]){
    for(int i=0;i<size_hashtable;i++){
        cout<<hashTable[i]<<"\n";
    }
}

int probe(int hashTable[],int key){
    int resultant_index=hash_function(key);
    int i=1;
    while((hashTable[(resultant_index+i*i)%size_hashtable])!=-1){
        i++;
    }
    return (resultant_index+i*i)%size_hashtable;
}