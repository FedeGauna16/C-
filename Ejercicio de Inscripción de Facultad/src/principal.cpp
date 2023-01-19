//============================================================================
// Name        : cpp.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "biblioteca/funciones/strings.hpp"
#include "biblioteca/funciones/tokens.hpp"
#include "biblioteca/funciones/files.hpp"
#include "biblioteca/tads/Array.hpp"
#include "biblioteca/tads/Map.hpp"
#include "biblioteca/tads/List.hpp"
#include "biblioteca/tads/Stack.hpp"
#include "biblioteca/tads/Queue.hpp"
#include "biblioteca/tads/Coll.hpp"
#include "principal.hpp"
using namespace std;

Map<int,RCurso> subirCursos()
{
	FILE* f = fopen("CURSOS.dat", "r+b");
	Map<int,RCurso> ret = map<int,RCurso>();

	Curso c = read<Curso>(f);

	while(!feof(f))
	{
		RCurso rc = rCurso(c,0);
		mapPut<int,RCurso>(ret,c.idCur,rc);
		c = read<Curso>(f);
	}

	return ret;
}

void procesarIns(Inscripcion i,Map<int,RCurso>& mCur,Map<int,List<string>>& mAlu)
{
	RCurso* curso = mapGet<int,RCurso>(mCur,i.idCur);
	int capActual = curso->c.cap - curso->cont;
	if(capActual > 0)
	{
		curso->cont++;
	}
	else
	{
		string materia = curso->c.materia;
		if(!mapContains<int,List<string>>(mAlu,i.idAlu))
		{
			List<string> materiasR = list<string>();
			listAdd<string>(materiasR, materia);
			mapPut<int,List<string>>(mAlu,i.idAlu,materiasR);
		}
		else
		{
			List<string>* materiasR = mapGet<int,List<string>>(mAlu,i.idAlu);
			listAdd<string>(*materiasR, materia);
			mapPut<int,List<string>>(mAlu,i.idAlu,materiasR);
		}
	}
}

int cmp1TK(string i, string c)
{
	return i - c;
}

int cmp2TK(int i, int c)
{
	return i - c;
}

void procesarRea(Map<int,List<string>>& mAlu,Map<string,List<int>>& mMat,Map<int,RCurso>& mCur)
{
	FILE* f = fopen("REASIGNACION.dat","w+b");
	mapSortByKeys<int,List<string>>(mAlu,cmp2TK);
	mapReset<int,List<string>>(mAlu);
	while(mapHasNext<int,List<string>>(mAlu))
	{
		int alumnoID = mapNextKey<int,List<string>>(mAlu);
		List<string>* materias = mapGet<int,List<string>>(mAlu,alumnoID);
		listReset<string>(*materias);
		while(listHasNext<string>(*materias))
		{
			string* materia = listNext<string>(*materias);
			List<int>* cursoEnc = mapGet<string,List<int>>(mMat,*materia);
			if(*cursoEnc != NULL)
			{
				listReset<int>(*cursoEnc);
				int* cursoID = listNext<int>(*cursoEnc);
				RCurso* rcursoEnc = mapGet<int,RCurso>(mCur,*cursoID);
				rcursoEnc->cont++;
				Reasignacion r = reasignacion(alumnoID,*cursoID);
				write<Reasignacion>(f,r);
				listRemove<string,string>(*materias,*materia,cmp1TK);
				if(listIsEmpty(*materias))
				{
					mapRemove<int,List<string>>(mAlu,alumnoID);
				}
				if((rcursoEnc->c.cap - rcursoEnc->cont) == 0)
				{
					listRemove<int,int>(*cursoEnc,*cursoID,cmp2TK);
				}
			}
		}
	}
}

void procesarRev(Map<int,List<string>> mAlu,Map<int,Revision> mRev)
{
	mapReset<int,List<string>>(mAlu);
	while(mapHasNext<int,List<string>>(mAlu))
	{
		int alumnoID = mapNextKey<int,List<string>>(mAlu);
		List<string> materias = mapGet<int,List<string>>(mAlu,alumnoID);
		Revision r = revision();
	}
}

void punto1(Map<int,List<string>> mAlu)
{
	mapReset<int,List<string>>(mAlu);
	while(mapHasNext<int,List<string>>(mAlu))
	{
		int aluID = mapNextKey<int,List<string>>(mAlu);
		List<string> materias = *mapGet<int,List<string>>(mAlu,aluID);
		listReset<string>(materias);
		while(listHasNext<string>(materias))
		{
			string* materia = listNext<string>(materias);
			cout << "Alumno: " << aluID << "Materia: " << materia->info << endl;
		}
	}
}

void punto2(Map<int,RCurso> mCur,Map<string,List<int>> mMat)
{
	mapReset<int,RCurso>(mCur);
	while(mapHasNext<int,RCurso>(mCur))
	{
		RCurso* c = mapNextValue<int,RCurso>(mCur);
		int capActual = c->c.cap - c->cont;
		if(capActual > 0)
		{
			string materia = c->c.materia;
			List<int>* cursos = mapGet<string,List<int>>(mMat, materia);
			if(cursos == NULL)
			{
				mapPut<string,List<int>>(mMat,materia,list<int>());
			}
			int cID = c->c.idCur;
			listAdd<int>(*cursos,cID);

		}
	}
	mapReset<string,List<int>>(mMat);
	while(mapHasNext<string,List<int>>(mMat))
	{
		string mat = mapNextKey<string,List<int>>(mMat);
		List<int> cursosMostrar = *mapGet<string,List<int>>(mMat,mat);
		listReset<int>(cursosMostrar);
		while(listHasNext<int>(cursosMostrar))
		{
			int* cursoID = listNext<int>(cursosMostrar);
			cout << "Materia: " << mat << "Curso: " << cursoID->info << endl;
		}
	}
}

void punto3(Map<int,Reasignacion> mRea)
{
	mapReset<int,Reasignacion>(mRea);
	while(mapHasNext<int,Reasignacion>(mRea))
	{
		int alumnoID = mapNextKey<int,Reasignacion>(mRea);
		Reasignacion* r = mapGet<int,Reasignacion>(mRea,alumnoID);
		cout << "Alumno: " << alumnoID << "Curso: " << r->idCurReasig << endl;
	}
}

void punto4(Map<int,Revision> mRev)
{

}

int main()
{
	Map<int,RCurso> mCur = subirCursos();
	Map<int,List<string>> mAlu = map<int,List<string>>();
	Map<string,List<int>> mMat = map<string,List<int>>();
	Map<int,Revision> mRev = map<int,Revision>();

	FILE* f = fopen("INSCRIPCIONES.dat", "r+b");

	Inscripcion i = read<Inscripcion>(f);

	while(!feof(f))
	{
		procesarIns(i,mCur,mAlu);
		i = read<Inscripcion>(f);
	}

	punto1(mAlu);
	punto2(mCur,mMat);
	procesarRea(mAlu,mMat,mCur);
	procesarRev(mAlu,mRev);
	punto3(mRea);
	punto4(mRev);

	fclose(f);
   return 0;
}
