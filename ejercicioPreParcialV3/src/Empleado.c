#include "Empleado.h"
#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
void em_calcularSueldo(void* p)
{
	// recibo elemento empleado como void.
	// hacer calculo de sueldo y escribirlo en campo sueldo del empleado
	Empleado* aux;
	int sueldo;
	int horas;
	if(p!=NULL)
	{
		aux=p;
		horas=aux->horasTrabajadas;
		if(horas>=80 && horas<=120)
		{
			sueldo=horas*180;
		}
		else if(horas>120 && horas<=160)
		{
			sueldo=horas*240;
		}
		else if(horas>160 && horas<=240)
		{
			sueldo=horas*350;
		}
		else
		{
			printf("Las horas trabajas estan fuera del rango");
		}
		aux->sueldo=sueldo;
		p=aux;
	}
}
Empleado* employee_new(){

Empleado* emp = (Empleado*)malloc(sizeof(Empleado));

if(emp != NULL){
    emp->id = 0;
    strcpy(emp->nombre, " ");
    emp->horasTrabajadas =0 ;
    emp->sueldo = 0;

}
return emp;
}
Empleado*  employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldo){

Empleado* emp = (Empleado*)malloc(sizeof(Empleado));

if(emp != NULL){
    emp->id = idStr;
    strcpy(emp->nombre, nombreStr);
    emp->horasTrabajadas = horasTrabajadasStr;
    emp->sueldo = sueldo;

}
return emp;
}
