#include"book.hpp"
#ifndef bookcopy_H
#define bookcopy_H
class bookcopy:public book{
protected:
    char copyno[10];
    char available[10];
public:
    bookcopy();
    bookcopy(char cpNo[10],char ttrang[10],int dkcabiet, char tt[20], int year);
    char *getCopyno();
    char *getAvailable();
    void setCopyno(char masach[]);
    void setAvailable(char ttrang[]);
    virtual void nhap();
    virtual void inra();
    virtual void inrafile();
};
#endif
