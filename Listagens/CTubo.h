#ifndef CTUBO_H
#define CTUBO_H
# include "CConversaoUnidades.h"
#include <iostream>
#include <fstream>
#include <map>
#include <string>
#include <math.h>
#include <cstdlib>
#include <iomanip>
#include <vector>
class CTubo
{
protected:
	std::map< std::string , double > tabelamaterial;
	std::map< double , std::string > tabelarugosidade;
	std::map<std::string,double> tabelarugosidaderelativa;
	std::vector<double>vetrugosidaderelativa;
	std::vector<double>vetorgraficorugosidade;
  	double rugosidade;
	double diametroHidraulico;
	std::string materialaux;
	std::vector<std::string> vectmaterial;
	std:: vector<double> vecrugosidade;	
	double areaTubo=1.00;
	
	
	std::string nomeArquivo;
	double rdh;
	double l;
	
public:
	
  //Empty Constructor
  CTubo(){Entrada(); areaTubo=DiametroHidraulico()*DiametroHidraulico()*3.141529/4; std::cout << "AREA TUBO: "<<areaTubo << '\n'; std::cout << "AREA HIDRAUKLCI: "<<DiametroHidraulico() << '\n';}
  
  //Construtor de copia
  CTubo(const CTubo& ob): vetrugosidaderelativa(ob.vetrugosidaderelativa), vetorgraficorugosidade(ob.vetorgraficorugosidade), rugosidade(ob.rugosidade), diametroHidraulico(ob.diametroHidraulico), materialaux(ob.materialaux),vectmaterial(ob.vectmaterial), vecrugosidade(ob.vecrugosidade),nomeArquivo(ob.nomeArquivo),rdh(ob.rdh),l(ob.l){}
  
  //Construtor sobrecarregado 
  CTubo( std::vector<double>_vetorgraficorugosidade, double _rugosidade,  double _diametroHidraulico, std::string _materialaux, std::vector<std::string> _vectmaterial, double _vecrugosidade, std::string _nomeArquivo, double _rdh, double _l ): vetorgraficorugosidade(_vetorgraficorugosidade), rugosidade(_rugosidade), diametroHidraulico(_diametroHidraulico),materialaux(_materialaux), vectmaterial(_vectmaterial),vecrugosidade(_vecrugosidade), nomeArquivo(_nomeArquivo), rdh(_rdh),l(_l){}
  
  //Empty Destructor
  virtual ~CTubo(){}
  
  void Entrada();
  
  //Set the value of rdh 
  //void Rdh (double _rdh) {rdh=_rdh;}
  
  double Rdh(){return rdh;}
  
  //Get the value of rdh
  double CRdh(){
  	for (int i=0; i<2; i++){
	   std::cin.get();
	}
  	std::cout << "Digite o nome do material específico (sem o uso de letras maiusculas ou espaços):\n";
	std::string _material; std::getline(std::cin,_material);
	for (auto& element: tabelarugosidaderelativa){
		std::cout<<element.first<<element.second<<'\n';
	}
	std::cout << "O valor é " << tabelarugosidaderelativa[_material] << '\n';
	rdh = tabelarugosidaderelativa[_material];
  }
  
  //Set the value of rugosidade 
  void Rugosidade (double _rugo) {rugosidade= _rugo;}

  //Get the value of Rugosidade
  double Rugosidade () {return rugosidade;}

  //Set the value of DiametroHidraulico
  void DiametroHidraulico (double _dh)   {diametroHidraulico = _dh;}

  //Get the value of DiametroHidraulico
  double DiametroHidraulico ()   {return diametroHidraulico;}
  
  double AreaTubo() {return areaTubo;}

  // Set the value of l
  void L (double _l) {l=_l;}

  //Get the value of L
  double L() {return l;}

  //Seta o map tabelamaterial 
  void Tabelamaterial (const std::map< std::string , double >& _tabelamaterial){tabelamaterial=_tabelamaterial;}
  //retorna o map tabelamaterial 
  std::map< std::string , double > Tabelamaterial(){return tabelamaterial;}
  //Seta o map tabelarugosidade 
  void Tabelarugosidade (std::map< double , std::string >_tabelarugosidade){tabelarugosidade=_tabelarugosidade;}
  //Retorna o map mAbertura 
  std::map< double ,std::string > Tabelarugosidade( )const{return tabelarugosidade;}
  
   //Dado rugosidade retorna material correspondente 
  std::string Tabelamaterial (double _tabelarugosidade){return tabelarugosidade[_tabelarugosidade];}
  // Dada material retorna rugosidade correspondente 
  double Tabelarugosidade (std::string _tabelamaterial){ return tabelamaterial [ _tabelamaterial ]; }
  //usuario cria tabela
  void tabela ();
  //Metodo para leitura de dados (l,diametro hidraulico)
  double Comprimento();
  //Metodo para leitura de dados (Diametro Hidraulico)
  double Diametrohidraulico( );
    
  //Sobrecarga de operadores
  friend std::istream& operator>>(std::istream& is , CTubo& ob);
  friend std::ostream& operator<<(std::ostream& out , CTubo& ob);
  friend std::ifstream& operator>>(std::ifstream& is , CTubo& ob);
  friend std::ofstream& operator<<(std::ofstream& out , CTubo& ob);
};
#endif



