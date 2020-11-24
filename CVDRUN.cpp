#include <iostream>
#include <vector>

using namespace std;

int inVector(vector<int> v, int i)
{
    for(int j = 0; j < v.size(); j++)
    {
        if(i == v[j])
            return 1;
    }
    return 0;
}



int main() {
    int T, N, K, X, Y, theInt;
    vector<int> myInts;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
	    cin >> N >> K >> X >> Y;
	    theInt = (X+K)%N;
	    myInts.push_back(X);
	    while(theInt != X)
	    {
	        myInts.push_back(theInt);
	        theInt = (theInt+K)%N;
	    }
    
	    //if((X+K)%Y != 0) cout << "YES" << endl;
	    //else cout << "NO" << endl;
	
	    if(inVector(myInts, Y)) cout << "YES" << endl;
	    else cout << "NO" << endl;
	    myInts.clear();
	}
	
	return 0;
}
