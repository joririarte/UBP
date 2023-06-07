#pragma once
class Mediciones
{
private:
	char material;
	int idComponente;
	int medicion;
public:
	Mediciones();
	Mediciones(char m, int comp,int med);
	~Mediciones();
	char getMaterial();
	int getComponenteId();
	int getMedicion();
	bool operator ==(Mediciones*);
	void mostrar();
};

