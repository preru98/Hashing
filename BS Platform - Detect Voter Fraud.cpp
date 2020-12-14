/*
______________________________________________________________________________________________
Question From : Binary Search Platform { Array }

Detect Voter Fraud
Given a two dimensional list of integers votes, where each list has two elements [candidate_id, voter_id], report whether any voter has voted more than once.

______________________________________________________________________________________________

*/

bool solve(vector<vector<int>>& votes) {
    int max = votes[0][1];
    for(int i=1;i<votes.size();i++){
        if(max<votes[i][1]){
            max =  votes[i][1];
        }
    }
    
    int * h= new int[max+1];
    
    for(int i=0;i<max+1;i++){
        h[i]=0;
    }
    
    for(int i=0;i<votes.size();i++){
            if(h[votes[i][1]]){
                return true;
            }
            h[votes[i][1]]++;
    }
    return false;
}

