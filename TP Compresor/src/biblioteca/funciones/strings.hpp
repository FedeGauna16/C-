#ifndef _TSTRINGS_T_
#define _TSTRINGS_T_

#include <iostream>
#include <stdio.h>
#include <math.h>
using namespace std;

int length(string s)
{
	int n = 0;
	while(s[n] != '\0')
	{
		n++;
	}
   return n;
}

int charCount(string s,char c)
{
	int n = 0, cont = 0;
		while(s[n] != '\0')
		{
			if(s[n] == c)
			{
				cont++;
			}
			n++;
		}
   return cont;
}

string substring(string s,int d,int h)
{
	int n = 0;
	string x = "";
			while(s[n] != '\0' && n != h)
			{
				if(n >= d)
				{
					x += s[n];
					//cout << x << " " << n <<endl;
					//cout << "-" << s[n] << "|" << s[h] << "- ";
				}
				n++;
			}
	   return x;
}

string substring(string s,int d) // ok
{
	int n = 0;
	string x = "";
				while(s[n] != '\0')
				{
					if(n >= d)
					{
						x += s[n];
						//cout << x << endl;
						//cout << "-" << s[n] << "|" << s[h] << "- ";
					}
					n++;
				}
		   return x;
}

int indexOf(string s,char c) // ok
{
	int n = 0;
	while(s[n] != '\0')
	{
		if(s[n] == c)
		{
			return n;
		}
		n++;
	}
	return -1;
}

int indexOf(string s,char c,int offSet) // ok
{
	int n = offSet;
	while(s[n] != '\0')
	{
		if(s[n] == c)
		{
			return n;
		}
		n++;
	}
   return -1;
}

int indexOf(string s,string toSearch) // ok
{
	int n = 0;
	char x = toSearch[0];
	while(s[n] != '\0')
	{
		if(s[n] == x)
		{
			string r = substring(s, n, n+length(toSearch));
			//cout << r << "|" << toSearch;
			//cout << (toSearch == r);
			if(toSearch == r)
			{
				//cout << "hola";
				return n;
			}
		}
		n++;
	}
	return -1;
}

int indexOf(string s,string toSearch,int offset) // ok
{
	int n = offset;
	char x = toSearch[0];
	while(s[n] != '\0')
	{
		if(s[n] == x)
		{
			string r = substring(s, n, n+length(toSearch));
			//cout << r << "|" << toSearch;
			//cout << (toSearch == r);
			if(toSearch == r)
			{
				//cout << "hola";
				return n;
			}
		}
		n++;
	}
	return -1;
}

int lastIndexOf(string s,char c)
{
	int n = 0, cantC = charCount(s, c), cont = 0;
	while(s[n] != '\0')
	{
		if(s[n] == c)
		{
			cont++;
			if(cantC == cont)
			{
				return n;
			}
		}
			n++;
	}
	return -1;
}

int indexOfN(string s,char c,int n)
{
	if(n == 0){
		return -1;
	}
	int N = 0, cont = 0;
	while(s[N] != '\0')
	{
		if(s[N] == c)
		{
			cont++;
			if(n == cont)
			{
				return N;
			}
		}
			N++;
	}
	if(n > cont)
	{
		return length(s);
	}
	return -1;
}

int charToInt(char c)
{
	//int i = c;
	if(48 <= c && c <= 57)
	{
		return c - 48;
	}
	if(65 <= c && c <= 90)
	{
		return c - 55;
	}
	if(97 <= c && c <= 122)
	{
		return c - 87;
	}
   return 0;
}

char intToChar(int i)
{

	if(0 <= i && i <= 9)
	{
		return i + 48;
	}
	if(10 <= i && i <= 35)
	{
		return i + 55;
	}
   return 'X';
}

int getDigit(int n,int i)
{
	int cont = -1, x = 0;
	while(cont != i)
	{
		x = n % 10;
		i++;
	}
   return x;
}

int digitCount(int n)
{
   return 0;
}

string intToString(int i)
{
   return "";
}

int stringToInt(string s,int b) // ok
{

   return 0;
}

int stringToInt(string s) // ok
{
	int n = 0, i = 0;
	char c;
	while(s[n] != '\0')
	{
		c = s[n];
		i = i * 10 + charToInt(c);
		n++;
	}
   return 0;
}

string charToString(char c)
{
   return "";
}

char stringToChar(string s)
{
   return 'X';
}

string stringToString(string s)
{
   return "";
}

string doubleToString(double d)
{
   return "";
}

double stringToDouble(string s)
{
   return 1.1;
}

bool isEmpty(string s)
{
   return true;
}

bool startsWith(string s,string x)
{
   return true;
}

bool endsWith(string s,string x)
{

   return true;
}

bool contains(string s,char c)
{
	int n = 0;
	bool x = false;
	while(s[n] != '\0')
	{
		if(s[n] == c)
		{
			x = true;
		}
		n++;
	}
	if(!x)
	{
		return false;
	}
   return true;
}

string replace(string s,char oldChar,char newChar)
{
   return "";
}

string insertAt(string s,int pos,char c)
{
   return "";
}

string removeAt(string s,int pos)
{
   return "";
}

string ltrim(string s)
{
   return "";
}

string rtrim(string s)
{
   return "";
}

string trim(string s)
{
   return "";
}

string replicate(char c,int n)
{
   return "";
}

string spaces(int n)
{
   return "";
}

string lpad(string s,int n,char c)
{
   return "";
}

string rpad(string s,int n,char c)
{
   return "";
}

string cpad(string s,int n,char c)
{
   return "";
}

bool isDigit(char c)
{
   return true;
}

bool isLetter(char c)
{
   return true;
}

bool isUpperCase(char c)
{
   return true;
}

bool isLowerCase(char c)
{
   return true;
}

char toUpperCase(char c)
{
   return 'X';
}

char toLowerCase(char c)
{
   return 'X';
}

string toUpperCase(string s)
{
   return "";
}

string toLowerCase(string s)
{
   return "";
}

int cmpString(string a,string b)
{
   return 0;
}

int cmpDouble(double a,double b)
{
   return 0;
}

#endif
