//---------------------------------------------------------------------------

#ifndef uFormPrincipalH
#define uFormPrincipalH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TImage *Image1;
        TLabel *Label1;
        TLabel *Label2;
        TButton *btnNovoPoligono;
        TListBox *ListBox1;
        TButton *btnMosta;
        TListBox *ListBox2;
        TRadioGroup *Linhas;
        TButton *btnTranslacao;
        TEdit *Edit1;
        TEdit *Edit2;
        TButton *btnEscalonamento;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TTabSheet *TabSheet3;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TEdit *edXmin;
        TEdit *edXmax;
        TEdit *edYmin;
        TEdit *edYmax;
        TButton *btnAtualizaMundo;
        TLabel *Label7;
        TButton *btnDireita;
        TButton *btnBaixo;
        TButton *btnCima;
        TButton *btnEsquerda;
        TButton *btnReset;
        TButton *btnMoreZoom;
        TButton *btnLessZoom;
        TEdit *edZoom;
        void __fastcall Image1MouseMove(TObject *Sender, TShiftState Shift,
          int X, int Y);
        void __fastcall btnMostaClick(TObject *Sender);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall btnNovoPoligonoClick(TObject *Sender);
        void __fastcall Image1MouseDown(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall btnAtualizaMundoClick(TObject *Sender);
        void __fastcall btnTranslacaoClick(TObject *Sender);
        void __fastcall btnEscalonamentoClick(TObject *Sender);
        void __fastcall btnEsquerdaClick(TObject *Sender);
        void __fastcall btnDireitaClick(TObject *Sender);
        void __fastcall btnBaixoClick(TObject *Sender);
        void __fastcall btnCimaClick(TObject *Sender);
        void __fastcall btnResetClick(TObject *Sender);
        void __fastcall btnMoreZoomClick(TObject *Sender);
        void __fastcall btnLessZoomClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
