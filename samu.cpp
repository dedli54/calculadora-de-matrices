#include <iostream>
#include <math.h>

using namespace std;
float  ycentro, xcentro, xradio, yradio, xk[50], yk[50], xcentronuevo, ycentronuevo,  prueba, prueba2, prueba3, prueba4;
float P10, P1Kmas1, p1k,p2k, SemiConstante, Variable, p20, x0, yo, terminoo,nuevascoordenadasX[50], nuevascoordenadasY[50];
int i, l, k, j,nuevasX,nuevasY;

int main() {

	cout << "\tingrese el radio de x" << endl;
	cin >> xradio;
	cout << "\tingrese el radio de y" << endl;
	cin >> yradio;
	cout << "\tingrese el centro de x" << endl;
	cin >> xcentro;
	cout << "\tingrese el centro de y" << endl;
	cin >> ycentro; 
	P10 = (pow(yradio, 2)) - ((pow(xradio, 2)) * yradio) + (.25 * (pow(xradio, 2)));
	cout << "\tp10 es:" << endl;
	cout << P10 << endl;
	p1k = P10;
	i = 0;
	xk[i] = 0;
	P1Kmas1 = 0;
	yk[k] = 6;
	nuevasX = 0;
	nuevasY = 0;
	j = 0;
	l = 1;
	k = 0;
	cout << "\tlas coordenadas Xk e Yk son:" << endl;
	cout << "(" << xk[i] << "," << yk[k] << ")" << endl;
	nuevascoordenadasX[nuevasX] = xk[i] + xcentro;
    nuevascoordenadasY[nuevasY] = yk[k] + ycentro;
	cout << "\tlas nuevas coordenadas de X e Y son:" << endl;
	cout << "(" << nuevascoordenadasX[nuevasX] << "," << nuevascoordenadasY[nuevasY] << ")" << endl;
	SemiConstante = (2 * pow(xradio, 2)) * yk[k];
	cout << "\tsemiconstante es:" << endl;
	cout << SemiConstante << endl;
	Variable = (2 * pow(yradio, 2)) * xk[i];
	cout << "\tvariable es:" << endl;
	cout << Variable << endl;
	P1Kmas1 = P10;


	do
	{

		//system("pause");
		if (P1Kmas1 < 0)
		{

			//system("pause");
			P1Kmas1 = p1k + (((2 * (pow(yradio, 2))) * (xk[i])) + (2 * pow(yradio, 2))) + (pow(yradio, 2));
			cout << "\tPk es:" << endl;
			cout << P1Kmas1 << endl;
			i++;
			xk[i] = j + 1;
			j++;
			cout << "\tlas coordenadas Xk e Yk son:" << endl;
			cout << "("<< xk[i]<<","<< yk[k]<<")" << endl;
			nuevasX++;
			
			nuevascoordenadasX[nuevasX] = xk[i] + xcentro;
			cout << "\tlas nuevas coordenadas de X e Y son:" << endl;
			cout << "(" << nuevascoordenadasX[nuevasX] << "," << nuevascoordenadasY[nuevasY] << ")" << endl;

		}
		else
		{

			P1Kmas1 = p1k + ((2 * (pow(yradio, 2)) * xk[i]) + (2 * pow(yradio, 2))) - ((2 * pow(xradio, 2) * yk[k]) - (2 * pow(xradio, 2))) + (pow(yradio, 2));
			cout << "\tPk es:" << endl;
			cout << P1Kmas1 << endl;
			i++;
			xk[i] = j + 1;
			j++;
			k++;
			yk[k] = 6 - l;
			l++;
			cout << "\tlas coordenadas Xk e Yk son:" << endl;
			cout << "(" << xk[i] << "," << yk[k] << ")" << endl;
			nuevasX++;
			nuevasY++;
			nuevascoordenadasX[nuevasX] = xk[i] + xcentro;
            nuevascoordenadasY[nuevasY] = yk[k] + ycentro;
			cout << "\tlas nuevas coordenadas de X e Y son:" << endl;
			cout << "(" << nuevascoordenadasX[nuevasX] << "," << nuevascoordenadasY[nuevasY] << ")" << endl;

		}
		p1k = P1Kmas1;
		SemiConstante = (2 * pow(xradio, 2)) * yk[k];
		cout << "\tsemiconstante es:" << endl;
		cout << SemiConstante << endl;
		Variable = (2 * pow(yradio, 2)) * xk[i];
		cout << "\tvariable es:" << endl;
		cout << Variable << endl;


		system("pause");
	} while (SemiConstante >= Variable);



x0 = xk[i];
	yo = yk[k];
	cout << "\t===== COMIENZA LA REGION DOS =====" << endl;
	

	p20 = (pow(yradio, 2) * (pow((x0 + .5), 2))) + ((pow(xradio, 2)) * (pow((yo - 1), 2))) - (pow(xradio, 2) * pow(yradio, 2));
	cout << "\teste es el valor inicial del parametro de decision de la region dos" << endl;
	cout << p20 << endl;
	p2k = p20;
	cout << "\tlas coordenadas Xk e Yk son:" << endl;
	cout << "(" << xk[i] << "," << yk[k] << ")" << endl;
	P1Kmas1 = p20;
	
	cout << "\tlas nuevas coordenadas de X e Y son:" << endl;
	cout << "(" << nuevascoordenadasX[nuevasX] << "," << nuevascoordenadasY[nuevasY] << ")" << endl;
	do
	{
		if ( P1Kmas1 >= 0)
		{

			//system("pause");
			


			P1Kmas1 = p2k - (((2 * ((pow(xradio, 2)))) * (yk[k])) - (2 * (pow(xradio, 2)))) + (pow(xradio, 2));
			cout << "\tPk es:" << endl;
			cout << P1Kmas1 << endl;
			k++;
			yk[k] = 6 - l;
			l++;
			cout << "\tlas coordenadas Xk e Yk son:" << endl;
			cout << "(" << xk[i] << "," << yk[k] << ")" << endl;
			
			nuevasY++;
			nuevascoordenadasY[nuevasY] = yk[k] + ycentro;
			cout << "\tlas nuevas coordenadas de X e Y son:" << endl;
			cout << "(" << nuevascoordenadasX[nuevasX] << "," << nuevascoordenadasY[nuevasY] << ")" << endl;
		}
		else
		{
			P1Kmas1 = p2k + ((2 * (pow(yradio, 2)) * xk[i]) + (2 * pow(yradio, 2))) - ((2 * pow(xradio, 2) * yk[k]) - (2 * pow(xradio, 2))) + (pow(xradio, 2));
			cout << "\tPk es:" << endl;
			cout << P1Kmas1 << endl;
			i++;
			xk[i] = j + 1;
			j++;
			k++;
			yk[k] = 6 - l;
			l++;
			cout << "\tlas coordenadas Xk e Yk son:" << endl;
			cout << "(" << xk[i] << "," << yk[k] << ")" << endl;
			nuevasX++;
			nuevasY++;
			nuevascoordenadasX[nuevasX] = xk[i] + xcentro;
            nuevascoordenadasY[nuevasY] = yk[k] + ycentro;
			cout << "\tlas nuevas coordenadas de X e Y son:" << endl;
			cout << "("<<nuevascoordenadasX[nuevasX] << "," << nuevascoordenadasY[nuevasY]<<")" << endl;
		}
		
		p2k = P1Kmas1;
		 terminoo= yk[k];
		

	} while (terminoo != 0);

	 



	

}