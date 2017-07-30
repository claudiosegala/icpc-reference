#include "template.hpp"

//graph is a adjacency list with edges being ii{w,dest} 'w' = weight, 'dest' = destination
vector<int> djikstra(vector<vector<ii>> graph,int source){
	vector<int> shortest(graph.size(),oo);
	priority_queue<ii,vector<ii>,greater<ii>> pq;

	shortest[source] = 0;
	pq.emplace(0,source);
	while(!pq.empty()){
		ii cur = pq.top();
		pq.pop();

		if(cur.first > shortest[cur.second])continue;
		shortest[cur.second] = cur.first;

		for(ii &edge : graph[cur.second]){
			int weight = cur.first + edge.first;
			if(shortest[edge.second] > weight){
				shortest[edge.second] = weight;
				pq.emplace(weight,edge.second);
			}
		}
	}
	return shortest;
}


int main(){
	vector<vector<ii>> graph;
	int n,m,i,j,w;
	cin >> n >> m;
	graph.resize(n);
	FOR(it,m){
		cin >> i >> j >> w;
		graph[i].push_back(ii{w,j});
		graph[j].push_back(ii{w,i});
	}
	cin >> w;
	vector<int> out = djikstra(graph,w);
	FOR(i,out.size())cout << i << " " << out[i] << endl;
}
/* example in
5
6
0 1 5
0 2 6
1 3 7
2 4 3
2 3 1
1 4 8
0
*/
