#include <bits/stdc++.h>
using namespace std;

class DinnerPlates
{
private:
        int capacity;
        vector<vector<int>> stacks;
        vector<int> available;

public:
        DinnerPlates(int capacity)
        {
                this->capacity = capacity;
        }

        void push(int val)
        {
                if (available.empty() || available.back() == stacks.size() - 1)
                {
                        stacks.push_back(vector<int>());
                        available.push_back(stacks.size() - 1);
                }

                stacks[available.back()].push_back(val);

                if (stacks[available.back()].size() == capacity)
                {
                        available.pop_back();
                }
        }

        int pop()
        {
                while (!stacks.empty() && stacks.back().empty())
                {
                        stacks.pop_back();
                        available.pop_back();
                }

                if (stacks.empty())
                {
                        return -1;
                }

                return popAtStack(stacks.size() - 1);
        }

        int popAtStack(int index)
        {
                if (index >= stacks.size() || stacks[index].empty())
                {
                        return -1;
                }

                int val = stacks[index].back();
                stacks[index].pop_back();

                if (index < available.size() && index < stacks.size() - 1)
                {
                        available.back() = index;
                }
                else if (stacks.back().empty())
                {
                        available.pop_back();
                        stacks.pop_back();
                }

                return val;
        }
};

int main()
{
        DinnerPlates D = DinnerPlates(2);

        D.push(1);
        D.push(2);
        D.push(3);
        D.push(4);
        D.push(5);

        cout << D.popAtStack(0) << endl;
        // D.display();

        D.push(20);
        D.push(21);

        // D.display();

        cout << D.popAtStack(0) << endl;
        // D.display();
        cout << D.popAtStack(2) << endl;
        //    D.display();
        cout << D.pop() << endl;
        cout << D.pop() << endl;
        cout << D.pop() << endl;
        cout << D.pop() << endl;
}