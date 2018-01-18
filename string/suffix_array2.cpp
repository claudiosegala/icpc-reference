#include <bits/stdc++.h>
 
using namespace std;
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rk1 ff.ff
#define rk2 ff.ss

const int N = 200005;

typedef unsigned long long ll;
typedef pair<int,int> ii;

ll mod;

int sa[100005];
int lcp[100005];

void cnt_sort(pair<ii, int> v[], int n){
	int ma1 = 0, ma2 = 0;
	for(int i = 0; i < n; i++){
		ma1 = max(ma1, v[i].rk1);
		ma2 = max(ma2, v[i].rk2);
	}
	ma2 += 2;
	int t = ma1 * ma2 + ma2;
	vector<pair<ii, int> > cnt[t + 2];
	memset(cnt, 0, sizeof cnt);

	for(int i = 0; i < n; i++)
		cnt[v[i].rk1 * ma2 + v[i].rk2 + 1].pb(v[i]);

	int id = 0;
	for(int i = 0; i < t; i++)
		for(pair<ii, int> j : cnt[i])
			v[id++] = j;
}

void build_sa(char s[], int n){
	pair<ii, int> v[n+1];
	int s2[n+1];
	for(int i = 0; i < n; i++){
		s2[i] = s[i] - 'a';
		v[i].rk1 = s[i] - 'a';
		v[i].rk2 = s[i+1] - 'a';
		v[i].ss = i;
	}
	v[n-1].rk2 = -1;

	cnt_sort(v, n);

	for(int k = 2; k < n; k *= 2){
		int ant1 = v[0].rk1, ant2 = v[0].rk2;
		v[0].rk1 = 0;
		s2[v[0].ss] = 0;

		for(int i = 1; i < n; i++){
			if(v[i].rk1 == ant1 && v[i].rk2 == ant2){
				ant1 = v[i].rk1;
				ant2 = v[i].rk2;
				v[i].rk1 = v[i-1].rk1; 
			}
			else{
				ant1 = v[i].rk1;
				ant2 = v[i].rk2;
				v[i].rk1 = v[i-1].rk1 + 1;
			}
			s2[v[i].ss] = v[i].rk1;
		}
		for(int i = 0; i < n; i++)
			v[i].rk2 = v[i].ss + k >= n ? -1 : s2[v[i].ss + k];

		cnt_sort(v, n);
	}

	for(int i = 0; i < n; i++)
		sa[i] = v[i].ss;
}

void build_lcp(char s[], int n){
	int invsa[n+1];
	for(int i = 0; i < n; i++)
		invsa[sa[i]] = i;

	int ini = 0;
	for(int i = 0; i < n; i++){
		if(invsa[i] == n-1) lcp[invsa[i]] = 0;
		else{
			int j = ini + i;
			int k = ini + sa[invsa[i] + 1];
			while(j < n && k < n && s[j] == s[k]){
				j++;
				k++;
			}
			lcp[invsa[i]] = j - i;
		}

		ini = max(0, lcp[invsa[i]] - 1);
	}
}

char sa_search(char s[], int n, char c[]){
	int m = strlen(c);
	int l = 0, r = n-1;
	int i = 0;
	while(i < m){
		while(l <= r && s[sa[l] + i] != c[i])
			l++;
		while(l <= r && s[sa[r] + i] != c[i])
			r--;
		i++;
	}
	for(int i = l; i <= r; i++)
		printf("%d ",sa[i]);
	printf("fim\n");
}

int main(){
	char s[100005];
	scanf("%s",s);
	int n = strlen(s);
	build_sa(s, n);
	build_lcp(s, n);

	printf("Suffix array:\n");
	for(int i = 0; i < n; i++)
		printf("%d ",sa[i] );
	printf("\n\n");

	printf("LCP:\n");
	for(int i = 0; i < n; i++)
		printf("%d ",lcp[i] );
	printf("\n");
}
