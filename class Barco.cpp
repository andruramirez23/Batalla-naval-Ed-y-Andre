class Barco{	
		
	public:
		Barco();
		int coordenadas[2][4];

};

Barco::Barco(){
	
	cout << "Ingrese las coordenadas del barco" << endl;
	
	for(int i=0; i<4; i++){
		
		cout << "Posicion " << i << ": "<<endl;
		cout << " x: ";
		cin >> coordenadas[0][i];
		cout << " y: ";
		cin >> coordenadas[1][i];
		cout << endl;
	
	}
	
}