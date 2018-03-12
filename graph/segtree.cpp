class SegTree{
	vector<int> st;
	vector<int> lazy;
	int n;
	void prop(int p, int L, int R){
		if(lazy[p]){
			st[p] += lazy[p];
			lazy[2*p] += lazy[p];
			lazy[2*p+1] += lazy[p];
			lazy[p] = 0;
		}
	}

	void upd(int p, int L, int R, int i, int j, int v){
		prop(p, L, R);

		if(j < L || i > R) return;
		if(i <= L && R <= j){
			lazy[p] = v;
			prop(p, L, R);
			return;
		}

		int mid = (L+R)/2;

		upd(2*p, L, mid, i, j, v);
		upd(2*p+1, mid+1, R, i, j, v);

		st[p] = max(st[2*p],st[2*p+1]);
	}
	
	int qry(int p, int L, int R, int i, int j){
		prop(p, L, R);

		if(j < L || i > R) return 0;
		if(i <= L && R <= j) return st[p];

		int mid = (L+R)/2;

		return max(qry(2*p, L, mid, i, j), qry(2*p+1, mid+1, R, i, j));
	}

public:

	SegTree(int sz){
		n = sz;
		st.assign(8*(n + 1), 0);
		lazy.assign(8*(n + 1), 0);
	}

	int qry(int i, int j){
		return qry(1, 1, n, i, j);
	}

	void upd(int i, int j, int v){
		upd(1, 1, n, i, j, v);
	}

};
