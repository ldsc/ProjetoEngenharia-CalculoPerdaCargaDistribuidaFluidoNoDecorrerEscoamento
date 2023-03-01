#ifndef CFluido_H
#define CFluido_H
# include "CConversaoUnidades.h"
#include <iostream>
#include <fstream>

/// Representa um fluido.
class CFluido
{
protected:
//Atributos
	double viscosidadeDinamica;    //< Representa a ViscosidadeDinamica.
	double viscosidadeCinematica;
	double velocidadeFluido;
	double massaEspecifica;

public:
  //Construtor vazio
  /// Construtor default.
  CFluido() {
  	 viscosidadeDinamica = VISCOSIDADEdinamica();
	 viscosidadeCinematica = VISCOSIDADEcinematica();
	 velocidadeFluido = VELOCIDADEfluido();
	 massaEspecifica = MASSAespecifica();
  };
  
  ///Construtor de copia
  CFluido(const CFluido & ob): viscosidadeDinamica(ob.viscosidadeDinamica), viscosidadeCinematica(ob.viscosidadeCinematica),velocidadeFluido(ob.velocidadeFluido),massaEspecifica(ob.massaEspecifica){};
 
  ///Destrutor
  virtual~CFluido(){}
  
  /// Entrada dos dados.
  void Entrada();

  ///Set the value of ViscosidadeDinamica
  void ViscosidadeDinamica (double _vd)   {viscosidadeDinamica = _vd;}
  
  ///Get the value of ViscosidadeDinamica
  double ViscosidadeDinamica ()   {return viscosidadeDinamica;}
  
  ///Set the value of velocidadeFluido
  void VelocidadeFluido (double _velocidadefluido) {velocidadeFluido = _velocidadefluido;}
  
  ///Get the valur of velocidadeFluido
  double VelocidadeFluido () {return velocidadeFluido;}

  ///Set the value of MassaEspecifica
  void MassaEspecifica (double _me)   {massaEspecifica = _me;}

  ///Get the value of MassaEspecifica
  double MassaEspecifica ()   {return massaEspecifica;}

  ///Set the value of viscosidadeCinematica 
  void ViscosidadeCinematica (double _vc)  {viscosidadeCinematica = _vc;}
  
  ///Get the value of viscosidadeCinematica
  double ViscosidadeCinematica() { return viscosidadeCinematica;}
  
  ///Metodo para leitura de dados 
  double VISCOSIDADEcinematica ( );
  double VELOCIDADEfluido ( );
  double MASSAespecifica ( );
  double VISCOSIDADEdinamica ( );

  friend std::istream& operator>>(std::istream& is , CFluido& ob);
 
  friend std::ostream& operator<<(std::ostream& out , CFluido& ob);
};
#endif



