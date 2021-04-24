class Solution {
public:
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
        size_t len = sensor1.size();
        size_t index = 0;
        
        while (index < len && sensor1[index] == sensor2[index]) {
            ++index;
        }
        if ((len - 1) <= index) {
            return -1;
        }
        
        
        while ((index + 1) < len && sensor1[index] == sensor2[index + 1]) {
            ++index;
        }
        return ((len - 1) <= index ? 1 : 2);
    }
};
