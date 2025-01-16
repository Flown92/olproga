#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using ld = long double;
using graph = vector<vector<int>>;

const int MAXN = 100'000;
const int mod = 1'000'000'000 + 7;
const int inf = numeric_limits<int>::max() - 1;

template <typename T>
istream &operator>>(istream &is, vector<T> &a);

template <typename T>
ostream &operator<<(ostream &os, vector<T> &a);

inline void io();

#define int ll

int32_t main() {
  io();

  int a, b, c, t;
  cin >> a >> b >> c >> t;

  for (int it = 0; it < t; ++it) {
    int minn = min({a, b, c}), maxx = max({a, b, c}), all = a + b + c;
    int vtor = all - minn - maxx;
    if (all - minn - maxx == minn) vtor = maxx;
    if (minn == a) {
      a = vtor * 2 - a;
    } else if (minn == b) {
      b = vtor * 2 - b;
    } else {
      c = vtor * 2 - c;
    }
  }
  cout << a << " " << b << " " << c << "\n";
}

template <typename T>
ostream &operator<<(ostream &os, vector<T> &a) {
  for (int i = 0; i < a.size(); i++) os << a[i] << " \n"[i == a.size() - 1];
  return os;
}

template <typename T>
istream &operator>>(istream &is, vector<T> &a) {
  for (auto &i : a) is >> i;
  return is;
}

inline void io() {
#ifdef LOCAL
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
#else
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
#endif
}
