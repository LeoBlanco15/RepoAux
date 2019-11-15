#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "LinkedList.h"
#include "Parser.h"
#include"utn.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
	FILE *pFile;
		Empleado* new = employee_new();
		int r;
		char * id;
		char*horasTrabajadas;
		char* salario;
		char *nombre;
		int idInt, horasTrabajadasInt;
		int salarioFloat;
		nombre = (char*)malloc(120*sizeof(char));
		id = (char*)malloc(120*sizeof(char));
		horasTrabajadas = (char*)malloc(120*sizeof(char));
		salario = (char*)malloc(120*sizeof(char));
		if(nombre!=NULL && id!=NULL && horasTrabajadas!=NULL && salario!=NULL)
		{
			pFile = fopen(fileName, "r");
			if(pFile == NULL)
			{
			printf("El archivo no existe");
			exit(EXIT_FAILURE);
			}
			do
			{
				r = fscanf(pFile,"%[^,],%[^,],%[^,\n]\n",id,nombre,horasTrabajadas);
			if(r==3)
			{
				if(esNumerico(id)== 0 && esNumerico(horasTrabajadas)== 0 && esNumerico(salario)== 0)
				{
				salarioFloat= 0;
				idInt = atoi(id);
				horasTrabajadasInt = atoi(horasTrabajadas);
				//salarioFloat= atoi(salario);
				new  =  employee_newParametros(idInt,nombre,horasTrabajadasInt, salarioFloat);
				ll_add(listaEmpleados, new);
				}
			}
			else
			{
				break;
			}

			}while(!feof(pFile));
		}
		fclose(pFile);
		free(id);
		free(nombre);
		free(horasTrabajadas);
		free(salario);
    return 1; // OK
}

