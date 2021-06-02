#include <iostream>
#include <Windows.h>
#include <cmath>
#include <cstdlib>

#define DIM 7
#define maxD 3
using namespace std;

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

void generaNumeri(int V[]){
    for(int i=0;i<DIM;i++){
        V[i] = rand() % 899 + 100;
    }
}

void visualizza(int V[], int c){
    int C[maxD],p,m;
    for(int i=0;i<DIM;i++){
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
}

void azzeraMat(int M[10][DIM]){
    for(int i=0;i<10;i++){
        for(int j=0;j<DIM;j++){
            M[i][j] = 0;
        }
    }
}

void accatasta(int V[], int M[10][DIM], int R[], int k){

}

void riposiziona(int V[], int M[10][DIM], int R[]){

}

void visualizzaMat(int M[10][DIM], int c, int R[]){
    int C[maxD],p,m;
    for(int i=0;i<10;i++){
        cout<<i<<": ";
        for(int j=0;j<R[i];j++){
            for(int k=maxD-1;k>=0;k--){
                p = pow(10,k+1);
                m = pow(10,k);
                C[j] = (M[i][j]%p)/m;
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
}

void azzeraVet(int R[]){
    for(int i=0;i<10;i++){
        R[i] = 0;
    }
}

void radixSort(int V[]){
    int M[10][DIM]; int R[10];
    for(int k=0;k<maxD;k++){
        azzeraVet(R);
        azzeraMat(M);
        accatasta(V,M,R,k);
        visualizzaMat(M,k,R);
        riposiziona(V,M,R);
    }
}

int main()
{
    int V[DIM];
    generaNumeri(V);
    return 0;
}
