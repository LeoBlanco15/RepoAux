#ifndef EMPLEADO_H_INCLUDED
#define EMPLEADO_H_INCLUDED

struct S_Empleado
{
  int id;
  char nombre[128];
  int horasTrabajadas;
  int sueldo;
};
typedef struct S_Empleado Empleado;

void em_calcularSueldo(void* p);
Empleado* employee_new();
Empleado*  employee_newParametros(int idStr,char* nombreStr,int horasTrabajadasStr, int sueldo);

#endif // EMPLEADO_H_INCLUDED
