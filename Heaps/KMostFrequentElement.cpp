/*
    Time Complexity: O(N ^ 2)
    Space Complexity: O(N)

    where 'N' is the size of the input array.
*/

#include<map>
#include<algorithm>

vector<int> uniq;
map<int, int> mp;

void swapUnique(int a, int b) {
    int temp = uniq[a];
    uniq[a] = uniq[b];
    uniq[b] = temp;
}

int partition(int left, int right, int pivot) {

    int pivotFrequency = mp[uniq[pivot]];

    // Move pivot to end.
    swapUnique(pivot, right);
    int idx = left;

    // Move all less frequent elements to the left of the pivot.
    for (int i = left; i <= right; i++) {

        if (mp[uniq[i]] < pivotFrequency) {

            swapUnique(idx, i);
            idx++;
        }
    }

    // Move pivot to its final place.
    swapUnique(idx, right);

    return idx;
}

void quickselect(int left, int right, int kSmall) {

    // If the list contains only one element.
    if (left == right) {
        return;
    }

    // Select a random index as pivot.
    int pivot = left + rand()%(right - left);

    // Find the position of pivot in the sorted list.
    pivot = partition(left, right, pivot);

    // If the pivot is in its final sorted position.
    if (kSmall == pivot) {

        return;
    }
    else if (kSmall < pivot) {

        // Move in the left direction.
        quickselect(left, pivot - 1, kSmall);
    }
    else {

        // Move in the right direction.
        quickselect(pivot + 1, right, kSmall);
    }
}

vector<int> KMostFrequent(int n, int k, vector<int> &arr)
{
    mp.clear();

    // Build map where the key is element
    // and value is how often this element appears in 'ARR'.
    for (int ele : arr) {
        mp[ele]++;
    }

    int size = mp.size();
    uniq.assign(size, 0);
    int i = 0;

    // Build array of uniq elements.
    for (auto x: mp) {

        uniq[i] = x.first;
        i++;
    }

    // Perform quickselect.
    quickselect(0, size - 1, size - k);

    // Return top 'K' frequent elements
    vector<int> topK;
    for(int i = size-k; i < size; i++){
        topK.push_back(uniq[i]);
    }
    
    sort(topK.begin(), topK.end());
    return topK;
}