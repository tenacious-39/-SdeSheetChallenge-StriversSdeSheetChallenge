

// My approach:
static bool cmp(Job a, Job b) { return a.profit > b.profit; } 
vector<int> JobScheduling(Job a[], int n) 
    { 
        // your code here
        int maxDead = 0;
        for(int i = 0; i < n; i++){
            maxDead = max(maxDead, a[i].dead);
        }
        vector<int> slot(maxDead+1, 0);
        sort(a, a+n, cmp);
        
        int profit = 0, jobs = 0;
        for(int i = 0; i < n; i++){
            int startSlot = a[i].dead;
            //bool ok = false;
            for(int j = startSlot; j >= 1; j--){
                if(slot[j] == 0){
                    slot[j] =1;
                    profit += a[i].profit;
                    jobs++;
                    break;
                }
            }
        }
        vector<int> res(2);
        res[0] = jobs; res[1] = profit;
        return res;
    } 
