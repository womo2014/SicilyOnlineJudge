#include <iostream>
#include <algorithm>
using namespace std;
int num[500];

long long c(int a, int b)
{
	if (a < b) return 0;
	long long ret = 1;
	for(int i = a; i > a-b; i--)
		ret *= i;
	for (int i = 2; i <= b; i++) 
		ret /= i;
	return ret;
}

long long dp(int time, int x, int n)
{
	if (x <= 0) {
		return 0;
	}
	long long ret = 0;
	int cnt = time-1;
	for(int i = time-1; i < n; i++) {
		int sum = 0;
		for(int j = 0; j < time; j++)
			sum += num[i-j];
		if(sum < x)
			cnt++;
		else if (time == 1)
			break;
		else ret += dp(time-1, x-num[i], i);
	}
	ret += c(cnt,time);
	return ret;
}

int main()
{
	int t;
	cin >> t;
	while (t--) {
		int n, x;
		cin >> n >> x;
		for(int i = 0; i < n; i++)
			cin >> num[i];
		sort(num, num+n);
		cout << dp(4, x, n) << endl;
	}
	return 0;
}
