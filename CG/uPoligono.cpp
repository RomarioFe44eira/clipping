#pragma hdrstop
#include "uPoligono.h"
#pragma package(smart_init)
           
#define SIGN(x)  ((x) < 0 ?(-1):(1))
#define ABS(x)   ((x) < 0 ? (-x) : (x))
#define FLOOR(x) ((x) < 0 ?((x) - (int)(x) != 0 ? ((int)(x)-1) : ((int)(x))):(int)(x))

#include <math.h>

#define PI 3.14159265359

#define NORMAL 0
#define HOMOGENEA 1

void Poligono::mostra(TListBox* aux){
     aux->Items->Clear();
     for (unsigned int i = 0; i < pontos.size(); i++){
          aux->Items->Add(pontos[i].toString());
     }
}


void Poligono::desenhaBresham(TCanvas* canvas, Janela mundo, Janela vp){

     for (unsigned int i = 0; i < pontos.size()-1; i++){
          double x1, y1, x2, y2;
          x1 = pontos[i].Xw2Vp(mundo, vp);
          y1 = pontos[i].Yw2Vp(mundo, vp);
          x2 = pontos[i+1].Xw2Vp(mundo, vp);
          y2 = pontos[i+1].Yw2Vp(mundo, vp);


          double deltax = ABS((x2-x1));
          double deltay = ABS((y2-y1));
          double signalx = SIGN((x2-x1));
          double signaly = SIGN((y2-y1));

          int x = x1;
          int y = y1;

          if(signalx < 0)
	          x -= 1;
          if(signaly < 0)
	          y -= 1;

          //Trocar deltax com deltay dependendo da inclinação da reta
          bool interchange = FALSE;

          if(deltay > deltax){
	          int tmp = deltax;
          	deltax = deltay;
	          deltay = tmp;
     	     interchange = TRUE;
          }
          int erro = 2 * deltay - deltax;

          for(unsigned int i=0; i < deltax; i++){
	          //DesenhaPonto(x, y, cor);

               canvas->Pen->Color = clSilver;
               canvas->Ellipse(FLOOR(x-1), FLOOR(y-1), FLOOR(x+1), FLOOR(y+1));

     	     while(erro >= 0){
	          	if(interchange)
			          x = x + signalx;
		          else
			          y = y + signaly;
     	          erro = erro - 2 * deltax;
	          }// End while

	          if(interchange)
		          y = y + signaly;
     	     else
	     	     x = x + signalx;
	          erro = erro + 2 * deltay;
          }//End For
     }
}


void Poligono::desenhaDDA(TCanvas* canvas, Janela mundo, Janela vp){
     double x, y, x1, y1, x2, y2,
          deltax, deltay, length;
          for (unsigned int i = 0; i < pontos.size()-1; i++){
          x1 = pontos[i].Xw2Vp(mundo, vp);
          y1 = pontos[i].Yw2Vp(mundo, vp);
          x2 = pontos[i+1].Xw2Vp(mundo, vp);
          y2 = pontos[i+1].Yw2Vp(mundo, vp);

          //INICIO DDA
          if(ABS((x2-x1)) >= ABS((y2-y1)))
	          length = ABS((x2-x1));
          else
	     length = ABS((y2-y1));

          deltax = ((float)(x2-x1))/(float)length;
          deltay = ((float)(y2-y1))/(float)length;

          x = x1 + 0.5 * SIGN(deltax);
          y = y1 + 0.5 * SIGN(deltay);


          for(unsigned int i =0; i < length; i++){
               canvas -> Pen -> Color = clGreen;
               canvas -> Ellipse(FLOOR(x)-1, FLOOR(y)-1, FLOOR(x)+1, FLOOR(y)+1);
	          x += deltax;
     	     y += deltay;
          }
          //FIM DDA

     }

}

void Poligono::desenhaMoveTo(TCanvas* canvas, Janela mundo, Janela vp){
     int xvp, yvp;
     for (unsigned int i = 0; i < pontos.size(); i++){
          xvp = pontos[i].Xw2Vp(mundo, vp);
          yvp = pontos[i].Yw2Vp(mundo, vp);
     if (i==0)
          canvas->MoveTo(xvp, yvp);
     else
          canvas->LineTo(xvp, yvp);
     }
}

void Poligono::desenha(TCanvas* canvas, Janela mundo, Janela vp, int tipoReta){
     switch(tipoReta){
          case 0: desenhaDDA(canvas, mundo, vp); break;
          case 1: desenhaBresham(canvas, mundo, vp); break;
          case 2: desenhaMoveTo(canvas, mundo, vp); break;
     }
}

void Poligono::translacao(float dx, float dy){
     for (unsigned int i = 0; i < pontos.size(); i++){
       pontos[i].translacao(dx, dy);
     }
}

void Poligono::escalonamento(float sx, float sy){

     for (unsigned int i = 0; i < pontos.size(); i++){
          pontos[i].escalonamento(sx, sy);
     }


}

void Poligono::rotacionar(float angulo, int tipo){

     if(tipo == NORMAL){
          //Rotaciona Normal
          for(unsigned int i = 0; i < pontos.size(); i++){
               pontos[i].rotacionar(angulo);
          }
     }
     else{
          //Rotaciona Homogenea.
          double sx = pontoMedio().x;
          double sy = pontoMedio().y;
          double rad = ((angulo * PI)/180);
          double aux;

          double matResult[3][3]={0,0,0,0,0,0,0,0,0};
          double matA[3][3]={1,0,0,0,1,0,-1*sx,-1*sy,1};
          double matB[3][3]={cos(rad),sin(rad),0,-1*sin(rad),cos(rad),0,0,0,1};
          double matC[3][3]={1,0,0,0,1,0,sx,sy,1};

          produtoMatriz(matResult,matA,matB);
          produtoMatriz(matResult,matResult,matC);

          for(unsigned int i = 0;i< pontos.size();i++){
               aux=pontos[i].x;
               pontos[i].x=aux * matResult[0][0]+pontos[i].y * matResult[1][0] + matResult[2][0];
               pontos[i].y=aux * matResult[0][1]+pontos[i].y * matResult[1][1] + matResult[2][1];
          }
     }
}


void Poligono::reflexao(int quadrante, int tipo){
     switch(tipo){
          case 0:
               for(unsigned int i = 0; i < pontos.size(); i++){
                    pontos[i].reflexao(pontos[i].x, pontos[i].y, quadrante);
               }
          break;
          case 1:
               double sx = pontoMedio().x;
               double sy = pontoMedio().y;
               double aux;
               double matResult[3][3]={0,0,0,0,0,0,0,0,0};
               double matA[3][3]={1,0,0,0,1,0,-sx,-sy,1};
               double matB[3][3] ={-1,0,0,0,1,0,0,0,1};

               //double matB[3][3]={-1,0,0,0,-1,0,0,0,1};
               //double matB[3][3]={-1,0,0,0,1,0,0,0,1};

               double matC[3][3]={1,0,0,0,1,0,sx,sy,1};
               produtoMatriz(matResult,matA,matB);
               produtoMatriz(matResult,matResult,matC);

               for(unsigned int i = 0;i< pontos.size();i++){
                    aux=pontos[i].x;
                    pontos[i].x=aux * matResult[0][0]+pontos[i].y * matResult[1][0] + matResult[2][0];
                    pontos[i].y=aux * matResult[0][1]+pontos[i].y * matResult[1][1] + matResult[2][1];
               }
          break;
     }
}

void Poligono::DesenhaPontoCircunferencia(float xc, float yc, float x, float y, Poligono *circ){
     circ->pontos.push_back(Ponto(xc+x, yc+y));
     circ->pontos.push_back(Ponto(xc+y, yc+x));
     circ->pontos.push_back(Ponto(xc+y, yc-x));
     circ->pontos.push_back(Ponto(xc+x, yc-y));
     circ->pontos.push_back(Ponto(xc-x, yc-y));
     circ->pontos.push_back(Ponto(xc-y, yc-x));
     circ->pontos.push_back(Ponto(xc-y, yc+x));
     circ->pontos.push_back(Ponto(xc-x, yc+y));
}

void Poligono::DesenhaCircunferencia(float xc, float yc, float r, Poligono  *circ){
	int x, y, p;
	x = 0;
	y = r;
	DesenhaPontoCircunferencia(xc, yc, x, y, circ);
	p = 1 - r;
	while(x < y){
		if(p < 0)
			x++;
		else{
			x++;
			y--;
		}
		if(p < 0)
			p += 2 * x + 1;
		else
			p += 2 * (x -y) + 1;
		DesenhaPontoCircunferencia(xc, yc, x, y, circ);
	}
}

Ponto Poligono::pontoMedio(){
    Ponto pto;
    double sx = 0, sy = 0;
    for(unsigned int i = 0;i < pontos.size();i++){
        sx+=pontos[i].x;
        sy+=pontos[i].y;
    }
    pto.x = (sx/pontos.size());
    pto.y = (sy/pontos.size());
    return pto;
}

void Poligono::produtoMatriz(double matResult[][3], double mat1[][3], double mat2[][3]){
     int i,j, k=0;

     double sum = 0;

     for(i = 0; i < 3; i++){
          for(j=0; j < 3; j++){
               for(k=0; k < 3;k++){
                    sum += mat1[i][k] * mat2[k][j];
               }
               matResult[i][j] = sum;
               sum = 0;
          }
     }
}
