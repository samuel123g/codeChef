#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

vector<long long> vSwap(vector<long long> vec, long long index1, long long index2);
void printVec(vector<long long> vec, long long N);

int main() {
    long long T, N;
    double temp;
    vector<long long> myVec;
	
	for(long long j = 1; j < pow(10,5)+1; j++)
        myVec.push_back(j);
        
	temp = log2(pow(10,5)+1);
    for(long long j = 0; j < temp; j++)
        myVec = vSwap(myVec, pow(2,j), pow(2,j)-1);
	    
	cin >> T;
	for(int i = 0; i < T; i++)
	{
	    cin >> N;
	    temp = log2(N);
	    double temp2;
	    if(N==1) cout << 1 << endl;
	    else if(N<3 || modf(temp, &temp2) == 0)
	    {
	        cout << -1 << endl;
	        continue;
	    }
	    else printVec(myVec, N);
	}
	return 0;
}

vector<long long> vSwap(vector<long long> vec, long long index1, long long index2)
{
    //cout << "index1: " << index1 << " index2: " << index2 << endl;
    long long temp = vec[index1];
    vec[index1] = vec[index2];
    vec[index2] = temp;
    return vec;
}

void printVec(vector<long long> vec, long long N)
{
    for(int i = 0; i < N-1; i++)
    {
        cout << vec[i] << ' ';
    }
    cout << vec[N-1] << endl;
}
