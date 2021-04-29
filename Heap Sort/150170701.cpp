#include<iostream>
#include<fstream> //for ifstream
#include<cstdlib> //for atoi
using namespace std;

struct node{  //for read data in string form
  string empID;
  string num_call;
  string pos_fb;
  string neg_fb;
};
struct nodeint{ //for store data in integer form

  int empIDi;
  int num_calli;
  int pos_fbi;
  int neg_fbi;
  int PS;

}heap[800]; //created array which includes 800 element because of average

void max_heapify(int array[], int i, int n){  //sorts smallest to largest order
	int j, temp;
	temp = array[i];
	j = 2*i;

 	while (j <= n){
		if (j < n && array[j+1] > array[j])
		j = j+1;

		if (temp > array[j])
			break;

		else if (temp <= array[j]){
			array[j/2] = array[j];
			j = 2*j;
		}
	}
	array[j/2] = temp;

}
void heapsort(int array[], int n){  //
	int i, temp;
	for (i=n; i>=2;i--){
		temp = array[i];
		array[i] = array[1];
		array[1] = temp;

		max_heapify(array, 1, i - 1); //calls heapify
	}
}

void show_best(int *array){ //for restriction to the show

  cout<<array[0]<<" ";

}
void find_best(int key){  //finds the employeeID of the bests
    int array[3];
    for(int i=0;i<800;i++){
        if(heap[i].PS == key){
          for(int j=0;j<3;j++)
          array[j] = heap[i].empIDi;
      }
    }
show_best(array);
}

void show_worst(int *array){  //for restriction to the show

  cout<<array[0]<<" ";

}
void find_worst(int key){ //finds the employeeID of the worsts
      int array[3];
        for(int i=0;i<800;i++){
            if(heap[i].PS == key){
              for(int j=0;j<3;j++)
              array[j] = heap[i].empIDi;
          }
        }

show_worst(array);
}
void build_max_heap(int array[],int n){  //makes a new heap largest to smallest order
	int i = n/2;
	for(;i>=1;i--)
		max_heapify(array,i,n);
}

int main(){

  ifstream inFile("day1.csv",ios::in);
  //ifstream inFile("day2.csv",ios::in);
  /*ifstream inFile("day3.csv",ios::in);
  ifstream inFile("day4.csv",ios::in);
  ifstream inFile("day5.csv",ios::in);
  ifstream inFile("day6.csv",ios::in);
  ifstream inFile("day7.csv",ios::in);
  ifstream inFile("day8.csv",ios::in);
  ifstream inFile("day9.csv",ios::in);
  ifstream inFile("day10.csv",ios::in);*/

  if(!inFile.is_open())
        cout<<"ERROR: File could not open!"<<endl;

  node *hold = new node[800];
  int i=0;
  while (i<800) {
    getline(inFile,hold[i].empID,',');
    getline(inFile,hold[i].num_call,',');
    getline(inFile,hold[i].pos_fb,',');
    getline(inFile,hold[i].neg_fb);

    /*cout<<hold[i].empID<<" | "<<hold[i].num_call<<" | "
<<hold[i].pos_fb<<" | "<<hold[i].neg_fb<<endl;
*/
  i++;

  }

  for(int m=0;m<800;m++){
      string temp = hold[m].empID;
      string temp1 = hold[m].num_call;
      string temp2 = hold[m].pos_fb;
      string temp3 = hold[m].neg_fb;

      int a = atoi(temp.c_str()); // converts from string to integer
      int b = atoi(temp1.c_str());
      int c = atoi(temp2.c_str());
      int d = atoi(temp3.c_str());

      heap[m].empIDi = a;
      heap[m].num_calli = b;
      heap[m].pos_fbi = c;
      heap[m].neg_fbi = d;
  }

  int n=800;
  int temparray[800];
  for(int k=0;k<800;k++){
    temparray[k]= heap[k].empIDi;
  }
  build_max_heap(temparray,n);  //for employee IDs
  heapsort(temparray,n);

  int temparray_PS[800];  //temporary arrays
  int temparray_calls[800];
    for (int j = 0; j < 800; j++){
        heap[j].PS = (2 * heap[j].num_calli) + heap[j].pos_fbi - heap[j].neg_fbi;
        temparray_PS[j] = heap[j].PS;

        temparray_calls[j] = heap[j].num_calli;
     }
  build_max_heap(temparray_PS,n); //for both of them
  heapsort(temparray_PS,n);
  cout<<"AFTER DAY-1"<<endl;
  cout<<"BEST PERFORMANCE: ";
  for(int a=799;a>=795;a--){
    find_best(temparray_PS[a]);
    if(temparray_PS[a]!=temparray_PS[--a])
    find_best(temparray_PS[a]);
  }
  cout<<endl;
  cout<<"WORST PERFORMANCE: ";
  for(int b=0;b<=4;b++){
    find_worst(temparray_PS[b]);
    if(temparray_PS[b]!=temparray_PS[++b])
    find_best(temparray_PS[b]);

  }
  build_max_heap(temparray_calls,n);  //for number of calls
  heapsort(temparray_calls,n);

  cout<<endl;
  cout<<"MAXIMUM CALLS: ";
  for(int a=799;a>=795;a--){
    find_best(temparray_calls[a]);
    if(temparray_calls[a]!=temparray_calls[--a])
    find_best(temparray_calls[a]);
  }

  cout<<endl;
  cout<<"MINIMUM CALLS: ";
  for(int b=0;b<=4;b++){
    find_worst(temparray_calls[b]);
    if(temparray_calls[b]!=temparray_calls[++b])
    find_best(temparray_calls[b]);
  }


}
