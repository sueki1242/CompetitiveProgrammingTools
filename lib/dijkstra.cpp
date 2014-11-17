#include <bits/stdc++.h>
#define _USE_MATH_DEFINES
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

#define GRAPH_V 101010

typedef pair<li, li> PI;
typedef pair<li, PI> PII;

vector<PI> edge[GRAPH_V];
bool visit[GRAPH_V];


li dijkstra(li from, li to){
	rep(i,GRAPH_V)visit[i]=false;
	priority_queue<PI> q;
	q.push({0, from});
	while(!q.empty()){
		PI now=q.top();
		li now_v=now.S;
		li now_c=now.F;
		if(now_v==to)return -now_c;
		q.pop();
		if(visit[now_v])continue;
		visit[now_v]=true;
		rep(i,sz(edge[now_v])){
			li next=edge[now_v][i].F;
			li w=edge[now_v][i].S;
			if(!visit[next])q.push({now_c-w, next});
		}
	}
	return -1;
}

int main(int argc, char *argv[]){
	li n;
	cin>>n;
	li m;
	cin>>m;

	rep(i,m){
		li x,y,c;
		cin>>x>>y>>c;
		edge[x-1].pb({y-1, c});
		edge[y-1].pb({x-1, c});
	}
	cout<<dijkstra(0, n-1)<<endl;


	return 0;
}