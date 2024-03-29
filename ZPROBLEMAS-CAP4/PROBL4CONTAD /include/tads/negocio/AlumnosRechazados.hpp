#ifndef ALUMNOSRECHAZADOS
#define ALUMNOSRECHAZADOS
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "../../funciones/strings.hpp"
#include "../../funciones/tokens.hpp"
#include "../../funciones/files.hpp"
#include "../../tads/Coll.hpp"


using namespace std;

struct AlumnoRechasoInsc
{
int idAlumno;
Coll <string> c;
};

struct AlumnosRechazados
{
Coll <AlumnoRechasoInsc> c;
};
string alumnoRechasoInscToString(AlumnoRechasoInsc x)
{
	char sep = 5;
	string sIdAlumno=to_string(x.idAlumno);
	string sC=collToString<string>(x.c);
	return sIdAlumno+sep+sC;
}

AlumnoRechasoInsc alumnoRechasoInscFromString(string s)
{
	char sep = 5;
	AlumnoRechasoInsc x;
	string t0 = getTokenAt(s,sep,0);
	x.idAlumno=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.c=collFromString<string>(t1);
	return x;
}

string alumnoRechasoInscToDebug(AlumnoRechasoInsc x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAlumno;
	sout << ",";
	collReset<string>(x.c);
	int n=collSize<string>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		string q = collGetAt<string>(x.c,i,stringToString);
		sout << stringToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string alumnoRechasoInscToDebug(string mssg,AlumnoRechasoInsc x)
{
	stringstream sout;
	sout<< mssg<<":[";
	sout << x.idAlumno;
	sout << ",";
	collReset<string>(x.c);
	int n=collSize<string>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		string q = collGetAt<string>(x.c,i,stringToString);
		sout << stringToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

AlumnoRechasoInsc alumnoRechasoInsc(int idAlumno,Coll <string> c)
{
	AlumnoRechasoInsc a;
	a.idAlumno = idAlumno;
	a.c = c;
	return a;
}

bool alumnoRechasoInscEquals(AlumnoRechasoInsc a,AlumnoRechasoInsc b)
{
	if(a.idAlumno!=b.idAlumno) return false;
	if(collToString<string>(a.c)!=collToString<string>(b.c)) return false;
	return true;
}


string alumnosRechazadosToString(AlumnosRechazados x)
{
	char sep = 9;
	string sC=collToString<AlumnoRechasoInsc>(x.c);
	return sC;
}

AlumnosRechazados alumnosRechazadosFromString(string s)
{
	char sep = 9;
	AlumnosRechazados x;
	string t0 = getTokenAt(s,sep,0);
	x.c=collFromString<AlumnoRechasoInsc>(t0);
	return x;
}

string alumnosRechazadosToDebug(AlumnosRechazados x)
{
	stringstream sout;
	sout<< "[";
	collReset<AlumnoRechasoInsc>(x.c);
	int n=collSize<AlumnoRechasoInsc>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		AlumnoRechasoInsc q = collGetAt<AlumnoRechasoInsc>(x.c,i,alumnoRechasoInscFromString);
		sout << alumnoRechasoInscToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

string alumnosRechazadosToDebug(string mssg,AlumnosRechazados x)
{
	stringstream sout;
	sout<< mssg<<":[";
	collReset<AlumnoRechasoInsc>(x.c);
	int n=collSize<AlumnoRechasoInsc>(x.c);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		AlumnoRechasoInsc q = collGetAt<AlumnoRechasoInsc>(x.c,i,alumnoRechasoInscFromString);
		sout << alumnoRechasoInscToDebug(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

AlumnosRechazados alumnosRechazados(Coll <AlumnoRechasoInsc> c)
{
	AlumnosRechazados a;
	a.c = c;
	return a;
}

bool alumnosRechazadosEquals(AlumnosRechazados a,AlumnosRechazados b)
{
	if(collToString<AlumnoRechasoInsc>(a.c)!=collToString<AlumnoRechasoInsc>(b.c)) return false;
	return true;
}
// -----------------------------------------------------------------------------------
AlumnosRechazados alumnosRechazadosCreate(){
	AlumnoRechasoInsc aIns = alumnoRechasoInsc(0,coll<string>());
	AlumnosRechazados cAlum = alumnosRechazados(coll<AlumnoRechasoInsc>());
	collAdd<AlumnoRechasoInsc>(cAlum.c,aIns,alumnoRechasoInscToString);
	return cAlum;
}



int cmpAlumnoRechasadoId(AlumnoRechasoInsc a, int b){
	return a.idAlumno-b;
}

int alumnosRechazadoBuscar(Coll<AlumnoRechasoInsc>c , int idAlum){
	return collFind<AlumnoRechasoInsc,int>(c,idAlum,cmpAlumnoRechasadoId,alumnoRechasoInscFromString);
}

AlumnoRechasoInsc AlumnoRechasoInscObtener(Coll<AlumnoRechasoInsc>c, int pos){
	return collGetAt<AlumnoRechasoInsc>(c,pos,alumnoRechasoInscFromString);
}


int cmpStringString(string a, string b){
	return cmpString(a,b);
}


int alumnosRechazadosBuscarPorMateria(Coll<string>c, string sMateria){
	return  collFind<string,string>(c,sMateria,cmpStringString,stringToString);
}


void alumnosRechazadosAgregarMateria(Coll<string>& c,string sMateria){
	collAdd<string>(c,sMateria,stringToString);
}


void alumnosRechazadosSet(Coll<AlumnoRechasoInsc>c,AlumnoRechasoInsc element, int pos){
	collSetAt<AlumnoRechasoInsc>(c,element,pos,alumnoRechasoInscToString);
}


void alumnosRechazadosActualizar(AlumnosRechazados& aRecha, char materia[20], int idAlum){
	string sMateria = materia;
	int pos = alumnosRechazadoBuscar(aRecha.c,idAlum);
	if (pos<0)
	{
		AlumnoRechasoInsc aIns = alumnoRechasoInsc(idAlum,coll<string>());
		int posMateria = alumnosRechazadosBuscarPorMateria(aIns.c,sMateria);
		if (posMateria<0)
		{
			alumnosRechazadosAgregarMateria(aIns.c,sMateria);
		}
	}else
	{
		AlumnoRechasoInsc aIns = AlumnoRechasoInscObtener(aRecha.c,pos);
		alumnosRechazadosAgregarMateria(aIns.c,sMateria);
		alumnosRechazadosSet(aRecha.c,aIns,pos);
	}
}



int alumnosRechazadosSize(Coll<AlumnoRechasoInsc>& c){
	return collSize<AlumnoRechasoInsc>(c)-1;
}



#endif