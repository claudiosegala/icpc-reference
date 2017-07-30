#include "template.hpp"

pair<int,vector<int>> lis(vector<int> &v){
	int n = v.size();
	vector<int> st(n+1,oo);
	st[0] = -oo;

	int last=0;
	FOR(i,n){
		if(v[i] > st[last]){
			st[++last] = v[i];
		}
		else{
			*lower_bound(st.begin(), st.end(),v[i]) = v[i];
		}
	}
	return make_pair(last,st);
}

int main(){
	vector<int> v = {1,5,0,2,5,5,2,3,4};
	auto out = lis(v);
	FOR2(i,1,out.ff+1)cout << out.ss[i] << " ";cout << endl;
}
