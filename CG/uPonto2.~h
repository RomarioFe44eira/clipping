#ifndef uPonto2H
#define uPonto2H
#include "uJanela.h"
#include <system.hpp>

class Ponto {
     public:
          double x,y;

          Ponto ();
          Ponto(double, double);
          int Xw2Vp(Janela mundo, Janela vp);
          int Yw2Vp(Janela mundo, Janela vp);
          String toString();

          void translacao(float dx, float dy);
          void escalonamento(float sx, float sy);
          void rotacionar(float angulo);
          void reflexao(float wx,float wy, int quadrante);

          String Ponto::toStr();

          void escalonamentoHomo();
          void homogenea();

         int cohen(Janela Clipping);
};
#endif
