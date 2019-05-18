// given a number of chosen items
for (int i=0; i < (1<<n); ++i) {
    // all subset of those chosen items
    for(int j = i; j > 0; j = (j-1) & i) {  
        // do stuff 
    }
}