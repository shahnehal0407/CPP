// class LFUCache {
// public:
//     int c;
//     unordered_map<int, int> cache;
//     unordered_map<int, int> freq;
//     vector<int> recent;

//     LFUCache(int capacity) {
//         c = capacity;
//     }

//     int get(int key) {
//         if (cache.find(key) == cache.end()) return -1;

//         freq[key]++;
//         recent.erase(find(recent.begin(), recent.end(), key));
//         recent.insert(recent.begin(), key);
//         return cache[key];
//     }

//     void put(int key, int value) {
//         if (c == 0) return;

//         // Case 1: Key exists, just update value and freq
//         if (cache.find(key) != cache.end()) {
//             cache[key] = value;
//             freq[key]++;
//             recent.erase(find(recent.begin(), recent.end(), key));
//             recent.insert(recent.begin(), key);
//             return;
//         }

//         // Case 2: Key doesn't exist and cache is full
//         if (recent.size() == c) {
//             int minFreq = INT_MAX;
//             int key_to_remove = -1;

//             // Find key with lowest frequency (LFU)
//             for (int i = recent.size() - 1; i >= 0; i--) {
//                 int k = recent[i];
//                 if (freq[k] < minFreq) {
//                     minFreq = freq[k];
//                     key_to_remove = k;
//                 }
//             }

//             // Remove LFU key
//             cache.erase(key_to_remove);
//             freq.erase(key_to_remove);
//             recent.erase(find(recent.begin(), recent.end(), key_to_remove));
//         }

//         // Insert new key
//         cache[key] = value;
//         freq[key] = 1;
//         recent.insert(recent.begin(), key);
//     }
// };

class LFUCache {
public:
    int capacity, minFreq;
    unordered_map<int, int> cache; // key -> value
    unordered_map<int, int> freq;  // key -> frequency
    unordered_map<int, list<int>> freq_list; // frequency -> list of keys
    unordered_map<int, list<int>::iterator> keyIter; // key -> iterator in freq_list

    LFUCache(int capacity) {
        this->capacity = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cache.find(key) == cache.end()) return -1;

        // update frequency
        int f = freq[key];
        freq_list[f].erase(keyIter[key]);
        freq[key]++;

        freq_list[f + 1].push_front(key);
        keyIter[key] = freq_list[f + 1].begin();

        if (freq_list[f].empty()) {
            freq_list.erase(f);
            if (minFreq == f) minFreq++;
        }

        return cache[key];
    }

    void put(int key, int value) {
        if (capacity == 0) return;

        if (cache.find(key) != cache.end()) {
            cache[key] = value;
            get(key); // reuse frequency update logic
            return;
        }

        // Eviction if full
        if (cache.size() == capacity) {
            int oldKey = freq_list[minFreq].back();
            freq_list[minFreq].pop_back();

            cache.erase(oldKey);
            freq.erase(oldKey);
            keyIter.erase(oldKey);

            if (freq_list[minFreq].empty()) {
                freq_list.erase(minFreq);
            }
        }

        // Insert new key
        cache[key] = value;
        freq[key] = 1;
        freq_list[1].push_front(key);
        keyIter[key] = freq_list[1].begin();
        minFreq = 1;
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */