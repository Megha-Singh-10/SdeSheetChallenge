/*
    Time Complexity : O((N ^ 2) * log(N))
    Space Complexity : O(N)

    Where 'N' is the total number of elements read at runtime.
*/

import java.util.ArrayList;
import java.util.Collections;

public class Kthlargest {
    private int size;
    private ArrayList<Integer> aux;

    Kthlargest(int k, int[] arr) {
        size = k;
        aux = new ArrayList<>();
        for (int it : arr) {
            aux.add(it);
        }

        Collections.sort(aux, Collections.reverseOrder());
    }

    void add(int num) {
        aux.add(num);
        Collections.sort(aux, Collections.reverseOrder());
    }

    int getKthLargest() {
        
        // The kth largest element will always be at the top of the queue.
        return aux.get(size - 1);
    }
}