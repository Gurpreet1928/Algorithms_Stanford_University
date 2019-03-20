#include <cstdlib>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

unsigned int mergeAndCountInv(vector<int> &v,int l,int m,int r){
  vector<int> v1(r+1);
  int count = 0;
  int i = l;
  int j = m+1;
  int k = l;
  while(i <= m && j <= r) {
    if(v[i] <= v[j]) {
      v1[k] = v[i];
      i++;
    }else {
      count = count + (m - i + 1);
      v1[k] = v[j];
      j++;
    }
    k++;
  }
  while(i <= m) {
    v1[k] = v[i];
    i++;
    k++;
  }
  while(j <= r) {
    v1[k] = v[j];
    j++;
    k++;
  }
  for(int x=l; x <= r; x++) {
     v[x] = v1[x];
  }
   
  v1.clear();
  //v1.shrink_to_fit();
  vector<int>().swap(v1); 
  //cout << "Inversions : " << count <<endl;
  return count;  
}

unsigned int mergeSort(vector<int> &v, int l, int r){
  int x =0;
  int y =0;
  int z = 0;
  if ( v.size() < 2){
     cout << "size less than 2" << endl;
     return 0;
  }
  if (l < r) {
    int m  = l + (r-l)/2;
    
    x = mergeSort(v,l,m);
    y = mergeSort(v,m+1,r);
    z = mergeAndCountInv(v,l,m,r);
  }
  return x+y+z;
}

int main(){
  vector<int> v;
  //int arr[] = {1,3,5,2,4,6};
  //vector<int> v (arr, arr + sizeof(arr) / sizeof(arr[0]) );
  unsigned int count = 0;
  int i ;
  //open and read file inputs into vector
  ifstream f;
  f.open("IntegerArray.txt",ios::in);

  while(f >> i) {
     v.push_back(i);
  }
   
  cout << v.size() << endl;
  
  count = mergeSort(v,0,v.size()-1);
  cout << "Final count" <<endl;
  cout << count << endl;
  for (int j =0; j < v.size() ; j++ ) {
     cout << v[j] << endl;
  }
  v.clear();
  //v1.shrink_to_fit();
  vector<int>().swap(v);  
  return 0;
}  
