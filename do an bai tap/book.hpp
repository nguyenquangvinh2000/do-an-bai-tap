#ifndef book_H
#define book_H
class book{
  protected:
    int ISBN;
    char title[20];
    int year;
public:
    book();
    book(int dkcabiet, char tt[20], int year);
    int getISBN();
    char *getTitle();
    int getYear();
    void setISBN(int dk);
    void setTitle(char tieude[]);
    void setYear(int y);
    virtual void nhap();
    virtual void inra();
    virtual void inrafile();

};
#endif
