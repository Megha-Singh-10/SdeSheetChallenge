/*
    Time Complexity: O(N * M)
    Space Complexity: O(N)

    Where 'N' denotes size of cache and 'M' denotes the number of operations.
*/

// Node class for object in the cache.
class Node
{
public:
    int value, index, freq; 
    Node(int value = 0, int index = 0, int freq = 0){
        this -> value = value;
        this -> index = index;
        this -> freq = freq;
    }
};

class LFUCache
{
public:

    int capacity, position, currSize;
    vector<int> cache;
    Node *nodes;

    // Initialise capacity, current size and cache.
    LFUCache(int capacity)
    {
        this -> capacity = capacity;
        this -> cache.resize(capacity, -1);
        nodes = new Node[capacity];
        this -> currSize = 0;
        this -> position = 0;
    }

    int get(int key)
    {
        // Update the current number of query.
        position += 1;

        // Set the initial value as -1.
        int value = -1;

        // Search the entire cache.
        for(int i = 0; i < cache.size(); i++){

            if(key == cache[i]){

                // If a key is found the cache update it's frequency and get it's value.
                value = nodes[i].value;
                nodes[i].freq += 1;
                nodes[i].index = position;
            }
        }

        // Return the value.
        return value;
        
    }

    void put(int key, int value)
    {
        // Update the current number of query.
        position += 1;

        // If capacity is 0 return.
        if(capacity == 0){
            return;
        }

        for(int i = 0; i < capacity; i++){

            // If key is found in the cache update it's value, position and frequency.
            if(cache[i] == key){

                nodes[i].index = position;
                nodes[i].freq += 1;
                nodes[i].value = value;
                return;
            }
        }

        // If the key is not present in the cache and the cache is not full.
        if(currSize < capacity){

            // Add the node and key at the last position of the cache.
            cache[currSize] = key;
            nodes[currSize].value = value;
            nodes[currSize].freq = 1;
            nodes[currSize].index = position;
            currSize += 1;
        }

        // If the cache is full.
        else{

            // Find the position of the LFU node.
            int pos = 0;

            for(int j = 0; j < capacity; j++){

                if(nodes[j].freq < nodes[pos].freq){
                    pos = j;
                }

                // If two nodes have same frequency then get the one which is LRU.
                else if(nodes[j].freq == nodes[pos].freq &&
                        nodes[j].index < nodes[pos].index){
                    pos = j;
                }
            }
            // Replace LFU node with the current key and value.
            cache[pos] = key;
            nodes[pos].value = value;
            nodes[pos].freq = 1;
            nodes[pos].index = position;
        }

    }
};
