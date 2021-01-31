#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef double db;
typedef string str;

typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<db, db> pd;

typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ll> vl;
typedef vector<db> vd;
typedef vector<str> vs;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<pd> vpd;

#define mp make_pair
#define f first
#define s second
#define sz(x) (int)x.size()
#define all(x) begin(x), end(x)
#define rall(x) (x).rbegin(), (x).rend()
#define rsz resize
#define ins insert
#define ft front()
#define bk back()
#define pf push_front
#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define F0R(i, a) FOR(i, 0, a)
#define ROF(i, a, b) for (int i = (b)-1; i >= (a); --i)
#define R0F(i, a) ROF(i, 0, a)
#define trav(a, x) for (auto &a : x)

const int MOD = 1e9 + 7; // 998244353;
const int MX = 2e5 + 5;
const ll INF = 1e18;
const ld PI = acos((ld)-1);
const int xd[4] = {1, 0, -1, 0}, yd[4] = {0, 1, 0, -1};

// INPUT
template <class A>
void re(complex<A> &c);
template <class A, class B>
void re(pair<A, B> &p);
template <class A>
void re(vector<A> &v);
template <class A, size_t SZ>
void re(array<A, SZ> &a);

template <class T>
void re(T &x) { cin >> x; }
void re(db &d)
{
  str t;
  re(t);
  d = stod(t);
}
void re(ld &d)
{
  str t;
  re(t);
  d = stold(t);
}
template <class H, class... T>
void re(H &h, T &... t)
{
  re(h);
  re(t...);
}

template <class A>
void re(complex<A> &c)
{
  A a, b;
  re(a, b);
  c = {a, b};
}
template <class A, class B>
void re(pair<A, B> &p) { re(p.f, p.s); }
template <class A>
void re(vector<A> &x) { trav(a, x) re(a); }
template <class A, size_t SZ>
void re(array<A, SZ> &x) { trav(a, x) re(a); }

// TO_STRING
#define ts to_string
template <class A, class B>
str ts(pair<A, B> p);
template <class A>
str ts(complex<A> c) { return ts(mp(c.real(), c.imag())); }
str ts(bool b) { return b ? "true" : "false"; } 
str ts(char c)
{
  str s = "";
  s += c;
  return s;
}
str ts(str s) { return s; }
str ts(const char *s) { return (str)s; }
str ts(vector<bool> v)
{
  bool fst = 1;
  str res = "{";
  F0R(i, sz(v))
  {
    if (!fst)
      res += ", ";
    fst = 0;
    res += ts(v[i]);
  }
  res += "}";
  return res;
}
template <size_t SZ>
str ts(bitset<SZ> b)
{
  str res = "";
  F0R(i, SZ)
  res += char('0' + b[i]);
  return res;
}
template <class T>
str ts(T v)
{
  bool fst = 1;
  str res = "{";
  for (const auto &x : v)
  {
    if (!fst)
      res += ", ";
    fst = 0;
    res += ts(x);
  }
  res += "}";
  return res;
}
template <class A, class B>
str ts(pair<A, B> p)
{
  return "(" + ts(p.f) + ", " + ts(p.s) + ")";
}

// OUTPUT
template <class A>
void pr(A x) { cout << ts(x); }
template <class H, class... T>
void pr(const H &h, const T &... t)
{
  pr(h);
  pr(t...);
}
void ps() { pr("\n"); } // print w/ spaces
template <class H, class... T>
void ps(const H &h, const T &... t)
{
  pr(h);
  if (sizeof...(t))
    pr(" ");
  ps(t...);
}

vector<string> split(string s, char dim)
{
  vector<string> res;
  stringstream ss(s);
  string item;
  while (getline(ss, item, dim))
    res.push_back(item);
  if (s[s.size() - 1] == dim)
    res.push_back("");
  return res;
}

long inv(long a, long m)
{
  long m0 = m, t, q;
  long x0 = 0, x1 = 1;

  if (m == 1)
    return 0;

  // Apply extended Euclid Algorithm
  while (a > 1)
  {
    // q is quotient
    q = a / m;

    t = m;

    // m is remainder now, process same as
    // euclid's algo
    m = a % m, a = t;

    t = x0;

    x0 = x1 - q * x0;

    x1 = t;
  }

  // Make x1 positive
  if (x1 < 0)
    x1 += m0;

  return x1;
}

long long mul_inv(long long a, long long b)
{
  long long b0{b}, t{0}, q{0};
  long long x0{0}, x1{1};

  if (b == 1)
  {
    return 1;
  }

  while (a > 1)
  {
    q = a / b;
    t = b, b = a % b, a = t;
    t = x0, x0 = x1 - q * x0, x1 = t;
  }

  if (x1 < 0)
  {
    x1 += b0;
  }

  return x1;
}

long long chinese_remainder(const std::vector<long long> &n, const std::vector<long long> &a, const long long lenght)
{
  long long p{0}, i{0}, prod{1}, sum{0};

  for (i = 0; i < lenght; i++)
  {
    prod *= n[i];
  }

  for (i = 0; i < lenght; i++)
  {
    p = prod / n[i];
    sum += a[i] * mul_inv(p, n[i]) * p;
  }

  return sum % prod;
}

string trim(const string &str)
{
  size_t first = str.find_first_not_of(' ');
  if (string::npos == first)
  {
    return str;
  }
  size_t last = str.find_last_not_of(' ');
  return str.substr(first, (last - first + 1));
}

vector<int> prefixSum(vector<int> &arr)
{
  vector<int> pre;
  int curr = 0;
  for (int i = 0; i < arr.size(); i++)
  {
    curr += arr[i];
    pre.push_back(curr);
  }
  return pre;
}

void solve()
{
  ps("");
}

int main()
{
  int m, a, b, c;
  re(m, a, b, c);
  vector<pair<int, unordered_set<string>>> pizzas;
  vector<unordered_set<string>> ings;
  F0R(i, m)
  {
    int n;
    re(n);
    vs ing(n);
    re(ing);
    ings.push_back(unordered_set<str>(all(ing)));
    pizzas.push_back({i, unordered_set<str>(all(ing))});
  }

  sort(pizzas.begin(), pizzas.end(), [](pair<int, unordered_set<string>> &a, pair<int, unordered_set<string>> &b) {
    return a.second.size() > b.second.size();
  });
  vector<vi> res;
  F0R(i, c)
  res.push_back({4});
  F0R(i, b)
  res.push_back({3});
  F0R(i, a)
  res.push_back({2});

  vector<unordered_set<string>> state(a + b + c);
  vi poor;

  F0R(i, m)
  {
    auto &p = pizzas[i];
    int toinsert = -1;
    bool done = false;
    F0R(j, res.size())
    {
      auto &r = res[j];
      int si = r[0];
      int cu = r.size();
      if (r.size() == si + 1)
        continue;
      toinsert = j;
      bool ok = true;
      auto &pt = state[j];
      for (auto &ing : p.second)
      {
        if (pt.count(ing))
        {
          ok = false;
          break;
        }
      }
      if (ok)
      {
        for (auto &ing : p.second)
        {
          pt.insert(ing);
        }
        r.push_back(p.first);
        done = true;
        break;
      }
    }
    if (!done)
    {
      if (toinsert != -1 && toinsert < res.size())
      {
        res[toinsert].push_back(p.first);
      }
      else
      {
        poor.pb(p.first);
      }
    }
  }

  vector<vi> finals;
  vector<vi> realRes;
  for (auto &r : res)
  {
    if (r[0] + 1 != r.size())
    {
      finals.pb(r);
      continue;
    }
    realRes.pb(r);
    if (r[0] == 2)
    {
      a -= 1;
    }
    if (r[0] == 3)
    {
      b -= 1;
    }
    if (r[0] == 4)
    {
      c -= 1;
    }
  }

  sort(all(finals), [](vi &a, vi &b) {
    return a.size() > b.size();
  });
  for (auto &r : finals)
  {
    int rs = r.size() - 1;
    if (c > 0 && rs >= 5)
    {
      realRes.push_back({4, r[1], r[2], r[3], r[4]});
      c -= 1;
    }
    else if (b > 0 && rs >= 4)
    {
      realRes.push_back({3, r[1], r[2], r[3]});
      b -= 1;
      FOR(i, 4, r.size())
      poor.pb(r[i]);
    }
    else if (a > 0 && rs >= 3)
    {
      realRes.push_back({2, r[1], r[2]});
      a -= 1;
      FOR(i, 3, r.size())
      poor.pb(r[i]);
    }
    else
    {
      FOR(i, 1, r.size())
      poor.pb(r[i]);
    }
  }
  int i = 0;
  sort(all(poor), [&](int a, int b) {
    return ings[a].size() > ings[b].size();
  });
  while (a > 0 || b > 0 || c > 0)
  {
    if (c > 0 && i + 3 < poor.size())
    {
      realRes.pb({4, poor[i], poor[i + 1], poor[i + 2], poor[i + 3]});
      i += 4;
      c -= 1;
    }
    else if (b > 0 && i + 2 < poor.size())
    {
      realRes.pb({3, poor[i], poor[i + 1], poor[i + 2]});
      i += 3;
      b -= 1;
    }
    else if (a > 0 && i + 1 < poor.size())
    {
      realRes.pb({2, poor[i], poor[i + 1]});
      i += 2;
      a -= 1;
    }
    else
    {
      break;
    }
  }

  long score = 0;
  ps(realRes.size());
  int allP = 0;
  for (auto &r : realRes)
  {
    allP += r.size() - 1;
    for (auto i : r)
    {
      pr(i, " ");
    }
    ps("");

    unordered_set<str> sco;
    int co = 0;
    FOR(i, 1, r.size())
    {
      int p = r[i];
      co += ings[p].size();
      for (auto &ing : ings[p])
      {
        sco.insert(ing);
      }
    }
    score += (long)sco.size() * (long)sco.size();
  }
  // ps(remaining.size(),a, b, c);
  // ps(poor.size(), poor[poor.size() - 1], poor[poor.size() - 2]);
  // ps(m, allP, a, b, c);
  ps(score);
}

// g++ -std=c++11 sol.cpp -o sol.out && ./sol.out < sol.in