#include<iostream>
#include<fstream>
#include<string.h>
#include"book.hpp"
#include"bookcopy.hpp"
#include"bookloan.hpp"
#include"menu.hpp"

using namespace std;

int main(){
    book *listbook[100];
    bookloan *listbookloan[100];
    int n=0;
    DoMenu(listbook, n);
    
}
