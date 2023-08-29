// C++ implementation of the approach
#include <bits/stdc++.h>
using namespace std;

// Max number of nodes given
const int N = 500 + 10;

// arr is the parent array
// sz is the size of the
// subtree in DSU
int arr[N], sz[N];

// Function to initialize the parent
// and size array for DSU
void initialize()
{
	for (int i = 1; i < N; ++i) {
		arr[i] = i;
		sz[i] = 1;
	}
}

// Function to return the
// parent of the node
int root(int i)
{
	while (arr[i] != i)
		i = arr[i];
	return i;
}

// Function to perform the
// merge operation
void Union(int a, int b)
{
	a = root(a);
	b = root(b);

	if (a != b) {
		if (sz[a] < sz[b])
			swap(a, b);

		sz[a] += sz[b];
		arr[b] = a;
	}
}

// Function to return the minimum cost required
double minCost(vector<pair<int, int> >& p)
{

	// Number of points
	int n = (int)p.size();

	// To store the cost of every possible pair
	// as { cost, {to, from}}.
	vector<pair<double, pair<int, int> > > cost;

	// Calculating the cost of every possible pair
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (i != j) {

				// Getting Manhattan distance
				int x = abs(p[i].first - p[j].first)
						+ abs(p[i].second - p[j].second);

				// If the distance is 1 the cost is 0
				// or already connected
				if (x == 1) {
					cost.push_back({ 0, { i + 1, j + 1 } });
					cost.push_back({ 0, { j + 1, i + 1 } });
				}
				else {

					// Calculating the euclidean distance
					int a = p[i].first - p[j].first;
					int b = p[i].second - p[j].second;
					a *= a;
					b *= b;
					double d = sqrt(a + b);
					cost.push_back({ d, { i + 1, j + 1 } });
					cost.push_back({ d, { j + 1, i + 1 } });
				}
			}
		}
	}

	// Krushkal Algorithm for Minimum
	// spanning tree
	sort(cost.begin(), cost.end());

	// To initialize the size and
	// parent array
	initialize();

	double ans = 0.00;
	for (auto i : cost) {
		double c = i.first;
		int a = i.second.first;
		int b = i.second.second;

		// If the parents are different
		if (root(a) != root(b)) {
			Union(a, b);
			ans += c;
		}
	}

	return ans;
}

// Driver code
int main()
{

	// Vector pairs of points
	vector<pair<int, int> > points = {
		{ 1, 1 },
		{ 2, 2 },
		{ 2, 3 }
	};

	// Function calling and printing
	// the answer
	cout << minCost(points);

	return 0;
}
