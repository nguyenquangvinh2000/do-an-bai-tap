#include<iostream>
#include<string.h>
#include"book.hpp"
#include<fstream>

using namespace std;

book::book(){
    ISBN=0;
    strcpy(this->title," ");
    year=0;
}
book::book(int dkcabiet, char tt[20], int year){
    ISBN=dkcabiet;
    strcpy(this->title,tt);
    year=year;
}
int book::getISBN(){
    return ISBN;
}
char *book::getTitle(){
    return title;
}

void book::setISBN(int dk){
    ISBN=dk;
}
void book::setTitle(char tieude[]){
    strcpy(this->title,tieude);
}
void book::setYear(int y){
    year=y;
}
void book::nhap(){
    cout<<"ISBN:";
    cin>>ISBN;
    cout<<"nhập tiêu đề sách:";
    cin>>title;
    cout<<"year:";
    cin>>year;
}
void book::inra(){
    cout<<ISBN<<"\t\t"<<title<<"\t\t"<<year<<"\t\t";
}
void book::inrafile(){
    ofstream f;
    f.open("quanlithuvien.dat",ios::app);
    f<<ISBN<<endl;
    f<<title<<endl;
    f<<year<<endl;
    
}
