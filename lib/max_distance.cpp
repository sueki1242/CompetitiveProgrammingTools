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

// cross of (a->b), (a->c)
inline li Cross3(const PI& a, const PI& b, const PI& c) {
    return (b.S - a.S) * (c.F - a.F) - (b.F - a.F) * (c.S - a.S);
}

// calc convex hull by Andrew's monotone chain method.
// verified: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_A
inline vector<PI> ConvexHull(vector<PI> ps) {
    li n = sz(ps);
    sort(allof(ps), [](PI & a, PI & b) {
        if (a.S != b.S) {
            return a.S < b.S;
        }
        return a.F < b.F;
    });

    vector<PI> res;
    rin{
        auto& now = ps[i];
        while (sz(res) > 1 && Cross3(res[sz(res) - 2], res[sz(res) - 1], now) > 0) {
            res.pop_back();
        }
        res.pb(now);
    }
    li t = sz(res);
    for (li i = n - 2; i >= 0; i--) {
        auto& now = ps[i];
        li nn = sz(res);
        while (sz(res) > t && Cross3(res[sz(res) - 2], res[sz(res) - 1], now) > 0) {
            res.pop_back();
        }
        res.pb(now);
    }
    res.pop_back();


    return res;
}

inline li Cross(const PI& a, const PI& b, const PI& c, const PI& d) {
    return (b.S - a.S) * (d.F - c.F) - (b.F - a.F) * (d.S - c.S);
}


// calc diameter of given convex hull.
// verified: https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=CGL_4_B
inline double ConvexDiameter(const vector<PI>& convex) {
    li n = sz(convex);
    if (n < 2)return 0;
    if (n == 2)return hypot(convex[1].F - convex[0].F, convex[1].S - convex[0].S);
    PI mi = {INF, INF};
    li mii = -1;
    li mai = -1;
    PI ma = { -INF, -INF};
    rin {
        if (mi > convex[i]) {
            mi = convex[i];
            mii = i;
        }
        if (ma < convex[i]) {
            ma = convex[i];
            mai = i;
        }
    }
    double res = 0.0;
    li now_ma = mai;
    li now_mi = mii;
    while (now_mi != mai || now_ma != mii) {
        res = max(res, hypot(convex[now_mi].F - convex[now_ma].F, convex[now_mi].S - convex[now_ma].S));
        if (Cross(convex[now_mi], convex[(now_mi + 1) % n], convex[now_ma], convex[(now_ma + 1) % n]) > 0) {
            now_mi = (now_mi + 1) % n;
        } else {
            now_ma = (now_ma + 1) % n;
        }
    }
    return res;
}


int main() {
    vector<PI> ps;
    li n;
    cin >> n;
    rin{
        double a, b;
        cin >> a >> b;
        ps.pb({b * 1000000, a * 1000000});
    }
    auto res = ConvexHull(ps);
    printf("%.12f\n", ConvexDiameter(res) / 1000000);


    return 0;
}