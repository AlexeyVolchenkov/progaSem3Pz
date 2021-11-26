#include <iostream>
#include <stack>
#include <vector>
using namespace std;

void depth(int flag, vector<vector<int>>& matrix)
{
	vector<bool> passed(matrix.size(), false);
	stack<int> s;
	while (flag != -1)
	{
		if (passed[flag] == false)
		{
			passed[flag] = true;

			for (int i = 0; i < matrix.size(); i++)
				if (matrix[flag][i] == 1 && passed[i] == false) s.push(i);
		}

		if (s.size() > 0)
		{
			flag = s.top();
			s.pop();
		}
		else flag = -1;
	}

	for (bool row_matrix : passed)
	{
		cout << row_matrix << ' ';
	}
	cout << endl;
}
int main()
{
	int N, flag = 0;
	cin >> N;

	vector<vector<int>> matrix(N, vector<int>(N, 0));

	int x;
	for (int i = 0; i < N; i++)
	{
		do
		{
			cin >> x;
			//Матрица смежности
			if (x != 0) matrix[i][x - 1] = 1;

		} while (cin.peek() != '\n');
	}
	cout << endl;
	for (int i = 0; i < N; i++) depth(i, matrix);
}