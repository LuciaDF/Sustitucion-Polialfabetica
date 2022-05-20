#include <iostream>

using namespace std;


char Alf[28]="ABCDEFGHIJKLMNOPQRSTUVWXYZ\0";

const int n=27;

struct PoliAlf
{
    char *mens;
    char *clave;
    char *res;
    int m;
    int d;
    
}pn1,pn2;

int BusquedaNum(char x);
void Mayuscula(char x[]);
char *ConvertirCadena(int tam);
char BusquedaLet(int y);
char* PoliAlfC(PoliAlf p3,int (*p5)(int,int));
int ModJusto2(int y, int n);
void p_cd(PoliAlf p1,int (*p6)(int,int),char enun[]);
void LimpiarArray(PoliAlf);
int Suma(int a,int b);
int Resta(int a,int b);

int Tam(char *p);


void menu();

int main(int argc, const char * argv[])
{
    
    menu();
    
 
    return 0;
}

int Suma(int a,int b)
{
    return a+b;
}

int Resta(int a,int b)
{
    return a-b;
    
}
int Tam(char *p)
{
    int r=0;
    for(char *q=p;*q;q++)
    {
        r++;
    }
    return r;
}
void menu()
{
    int op;
    int (*p2[2])(int,int)={Suma,Resta};
    
    char enun[2][40]={"--------CIFRAR----------","--------DESCIFRAR----------"};
    
    cout<<"--------MENU - SUSTITUCION POLI-ALFABETICA--------"<<endl;
    cout<<"1.- Cifrar palabra."<<endl;
    cout<<"2.- Descifrar con clave."<<endl;
    cout<<"3.- Salir."<<endl;
    cout<<"Opcion?: ";cin>>op;
    
    if (op==3)
    {
        exit(1);
    }
    else
    {
        p_cd(pn1, *(p2+(op-1)),*(enun+(op-1)));
    }
   
}

void LimpiarArray(char *p)
{
    delete []p;
    
    
    cout<<"limpiado!"<<endl;
    
    
}

void p_cd(PoliAlf p1,int (*p6)(int,int),char enun[])
{
    p1.mens=ConvertirCadena(p1.m);
    p1.clave=ConvertirCadena(p1.d);
    
    cout<<enun<<endl;
    fflush(stdin);
    cout<<"Digite palabra: ";cin>>p1.mens;
    fflush(stdin);
    cout<<"Digite clave a cifrar: ";cin>>p1.clave;
    fflush(stdin);
    
    
    p1.m=Tam(p1.mens);
    p1.d=Tam(p1.clave);
    
    cout<<p1.m<<endl;
    cout<<p1.d<<endl;
    Mayuscula(p1.mens);
    Mayuscula(p1.clave);
    
    p1.res=PoliAlfC(p1,p6);
    
    LimpiarArray(p1.res);
    LimpiarArray(p1.clave);
    
    menu();
}


char *ConvertirCadena(int tam)
{
    char *p;
    p=new char[tam];
    
    return p;
}


void Mayuscula(char x[]) // Si el usuario lo escriba en conbinacion de mayus y minus la funcion ayuda con ese problema.
{
    for(char *p=x;*p;p++)
    {
        if(*p>=97 and *p<=122)
        {
            *p-=32;
        }
        cout<<*p<<" ";
    }
    //cout<<endl;
}

int BusquedaNum(char x)
{
    int i=0;
   
    for (char *p=Alf;*p;p++)
    {
            //cout<<*p<<endl;
        if (*p=='O')
        {
                //cout<<*p<<endl;
            i++;
                
        }
        if (*p==x)
        {
                //cout<<*p<<endl;
            return i;
        }
        else
        {
            i++;
        }
            
        
    }
    
    
    return 14; // si es ñ
    
    
}

char BusquedaLet(int y)
{
    char *q=Alf;
    for(int i=0;i<n;i++)
    {
        if(y==i)
        {
           if (i==14)
           {
               //cout<<abc[i]<<"* ";
               return (char)165;
           }
           else
           {
               if(i>=15)
               {
                   i--;
                   //cout<<abc[i]<<" ";
                   return Alf[i];
               }
               //cout<<abc[i]<<" ";
               return Alf[i];
           }
        }
        
    
    }
    
    return '0';
}

char* PoliAlfC(PoliAlf p3,int (*p5)(int,int))
{
    char *p=new char [p3.m];
    cout<<"Tam: "<<p3.m<<endl;
    char *p1=p;
    char *r=p3.clave;
    int i=0;
    int x;
    int k;
    char *q=p3.mens;
    *(p+p3.m)='\0';
    for (;*p,i<p3.m;q++,p1++,i++)
    {
       
   
        x=BusquedaNum(*q);
        k=BusquedaNum(*(r+ModJusto2(i, p3.d)));
            
        *p1=BusquedaLet(ModJusto2(p5(x,k), n));
        
        cout<<x<<" + "<<k<<" = "<<*p1<<endl;
       
       

    }
    
    
    cout<<p<<endl;
    
    return p;
}


int ModJusto2(int y, int n)
{
    int y1;
    if (y>=0 and y<n)
    {
        return y;
    }
    else if (y>=n)
    {
        y1=y-n;
        return ModJusto2(y1,n);
    }
    else if (y<0)
    {
        y1=y+n;
        return ModJusto2(y1, n);
    }
    return 28;
}

