class Trie {
    public:
    Trie () : _next(1) {
        for (int i = 0; i <= MAX; i++) {
            _endw[i] = false;
            _qnt[i] = 0;
        }
    }

    void add (string& str) {
        int idx = 0;

        for (auto c : str) {
            auto &node = _tree[idx];

            if (!node.count(c)) {
                node[c] = _next++;
            }

            _qnt[idx]++;
            idx = node[c];
        }

        _endw[idx] = true;
    }

    bool search (string& str) {
        int idx = 0;

        for (auto c : str) {
            auto &node = _tree[idx];

            if (!node.count(c)) {
                return false;
            }

            idx = node[c];
        }

        return _endw[idx];
    }

    void clear () {
        for (int i = 0; i <= _next; i++) {
            _tree[i].clear();
            _endw[i] = false;
            _qnt[i] = 0;
        }

        _next = 1;
    }

    int dfs (int idx = 0) {
        auto &node = _tree[idx];
        auto ans = node.size() > 1 || idx == 0 || _endw[idx] ? _qnt[idx] : 0;

        for (auto u : node) {
            ans += dfs(u.second);
        }

        return ans;
    }

    private:
    int _next;
    int _qnt[MAX];
    bool _endw[MAX];
    map<char, int> _tree[MAX];
};