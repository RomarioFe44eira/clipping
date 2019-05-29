#pragma hdrstop
#include "uDisplay.h"
#include <SysUtils.hpp>
#pragma package(smart_init)

//USADO PARA MOSTRAR OS PONOTOS NA LIST BOX
void Display::mostra(TListBox* aux){
     aux->Items->Clear();
     for (unsigned int i = 0; i < poligonos.size(); i++){
          aux->Items->Add(IntToStr(poligonos[i].id));
     }
}

void Display::desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta){
     //canvas->Pen->Color = clRed;
     //ALTERA A EXPESSURA DA LINHA
     canvas->Pen->Width = 3;
     //ALTERA A COR DE FUNDO DO COMPONENTE IMAGE
     canvas->Brush->Color = clYellow;

     canvas->FillRect(Rect(0,0,500,500)); //Preenche retângulo

     //AFETA COMO É PRINTADA A LINHA NO CANVAS, USADO PARA FAZER O PLANDO CARTESIANO
     for (unsigned int i = 0; i < poligonos.size(); i++){
          if(i < 2)
               canvas->Pen->Color = clBlack;
          else
               canvas->Pen->Color = clBlue;

          poligonos[i].desenha(canvas, mundo, vp, tipoReta);
     }
}
