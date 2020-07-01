#include"bookcopy.hpp"
#include"book.hpp"
#ifndef bookloan_H
#define bookloan_H
class bookloan:public bookcopy{
private:
    char Date[20];
    char Name[30];
public:
    bookloan();
    bookloan(char date[20],char loanname[30],char cpNo[10],char ttrang[],int dkcabiet,char tt[20],int year);
    char *getDate();
    char *getName();
    void setDate(char dateloan[20]);
    void setName(char nameloan[30]);
    virtual void nhap();
    virtual void inra();
    virtual void inrafile();
};
#endif
