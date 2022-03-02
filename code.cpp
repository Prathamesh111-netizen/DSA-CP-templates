#include<bits/stdc++.h>

using namespace std;

void read(vector<int>&arr, int n){
	for(int i = 0; i < n; i++)
		cin >> arr[i];
}

void write(vector<int>&arr, int n){
	cout << " [ ";
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	cout << "]\n";
}

signed main (int argc, char ** argv){
	#ifndef ONLNE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	freopen("debug.txt", "w", stderr);
	#endif
	
	int t;
	cin >> t;
	
	while(t--){
		int n;
		cin >> n;
		
		vector<int>s1(n), s2(n);
		vector<int>e1(n - 1), e2(n - 1);
		
		read(s1, n);
		read(s2, n);
		read(e1, n -1);
		read(e2, n -1);
		
		// write(s1, n);
		// write(s2, n);
		// write(e1, n -1);
		// write(e2, n -1);
		
		vector<int>answer[2];
		
		answer[0].push_back(s1[0]);
		answer[1].push_back(s2[0]);
		
		vector<int>path[2];
		path[0].push_back(1);
		path[1].push_back(2);
		
		
	for (int i = 1; i < n; i++){
	
	if( answer[0][i-1] + s1[i] < answer[1][i-1] + e2[i-1] + s1[i]){
		cerr << "if1" << endl;
		answer[0].push_back(answer[0][i-1] + s1[i]);
		path[0].push_back(1);
	}
	else{
		cerr << "else1"<< endl;
		answer[0].push_back( answer[1][i-1] + e2[i-1] + s1[i] );
		path[0].push_back(2);
	}
		
	if(answer[1][i-1] + s2[i] < answer[0][i-1] + e1[i-1]+s2[i] ){
		cerr << "if2" << endl;
		answer[1].push_back(answer[1][i-1] + s2[i]);
		path[1].push_back(2);
	}
	else{
		cerr << "else2" << endl;
		answer[1].push_back(answer[0][i-1] + e1[i-1]+s2[i] );
		path[1].push_back(1);
	}
		
	}
	
	write(answer[0], n);
	write(answer[1], n);
	
	write(path[0], n);
	write(path[1], n);
		cout << min(answer[0][n-1], answer[1][n-1]) << endl;
		
	
	}
	return 0;
	
}
