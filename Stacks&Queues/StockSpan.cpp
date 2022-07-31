/*

    Time Complexity : O(N^2)
    Space Complexity : O(1)

    where 'N' is the size of array/list ‘PRICE’.
    
*/

vector<int> findSpans(vector<int> &price) {
    //  Size of array/list ‘price’.
    int n = price.size();

    //  Make an array/list ‘result’ of size ‘n’ and fill it with 0.
    vector<int> result(n);

    for(int i = 0; i < n; i++) {
        int j = i;
        //  Find span of Ninja coin on day 'i'.
        while(j >= 0 && price[j] <= price[i]) {
            result[i] += 1;
            j -= 1;
        }
    }

    return result;
}