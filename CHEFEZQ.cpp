#include <iostream>
#include <vector>

using namespace std;

int main() {
    long long T, N, K, Q, total, counter;
    vector<long long> myVec;
	cin >> T;
	for(int i = 0; i < T; i++)
	{
	    cin >> N >> K;
	    total = 0;
	    counter = 0;
	    for(int j = 0; j < N; j++)
	    {
	        cin >> Q;
	        myVec.push_back(Q);
	    }
	    for(int j = 0; j < myVec.size(); j++)
	    {
	        total += myVec[j];
	        total -= K;
	        counter += 1;
	        if(total < 0)
	        {
	            //cout << counter << endl;
	            j = myVec.size()-1;
	            //total = -1;
	        }
	    }
	    //cout << total << endl;
	    /*while(total >= 0)
	    {
	        total -= K;
	        counter+=1;
	    }
	    */
	    if(total >= 0)
	    {
	        counter += total/K;
	        //if(total%K == 0)
	        counter += 1;
	    }
	    myVec.clear();
	    cout << counter << endl;
	}
	
	return 0;
}
