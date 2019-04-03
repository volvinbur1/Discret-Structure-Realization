#include <iostream>
#include <ctime>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

bool dfs(vector<vector<bool>> _graph, uint32_t _vertex, uint32_t _goal_vertex, int** &_arr);
bool bfs(vector<vector<bool>> _graph, uint32_t _vertex, uint32_t _goal_vertex, int** &_arr);

int main()
{
	vector<vector<bool>> graph = {  {0, 1, 1, 0},
									{1, 0, 1, 1},
									{1, 1, 0, 1},
									{0, 1, 1, 0} };

	int** g_arr = new int*[2]; // 0 - market vertex; 1 - vertex number 

	for (uint32_t i = 0; i < 2; i++)
	{
		g_arr[i] = new int[graph[0].size()];
		for (uint32_t j = 0; j < graph[0].size(); j++)
			g_arr[i][j] = 0;
	}

	clock_t dfs_start_time = clock();

	bool dfs_result = dfs(graph, 0, 3, g_arr);

	double dfs_run_time = (clock() - dfs_start_time) / CLOCKS_PER_SEC;

	for (uint32_t i = 0; i < 2; i++)
		for (uint32_t j = 0; j < graph[0].size(); j++)
			g_arr[i][j] = 0;

	clock_t bfs_start_time = clock();

	bool bfs_result = bfs(graph, 0, 3, g_arr);

	double bfs_run_time = (clock() - dfs_start_time) / CLOCKS_PER_SEC;

	system("PAUSE");
}

bool dfs(vector<vector<bool>> _graph, uint32_t _vertex, uint32_t _goal_vertex, int** &_arr)
{
	int n = 0;

	_arr[0][_vertex] = 1;
	_arr[1][_vertex] = ++n;

	stack<int> st;
	st.push(_vertex);

	while (!st.empty())
	{
		int v = st.top();
		st.pop();

		if (v == _goal_vertex)
			return true;

		for (uint32_t i = 0; i < _graph[0].size(); i++)
			if (_graph[v][i] == 1)
				if (_arr[0][i] == 0)
				{
					_arr[0][i] = 1;
					_arr[1][i] = ++n;

					st.push(i);
					break;
				}
	}

	return false;
}

bool bfs(vector<vector<bool>> _graph, uint32_t _vertex, uint32_t _goal_vertex, int** &_arr)
{
	int n = 0;

	_arr[0][_vertex] = 1;
	_arr[1][_vertex] = ++n;

	queue<int> q;
	q.push(_vertex);

	while (!q.empty())
	{
		int v = q.front();
		q.pop();

		if (v == _goal_vertex)
			return true;

		for (uint32_t i = 0; i < _graph[0].size(); i++)
			if (_graph[v][i] == 1)
				if (_arr[0][i] == 0)
				{
					_arr[0][i] = 1;
					_arr[1][i] = ++n;

					q.push(i);
				}
	}

	return false;
}
