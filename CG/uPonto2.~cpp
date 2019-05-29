#include <vcl.h>
#pragma hdrstop
#include "uPonto2.h"
#include <SysUtils.hpp>
#include <math.h>
#pragma package(smart_init)

#define PI 3.14159265359

Ponto::Ponto(){
     x = y = 0;
}

Ponto::Ponto(double nx, double ny){
     x = nx;
     y = ny;
}

int Ponto::Xw2Vp(Janela mundo, Janela vp){
     //CONVERTE X DE MUNDO PARA X DE VIEWPORT
     if((mundo.xmax - mundo.xmin) != 0){
          return (x-mundo.xmin) / (mundo.xmax - mundo.xmin) * (vp.xmax - vp.xmin);
     }
     return 0;
}

int Ponto::Yw2Vp(Janela mundo, Janela vp){
     //CONVERTE Y DE MUNDO PARA Y DE VIEWPORT
     if((mundo.ymax - mundo.ymin)!= 0){
          return (1 - (y-mundo.ymin) / (mundo.ymax - mundo.ymin)) * (vp.ymax - vp.ymin);
     }
     return 0;
}

String Ponto::toString(){
     return "(" + FloatToStr(x) + "," + FloatToStr(y) + ")";
}

String Ponto::toStr(){
     return "(" + FloatToStr((int)x) + ";" + FloatToStr((int)y) + ")";
}

void Ponto::translacao(float dx, float dy){
     x = x + dx;
     y = y + dy;
}

void Ponto::escalonamento(float sx, float sy){
     x = x * sx;
     y = y * sy;
}

void Ponto::rotacionar(float angulo){
     float teta = ((angulo * PI)/180);
     double aux = x;

     x = x * cos(teta) - y * sin(teta);
     y = aux * sin(teta) + y * cos(teta);
}

void Ponto::reflexao(float wx, float wy, int quadrante){
     switch(quadrante){
          case 0:x = -wx;break; //Reflexão em x
          case 1:y = -wy;break;//Reflexão em y
          case 2:x = -wx;y = -wy;break; //Reflexão em x e y
     }
}

int Ponto::cohen(Janela Clipping){
     int aux = 0;
     if(x < Clipping.xmin )
          aux += 1;
     if(x > Clipping.xmax)
          aux += 2;
     if(y < Clipping.ymin)
          aux += 4;
     if(y > Clipping.ymax)
          aux += 8;

     return aux;
}
