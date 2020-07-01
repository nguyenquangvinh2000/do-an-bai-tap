#include<iostream>
#include<string.h>
#include"bookloan.hpp"
#include<fstream>
#include"bookcopy.hpp"
#include"book.hpp"

using namespace std;

bookloan::bookloan():bookcopy(){
  strcpy(this->Date,"");
  strcpy(this->Name, "");
}

bookloan::bookloan(char date[20],char loanname[30],char cpNo[10],char ttrang[],int dkcabiet,char tt[20],int year):bookcopy(cpNo,ttrang,dkcabiet,tt,year){
  strcpy(this->Date,date);
  strcpy(this->Name,loanname);
}
char *bookloan::getDate(){
    return Date;
}
char *bookloan::getName(){
    return Name;
}
void bookloan::setDate(char dateloan[20]){
    strcpy(this->Date, dateloan);
}
void bookloan::setName(char nameloan[30]){
    strcpy(this->Name,nameloan);
}
void bookloan::nhap(){
    bookcopy::nhap();
    cout<<"nhập ngày mượn:";
    cin>>Date;
    cout<<"nhập tên người mượn:";
    cin>>Name;
}
void bookloan::inra(){
    bookcopy::inra();
    cout<<Date<<"\t\t"<<Name<<endl;
}
void bookloan::inrafile(){
    ofstream f;
    f.open("quanlithuvien.dat",ios::app);
    if(f.fail()){
        cout<<"file erro";
    }
    f<<Date<<endl;
    f<<Name<<endl;
    f<<copyno<<endl;
    f<<available<<endl;
    
    f.close();
    
}
