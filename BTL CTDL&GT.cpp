#include<iostream>
#include<string.h>
using namespace std;
struct book{
	char title[100];
	char author[100];
	int year;
};
void nhap1(book &a);
void list(book a[],int &n);
void lookfor(book a[],int n);
void findfix(book a[],int n);
void add1(book a[],int &n);
void add(book a[],int &n,int x);
void remove(book a[],int &n,int x);
void xuat(book a[],int n);
int main()
{
	int n,x;
	book a[100],b;
	nhap1(b);
	list(a,n);
	xuat(a,n);
	lookfor(a,n);
	findfix(a,n);
	add1(a,n);
	add(a,n,x);
	remove(a,n,x);
	return 0;
}
void list(book a[],int &n)
{
	cout<<"Nhap so sach :";cin>>n;
	for(int i=0;i<n;i++)
		nhap1(a[i]);
}
void add(book a[],int &n,int x)
{
	cout<<"nhap vi tri chen :";cin>>x;
	for(int i=n-1;i>=x;i--)
	{
		strcpy(a[i+1].title,a[i].title);
		strcpy(a[i+1].author,a[i].author);
		a[i+1].year=a[i].year;
	}
		cout<<"Nhap tac pham :";cin>>a[x].title;
		cout<<"Nhap tac gia :";cin>>a[x].author;
		cout<<"nam xuat ban :";cin>>a[x].year;
	n=n+1;
	xuat(a,n);
}
void remove(book a[],int &n,int x)
{
	cout<<"chon vi tri can xoa :";cin>>x;
	for(int i=x;i<n-1;i++)
	{
		strcpy(a[i].title,a[i+1].title);
		strcpy(a[i].author,a[i+1].author);
		a[i].year=a[i+1].year;
	}
	n=n-1;
	xuat(a,n);
}
void xuat(book a[],int n)
{
	for(int i=0;i<n;i++)
		cout<<i<<" "<<"ten sach :"<<a[i].title<<"\t"<<"tac gia :"<<a[i].author<<"\t"<<"nam xb :"<<a[i].year<<endl;		
}
void nhap1(book &a)
{
	cout<<"Nhap tac pham :";cin>>a.title;
	cout<<"Nhap tac gia :";cin>>a.author;
	cout<<"nam xuat ban :";cin>>a.year;	
}
void lookfor(book a[],int n)
{
	char x[100];
	cout<<"Nhap ten sach can tim :";cin>>x;
	for(int i=0;i<n;i++)
		if(strcmp(x,a[i].title)==0)
			cout<<"ten sach :"<<a[i].title<<" "<<a[i].author<<" "<<a[i].year<<endl;
}
void add1(book a[],int &n)
{
	nhap1(a[n]);
	n+=1;
	xuat(a,n);
}
void findfix(book a[],int n)
{
	char x[100];
	int d;
	cout<<"Nhap ten sach can tim :";cin>>x;
	for(int i=0;i<n;i++)
		if(strcmp(x,a[i].title)==0)
			d=i;
	cout<<"Nhap tac pham :";cin>>a[d].title;
	cout<<"Nhap tac gia :";cin>>a[d].author;
	cout<<"nam xuat ban :";cin>>a[d].year;
	xuat(a,n);
}
