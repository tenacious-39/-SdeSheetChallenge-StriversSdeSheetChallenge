bool isPossible(int arr[], int n, int dist, int cows) {
	int cnt = 1;
	int d = arr[0];
	for (int i = 1; i < n; i++) {
		if (abs(arr[i] - d) >= dist) {
			cnt++;
			d = arr[i];
		}
	} return cnt >= cows;
}
void solve() {
	int n, cows;
	cin >> n >> cows;
	int arr[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int low = 1, high = *max_element(arr, arr + n) - *min_element(arr, arr + n);
	while (low <= high) {
		int mid = (low + high) >> 1;
		//cout << "low = " << low << " mid = " << mid << " high = " << high << "\n";
		if (isPossible(arr, n, mid, cows)) low = mid + 1;
		else high = mid - 1;
	}
	cout << high << "\n";
}
