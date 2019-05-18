void dfs(int x) {
	if (visited[x]) return;
	visited[x] = 1;
	for (auto u : graph[x]) dfs(u);
	result.push_back(x);
}