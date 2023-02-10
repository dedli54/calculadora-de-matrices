#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265

using namespace std;

//Matrices suma/resta/multiplicación
float matriz1[50][50];
float matriz2[50][50];
float matriz3[50][50]; //Matriz de resultado

float angulo;

//[Y][X]
float matrizTras[4][4]; //Matriz Traslación
float matrizRot[4][4]; //Matriz Rotación
float matrizEsc[4][4]; //Matriz Escalar
float matrizPunt[4][1]; //Matriz del punto
float matrizRes[4][4]; //Matriz Resultado
float matrizRes2[4][4];

int filas[2] = { 0,0 }; //[0] = filas de matriz 1, [1] = filas de matriz 2
int columnas[2] = { 0,0 }; //[0] = columnas de matriz 1, [1] = columnas de matriz 2
int opcionGeneral; //Opcion general
int opcionMatCom; //Opcion de matrices compuestas 
int subopcionMatCom; //Opcion extra de matrices compuestas
int opcionOpSimp; //Opcion de operaciones simples

void OperacionesSimples(); //Suma, resta y multiplicación
void MatricesCompuestas(); //Rotación, Traslación, Escalación
void SumaMatrices();
void RestaMatrices();
void MultiplicaMatrices();
void cuaterniones();
void ZPerspectiva();
void Recta();
void Circulo();

int main()
{
	system("cls");
	//Menu principal
	cout << "------------------------------------------------" << endl;
	cout << "Ingrese la opcion de la operacion a realizar" << endl;
	cout << "1: Operaciones basicas de 2 matrices" << endl;
	cout << "2: Multiplicaciones con matrices compuestas" << endl;
	cout << "3: Rotacion con cuaternios" << endl;
	cout << "4: Z Perspectiva" << endl;
	cout << "5: Recta con algoritmo de Bresenham" << endl;
	cout << "6: Circulo con algoritmo de Bresenham" << endl;
	cout << "7: Salir" << endl;
	cout << "------------------------------------------------" << endl << endl;
	cin >> opcionGeneral;

	switch (opcionGeneral) {

	case 1:
		OperacionesSimples();
		main();
		break;

	case 2:
		MatricesCompuestas();
		main();
		break;

	case 3:
		cuaterniones();
		main();
		break;

	case 4:
		ZPerspectiva();
		main();
		break;

	case 5:
		Recta();
		main();
		break;

	case 6:
		Circulo();
		main();
		break;

	case 7:
		return 0;
		break;
	}
	return 0;
}

void OperacionesSimples()
{
	for (int i = 0; i < 50; i++)
	{
		for (int j = 0; j < 50; j++)
		{
			matriz1[i][j] = 0;
			matriz2[i][j] = 0;
			matriz3[i][j] = 0;
		}
	}
	//Asignar numero de filas y columnas de la primera matriz
	cout << "------------------------------------------------" << endl;
	cout << "Ingrese el numero de filas de la matriz 1: ";
	cin >> filas[0];
	cout << "Ingrese el numero de columnas de la matriz 1: ";
	cin >> columnas[0];
	cout << "------------------------------------------------" << endl << endl;

	//Asignar valores a cada casilla de la matriz 1
	for (int i = 0; i < filas[0]; i++)
	{
		for (int j = 0; j < columnas[0]; j++)
		{
			cout << "Ingrese un numero en fila " << i + 1 << ", columna " << j + 1 << ": ";
			cin >> matriz1[i][j];
			cout << endl;
		}
	}

	//Asignar numero de filas y columnas de la segunda matriz
	cout << "------------------------------------------------" << endl;
	cout << "Ingrese el numero de filas de la matriz 2: ";
	cin >> filas[1];
	cout << "Ingrese el numero de columnas de la matriz 2: ";
	cin >> columnas[1];
	cout << "------------------------------------------------" << endl << endl;

	//Asignar valores a cada casilla de la matriz 2
	for (int i = 0; i < filas[1]; i++)
	{
		for (int j = 0; j < columnas[1]; j++)
		{
			cout << "Ingrese un numero en la fila " << i + 1 << ", columna " << j + 1 << ": ";
			cin >> matriz2[i][j];
			cout << endl;
		}
	}

	cout << "Matriz 1: " << "\n";
	for (int i = 0; i < filas[0]; i++)
	{
		for (int j = 0; j < columnas[0]; j++)
		{
			cout << matriz1[i][j] << " ";
		}
		cout << "\n";
	}

	cout << endl << "Matriz 2: " << "\n";
	for (int i = 0; i < filas[1]; i++)
	{
		for (int j = 0; j < columnas[1]; j++)
		{
			cout << matriz2[i][j] << " ";
		}
		cout << "\n";
	}
	cout << endl;

	system("pause");

	system("cls");
	cout << "Ingrese la operacion a realizar:";
	cout << "\t1: Suma de matrices";
	cout << "\t2: Resta de matrices";
	cout << "\t3: Multiplicacion de matrices"
		<< endl << endl;
	cin >> opcionOpSimp;

	switch (opcionOpSimp)
	{
	case 1:
		SumaMatrices();
		break;

	case 2:
		RestaMatrices();
		break;

	case 3:
		MultiplicaMatrices();
		break;

	default:
		break;
	}
}

void MatricesCompuestas()
{
	matrizTras[0][0] = 1, matrizTras[0][1] = 0, matrizTras[0][2] = 0,
		matrizTras[1][0] = 0, matrizTras[1][1] = 1, matrizTras[1][2] = 0,
		matrizTras[2][0] = 0, matrizTras[2][1] = 0, matrizTras[2][2] = 1,
		matrizTras[3][0] = 0, matrizTras[3][1] = 0, matrizTras[3][2] = 0, matrizTras[3][3] = 1;
	//matrizTras[0][3] = Tx 
	//matrizTras[1][3] = Ty 
	//matrizTras[2][3] = Tz
	// 
	//Rotación en X
	//matrizRotX[1][1] = cos(angulo), matrizRotX[1][2] = -sin(angulo)
	//matrizRotX[2][1] = sin(angulo), matrizRotX[2][2] = cos(angulo)

	//Rotación en Y
	//matrizRotY[0][0] = cos(angulo), matrizRotY[0][2] = sin(angulo)
	//matrizRotY[2][0] = -sin(angulo), matrizRotY[2][2] = cos(angulo)

	//Rotación en Z 
	//matrizRotZ[0][0] = cos(angulo), matrizRotZ[0][1] = -sin(angulo)
	//matrizRotZ[1][0] = sin(angulo), matrizRotZ[1][1] = cos(angulo)

	matrizEsc[0][1] = 0, matrizEsc[0][2] = 0, matrizEsc[0][3] = 0,
		matrizEsc[1][0] = 0, matrizEsc[1][2] = 0, matrizEsc[1][3] = 0,
		matrizEsc[2][0] = 0, matrizEsc[2][1] = 0, matrizEsc[2][3] = 0,
		matrizEsc[3][0] = 0, matrizEsc[3][1] = 0, matrizEsc[3][2] = 0, matrizEsc[3][3] = 1;
	//matrizEsc[0][0] = Sx
	//matrizEsc[1][1] = Sy
	//matrizEsc[2][2] = Sz

	matrizPunt[3][0] = 1;

	//[0][0] = X, [1][0] = Y, [2][0] = Z

	system("cls");

	cout << "------------------------------------------------" << endl;
	cout << "Ingrese la opcion de a realizar" << endl;
	cout << "1: Definir angulo y eje de rotacion" << endl;
	cout << "2: Definir vector de traslacion" << endl;
	cout << "3: Definir vector de escalacion" << endl;
	cout << "4: Definir matriz punto" << endl;
	cout << "5: Multiplicar matrices" << endl;
	cout << "6: Ver matriz resultado" << endl;
	cout << "7: Limpiar matriz resultado" << endl;
	cout << "8: Regresar" << endl;
	cout << "------------------------------------------------" << endl << endl;
	cin >> opcionMatCom;

	switch (opcionMatCom) {
	case 1:
		//Limpiar matriz de rotación
		matrizRot[0][0] = 1, matrizRot[0][1] = 0, matrizRot[0][2] = 0, matrizRot[0][3] = 0,
			matrizRot[1][0] = 0, matrizRot[1][1] = 1, matrizRot[1][2] = 0, matrizRot[1][3] = 0,
			matrizRot[2][0] = 0, matrizRot[2][1] = 0, matrizRot[2][2] = 1, matrizRot[2][3] = 0,
			matrizRot[3][0] = 0, matrizRot[3][1] = 0, matrizRot[3][2] = 0, matrizRot[3][3] = 1;

		cout << "Ingrese el angulo" << endl;
		cin >> angulo;

		cout << "Ingrese el eje" << endl;
		cout << "1: X" << endl;
		cout << "2: Y" << endl;
		cout << "3: Z" << endl;
		cout << "------------------------------------------------" << endl << endl;
		cin >> subopcionMatCom;

		switch (subopcionMatCom) {
		case 1:
			matrizRot[1][1] = cos(angulo * PI / 180), matrizRot[1][2] = -sin(angulo * PI / 180);
			matrizRot[2][1] = sin(angulo * PI / 180), matrizRot[2][2] = cos(angulo * PI / 180);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << matrizRot[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			system("pause");
			MatricesCompuestas();
			break;

		case 2:
			matrizRot[0][0] = cos(angulo * PI / 180), matrizRot[0][2] = sin(angulo * PI / 180);
			matrizRot[2][0] = -sin(angulo * PI / 180), matrizRot[2][2] = cos(angulo * PI / 180);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << matrizRot[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			system("pause");
			MatricesCompuestas();
			break;

		case 3:
			matrizRot[0][0] = cos(angulo * PI / 180), matrizRot[0][1] = -sin(angulo * PI / 180);
			matrizRot[1][0] = sin(angulo * PI / 180), matrizRot[1][1] = cos(angulo * PI / 180);
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					cout << matrizRot[i][j] << "\t";
				}
				cout << endl;
			}
			cout << endl;
			system("pause");
			MatricesCompuestas();
			break;
		}
		break;

	case 2:
		cout << "Ingresa el valor x" << endl;
		cin >> matrizTras[0][3];
		cout << "Ingresa el valor y" << endl;
		cin >> matrizTras[1][3];
		cout << "Ingresa el valor z" << endl;
		cin >> matrizTras[2][3];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << matrizTras[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		MatricesCompuestas();
		break;

	case 3:
		cout << "Ingresa el valor x" << endl;
		cin >> matrizEsc[0][0];
		cout << "Ingresa el valor y" << endl;
		cin >> matrizEsc[1][1];
		cout << "Ingresa el valor z" << endl;
		cin >> matrizEsc[2][2];
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << matrizEsc[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		MatricesCompuestas();
		break;

	case 4:
		cout << "Ingresa el valor x" << endl;
		cin >> matrizPunt[0][0];
		cout << "Ingresa el valor y" << endl;
		cin >> matrizPunt[1][0];
		cout << "Ingresa el valor z" << endl;
		cin >> matrizPunt[2][0];
		for (int i = 0; i < 4; i++) {
			cout << matrizPunt[i][0];
			cout << endl;
		}
		cout << endl;
		system("pause");
		MatricesCompuestas();
		break;

	case 5:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matriz1[i][j] = 0;
				matriz2[i][j] = 0;
				matrizRes[i][j] = 0;
			}
		}
		cout << "Cual sera la primera matriz a multiplicar" << endl << endl;
		cout << "1: Rotacion" << endl;
		cout << "2: Traslacion" << endl;
		cout << "3: Escalacion" << endl;
		cout << "4: Punto" << endl;
		cout << "5: Matriz resultado actual" << endl;
		cin >> subopcionMatCom;

		switch (subopcionMatCom) {
		case 1:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz1[i][j] = matrizRot[i][j];
				}
			}
			columnas[0] = 4;
			filas[0] = 4;
			break;

		case 2:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz1[i][j] = matrizTras[i][j];
				}
			}
			columnas[0] = 4;
			filas[0] = 4;
			break;

		case 3:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz1[i][j] = matrizEsc[i][j];
				}
			}
			columnas[0] = 4;
			filas[0] = 4;
			break;

		case 4:
			for (int i = 0; i < 4; i++) {
				matriz1[i][0] = matrizPunt[i][0];
			}
			columnas[0] = 1;
			filas[0] = 4;
			break;

		case 5:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz1[i][j] = matrizRes2[i][j];
				}
			}
			columnas[0] = 4;
			filas[0] = 4;
			break;
		}

		cout << "Cual sera la segunda matriz a multiplicar" << endl << endl;
		cout << "1: Rotacion" << endl;
		cout << "2: Traslacion" << endl;
		cout << "3: Escalacion" << endl;
		cout << "4: Punto" << endl;
		cout << "5: Matriz resultado actual" << endl;
		cin >> subopcionMatCom;

		switch (subopcionMatCom) {
		case 1:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz2[i][j] = matrizRot[i][j];
				}
			}
			columnas[1] = 4;
			filas[1] = 4;
			break;

		case 2:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz2[i][j] = matrizTras[i][j];
				}
			}
			columnas[1] = 4;
			filas[1] = 4;
			break;

		case 3:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz2[i][j] = matrizEsc[i][j];
				}
			}
			columnas[1] = 4;
			filas[1] = 4;
			break;

		case 4:
			for (int i = 0; i < 4; i++) {
				matriz2[i][0] = matrizPunt[i][0];
			}
			columnas[1] = 1;
			filas[1] = 4;
			break;

		case 5:
			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					matriz2[i][j] = matrizRes2[i][j];
				}
			}
			columnas[1] = 4;
			filas[1] = 4;
			break;
		}

		for (int i = 0; i < filas[0]; i++) {
			for (int j = 0; j < columnas[1]; j++) {
				for (int k = 0; k < columnas[0]; k++) {
					matrizRes[i][j] += matriz1[i][k] * matriz2[k][j];
				}
			}
		}

		for (int i = 0; i < filas[0]; i++) {
			for (int j = 0; j < columnas[1]; j++) {
				cout << matrizRes[i][j] << "\t";
			}
			cout << endl;
		}

		cout << "Quieres guardar la matriz resultado?" << endl
			<< "1: Si" << endl
			<< "2: No" << endl;
		cin >> subopcionMatCom;

		if (subopcionMatCom == 1) {
			for (int i = 0; i < filas[0]; i++) {
				for (int j = 0; j < columnas[1]; j++) {
					matrizRes2[i][j] = matrizRes[i][j];
				}
			}
		}

		system("pause");
		MatricesCompuestas();
		break;

	case 6:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				cout << matrizRes2[i][j] << "\t";
			}
			cout << endl;
		}
		cout << endl;
		system("pause");
		MatricesCompuestas();
		break;

	case 7:
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrizRes2[i][j] = 0;
			}
		}
		MatricesCompuestas();
		break;

	case 8:
		break;
	}
}

void SumaMatrices() {
	if (filas[0] == filas[1] && columnas[0] == columnas[1]) {
		for (int i = 0; i < filas[0]; i++)
		{
			for (int j = 0; j < columnas[0]; j++)
			{
				matriz3[i][j] = matriz1[i][j] + matriz2[i][j];
			}
		}
		cout << "Resultado:" << endl;
		for (int i = 0; i < filas[0]; i++)
		{
			for (int j = 0; j < columnas[0]; j++)
			{
				cout << matriz3[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		cout << endl
			<< "Las matrices no tienen el mismo numero de columnas y/o de filas" << endl
			<< "No pueden ser sumadas" << endl;
	}

	system("PAUSE");
}

void RestaMatrices() {
	if (filas[0] == filas[1] && columnas[0] == columnas[1]) {
		for (int i = 0; i < filas[0]; i++)
		{
			for (int j = 0; j < columnas[0]; j++)
			{
				matriz3[i][j] = matriz1[i][j] - matriz2[i][j];
			}
		}
		cout << "Resultado:" << endl;
		for (int i = 0; i < filas[0]; i++)
		{
			for (int j = 0; j < columnas[0]; j++)
			{
				cout << matriz3[i][j] << " ";
			}
			cout << "\n";
		}
	}
	else {
		cout << endl
			<< "Las matrices no tienen el mismo numero de columnas y/o de filas" << endl
			<< "No pueden ser restadas" << endl;
	}
	system("PAUSE");
}

void MultiplicaMatrices()
{
	if (columnas[0] == filas[1]) {
		for (int i = 0; i < filas[0]; i++) {
			for (int j = 0; j < columnas[1]; j++) {
				for (int k = 0; k < columnas[0]; k++) {
					matriz3[i][j] += matriz1[i][k] * matriz2[k][j];
				}
			}
		}

		for (int i = 0; i < filas[0]; i++) {
			for (int j = 0; j < columnas[1]; j++) {
				cout << matriz3[i][j] << "\t";
			}
			cout << endl;
		}
	}
	else {
		cout << "No se puede multiplicar estas matrices" << endl;
	}
	system("PAUSE");
}

void cuaterniones() {
	system("cls");
	float puntox, puntoy, puntoz, angulo, vectorx, vectory, vectorz, q, vunitario;
	cout << "Rotacion de cuaterniones" << endl;
	cout << "Introducir punto" << endl;
	cout << "i:";
	cin >> puntox;
	cout << "j:";
	cin >> puntoy;
	cout << "k:";
	cin >> puntoz;
	cout << endl;
	cout << "Introducir angulo" << endl;
	cin >> angulo;
	cout << "Introducir vector" << endl;
	cout << "i:";
	cin >> vectorx;
	cout << "j:";
	cin >> vectory;
	cout << "k:";
	cin >> vectorz;
	cout << endl;
	vunitario = sqrt(pow(vectorx, 2) + pow(vectory, 2) + pow(vectorz, 2));
	float q1, q2, q3, q4;
	q1 = cos((angulo / 2) * PI / 180);
	q2 = (vectorx / vunitario) * sin((angulo / 2) * PI / 180);
	q3 = (vectory / vunitario) * sin((angulo / 2) * PI / 180);
	q4 = (vectorz / vunitario) * sin((angulo / 2) * PI / 180);
	//cout << "w=" << q1 << endl;
	//cout << "x=" << q2 << endl;
	//cout << "y=" << q3 << endl;
	//cout << "z=" << q4 << endl;

	/*Matriz*/
	float columna11, columna12, columna13, columna21, columna22, columna23, columna31, columna32, columna33, irotado, jrotado, krotado;
	columna11 = 1 - (2 * pow(q3, 2)) - (2 * pow(q4, 2));
	columna12 = (2 * q2 * q3) + (2 * q1 * q4);
	columna13 = (2 * q2 * q4) - (2 * q1 * q3);
	columna21 = (2 * q2 * q3) - (2 * q1 * q4);
	columna22 = 1 - (2 * (pow(q2, 2))) - (2 * (pow(q4, 2)));
	columna23 = (2 * q3 * q4) + (2 * q1 * q2);
	columna31 = (2 * q2 * q4) + (2 * q1 * q3);
	columna32 = (2 * q3 * q4) - (2 * q1 * q2);
	columna33 = 1 - (2 * (pow(q2, 2))) - (2 * (pow(q3, 2)));
	//cout << "Matriz:" << endl;
	//cout << columna11 << " " << columna21 << " " << columna31 << " " << 0 << endl;
	//cout << columna12 << " " << columna22 << " " << columna32 << " " << 0 << endl;
	//cout << columna13 << " " << columna23 << " " << columna33 << " " << 0 << endl;
	//cout << 0 << " " << 0 << " " << 0 << " " << 1 << endl;

	irotado = (columna11 * puntox) + (columna21 * puntoy) + (columna31 * puntoz);
	jrotado = (columna12 * puntox) + (columna22 * puntoy) + (columna32 * puntoz);
	krotado = (columna13 * puntox) + (columna23 * puntoy) + (columna33 * puntoz);
	cout << "Puntos rotados" << endl;
	cout << "i:" << irotado << endl;
	cout << "j:" << jrotado << endl;
	cout << "k:" << krotado << endl;
	cout << endl;
	system("PAUSE");
}

void ZPerspectiva() {

	int puntos = 0;
	float Xprp[50];
	float Yprp[50];
	float Zprp = 0;
	float Puntox[50];
	float Puntoy[50];
	float Puntoz[50];

	cout << "Cuantos puntos quiere colocar?" << endl;
	cin >> puntos;
	cout << "Cual es el valor de Zprp?" << endl;
	cin >> Zprp;

	for (int i = 0; i < puntos; i++)//escribir los puntos a usar
	{
		cout << "Ingrese los valores del punto " << i + 1 << endl;
		cout << "X:";
		cin >> Puntox[i];
		cout << "Y:";
		cin >> Puntoy[i];
		cout << "Z:";
		cin >> Puntoz[i];
	}

	for (int i = 0; i < puntos; i++)//sacando la persectiva X & Y
	{
		Xprp[i] = Puntox[i] * ((Zprp / (Zprp - Puntoz[i])));

		Yprp[i] = Puntoy[i] * ((Zprp / (Zprp - Puntoz[i])));
	}

	for (int i = 0; i < puntos; i++)
	{
		cout << " El punto " << i + 1 << " es (" << Xprp[i] << "," << Yprp[i] << ")" << endl;
	}

	system("pause");
}

void Recta() {
	int P1[2] = {0,0}, P2[2] = {0,0}, xk = 0, yk = 0, Pk = 0, dx = 0, dy = 0;
	cout << endl << "Ingresa el primer punto de la recta" << endl
		<< "X: ";
	cin >> P1[0];
	cout << "Y: ";
	cin >> P1[1];
	cout << endl;

	cout << "Ingresa el segundo punto de la recta" << endl
		<< "X: ";
	cin >> P2[0];
	cout << "Y: ";
	cin >> P2[1];
	cout << endl;

	dx = P2[0] - P1[0];
	dy = P2[1] - P1[1];

	Pk = (2 * dy) - dx;
	xk = P1[0];
	yk = P1[1];
	cout << "(" << xk << ", " << yk << ") Pk = " << Pk << endl;
	
	for (int i = 0; i < dx; i++) {
		if (Pk >= 0) {
			Pk = Pk + (2 * dy) - (2 * dx);
			xk++, yk++;
		}
		else {
			Pk = Pk + (2 * dy);
			xk++;
		}
		cout << "(" << xk << ", " << yk << ") Pk = " << Pk << endl;
	}
	cout << endl;
	system("pause");
}

void Circulo() {
	int Pc[2] = { 0,0 }, xk = 0, yk = 0, Pk = 0, opc = 0, Puntos[20][2];
	float R = 0;

	cout << "El centro estara dentro o fuera del origen?" << endl
		<< "1: Dentro	2: Fuera" << endl;
	cin >> opc;

	if (opc == 2) {
		cout << endl << "Introduce el centro" << endl
			<< "X: ";
		cin >> Pc[0];

		cout << "Y: ";
		cin >> Pc[1];
	}
	cout << endl;

	cout << "Introduce el radio" << endl;
	cin >> R;
	cout << endl;

	if (R == (int)R) {
		Pk = 1 - R;
	}
	else {
		R = round(R);
		Pk = 1.25 - R;
	}

	cout << "Primer cuadrante:" << endl << endl;

	xk = 0, yk = R;
	Puntos[0][0] = 0, Puntos[0][1] = R;
	cout << "(" << xk << ", " << yk << ") Pk: " << Pk << endl;

	int numpunt = 1;

	while (yk != 0) {
		if (Pk >= 0) {
			Pk = Pk + (2 * xk) + 2 + 1 - (2 * yk) + 2;
			if (xk == R) {
				yk--;
			}
			else {
				xk++, yk--;
			}
		}
		else {
			Pk = Pk + (2 * xk) + 2 + 1;
			xk++;
		}

		if (Pc[0] == 0 && Pc[1] == 0) {
			Puntos[numpunt][0] = xk;
			Puntos[numpunt][1] = yk;
			cout << "(" << xk << ", " << yk << ") Pk: " << Pk << endl;
		}
		else {
			Puntos[numpunt][0] = xk + Pc[0];
			Puntos[numpunt][1] = yk + Pc[1];
			cout << "(" << xk + Pc[0] << ", " << yk + Pc[1] << ") Pk: " << Pk << endl;
		}
		numpunt++;
	}

	cout << endl << "Segundo cuadrante:" << endl << endl;

	for (int i = 0; i < numpunt; i++) {
		cout << "(" << (Puntos[i][0] * -1) << ", " << Puntos [i][1] << ")" << endl;
	}

	cout << endl << "Tercer cuadrante:" << endl << endl;

	for (int i = 0; i < numpunt; i++) {
		cout << "(" << (Puntos[i][0] * -1) << ", " << (Puntos[i][1] * -1) << ")" << endl;
	}

	cout << endl << "Cuarto cuadrante:" << endl << endl;

	for (int i = 0; i < numpunt; i++) {
		cout << "(" << Puntos[i][0] << ", " << (Puntos[i][1] * -1) << ")" << endl;
	}
	system("pause");
}