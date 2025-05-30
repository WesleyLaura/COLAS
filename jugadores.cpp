//juego con varios jugadores, cada jugador tendra turno
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
		void mostrarCola();
		void  jugadores();
			
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
		cout<<"----------------------------------"<<endl;
		cout<<"|Agregado correctamente a la COLA|\n";
		cout<<"----------------------------------"<<endl;
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

//mostrar todo los elementos de la cola
void Cola::mostrarCola(){
	if(colaVacia()){
		cout<<"COLA VACIA\n";
	}else{
		for(int i=frente;i<=final;i++){
			cout<<elementos[i]<<" ,";
		}
		cout<<"\n";
	}
}




void Cola::jugadores(){
	while(!colaVacia()){
		string jugador=eliminarCola();
		char op;
		cout<<"JUGADOR "<<jugador<<" quieres retirarte (R) o seguir(S): ";
		cin>>op;
		if(op=='s' || op=='S'){
			insertarCola(jugador);
		}
	}
		cout<<"No quedan mas jugadores\n";
}

void menu(){
	Cola cola1, jugadores1;
	string dato;
	int op;
	
	do{
		system("cls");
		cout<<"--------------------------"<<endl
			<<"|\tMENU DEL JUEGO   |"<<endl
			<<"--------------------------"<<endl
			<<"1.- Insertar jugadores en la Cola"<<endl
			<<"2.- MOSTRAR JUGADORES"<<endl
			<<"3.- JUEGO DE JUGADORES"<<endl
			<<"0.- SALIR"<<endl;
		cout<<"Seleccione una opcion: "; cin>>op;
			cin.ignore();
			switch(op){
				case 1:
					system("cls");
					cout<<"Ingrese el nombre del jugador: ";
					getline(cin,dato);
					jugadores1.insertarCola(dato);
					system("pause");
					break;
				case 2:
					system("cls");
					cout<<"\n\tNOMBRE DE LOS JUGADORES\n";
					jugadores1.mostrarCola();
					system("pause");
					break;
				case 3:
					system("cls");	
					jugadores1.jugadores(); //funcion del juego
					break;
					system("pause");system("pause");
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
