#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

void swap(int* l, int* r ) {
   int temp = *l;
   *l = *r;
   *r = temp;
}

//choosing the last ele as pivot
/*int partition(vector<int> &v, int l, int r ) {
    int pivot = v[r];
    //cout << "pivot " << pivot << endl;
    int i = l;
    for(int j = l; j < r ; j++) {
       if(v[j] < pivot) {
         swap(&v[i],&v[j]);
         i++;
       }
    }
    swap(&v[r],&v[i]);
    for(int x = 0 ; x < v.size(); x++){
      cout << v[x] << ">";
    }
    cout << "\n" << endl;
    return i;
}*/
//choosing the first ele as pivot
int partition(vector<int> &v, int l, int r ) {
    int pivot = v[l];
    cout << "pivot " << pivot << endl;
    int i = l+1;
    for(int j = l+1; j <= r ; j++) {
       if(v[j] < pivot) {
         swap(&v[i],&v[j]);
         i++;
       }
    }
    swap(&v[l],&v[i-1]);
    /*for(int x = 0 ; x < v.size(); x++){
      cout << v[x] << ">";
    }*/
    return i-1;
}

unsigned int quickSort(vector<int> &v, int l, int r) {
    //parition return index of partitin
    int c = 0;
    int c1 = 0;
    int c2 = 0;
    int median = 0;
    if(l < r) {
      //implementing to calculate median pivot
      int m = (l+r)/2;
      if(v[l] <= v[m]) {
          if(v[m] < v[r]) 
             median = m;
          else if(v[r] <  v[m] && v[r] > v[l]) 
             median = r;
          else
             median = l;
      } else if(v[m] < v[l]) {
          if(v[l] < v[r]) 
             median = l;
          else if(v[r] <  v[l] && v[m] < v[r]) 
             median = r;
          else 
             median = m;
      }

  //    cout << "value of l r m median " << l << " " << r << " " << m << " " << median <<  endl;
    //  cout << "value of v[l] v[r] v[m] v[median] " << v[l] << " " << v[r] << " " << v[m] << " " << v[median] <<  endl;
      //enable below swap command only for choosing last element
      //swap(&v[l],&v[r]);
      swap(&v[l],&v[median]);
      int pIndex = partition(v,l,r);
      //cout << "pIndex " << pIndex << endl;
      c = r-l;
      //cout << "c :" << c << endl;
      c1 = quickSort(v,l,pIndex-1);
      //cout << "c1 :" << c1 << endl;
      c2 = quickSort(v,pIndex+1,r);
      //cout << "c2 :" << c2 << endl;
    }
   // cout << "quicksort count " << c+c1+c2 << endl;
    return c+c1+c2;
}
 
int main() {
   vector<int> v;
  //int arr[] = {3,2,1,4,5};
  //  int arr[] = {4,1,2,5,3};
  // int arr[] = {1,6,8,10,7,5,2,9,4,3};
   //int arr[] = {11,18,5,20,8,10,3,2,17,4,13,7,12,9,6,16,19,15,1,14};

  //vector<int> v (arr, arr + sizeof(arr)/sizeof(arr[0]));
  unsigned int count = 0;
  int i = 0;
  //read the file and push to a vector
  ifstream f;
  f.open("QuickSort.txt",ios::in);

  while(f >> i){
    v.push_back(i);
  }
  cout << v.size() << endl;
  /*for(int x = 0 ; x < v.size(); x++){
      cout << v[x] << ">";
    }*/
  count = quickSort(v,0,v.size()-1);
  cout << "count" << count<< endl;
  /*for(int j = 0 ; j< v.size(); j++){
    cout << v[j] << endl;
  }*/
  return 0;
}
