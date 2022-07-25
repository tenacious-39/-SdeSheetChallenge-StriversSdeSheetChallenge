string writeAsYouSpeak(int n) 
{
	// Write your code here.
    string ans = "1";
    for(int i=1;i<n;i++){
        string tmp = "";
        int cnt =1;
        int n = ans.size();
        for(int j=0;j<n-1;j++){
            if(ans[j] == ans[j+1]) cnt++;
            else{
                tmp += to_string(cnt)+ans[j];
                cnt = 1;
            }
        }
        tmp += to_string(cnt) + ans[n-1];
        ans = tmp;
    } return ans;
}
