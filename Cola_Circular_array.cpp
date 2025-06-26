#include <iostream>
#include <string>
#define MAX 5  // tamanio maximo de la cola
using namespace std;
class ColaCircular{
	private:
		string elementos[MAX];
		int frente;
		int final;
	public:
		ColaCircular();
		
		bool colaCirVacia();
		bool colaCirLlena();
		void insertaCircular(string dato);
		string eliminarCircular();
		void mostrarCircular();
		
			
};


//constructor : Inicializa la cola vacia
ColaCircular::ColaCircular(){
	frente=-1;
	final=-1;
}

// verifica si la cola circular esta llena
bool ColaCircular::colaCirLlena(){
	/*if((final==frente + 1) || (frente==1 && final==MAX-1)){
		return true;
	}else{
		return false;
	}*/
	 return ( (final + 1) % MAX == frente );
}

//verifica si la cola circular esta vacia

bool  ColaCircular::colaCirVacia(){
	if(frente==-1){
		return true;
	}else{
		return false;
	}
}

//agregar un elemento en la cola cicular
void ColaCircular::insertaCircular(string dato){
	if(!colaCirLlena()){
		if(colaCirVacia()){
			frente=0;
			final=0;
		}else{
			final=(final+1) % MAX;
		}
		
		elementos[final]=dato;
	}else{
		cout<<"COLA LLENA\n";
		return;
	}
}

//eliminar un elemento de cola circular

string ColaCircular::eliminarCircular(){
	if(colaCirVacia()){
		cout<<"COLA VACIA\n";
		return"";
	}else{
		string dato=elementos[frente];
		if(final==frente){ // si hay un solo elemento 
			frente=-1;
			final=-1;
		}else{
			frente=(frente + 1) % MAX;
		}
	return dato;
	}
	
}

//mostrar todo los elementos de la cola circular
void ColaCircular::mostrarCircular() {
	if(colaCirVacia()){
		cout<<"COLA VACIA\n";
		return;
	}else{
		
	  int i=frente;
	  while(true){
	  	cout<<elementos[i]<<" ";
	  	if(i==final) break;
	  	i=(i+1) % MAX;
	  }
	}
  cout<<"\n";
}



void menu(){
	ColaCircular colaCir1;
	string dato, elemento;
	int op;
	
	do{
		system("cls");
		cout<<"\t---MENU DE COLA-----"<<endl
			<<"1.- Insertar elemento en la cola"<<endl
			<<"2.- Eliminar elemento en la cola"<<endl
			<<"3.- Mostrar COLA CIRCULAR"<<endl
			<<"0.- SALIR"<<endl;
		cout<<"Seleccione una opcion: "; cin>>op;
			cin.ignore(); // para limpiar el bufer
			switch(op){
				
				case 1:
					system("cls");
					cout<<"Ingrese el dato que desea ingresar: ";
					getline(cin,dato);
					colaCir1.insertaCircular(dato);
					system("pause");
					break;
				case 2:
					system("cls");
					dato=colaCir1.eliminarCircular();
					if(dato !="")
					cout<<"Elemento eliminado "<<dato<<endl;
					system("pause");
					break;
				case 3:
					system("cls");
					colaCir1.mostrarCircular();
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