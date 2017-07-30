#include "template.hpp"

class uFind{
	vector<int> pai;
public:
	int cont;
	uFind(int n):pai(n),cont{n}{
		FOR(i,n)pai[i]=i;
	}
	int find(int i){
		if(pai[i]==i)return i;
		return pai[i]=find(pai[i]);
	}
	void merge(int i,int j){
		int a=find(i),b=find(j);
		if(a != b){
			cont--;
			pai[a]=b;
		}
	}
};
