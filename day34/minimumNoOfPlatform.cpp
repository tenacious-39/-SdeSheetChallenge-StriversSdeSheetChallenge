int findPlatform(int arr[], int dep[], int n)
    {
    	// Your code here
    	sort(arr, arr+n);
    	sort(dep, dep+n);
    	
    	int platform = 1;
    	int maxi = 1;
    	int j = 0;
    	int i = 1;
    	while(i < n && j < n){
    	    if(arr[i] <= dep[j]){
    	        i++;
    	        platform++;
    	    } else{
    	        platform--;
    	        j++;
    	    }
    	    maxi = max(maxi, platform);
    	}
    	return maxi;
    }
