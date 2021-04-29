#include <iostream>
#include <fstream>  //ifstream için kullanıldı
#include <stdlib.h> //rand() fonk için kullanıldı
using namespace std;

struct node{
        string key; //kelime
        int index; // keyin kaçıncı satırda olduğunu belirten değer
        int col_value = 0;  //hiç collison yok default 0
        bool is_full = false; //default boş olarak yaratılır true slot dolu, false slot boş anlamını taşıyor
};
void printer(node *from, int m){  //sonuçları ekrana basmak için kullanılan printer
int collision = 0;
  for(int i=0;i<m;i++){

  cout<<from[i].index <<") "<<from[i].key<<endl;

  collision =+ from[i].col_value;
  }
  cout<<"Collison: "<<collision<<endl;

}
int hashing(int index, int mood){  //indexin modunu alan basit bir fonksiyon

        return index % mood;

}
void linear_probing(node* one, int m,node *s_one){
  node *hold = new node[m];
  int i = 0;
  char choice;
  cout<<"Enter your choice: a)Insert b)Search"<<endl;
  cin>>choice;

if(choice == 'a'){
  while(i < m){
  int hash_value = hashing(one[i].index,m);

  for(int j = 0; j < m; j++)
  if(hold[j].is_full == false)
    hold[hash_value].key = one[i].key;

    if(i == m-1)
      hold[hash_value].index = 0;
    else
      hold[hash_value].index = i+1;

      hold[hash_value].is_full = true;  //doldurulduğu için trueya çekilir

      i++;

  }
  cout<<"----------------Lİnear Probing Insert-----------------"<<endl;
    printer(hold,m);
  cout<<"-----------------------------------------------"<<endl;
}

else if(choice == 'b'){
  while(i < m){
  int hash_value = hashing(one[i].index,m);

  for(int j = 0; j < m; j++)
  if(hold[j].is_full == false)
    hold[hash_value].key = one[i].key;

    if(i == m-1)
      hold[hash_value].index = 0;
    else
      hold[hash_value].index = i+1;

      hold[hash_value].is_full = true;  //doldurulduğu için trueya çekilir

      i++;

    }
for(int x = 0; x < m; x++){
  for(int y = 0; y < m; y++){
    if(hold[x].key == s_one[y].key)
     cout<<"Found key: "<<hold[x].index<<" - "<<hold[x].key<<endl;
    else
    hold[x].col_value++;
  }
}
cout<<"----------------Lİnear Probing Search-----------------"<<endl;
  printer(hold,m);
cout<<"-----------------------------------------------"<<endl;

  }

}

void double_hashing(node *one,int m,int mood,node *s_one){ //yer dolu mu boş mu diye bak bool yapabilirsin, colision olursa col_valueyu
//arttır ikinci işleme geç, asal sayıyı kullanıcıdan alabilirsin herhangi bir asal sayı olması lazım???

  node *hold = new node[m];
  int i = 0;
  int hash_value;
  char choice;
  cout<<"Enter your choice: a)Insert b)Search"<<endl;
  cin>>choice;
  //cout<<"IS_FULL: "<<hold[1].is_full<<endl;
  int prime_number;
  cout<<"Please choose your prime number for double_hashing: "<<endl;
  cin>>prime_number;
if(choice == 'a'){
  while(i<m){
if(m == mood){  //
    hash_value = hashing(one[i].index,mood);
    //cout<<"hashing: "<<hashing(one[i].index,mood)<<endl;
  if(hold[hash_value].is_full == false){
    hold[hash_value].key = one[i].key;
    if(i == m-1)
      hold[hash_value].index = 0;
    else
      hold[hash_value].index = i+1;

    }
  }

  else{

    one[i].col_value++;// colision olduğu için +1 yapmalıyız

    hash_value = hashing(one[i].index,mood);  //double_hash_1
    int double_value = prime_number - hashing(one[i].index,prime_number);  //prime_number-(index % prime_number) -> double_hash_2
    int double_hash_value = hash_value +(double_value * one[i].col_value);

    hold[double_hash_value].key = one[i].key;
    hold[i].index = i;

  }
  i++;

}
  cout<<"-------------Double Hashing Insert---------------"<<endl;
  printer(hold,m);
  cout<<"-------------------------------------------"<<endl;
  }

  if(choice == 'b'){
    while(i<m){
  if(m == mood){  //
      hash_value = hashing(one[i].index,mood);
      //cout<<"hashing: "<<hashing(one[i].index,mood)<<endl;
    if(hold[hash_value].is_full == false){
      hold[hash_value].key = one[i].key;
      if(i == m-1)
        hold[hash_value].index = 0;
      else
        hold[hash_value].index = i+1;

      }
    }

    else{

      one[i].col_value++;// colision olduğu için +1 yapmalıyız

      hash_value = hashing(one[i].index,mood);  //double_hash_1
      int double_value = prime_number - hashing(one[i].index,prime_number);  //prime_number-(index % prime_number) -> double_hash_2
      int double_hash_value = hash_value +(double_value * one[i].col_value);

      hold[double_hash_value].key = one[i].key;
      hold[i].index = i;

    }
    i++;

  }
  for(int x = 0; x < m; x++){
    for(int y = 0; y < m; y++){
      if(hold[x].key == s_one[y].key)
        cout<<"Found key: "<<hold[x].index<<" - "<<hold[x].key<<endl;
      else
      hold[x].col_value++;
    }
  }

  cout<<"-------------Double Hashing Search---------------"<<endl;
  printer(hold,m);
  cout<<"-------------------------------------------"<<endl;
}//
}

void universal_hashing(node *one, int m,node *s_one){

  node *hold = new node[m];
  int hash_value;
  char choice;
  cout<<"Enter your choice: a)Insert b)Search"<<endl;
  cin>>choice;

  int a = rand() % m; //random a integer
  cout<<"Random integer a: "<<a<<endl;

  int k0,k1,k2;
  int i=0;
if(choice == 'a'){
  while(i < m){
     k0 = one[i].index / 10000; //2li şekilde 3 parçaya bölündü
     k1 = one[i].index / 100;
     k2 = one[i].index % 100;
     //cout<<k0<<" "<<k1<<" "<<k2<<endl;

     int hash_value = hashing((k0*a + k1*a + k2*a),m);
     cout<<"Universal Hash Value: "<<hash_value<<endl;

     if(hold[hash_value].is_full == false){
       hold[hash_value].key = one[i].key;

       hold[i].index = i;
       hold[hash_value].is_full = true; //dolduğunda trueya çekilir

}
    else
      hold[i].col_value++;

i++;
  }
  cout<<"------------------Universal Hashing Insert-----------------"<<endl;
  printer(hold,m);
  cout<<"----------------------------------------------------"<<endl;
  }
  else if(choice == 'b'){
    while(i < m){
       k0 = one[i].index / 10000; //2li şekilde 3 parçaya bölündü
       k1 = one[i].index / 100;
       k2 = one[i].index % 100;
       //cout<<k0<<" "<<k1<<" "<<k2<<endl;

       int hash_value = hashing((k0*a + k1*a + k2*a),m);
       //cout<<"Universal Hash Value: "<<hash_value<<endl; //istenirse gelen hash valueya bakılabilir.

       if(hold[hash_value].is_full == false){
         hold[hash_value].key = one[i].key;

         hold[i].index = i;
         hold[hash_value].is_full = true; //dolduğunda trueya çekilir

}
      else{
        hold[i].col_value++;
      }

i++;
}
    for(int x = 0; x < m; x++){ //Search fonksiyonu
      for(int y = 0; y < m; y++){
        if(hold[x].key == s_one[y].key)
          cout<<"Found key: "<<hold[x].index<<" - "<<hold[x].key<<endl;
        else
        hold[x].col_value++;
      }
    }
    cout<<"------------------Universal Hashing Search-----------------"<<endl;
    printer(hold,m);
    cout<<"----------------------------------------------------"<<endl;

  }
}
void menu(){  //seçim için menu fonksiyonu kolaylık için
  cout<<endl;
  cout<<"1) Linear Probing a)Insert b)Search"<<endl;
  cout<<"2) Double Hashing a)Insert b)Search"<<endl;
  cout<<"3) Universal Hashing a)Insert b)Search"<<endl;

  cout<<"4) Exit "<<endl;
  cout<<endl;
}
void search(node *one, string key, int m){

}

int main(){
  bool end = false;
  int choice;
  string key;

  int m;
  cout<<"Enter the size of table: "<<endl;
  cin>>m;

  node *table = new node[m];
  node *s_table = new node[m];

  ifstream inFile ("vocab.txt");
  ifstream inFile2 ("search.txt");

  int i = 0;
  while(i<m){
  getline(inFile,table[i].key);
  getline(inFile2,s_table[i].key);

  table[i].index = i+1;
  s_table[i].index = i+1;

  //cout<<s_table[i].index <<" - "<<s_table[i].key<<endl;
i++;
}
cout<<endl;
int mood;

  while(!end){
    menu();
    cin>>choice;
    if(choice == 1)
      linear_probing(table,m,s_table);
    if(choice == 2){
      cout<<"If you have double index in the list, Please enter the mood number which is smaller than table size:"<<endl;
      cout<<"If you do not have any double index in the list, Please enter table size: "<<endl;
      cin>>mood;
      double_hashing(table,m, mood,s_table);
    }
    if(choice == 3)
      universal_hashing(table,m,s_table);

    if(choice == 4)
      end = true;
    else
    cout<<"Please enter your choice again: "<<endl;

  }


//linear_probing(table,m);


//double_hashing(table,m,mood);

//universal_hashing(table,m);
return 0;
}
