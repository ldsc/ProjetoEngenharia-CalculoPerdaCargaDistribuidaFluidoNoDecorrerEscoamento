#ifndef CConversaoUnidades_h 
#define CConversaoUnidades_h
#include <iostream> 
#include <iomanip> 
#include <fstream> 
#include <string> 
#include <vector>

//Autor: Prof. Andre Duarte Bueno, Dr. Eng.
class CConversaoUnidades 
{
private : // Atributos
std :: vector < std :: string > unidade; ///< vetor com unidades
std :: vector < std :: string > si; ///< vetor com unidades si
std :: vector < std :: string > un; ///< vetor com unidades un
std :: vector < double > fatorConversao; ///< fatorConversao de SI para UN
std::string s; 
double v;
static bool conversaoPadraoUNSI; ///< A conversao padrao e de UNSI
static std :: string novaUnidade; ///< Unidade da ultima conversao realizada
public : 
// Construtor vazio
CConversaoUnidades ( ) {LerDadosTabelaConversao ( "unidadesPrimarias.dat" );LerDadosTabelaConversao ( "unidadesSecundarias.dat" );}
// Construtor sobrecarregado
CConversaoUnidades ( std :: vector < std :: string > _unidade , std :: vector < std :: string > _si ,
std :: vector < std :: string > _un , std :: vector <double > _fatorConversao ): unidade(_unidade ), si( _si ), un(_un), fatorConversao ( _fatorConversao ) { }
// Construtor copia
CConversaoUnidades ( const CConversaoUnidades & obj): unidade(obj.unidade ), si(obj .si), un( obj .un), fatorConversao (obj . fatorConversao ) {}
// Destrutor
~ CConversaoUnidades ( ) {};
// Retorna conversaoPadraoUNSI ( Get )
bool ConversaoPadraoUNSI () { return conversaoPadraoUNSI ; }
// Seta conversaoPadraoUNSI ( Set )
void ConversaoPadraoUNSI ( bool b) { conversaoPadraoUNSI = b; }
// Adiciona nos vetores : unidade , si , bg e fatorConversao a partir uma ifstream 
void LerDadosTabelaConversao ( std :: istream & in ) {
std :: string s; double v;
in >> s; unidade.push_back(s); /// Adiciona no final do vetor
in >> s; si.push_back (s);
in >> s; un.push_back (s);
in >> v; fatorConversao.push_back (v);
}
// Adiciona nos vetores : unidade , si , bg e fatorConversao a partir arquivo disco 
void LerDadosTabelaConversao (std :: string fileName ) {
std :: ifstream fin( fileName.c_str () );
if( fin.fail () )
std :: cerr << " Nome de arquivo invalido ou nao tem acesso leitura .\n";
while ( ! fin.eof () )
LerDadosTabelaConversao ( fin );
fin. close ();
}
// Modifica informacoes de conversao de uma dada posicao 
void ModificarDadosTabelaConversao ( std :: istream & in , int posicao = -1) 
{
if(posicao>=0 and posicao<unidade.size()) 
{
in >> unidade [ posicao ];
in >> si[ posicao ];
in >> un[ posicao ];
in >> fatorConversao [ posicao ];
}
else std :: cerr << "\nPosicaoo invalida !\n";
}
/** Retorna linha com informacoes : unidade unidadeSI unidadeBG fatorConversao */
void ModificarDadosTabelaConversao ( std :: ostream & out , int p= -1) {
if(p>=unidade.size() or p<0)
std :: cerr << "\n--> Posicao invalida !\n";
else
out << std :: setw (25) << unidade [p] << std :: setw (15) << si[p]
<< std :: setw (15) << un[p] << std :: setw (15) << fatorConversao [p] << '\n';
}
/** Salva informacoes em disco */
void ModificarDadosTabelaConversao ( std :: string fileName ) {
std :: ofstream fout ( fileName . c_str () );
if( fout )
for( int p=0; p<unidade.size(); p++)
ModificarDadosTabelaConversao (fout ,p);
else std :: cerr << " Nome de Arquivo  Invalido ou acesso negado .\n";
fout . close ();
}
/** Realiza conversao SI2BG */
double SIUN ( double valor , std :: string & unidadeSI ){
for( int p=0; p<unidade.size();p++)
if ( unidadeSI == si[p]){
novaUnidade = un[p];
return valor = valor / fatorConversao [p];
}
novaUnidade = unidadeSI ; // Mantem a unidade
return valor ;
}
/** Realiza conversao UNSI */
double UNSI ( double valor , std :: string & unidadeUN ){
for( int p=0; p<unidade.size(); p++)
if ( unidadeUN == un[p]) {
novaUnidade = si[p];
return valor = valor * fatorConversao [p];
}
novaUnidade = unidadeUN ; // Mant~A ©m a unidade
return valor ;
}
/** Realiza inversao da unidade ; se for SI converte para BG e vice - versa */
double InverteUnidade ( double valor , std :: string & _unidade ){
for( int p=0; p<unidade.size();p++) {
if ( _unidade == si[p]){ novaUnidade = un[p];
return valor /= fatorConversao [p]; // Converte para un
 }
if ( _unidade == un[p]){ novaUnidade = si[p];
return valor *= fatorConversao [p]; // Converte para si
}
}
novaUnidade = _unidade ; // Mantem  a unidade
std :: cerr << "\a\a\a\nUnidade nao encontrada! Conversao nao foi realizada!\n";
return valor ;
}
/** Retorna nova unidade */
std :: string NovaUnidade () { return novaUnidade ; }
// Operadores
/** Realiza UNSI se conversaoPadraoUNSI = true ; usa sobrecarga operador ( como função membro ) */
// Uso: double valorConvertido = objetoConversao ( valorAntesConversao );
double operator ()( double _v , std :: string & _un ){
return conversaoPadraoUNSI ? UNSI(_v , _un): SIUN (_v , _un);
}
/** Funcao amiga , envia para dipositivo de saida dados da tabela de convers~A o .*/
friend std :: ostream & operator << ( std :: ostream & out , CConversaoUnidades & conversor ){
for ( int p=0; p<conversor.unidade.size(); p++ )
conversor . ModificarDadosTabelaConversao (out ,p);
return out;
}
/** Funcao amiga , recebe de dipositivo de entrada dados da tabela de conversao .*/
friend std :: istream & operator >>( std :: istream & in , CConversaoUnidades & conversor ){
while ( ! in. eof () ) conversor . LerDadosTabelaConversao (in);
return in;
}
};
# endif
