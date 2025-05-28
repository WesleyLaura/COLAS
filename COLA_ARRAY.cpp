#include <iostream>
#include <string>
#define MAX 10  // tamanio maximoi de la cola
using namespace std;
class Cola{
	private:
		string elementos[MAX];
		int frente;
		int final;
	public:
		Cola();
		
		bool colaVacia();
		bool colaLlena();
		void insertarCola(string dato);
		string eliminarCola();
		string verFrente();
		void mostraCola();
		int contarElementos();
		bool buscarElemento(string dato);
			
};

//constructor : Inicializa la cola vacia
Cola::Cola(){
	frente=-1;
	final=-1;
}

// verifica si la cola esta vacia
bool Cola::colaVacia(){
	if(frente==-1){
		return true;
	}else{
		return false;
	}
}

//verifica si la cola esta llena

bool  Cola::colaLlena(){
	if(final==MAX-1){
		return true;
	}else{
		return false;
	}
}

//agregar un elemento en la cola
void Cola::insertarCola(string dato){
	if(!colaLlena()){
		if(colaVacia()){
			frente=0;
			final=0;	
		}else{
			final++;
		}
		elementos[final]=dato;
		cout<<"Agregado correctamente a la COLA\n";
	}else{
		cout<<"Desbordamiento - Cola esta llena\n";
		return;
	}
}

//eliminar un elemento de cola
string Cola::eliminarCola(){
	string dato=elementos[frente];
	if(!colaVacia()){
		if(final==frente){
			final=-1;
			frente=-1;
		}else{
			frente++;
		}
	}else{
		cout<<"Subdesbordamiento - COLA VACIA\n";
	}
	return dato;
}

void menu(){
	Cola cola1;
	string dato;
	int op;
	
	do{
		cout<<"\t---MENU DE COLA-----"<<endl
			<<"1.- Insertar elemento en la cola"<<endl
			<<"2.- Eliminar elemento en la cola"<<endl
			<<"3.- Ver frente"<<endl
			<<"4.- Mostrar COLA"<<endl
			<<"5.- Contar elementos"<<endl
			<<"0.- SALIR"<<endl;
		cout<<"Seleccione una opcion: "; cin>>op;
			cin.ignore();
			switch(op){
				
				case 1:
					cout<<"Ingrese el dato que desea ingresar: ";
					getline(cin,dato);
					cola1.insertarCola(dato);
					break;
				case 2:
					cola1.eliminarCola();
					break;
				case 3:
					//
					break;
				case 4:
					//mostrar
					break;
				case 5:
					//contar
					break;
				case 0:
					cout<<"Finalizar programa...\n";
					break;
				default:
					cout<<"Opcion invalida\n";						
			}
	}while(op !=0);
}

int main(){
	menu();
	return 0;
}