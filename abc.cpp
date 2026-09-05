#ifndef ONLINE_JUDGE
#define _GLIBCXX_DEBUG//[]で配列外参照をするとエラーにしてくれる。上下のやつがないとTLEになるので注意
#endif
#include <bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using namespace std;
using namespace boost::multiprecision;
#include <atcoder/all>
using namespace atcoder;
#define YES std::cout << "Yes" << std::endl
#define NO std::cout << "No" << std::endl
#define rep(i,n) for (ll i = 0; i < (ll) (n); ++i)
#define rrep(i, n) for (ll i = (n)-1; i >= 0; i--)
#define repab(i,a,b) for (ll i=(a); i<(ll) (b); ++i)
#define ANS(ans) print(ans ? "Yes" : "No");
#define sort stable_sort
#define all(a) (a).begin(), (a).end()
#define dame std::cout << -1 << std::endl
#define popcount(x) __builtin_popcountll(x) 
// using mint = atcoder::modint1000000007;
using mint = atcoder::modint998244353;
using ll        = long long; 
using ull       = unsigned long long;
using ld        = long double;
using ui        = unsigned int;
using pint      = pair<int, int>;
using pll       = pair<ll, ll>; 
using tint      = tuple<int, int, int>; 
using tll       = tuple<ll, ll, ll>;
using vint      = vector<int>;
using vvint     = vector<vint>;
using vvvint    = vector<vvint>;
using vvvvint   = vector<vvvint>;
using vll       = vector<ll>;
using vvll      = vector<vll>;
using vvvll     = vector<vvll>;
using vvvvll    = vector<vvvll>;
using vb        = vector<bool>;
using vvb       = vector<vb>;
using vvvb      = vector<vvb>;
using vvvvb     = vector<vvvb>;
using vst       = vector<string>;
using vpint     = vector<pair<int, int>>;
using vpll      = vector<pair<ll, ll>>;
using vvpll     = vector<vpll>;
using vvpint    = vector<vpint>;
using vtint     = vector<tint>;
using vtll      = vector<tll>;
using vvtint    = vector<vtint>;
using vvtll     = vector<vtll>;
using vmint     = vector<mint>;
using vvmint    = vector<vmint>;
const ll INF    = 1LL << 60;
const int inf   = 2e9;
struct Edge {
    int to; ll w;
    Edge(int to, ll w) : to(to), w(w) {}
};
namespace operators
{
    
    template<class T> vector<T> operator-=(vector<T> &lhs, const vector<T> &rhs) {
        assert(lhs.size() == rhs.size());
        rep(i, lhs.size()) {    
            lhs[i] -= rhs[i];
        }
        return lhs;
    }
    template<class T> vector<T> operator+=(vector<T> &lhs, const vector<T> &rhs) {
        assert(lhs.size() == rhs.size());
        rep(i, lhs.size()) {    
            lhs[i] += rhs[i];
        }
        return lhs;
    }
    template<class T> vector<T> operator+(vector<T> lhs, vector<T> rhs) {
        assert(lhs.size() == rhs.size());
        int size = lhs.size();
        vector<T> res(size);
        rep(i, size) {
            res[i] = lhs[i] + rhs[i];
        } 
        return res;
    }
    template<class T> vector<T> operator-(vector<T> lhs, vector<T> rhs) {
        
        assert(lhs.size() == rhs.size());
        int size = lhs.size();
        vector<T> res(size);
        rep(i, size) {
            res[i] = lhs[i] - rhs[i];
        } 
        return res;
    }
    template<class T, class U> pair<T, U> operator+(const pair<T, U> lhs, const pair<T, U> rhs) {
        return make_pair(lhs.first + rhs.first, lhs.second + rhs.second);
    }
    template<class T> pair<T, T> operator-(pair<T, T> &lhs, const pair<T, T> &rhs) {
        return make_pair(lhs.first - rhs.first, lhs.second - rhs.second);
    }
    template<class T> pair<T, T> operator-=(pair<T, T> &lhs, const pair<T, T> &rhs) {
        lhs.first -= rhs.first;
        lhs.second -= rhs.second;
        return lhs;
    }
    template<class T, class U> pair<T, U> operator+=(pair<T, U> &lhs, const pair<T, U> &rhs) {
        lhs.first += rhs.first;
        lhs.second += rhs.second;
        return lhs;
    }
    template<class T> ostream& operator<<(ostream& os, const set<T> &st) {
        string res = "(";
        for (auto x : st) res += to_string(x) + ", ";
        if (st.size()) {
            rep(_, 2) res.pop_back();
        }
        res += ")";
        os << res;
        return os;
    }
    template<class T1, class T2> inline ostream& operator<<(ostream& os, const pair<T1, T2> &p) {
        os << '(' << p.first << ", " << p.second << ')';
        return os;
    }
    template<class T1, class T2, class T3> inline ostream& operator<<(ostream& os, const tuple<T1, T2, T3> &t) {
        os << '(' << std::get<0>(t) << ", " << std::get<1>(t) << ", " << std::get<2>(t) << ')';
        return os;
    }
    inline ostream& operator<<(ostream& os, const modint998244353 &m) {
        os << m.val();
        return os;
    }
    inline ostream& operator<<(ostream& os, const modint1000000007 &m) {
        os << m.val();
        return os;
    }
    template<class T> inline ostream& operator<<(ostream& os, const vector<T> &vec) {
        os << "{";
        rep(i, vec.size()) os << vec[i] << vst({", ", ""})[i == vec.size()-1];
        os << "}";
        return os; 
    }
    template<class T1, class T2> inline istream& operator>>(istream& is, pair<T1, T2>& p) {
        is >> p.first >> p.second;
        return is;
    }
    template<class T> inline istream& operator>>(istream& is, vector<T>& p) {
        rep(i, p.size()) is >> p[i];
        return is;
    }
} // namespace operators
using namespace operators;

namespace comb {
    const int MAX = 6100000;
    mint fac[MAX], finv[MAX], inv[MAX];
    
    // テーブルを作る前処理
    void init() {
        const int MOD = mint::mod();
        fac[0] = fac[1] = 1;
        finv[0] = finv[1] = 1;
        inv[1] = 1;
        for (int i = 2; i < MAX; ++i){
            fac[i] = fac[i - 1] * i;
            inv[i] = MOD - inv[MOD%i] * (MOD / i);
            finv[i] = finv[i - 1] * inv[i];
        }
    }
    
    // 二項係数計算
    mint com(int n, int k){
        if (n < k) return 0;
        if (n < 0 || k < 0) return 0;
        mint res = fac[n] * finv[k];
        res *= finv[n - k];
        return res;
    }
} // namespace comb

void print() {
    cout << endl;
}
template<class T1, class T2> void print(map<T1, T2> &mp) {
    for (auto [x1, x2] : mp) {
        cout << "{" << x1 << " : " << x2 << "}" << endl;
    }
} 
template<class T> void print(vector<vector<T>> &vec) {
    rep(i, vec.size()) {
        for (auto x : vec[i]) cout << x << " ";
        cout << endl;
    }
}
template<typename T, typename... Args> void print(const T& first, const Args&... args) {
    cout << first;
    ((cout << " " << args), ...);
    cout << endl;
}
template<class T> inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}
template<class T> inline void vv_cout(vector<vector<T>> &a) {
    rep(i, a.size()) {
        for (T n : a[i]) cout << n << " ";
        cout << endl;
    }
}
template<class T> inline void v_cout(vector<T> &a) {
    for (T x : a) cout << x << " ";
    cout << endl;
}
template<class T> inline void st_cout(set<T> &st) {
    for (T x : st) cout << x << " ";
    cout << endl;
}
template<class T> inline T floor(T x, T m) {
    T r = (x % m + m) % m;
    return (x - r)/m;
}
template<class T> inline T ceil(T a, T b) { 
    return (a + b - 1)/b; 
}

struct Point {
    ll x, y;
    Point(pll a) : x(a.first), y(a.second) {}
    Point(ll x, ll y) : x(x), y(y) {}
    Point operator-(const Point& other) const {
        return {x - other.x, y - other.y};
    }
    Point operator+(const Point& other) const {
        return {x + other.x, y + other.y};
    }
};
// 外積a×b
ll cross(Point a, Point b) {
    return a.x * b.y - a.y * b.x;
}
// 内積
ll dot(Point a, Point b) {
    return a.x * b.x + a.y * b.y;
}
// xをm進数に変換(i文字目はm^iに対応)
template<class T> inline vector<T> to_m_digit(T n, T m) {
    if (n == 0) return vector<T>({0});
    vector<T> res;
    while (n) {
        res.push_back(n%m);
        n /= m;
    }
    return res;
}

// LCA を求めるライブラリ(2頂点間のパスの長さを求められる。最短の共通の祖先がわかる)
struct LCA {
    using Graph = vector<vector<int>>;
    vector<vector<int> > parent; // parent[d][v] := 2^d-th parent of v
    vector<int> depth;
    LCA() { }
    LCA(const Graph &G, int r = 0) { init(G, r); }
    void init(const Graph &G, int r = 0) {
        int V = (int)G.size();
        int h = 1;
        while ((1<<h) < V) ++h;
        parent.assign(h, vector<int>(V, -1));
        depth.assign(V, -1);
        dfs(G, r, -1, 0);
        for (int i = 0; i+1 < (int)parent.size(); ++i)
        for (int v = 0; v < V; ++v)
        if (parent[i][v] != -1)
        parent[i+1][v] = parent[i][parent[i][v]];
    }
    void dfs(const Graph &G, int v, int p, int d) {
        parent[0][v] = p;
        depth[v] = d;
        for (auto e : G[v]) if (e != p) dfs(G, e, v, d+1);
    }
    // O(log_2(木の深さ))？
    int get(int u, int v) {
        if (depth[u] > depth[v]) swap(u, v);
        for (int i = 0; i < (int)parent.size(); ++i)
        if ( (depth[v] - depth[u]) & (1<<i) )
        v = parent[i][v];
        if (u == v) return u;
        for (int i = (int)parent.size()-1; i >= 0; --i) {
            if (parent[i][u] != parent[i][v]) {
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }
};

struct Timer {
    std::chrono::steady_clock::time_point start;
    const char* name;

    Timer(const char* name) : start(std::chrono::steady_clock::now()), name(name) {}

    ~Timer() {
        auto end = std::chrono::steady_clock::now();
        auto dur = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cerr << name << ": " << dur << " ms\n";
    }
};
#define TIME_BLOCK(name) Timer timer_##__LINE__(name)

// return x^k(O(k))
inline ll pw(ll x, ll k) {
    ll res = 1;
    rep(_, k) res *= x;
    return res;
} 

// 素数判定(O√N)
template<class T> inline bool is_prime(T n) {
    for (T i = 2; i*i <= n; ++i) {
        if (n % i == 0) return false;
    } return true;
}

inline void cout_grid(vector<string> &grid) {
    rep(i, grid.size()) {
        rep(j, grid[i].size()) cout << grid[i][j];
        cout << endl;
    }
}
// ユークリッド距離を計算
inline ll euclideanDistance(const pll a, const pll b) {
    return pw(a.first - b.first, 2) + pw(a.second - b.second, 2);
}
// nを素因数分解(first = 素数, second = 指数)
vector<pll> prime_factorize(ll n) {
    vpll res;
    for (ll a = 2; a*a <= n; ++a) {
        if (n % a) continue;
        int ex = 0;
        while(n % a == 0) ++ex, n /= a;
        res.push_back({a, ex});
    }
    if (n != 1) res.push_back({n, 1});
    return res;
}
// マンハッタン距離を計算
template<class T> inline T man(const pair<T, T> &a, const pair<T, T> &b) {
    return abs(a.first - b.first) + abs(a.second - b.second);
}

// return log_bottom(x)(supは適切な範囲で：2なら2^60（=sup）まで)
ll log_integer(ll x, ll sup, ll bottom) {
    // assert(x > 0 and sup > x);
    ll ok = 0, ng = sup;
    while(ng - ok > 1) {
        ll mid = (ok + ng)/2;
        auto f = [&]() {
            ll tmp = pw(bottom, mid);
            return tmp <= x;
        };
        if (f()) ok = mid;
        else ng = mid;
    }
    return ok;
}

// cの中にcharsの要素が含まれているかを判定
inline bool contain(char &c, string chars) {
    for (auto _c : chars) {
        if (c == _c) return true;
    }
    return false;
}
// 範囲外参照をするかを判定
inline bool outOfRange(ll i, ll j, ll hight, ll width) {
    return i < 0 or i >= hight or j < 0 or j >= width;
}
// 最小公倍数L = a/gcd(a, b)*b

// エラトステネスの篩
void Eratosthenes(vector<int> &vec){
    vec[0] = vec[1] = 0;
    for(int i=2; i*i < (int) vec.size(); ++i){
        if(vec[i]==0) continue;
        
        int x = i+i;
        while(x < (int) vec.size()){
            vec[x]=0;
            x += i;
        }
    }
}
// template<class T> T gcd(T a, T b) { if (b == 0) return a; else return gcd(b, a % b); } 

vector<pair<char, ll>> RLE(string &s) {
    vector<pair<char, ll>> rle;
    rep(i, s.size()) {
        if (rle.empty()) rle.emplace_back(s[i], 1);
        else {
            if (rle.back().first == s[i]) ++rle.back().second;
            else rle.emplace_back(s[i], 1);
        }
    }
    return rle;
}

template<class T> vector<pair<T, ll>> RLE(vector<T> vec) {
    vector<pair<T, ll>> rle;
    rep(i, vec.size()) {
        if (rle.empty()) rle.emplace_back(vec[i], 1);
        else {
            if (rle.back().first == vec[i]) ++rle.back().second;
            else rle.emplace_back(vec[i], 1);
        }
    }
    return rle;
}
// [l, r]の範囲で偶数の個数を求める
ll cnt_even(ll l, ll r) {
    // l ≤ r
    if (l > r) return 0;
    return (r+1 - l)/2 + (l % 2 == 0 and r % 2 == 0);
}

//　自分の周りの８方向
// const vint di = {+1, +1, +1, +0, +0, -1, -1, -1};
// const vint dj = {-1, +0, +1, +1, -1, -1, +0, +1};

// 自分の周りの4方向
const vint di = {-1, +0, +1, +0};
const vint dj = {+0, +1, +0, -1};
// string input_text_name = "input.txt";
// ifstream in(input_text_name); cin.rdbuf(in.rdbuf()); 
// cout << setprecision(20) << ans << endl;

void _main() {
}

int main() {
    cin.tie(0); 
    ios::sync_with_stdio(false);
    _main();
    return 0;
}