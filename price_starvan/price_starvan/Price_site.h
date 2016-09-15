#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;
#pragma once



class Price_site
{
	char *p_;
	int n_str_,n_col_;
	char f_;
public:
	void Open(char *, int ,int );
	void Read(char *);
	//void Read();
	void Prints(int);
	Price_site(void);
	~Price_site(void);
	
};