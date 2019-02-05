#pragma once


#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

class rejilla{

private:

	vector<vector<char> > M_;
	int 	m_;
	int		n_;

public:

	rejilla(int m=500,int n=500);
	int get_m(void) const;
	int get_n(void) const;
	char get_color(int i,int j) const;
	void set_color(int i,int j,char color);
	
};