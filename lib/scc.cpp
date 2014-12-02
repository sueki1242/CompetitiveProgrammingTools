#include <bits/stdc++.h>
using namespace std;

#define li			long long int
#define rep(i,to)	for(li i=0;i<((li)(to));i++)
#define repp(i,start,to)	for(li i=(li)(start);i<((li)(to));i++)
#define pb			push_back
#define sz(v)		((li)(v).size())
#define bgn(v)		((v).begin())
#define eend(v)		((v).end())
#define allof(v)	(v).begin(), (v).end()
#define dodp(v,n)		memset(v,(li)n,sizeof(v))
#define bit(n)		(1ll<<(li)(n))
#define mp(a,b)		make_pair(a,b)
#define rin	rep(i,n)
#define rjm	rep(j,m)


#define DBGP 1


#define idp if(DBGP)
#define F first
#define S second
#define p2(a,b)		idp cout<<a<<"\t"<<b<<endl
#define p3(a,b,c)		idp cout<<a<<"\t"<<b<<"\t"<<c<<endl
#define p4(a,b,c,d)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<endl
#define p5(a,b,c,d,e)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<endl
#define p6(a,b,c,d,e,f)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<endl
#define p7(a,b,c,d,e,f,g)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<endl
#define p8(a,b,c,d,e,f,g,h)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<endl
#define p9(a,b,c,d,e,f,g,h,i)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<endl
#define p10(a,b,c,d,e,f,g,h,i,j)		idp cout<<a<<"\t"<<b<<"\t"<<c<<"\t"<<d<<"\t"<<e<<"\t"<<f<<"\t"<<g<<"\t"<<h<<"\t"<<i<<"\t"<<j<<endl
#define foreach(it,v)	for(__typeof((v).begin()) it=(v).begin(); it!=(v).end(); ++it)
#define p2p(x)		idp p2((x).F, (x).S)
#define dump(x,n)	idp{rep(i,n){cout<<x[i]<<" ";}puts("");}
#define dump2(x,n)	idp{rep(i,n){cout<<"["<<x[i].F<<" , "<<x[i].S<<"] ";}puts("");}
#define dumpi(x)	idp{foreach(it, x){cout<<(*it)<<" ";}puts("");}
#define dumpi2(x)	idp{foreach(it, x){cout<<"["<<(it)->F<<" , "<<(it)->S<<"] ";}puts("");}

#define read2d(a,w,h)	rep(i,h)rep(j,w)cin>>a[i][j]
#define dump2d(a,w,h)	rep(i,h){rep(j,w)cout<<a[i][j]<<" ";puts("");}


#define EPS 1e-10
#define ETOL 1e-8
#define MOD 100000009

li n;
vector<li> edge[110];
stack<li> s;
li num[110], low[110];
bool in_s[110];

void visit(li v, vector< vector<li> >& scc, li& t) {
	low[v] = num[v] = t;
	t++;
	s.push(v);
	in_s[v] = true;
	rep(i, sz(edge[v])) {
		li w = edge[v][i];
		if(num[w] == 0) {
			visit(w, scc, t);
			low[v] = min(low[v], low[w]);
		}
		else if(in_s[w]){
			low[v] = min(low[v], num[w]);
		}
	}
	if (low[v] == num[v]) {
		scc.push_back(vector<li>());
		while (1) {
			int w = s.top(); s.pop();
			in_s[w] = false;
			scc.back().pb(w);
			if(v == w)break;
		}
	}
}

void stronglyConnectedComponents(vector< vector<li> >& scc) {
	li time = 0;
	rep(i,n)num[i]=0;
	rep(i, n)if(num[i] == 0)visit(i, scc, time);
}

int main(){
	n=6;
	edge[0].pb(1);
	edge[1].pb(2);
	edge[2].pb(3);
	edge[3].pb(4);
	edge[3].pb(5);
	edge[4].pb(1);
	vector<vector<li> > scc;
	stronglyConnectedComponents(scc);

	rep(i,sz(scc)){
		rep(j,sz(scc[i]))cout<<scc[i][j]<<" ";puts("");
	}

	return 0;
}