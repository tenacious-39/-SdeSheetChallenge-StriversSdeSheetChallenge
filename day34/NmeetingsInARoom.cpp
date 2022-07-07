 static bool cmp(pair<int, pair<int,int>> a, pair<int, pair<int,int>> b){
        if(a.second.first < b.second.first) return true;
        else if(a.second.first > b.second.first) return false;
        else if(a.second.second < b.second.second) return true;
        return false;
    }

int maxMeetings(int start[], int end[], int n)
    {
        // Your code here
        vector<pair<int, pair<int,int>>> meeting;
        for(int i = 0; i < n; i++) meeting.push_back({start[i], {end[i], i+1}});
        
        sort(meeting.begin(), meeting.end(), cmp);
        int ans = 1;
        
        int limit = meeting[0].second.first;
        //ans.push_back(1);
        for(int i = 1; i < n; i++){
            if(meeting[i].first > limit){
                ans++;
                limit = meeting[i].second.first;
            }
        }
        return ans;
        
    }
