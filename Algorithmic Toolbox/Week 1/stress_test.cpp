/*Stress testing generally a program that generates random test is an infinite loop, and for each test ,it launches two alternative solution on the same test and compares the result.*/
#include<iostream>
#include<cstdlib>
#include<vector>

using  namespace std;
// naive alogrithm for max pairwise product//
long long MaxProduct(const vector<int>&num){
  long long result=0;
  int n=num.size();
  for (int i = 0; i < n; ++i)
    for (int j = i+1; j< n; ++j)
      if (((long long)(num[i])*num[j])>result&&num[i]!=num[j])  
        result=((long long)(num[i])*num[j]);
  return result;
}
//fast algorithm for max pairwise product//
long long MaxProductFast(const vector<int>&num){
  int n=num.size();
  int max_i=-1;
  for (int i = 0; i < n; ++i)
    if ((max_i==-1)||(num[i]>num[max_i]))
      max_i=i;
  int max_j=-1;
  for (int j = 0; j < n; ++j)
    if (((j!=max_i)&&(num[j]!=num[max_i]))&&((max_j==-1)||(num[j]>num[max_j])))
      max_j=j;
    if(max_j==-1)
       return (long long)num[max_i]*0;
  cout<<max_i<<" "<<max_j<<endl;
  return (long long)num[max_i]*num[max_j];
}

int main(void){
  while (true)
  {
    int n=rand()%4+2;
    cout<<n<<endl;
    vector<int> a;
    for (int i = 0; i < n; ++i)
      a.push_back(rand()%10);
    for (int i = 0; i < n; ++i)
      cout<<a[i]<<" ";
    cout<<"\n";
    long long res1=MaxProduct(a);
    long long res2=MaxProductFast(a);
    if (res1!=res2)
    {
      cout<<"Wrong Answer X?:"<<res1<<" "<<res2<<endl;
      break;
    }
    else
      cout<<"Right!"<<endl;
  }
  int n;
  cin>>n;
  vector<int> num(n);
  for (int i = 0; i < n; ++i)
  {
    cin>>num[i];
  }
  long long result=MaxProductFast(num);
  cout<<result<<endl;
  return 0;
}