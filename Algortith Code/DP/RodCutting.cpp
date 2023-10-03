#include <bits/stdc++.h>
using namespace std;
using namespace chrono;

vector<int> price;

int Recursion(int n)
{
	if (n == 0)
	{
		return 0;
	}

	int qr = INT_MIN;

	for (int i = 1; i <= n; i++)
	{
		qr = max(qr, price[i] + Recursion(n - i));
	}

	return qr;
}

int Mem_Aux(int n, vector<int> &topDown)
{

	if (topDown[n] >= 0)
	{
		return topDown[n];
	}
	int qm = 0;
	if (n == 0)
	{
		qm = 0;
	}
	else
	{
		qm = INT_MIN;
		for (int i = 1; i <= n; i++)
		{
			qm = max(qm, price[i] + Mem_Aux(n - i, topDown));
		}
	}
	topDown[n] = qm;
	return qm;
}

int Memoization(int n, vector<int> &topDown)
{
	return Mem_Aux(n, topDown);
}

int DP(int n, vector<int> &bottomUp)
{

	bottomUp[0] = 0;

	int qd = 0;

	for (int j = 1; j <= n; j++)
	{
		qd = INT_MIN;

		for (int i = 1; i <= j; i++)
		{
			qd = max(qd, price[i] + bottomUp[j - i]);
		}
		bottomUp[j] = qd;
	}
	return bottomUp[n];
}
void input(int n)
{
	price.push_back(0);

	srand(time(nullptr));

	for (int i = 1; i < n; i++)
	{
		price.push_back(rand() % (2 * n + 1));
	}
}

int main()
{

	int n;

	FILE *fpp;
	fpp = freopen("23_input_size.txt", "r", stdin);
	cin >> n;
	fclose(fpp);

	input(n);

	FILE *fp;
	fp = freopen("23_input_array.txt", "w", stdout);
	for (int i = 1; i <= n; i++)
	{
		cout << price[i] << endl;
	}
	fclose(fp);

	int i = n;

	FILE *fp1;
	fp1 = freopen("23_output.txt", "w", stdout);

	for (int i = 2; i <= n; i += 2)
	{

		vector<int> topDown(1000, INT_MIN);
		vector<int> bottomUp(1000, INT_MIN);

		cout << "For n = " << i << endl;
		auto tStart = high_resolution_clock::now();
		int x = Recursion(i);
		auto tEnd = high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(tEnd - tStart);
		cout << "Result: " << x << "\nTime for recursion in microsecond: " << duration.count() << endl;

		auto tStart1 = high_resolution_clock::now();
		int y = Memoization(i, topDown);
		auto tEnd1 = high_resolution_clock::now();
		auto duration1 = duration_cast<microseconds>(tEnd1 - tStart1);
		cout << "Result: " << y << "\nTime for memoization in microsecond: " << duration1.count() << endl;

		auto tStart2 = high_resolution_clock::now();
		int z = DP(i, bottomUp);
		auto tEnd2 = high_resolution_clock::now();
		auto duration2 = duration_cast<microseconds>(tEnd2 - tStart2);
		cout << "Result: " << z << "\nTime for DP in microsecond: " << duration2.count() << endl;
	}

	fclose(fp1);
	return 0;
}