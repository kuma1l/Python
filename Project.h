#include<iostream>
#include<fstream>
using namespace std;
class MyChar{
	char c;
	int ch_size;
public:
	MyChar();
	MyChar(const char newC);
	MyChar &operator=(const MyChar &obj);
	friend ifstream &operator >>(ifstream &cin, MyChar &obj);
	friend ostream &operator<<(ostream &cout, const MyChar &obj);
	friend ofstream &operator << (ofstream &cout,const MyChar &obj){
		cout << obj.c;
		return cout;
	}
	bool operator==(const MyChar &obj);
	bool operator>=(const MyChar &obj);
	bool operator<=(const MyChar &obj);
	bool operator!=(const MyChar &obj);
	MyChar operator +(const int num);
	MyChar operator -(const int num);
	void setchar(const char x);
	const char getchar()const;
	const int getchsize()const;
};
class MyWord{
	MyChar *word;
	int word_Size;
public:
	MyWord();
	MyWord(MyChar *arr);
	friend ifstream &operator>>(ifstream &cin, MyWord &obj);
	friend ostream &operator <<(ostream &cout, const MyWord &obj);
	MyWord &operator=(const MyWord &obj);
	const int getwsize()const;
};
class Sentence{
	MyChar *sent;
	int Sent_Size;
public:
	Sentence();
	Sentence(MyChar *obj);
	friend ifstream &operator>>(ifstream &cin, Sentence &obj);
	int countwords()const;
	friend ostream &operator<<(ostream &cout, const Sentence &obj);
	MyChar &operator [](int i);
	const int getSize()const;
	MyChar*getsent()const;
};
class Paragraph{
	MyChar *Para;
	int Psize;
public:
	Paragraph();
	Paragraph(MyChar *arr);
	void countpunc()const;
	int countsent();
	void countwords();
	void countwords(ofstream &fout);
	void countwords(int);
	void wrdCheck()const;
	friend ifstream &operator>>(ifstream &cin, Paragraph &obj);
	friend ostream &operator<<(ostream &bout, const Paragraph &obj);
	friend ofstream &operator<<(ofstream &cout, const Paragraph &obj);
	void operator +();
	void operator -();
	Paragraph &operator %(const int num);
	Paragraph &operator +(const Paragraph &obj);
	Paragraph &operator *(const int num);
	void operator !();
	void operator ^(int);
	bool operator==(const Paragraph &obj);
	const MyChar *getpara()const;
};
//ofstream &operator<<(ofstream &cout, MyChar &obj);
void Menu();
void submenu();