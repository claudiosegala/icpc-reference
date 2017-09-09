#include "template.hpp"
#include "uFind.cpp"

//graph is a vector of edges (w,i,j) 'i' to 'j' with weight 'w'
//return is a vector of the edges to include
vector<ii> kruskal(vector<array<int,3>> graph,int graphSZ){
	vector<ii> ret;
	uFind u(graphSZ);
	sort(graph.begin(), graph.end());
	for(auto &edge : graph){
		if(u.cont == 1)break;
		if(u.find(edge[1]) != u.find(edge[2])){
			u.merge(edge[1],edge[2]);
			ret.push_back(ii{edge[1],edge[2]});
		}
	}
	return ret;
}



int main(){
	vector<array<int,3>> graph;
	int n,m,i,j,w;
	cin >> n >> m;
	graph.resize(m);
	FOR(it,m){
		cin >> i >> j >> w;
		graph.push_back(array<int,3>{w,i,j});
	}
	vector<ii> out = kruskal(graph,n);
	FOR(i,out.size())cout << i << " " << out[i].first << "," << out[i].second << endl;
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
*/
