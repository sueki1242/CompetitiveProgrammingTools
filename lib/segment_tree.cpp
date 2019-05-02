#include<bits/stdc++.h>
using namespace std;


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

// segtree ----------------------------------
// verified: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DSL_2_A

template<typename T>
class Segtree {
public:
    Segtree(li n,
            T default_value,
            T invalid_value_,
            std::function<T(T, T)> func_) : invalid_value(invalid_value_),
        func(func_) {
        nn = 1;
        while (nn < n) {
            nn *= 2;
        }
        data.resize(nn * 2 - 1);
        for (auto && item : data) {
            item = default_value;
        }
    }

    inline void update(li i, T x) {
        i += nn - 1;
        data[i] = x;
        while (i > 0) {
            i = (i - 1) / 2;
            data[i] = func(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }

    inline T query_(li a, li b, li k, li l, li r) {
        if (r <= a || b <= l) return invalid_value;
        if (a <= l && r <= b) return data[k];
        li mid = (l + r) / 2;
        li vl = query_(a, b, k * 2 + 1, l, mid);
        li vr = query_(a, b, k * 2 + 2, mid, r);
        return func(vl, vr);
    }

    inline T query(li a, li b) {
        li l = 0;
        li r = nn;
        li k = 0;
        if (r <= a || b <= l) return invalid_value;
        if (a <= l && r <= b) return data[k];
        li mid = (l + r) / 2;
        li vl = query_(a, b, k * 2 + 1, l, mid);
        li vr = query_(a, b, k * 2 + 2, mid, r);
        return func(vl, vr);
    }

    li nn;
    vector<T> data;
    T invalid_value;
    function<T(T, T)> func;
};
// segtree --------------------------------//

int main() {
    li n, q;
    cin >> n >> q;
    Segtree<li> segtree(n, bit(31) - 1, INF, [](li a, li b) {return min(a, b);});
    rep(i, q) {
        li type, x, y;
        cin >> type >> x >> y;
        if (type == 0) {
            segtree.update(x, y);
        } else {
            cout << segtree.query(x, y + 1) << endl;
        }
    }

    return 0;
}