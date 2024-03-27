#include <iostream>
#include <cstdlib>
using namespace std;

void poczatek() // wyswietla poczatkowy napis i plansze do gry
{
    int T[3][3]={{1,4,7},{2,5,8},{3,6,9}};
    cout<<endl;
    cout<<"***************"<<endl; 
    cout<<"Kolko i Krzyzyk"<<endl; 
    cout<<"***************"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Plansza sklada sie z 9 pol ponumerowanych"<<endl;
    cout<<"wedlug schematu ponizej:"<<endl;
    cout<<endl;
    cout<<endl;
    for (int i = 0; i < 3; i++)
    {
        if(i>0) cout<<"-------------"<<endl;
        for (int j = 0; j < 3; j++)
        {
            if(j<2) cout<<" "<<T[i][j]<<" | ";
            if(j==2) cout<<" "<<T[i][j]<<endl;
        }
    }
}
//losowanie kolejki przez rzut moneta, zwraca wylosowanego gracza
void losowanie_kolejki(string& wyl,int& kol,string g1, string g2,bool& czy_poprawna_nazwa)
{
    int orzel, reszka,wybor;
    string a,gracz;
    bool strona_monety;
    srand(time(NULL));
    int moneta = rand()%2+1;
    if(moneta==1) a="orzel";
    if(moneta==2) a="reszka";
    cout<<"Losujacy gracz: ";
    cin>>gracz;
    cout<<endl;
    cout<<"Wybierz strone monety: "<<endl;
    cout<<endl;
    if(gracz==g1 || gracz==g2) czy_poprawna_nazwa=true;
    else czy_poprawna_nazwa=false;
    if(czy_poprawna_nazwa==true){
        do{
    cout<<"1. Wybierz orla"<<endl;
    cout<<"2. Wybierz reszke"<<endl;
    cout<<"Wybor: ";
    cin>>wybor;
    if(wybor==1) cout<<"Wybrano orla"<<endl;
    if(wybor==2) cout<<"Wybrano reszke"<<endl;
    cout<<endl;
    if(wybor==1 || wybor==2){
        strona_monety=true;
    cout<<"wylosowana strona monety : "<<a<<endl;
    cout<<endl;
    if(moneta==wybor) {
        cout<<gracz<<" zaczynasz!"<<endl;
        wyl=gracz;
        if (wyl==g1)
        {
            kol=0;
        }
        else if(wyl==g2)
        {
            kol=1;
        }
        
    }
    else{
        if(gracz==g1){ 
            cout<<"Zaczyna "<<g2<<endl;
            wyl=g2;
            kol=1;
        }
        if(gracz==g2){
            cout<<"Zaczyna "<<g1<<endl;
            wyl=g1;
            kol=0;
        }
    }
  }
  else{
    cout<<"Nie ma takiej opcji :(, sprobuj ponownie"<<endl;
    strona_monety=false;
  }
    }while(strona_monety==false);
    }
    else{
        cout<<"Niepoprawna nazwa gracza, sprobuj ponownie"<<endl;
    }
  cout<<endl;
}
//wypelnianie planszy
void wybor_pola(string g1,string g2, int& k, string (&T)[3][3],bool wygrana,int& nrkolejki,string x,string x2){
    int wybor;
    bool znak; 
if(wygrana==false){
    if(k==0){
        cout<<g1<<", wybierz numer pola od 1 do 9"<<endl;
        cout<<endl;
        cout<<"Pole nr. ";
    cin>>wybor;
    }
    else if(k==1){
        cout<<g2<<", wybierz numer pola od 1 do 9"<<endl;
        cout<<endl;
        cout<<"Pole nr. ";
    cin>>wybor;
    }
    switch(wybor){     
case 1:
         if(T[0][0]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;         
            k=1;
        }
        else if(T[0][0]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;        
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            bool czy_dobre_pole=true;
        while(T[0][0]==" "){
                cout<<endl;
                if(k==0) T[0][0]=x;
                else T[0][0]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 2:
         if(T[1][0]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;         
            k=1;
        }
        else if(T[1][0]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;          
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[1][0]==" "){
                cout<<endl;
                if(k==0) T[1][0]=x;
                else T[1][0]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 3:
        if(T[2][0]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;          
            k=1;
        }
        else if(T[2][0]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;        
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[2][0]==" "){
            cout<<endl;
                if(k==0) T[2][0]=x;
                else T[2][0]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 4:
        if(T[0][1]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;
            k=1;
        }
        else if(T[0][1]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;  
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[0][1]==" "){
             cout<<endl;
                if(k==0) T[0][1]=x;
                else T[0][1]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 5:
        if(T[1][1]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;           
            k=1;
        }
        else if(T[1][1]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;          
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
        while(T[1][1]==" "){
            cout<<endl;
                if(k==0) T[1][1]=x;
                else T[1][1]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 6:
        if(T[2][1]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;
            k=1;
        }
        else if(T[2][1]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[2][1]==" "){
              cout<<endl;
                if(k==0) T[2][1]=x;
                else T[2][1]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 7:
if(T[0][2]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;
            
            k=1;
        }
        else if(T[0][2]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;
            
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[0][2]==" "){
             cout<<endl;
                if(k==0) T[0][2]=x;
                else T[0][2]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 8:
if(T[1][2]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;
            
            k=1;
        }
        else if(T[1][2]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;
            
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[1][2]==" "){
               cout<<endl;
                if(k==0) T[1][2]=x;
                else T[1][2]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
case 9:
if(T[2][2]!=" " && k==0){
            cout<<"To pole jest juz zapelnione"<<endl;
            
            k=1;
        }
        else if(T[2][2]!=" " && k==1){
            cout<<"To pole jest juz zapelnione"<<endl;
            
            k=0;
        }
        else{
            nrkolejki++;
            bool wykonane=false;
            
        while(T[2][2]==" "){
               cout<<endl;
                if(k==0) T[2][2]=x;
                else T[2][2]=x2;
                wykonane=true;
        cout<<endl;
        }
          if(wykonane==true){
            for(int m=0;m<3;m++){
                if(m>0){ 
            cout<<"-----------"<<endl;
            }
            for(int a=0;a<3;a++){
            if(a<2) cout<<" "<<T[m][a]<<" |";
            if(a==2) cout<<" "<<T[m][a]<<endl;
            }
            }
            cout<<endl;
        }
        }
        break;
default:
if(k==0){
    cout<<endl;
    cout<<"no przeciez nie ma takiego pola xd jeszcze raz"<<endl;
    cout<<endl;
    k=1;
}
else if(k==1){
    cout<<endl;
    cout<<"no przeciez nie ma takiego pola xd jeszcze raz"<<endl;
    cout<<endl;
    k=0;
}
break;
    }
    if(k==0){
    k=1;
    }
    else if(k==1){
    k=0;
    }
}
}
bool wygrana(string (&T)[3][3]){
int i=0,j=0;
        if(T[i][j]==T[i][j+1] && T[i][j]==T[i][j+2] && T[i][j]!=" ") return true;//1 wiersz taka sama
        if(T[i][j]==T[i+1][j] && T[i][j]==T[i+2][j] && T[i][j]!=" ") return true;//1 kolumna taki sam
        if(T[i][j]==T[i+1][j+1] && T[i][j]==T[i+2][j+2]&&T[i][j]!=" ") return true;//przekatna L-P taka sama
        if(T[i][j+1]==T[i+1][j+1] && T[i][j+1]==T[i+2][j+1] && T[i][j+1]!=" ") return true;//2 kolumna taka sama
        if(T[i][j+2]==T[i+1][j+2] && T[i][j+2]==T[i+2][j+2]&& T[i][j+2]!=" ") return true;//3 kolumna taka sama
        if(T[i][j+2]==T[i+1][j+1] && T[i][j+2]==T[i+2][j]&& T[i][j+2]!=" ") return true;//przekatna P-L taka sama
        if(T[i+1][j]==T[i+1][j+1] && T[i+1][j]==T[i+1][j+2]&&T[i+1][j]!=" ") return true;//2 wiersz taki sam
        if(T[i+2][j]==T[i+2][j+1] && T[i+2][j]==T[i+2][j+2]&&T[i+2][j]!=" ") return true;//3 wiersz taki sam
return false;
}
int main(){
    int k, x=0;
    string gracz1, gracz2,wyl,znak,znak2; 
    string T[3][3]={{" "," "," "},{" "," "," "},{" "," "," "}};
    bool y;
    bool poprawna_opcja;
    poczatek();
    cout<<endl;
    cout<<"Nazwa gracza 1: ";
    cin>>gracz1;
    cout<<"Nazwa gracza 2: ";
    cin>>gracz2;
    cout<<endl;
    cout<<"Losowanie kolejki monetą"<<endl;
    cout<<endl;
    do{
    losowanie_kolejki(wyl,k,gracz1,gracz2,y);
    }while(y==false);
    cout<<"Wybierz jakim znakiem chcesz grac: "<<endl;
    do{
    cout<<"kolko ( O )"<<endl;
    cout<<"krzyzyk ( X )"<<endl;
    cout<<endl;
    cout<<"Wybor: ";
    cin>>znak;
    cout<<endl;
    if(znak=="X") {
        poprawna_opcja=true;
    }
    else if(znak=="O"){ 
        poprawna_opcja=true;
    }
    else{
        cout<<"Nie ma takiej opcji, wybierz 1 lub 2 :D"<<endl;
        poprawna_opcja=false;
    }
    cout<<endl;
    }while(poprawna_opcja==false);
if(wyl==gracz1 && znak=="X"){
        znak2="O";
    }
else if(wyl==gracz1 && znak=="O"){
    znak2="X";
}
if(wyl==gracz2 && znak=="X"){
        znak2="X";
        znak="O";
    }
else if(wyl==gracz2 && znak=="O"){
    znak2="O";
    znak="X";
}
cout<<gracz1<<": "<<znak<<"         "<<gracz2<<": "<<znak2<<endl;
    cout<<endl;
    cout<<"Udanej gry!!!"<<endl;
    cout<<endl;
    do{
    wybor_pola(gracz1,gracz2,k,T,wygrana(T),x,znak,znak2);
    }while(wygrana(T)!=true&&x<9);
    if(wygrana(T)==true){
    if(k==1) cout<<"Wygrywa "<<gracz1<<endl;
    else if(k==0) cout<<"Wygrywa "<<gracz2<<endl;
    }
    else{
        cout<<"Remis!!!"<<endl;
    }
    cout<<endl; //odstep
    cout<<endl; //odstep
    return 0;
}