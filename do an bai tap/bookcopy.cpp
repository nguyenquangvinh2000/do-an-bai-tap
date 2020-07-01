#include<iostream>
#include"bookcopy.hpp"
#include<string.h>
#include<fstream>
#include"book.hpp"

using namespace std;

bookcopy::bookcopy():book(){
  strcpy(this->copyno," ");
  strcpy(available," ");
}
bookcopy::bookcopy(char cpNo[10],char ttrang[],int dkcabiet, char tt[20], int year):book(dkcabiet,tt,year){
    strcpy(this->copyno,cpNo);
    strcpy(this->available,ttrang);
}
char *bookcopy::getAvailable(){
    return available;
}
void bookcopy::setCopyno(char masach[]){
    strcpy(this->copyno,masach);
}

void bookcopy::nhap(){
    book::nhap();
    cout<<"nhập mã sách:";
    cin>>copyno;
    cout<<"nhập tình trạng:";
    cin>>available;
}
void bookcopy::inra(){
  book::inra();
  cout<<copyno<<"\t\t"<<available<<"\t\t";
}
void bookcopy::inrafile(){
  book::inrafile();
  ofstream f;
  f.open("quanlithuvien.dat",ios::app);
  if(f.fail()){
      cout<<"file erro";
  }
  f<<copyno<<endl;
  f<<available<<endl;
  f.close();
}
