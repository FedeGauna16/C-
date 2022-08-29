#ifndef _TTOKENS_T_
#define _TTOKENS_T_

#include <iostream>
#include <stdio.h>
#include "strings.hpp"
using namespace std;

int tokenCount(string s,char sep)
{
	int n = 0, cont = 0, x = charCount(s, sep), cont2 = 0;

	while(s[n] != '\0')
	{
		if(!contains(s, sep))
		{
			cont = 1;
			return cont;
		}

		if(s[n] == sep)
		{
			cont2++;
			if(cont2 == x && s[n+1] == '\0')
			{
				cont++;
				return cont;
			}
			cont++;
		}
		n++;
	}
   return cont+1;
}

void addToken(string& s,char sep,string t)
{
	if(s == "")
	{
		s += t;
	}
	else
	{
		s += sep + t;
	}

}

string getTokenAt(string s,char sep, int i)
{

   return "";
}

void removeTokenAt(string& s,char sep, int i)
{
}

void setTokenAt(string& s,char sep, string t,int i)
{
}

int findToken(string s,char sep, string t)
{
   return 0;
}

#endif
