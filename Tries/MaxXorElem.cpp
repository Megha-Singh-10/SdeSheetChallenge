
/*
    Time Complexity : O(N*M)
    Space Complexity : O(1)

    Where 'N' is the size of ARR, and 'M'  is the number of queries.
*/
import java.util.ArrayList;

public class Solution 
{
    public static ArrayList<Integer> maxXorQueries(ArrayList<Integer> arr,ArrayList<ArrayList<Integer>> queries)
    {
    	// Size of array and number of queries.
	    int n = arr.size();
	    int m = queries.size();

	    ArrayList<Integer> result = new ArrayList<Integer>();
	    for (int i = 0; i<m; i++)
	    {
	    	result.add(-1);
	    }

	    // Finding answer of each query.
	    for(int i = 0; i < m; i++)
	    {
	        for(int j = 0; j < n; j++)
	        {
	            if(arr.get(j) <= queries.get(i).get(1))
	            {
	            	int p = Math.max(result.get(i), (arr.get(j) ^ queries.get(i).get(0)));
	                result.set(i,p);
	            }
	        }
	    }

	    return result;
	        
    }

}