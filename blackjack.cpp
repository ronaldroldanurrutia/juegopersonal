#include<iostream>
#include<windows.h>
#include<stdlib.h>
#include<stdio.h>
#include<list>


#define WIN 21

using namespace std;


int arr[13];
void formar(void){
    for(int i = 0 ; i < 13; i++){
        arr[i] = 4;

    }

}

class jugador{
    private:
        int x;
        int acumulado;
    public:
        jugador(const int x = 0,const int acumulado = 0){
            this->x = x;
            this->acumulado = acumulado;

        }
        virtual void mostrar(){
            cout<<this->x<<endl;

        }
        void insertx(const int x){
            this->x = x;

        }
        bool probar(int x){
            if(x == WIN){
                return true;
            }
            return false;

        }
        bool lose(int x){
            if(x > WIN){
                return true;
            }
            return false;

        }
        void poner(void){
            this->x = rand()%12 + 1;
            while(arr[this->x-1]==0){
                this->x = rand()%12 + 1;
            }
            arr[this->x-1]--;
            this->acumulado+=this->x;
            this->x = 0;
        }
        void mostrares(void){
            cout<<this->x<<endl;
        }

};


list<jugador*>lis;
list<jugador*>::iterator elemento;

/*virtual void jugador<T>:: mostrar(){
    cout<<this->x<<endl;

}*/

void crear (int n){

    for(int i = 0 ; i < n ;i++){
        lis.push_back(new jugador(rand()%12 + 1));

    }
    for(elemento = lis.begin() ; elemento != lis.end() ; elemento ++){
        (*elemento)->poner();
    }
    elemento = lis.begin();
    for(int i = 0 ; i < n ; i++,elemento++){
        (*elemento)->mostrares();

    }

}




int main(){
    int n;

    formar();

    cout<<"Inserte Personas: ";
    cin>>n;
    while(n > 5){
        cout<<"muchas personas inserte de nuevo"<<endl;
        cout<<"Inserte Personas: ";
        cin>>n;
    }

    crear(n);

    return 0;
}


