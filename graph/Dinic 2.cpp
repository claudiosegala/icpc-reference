int bfs(int s,int t){
	queue<int> q;
	int v;
	int i;
	level[s] = 0;
	q.push(s);

	while(!q.empty()){
		v = q.front();
		q.pop();

		for(i = 0; i < adj[v].size(); i++){
			if(level[adj[v][i]] == -1 && cap[v][adj[v][i]] > 0){
				q.push(adj[v][i]);
				level[adj[v][i]] = level[v] + 1;
			}
		}
	}

	return level[t] == -1;
}

int dfs(int x, int t, int flow){
	if(x == t) return flow;

	for(; v[x] < adj[x].size(); v[x]++){
		if(level[adj[x][v[x]]] == level[x] + 1 && cap[x][adj[x][v[x]]] > 0){
			int currflow = min(flow,cap[x][adj[x][v[x]]]);
			currflow = dfs(adj[x][v[x]], t, currflow);

			// se consegue chegar em t
			if(currflow){
				// subtrai da aresta utilizada e soma na inversa
				cap[x][adj[x][v[x]]] -= currflow;
				cap[adj[x][v[x]]][x] += currflow;
				return currflow;
			}
		}
	}

	return 0;
}

void dinic(int s,int t){
	while(1){
		memset(level, -1, sizeof level);
		// verifica se existe um caminho de s para t e coisa o vetor level
		// level[i] = distancia de s a i
		if(bfs(s,t)) break;

		// v[i] salva qual foi a ultima aresta utilizada no dfs pelo vertice i
		// pra nao fazer o dfs varias vezes
		memset(v, 0, sizeof v);
		while(int temp = dfs(s,t,oo)) maxflow += temp;
	}
}
