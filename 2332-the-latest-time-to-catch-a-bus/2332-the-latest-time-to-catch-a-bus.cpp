class Solution {
    // So many corner cases
    // https://leetcode.cn/problems/the-latest-time-to-catch-a-bus/solution/by-kun-zi-2-9h78/
    
    // 解题思路:
    // 最后一辆车上满人了没有？
    // 1.满了，挤掉最后一个人
    // 2.没满，尝试在最后一辆车到达的时间上车(若没其他人在这个时刻上)，有人在这时刻上了就往前找合适时间。
    
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        int i = 0;      // bus index
        int n = buses.size();
        sort(passengers.begin(), passengers.end());
        int j = 0;      // passengers index
        int m = passengers.size();
        
        int cur_cap = capacity;
        int last_cap = 0;
        while (i < n && j < m) {
            if (passengers[j] <= buses[i]) {
                j++;
                cur_cap--;
                if (cur_cap == 0) {
                    i++;
                    last_cap = cur_cap;
                    cur_cap = capacity;
                }
            } else {
                i++;
                last_cap = cur_cap;
                cur_cap = capacity;
            }
        }
        
        cout << "i: " << i << " j: " << j << " last_cap: " <<  last_cap << endl;
        
        int latest = -1;
        if (i < n) {    // still have buses ; passengers all have gone j == m
            latest = buses[n - 1];
            j--;
            while (j >= 0 &&passengers[j] == latest) {
                j--;
                latest--;
            }
            return latest;
        } else {    // i == n  all buses have gone
            if (last_cap <= 0) { // the last bus is full
                j--;
                latest = passengers[j];
                while (j >= 0 && passengers[j] == latest) {
                    j--;
                    latest--;
                }
                
                return latest;
            } else { // the last bus is not full
                latest = buses[n - 1];
                j--;
                while (j >= 0 && passengers[j] == latest) {
                    j--;
                    latest--;
                }
                
                return latest;
            }
        }
        

            
        
        return latest;
    }
};