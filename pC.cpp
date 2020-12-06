#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_cxx;
using namespace __gnu_pbds;

#define FAST ios::sync_with_stdio(false);cin.tie(0);
#define Fr(i,s,e) for(auto i = s ; i < e ; i++)
#define endl '\n'
#define Ft first
#define Sd second
#define All(v) v.begin(),v.end()
#define _ <<' '<<

typedef long long ll;
typedef pair<int, int> pii;

const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

constexpr ll MUL = 454'165;
constexpr ll MOD = 100'100'107;

int T, N, M;
bool ans;
gp_hash_table<ll, int> table;
vector< vector<int> > mp;

bool valid(int x, int y){
	return x >= 0 and y >= 0 and x < M and y < N; 
}
bool dfs(int x, int y, ll hash){
	if(x + 1 == M and y + 1 == N){
		auto it = table.find(hash);
		if(it != table.end()){
			ans = true;
			return true;
		} else {
			table.insert({hash, 1});
		}
	} else {
		Fr(i,0,2){
			int nx = x + dx[i], ny = y + dy[i];
			if(valid(nx, ny)){
				ll newhash = (hash * MUL % MOD + mp[ny][nx]) % MOD;
				dfs(nx, ny, newhash);
			}
		}
	}
	return false;
}

int main(){
	FAST;
	cin >> T;
	while(T--){
		cin >> N >> M;
		table.clear(); mp.clear(); mp.resize(N);
		Fr(i,0,N){
			Fr(j,0,M){
				int tmp; cin >> tmp;
				mp[i].push_back(tmp);
			}
		}
		ans = false;
		dfs(0, 0, 1);
		cout << (ans ? "Yes" : "No") << endl;
	}
}