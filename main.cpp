#include <iostream>
#include <Windows.h>
#include <cmath>
#include <cstdlib>

#define DIM 10
#define maxD 3
using namespace std;

void azzeraVet(int R[]){
    for(int i=0;i<10;i++){
        R[i] = 0;
    }
}

void provaColori(){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    for(int k = 1; k < 255; k++){
        SetConsoleTextAttribute(h, k);
        cout << k << " I want to be nice today!" << endl;
    }
}

void stampaColorato(int color, int num){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    cout<<num;
    SetConsoleTextAttribute(h, 7);

}

void stampaStringaColorato(int color, string text){
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
    cout<<text;
    SetConsoleTextAttribute(h, 7);

}

void visualizzaMat(int M[10][DIM], int c, int R[]){
    int C[maxD],p,m;
    for(int i=0;i<10;i++){
        cout<<i<<": ";
        for(int j=0;j<R[i];j++){
            if(M[i][j]==0){
                continue;
            }
            for(int k=maxD-1;k>=0;k--){
                p = pow(10,k+1);
                m = pow(10,k);
                C[k] = (M[i][j]%p)/m;
                if(k==c){
                    stampaColorato(4,C[k]);
                } else {
                    stampaColorato(7,C[k]);
                }
            }
            cout<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

void generaNumeri(int V[]){
    for(int i=0;i<DIM;i++){
        V[i] = rand() % 899 + 100;
    }
}

void visualizza(int V[], int c){
    int C[maxD],p,m;
    for(int i=0;i<DIM;i++){
        if(V[i]==0){
            cout<<" ";
            continue;
        }
        for(int j=maxD-1;j>=0;j--){
            p = pow(10,j+1);
            m = pow(10,j);
            C[j] = (V[i]%p)/m;
            if(j==c){
                stampaColorato(4,C[j]);
            } else if(c==maxD+1){
                stampaColorato(10,C[j]);
            } else {
                stampaColorato(7,C[j]);
            }
        }
        cout<<" ";
    }
    cout<<endl;
}

void azzeraMat(int M[10][DIM]){
    for(int i=0;i<10;i++){
        for(int j=0;j<DIM;j++){
            M[i][j] = 0;
        }
    }
}

void visualizzaSelect(int V[], int c, int x){
    int C[maxD],p,m;
    for(int i=0;i<DIM;i++){
        if(i==x){
            cout<<"[";
        }
        for(int j=maxD-1;j>=0;j--){
            p = pow(10,j+1);
            m = pow(10,j);
            C[j] = (V[i]%p)/m;
            if(j==c){
                stampaColorato(4,C[j]);
            } else if(c==maxD+1){
                stampaColorato(10,C[j]);
            } else {
                stampaColorato(7,C[j]);
            }
        }
        if(i==x){
            cout<<"]";
        }
        cout<<" ";
    }
    cout<<endl;
}

void accatasta(int V[], int M[10][DIM], int R[], int k){
    int p,m,temp;
    for(int l=0;l<DIM;l++){
        p = pow(10,k+1);
        m = pow(10,k);
        temp = (V[l]%p)/m;
        M[temp][R[temp]] = V[l];
        R[temp]++;
        stampaStringaColorato(6,"Step n ");
        stampaColorato(6,l);
        cout<<" V: ";
        visualizzaSelect(V,k,l);
        cout<<endl;
        visualizzaMat(M,k,R);
        system("pause");
        system("cls");
    }
}

void riposiziona(int V[], int M[10][DIM], int R[], int c){
    int cont = 0;
    azzeraVet(V);
    for(int i=0;i<10;i++){
        for(int j=0;j<R[i];j++){
            stampaStringaColorato(6,"Step n ");
            stampaColorato(6,cont);
            cout<<" V: ";
            V[cont]=M[i][j];
            M[i][j]=0;
            cont++;
            visualizza(V,c);
            visualizzaMat(M,c,R);
            system("pause");
            system("cls");
        }
    }
}

void radixSort(int V[]){
    int M[10][DIM]; int R[10]; string pos[3] = {"unita'","decine","centinaia"};
    for(int k=0;k<maxD;k++){
        stampaStringaColorato(249,"Ora analizziamo ed ordiniamo le "+pos[k]+" \n");
        system("pause");
        azzeraVet(R);
        azzeraMat(M);
        accatasta(V,M,R,k);
        stampaStringaColorato(249,"Ora riposizioniamo i numeri: \n");
        riposiziona(V,M,R,k);
        stampaStringaColorato(249,"Ordine numeri al ");
        stampaColorato(249,k+1);
        stampaStringaColorato(249," giro: \n");
        visualizza(V,k);
        system("pause");
        system("cls");
    }
}

int main()
{
    int V[DIM];
    stampaStringaColorato(253,"Generiamo i numeri del vettore da mettere in ordine: \n");
    generaNumeri(V);
    visualizza(V,4);
    radixSort(V);
    stampaStringaColorato(253,"Ecco i numeri finali: \n");
    visualizza(V,4);
    return 0;
}
