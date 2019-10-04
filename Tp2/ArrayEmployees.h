#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

typedef struct
{
    int id;
    int isEmpty;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
}Employee;

/** \brief Inicializa toda la lista y cambia el isEmpty a 0(Libre).
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o retorno 0 si todo esta ok.
 *
 */

int initEmployees(Employee* list, int len);
/** \brief Busco un lugar libre en la lista.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hubo un error o retorno el lugar libre.
 *
 */

int findFreePlace(Employee* list, int len);
/** \brief Busco un empleado por el Id.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \param Id es el id a comparar si existe.
 * \param Posicion es la posicion que me devuelve mi Id.
 * \return Retorno -1 si hubo un error o retorno el id encontrado.
 *
 */

int findEmployeeById(Employee* list, int len,int id,int *posicion);
/** \brief Busca un lugar libre y da el alta de un empleado
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \param Id es el id del empleado.
 * \param Name es el nombre del empleado.
 * \param LastName es el apellido del empleado.
 * \param salary es el salario del empleado.
 * \param sector es el sector del empleado.
 * \return Retorno -1 si hay error o retorno 0 si los datos fueron cargados.
 *
 */

int addEmployee(Employee* list, int len, int id, char *name,char *lastName,float salary,int sector);
/** \brief Se da la Alta a un empleado
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o retorno 0 si todo esta ok.
 *
 */

int registerAnEmployee(Employee *list,int len);
/** \brief Imprimo todos los empleados.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int printEmployees(Employee *list,int len);
/** \brief Imprime por id a un empleado.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int printEmployeesById(Employee *list,int len,int id);
/** \brief Pide el id del empleado y se podes modificar el nombre, apellido, sector o salario.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int modifyAnEmployee(Employee *list,int len);
/** \brief Se realiza la baja de un empleado
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int removeEmployee(Employee* list, int len,int id);
/** \brief Calcula la cantidad de empleados que superan el promedio
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int employeeQueSuperaElPromedio(Employee *list,int len);
/** \brief Calcula el promedio de salarios de todos los empleados.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int promedioDeSalarioEmployee(Employee *list,int len,float *promedio);
/** \brief Suma los salarios de todos los empleados.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int sumaDeSalariosEmployee(Employee *list,int len,float *sumaTotal);
/** \brief Ordena los apellidos de forma ascendente o descendente y sector si los apellidos son iguales.
 *
 * \param List es un lista de empleado que se va a recorrer.
 * \param Len es el largo de la lista.
 * \param Order es el orden de ordenamiento. 0-Descendente o 1-Ascendente.
 * \return Retorno -1 si hay error o rertono 0 si todo esta ok.
 *
 */

int sortEmployees(Employee* list, int len, int order);
/** \brief Se autogenera un id
 *
 * \param void no recibe parametro
 * \param
 * \return no retorna nada
 *
 */

int generarId(void);
#endif // ARRAYEMPLOYEES_H_INCLUDED
