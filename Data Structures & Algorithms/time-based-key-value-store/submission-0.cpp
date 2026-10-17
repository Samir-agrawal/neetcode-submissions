class TimeMap {
private:
    unordered_map<string,map<int,string>> store;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        store[key][timestamp] = value;
    }
    
    string get(string key, int timestamp) {
        auto keyIt = store.find(key);
        if(keyIt == store.end()) return "";
        const auto &timeMap = keyIt->second;
        auto it = timeMap.upper_bound(timestamp);
        if (it == timeMap.begin()) return "";

        it--;
        return it->second;
    }
};
