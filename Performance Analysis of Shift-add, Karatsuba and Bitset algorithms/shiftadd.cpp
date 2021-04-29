#include<iostream>
#include<string>
#include<cstring>
//#include<bitset>
#include<cmath>
#include<time.h>
#include<fstream>

using namespace std;

int BinaryToDecimal(int *arr,int size){
	int dec = 0;
	int temp = 0;
	int j=0;
	for(int i=size-1;i>=0;i--){
		dec = arr[i]*pow(2,j);
		temp = dec + temp;
	/*	cout<<"dec: "<<dec;
		cout<<"temp: "<<temp;
		cout<<" J: "<<j;*/
		j++;
	}
cout<<"Decimal: "<<temp<<endl;
return temp;
}

int *right_shift(int *arr,int size){
		int *temp;
		for(int i=size+1;i<=0;i)
			arr[i] = arr[--i];
			arr[0] = 0;
		return arr;

}
int *left_shift(int *arr, int size){
		int *temp;
		for(int i=0;i<size;i)
			arr[i] = arr[++i];
			arr[size] = 0;
		/*	cout<<"arr deneme: ";
		for(int j=0;j<size+1;j++)
			cout<<arr[j];
			cout<<endl;*/
		return arr;
}
int *addition(int *a, int *b,int asize, int bsize){
	int maxsize = asize >= bsize ? asize : bsize;
	int *result = new int[maxsize];
	int *temp = new int[maxsize+1];
//	cout<<"gelen size: "<<size<<endl;
	int carry = 0;
	//cout<<"size"<<size<<endl;
		for(int i = maxsize-1;i>=0;i--){
			result[i] = a[i] +b[i];
		if(a[i] )
		//for(int i = size-1;i>=0;i--)
			//result[i] = ilk[i] + son[i] + carry;
			if(a[i]+b[i]+carry==3){
		  	result[i]=1;
		  	carry=1;
		   }
		  if(a[i]+b[i]+carry==2) {
		    result[i]=0;
		    carry=1;
		  }
		  if(a[i]+b[i]+carry==1){
		    result[i]=1;
		    carry=0;
		  }
		  if(a[i]+b[i]+carry==0){
		   result[i]=0;
		   carry=0;
		  }
			//cout<<"i: "<<i<<endl;
		}
		if(carry == 1){
			for(int j = maxsize-1;j>=0;j--)
				temp[j] = result[j];
				temp[0] = 1;
				return temp;
		}
		else{
			for(int j = maxsize-1;j>=0;j--)
				temp[j] = result[j];
				//temp[0] = 0;
				return temp;
	}
}

int *multip(int *ilk, int *son,int size_ilk,int size_son){
	int size = size_ilk * size_son;
	int *result = new int[size];
	int *temp = new int[size_ilk];

	for(int j = size_son-1;j>=0;j--){
		for(int i = size_ilk-1;i>=0;i--){
			temp[i] = son[j] * ilk[i];
			left_shift(temp,size_ilk);
			result = addition(temp,result,size_ilk,size_son);
		}
}
return result;

}

int main(){
	float start_t = clock();
	string sbin1,sbin2;
	cout<<"Enter the first binary:"<<endl;
	cin>>sbin1;
	cout<<"Enter the second binary:"<<endl;
	cin>>sbin2;

	int bin_size1 = sbin1.size();
	int bin_size2 = sbin2.size();

	char cbin1[sbin1.size() + 1];
	strcpy(cbin1, sbin1.c_str());

	int binary1[sbin1.size()+1];
	for(int i=0;i<bin_size1;i++){
		binary1[i] = cbin1[i]- '0';

}
	//BinaryToDecimal(binary1,sbin1.size());

	cout<<endl;
	char cbin2[sbin2.size() + 1];
	strcpy(cbin2, sbin2.c_str());

	int binary2[sbin2.size()+1];
	for(int i=0;i<bin_size2;i++){
		binary2[i] = cbin2[i]- '0';

}/*
BinaryToDecimal(binary2,sbin2.size());
	cout<<endl;
	int *temp = left_shift(binary1,sbin1.size());
	cout<<"LEFT: ";
	for(int i=0;i<sbin1.size()+1;i++)
		cout<<temp[i];
		cout<<endl;

	/*	cout<<"RIGHT"<<endl;

	int *temp2 = right_shift(binary1,sbin1.size());
		for(int j=0;j<sbin1.size()+1;j++)
			cout<<temp2[j];
			cout<<endl;
*/
	/*cout<<"ADD: ";
	//int *result = new int[sbin1.size()+sbin2.size()];
	int *temp3 = addition(binary1,binary2,sbin1.size(),sbin2.size());
	for(int j=0;j<sbin2.size();j++)
		cout<<temp3[j];
		cout<<endl;
		BinaryToDecimal(temp3,sbin2.size());
	//	addition(binary1,binary2,sbin1.size(),sbin2.size(),result);


*/
	ofstream out("output2.txt");
	cout<<"multiplication: ";
	int *multitemp = multip(binary1,binary2,sbin1.size(),sbin2.size()); //1 eksik yazdım fonkta tam kullanabilmek için
	//for(int k=0;k<sbin1.size()+sbin2.size();k++)
		//cout<<multitemp[k];
		cout<<endl;

	//cout<<BinaryToDecimal(multitemp,sbin1.size()+sbin2.size());
	out<<BinaryToDecimal(multitemp,sbin1.size()+sbin2.size());

	float end_t = clock();
  float total_t = (end_t - start_t) / CLOCKS_PER_SEC;
  cout<<"TIME: "<<total_t<<endl;
	return 0;

}
