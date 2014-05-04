
/***********************************************************bottom-up**********************************************************************/
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
void mergesort(int a[],int,int,double&);
void merge(int a[],int,int,int,double&);

int min(int a, int b)
{
	return (a<b)? a:b;
}

int main (){
	ifstream fin("data1.1024");
	int max = 1024;
	int *a = new int [max];
	int t = 0;
	//int i = 0;
	while(!fin.eof()){
		fin >> a[t++];
	}
	double count = 0;	
	mergesort(a,0,max-1,count);
	cout<<count<<endl;
	return 0;
}
	
void mergesort(int a[],int l,int r, double &count){
	int m;
	for(m = 1; m <= r-l; m += m)
		for(int i = l; i <= r-m; i+= m+m)
			merge(a,i,i+m-1,min(i+m+m-1,r),count);
}

void merge(int a[],int l,int m, int r, double &count){
	int i,j;
	int *aux = new int [r];
	for(i = m+1; i>l;i--) aux[i-1] = a[i-1];
	for(j = m; j<r ; j++) aux[r+m-j] = a[j+1];
	int k;
	for(k =l; k<=r ; k++)
	{
		if(aux[i]< aux[j]) a[k] = aux[i++];
		else a[k] = aux[j--];
		count ++;
	}
}


/*************************************************************up-down**************************************************************/

/*
#include <iostream>
#include <fstream>
#include <iomanip>
#include <ctime>

using namespace std;
void mergesort(int a[],int,int,int&);
void merge(int a[],int,int,int,int&);

int main (){
	ifstream fin("data1.32768");
	int max = 32768;
	int *a = new int [max];
	int t = 0;
	//int i = 0;
	while(!fin.eof()){
		fin >> a[t++];
	//	cout<<a[i++];
	}
	int count = 0;	
	mergesort(a,0,max-1,count);
	int i = 0;
	/*for(i;i<=max-1;i++){
		cout<<a[i]<<endl;
	}
	cout<<count<<endl;
	return 0;
}
	
void mergesort(int a[],int l,int r, int &count){
	if(r<=l) return;
	int m = (r+l)/2;
	mergesort(a,l,m,count);
	mergesort(a,m+1,r,count);
	merge(a,l,m,r,count);
}

void merge(int a[],int l,int m, int r, int &count){
	int i,j;
	int *aux = new int [r];
	for(i = m+1; i>l;i--) aux[i-1] = a[i-1];
	for(j = m; j<r ; j++) aux[r+m-j] = a[j+1];
	int k;
	for(k =l; k<=r ; k++){
		if(aux[i]< aux[j]) a[k] = aux[i++];
		else a[k] = aux[j--];
		count ++;
	}
}
*/








