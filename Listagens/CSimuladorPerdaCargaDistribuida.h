#ifndef CSIMULADORPERDACARGADISTRIBUIDA_H
#define CSIMULADORPERDACARGADISTRIBUIDA_H
#include <cstdlib> 
#include <string>  
#include <map>
#include <math.h>
#include <iostream>
#include <fstream>
#include <map>
#include <cmath>
# include "CConversaoUnidades.h"
#include "CTubo.h"
#include "CFluido.h"
#include "CGnuplot.h"

using namespace std;

/////////////////////////////////////
//Autores: Mateus Nascimento Gonçalves Rocha, Lucas Isaac Vieira Oliveira

class CSimuladorPerdaCargaDistribuida
{
    
protected:
	 //Atributos
	 double vazao=1.00;
 	 double re=1.00;
	 double hf=0.00;
 	 double f=1.00;
     CConversaoUnidades* conversor;
     CTubo* tubo;
     CFluido* fluido;
  
public:
 
const double g=9.81;

  //Empty Constructor
  CSimuladorPerdaCargaDistribuida (){
  	conversor = new CConversaoUnidades();
  	cout << *conversor;
  	tubo = new CTubo();
  	fluido = new CFluido();	
  }
  
  //Construtor de copia
  //CSimuladorPerdaCargaDistribuida(CTubo& _tubo,CFluido& _fluido,const CSimuladorPerdaCargaDistribuida& ob): tubo(_tubo),fluido(_fluido),vazao(ob.vazao), re(ob.re), hf(ob.hf), f(ob.f),areaTubo(ob.areaTubo){}
  
  //Construtor sobrecarregado 
  //CSimuladorPerdaCargaDistribuida(CTubo& _tubo,CFluido& _fluido, double _vazao,  double _re, double _hf, double _f, double _g, double _areaTubo, double _diametrohidraulico ):tubo(_tubo),fluido(_fluido),vazao(_vazao), re(_re),hf(_hf), f(_f),areaTubo(_areaTubo) {}
  
  //Empty Destructor
  virtual ~CSimuladorPerdaCargaDistribuida (){}
  
  
  //Metodo set
  void Vazao (double _vaz)   {vazao = _vaz;}
  
  //Metodo get
  double Vazao ()   {return vazao;}
  
  //Metodo set
  void Re (double _re)   {re = _re;}
  
  //Metodo get
  double Re ()   {return re;}
  
  //Metodo set
  void Hf (double _hf)   {hf = _hf;}
  
  //Metodo get
  double Hf ()   {return hf;}
  
  //Metodo set
  void F (double _f)   {f = _f;}
  
  //Metodo get
  double F ()   {return f;}
  
  //Metodos de calculo
 
  double CalcVazao ( );

  double CalcRe ( );
  
  double Calcf  ();

  double CalcHfQ ();
  
  void Plotar();

  //Sobrecarga de operador
  friend std::ifstream& operator>>(std::ifstream& is , CSimuladorPerdaCargaDistribuida& ob);
  friend std::ofstream& operator<<(std::ofstream& out , CSimuladorPerdaCargaDistribuida& ob);

  void Simular();                                         

};
#endif 
