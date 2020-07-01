#include<iostream>
#include<string.h>
#include<fstream>
#include"book.hpp"
#include"bookcopy.hpp"
#include"bookloan.hpp"
#include"menu.hpp"

using namespace std;

int InMenu(){
    int chon;
    system("clear");
    cout<<"\t1. Thêm sách"<<endl;
    cout<<"\t2. Tìm sách"<<endl;
    cout<<"\t3. Xoá"<<endl;
    cout<<"\t4. Hiện thị danh sách trong mảng"<<endl;
    cout<<"\t5. Hiển thị danh sách trong file"<<endl;
    cout<<"\t6. Lưu danh sách vào file "<<endl;
    cout<<"\t7. Tạo tệp mới"<<endl;
    cout<<"\t8. Thoát"<<endl;
    cout<<"select:";
    cin>>chon;
    return chon;
}
void DoMenu(book *listbook[],int &n){
  char anykey;
  int chon;
  do{
    chon=InMenu();
    switch(chon)
    {
      case 1: //thêm sách
      {
        n++;
        bookloan *b = new bookloan();
        b->nhap();
        listbook[n-1]=b;
        break;
      }
      case 2:
      {
        char ten[30];
        cin.ignore();
        cout<<"Nhập tên tìm: ";
        cin.getline(ten,30);
        cout<<"STT\t"<<"ISBN\t"<<"title\t"<<"Năm xb\t"<<"mã sách\t"<<"tình trạng\t"<<"ngày mượn\t"<<"tên người mượn"<<endl;
        for(int i=0;i<n;i++){
          if(strcmp(listbook[i]->getTitle(),ten)==0)
          {
            cout<<i+1<<"\t\t";
            listbook[i]->inra();
          }
        }
        break;
      }
      case 3: //xoá
      {
        char ten[30];
        cin.ignore();
        cout<<"nhập tên xoá:";
        cin.getline(ten,30);
        for(int i=0;i<n;i++){
          if(strcmp(listbook[i]->getTitle(),ten)==0){
            n--;
            for(int j=i;j<n;j++){
              listbook[j]=listbook[j+1];
            }
            break;
          }
        }
        break;
      }
      case 4: //in danh sách ra mảng
      {
        cout<<"STT\t"<<"tên\t"<<"ISBN\t"<<"title\t"<<"Năm xb\t"<<"mã sách\t"<<"tình trạng\t"<<"ngày mượn\t"<<"tên người mượn"<<endl;
        for(int i=0;i<n;i++){
          cout<<i+1<<"\t\t";
          listbook[i]->inra();
        }
        break;
      }
      case 5:
      {
        ifstream f;
        f.open("quanlithuvien.dat",ios::in);
        if(f.fail()){
          cout<<"file erro";
          break;
        }
        char type[3];
        int isbn;
        char tieude[20];
        int namxuatban;
        char masach[11];
        bool tinhtrang;
        char ngaymuon[20];
        char tennguoimuon[30];
        bookloan *b;
        n=0;
        while(!f.eof()){
          f.getline(type,3);
          if(strcmp(type,"sach")==0){
            n++;
            b = new bookloan();
            f>>isbn;
            f.getline(tieude,20);
            b->setTitle(tieude);
            f>>namxuatban;
            f.getline(masach,11);
            b->setCopyno(masach);
            f>>tinhtrang;
            f.getline(ngaymuon,20);
            b->setDate(ngaymuon);
            f.getline(tennguoimuon,30);
            b->setName(tennguoimuon);
            listbook[n-1]=b;
          }
        }
        f.close();
        cout<<"STT\t"<<"tên\t"<<"ISBN\t"<<"title\t"<<"Năm xb\t"<<"mã sách\t"<<"tình trạng\t"<<"ngày mượn\t"<<"tên người mượn"<<endl;
        for(int i=0;i<n;i++)
        {
          cout<<i+1<<"\t\t";
          listbook[i]->inra();
          cout<<endl;
        }
        break;

      }
      case 6: // in ra file
      {
        for(int i=0;i<n;i++){
          listbook[i]->inrafile();
        }
        break;
      }
      case 7: // tạo file mới
      {
        ofstream f;
        f.open("quanlithuvien.dat",ios::out);
        if(f.fail()){
          cout<<"file erro";
        }
        cout<<"Tạo tệp mới thành công!"<<endl;
        n=0;
        f.close();
        break;
      }
    }
    // ket thuc
    cout<<"Press any key to continue . . .";
    cin.ignore();
    cin.get();
  }
  while(chon>=1&&chon<9);
}
