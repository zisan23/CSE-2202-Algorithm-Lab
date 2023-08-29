#include <bits/stdc++.h>
using namespace std;

class Dinnerplates
{
private:
	vector<vector<int>> dp;
	vector<int> index; // the last number of each of the stacks
	int capacity;
	// capacity of each stacks
	int latest;
	// the number of stacks

public:
	Dinnerplates(int n)

	{
		this->dp.resize(1000);
		this->index.resize(1000);

		for (int i = 0; i < 1000; i++)

		{
			this->dp[i].resize(n);
		}
		this->capacity = n;

		for (int i = 0; i < 1000; i++)

		{
			this->index[i] = 0;
		}

		this->latest = 0;
	}

	void push(int num)

	{
		for (int ii = 0; ii < 1000; ii++)

		{
			if (this->index[ii] < this->capacity)

			{
				this->dp[ii][index[ii]] = num;
				this->index[ii] = this->index[ii] + 1;
				this->latest = max(this->latest, ii);
				return;
			}
		}
	}

	int pop()

	{
		if (this->latest == 0 && this->index[0] == 0)
			return -1;

		if (this->index[this->latest] == 0)
			return -1;

		int num = this->dp[this->latest][this->index[this->latest] - 1];
		this->index[this->latest] = this->index[this->latest] - 1;

		if (this->index[this->latest] <= 0)

		{
			this->index[this->latest] = 0;
			this->latest = this->latest - 1;
		}

		return num;
	}

	int popAtStack(int id)

	{
		if (this->index[id] == 0)
			return -1;

		int num = this->dp[id][this->index[id] - 1];
		this->index[id] = this->index[id] - 1;

		if (this->index[id] <= 0)

		{
			this->index[id] = 0;
			this->latest = this->latest - 1;
		}

		return num;
	}

	void display()

	{
		cout << "display start\n";
		for (int i = 0; i <= this->latest; i++)

		{
			for (int j = 0; j < this->index[i]; j++)
				cout
					<< this->dp[i][j] << " ";
			cout << endl;
		}
		cout << "Display done\n";
	}
};

int main()
{
	// freopen ("in1.txt", "r", stdin);
	// freopen("out1.txt", "w", stdout);

	Dinnerplates D = Dinnerplates(2);

	D.push(1);
	D.push(2);
	D.push(3);
	D.push(4);
	D.push(5);

	cout << D.popAtStack(0) << endl;
	// D.display();

	D.push(20);
	D.push(21);

	cout << D.popAtStack(0) << endl;
	cout << D.popAtStack(2) << endl;

	// D.display();

	cout << D.pop() << endl;
	cout << D.pop() << endl;
	cout << D.pop() << endl;
	cout << D.pop() << endl;
	cout << D.pop() << endl;
}

#include <iostream>
using namespace std;

class DinnerPlates
{
public:
	const int maxsize = 10;
	int a[10][10];
	int left;
	int right;
	int cap;

	DinnerPlates(int x)
	{
		left = 0;
		right = 0;
		cap = x;

		for (int i = 0; i < maxsize; i++)
		{
			for (int j = 0; j < x; j++)
			{
				a[i][j] = 0;
			}
		}
	}

	void push(int x)
	{
		for (int i = 0; i < maxsize; i++)
		{
			for (int j = 0; j < cap; j++)
			{
				if (a[i][j] == 0)
				{
					a[i][j] = x;
					return;
				}
			}
		}
	}

	void pop(void)
	{
		for (int i = maxsize - 1; i >= 0; i--)
		{
			for (int j = cap - 1; j >= 0; j--)
			{
				if (a[i][j] > 0)
				{
					a[i][j] = 0;
					return;
				}
			}
		}
	}

	void popapatstack(int idx)
	{
		for (int i = cap - 1; i >= 0; i--)
		{
			if (a[idx][i] > 0)
			{
				a[idx][i] = 0;
				return;
			}
		}
	}

	void print(void)
	{
		for (int i = cap - 1; i >= 0; i--)
		{
			for (int j = 0; j < maxsize; j++)
			{
				if (a[j][i] != 0)
				{
					cout << a[j][i] << " ";
				}
				else
				{
					cout << "  ";
				}

				// cout << a[j][i] << " ";
			}
			cout << endl;
		}
		cout << endl;
	}
};

int main(int argc, char const *argv[])
{
	DinnerPlates myclass = DinnerPlates(2);

	myclass.push(1);
	myclass.push(2);
	myclass.push(3);
	myclass.push(4);
	myclass.push(5);

	myclass.print();

	myclass.popapatstack(0);

	myclass.print();

	myclass.push(20);
	myclass.push(21);

	myclass.print();

	myclass.popapatstack(0);

	myclass.print();

	return 0;
}