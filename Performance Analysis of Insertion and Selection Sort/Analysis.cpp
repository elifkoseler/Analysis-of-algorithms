#include<iostream>
#include<fstream> //for fstream and ofstream
#include<cstdlib> //for c_str() function
#include<time.h>  //for clock() function


using namespace std;

struct node{  
  string timestamp;
  string instrument_token;
  string last_price;
  string volume;
  string sell_quantity;
  string last_quantity;
  string change;
  string average_price;
  string open,high,low,close;
  string depth_buy_price_0,depth_buy_orders_0,depth_buy_quantity_0,
    depth_sell_price_0,depth_sell_orders_0,depth_sell_quantity_0;

  string depth_buy_price_1,depth_buy_orders_1,depth_buy_quantity_1,
    depth_sell_price_1,depth_sell_orders_1,depth_sell_quantity_1;

  string depth_buy_price_2,depth_buy_orders_2,depth_buy_quantity_2,
    depth_sell_price_2,depth_sell_orders_2,depth_sell_quantity_2;

  string depth_buy_price_3,depth_buy_orders_3,depth_buy_quantity_3,
    depth_sell_price_3,depth_sell_orders_3,depth_sell_quantity_3;

  string depth_buy_price_4,depth_buy_orders_4,depth_buy_quantity_4,
    depth_sell_price_4,depth_sell_orders_4,depth_sell_quantity_4;

};
template<class T> // I created template insertion function so, 2 data type can use easily
void insertion(T *A,int n) {
  T key;
  int i = 0;

  for(int j=1;j<n;j++){
    key = A[j];
    i = j-1;
    while ((i>=0)&&(A[i]>key)) {
      A[i+1] = A[i];
      i = i-1;

    }
    A[i+1] = key;
  }

}
template<class T>
void print(T *A,int n){
  for(int i=0;i<n;i++){
    cout<<i+1<<")"<<A[i]<<endl;;
  }
}
void merge(float array[], int low, int mid, int high){ //for last_price feature
  int list1, list2, i;
  float *temp = new float[high+1];

  list1 = low;
  list2 = mid + 1;
  i = low;

  while(list1 <= mid && list2 <= high){
     if(array[list1] <= array[list2])
        temp[i] = array[list1++];
     else
        temp[i] = array[list2++];
  i++;
}

  while(list1 <= mid)
    temp[i++] = array[list1++];

  while(list2 <= high)
      temp[i++] = array[list2++];

  for(i = low; i <= high; i++){
    array[i] = temp[i];
  }

}

void mergeSort(float array[],int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high)/2;
      mergeSort(array,low,mid);
      mergeSort(array,mid+1,high);
      merge(array,low, mid,high);
   }
   else {
      return;
   }
}
void merge(string array[], int low, int mid, int high){ //for timestamp feature
  int list1, list2, i;
  string *temp;

  list1 = low;
  list2 = mid + 1;
  i = low;

  while(list1 <= mid && list2 <= high){
     if(array[list1] <= array[list2])
        temp[i] = array[list1++];
     else
        temp[i] = array[list2++];
  i++;
}

  while(list1 <= mid)
    temp[i++] = array[list1++];

  while(list2 <= high)
      temp[i++] = array[list2++];

  for(i = low; i <= high; i++){
    array[i] = temp[i];
  }
}
void mergeSort(string array[],int low, int high) {
   int mid;

   if(low < high) {
      mid = (low + high)/2;
      mergeSort(array,low,mid);
      mergeSort(array,mid+1,high);
      merge(array,low, mid,high);
   }
   else {
      return;
   }
}


int main(int argc,char *argv[]){
    float start_t;
    start_t = clock();

    char algo_type;
    char feature;
    int N;

    algo_type = *argv[2];
    feature = *argv[4];
    N = atoi(argv[6]);

    ifstream inFile("log_inf.csv",ios::in);
    ofstream outFile("sorted.csv");

    if(!inFile.is_open())
      cout<<"ERROR: File could not open!"<<endl;

    int i=0;

    node *one = new node[N];  //node array for storage data
    while (i<N) {
      getline(inFile,one[i].timestamp,',');
      getline(inFile,one[i].instrument_token,',');
      getline(inFile,one[i].last_price,',');
      getline(inFile,one[i].volume,',');
      getline(inFile,one[i].sell_quantity,',');
      getline(inFile,one[i].last_quantity,',');
      getline(inFile,one[i].change,',');
      getline(inFile,one[i].average_price,',');
      getline(inFile,one[i].open,',');
      getline(inFile,one[i].high,',');
      getline(inFile,one[i].low,',');
      getline(inFile,one[i].close,',');

      getline(inFile,one[i].depth_buy_price_0,',');
      getline(inFile,one[i].depth_buy_orders_0,',');
      getline(inFile,one[i].depth_buy_quantity_0,',');
      getline(inFile,one[i].depth_sell_price_0,',');
      getline(inFile,one[i].depth_sell_orders_0,',');
      getline(inFile,one[i].depth_sell_quantity_0,',');

      getline(inFile,one[i].depth_buy_price_1,',');
      getline(inFile,one[i].depth_buy_orders_1,',');
      getline(inFile,one[i].depth_buy_quantity_1,',');
      getline(inFile,one[i].depth_sell_price_1,',');
      getline(inFile,one[i].depth_sell_orders_1,',');
      getline(inFile,one[i].depth_sell_quantity_1,',');

      getline(inFile,one[i].depth_buy_price_2,',');
      getline(inFile,one[i].depth_buy_orders_2,',');
      getline(inFile,one[i].depth_buy_quantity_2,',');
      getline(inFile,one[i].depth_sell_price_2,',');
      getline(inFile,one[i].depth_sell_orders_2,',');
      getline(inFile,one[i].depth_sell_quantity_2,',');

      getline(inFile,one[i].depth_buy_price_3,',');
      getline(inFile,one[i].depth_buy_orders_3,',');
      getline(inFile,one[i].depth_buy_quantity_3,',');
      getline(inFile,one[i].depth_sell_price_3,',');
      getline(inFile,one[i].depth_sell_orders_3,',');
      getline(inFile,one[i].depth_sell_quantity_3,',');

      getline(inFile,one[i].depth_buy_price_4,',');
      getline(inFile,one[i].depth_buy_orders_4,',');
      getline(inFile,one[i].depth_buy_quantity_4,',');
      getline(inFile,one[i].depth_sell_price_4,',');
      getline(inFile,one[i].depth_sell_orders_4,',');
      getline(inFile,one[i].depth_sell_quantity_4);


i++;
    }
    string tempt[N];  //template array to hold data for timestamp
    for(int j=0;j<N;j++){
        tempt[j] = one[j].timestamp;
    }

    float tempp[N]; //template array to hold data for last_price
    for(int m=0;m<N;m++){
        string temp = one[m].last_price;
        float a = atof(temp.c_str());
        tempp[m]=a;
    }


    if (feature =='t'||feature =='T') {//timestamp--------------------
      if(algo_type=='m'){
        mergeSort(tempt,0,N);
        for(int i=0;i<N;i++){
          outFile<<tempt[i]<<endl;
      }
    }
      if(algo_type=='i'){//insertion---

      insertion(tempt,N);

      for(int i=0;i<N;i++){
        outFile<<tempt[i]<<endl;
    }
  }
}
    if(feature =='p'||feature =='P'){ //last_price-------------------------
      if(algo_type=='m'){
        mergeSort(tempp,0,N);

        for(int i=0;i<N;i++){
          outFile<<tempp[i]<<endl;
    //    print(tempp,N);
      }
    }

      if(algo_type=='i'){
        insertion(tempp,N);

        for(int i=0;i<N;i++){
          outFile<<tempp[i]<<endl;
    }

    }

  }
    float end_t = clock();
    float total_t = (end_t - start_t) /CLOCKS_PER_SEC;
    cout<<"TIME: "<<total_t<<endl;
  }
