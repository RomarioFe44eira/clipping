//---------------------------------------------------------------------------

#ifndef uPontoH
#define uPontoH

//---------------------------------------------------------------------------
class Ponto{
 public:
  double x;
  double y;

  Ponto();
  Ponto (double ax, double ay);
  int Xw2Vp(Janela mundo, Janela vp);
  int Yw2Vp(Janela mundo, Janela vp);
};
#endif
