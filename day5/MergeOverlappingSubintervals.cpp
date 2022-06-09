

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> ans;
        if(intervals.size() == 0) return ans;
        sort(intervals.begin(), intervals.end());
        vector<int> tmp = intervals[0];
        for(auto it : intervals){
            if(it[0] <= tmp[1]){
                tmp[1] = max(tmp[1], it[1]);
            } else{
                ans.push_back(tmp);
                tmp = it;
            }
        } ans.push_back(tmp);
        return ans;
    }
};

// Brute force approach:
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int n = 1;
        for(auto it : intervals){
            if(it[0] <= ans[n-1][1]){
                ans[n-1][1] = max(ans[n-1][1], it[1]);
            } else{
                ans.push_back(it);
                n++;
            }
        }
        return ans;
    }
};
