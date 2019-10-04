#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "utn.h"
#define OCUPADO 1
#define LIBRE 0

int initEmployees(Employee* list, int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            list[i].isEmpty=LIBRE;
        }
        ret = 0;
    }

    return ret;
}

int findFreePlace(Employee* list, int len)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==LIBRE)
            {
                ret = i;
                break;
            }
        }
    }
    return ret;
}

int findEmployeeById(Employee* list, int len,int id,int *posicion)
{
    int ret = -1;
    int i;
    if(list!=NULL && len>0 && id>=0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id && list[i].isEmpty==OCUPADO)
            {
                *posicion=i;

                ret=0;
                break;
            }
        }
    }
    return ret;
}


int addEmployee(Employee* list, int len, int id, char *name,char *lastName,float salary,int sector)
{
    int ret = -1;
    int posLibre;

    posLibre= findFreePlace(list,len);
    if(list!=NULL && len>0)
    {
        if(posLibre!=-1)
        {
            strncpy(list[posLibre].name,name,51);
            strncpy(list[posLibre].lastName,lastName,51);
            list[posLibre].salary=salary;
            list[posLibre].sector=sector;
            list[posLibre].id=id;
            list[posLibre].isEmpty=OCUPADO;
        }
        ret = 0;
    }
    else
    {
        printf("ERROR en los datos de parametro 'addPersona'\n");
    }
    return ret;
}

int registerAnEmployee(Employee *list,int len)
{
    char auxName[50];
    char auxLastName[50];
    float auxSalary;
    int auxSector;
    int auxId;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        if(utn_getValidName(auxName)==0 && utn_getValidLastName(auxLastName)==0 &&
            utn_getValidFloat("\n*Ingrese Salario: ","\nERROR, no es una Salario.",&auxSalary,0,99999,2)==0 &&
            utn_getValidInt("\n*Ingrese Sector: ","\nERROR, no es una sector.",&auxSector,0,99999,2)==0)
            {
                auxId=generarId();
                addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);
                printf("\n---------------------------\n");
                printf("\nID de Persona: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n",
                auxId,auxName,auxLastName,auxSalary,auxSector);
                ret=0;

            }
        }
    return ret;
}

int modifyAnEmployee(Employee *list,int len)
{
    int ret=-1;
    char auxNombre[51];
    char auxApellido[51];
    float auxSalario;
    int auxSector;
    int auxId;
    int auxPos;
    int opciones;
    if(list!=NULL && len>0)
    {
        if(utn_getValidInt("\nIngrese el id: ","\nError, repuesta incorrecta.",&auxId,1,99999,2)==0)
        {

            if(findEmployeeById(list,len,auxId,&auxPos)==-1)
            {
                printf("\nError, no se encontro Id");
            }
            else
            {
                do
                {
                    if(utn_getValidInt("\n\nQue desea modificar?\n1-Nombre\n2-Apellido\n3-Salario\n4-Sector\n5-Salir\n\nIngrese opcion: ",
                                        "Error",&opciones,1,5,3)==0)
                    {

                        switch(opciones)
                        {
                            case 1:
                                utn_getValidString("\nIngrese nuevo nombre: ","\nError","\nError, excediste el maximo de caracteres.",auxNombre,51,3);
                                strncpy(list[auxPos].name,auxNombre,51);
                                printf("\nNombre nuevo: %s",auxNombre);
                                break;
                            case 2:
                                utn_getValidString("\nIngrese nuevo apellido: ","\nError","\nError, excediste el maximo de caracteres.",auxApellido,51,3);
                                strncpy(list[auxPos].lastName,auxApellido,51);
                                printf("\nNombre: %s",auxApellido);
                                break;
                            case 3:
                                utn_getValidFloat("\nIngrese nuevo salario: ","\nError",&auxSalario,1,999999,3);
                                list[auxPos].salary=auxSalario;
                                break;
                            case 4:
                                utn_getValidInt("\nIngrese nuevo sector: ","\nError",&auxSector,1,999999,3);
                                list[auxPos].sector=auxSector;
                                break;
                            case 5:
                                break;
                            default:
                                printf("\nError, No es una opcion");
                                break;
                        }
                        ret=0;
                    }
                }while(opciones!=5);
            }
        }
    }
    return ret;
}


int removeEmployee(Employee* list, int len,int id)
{
    int retorno=-1;
    int i;
    if(list!=NULL && len>0 && id>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].id==id)
            {
                list[i].isEmpty=LIBRE;
                retorno=0;
            }
        }
    }
    return retorno;
}

int printEmployees(Employee *list,int len)
{
    int i;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                printf("\n---------------------------\n");
                printf("\nId del Empleado: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n",
                       list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
            }
        }
        ret = 0;
    }
    return ret;
}

int printEmployeesById(Employee *list,int len,int id)
{
    int i;
    int ret = -1;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                if(list[i].id==id)
                {
                    printf("\n---------------------------\n");
                    printf("\nId del Empleado: %d\nNombre: %s\nApellido: %s\nSalario: %.2f\nSector: %d\n",
                           list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
                           ret = 0;
                }
            }
        }
    }
    return ret;
}

int sumaDeSalariosEmployee(Employee *list,int len,float *sumaTotal)
{
    int i;
    int ret = -1;
    float suma=0;
    int contador=0;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                suma=list[i].salary+suma;
                contador++;
            }
        }
        *sumaTotal=suma;
        ret = 0;
    }
    return ret;
}

int promedioDeSalarioEmployee(Employee *list,int len,float *promedio)
{
    int i;
    int ret = -1;
    float suma=0;
    int contador=0;
    if(list!=NULL && len>0)
    {
        for(i=0; i<len; i++)
        {
            if(list[i].isEmpty==OCUPADO)
            {
                suma=list[i].salary+suma;
                contador++;
            }
        }
        *promedio=suma/contador;
        ret = 0;
    }
    return ret;
}

int employeeQueSuperaElPromedio(Employee *list,int len)
{
    int i;
    int ret = -1;
    int contadorMayor=0;
    float promedio;
    if(list!=NULL && len>0)
    {
        promedioDeSalarioEmployee(list,len,&promedio);
        for(i=0;i<len;i++)
        {
            if(list[i].salary>promedio && list[i].isEmpty==OCUPADO)
            {
                contadorMayor++;
                printEmployeesById(list,len,list[i].id);
            }
        }
        printf("\nCantidad de empleados que superan el promedio: %d",contadorMayor);
        ret=0;
    }
    return ret;
}

int sortEmployees(Employee* list, int len, int order)
{
    int ret=-1;
    int i,j;
    Employee auxEmpleado;
    int auxSector;
    if(list!=NULL && len>0)
    {
        if(order==1)
        {
            for(i=0;i<len-1;i++)
            {
                for(j=i+1;j<len;j++)
                {
                    if(strncmp(list[i].lastName,list[j].lastName,51)>0)
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                    if(strncmp(list[i].lastName,list[j].lastName,51)==0)
                    {
                        if(list[i].sector>list[j].sector)
                        {
                            auxEmpleado=list[i];
                            list[i]=list[j];
                            list[j]=auxEmpleado;
                        }
                    }
                }
            }
        }
        else if(order==0)
        {
            for(i=0;i<len-1;i++)
            {
                for(j=i+1;j<len;j++)
                {
                    if(strncmp(list[i].lastName,list[j].lastName,51)<0)
                    {
                        auxEmpleado=list[i];
                        list[i]=list[j];
                        list[j]=auxEmpleado;
                    }
                    if(strncmp(list[i].lastName,list[j].lastName,51)==0)
                    {
                        if(list[i].sector>list[j].sector)
                        {
                            auxSector=list[i].sector;
                            list[i].sector=list[j].sector;
                            list[j].sector=auxSector;
                        }
                    }
                }
            }
        }
         ret=0;
    }
    return ret;
}

int generarId(void)
{
    static int idMax=1;
    return idMax++;
}
