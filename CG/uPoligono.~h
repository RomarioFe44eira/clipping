#ifndef uPoligonoH
#define uPoligonoH
#include <vector>
#include "uPonto2.h"
#include <StdCtrls.hpp>
#include <ExtCtrls.hpp>

using namespace std;

class Poligono {
     public:
          int id;
          vector<Ponto> pontos;
          int tipo;

   void mostra(TListBox* aux);
   void desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta);
   void desenhaMoveTo(TCanvas* canvas, Janela mundo, Janela vp);
   void desenhaDDA(TCanvas* canvas, Janela mundo, Janela vp);
   void desenhaBresham(TCanvas* canvas, Janela mundo, Janela vp);

   void translacao(float dx, float dy);
   void escalonamento(float sx, float sy);
   void rotacionar(float angulo, int tipo);
   void reflexao(int quadrante, int tipo);

   void DesenhaCircunferencia(float xc, float yc, float r, Poligono *circ);
   void DesenhaPontoCircunferencia(float xc, float yc, float x, float y, Poligono *circ);

   Ponto Poligono::pontoMedio();
   //void Poligono::rotacionaHomo(double ang);
   void produtoMatriz(double matA[][3], double matB[][3], double matC[][3]);

};
#endif


