#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define CANT_EMP 1000

int main()
{
    Employee listEmployee[CANT_EMP];
    initEmployees(listEmployee,CANT_EMP);

    int opciones;
    int auxOpcion;
    int auxId;
    int flag=0;
    float auxSumaTotal;
    float auxPromedio;
    do
    {
        printf("\n---------------------------\n");
        if(utn_getValidInt("\n1-Alta\n2-Modificar\n3-Baja\n4-Informes\n5-Salir\nIngrese opcion: ","Error",&opciones,1,5,3)==0)
        {
            switch(opciones)
            {
            case 1:
                printf("\n---------------------------\n");
                if(registerAnEmployee(listEmployee,CANT_EMP)==0)
                {
                    printf("\n---------------------------\n");
                    printf("\n\tALTA EXITOSA\n");
                    flag=1;
                }
                else
                {
                    printf("ERROR");
                }
                break;
            case 2:
                if(flag)
                {
                    printEmployees(listEmployee,CANT_EMP);
                    if(modifyAnEmployee(listEmployee,CANT_EMP)==0)
                    {
                        printf("Se modificaron los datos exitosamente");
                    }
                }
                else
                {
                    printf("\nError, no se cargaron los datos del empleado");
                }
                break;
            case 3:
                if(flag)
                {
                    printEmployees(listEmployee,CANT_EMP);
                    if(utn_getValidInt("Ingrese id: ","Error",&auxId,1,1000,2)==0)
                    {
                        if(removeEmployee(listEmployee,CANT_EMP,auxId)==0)
                        {
                            printf("Baja exitosa");
                        }
                        else
                        {
                            printf("Error");
                        }
                    }
                }
                else
                {
                    printf("\nError, no se cargaron los datos del empleado");
                }
                break;
            case 4:
                if(flag)
                {
                    if(utn_getValidInt("\n1. Listado de los empleados ordenados Alfabeticamente por apellido y sector\n2. Total, promedio de los salarios y cuantos empleados superan el salario\npromedio\n\nIngrese opcion: ",
                                       "\nError, no es una opcion",&auxOpcion,1,2,2)==0)
                    {
                        if(auxOpcion==1)
                        {
                            sortEmployees(listEmployee,CANT_EMP,1);
                            printEmployees(listEmployee,CANT_EMP);
                        }
                        else if(auxOpcion==2)
                        {
                            if(sumaDeSalariosEmployee(listEmployee,CANT_EMP,&auxSumaTotal)==0 &&
                                    promedioDeSalarioEmployee(listEmployee,CANT_EMP,&auxPromedio)==0)
                            {
                                printf("\n\n*Empleado que superan el salario promedio.");
                                employeeQueSuperaElPromedio(listEmployee,CANT_EMP);
                                printf("\n*Suma Total: %.2f",auxSumaTotal);
                                printf("\n*Promedio de salario: %.2f",auxPromedio);
                            }
                        }
                    }
                }
                else
                {
                    printf("\nError, no se cargaron los datos del empleado");
                }
                break;
            case 5:
                break;
            default:
                break;
            }
        }
    }
    while(opciones!=5);
    return 0;
}
