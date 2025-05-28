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
		void mostrarCola();
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

//mostrar todo los elementos de la cola
void Cola::mostrarCola(){
	if(colaVacia()){
		cout<<"COLA VACIA\n";
	}else{
		for(int i=frente;i<=final;i++){
			cout<<elementos[i]<<" ";
		}
		cout<<"\n";
	}
}

//ver frente de la cola (muestra el primer elemento de la cola)
string Cola::verFrente(){
	if(colaVacia()){
		cout<<"Cola vacia\n";
		return NULL;
	}else{
		return elementos[frente];
	}
}
//contar los elementos de la cola
int Cola::contarElementos(){
		return final- frente +1;
}

//busca un elemento en la cola
bool Cola::buscarElemento(string dato){
	if(!colaVacia()){
		int i=frente;
		while(i<=final){
			if(elementos[i]==dato){
				return true;
			}else{
				i++;
			}
		}
	
	}
				return false;	
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
			<<"6.- Buscar elemento en la Cola"<<endl
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
					dato=cola1.eliminarCola();
					if(dato !="")
					cout<<"Elemento eliminado "<<dato<<endl;
					break;
				case 3:
					dato=cola1.verFrente();
					if(dato !="")
					cout<<"Elemento en el frente "<<dato<<endl;
					break;
				case 4:
					cola1.mostrarCola();
					break;
				case 5:
					cout<<" Total de elementos en la cola: "<<cola1.contarElementos()<<endl;
					break;
				case 6:
					cout<<"Ingrese el dato a buscar en la cola: ";
					getline(cin,dato);
					cout<<"Esta "<<dato<<" ?: "<<(cola1.buscarElemento(dato) ? "SI":"NO")<<endl;
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