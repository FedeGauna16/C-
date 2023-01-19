#ifndef _TARR_BITWRITER_
#define _TARR_BITWRITER_

#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"

using namespace std;

struct BitWriter
{
	int bits[8];
	FILE* f;
	int cont;
	int acum;
};

BitWriter bitWriter(FILE* f)
{
	BitWriter bw;
	bw.f = f;
	bw.cont = 0;

   return bw;
}

void bitWriterWrite(BitWriter& bw,int bit)
{
	if(bw.cont == 8)
	{
		write<int>(bw.f, bw.bits);
		bw.cont = 0;
	}
	bw.bits[bw.cont] = bit;
	bw.cont++;
	bw.acum++;
}

void bitWriterFlush(BitWriter& bw)
{
	while((bw.acum % 8) != 0)
	{
		bitWriterWrite(bw, 0);
	}
	if(bw.cont == 8)
	{
		write<int>(bw.f, bw.bits);
		bw.cont = 0;
	}
}

#endif
