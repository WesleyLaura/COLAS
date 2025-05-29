//problema para vaciar cola con prioridades de forma correcta
#include <iostream>
#define MAX 10
using namespace std;

class Cola{
	private:
		string elementos[MAX];
		int frente;
		int final;
	public:
		Cola();	
		void insertaCola(string dato);
		bool colaVacia();
		bool colaLlena();
		string sacarCola();
		void mostrarCola();
		void vaciarCola(Cola& destino);
	
	
};
//constructor
Cola::Cola(){
	frente=-1;
	final=-1;
}

bool Cola::colaVacia(){
	if(frente==-1){
		return true;
	}else{
		return false;
	}
}

bool Cola::colaLlena(){
	if(final==MAX-1){
		return true;
	}else{
		return false;
	}
}
//para insertar en cada cola
void Cola::insertaCola(string dato){
	if(!colaLlena()){
		if(colaVacia()){
			final=0;
			frente=0;
		}else{
			final++;
		}
		elementos[final]=dato;
	}else{
		cout<<"Desbordamiento COLA-LLENAn";
	}
	
}

string Cola::sacarCola(){
	string dato=elementos[frente];
	if(!colaVacia()){
		if(final==frente){
			final=-1;
			frente=-1;
		}else{
			frente++;
		}
		
	}else{
		cout<<"Subdesbordamiento COLA-VACIA\n";
	}
	
	return dato;
}

void Cola::mostrarCola(){
	cout<<"Elementos de la COLA: ";
	if(!colaVacia()){
		for(int i=frente; i<=final;i++){
			cout<<elementos[i]<<" ,";
		}
		cout<<"\n";
	}else{
		cout<<"Cola vacia\n";
	}
}

void Cola::vaciarCola(Cola& destino) {
    while (!colaVacia()) {
        destino.insertaCola(sacarCola());
    }
}




void menu(){
	Cola cola1,cola2,cola3,colaFinal;
	int op,subop;
	string dato;
	do{
		cout<<"\n\t----MENU DE EVACUACION------\n"<<endl
			<<"1.- Insertar persona"<<endl
			<<"2.- Mostrar contenido de las 3 colas"<<endl
			<<"3.- Vaciar colas en orden de prioridad (Pasajeros Prioridad,Pasajeros y Tripulante)"<<endl
			<<"0.- SALIR "<<endl;
		cout<<"Escriba la opcion: "; cin>>op;
		cin.ignore();
			switch(op){
				case 1:
					cout << "\nA que cola desea insertar?\n\n";
            		cout << "1. Pasajeros Prioritarios\n";
            		cout << "2. Pasajeros\n";
		            cout << "3. Tripulacion\n";
		            cout << "Seleccione: "; cin >> subop;
		            cout << "Nombre de la persona: ";
		            cin.ignore();
		            getline(cin, dato);
		            if (subop == 1)
		                cola1.insertaCola(dato);
		            else if (subop == 2)
		                cola2.insertaCola(dato);
		            else if (subop == 3)
		                cola3.insertaCola(dato);
		            else
		                cout<< "Opción inválida.\n";
		            break;
				case 2:
					cout<<"\n--- Contenido de las colas ---\n";
		            cout<<"Pasajeros Prioritarios:";
		            cola1.mostrarCola();
		            cout<<"Pasajeros:";
		            cola2.mostrarCola();
		            cout<<"Tripulacion:";
		            cola3.mostrarCola();
		            break;
				case 3:
					cout<<"\n---Vaciando colas con prioridad (Pasajeros Prioridad,Pasajeros y Tripulante)---\n";
		            cola1.vaciarCola(colaFinal);
		            cola2.vaciarCola(colaFinal);
		            cola3.vaciarCola(colaFinal);
		            cout<<"Evacuacion final (orden de salida):\n";
		            colaFinal.mostrarCola();
		            break;
				case 0:
					cout<<"FINALIZAR PRGRAMA...\n";
					break;
				default:
					cout<<"OPCION INVALIDA\n";		
			}
	}while(op!=0);
}

int main(){
	menu();
	return 0;
}