#include<bits/stdc++.h>
using namespace std;


#define li          long long int
#define uli         unsigned long long int
#define rep(i,to)   for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)    for(li i=(li)(start);i<((li)(to));i++)
#define pb          push_back
#define sz(v)       ((li)(v).size())
#define bgn(v)      ((v).begin())
#define eend(v)     ((v).end())
#define allof(v)    (v).begin(), (v).end()
#define dodp(v,n)       memset(v,(li)n,sizeof(v))
#define bit(n)      (1ll<<(li)(n))
#define mp(a,b)     make_pair(a,b)
#define rin rep(i,n)
#define EPS 1e-12
#define ETOL 1e-8
#define MOD 1000000007
typedef pair<li, li> PI;

#define INF bit(60)

#define DBGP 1


#define idp if(DBGP)
#define F first
#define S second
#define p2(a,b)     idp cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)       idp cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define p4(a,b,c,d)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl
#define p5(a,b,c,d,e)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl
#define p6(a,b,c,d,e,f)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<endl
#define p7(a,b,c,d,e,f,g)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<endl
#define p8(a,b,c,d,e,f,g,h)     idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<endl
#define p9(a,b,c,d,e,f,g,h,i)       idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<endl
#define p10(a,b,c,d,e,f,g,h,i,j)        idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<"\t"<<j<<endl
#define foreach(it,v)   for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define p2p(x)      idp p2((x).F, (x).S)
#define dump(x,n)   idp{rep(i,n){cout<<x[i]<<" ";}puts("");}
#define dump2(x,n)  idp{rep(i,n){cout<<"["<<x[i].F<<" , "<<x[i].S<<"] ";}puts("");}
#define dumpi(x)    idp{foreach(it, x){cout<<(*it)<<" ";}puts("");}
#define dumpi2(x)   idp{foreach(it, x){cout<<"["<<(it)->F<<" , "<<(it)->S<<"] ";}puts("");}

#define read2d(a,w,h)   rep(i,h)rep(j,w)cin>>a[i][j]
#define dump2d(a,w,h)   rep(i,h){rep(j,w)cout<<a[i][j]<<" ";puts("");}

typedef pair<li, li> PI;

// rolling hash ---------------------------------------------
// verified: https://atcoder.jp/contests/agc047/tasks/agc047_b
class RollingHash {
public:
	RollingHash(const string& str) :
		hash_(sz(str) + 1, 0) {
		hash_[0] = 1;
		rep(i, sz(str)) {
			hash_[i + 1] = CalcMod(Mul(hash_[i], base) + (str[i] - 'a' + 1));
		}
		if (pow_memo.empty()) {
			pow_memo.resize(max_len + 1);
			pow_memo[0] = 1;
			repp(i, 1, sz(pow_memo)) {
				pow_memo[i] = CalcMod(Mul(pow_memo[i - 1], base));
			}
		}
	}

	uli Slice(li begin, li len) {
		return CalcMod(hash_[begin + len] + positiviser - Mul(hash_[begin], pow_memo[len]));
	}
private:
	static vector<uli> pow_memo;
	vector<uli> hash_;

	const uli base = 1000000007; //<! @todo fix to random value
	const uli mask30 = bit(30) - 1;
	const uli mask31 = bit(31) - 1;
	const uli RHMOD = bit(61) - 1;
	const uli mask61 = RHMOD;
	const uli positiviser = RHMOD * ((1UL << 3) - 1);
	const uli RHBASE = 29;
	const uli max_len = 1001000;

	inline uli CalcMod(uli x) {
		uli xu = x >> 61;
		uli xd = x & mask61;
		uli res = xu + xd;
		if (res >= RHMOD) res -= RHMOD;
		return res;
	}

	// returns a*b%RHMOD
	inline uli Mul(uli a, uli b) {
		uli au = a >> 31;
		uli ad = a & mask31;
		uli bu = b >> 31;
		uli bd = b & mask31;

		uli mid = ad * bu + au * bd;
		uli midu = mid >> 30;
		uli midd = mid & mask30;

		return CalcMod(au * bu * 2 + midu + (midd << 31) + ad * bd);
	}
};

vector<uli> RollingHash::pow_memo;
// rolling hash ---------------------------------------------

string s[200200];
li n;

unordered_map<uli, li> cnt[26];

int main() {
	cin >> n;
	rin{
		cin >> s[i];
	}
	sort(s, s + n, [](const string & a, const string & b) {
		if (sz(a) != sz(b)) {
			return sz(a) < sz(b);
		}
		return a < b;
	});

	li res = 0;
	rin{
		set<li> st;
		RollingHash rh(s[i]);
		rep(j, sz(s[i])) {
			st.insert(s[i][j] - 'a');
			uli h = rh.Slice(j + 1, sz(s[i]) - j - 1);
			for (auto v : st) {
				if (cnt[v].count(h) > 0) {
					res += cnt[v][h];
				}
			}
		}
		cnt[s[i][0] - 'a'][rh.Slice(1, sz(s[i]) - 1)]++;
	}
	cout << res << endl;

	return 0;
}
