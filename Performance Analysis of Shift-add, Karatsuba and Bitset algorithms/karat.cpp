#include<iostream>
#include<string>	//string kullanımı için
#include<fstream>	//ofstream için
#include<time.h> //clock() fonk için

using namespace std;

int eq(string &str1, string &str2){
	int len1 = str1.size();
	int len2 = str2.size();
	if (len1 < len2){
		for (int i = 0 ;i < len2 - len1 ;i++)
			str1 = str1 + '0' ;
		return len2;
	}
	else if (len1 > len2){
		for (int i = 0 ; i < len1 - len2 ; i++)
			str2 =  str2+'0';
	}
	return len1;
}

string add( string first, string second ){
	int size = eq(first, second);	//iki string sizeı karşılaştırma.
	int carry = 0;
	string result;
	for (int i = size-1 ; i >= 0 ; i--){
		int firstBit = first.at(i) - '0';
		int secondBit = second.at(i) - '0';
		int sum = (firstBit ^ secondBit ^ carry)+'0'; //bit xor kullanıldı.

		result = (char)sum + result;

		carry = (firstBit&secondBit) | (secondBit&carry) | (firstBit&carry); //bit and ve orlar kullanıldı.
	}

	if (carry)	//carry varsa resulta eklenir yoksa if çalışmaz.
	 result = '1' + result;

	return result;
}

int multiplybit(string a, string b){
	 return (a[0] - '0')*(b[0] - '0'); //ilk bit çarpımı için kullanıldı.
 }

long int multiply(string x, string y){
	int n = eq(x, y);
	if (n == 1)
		return multiplybit(x, y); //tek bitlik string ise tek bitlik çarpıma yollanır.
	if (n == 0)
		return 0;	//string boşsa sıfır döner.

	int left = n/2;	//sol kısım
	int right = (n-left);	//sağ kısım

	string xl = x.substr(0,left);//ilk yarı
	string xr = x.substr(left, right);	//son yarı

	string yl = y.substr(0, left);
	string yr = y.substr(left, right);

	long int P1 = multiply(xl, yl);
	long int P2 = multiply(xr, yr);
	long int P3 = multiply(add(xl, xr), add(yl, yr));

	return P1*(1<<(2*right)) + (P3 - P1 - P2)*(1<<right) + P2;
}


int main(){
	float start_t;	//zaman kıyaslaması için
  	start_t = clock();

	string one, two;
	cout<<"Enter the first: "<<endl;
	cin>>one;
	cout<<"Enter the second: "<<endl;
	cin>>two;
	cout<< "Result in decimal: " <<multiply(one,two)<<endl;
	ofstream out("output.txt");
	out<<"Result in decimal: " <<multiply(one,two)<<endl;

	float end_t = clock();
 	float total_t = (end_t - start_t) / CLOCKS_PER_SEC;
  	cout<<"TIME: "<<total_t<<endl;
}
