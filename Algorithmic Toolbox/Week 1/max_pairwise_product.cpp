#include<iostream>
#include<vector>

using namespace std;
long long MaxPairWiseProduct(const vector <int> &num){
 long long result=0;
  int n=num.size();
  int max_i=-1;
  for (int i = 0; i < n; ++i)
    if ((max_i==-1)||(num[i]>num[max_i]))
      max_i=i;
  int max_j=-1;
  for (int j = 0; j < n; ++j)
    if ((j!=max_i)&&((max_j==-1)||(num[j]>num[max_j])))
      max_j=j;
  
  return (long long)(num[max_i])*num[max_j];
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