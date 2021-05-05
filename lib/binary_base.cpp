#include<bits/stdc++.h>
using namespace std;

#include <atcoder/all>
using namespace atcoder;

#define li          long long int
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
#define MOD 998244353

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

inline bool b(li x, li keta) {
    return ((x >> keta) & 1) > 0;
}

inline li msb(li x) {
    for (li i = 60; i >= 0; i--) {
        if (b(x, i))return i;
    }
    return -1;
}

// binary base.
// verified: https://atcoder.jp/contests/zone2021/tasks/zone2021_f
class BinaryBase {
public:
    BinaryBase() {}

    bool CanMake(li x) {
        li n = sz(original);
        rin{
            if (b(x, msbs[i])) {
                x ^= modified[i];
            }
        }
        return x == 0;
    }

    void add(li x) {
        li n = sz(original);
        original.pb(x);
        rin{
            if (b(x, msbs[i])) {
                x ^= modified[i];
            }
        }
        msbs.pb(msb(x));
        modified.pb(x);
        rin{
            if (b(modified[i], msbs.back())) {
                modified[i] ^= x;
            }
        }
    }

    li rank() {
        return sz(original);
    }

    vector<li> original;
    vector<li> modified;
    vector<li> msbs;
};

int main() {
    li n, m;
    cin >> n >> m;
    vector<bool> ok(n, true);
    rep(i, m) {
        li a;
        cin >> a;
        ok[a] = false;
    }
    li nn = msb(n);
    BinaryBase bb;
    repp(i, 1, n) {
        if (ok[i]) {
            if (!bb.CanMake(i)) {
                bb.add(i);
                if (bb.rank() == nn) {
                    break;
                }
            }
        }
    }

    if (bb.rank() != nn) {
        puts("-1");
        return 0;
    }

    li prev = 0;
    rep(i, n - 1) {
        bitset<60> bs((i + 1) ^ ((i + 1) >> 1));
        li x = 0;
        rep(j, nn) {
            if (bs[j]) {
                x ^= bb.original[j];
            }
        }
        cout << prev << " " << x << endl;
        prev = x;
    }

    return 0;
}