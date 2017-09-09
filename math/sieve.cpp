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
