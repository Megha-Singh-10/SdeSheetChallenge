(Coding Ninja) The Celebrity Problem
/* Problem Statement
There are ‘N’ people at a party. Each person has been assigned a unique id between 0 to 'N' - 1(both inclusive). A celebrity is a person who is known to everyone but does not know anyone at the party.
Given a helper function ‘knows(A, B)’, It will returns "true" if the person having id ‘A’ know the person having id ‘B’ in the party, "false" otherwise. Your task is to find out the celebrity at the party. Print the id of the celebrity, if there is no celebrity at the party then print -1. */

TC->O(2N)
SC->O(1)

/*
	This is signature of helper function 'knows'.
	You should not implement it, or speculate about its implementation.

	bool knows(int A, int B); 
	Function 'knows(A, B)' will returns "true" if the person having
	id 'A' know the person having id 'B' in the party, "false" otherwise.
*/

int findCelebrity(int n) {
 	// Write your code here.
    int c=0;
    for(int i=1;i<n;i++)
    {
        if(knows(c,i))
            c=i;
    }
    for(int i=0;i<n;i++)
    {
        if(i!=c)
        {
            if(knows(c,i))
                return -1;
            if(!knows(i,c))
                return -1;
        }
    }
    return c;
}