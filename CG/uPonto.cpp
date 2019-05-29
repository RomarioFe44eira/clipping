//---------------------------------------------------------------------------


#pragma hdrstop

#include "uPonto.h"
#include "uJanela.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)

Ponto::Ponto (){
 x = y = 0;
}

Ponto::Ponto (double ax, double ay){
 x = ax;
 y = ay;
}

int Ponto::Xw2Vp (Janela mundo, Janela vp){
 return (x - mundo.xmin) / (mundo.xmax - mundo.xmin) * (vp.xmax - vp.xmin);
}

int Ponto::Yw2Vp (Janela mundo, Janela vp){
 return (1 - (y - mundo.ymin) / (mundo.xmax - mundo.xmin)) * (vp.ymax - vp.ymin); 
}
