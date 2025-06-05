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
		void invertirCola();
		void eliminarElementoCola(string dato);
			
};

class Pila{
	private:
		string elementos[MAX];
		int tope;
	public:
		Pila();
		
		void insertarPila(string dato);
		string sacarPila();
		bool pilaLlena();
		bool pilaVacia();
			
};

// constructor de la Pila
Pila::Pila(){
	tope=-1;
}
//pila Llena
bool Pila::pilaLlena(){
	if(tope==MAX-1){
		return true;
	}else{
		return false;
	}
}

//pila vacia
bool Pila::pilaVacia(){
	if(tope==-1){
		return true;
	}else{
		return false;
	}
}

//insertar elemento en la Pila
void Pila::insertarPila(string dato){
	if(!pilaLlena()){
		tope++;
		elementos[tope]=dato;
	}else{
		cout<<"COLA LLENA\n";
		return;
	}
}

//metodo para sacar elemento de la pila

string Pila::sacarPila(){
	if(pilaVacia()){
		cout<<"PILA VACIA\n";
		return(0);
	}else{
		string dato=elementos[tope];
		tope--;
		return dato;
	}
}

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
		cout<<"\nAgregado correctamente a la COLA\n";
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
		return "Cola vacia\n";
	
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

//funcion para invertir Cola
void Cola::invertirCola(){
	Pila pila1;
	if(colaVacia()){
		cout<<"COLA VACIA\n";
	}else{
		while(!colaVacia()){
		string info=eliminarCola();
		pila1.insertarPila(info);	
		}
		while(!pila1.pilaVacia()){
			string info1=pila1.sacarPila();
			insertarCola(info1);
		}
	}
	cout<<"\n--COLA INVERTIDO CORRECTAMENTE--\n";
}

//funcion para eleminar un dato en particular en una cola
void Cola::eliminarElementoCola(string dato){
	Cola cola1;
	if(buscarElemento(dato)){
		int cantidad=final-frente+1;
		int i=0;
		while(i<cantidad){
				string dato1=eliminarCola();
			if(dato1!=dato){
				cola1.insertarCola(dato1);
			}
			i++;
		}
			while(!cola1.colaVacia()){
			string dato2=cola1.eliminarCola();
			insertarCola(dato2);
					
			}
		
		cout<<"\nELEMENTO "<<dato<<" ELIMINADO CORRECTAMENTE\n";
	}else{
		cout<<"Dato elimnar no encontrado en la COLA\n";
	}	
}

void menu(){
	Cola cola1;
	string dato, elemento;
	int op;
	
	do{
		system("cls");
		cout<<"\t---MENU DE COLA-----"<<endl
			<<"1.- Insertar elemento en la cola"<<endl
			<<"2.- Eliminar elemento en la cola"<<endl
			<<"3.- Ver frente"<<endl
			<<"4.- Mostrar COLA"<<endl
			<<"5.- Contar elementos"<<endl
			<<"6.- Buscar elemento en la Cola"<<endl
			<<"7.- Invertir Cola"<<endl
			<<"8.- Eliminar elemento de la Cola"<<endl
			<<"0.- SALIR"<<endl;
		cout<<"Seleccione una opcion: "; cin>>op;
			cin.ignore(); // para limpiar el bufer
			switch(op){
				
				case 1:
					system("cls");
					cout<<"Ingrese el dato que desea ingresar: ";
					getline(cin,dato);
					cola1.insertarCola(dato);
					system("pause");
					break;
				case 2:
					system("cls");
					dato=cola1.eliminarCola();
					if(dato !="")
					cout<<"Elemento eliminado "<<dato<<endl;
					system("pause");
					break;
				case 3:
					system("cls");
					dato=cola1.verFrente();
					if(dato !="")
					cout<<"Elemento en el frente: "<<dato<<endl;
					system("pause");
					break;
				case 4:
					system("cls");
					cola1.mostrarCola();
					system("pause");
					break;
				case 5:
					system("cls");
					cout<<" Total de elementos en la cola: "<<cola1.contarElementos()<<endl;
					system("pause");
					break;
				case 6:
					system("cls");
					cout<<"Ingrese el dato a buscar en la cola: ";
					getline(cin,dato);
					cout<<"Esta "<<dato<<" ?: "<<(cola1.buscarElemento(dato) ? "SI":"NO")<<endl;
					system("pause");
					break;
				case 7:
					system("cls");
					cola1.invertirCola();
					system("pause");
					break;
				case 8:
					system("cls");
					cout<<"Ingrese el elemento que desea eliminar de la COLA: ";
					getline(cin,elemento);
					cola1.eliminarElementoCola(elemento);
					system("pause");
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