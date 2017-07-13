///////////////
// UNION FIND
///////////////

int parent[MAXVERTICES];
void make_set(int x){ parent[x] = x; }
int find(int x){ return (parent[x] == x)? x : parent[x] = find(parent[x]); }
int joint(int x, int y){ return parent[find(x)] = find(y); }

///////////////
// KRUSKAL
///////////////

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

///////////////
// Djikstra
///////////////

#define pair<int, int> ii;
#define vector<ii> vii;
#define verticesMAX 5000
int vertices, arestas;

vector<int> shortest(verticesMAX, INF);
vector<vii> graph(verticesMAX + 1); // [u][peso, v]

void djikstra(int source, int destination){
	priority_queue< pii, vector< pii >, greater< pii > > Q;
	shortest[source] = 0;
	Q.push(ii(0, source));
	while(not Q.empty()){
		auto current = Q.top().second; 
		auto current_weight = Q.top().first; 
		Q.pop(); 
		for(auto g : graph[current]) {
			int V = g[i].first, W = g[i].second, tmp = current_weight + W;
			if( shortest[V] > tmp) {
				shortest[V] = tmp;
				Q.push(ii(shortest[V], V)); 
			}
		}
	}
	printf("%d\n", shortest[destination]);
}

///////////////
// CRIVO DE ERASTHOTENES
///////////////

void sieveErathostenes(vector<int>& out, int n){
	vector<bool> v(n+1);
	out.push_back(2);
	for(int j = 3; j <= n; j += 2) v[j] = true;
	for(int j = 4; j <= n; j += 2) v[j] = false;
	int i;
	for(i = 3; i*i <= n; i += 2)
		if(v[i]){
			out.push_back(i);
			for(int j = i*i; j <= n; j = j * i) v[j] = false;
		}
	for(;i <= n; i++)
		if(v[i]) out.push_back(i);
}

///////////////
// FAST POT
///////////////

int fastPot(int x, int exp){
	if(!exp)	return 1;
	if(exp%2)	return x * fastPot(x*x, (exp-1)/2);
	return fastPot(x*x, exp/2);
}

///////////////
// FAST FIBONNACI       -need_revision
///////////////

typedef struct { int v[2][2]; } matriz;
matriz I, FIB;

matriz MM(matriz x, matriz y){ // MATRIZ MULTIPLICATION
    matriz k;
    for(int i = 0; i < 2; i++)
        for(int j = 0; j < 2; j++)
            k.v[i][j] = (x.v[i][0] * y.v[0][j] + x.v[i][1] * y.v[1][j]);
    return k;
}

matriz fastPot(matriz x, int exp){ // FASTPOT MATRIZ EDITION
    if(exp <= 0) return I;
    if(exp%2)   return MM(x, fastPot(MM(x, x), (exp-1)/2));
    return fastPot(MM(x, x), exp/2);
}

void startFastPot(int N) {
    I.v[0][1] = I.v[1][0] = 0; I.v[0][0] = I.v[1][1] = 1; // matriz identidade
    FIB.v[0][0] = FIB.v[0][1] = FIB.v[1][0] = 1; FIB.v[1][1] = 0;
    FIB = fastPot(INI, N); // N é o n-ézimo número de fibonacci
 	// resposta está em FIB.v[1][0]
}

///////////////
// Binary Search
///////////////

int bb(int* v, int p, int q, int x){
	int r;
	while(p < q){
		r = (p + q)/2;
		if(v[r] == x) return r;
		if(v[r] > x)	q = r-1;
		else 			p = r+1;
	}
	return -1;
}

///////////////
// Binomial Coefficient -need_revision
///////////////

long binomial_coefficient(n,m){ /* Calculo de Arranjo Rápido */
	int n,m;
	int i,j;
	long bc[MAXN][MAXN];
	for(i=0; i<=n; i++) bc[i][0] = 1;
	for(j=0; j<=n; j++) bc[j][j] = 1;
	for(i=1; i<=n; i++)
		for(j=1; j<i; j++)
			bc[i][j] = bc[i-1][j-1] + bc[i-1][j];
	return( bc[n][m] );
}

///////////////
// GCD
///////////////

int gcd(int a, int b){ return (a%b)? gcd(b, a%b) : b; }

///////////////
// LCM
///////////////

int lcm(int a, int b){ auto g = gcd(a, b); return g ? (a / g * b) : 0; }

///////////////
// Josefus Problem
///////////////

int f(int n, int k){	// Quantidade de pessoas e o tamanho do salto
	if(n == 1) return 1;
	return (f(n-1, k) + k - 1)%n + 1;
}

///////////////
// Merge Sort
///////////////

void intercala( int * v, int p, int q, int r){
	int i = p, j = q, k = 0;
	vector<int> w(r-p);
	while (i < q && j < r)
		if (v[i] <= v[j]) {
			w[k++] = v[i++];
			cnt += q - i; // conta o numero de trocas
		}
		else				w[k++] = v[j++];
	while (i < q)  w[k++] = v[i++];
	while (j < r)  w[k++] = v[j++];
	for (i = p; i < r; ++i)  v[i] = w[i-p];
}

void merge_sort (int* v, int p, int r){
	if (p < r-1){
		int q = (p+r)/2;
		merge_sort (v, p, q);
		merge_sort (v, q, r);
		intercala(v, p, q, r);
	}
}

///////////////
// Tips
///////////////

// Permutações
next_permutation(myints,myints+3)
prev_permutation(myints,myints+3)

// para saber se é potencia de 2 basta
bool is_power_of_2(int i) {
    if ( i <= 0 ) {
        return 0;
    }
    return ! (i & (i-1));
}

// le como heaxadecimal
scanf("%x")

// le como notação cientifica
scanf("%e")

