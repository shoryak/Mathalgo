#include <iostream>
#include<bits/stdc++.h>
#include<functional>
using namespace std;
typedef vector< int > vi;
typedef vector< vi > vvi;
typedef vector< long long > vll;
typedef pair< int,int > ii;
typedef long long ll;
#define sz(a) int((a).size())
#define pb push_back
#define mp  make_pair
#define pll pair <ll,ll>
#define mod 1000000007
#define mod2 998244353
#define all(c) c.begin(),c.end()
#define tr(c,i) for(typeof(c).begin() i = c.begin(); i != c.end(); i++)
#define present(c,x) (c.find(x) != c.end())
#define cpresent(c,x) (find(all(c),x) != c.end())
#define rep(i, a, b) for (int i = (a); i <= int(b); i++)
#define repn(i,a,b)   for(int i=a;i>=b;i--)
#define fo(i,n) for(ll i=1;i<=n;i++)
#define fo0(i,n) for(ll i=0;i<n;i++)
#define YES cout<<"YES\n"
#define NO cout<<"NO\n"
#define Yes cout<<"Yes\n"
#define No cout<<"No\n"
#define nl "\n"
#define F first
#define S second 
#define eps 0.0000001
/*
Mathematical Fact:
(n/1)+(n/2)+(n/3)+....(n/n) = O(nlogn)
/*
This code deals with prime factorisation of any number in O(logn)
*/
const int N=100023;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout); 
    #endif

    int primefactor[N+1]; 
    // primefactor[i] stores the largest prime number which divides i
    // For eg primefactor[3]=3, primefactor[15]=5
    for(int i=1;i<=N;i++){
        primefactor[i]=i;
    }
    for(int i=2;i<=N;i++){
        if(primefactor[i]!=i)  // i.e. i is not prime
            continue;
        for(int j=i;j<=N;j+=i)
            primefactor[j]=i;  // Since i is prime and divides j
    }
    /*
        This is the precomputation part
        Complexity of above part is:
        (N/2)+(N/3)+(N/5)+(N/7)+.... which is less than (N/1)+(N/2)+...(N/N)=O(NlogN)
    */
    // Now for any number x<N we can prime factorise it in O(logn) time
    int x=100;
    // Lets count no. of factors of x
    for(int i=1;i<20;i++){
        cout<<primefactor[i]<<" ";
    }
            cout<<endl;
    int factors=1;
    while(x!=1){
        int p=primefactor[x];  // p is prime and divides x
        int cnt=0;   // It will store the maximum power of p dividing x
        while((x%p)==0){
            x/=p;
            cnt++;
        }
        factors*=(cnt+1);
    }
    cout<<factors<<'\n';

    // task print all factors of all numbers from  1..N
    vector<int> ans[N+1];
    for(int i=2;i<=N;i++){
        for(int j=i;j<=N;j+=i){
            ans[j].push_back(i);  // i divides j hence it is a factor of j
        }
    }
    // now printing the ans for all numbers from 1,,N
    for(int i=1;i<=N;i++){
        cout<<1<<" "; // 1 is a factor of all 
        for(auto j : ans[i]){
            cout<<j<<" ";
        }
        cout<<nl;
    }
}