vector<iii> out;
void kruskal(){
	for(int i = 0; i < n_vertices; i++) make_set(i);
	sort(graph.bg(), graph.nd()); // ii(peso, ii(u, v))
	for(int i = 0; i < graph.size(); i++)
		if(find(graph[i].ss.ff) != find(graph[i].second.second))
			joint(graph[i].second.first, graph[i].second.second);
		else
			out.pb(graph[i]);
}