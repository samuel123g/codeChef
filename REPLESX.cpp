#include <iostream>
#include <vector>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;
void printVec(vector<long long> vec, long long N);
long long getPos(vector<long long> vec, long long N);
long long getRevPos(vector<long long> vec, long long N);

int main() {
    long long T, N, X, p, k, i, j, A, G, L;
    vector<long long> myVec;
	cin >> T;
	for(i = 0; i < T; i++)
	{
	    cin >> N >> X >> p >> k;
	    //cout << N << ' ' << X << ' ' << p << ' ' << k << endl;
	    for(j = 0; j < N; j++)
	    {
	        cin >> A;
	        myVec.push_back(A);
	    }
	    sort(myVec.begin(), myVec.end());
	    //printVec(myVec, myVec.size());
	    // G and L are backwards, sort of like electrons and protons
		G = getPos(myVec, X);
		//cout << "G: " << G << endl;
		L = getRevPos(myVec, X);
		//cout << "L: " << L << endl;
		
		if(p!=k && ( (p<k && myVec[p-1] < X) || (p>k && myVec[p-1] > X) ))
			cout << -1 << endl;
		else if(myVec[p-1] == X)
			cout << 0 << endl;
		else if(p < k)
			cout << p-G << endl;
		else if(p > k)
			cout << N-p+1-L << endl;
		else if(p == k)
		{
			if(myVec[p-1] < X)
				cout << N-p+1-L << endl;
			if(myVec[p-1] > X)
				cout << p-G << endl;
		}   
	    myVec.clear();
	}
	return 0;
}

void printVec(vector<long long> vec, long long N)
{
    for(int i = 0; i < N-1; i++)
    {
        cout << vec[i] << ' ';
    }
    cout << vec[N-1] << endl;
}

// get how many nums are >= N
long long getPos(vector<long long> vec, long long N)
{
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[i] > N)
			return i;	
	}
	return vec.size();
}

long long getRevPos(vector<long long> vec, long long N)
{
	for(int i = 0; i < vec.size(); i++)
	{
		if(vec[vec.size()-i-1] < N)
			return i;	
	}
	return 0;
}
