
//	Universidad de la cañada
//	Titulo del Programa: "Busca Minas"	
// 	Grupo:201     Segundo Semestre
// 	M.C Jose Alberto Marquez Dominguez
//	Alumno
// 	Jurarez Carrera Javier
//	Junio 2017
# include <conio.h>
# include <stdio.h>
# include <stdlib.h>

void llenar_espacios(char matrizD[4][4]);
void llenar_matriz(char matrizD[4][4]);
void mostrar_matriz(char matrizD[4][4]);
void llenar_minas(char matrizD[4][4]);
int  valida_mina(char matrizD[4][4],int posX, int posY);

int main()
{
	
	char matriz1[4][4];
	char matriz2[4][4];
	int X=0, Y=0;
	int mina = 0;
	int espacio_vacios=12;
	int jugar_dnuevo=0;
	system("color 0b");
	printf("\n---------------------------------BUSCA MINAS------------------------------------\n");
	printf("\n¡¡¡INSTRUCCIONES!!!");
	printf("\n1---EN EL JUEGO EXISTEN 4 MINAS '*'");
	printf("\n2---DESCUBRIR 12 CASILLAS CON ''1'' PARA GANAR, SIN DESCUBRIR NINGUNA MINA");
	printf("\n3---PRESIONAR ENTER AL FINALIZAR CADA ACCION PARA CONTINUAR\n");
	printf("\n Presione enter para continuar...");
	getch();
	printf("\n-------------------------------INICIAR PARTIDA----------------------------------\n");
	printf("\n Presione enter para continuar...");
	do
	{
		llenar_matriz(matriz1);
		llenar_espacios(matriz2);
		llenar_minas(matriz2);
		int bandera=0;
		int puntuacion=0;
		getch();
		do
		{
			system("cls");
	        printf("\n---------------------------------BUSCA MINAS------------------------------------\n");
			printf("\n--------------------------------------------------------------------------------\n");
			system("color 0A");
			mostrar_matriz(matriz1);
			printf("\n--------------------------------------------------------------------------------\n");
			int posicionx=0, posiciony=0;
			do
			{
				printf("\n\t Ingresar la posicion de la Fila del rango de 0 a 3: ");
				scanf("%d",&posicionx);
			}while(posicionx>3);
			do
			{
				printf("\n\t Ingrese la posicion de la Columna del rango de 0 a 3: ");
				scanf("%d",&posiciony);
			}while(posiciony>3);
			if (matriz1[posicionx][posiciony] == '-')
				{
				  mina = valida_mina(matriz2,posicionx, posiciony);	
				  if (mina == 0)
				  	{
				  		matriz1[posicionx][posiciony] = '1';
				  		puntuacion++;
				  	}
				     
				  else
				    {
					 bandera = 1;
					 	posicionx=0;
						posiciony=0;
						for(posicionx=0;posicionx<4;posicionx++)
						{
							for(posiciony=0;posiciony<4;posiciony++)
							{
								if(matriz2[posicionx][posiciony]=='*')
								{
									matriz1[posicionx][posiciony]=matriz2[posicionx][posiciony];
								}
								printf("\n");	
							}
						}
					}
				}		 	
		}while((bandera==0)&&(puntuacion<espacio_vacios));
		if(bandera==0)
		{
			system("cls");
			printf("\n---------------------------------BUSCA MINAS------------------------------------\n");
			printf("\n--------------------------------------------------------------------------------\n");
			mostrar_matriz(matriz1);
			printf("\n--------------------------GANASTES EL JUEGO ¡FELICIDADES!-----------------------\n");
			printf("\nTu puntuacion es:%d",puntuacion);
			printf("\n-------------------------------FIN DEL JUEGO------------------------------------\n");
			printf("\t Presione enter para continuar...");
			getch();
			system("cls");
		}
		else
		{
			system("cls");
			printf("\n---------------------------------BUSCA MINAS------------------------------------\n");
			printf("\n--------------------------------------------------------------------------------\n");
			mostrar_matriz(matriz1);
			printf("\n----------------------LO SENTIMOS HAS PERDIDO EL JUUEGO-------------------------\n");
			printf("\nTu puntuacion es:%d",puntuacion);
			printf("\n-------------------------------FIN DEL JUEGO------------------------------------\n");
			printf("\t Presione enter para continuar...");
			getch();
			system("cls");
		}
		system("color 0E");
		printf("\nDESEA VOLVER A JUAGAR,INGRESAR 1-->si  INGRESAR 2-->no:\n ");
		scanf ("%d",&jugar_dnuevo);
		printf("\t Presione enter para continuar...");
	}while (jugar_dnuevo==1);
	printf("\n\t\t\t creditos:\n\t\t\tJuarez Carrera Javier");
}
void llenar_matriz(char matrizD[4][4])
{
	int posicionx=0,posiciony=0;
	for(posicionx=0;posicionx<4;posicionx++)
	{
		for (posiciony=0;posiciony<4;posiciony++)
		{
			matrizD[posicionx][posiciony]='-';
		}
		printf("\n");
	}
}
void llenar_espacios(char matrizD[4][4])
{
	int posicionx=0,posiciony=0;
	for(posicionx=0;posicionx<4;posicionx++)
	{
		for (posiciony=0;posiciony<4;posiciony++)
		{
			matrizD[posicionx][posiciony]=' ';
		}
		printf("\n");
	}
}
void mostrar_matriz(char matrizD[4][4])
{
	int posicionx=0,posiciony=0;
	printf("\t\tCOLUMNAS");
	printf("\n");
	for(posicionx = 0;posicionx <4; posicionx++)
    printf("\t\t%d ", posicionx);
    printf("\n");  
    printf("\t\t---------------------------------------------------------");
    printf("\n");
	for(posicionx=0;posicionx<4;posicionx++)
	{
		for (posiciony=0;posiciony<4;posiciony++)
		{
			printf("\t\t%c",matrizD[posicionx][posiciony]);
		}
		printf("\t|%d", posicionx);
		printf("\n\n\n");
	}
	printf("\t\t---------------------------------------------------------");
	printf("\t\t\t\t\t\t\t\t\t\t\t\t FILAS");
	
}
void llenar_minas(char matrizD[4][4])
{
	int posicionx=0, posiciony=0, contador=0;
	while(contador<4)
	{
		posicionx=rand()%3;
		posiciony=rand()%3;
		if(matrizD[posicionx][posiciony]!='*')
		{
			matrizD[posicionx][posiciony]='*';
			contador=contador+1;
		}
		else
		{
			matrizD[posicionx][posiciony]= ' ';
			contador=contador-1;
		}
	}
}
int valida_mina(char matrizD[4][4], int posX, int posY)
{
	if (matrizD[posX][posY]==' ')
		return 0;
	else 
		return 1;
}
