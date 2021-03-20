#include<iostream>
#include<vector>

using namespace std;
long long MaxPairWiseProduct(const vector <int> &num){
 long long result=0;
  int n=num.size();
  for (int i = 0; i < n; i++)
  {
    for (int j = i+1; j < n; j++)
    {
      if (((long long)(num[i])*num[j])>result)
      {
        result=(long long)(num[i])*num[j];
      }
      
    }
    
  }
  return result;
}

int main(void){
  int n;
  cin>>n;
  vector<int> num(n);
  for (int i = 0; i < n; i++)
  {
    cin>>num[i];
  }
  long long result=MaxPairWiseProduct(num);
  cout<<result<<endl;
  
  return 0;
}