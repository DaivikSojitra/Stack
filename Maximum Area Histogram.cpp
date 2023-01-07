#include <bits/stdc++.h>
using namespace std;

class Solution{

  public:
  long long getMaxArea(long long arr[], int n)
      {
          vector<long long> left;
          vector<long long> right;
          vector<long long> width(n), area(n);
          stack<pair<long long, long long>> st;
          long long pindex = -1;
          for(long long i=0;i<n;i++){
              if(st.size()==0){
                  left.push_back(pindex);
              }
              else if(st.size()>0 && st.top().first < arr[i]){
                  left.push_back(st.top().second);
              }
              else if(st.size()>0 && st.top().first >= arr[i]){
                  while(st.size()>0 && st.top().first >= arr[i]){
                       st.pop();
                  }
                  if(st.size() == 0){
                      left.push_back(pindex);
                  }
                  else{
                      left.push_back(st.top().second);
                  }
              }
              st.push({arr[i],i});
          }
          while(st.size() != 0){
              st.pop();
          }
          pindex = n;
          for(long long i=n-1;i>=0;i--){
              if(st.size()==0){
                  right.push_back(pindex);
              }
              else if(st.size()>0 && st.top().first < arr[i]){
                  right.push_back(st.top().second);
              }
              else if(st.size()>0 && st.top().first >= arr[i]){
                  while(st.size()>0 && st.top().first >= arr[i]){
                       st.pop();
                  }
                  if(st.size() == 0){
                      right.push_back(pindex);
                  }
                  else{
                      right.push_back(st.top().second);
                  }
              }
               st.push({arr[i],i});
          }
          reverse(right.begin(),right.end());
          for(long long i=0;i<n;i++){
              width[i] = right[i] - left[i] -1;
          }
          long long max = LLONG_MIN;
          for(long long i=0;i<n;i++){
              area[i] = width[i] * arr[i];
              if(max < area[i]){
                  max = area[i];
              }
          }
          return max;
      }
};

int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
