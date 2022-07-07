static bool cmp(Item a, Item b){
        double eacha = (double)(a.value)/(double)(a.weight);
        double eachb = (double)(b.value)/(double)(b.weight);
        return eacha > eachb;
    }

 double fractionalKnapsack(int W, Item arr[], int n)
    {
        // Your code here
        sort(arr, arr+n, cmp);
        double res = 0;
        int sum = 0;
        for(int i = 0; i < n; i++){
            if(sum+arr[i].weight <= W){
                res += arr[i].value;
                sum += arr[i].weight;
            } else{
                res += ((double)(arr[i].value)/(double)(arr[i].weight))*(double)(W-sum);
                break;
            }
        }
        return res;
        
    }
