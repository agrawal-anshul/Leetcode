class TimeMap {
public:
    TimeMap() {
        // Initializes the internal storage
    }

    void set(string key, string value, int timestamp) {
        // Insert (timestamp, value) for the given key
        storage[key][timestamp] = value;
    }

    string get(string key, int timestamp) {
        // If the key does not exist, return empty string
        if (storage.find(key) == storage.end()) {
            return "";
        }

        // Access the inner map for the key
        map<int, string>& times = storage[key];

        // Manually search from greatest to smallest timestamp ≤ given timestamp
        for (auto it = times.rbegin(); it != times.rend(); it++) {
            if (it->first <= timestamp) {
                return it->second;
            }
        }

        // If no suitable timestamp is found
        return "";
    }

private:
    map<string, map<int, string>> storage;
};