#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <stdio.h>
#define PI 3.14159265
using namespace std;
struct matriz
{
	int id;
	int filas;
	int columnas;
	double elementos[10][10];
	matriz* sig;
};
float pi = 3.1516;
double angulo = 35;
double x, y, z;
matriz* ultimo, * inicio = 0, * aux, * auxoperacion, * matrizA, * matrizB;
matriz rotacionx, rotaciony, rotacionz, traslacion, escalasion, punto, quaternions, matriz_identida, _base, _matrizA, _matrizB, _matrizC;
int opc;
int ids = 1;

void leerMatriz(int** M, int fil, int col);
void sumaMatrices();
void restaMatrices();
void multiplicacionMatrices();
void imprimirMatriz(int** M, int fil, int col);

void agregalista();
void agregamatriz();
void mostrar();
void rotacion();
void matrixpunto();
void matrizcompuesta();
void matrizele();

void cuaterniones();
void lineaBresenham();
void circuloBresenham();
void circulofueraBresenham();
void elipseBresenham();
void elipsefueraBresenham();
int xkcirinv[20], ykcirinv[20];
int main() {
	rotacionx.elementos[0][0] = 1;
	rotacionx.elementos[0][1] = 0;
	rotacionx.elementos[0][2] = 0;
	rotacionx.elementos[0][3] = 0;//
	rotacionx.elementos[1][0] = 0;
	rotacionx.elementos[1][1] = cos(angulo * pi / 180);
	rotacionx.elementos[1][2] = -sin(angulo * pi / 180);
	rotacionx.elementos[1][3] = 0;//
	rotacionx.elementos[2][0] = 0;
	rotacionx.elementos[2][1] = sin(angulo * pi / 180);
	rotacionx.elementos[2][2] = cos(angulo * pi / 180);
	rotacionx.elementos[2][3] = 0;//
	rotacionx.elementos[3][0] = 0;
	rotacionx.elementos[3][1] = 0;
	rotacionx.elementos[3][2] = 0;
	rotacionx.elementos[3][3] = 1;//
	rotaciony.elementos[0][0] = cos(angulo * pi / 180);
	rotaciony.elementos[0][1] = 0;
	rotaciony.elementos[0][2] = sin(angulo * pi / 180);
	rotaciony.elementos[0][3] = 0;//
	rotaciony.elementos[1][0] = 0;
	rotaciony.elementos[1][1] = 1;
	rotaciony.elementos[1][2] = 0;
	rotaciony.elementos[1][3] = 0;//
	rotaciony.elementos[2][0] = -sin(angulo * pi / 180);
	rotaciony.elementos[2][1] = 0;
	rotaciony.elementos[2][2] = cos(angulo * pi / 180);
	rotaciony.elementos[2][3] = 0;//
	rotaciony.elementos[3][0] = 0;
	rotaciony.elementos[3][1] = 0;
	rotaciony.elementos[3][2] = 0;
	rotaciony.elementos[3][3] = 1;//
	rotacionz.elementos[0][0] = cos(angulo * pi / 180);
	rotacionz.elementos[0][1] = sin(angulo * pi / 180);
	rotacionz.elementos[0][2] = 0;
	rotacionz.elementos[0][3] = 0;//
	rotacionz.elementos[1][0] = sin(angulo * pi / 180);
	rotacionz.elementos[1][1] = cos(angulo * pi / 180);
	rotacionz.elementos[1][2] = 0;
	rotacionz.elementos[1][3] = 0;//
	rotacionz.elementos[2][0] = 0;
	rotacionz.elementos[2][1] = 0;
	rotacionz.elementos[2][2] = 1;
	rotacionz.elementos[2][3] = 0;//
	rotacionz.elementos[3][0] = 0;
	rotacionz.elementos[3][1] = 0;
	rotacionz.elementos[3][2] = 0;
	rotacionz.elementos[3][3] = 1;//

	rotacionx.columnas = 4;
	rotacionx.filas = 4;

	rotaciony.columnas = 4;
	rotaciony.filas = 4;

	rotacionz.columnas = 4;
	rotacionz.filas = 4;
	int opcion;
	do {
		system("cls");
		cout << "Menu" << endl;
		cout << "Seleccione la opcion a la que desee ingresar:" << endl;
		cout << "1) Suma de matrices" << endl;
		cout << "2) Resta de matrices" << endl;
		cout << "3) Multiplicacion de matrices" << endl;
		cout << "4) Matriz compuesta por puntos" << endl;
		cout << "5) Matriz por punto" << endl;
		cout << "6) Rotacion" << endl;
		cout << "7) Cuaterniones" << endl;
		cout << "8) Linea de Bresenham" << endl;
		cout << "9) Circulo  de Bresenham" << endl;
		cout << "10) Circulo de Bresenham fuera del origen" << endl;
		cout << "11) Elipse de Bresenham" << endl;
		cout << "12) Elipse de Bresenham fuera del origen" << endl;
		cout << "13) Salir" << endl;
		cin >> opcion;
		switch (opcion) {
		case 1: sumaMatrices();
			break;
		case 2: restaMatrices();
			break;
		case 3: multiplicacionMatrices();
			break;
		case 4:
			matrizcompuesta();
			break;
		case 5:
			matrixpunto();
			break;
		case 6:
			rotacion();
			break;
		case 7:
			cuaterniones();
			break;
		case 8:
			lineaBresenham();
			break;
		case 9:
			circuloBresenham();
			break;
		case 10:
			circulofueraBresenham();
			break;
		case 11:
			elipseBresenham();
			break;
		case 12:
			elipsefueraBresenham();
			break;
		case 13:
			break;
		default:
			break;
		}
	} while (opcion != 13);
	system("PAUSE");

	// Batalle para volver funcion todo esto sin borrarlo de aqui :( 
	int x0, y0, x1, y1, dx, dy, veces, abscisa, ordenada, paraminicial; // linea
	int x0cir, y0cir, x1cir, y1cir, radiocir, xkcir = 0, ykcir, paraminicialcir; // circulo origen
	float puntox, puntoy, puntoz, angulo, vectorx, vectory, vectorz, q, vunitario; // cuaterniones

	float radiox, radioy, xk = 0, yk, finy, finx, paramini, pkeli, paramini2, xk2, yk2, pkeli2; // elipse origen 
	int coordenadax, coordenaday;
	/*
	cout << "Elipse en origen" << endl;
	cout << "Radio en x" << endl;
	cin >> radiox;
	cout << "Radio en y" << endl;
	cin >> radioy;
	yk = radioy;
	paramini = (pow(radioy, 2)) - (pow(radiox, 2) * radioy) + (.25 * pow(radiox, 2));
	cout << "K" << "  " << "xk,yk" << "  " << "Pk<0" << "  " << "Pk>=0" << "  " << "2ry^2x" << "  " << "2rx^2y" << endl;
	if (paramini >= 0) {
		cout << 0 << "  " << xk << yk << "  " << "     " << "  " << paramini << "  " << 2 * pow(radioy, 2) * xk << "  " << 2 * pow(radiox, 2) * yk << endl;
	}
	else {
		cout << 0 << "  " << xk << yk << "  " << paramini << "  " << "     " << "  " << 2 * pow(radioy, 2) * xk << "  " << 2 * pow(radiox, 2) * yk << endl;
	}
	finy = 2 * pow(radioy, 2) * xk;
	finx = 2 * pow(radiox, 2) * yk;
	pkeli = paramini;
	int cuenta = 1;
	do {
		if (pkeli < 0) {
			pkeli = pkeli + ((2 * pow(radioy, 2) * xk) + (2 * pow(radioy, 2))) + pow(radioy, 2);
			xk = xk + 1;
			yk = yk;
			finy = 2 * pow(radioy, 2) * xk;
			finx = 2 * pow(radiox, 2) * yk;
			if (pkeli < 0) {
				cout << cuenta << "  " << xk << yk << "  " << pkeli << "  " << "     " << "  " << finy << "  " << finx << endl;
			}
			else {
				cout << cuenta << "  " << xk << yk << "  " << "     " << "  " << pkeli << "  " << finy << "  " << finx << endl;
			}
		}
		else {
			pkeli = pkeli + ((2 * pow(radioy, 2) * xk) + (2 * pow(radioy, 2))) - ((2 * pow(radiox, 2) * yk) - (2 * pow(radiox, 2))) + pow(radioy, 2);
			xk = xk + 1;
			yk = yk - 1;
			finy = 2 * pow(radioy, 2) * xk;
			finx = 2 * pow(radiox, 2) * yk;
			if (pkeli < 0) {
				cout << cuenta << "  " << xk << yk << "  " << pkeli << "  " << "     " << "  " << finy << "  " << finx << endl;
			}
			else {
				cout << cuenta << "  " << xk << yk << "  " << "     " << "  " << pkeli << "  " << finy << "  " << finx << endl;
			}
		}
		cuenta++;
	} while (finy < finx);
	// Region 2
	xk2 = xk;
	yk2 = yk;
	paramini2 = (pow(radioy, 2) * pow(xk2 + 0.5, 2)) + (pow(radiox, 2) * pow(yk2 - 1, 2)) - (pow(radioy, 2) * pow(radiox, 2));
	cout << "K" << "  " << "xk,yk" << "  " << "Pk<=0" << "  " << "Pk>0" << endl;
	if (paramini2 > 0) {
		cout << 0 << " " << xk2 << yk2 << "  " << "     " << " " << paramini2 << endl;
	}
	else {
		cout << 0 << " " << xk2 << yk2 << "  " << paramini2 << " " << endl;
	}

	pkeli2 = paramini2;
	int cuenta2 = 1;
	do {
		if (pkeli2 <= 0) {
			pkeli2 = pkeli2 + ((2 * pow(radioy, 2) * xk2) + (2 * pow(radioy, 2))) - ((2 * pow(radiox, 2) * yk2) - (2 * pow(radiox, 2))) + pow(radiox, 2);
			xk2 = xk2 + 1;
			yk2 = yk2 - 1;
			if (pkeli2 <= 0) {
				cout << cuenta2 << " " << xk2 << yk2 << "  " << pkeli2 << " " << endl;
			}
			else {
				cout << 0 << " " << xk2 << yk2 << "  " << "     " << " " << pkeli2 << endl;
			}
		}
		else {
			pkeli2 = pkeli2 - ((2 * pow(radiox, 2) * yk2) - (2 * pow(radiox, 2))) + pow(radiox, 2);
			xk2 = xk2;
			yk2 = yk2 - 1;
			if (pkeli2 <= 0) {
				cout << cuenta2 << " " << xk2 << yk2 << "  " << pkeli2 << " " << endl;
			}
			else {
				cout << 0 << " " << xk2 << yk2 << "  " << "     " << " " << pkeli2 << endl;
			}
		}
	} while (yk2 != 0);


	parentesis cuaterniones

	cout << "Rotacion de cuaterniones" << endl;
	cout << "Introducir punto" << endl;
	cout << "i:";
	cin >> puntox;
	cout << endl;
	cout << "j:";
	cin >> puntoy;
	cout << endl;
	cout << "k:";
	cin >> puntoz;
	cout << endl;
	cout << "Introducir angulo" << endl;
	cin >> angulo;
	cout << "Introducir vector" << endl;
	cout << "i:";
	cin >> vectorx;
	cout << endl;
	cout << "j:";
	cin >> vectory;
	cout << endl;
	cout << "k:";
	cin >> vectorz;
	cout << endl;
	vunitario = sqrt(pow(vectorx, 2) + pow(vectory, 2) + pow(vectorz, 2));
	float q1, q2, q3, q4;
	q1 = cos((angulo / 2) * PI / 180);
	q2 = (vectorx / vunitario) * sin((angulo / 2) * PI / 180);
	q3 = (vectory / vunitario) * sin((angulo / 2) * PI / 180);
	q4 = (vectorz / vunitario) * sin((angulo / 2) * PI / 180);
	cout << "w=" << q1 << endl;
	cout << "x=" << q2 << endl;
	cout << "y=" << q3 << endl;
	cout << "z=" << q4 << endl;


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
	cout << columna11 << endl;
	cout << columna12 << endl;
	cout << columna13 << endl;
	cout << columna21 << endl;
	cout << columna22 << endl;
	cout << columna23 << endl;
	cout << columna31 << endl;
	cout << columna32 << endl;
	cout << columna33 << endl;

	irotado = (columna11 * puntox) + (columna21 * puntoy) + (columna31 * puntoz);
	jrotado = (columna12 * puntox) + (columna22 * puntoy) + (columna32 * puntoz);
	krotado = (columna13 * puntox) + (columna23 * puntoy) + (columna33 * puntoz);
	cout << "Puntos rotados" << endl;
	cout << "i" << irotado;
	cout << "j" << jrotado;
	cout << "k" << krotado;
	cout << endl;

	/*
	parentesis division de circulo
	*/ /*
	cout << "Trazado de circulo en origen" << endl;
	cout << "Introducir radio del circulo" << endl;
	cin >> radiocir;
	paraminicialcir = 1 - radiocir;
	if (paraminicialcir < 0) {
		cout << "K" << "	" << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << "        " << endl;
		cout << "0" << "	" << xkcir << "," << radiocir << "	    " << paraminicialcir << "       " << "    " << endl;
	}
	else {
		cout << "K" << "       " << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << "        " << endl;
		cout << "0" << "       " << xkcir << "," << radiocir << "     " << "    " << "		 " << paraminicialcir << endl;
	}

	int pkcir = paraminicialcir, j = 1, k = 0;
	ykcir = radiocir;
	int xkcirinv[20], ykcirinv[20];
	for (int i = xkcir; i < ykcir; i++) {
		if (pkcir < 0) {
			pkcir = pkcir + ((2 * xkcir) + 2) + 1;
			xkcir = xkcir + 1;
			xkcirinv[k] = xkcir;
			ykcirinv[k] = ykcir;
			if (pkcir < 0) {
				cout << j << "       " << xkcir << "," << ykcir << "	    " << pkcir << "       " << "    " << endl;
			}
			else {
				cout << j << "       " << xkcir << "," << ykcir << "     " << "    " << "		 " << pkcir << endl;
			}
		}
		else {
			pkcir = pkcir + ((2 * xkcir) + 2) + 1 - ((2 * ykcir) - 2);
			xkcir = xkcir + 1;
			ykcir = ykcir - 1;
			xkcirinv[k] = xkcir;
			ykcirinv[k] = ykcir;
			if (pkcir < 0) {
				cout << j << "       " << xkcir << "," << ykcir << "	    " << pkcir << "       " << "    " << endl;
			}
			else {
				cout << j << "       " << xkcir << "," << ykcir << "     " << "    " << "		 " << pkcir << endl;
			}
		}
		j++;
		k++;
	}
	for (int i = 0; i < k; i++) {
		cout << " " << "       " << ykcir << "," << xkcir << "	    " << "       " << "    " << endl;
	}

	/*
	parentesis division de linea
	*/ /*
	cout << "Introducir X0" << endl;
	cin >> x0;
	cout << "Introducir Y0" << endl;
	cin >> y0;
	cout << "Introducir X1" << endl;
	cin >> x1;
	cout << "Introducir Y1" << endl;
	cin >> y1;
	dx = x1 - x0;
	dy = y1 - y0;
	veces = dx - 1;
	abscisa = x0;
	ordenada = y0;
	paraminicial = (2 * dy) - dx;

	if (paraminicial < 0) {
		cout << "K" << "       " << "" << "       " << "Pk<0" << "       " << "Pk>=0" << endl;
		cout << "0" << "       " << abscisa << "," << ordenada << "     " << paraminicial << "       " << "    " << endl;
	}
	else {
		cout << "K" << "       " << "" << "       " << "Pk<0" << "       " << "Pk>=0" << endl;
		cout << "0" << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << paraminicial << endl;
	}

	int pk = paraminicial;

	if (veces > 1) {
		for (int i = 0; i < veces; i++) {
			if (pk >= 0) {
				abscisa = abscisa + 1;
				ordenada = ordenada + 1;
				if (pk >= 0) {
					pk = pk + (2 * dy) - (2 * dx);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}
				}
				else {
					pk = pk + (2 * dy);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}

				}
			}
			else {
				abscisa = abscisa + 1;
				if (pk >= 0) {
					pk = pk + (2 * dy) - (2 * dx);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}
				}
				else {
					pk = pk + (2 * dy);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}

				}

			}

			/* if (pk >= 0) {
				pk = pk + (2 * dy) - (2 * dx);
			}
			else {
				pk = pk + (2 * dy);
			} */ /*
		}
	}
	else {
		system("PAUSE");
	}
	system("PAUSE");
	*/
}

void leerMatriz(int** M, int fil, int col)
{
	cout << "\nRellenar la matriz:\n";
	for (int i = 0; i < fil; i++) {
		for (int j = 0; j < col; j++) {
			cout << "Matriz[" << i << "][" << j << "]: ";
			cin >> M[i][j];
		}
	}
}

void sumaMatrices()
{
	system("cls");
	int fil, col;
	cout << "Suma de matrices" << endl;
	cout << "\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
		<< "\nDimension de la matriz:";
	cout << "\nFilas de la matriz: "; cin >> fil;
	cout << "Columnas de la matriz: "; cin >> col;

	int** A = new int* [fil];
	for (int i = 0; i < fil; i++)
		A[i] = new int[col];

	int** B = new int* [fil];
	for (int i = 0; i < fil; i++)
		B[i] = new int[col];

	int** C = new int* [fil];
	for (int i = 0; i < fil; i++)
		C[i] = new int[col];

	cout << "\nDatos de la matriz A: ";
	leerMatriz(A, fil, col);

	cout << "\nDatos de la matriz B: ";
	leerMatriz(B, fil, col);

	for (int i = 0; i < fil; i++)
		for (int j = 0; j < col; j++)
			C[i][j] = A[i][j] + B[i][j];

	cout << "\nMatriz A:\n";
	imprimirMatriz(A, fil, col);
	cout << "\nMatriz B:\n";
	imprimirMatriz(B, fil, col);
	cout << "\nSuma de las matrices (A+B):\n";
	imprimirMatriz(C, fil, col);

	system("PAUSE");

}

void restaMatrices()
{
	system("cls");
	int fil, col;
	cout << "Resta de matrices" << endl;
	cout << "\nLAS MATRICES DEBEN TENER LA MISMA DIMENSION\n"
		<< "\nDimension de la matriz:";
	cout << "\nFilas de la matriz: "; cin >> fil;
	cout << "Columnas de la matriz: "; cin >> col;

	int** A = new int* [fil];
	for (int i = 0; i < fil; i++)
		A[i] = new int[col];

	int** B = new int* [fil];
	for (int i = 0; i < fil; i++)
		B[i] = new int[col];

	int** C = new int* [fil];
	for (int i = 0; i < fil; i++)
		C[i] = new int[col];

	cout << "\nDatos de la matriz A: ";
	leerMatriz(A, fil, col);

	cout << "\nDatos de la matriz B: ";
	leerMatriz(B, fil, col);

	for (int i = 0; i < fil; i++)
		for (int j = 0; j < col; j++)
			C[i][j] = A[i][j] - B[i][j];

	cout << "\nMatriz A:\n";
	imprimirMatriz(A, fil, col);
	cout << "\nMatriz B:\n";
	imprimirMatriz(B, fil, col);
	cout << "\nResta de las matrices (A-B):\n";
	imprimirMatriz(C, fil, col);

	system("PAUSE");
}

void multiplicacionMatrices()
{
	system("cls");
	int filA, colA, filB, colB;
	cout << "Multiplicacion de matrices" << endl;
	cout << "\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
		<< "\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRI B\n";

	cout << "\nDimension de la matriz A:";
	cout << "\nFilas de la matriz: "; cin >> filA;
	cout << "Columnas de la matriz: "; cin >> colA;

	int** A = new int* [filA];
	for (int i = 0; i < filA; i++)
		A[i] = new int[colA];

	leerMatriz(A, filA, colA);

	cout << "\nDimension de la matriz B:";
	cout << "\nFilas de la matriz: "; cin >> filB;
	cout << "Columnas de la matriz: "; cin >> colB;

	int** B = new int* [filB];
	for (int i = 0; i < filB; i++)
		B[i] = new int[colB];

	leerMatriz(B, filB, colB);

	int** C = new int* [filA];
	for (int i = 0; i < filA; i++)
		C[i] = new int[colA];

	if (colA == filB) {
		for (int i = 0; i < filA; ++i) {
			for (int j = 0; j < colB; ++j) {
				C[i][j] = 0;
				for (int z = 0; z < colA; ++z)
					C[i][j] += A[i][z] * B[z][j];
			}
		}

		cout << "\nMatriz A:\n";
		imprimirMatriz(A, filA, colA);
		cout << "\nMatriz B:\n";
		imprimirMatriz(B, filB, colB);
		cout << "\nMultiplicacion de las matrices (A*B):\n";
		imprimirMatriz(C, filA, colB);

	}
	else
		cout << "\n         NO SE PUEDEN MULTIPLICAR"
		<< "\n    EL NUMERO DE COLUMNAS DE LA MATRIZ A"
		<< "\nDEBE COINCIDIR CON EL DE FILAS DE LA MATRI B";

	system("PAUSE");

}

void imprimirMatriz(int** M, int fil, int col)
{
	for (int i = 0; i < fil; i++) {
		cout << "\n| ";
		for (int j = 0; j < col; j++)
			cout << M[i][j] << " ";

		cout << " |";
	}
	cout << endl;
}

void agregalista() {
	aux->id = ids;
	ids++;

	if (inicio == 0) {
		inicio = aux;
		ultimo = aux;
		aux->sig = 0;
	}
	else {
		ultimo->sig = aux;
		ultimo = aux;
		aux->sig = 0;
	}
}

void mostrar() {
	aux = inicio;

	while (aux != 0) {
		cout << endl;
		cout << "La matriz " << aux->id << " es:\n";
		for (int i = 0; i < aux->filas; i++) {
			cout << endl;
			for (int j = 0; j < aux->columnas; j++) {
				cout << "[" << aux->elementos[i][j] << "]";
			}
		}
		aux = aux->sig;
	}

}

void agregamatriz()
{

	
	aux = new matriz;



	cout << "Ingrese las filas: ";
	while (1) {
		cin >> aux->filas;
		if (aux->filas > 0) {
			break;
		}
		else {
			cout << "Ingrese un numero de filas correcto";
		}
	}
	cout << "Ingrese las columnas: ";
	while (1) {
		cin >> aux->columnas;
		if (aux->columnas > 0) {
			break;
		}
		else {
			cout << "Ingrese un numero de columnas correcto";
		}
	}


	for (int i = 0; i < aux->filas; i++) {
		for (int j = 0; j < aux->columnas; j++) {
			cout << "Ingrese el elemento[" << i + 1 << "][" << j + 1 << "]:";
			cin >> aux->elementos[i][j];
		}
	}

	cout << "La matriz es:";

	for (int i = 0; i < aux->filas; i++) {
		cout << endl;
		for (int j = 0; j < aux->columnas; j++) {
			cout << "[" << aux->elementos[i][j] << "]";
		}
	}
	agregalista();
	cout << "\n";
	system("PAUSE");
}

void rotacion() {
	system("cls");
	cout << "Rotacion de matriz" << endl;
	cout << "Ingresa el punto (x, y, z)\nx:";
	cin >> x;
	cout << "y:";
	cin >> y;
	cout << "z:";
	cin >> z;
	{
		punto.filas = 4;
		punto.columnas = 4;
		punto.elementos[0][0] = 1;
		punto.elementos[0][1] = 0;
		punto.elementos[0][2] = 0;
		punto.elementos[0][3] = x;//
		punto.elementos[1][0] = 0;
		punto.elementos[1][1] = 1;
		punto.elementos[1][2] = 0;
		punto.elementos[1][3] = y;//
		punto.elementos[2][0] = 0;
		punto.elementos[2][1] = 0;
		punto.elementos[2][2] = 1;
		punto.elementos[2][3] = z;//
		punto.elementos[3][0] = 0;
		punto.elementos[3][1] = 0;
		punto.elementos[3][2] = 0;
		punto.elementos[3][3] = 1;//
	}
	matrizB = &punto;
	cout << "Seleccione respecto a que plano rotara\n1.X\n2.Y\n3.Z\nOpcion:";
	cin >> opc;
	switch (opc)
	{
	case 1:
		matrizA = &rotacionx;
		break;
	case 2:
		matrizA = &rotaciony;
		break;
	case 3:
		matrizA = &rotacionz;
		break;
	default:
		break;
	}

	cout << "Ingrese el angulo con el que se rotara:";
	cin >> angulo;
	if (matrizA->filas == matrizB->columnas) {
		cout << "La matriz resultante es:";
		aux = new matriz;
		aux->columnas = matrizA->columnas;
		aux->filas = matrizA->filas;

		for (int i = 0; i < matrizA->filas; i++) {
			for (int j = 0; j < matrizB->columnas; j++) {
				aux->elementos[i][j] = 0;
				for (int k = 0; k < matrizA->columnas; k++) {
					aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
				}
			}
		}
		aux->filas = matrizA->filas;
		aux->columnas = matrizB->columnas;

		cout << "\n";
		for (int i = 0; i < aux->filas; i++) {
			cout << endl;
			for (int j = 0; j < aux->columnas; j++) {
				cout << "[" << aux->elementos[i][j] << "]";
			}
		}


		agregalista();
		cout << "\n";
		cout << "Se guardo en la lista de matrices";
		cout << "\n";
		system("Pause");
	}
	system("PAUSE");
}

void matrixpunto() {
	system("cls");
	cout << "Matriz por punto" << endl;
	cout << "Selecciona la Matriz compuesta:";
	agregamatriz();
	mostrar();

	cin >> opc;
	cout << "Ingrese el punto (x,y,z)\nx:";
	cin >> x;
	cout << "y:";
	cin >> y;
	cout << "z:";
	cin >> z;

	matriz matripunt;
	matripunt.columnas = 1;
	matripunt.filas = 4;
	matripunt.elementos[0][0] = x;
	matripunt.elementos[1][0] = y;
	matripunt.elementos[2][0] = z;
	matripunt.elementos[3][0] = 1;

	matrizB = &matripunt;

	aux = new matriz;
	aux = inicio;
	while (aux != 0)
	{
		if (aux->id == opc) {
			matrizA = aux;
		}
		aux = aux->sig;
	}
	if (matrizA->columnas == matrizB->filas) {
		cout << "El punto transformado es:";
		aux = new matriz;
		for (int i = 0; i < matrizA->filas; i++) {
			for (int j = 0; j < matrizB->columnas; j++) {
				aux->elementos[i][j] = 0;
				for (int k = 0; k < matrizA->columnas; k++) {
					aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
				}
			}
		}
		aux->filas = matrizA->filas;
		aux->columnas = matrizB->columnas;

		cout << "\n";
		for (int i = 0; i < aux->filas; i++) {
			cout << endl;
			for (int j = 0; j < aux->columnas; j++) {
				cout << "[" << aux->elementos[i][j] << "]";
			}
		}

		system("PAUSE");
	}
	else {
		cout << "No se puede multiplicar esa matriz por el punto";
		system("PAUSE");
	}
}

void matrizcompuesta() {
	double ex = 0, ey = 0, ez = 0, tx = 0, ty = 0, tz = 0;

	int cos90 = 0;

	traslacion.columnas = 4;
	traslacion.filas = 4;
	escalasion.columnas = 4;
	escalasion.filas = 4;
	{
		traslacion.elementos[0][0] = 1;
		traslacion.elementos[0][1] = 0;
		traslacion.elementos[0][2] = 0;
		traslacion.elementos[0][3] = tx;

		traslacion.elementos[1][0] = 0;
		traslacion.elementos[1][1] = 1;
		traslacion.elementos[1][2] = 0;
		traslacion.elementos[1][3] = ty;

		traslacion.elementos[2][0] = 0;
		traslacion.elementos[2][1] = 0;
		traslacion.elementos[2][2] = 1;
		traslacion.elementos[2][3] = tz;

		traslacion.elementos[3][0] = 0;
		traslacion.elementos[3][1] = 0;
		traslacion.elementos[3][2] = 0;
		traslacion.elementos[3][3] = 1;
	}
	{
		escalasion.elementos[0][0] = ex;
		escalasion.elementos[0][1] = 0;
		escalasion.elementos[0][2] = 0;
		escalasion.elementos[0][3] = 0;

		escalasion.elementos[1][0] = 0;
		escalasion.elementos[1][1] = ey;
		escalasion.elementos[1][2] = 0;
		escalasion.elementos[1][3] = 0;

		escalasion.elementos[2][0] = 0;
		escalasion.elementos[2][1] = 0;
		escalasion.elementos[2][2] = ez;
		escalasion.elementos[2][3] = 0;

		escalasion.elementos[3][0] = 0;
		escalasion.elementos[3][1] = 0;
		escalasion.elementos[3][2] = 0;
		escalasion.elementos[3][3] = 1;
	}
	{
		matriz_identida.filas = 4;
		matriz_identida.columnas = 4;
		matriz_identida.elementos[0][0] = 1;
		matriz_identida.elementos[0][1] = 0;
		matriz_identida.elementos[0][2] = 0;
		matriz_identida.elementos[0][3] = 0;

		matriz_identida.elementos[1][0] = 0;
		matriz_identida.elementos[1][1] = 1;
		matriz_identida.elementos[1][2] = 0;
		matriz_identida.elementos[1][3] = 0;

		matriz_identida.elementos[2][0] = 0;
		matriz_identida.elementos[2][1] = 0;
		matriz_identida.elementos[2][2] = 1;
		matriz_identida.elementos[2][3] = 0;

		matriz_identida.elementos[3][0] = 0;
		matriz_identida.elementos[3][1] = 0;
		matriz_identida.elementos[3][2] = 0;
		matriz_identida.elementos[3][3] = 1;
	}


	aux = new matriz;

	_matrizC = matriz_identida;
	_matrizA = matriz_identida;
	_matrizB = matriz_identida;

	_matrizC.filas = 4;
	_matrizC.columnas = 4;

	bool aln = 1;
	bool simba = 1;


	while (simba)
	{
		system("CLS");

		cout << "La matriz compuesta es:";

		cout << "\n";
		for (int i = 0; i < _matrizC.filas; i++) {
			cout << endl;
			for (int j = 0; j < _matrizC.columnas; j++) {
				cout << "[" << _matrizC.elementos[i][j] << "]";
			}
		}
		cout << "\n";
		/*
			for (int i = 0; i < matrizA->filas; i++) {
				for (int j = 0; j < matrizB->columnas; j++) {
					aux->elementos[i][j] = 0;
					for (int k = 0; k < matrizA->columnas; k++) {
						aux->elementos[i][j] = aux->elementos[i][j] + matrizA->elementos[i][k] * matrizB->elementos[k][j];
					}
				}
			}
			*/
		cout << "Matriz compuesta" << endl;
		cout << "1.Rotar \n 2.Trasladar \n3.Escalar\n 4.Aplicarse en puntos (Utilizar la matriz actual)\n 5. Salir \nopc:";
		cin >> opc;
		switch (opc)
		{
		case 1:
		{
			cout << "Cuantos grados desea rotar?\nAngulo:";
			cin >> angulo;
			if (angulo == 90) {
				cos90 = 1;
			}
			else if (angulo == 180) {
				cos90 = 2;
			}
			else if (angulo == 270) {
				cos90 = 3;
			}
			else if (angulo == 360) {
				cos90 = 4;
			}
			angulo = angulo * pi / 180;
			cout << "En que eje deseas rotar? 1.x 2.y 3.z\nopc:";
			cin >> opc;
			switch (opc)
			{
			case 1:
				_matrizA = _matrizC;
				{
					rotacionx.elementos[0][0] = 1;
					rotacionx.elementos[0][1] = 0;
					rotacionx.elementos[0][2] = 0;
					rotacionx.elementos[0][3] = 0;//
					rotacionx.elementos[1][0] = 0;

					rotacionx.elementos[1][1] = cos(angulo * pi / 180);
					rotacionx.elementos[1][2] = -sin(angulo * pi / 180);
					if (cos90 == 1) {
						rotacionx.elementos[1][1] = 0;
						rotacionx.elementos[1][2] = -1;
					}
					rotacionx.elementos[1][3] = 0;//
					rotacionx.elementos[2][0] = 0;
					rotacionx.elementos[2][1] = sin(angulo * pi / 180);
					rotacionx.elementos[2][2] = cos(angulo * pi / 180);
					if (cos90 == 1) {
						rotacionx.elementos[2][1] = 1;
						rotacionx.elementos[2][2] = 0;
					}
					rotacionx.elementos[2][3] = 0;//
					rotacionx.elementos[3][0] = 0;
					rotacionx.elementos[3][1] = 0;
					rotacionx.elementos[3][2] = 0;
					rotacionx.elementos[3][3] = 1;//
				}
				_matrizB = rotacionx;
				break;
			case 2:
				_matrizA = _matrizC;
				{
					rotaciony.elementos[0][0] = cos(angulo * pi / 180);
					rotaciony.elementos[0][1] = 0;
					rotaciony.elementos[0][2] = sin(angulo * pi / 180);
					if (cos90 == 1) {
						rotaciony.elementos[0][0] = 0;
						rotaciony.elementos[0][2] = 1;
					}
					rotaciony.elementos[0][3] = 0;//
					rotaciony.elementos[1][0] = 0;
					rotaciony.elementos[1][1] = 1;
					rotaciony.elementos[1][2] = 0;
					rotaciony.elementos[1][3] = 0;//
					rotaciony.elementos[2][0] = -sin(angulo * pi / 180);
					rotaciony.elementos[2][1] = 0;
					rotaciony.elementos[2][2] = cos(angulo * pi / 180);
					if (cos90 == 1) {
						rotaciony.elementos[2][0] = -1;
						rotaciony.elementos[2][2] = 0;
					}
					rotaciony.elementos[2][3] = 0;//
					rotaciony.elementos[3][0] = 0;
					rotaciony.elementos[3][1] = 0;
					rotaciony.elementos[3][2] = 0;
					rotaciony.elementos[3][3] = 1;//
				}

				_matrizB = rotaciony;
				break;
			case 3:
				_matrizA = _matrizC;
				{
					rotacionz.elementos[0][0] = cos(angulo * pi / 180);
					rotacionz.elementos[0][1] = sin(angulo * pi / 180);
					if (cos90 == 1) {
						rotacionz.elementos[0][0] = 0;
						rotacionz.elementos[0][1] = 1;
					}
					rotacionz.elementos[0][2] = 0;
					rotacionz.elementos[0][3] = 0;//
					rotacionz.elementos[1][0] = sin(angulo * pi / 180);
					rotacionz.elementos[1][1] = cos(angulo * pi / 180);
					if (cos90 == 1) {
						rotacionz.elementos[1][0] = 1;
						rotacionz.elementos[1][1] = 0;
					}
					rotacionz.elementos[1][2] = 0;
					rotacionz.elementos[1][3] = 0;//
					rotacionz.elementos[2][0] = 0;
					rotacionz.elementos[2][1] = 0;
					rotacionz.elementos[2][2] = 1;
					rotacionz.elementos[2][3] = 0;//
					rotacionz.elementos[3][0] = 0;
					rotacionz.elementos[3][1] = 0;
					rotacionz.elementos[3][2] = 0;
					rotacionz.elementos[3][3] = 1;//
				}
				_matrizB = rotacionz;
				break;
			default:
				break;
			}

		}
		break;
		case 2:
		{
			cout << "Cuanto quiere trasladar en (x,y,z)\nx:";
			cin >> tx;
			cout << "y:";
			cin >> ty;
			cout << "z:";
			cin >> tz;
			{
				traslacion.elementos[0][0] = 1;
				traslacion.elementos[0][1] = 0;
				traslacion.elementos[0][2] = 0;
				traslacion.elementos[0][3] = tx;

				traslacion.elementos[1][0] = 0;
				traslacion.elementos[1][1] = 1;
				traslacion.elementos[1][2] = 0;
				traslacion.elementos[1][3] = ty;

				traslacion.elementos[2][0] = 0;
				traslacion.elementos[2][1] = 0;
				traslacion.elementos[2][2] = 1;
				traslacion.elementos[2][3] = tz;

				traslacion.elementos[3][0] = 0;
				traslacion.elementos[3][1] = 0;
				traslacion.elementos[3][2] = 0;
				traslacion.elementos[3][3] = 1;
			}
			_matrizA = _matrizC;
			_matrizB = traslacion;
		}
		break;
		case 3:
		{
			cout << "Cuanto quiere escalar en (x,y,z)\nx:";
			cin >> ex;
			cout << "y:";
			cin >> ey;
			cout << "z:";
			cin >> ez;
			{
				escalasion.elementos[0][0] = ex;
				escalasion.elementos[0][1] = 0;
				escalasion.elementos[0][2] = 0;
				escalasion.elementos[0][3] = 0;

				escalasion.elementos[1][0] = 0;
				escalasion.elementos[1][1] = ey;
				escalasion.elementos[1][2] = 0;
				escalasion.elementos[1][3] = 0;

				escalasion.elementos[2][0] = 0;
				escalasion.elementos[2][1] = 0;
				escalasion.elementos[2][2] = ez;
				escalasion.elementos[2][3] = 0;

				escalasion.elementos[3][0] = 0;
				escalasion.elementos[3][1] = 0;
				escalasion.elementos[3][2] = 0;
				escalasion.elementos[3][3] = 1;
			}
			_matrizA = _matrizC;
			_matrizB = escalasion;
		}
		break;
		case 4:


			matrizele();
			simba = 0;
			break;
		case 5:
			simba = NULL;
			break;
		default:
			break;
		}
		_matrizA.filas = 4;
		_matrizB.columnas = 4;


		for (int i = 0; i < _matrizA.filas; i++) {
			for (int j = 0; j < _matrizB.columnas; j++) {
				_matrizC.elementos[i][j] = 0;
				for (int k = 0; k < _matrizA.columnas; k++) {
					_matrizC.elementos[i][j] = _matrizC.elementos[i][j] + _matrizA.elementos[i][k] * _matrizB.elementos[k][j];
				}
			}
		}
	}
}

void matrizele()
{
	_matrizA = _matrizC;
	while (1)
	{
		system("CLS");

		cout << "Ingresa los puntos (x,y,z)\nx:";
		cin >> x;
		cout << "y:";
		cin >> y;
		cout << "z:";
		cin >> z;
		{
			matriz matripunt;
			matripunt.columnas = 1;
			matripunt.filas = 4;
			matripunt.elementos[0][0] = x;
			matripunt.elementos[1][0] = y;
			matripunt.elementos[2][0] = z;
			matripunt.elementos[3][0] = 1;

			_matrizB = matripunt;
		}
		for (int i = 0; i < _matrizA.filas; i++) {
			for (int j = 0; j < _matrizB.columnas; j++) {
				_matrizC.elementos[i][j] = 0;
				for (int k = 0; k < _matrizA.columnas; k++) {
					_matrizC.elementos[i][j] = _matrizC.elementos[i][j] + _matrizA.elementos[i][k] * _matrizB.elementos[k][j];
				}
			}
		}

		_matrizC.filas = 4;
		_matrizC.columnas = 1;

		cout << "\nEl punto es (x,y,z):\n";
		for (int i = 0; i < _matrizC.filas; i++) {
			cout << endl;
			for (int j = 0; j < _matrizC.columnas; j++) {
				cout << "[" << _matrizC.elementos[i][j] << "]";
			}
		}
		cout << "\n1.Ingresar otro punto \n2.Salir";
		cin >> opc;
		if (opc == 1) {

		}
		else {
			break;
		}

	}

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
	cout << "w=" << q1 << endl;
	cout << "x=" << q2 << endl;
	cout << "y=" << q3 << endl;
	cout << "z=" << q4 << endl;

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
	cout << "Matriz:" << endl;
	cout << columna11 << " " << columna21 << " " << columna31 << " " << 0 << endl;
	cout << columna12 << " " << columna22 << " " << columna32 << " " << 0 << endl;
	cout << columna13 << " " << columna23 << " " << columna33 << " " << 0 << endl;
	cout << 0 << " " << 0 << " " << 0 << " " << 1 << endl;

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

void lineaBresenham() {
	system("cls");
	cout << "Trazado de linea de Bresenham" << endl;
	int x0, y0, x1, y1, dx, dy, veces, abscisa, ordenada, paraminicial;
	cout << "Introducir X0" << endl;
	cin >> x0;
	cout << "Introducir Y0" << endl;
	cin >> y0;
	cout << "Introducir X1" << endl;
	cin >> x1;
	cout << "Introducir Y1" << endl;
	cin >> y1;
	dx = x1 - x0;
	dy = y1 - y0;
	veces = dx - 1;
	abscisa = x0;
	ordenada = y0;
	paraminicial = (2 * dy) - dx;

	if (paraminicial < 0) {
		cout << "K" << "       " << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << endl;
		cout << "0" << "       " << abscisa << "," << ordenada << "     " << paraminicial << "       " << "    " << endl;
	}
	else {
		cout << "K" << "       " << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << endl;
		cout << "0" << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << paraminicial << endl;
	}

	int pk = paraminicial;

	if (veces > 1) {
		for (int i = 0; i < veces; i++) {
			if (pk >= 0) {
				abscisa = abscisa + 1;
				ordenada = ordenada + 1;
				if (pk >= 0) {
					pk = pk + (2 * dy) - (2 * dx);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}
				}
				else {
					pk = pk + (2 * dy);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}

				}
			}
			else {
				abscisa = abscisa + 1;
				if (pk >= 0) {
					pk = pk + (2 * dy) - (2 * dx);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}
				}
				else {
					pk = pk + (2 * dy);
					if (pk >= 0) {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << "    " << "       " << pk << endl;
					}
					else {
						cout << i + 1 << "       " << abscisa << "," << ordenada << "     " << pk << "       " << "            " << endl;
					}

				}

			}

			/* if (pk >= 0) {
				pk = pk + (2 * dy) - (2 * dx);
			}
			else {
				pk = pk + (2 * dy);
			} */
		}
	}
	else {
		system("PAUSE");
	}
	system("PAUSE");
}

void circuloBresenham() {
	system("cls");
	int x0cir, y0cir, x1cir, y1cir, radiocir, xkcir = 0, ykcir, paraminicialcir;
	cout << "Trazado de circulo en origen" << endl;
	cout << "Introducir radio del circulo" << endl;
	cin >> radiocir;
	paraminicialcir = 1 - radiocir;
	if (paraminicialcir < 0) {
		cout << "K" << "	" << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << "        " << endl;
		cout << "0" << "	" << xkcir << "," << radiocir << "	    " << paraminicialcir << "       " << "    " << endl;
	}
	else {
		cout << "K" << "       " << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << "        " << endl;
		cout << "0" << "       " << xkcir << "," << radiocir << "     " << "    " << "		 " << paraminicialcir << endl;
	}
	int finalinvx = xkcir;
	int finalinvy = radiocir;
	int pkcir = paraminicialcir, j = 1, k = 0;
	ykcir = radiocir;
	int xkcirinv[20], ykcirinv[20];
	for (int i = xkcir; i < ykcir - 1; i++) {
		if (pkcir < 0) {
			pkcir = pkcir + ((2 * xkcir) + 2) + 1;
			xkcir = xkcir + 1;
			xkcirinv[k] = xkcir;
			ykcirinv[k] = ykcir;
			if (pkcir < 0) {
				cout << j << "       " << xkcir << "," << ykcir << "	    " << pkcir << "       " << "    " << endl;
			}
			else {
				cout << j << "       " << xkcir << "," << ykcir << "     " << "    " << "		 " << pkcir << endl;
			}
		}
		else {
			pkcir = pkcir + ((2 * xkcir) + 2) + 1 - ((2 * ykcir) - 2);
			xkcir = xkcir + 1;
			ykcir = ykcir - 1;
			xkcirinv[k] = xkcir;
			ykcirinv[k] = ykcir;
			if (pkcir < 0) {
				cout << j << "       " << xkcir << "," << ykcir << "	    " << pkcir << "       " << "    " << endl;
			}
			else {
				cout << j << "       " << xkcir << "," << ykcir << "     " << "    " << "		 " << pkcir << endl;
			}
		}

		j++;
		k++;
	}
	for (int i = 1; i < j; i++) {
		cout << " " << "       " << ykcirinv[k - i] << "," << xkcirinv[k - i] << "	    " << "       " << "    " << endl;
	}
	cout << " " << "       " << finalinvy << "," << finalinvx << "	    " << "       " << "    " << endl;
	system("PAUSE");

}

void circulofueraBresenham() {
	system("cls");
	int x0cir, y0cir, x1cir, y1cir, radiocir, xkcir = 0, ykcir, paraminicialcir, coordenadax, coordenaday;
	cout << "Trazado de circulo fuera de origen" << endl;
	cout << "Introducir radio del circulo" << endl;
	cin >> radiocir;
	cout << "Introducir coordenada X de origen" << endl;
	cin >> coordenadax;
	cout << "Introducir coordenada Y de origen" << endl;
	cin >> coordenaday;
	paraminicialcir = 1 - radiocir;
	if (paraminicialcir < 0) {
		cout << "K" << "	" << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << "       " << "Coordenadas relocalizadas" << endl;
		cout << "0" << "	" << xkcir << "," << radiocir << "	    " << paraminicialcir << "       " << "    " << "		" << xkcir + coordenadax << "," << radiocir + coordenaday << endl;
	}
	else {
		cout << "K" << "	" << "xk,yk" << "       " << "Pk<0" << "       " << "Pk>=0" << "       " << "Coordenadas relocalizadas" << endl;
		cout << "0" << "       " << xkcir << "," << radiocir << "     " << "    " << "		 " << paraminicialcir << "		" << xkcir + coordenadax << "," << radiocir + coordenaday << endl;
	}
	int finalinvx = xkcir;
	int finalinvy = radiocir;
	int pkcir = paraminicialcir, j = 1, k = 0;
	ykcir = radiocir;
	int xkcirinv[20], ykcirinv[20];
	for (int i = xkcir; i < ykcir - 1; i++) {
		if (pkcir < 0) {
			pkcir = pkcir + ((2 * xkcir) + 2) + 1;
			xkcir = xkcir + 1;
			xkcirinv[k] = xkcir;
			ykcirinv[k] = ykcir;
			if (pkcir < 0) {
				cout << j << "       " << xkcir << "," << ykcir << "	    " << pkcir << "       " << "    " << "		 " << xkcir + coordenadax << "," << ykcir + coordenaday << endl;
			}
			else {
				cout << j << "       " << xkcir << "," << ykcir << "     " << "    " << "		 " << pkcir << "		 " << xkcir + coordenadax << "," << ykcir + coordenaday << endl;
			}
		}
		else {
			pkcir = pkcir + ((2 * xkcir) + 2) + 1 - ((2 * ykcir) - 2);
			xkcir = xkcir + 1;
			ykcir = ykcir - 1;
			xkcirinv[k] = xkcir;
			ykcirinv[k] = ykcir;
			if (pkcir < 0) {
				cout << j << "       " << xkcir << "," << ykcir << "	    " << pkcir << "       " << "    " << "		 " << xkcir + coordenadax << "," << ykcir + coordenaday << endl;
			}
			else {
				cout << j << "       " << xkcir << "," << ykcir << "     " << "    " << "		 " << pkcir << "		 " << xkcir + coordenadax << "," << ykcir + coordenaday << endl;
			}
		}

		j++;
		k++;
	}
	for (int i = 1; i < j; i++) {
		cout << " " << "       " << ykcirinv[k - i] << "," << xkcirinv[k - i] << "	    " << "       " << "			 " << ykcirinv[k - i] + coordenadax << "," << xkcirinv[k - i] + coordenaday << endl;
	}
	cout << " " << "       " << finalinvy << "," << finalinvx << "	    " << "       " << "			 " << finalinvy + coordenadax << "," << finalinvx + coordenaday << endl;
	system("PAUSE");

}

void elipseBresenham() {
	system("cls");
	float radiox, radioy, xk = 0, yk, finy, finx, paramini, pkeli, paramini2, xk2, yk2, pkeli2;
	cout << "Elipse en origen" << endl;
	cout << "Radio en x" << endl;
	cin >> radiox;
	cout << "Radio en y" << endl;
	cin >> radioy;
	yk = radioy;
	paramini = (pow(radioy, 2)) - (pow(radiox, 2) * radioy) + (.25 * pow(radiox, 2));
	cout << "Region 1" << endl;
	cout << "K" << "  " << "xk,yk" << "  " << "Pk<0" << "  " << "Pk>=0" << "  " << "2ry^2x" << "  " << "2rx^2y" << endl;
	if (paramini >= 0) {
		cout << 0 << "    " << xk << "," << yk << "   " << "        " << "    " << paramini << "    " << 2 * pow(radioy, 2) * xk << "    " << 2 * pow(radiox, 2) * yk << endl;
	}
	else {
		cout << 0 << "    " << xk << "," << yk << "   " << paramini << "    " << "     " << "    " << 2 * pow(radioy, 2) * xk << "    " << 2 * pow(radiox, 2) * yk << endl;
	}
	finy = 2 * pow(radioy, 2) * xk;
	finx = 2 * pow(radiox, 2) * yk;
	pkeli = paramini;
	int cuenta = 1;
	do {
		if (pkeli < 0) {
			pkeli = pkeli + ((2 * pow(radioy, 2) * xk) + (2 * pow(radioy, 2))) + pow(radioy, 2);
			xk = xk + 1;
			yk = yk;
			finy = 2 * pow(radioy, 2) * xk;
			finx = 2 * pow(radiox, 2) * yk;
			if (pkeli < 0) {
				cout << cuenta << "    " << xk << "," << yk << "   " << pkeli << "  " << "     " << "     " << finy << "     " << finx << endl;
			}
			else {
				cout << cuenta << "    " << xk << "," << yk << "   " << "    " << "    " << pkeli << "    " << finy << "     " << finx << endl;
			}
		}
		else {
			pkeli = pkeli + ((2 * pow(radioy, 2) * xk) + (2 * pow(radioy, 2))) - ((2 * pow(radiox, 2) * yk) - (2 * pow(radiox, 2))) + pow(radioy, 2);
			xk = xk + 1;
			yk = yk - 1;
			finy = 2 * pow(radioy, 2) * xk;
			finx = 2 * pow(radiox, 2) * yk;
			if (pkeli < 0) {
				cout << cuenta << "    " << xk << "," << yk << "   " << pkeli << "  " << "     " << "     " << finy << "     " << finx << endl;
			}
			else {
				cout << cuenta << "    " << xk << "," << yk << "   " << "    " << "    " << pkeli << "    " << finy << "     " << finx << endl;
			}
		}
		cuenta++;
	} while (finy < finx);
	cout << endl;
	// Region 2
	xk2 = xk;
	yk2 = yk;
	paramini2 = (pow(radioy, 2) * pow(xk2 + 0.5, 2)) + (pow(radiox, 2) * pow(yk2 - 1, 2)) - (pow(radioy, 2) * pow(radiox, 2));
	cout << "K" << "  " << "xk,yk" << "  " << "Pk<=0" << "  " << "Pk>0" << endl;
	if (paramini2 > 0) {
		cout << 0 << "   " << xk2 << "," << yk2 << "  " << "     " << " " << paramini2 << endl;
	}
	else {
		cout << 0 << "   " << xk2 << "," << yk2 << "  " << paramini2 << " " << endl;
	}

	pkeli2 = paramini2;
	int cuenta2 = 1;
	do {
		if (pkeli2 <= 0) {
			pkeli2 = pkeli2 + ((2 * pow(radioy, 2) * xk2) + (2 * pow(radioy, 2))) - ((2 * pow(radiox, 2) * yk2) - (2 * pow(radiox, 2))) + pow(radiox, 2);
			xk2 = xk2 + 1;
			yk2 = yk2 - 1;
			if (pkeli2 <= 0) {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << pkeli2 << " " << endl;
			}
			else {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << "        " << " " << pkeli2 << endl;
			}
		}
		else {
			pkeli2 = pkeli2 - ((2 * pow(radiox, 2) * yk2) - (2 * pow(radiox, 2))) + pow(radiox, 2);
			xk2 = xk2;
			yk2 = yk2 - 1;
			if (pkeli2 <= 0) {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << pkeli2 << " " << endl;
			}
			else {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << "        " << " " << pkeli2 << endl;
			}
		}
	} while (yk2 != 0);
	system("PAUSE");
}

void elipsefueraBresenham() {
	system("cls");
	float radiox, radioy, xk = 0, yk, finy, finx, paramini, pkeli, paramini2, xk2, yk2, pkeli2;
	int coordenadax, coordenaday;
	cout << "Elipse fuera de origen" << endl;
	cout << "Coordenada del centro x" << endl;
	cin >> coordenadax;
	cout << "Coordenada del centro y" << endl;
	cin >> coordenaday;
	cout << "Radio en x" << endl;
	cin >> radiox;
	cout << "Radio en y" << endl;
	cin >> radioy;
	yk = radioy;
	paramini = (pow(radioy, 2)) - (pow(radiox, 2) * radioy) + (.25 * pow(radiox, 2));
	cout << "Region 1" << endl;
	cout << "K" << "  " << "xk,yk" << "  " << "Pk<0" << "  " << "Pk>=0" << "  " << "2ry^2x" << "  " << "2rx^2y" << "      " << "Coordenadas relocalizadas" << endl;
	if (paramini >= 0) {
		cout << 0 << "    " << xk << "," << yk << "   " << "        " << "    " << paramini << "    " << 2 * pow(radioy, 2) * xk << "    " << 2 * pow(radiox, 2) * yk << "			" << coordenadax + xk << "," << coordenaday + yk << endl;
	}
	else {
		cout << 0 << "    " << xk << "," << yk << " " << paramini << "    " << "   " << "      " << 2 * pow(radioy, 2) * xk << "    " << 2 * pow(radiox, 2) * yk << "			" << coordenadax + xk << "," << coordenaday + yk << endl;
	}
	finy = 2 * pow(radioy, 2) * xk;
	finx = 2 * pow(radiox, 2) * yk;
	pkeli = paramini;
	int cuenta = 1;
	do {
		if (pkeli < 0) {
			pkeli = pkeli + ((2 * pow(radioy, 2) * xk) + (2 * pow(radioy, 2))) + pow(radioy, 2);
			xk = xk + 1;
			yk = yk;
			finy = 2 * pow(radioy, 2) * xk;
			finx = 2 * pow(radiox, 2) * yk;
			if (pkeli < 0) {
				cout << cuenta << "    " << xk << "," << yk << " " << pkeli << "    " << "   " << "      " << finy << "    " << finx << "			" << coordenadax + xk << "," << coordenaday + yk << endl;
			}
			else {
				cout << cuenta << "    " << xk << "," << yk << "   " << "    " << "    " << pkeli << "    " << finy << "     " << finx << "      " << coordenadax + xk << "," << coordenaday + yk << endl;
			}
		}
		else {
			pkeli = pkeli + ((2 * pow(radioy, 2) * xk) + (2 * pow(radioy, 2))) - ((2 * pow(radiox, 2) * yk) - (2 * pow(radiox, 2))) + pow(radioy, 2);
			xk = xk + 1;
			yk = yk - 1;
			finy = 2 * pow(radioy, 2) * xk;
			finx = 2 * pow(radiox, 2) * yk;
			if (pkeli < 0) {
				cout << cuenta << "    " << xk << "," << yk << " " << pkeli << "    " << "   " << "      " << finy << "    " << finx << "			" << coordenadax + xk << "," << coordenaday + yk << endl;
			}
			else {
				cout << cuenta << "    " << xk << "," << yk << "   " << "    " << "    " << pkeli << "    " << finy << "     " << finx << "      " << coordenadax + xk << "," << coordenaday + yk << endl;
			}
		}
		cuenta++;
	} while (finy < finx);
	cout << endl;
	// Region 2
	xk2 = xk;
	yk2 = yk;
	paramini2 = (pow(radioy, 2) * pow(xk2 + 0.5, 2)) + (pow(radiox, 2) * pow(yk2 - 1, 2)) - (pow(radioy, 2) * pow(radiox, 2));
	cout << "K" << "  " << "xk,yk" << "  " << "Pk<=0" << "  " << "Pk>0" << "      " << "Coordenadas relocalizadas" << endl;
	if (paramini2 > 0) {
		cout << 0 << "   " << xk2 << "," << yk2 << "  " << "     " << "   " << paramini2 << "       " << coordenadax + xk2 << "," << coordenaday + yk2 << endl;
	}
	else {
		cout << 0 << "   " << xk2 << "," << yk2 << "  " << paramini2 << " " << "		   " << coordenadax + xk2 << "," << coordenaday + yk2 << endl;
	}

	pkeli2 = paramini2;
	int cuenta2 = 1;
	do {
		if (pkeli2 <= 0) {
			pkeli2 = pkeli2 + ((2 * pow(radioy, 2) * xk2) + (2 * pow(radioy, 2))) - ((2 * pow(radiox, 2) * yk2) - (2 * pow(radiox, 2))) + pow(radiox, 2);
			xk2 = xk2 + 1;
			yk2 = yk2 - 1;
			if (pkeli2 <= 0) {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << pkeli2 << " " << "		   " << coordenadax + xk2 << "," << coordenaday + yk2 << endl;
			}
			else {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << "     " << "   " << pkeli2 << "       " << coordenadax + xk2 << "," << coordenaday + yk2 << endl;
			}
		}
		else {
			pkeli2 = pkeli2 - ((2 * pow(radiox, 2) * yk2) - (2 * pow(radiox, 2))) + pow(radiox, 2);
			xk2 = xk2;
			yk2 = yk2 - 1;
			if (pkeli2 <= 0) {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << pkeli2 << " " << "		   " << coordenadax + xk2 << "," << coordenaday + yk2 << endl;
			}
			else {
				cout << cuenta2 << "   " << xk2 << "," << yk2 << "  " << "     " << "   " << pkeli2 << "       " << coordenadax + xk2 << "," << coordenaday + yk2 << endl;
			}
		}
	} while (yk2 != 0);
	system("PAUSE");
}