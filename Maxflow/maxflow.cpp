#include<fstream> //for read and write operations from file
#include<iostream>
//#include<algorithm> //for min function

using namespace std;
int n;  //number of teams

int main(int argc, char *argv[]){
  string inputFile = argv[1];

  ifstream read(inputFile.c_str()); //reads from pointed file
  ofstream write("output.txt"); //to write results

  read>>n;
  //cout<<n;

  int *score_table = new int[n];
  int remaining_matches[n][n]; //dinamik yapılamadı const sıkıntısından

  for(int i = 0; i<n; i++){
    read>>score_table[i];
    cout<<score_table[i]<<" ";
  }
  for(int i = 0; i<n; i++){ // i = team ,j = matches
    cout<<endl;
    for(int j = 0; j<n; j++){
      read>>remaining_matches[i][j];
      cout<<remaining_matches[i][j]<<" ";
    }
  }
int min = 0;
int min_index = 0;
int sum = 0;
int sum_array[n];
  for(int i = 0; i<n; ++i){
    sum = 0;
    for(int j = 0; j<n; ++j){
      sum += remaining_matches[j][i];

    }
    cout<<sum<<" ";
    sum_array[i] = sum;
  }
  for(int i = 0; i<n; i++)
  cout<<"\nSUM of "<<i+1<< ". column: "<<sum_array[i]<<endl;

  for(int i = 0; i<n; i++){
    min = sum_array[0];

    if(min>sum_array[i]){
      min = sum_array[i];
      min_index = i;
      }
  }
  cout<<min_index+1<<". team is min : "<<min<<endl; // en küçükten ihtimal hesaplamaya basla
  //puan durumundaki minimumu da bularak dene
  // min durumununu fonksiyona cevir icine tek boyutlu array alacak
  read.close();
  write.close();
}
