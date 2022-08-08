#ifndef _MAINHPP
#define _MAINHPP
#include <iostream>
#include <iostream>
#include <sstream>
#include <string>
#include <string.h>
#include <stdlib.h>

#include "../funciones/strings.hpp"
#include "../funciones/tokens.hpp"
#include "../tads/Coll.hpp"
#include "../funciones/files.hpp"

using namespace std;

struct Calificacion
{
	int idAsig;
	int idEst;
	int calif;
};

struct Asignatura
{
	int idAsig;
	char nomAsig[30];
	char maestroACargo[50];
};

struct RAsignatura
{
	Asignatura asig;
	Coll<int> collEst;
};

string calificacionToString(Calificacion x)
{
	char sep = 1;
	string sIdAsig=to_string(x.idAsig);
	string sIdEst=to_string(x.idEst);
	string sCalif=to_string(x.calif);
	return sIdAsig+sep+sIdEst+sep+sCalif;
}

Calificacion calificacionFromString(string s)
{
	char sep = 1;
	Calificacion x;
	string t0 = getTokenAt(s,sep,0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,sep,1);
	x.idEst=stoi(t1);
	string t2 = getTokenAt(s,sep,2);
	x.calif=stoi(t2);
	return x;
}

string calificacionToDebug(Calificacion x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.idEst;
	sout << ",";
	sout << x.calif;
	sout<< "]";
	return sout.str();
}

Calificacion calificacion(int idAsig,int idEst,int calif)
{
	Calificacion a;
	a.idAsig = idAsig;
	a.idEst = idEst;
	a.calif = calif;
	return a;
}

bool calificacionEquals(Calificacion a,Calificacion b)
{
	if(a.idAsig!=b.idAsig) return false;
	if(a.idEst!=b.idEst) return false;
	if(a.calif!=b.calif) return false;
	return true;
}

// ------------------------------------------------------

// string asignaturaToString(Asignatura x)
// {
// 	char sep = 2;
// 	string sIdAsig=to_string(x.idAsig);
// 	string sNomAsig=x.nomAsig;
// 	string sMaestroACargo=x.maestroACargo;
// 	return sIdAsig+sep+sNomAsig+sep+sMaestroACargo;
// }

string asignaturaToString(Asignatura x)
{
	// char sep = 2;
	string sIdAsig=to_string(x.idAsig);
	string sNomAsig=x.nomAsig;
	string sMaestroACargo=x.maestroACargo;
	return sIdAsig+","+sNomAsig+","+sMaestroACargo;
}

// Asignatura asignaturaFromString(string s)
// {
// 	char sep = 2;
// 	Asignatura x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.idAsig=stoi(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	strcpy(x.nomAsig,t1.c_str());
// 	string t2 = getTokenAt(s,sep,2);
// 	strcpy(x.maestroACargo,t2.c_str());
// 	return x;
// }
Asignatura asignaturaFromString(string s)
{
	// char sep = 2;
	Asignatura x;
	string t0 = getTokenAt(s,'|',0);
	x.idAsig=stoi(t0);
	string t1 = getTokenAt(s,'|',1);
	strcpy(x.nomAsig,t1.c_str());
	string t2 = getTokenAt(s,'|',2);
	strcpy(x.maestroACargo,t2.c_str());
	return x;
}

string asignaturaToDebug(Asignatura x)
{
	stringstream sout;
	sout<< "[";
	sout << x.idAsig;
	sout << ",";
	sout << x.nomAsig;
	sout << ",";
	sout << x.maestroACargo;
	sout<< "]";
	return sout.str();
}

Asignatura asignatura(int idAsig,string nomAsig,string maestroACargo)
{
	Asignatura a;
	a.idAsig = idAsig;
	strcpy(a.nomAsig,nomAsig.c_str());
	strcpy(a.maestroACargo,maestroACargo.c_str());
	return a;
}

bool asignaturaEquals(Asignatura a,Asignatura b)
{
	if(a.idAsig!=b.idAsig) return false;
	return true;
}
// --------------------------------------------------

// string rAsignaturaToString(RAsignatura x)
// {
// 	char sep = 3;
// 	string sAsig=asignaturaToString(x.asig);
// 	string sCollEst=collToString<int>(x.collEst);
// 	return sAsig+sep+sCollEst;
// }

string rAsignaturaToString(RAsignatura x)
{
	// char sep = 3;
	string sAsig=asignaturaToString(x.asig);
	string sCollEst=collToString<int>(x.collEst);
	return sAsig+"*"+sCollEst;
}

// RAsignatura rAsignaturaFromString(string s)
// {
// 	char sep = 3;
// 	RAsignatura x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.asig=asignaturaFromString(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.collEst=collFromString<int>(t1);
// 	return x;
// }

// RAsignatura rAsignaturaFromString(string s)
// {
// 	char sep = 3;
// 	RAsignatura x;
// 	string t0 = getTokenAt(s,sep,0);
// 	x.asig=asignaturaFromString(t0);
// 	string t1 = getTokenAt(s,sep,1);
// 	x.collEst=collFromString<int>(t1);
// 	return x;
// }

RAsignatura rAsignaturaFromString(string s)
{
	// char sep = 3;
	RAsignatura x;
	string t0 = getTokenAt(s,'*',0);
	x.asig=asignaturaFromString(t0);
	string t1 = getTokenAt(s,'*',1);
	x.collEst=collFromString<int>(t1);
	return x;
}

string rAsignaturaToDebug(RAsignatura x)
{
	stringstream sout;
	sout<< "[";
	sout << asignaturaToDebug(x.asig);
	sout << ",";
	collReset<int>(x.collEst);
	int n=collSize<int>(x.collEst);
	sout << "{";
	for(int i=0; i<n; i++)
	{
		int q = collGetAt<int>(x.collEst,i,stringToInt);
		sout << intToString(q) << ((i<n-1)?",":"");
	}
	sout << "}";
	sout<< "]";
	return sout.str();
}

RAsignatura rAsignatura(Asignatura asig,Coll<int> collEst)
{
	RAsignatura b;
	b.asig = asig;
	b.collEst = collEst;
	return b;
}

bool rAsignaturaEquals(RAsignatura a,RAsignatura b)
{
	if(!asignaturaEquals(a.asig,b.asig)) return false;
	if(collToString<int>(a.collEst)!=collToString<int>(b.collEst)) return false;
	return true;
}

// string calificacionToString(Calificacion x){
// 	return intToString(x.idAsig)+','+ intToString(x.idEst)+','+intToString(x.calif);
// }


// Calificacion calificacionFromString(string s)
// {
// 	Calificacion x;
// 	x.idAsig = stringToInt(getTokenAt(s, ',', 0));
// 	x.idEst = stringToInt(getTokenAt(s, ',', 1));
// 	x.idAsig = stringToInt(getTokenAt(s, ',', 2));
// 	return x;
// }



#endif