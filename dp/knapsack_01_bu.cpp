int knapsack(vector<int> w, vector<int> v, int W) {
    int n = w.size();
    int matrix = int[n + 1][W + 1];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < W; j++) {
            matrix[i][j] = 0;
        }
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= W; j++) {
            int weight = w[i - 1];
            if(weight<=j){
                matrix[i][j] = max(
                    v[i - 1] + matrix[i - 1][j - weight],
                    matrix[i - 1][j]
                );
            }else{
                matrix[i][j]=matrix[i-1][j];
            }

        }
    }
    return matrix[n][W];
}