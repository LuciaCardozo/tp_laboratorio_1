#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

/** \brief Suma dos numeros, se guarda el resultado en resultadoSuma y retorna 0 si esta todo ok.
 *
 * \param resultadoSuma es el valor de la suma de las dos variables ingresada por el usuario.
 * \param numeroA es el primer numero ingresado por el usuario.
 * \param numeroB es el segundo numero ingresado por el usuario.
 * \return retorna 0 si esta todo ok.
 *
 */

float sumarDosNumeros(float *resultadoSuma,float numeroA,float numeroB);
/** \brief Resta dos numeros, se guarda el resultado en resultadoResta y retorna 0 si esta todo ok.
 *
 * \param resultadoResta es el valor de la resta de las dos variables ingresada por el usuario.
 * \param numeroA es el primer numero ingresado por el usuario.
 * \param numeroB es el segundo numero ingresado por el usuario.
 * \return retorna 0 si esta todo ok.
 *
 */

float restarDosNumeros(float *resultadoResta,float numeroA,float numeroB);
/** \brief Multiplica dos numeros, se guarda el resultado en resultadoMult y retorna 0 si esta todo ok.
 *
 * \param resultadoMult es el valor de la multiplicacion de las dos variables ingresada por el usuario.
 * \param numeroA es el primer numero ingresado por el usuario.
 * \param numeroB es el segundo numero ingresado por el usuario.
 * \return retorna 0 si esta todo ok.
 *
 */

float multiplicacionDosNumeros(float* resultadoMult,float numeroA,float numeroB);
/** \brief Divide dos numeros, se guarda el resultado en resultadoDiv y retorna 0 si esta todo ok.
 *
 * \param resultadoDiv es el valor de la division de las dos variables ingresada por el usuario.
 * \param numeroA es el primer numero ingresado por el usuario.
 * \param numeroB es el segundo numero ingresado por el usuario.
 * \return retorna 0 si esta todo ok o retorna -1 si hay error.
 *
 */

int dividirDosNumeros(float *resultadoDiv, float numeroA,float numeroB);
/** \brief Saca el factorial de un numero.
 *
 * \param numeroIngresado es el numero que ingresa el usuario.
 * \return retorna el resultado.
 *
 */

int sacarFactorial(int numeroIngresado);
/** \brief Pide un numero y lo guarda.
 *
 * \return retorna el numero que ingreso el usuario.
 *
 */

int pedirNumero();
/** \brief Muestra un lista de opciones y se guarda la opcion elegida por el usuario.
 *
 * \return retorna el valor que ingreso el usuario.
 *
 */

int mostrarMenuDeOpciones();
/** \brief Valida el rango de un numero para sacar el factorial(Minimo 0 y maximo 12).Muesta mensaje si hay error o no.
 *
 * \param number es el numero ingresado por el usuario.
 * \param result es el resultado del numero ingresado.
 * \return retorna 0 si esta todo ok o retorna -1 si hay error.
 *
 */

int validarFactorial(float number,int result);
/** \brief Muestra un lista de opciones, valida que la opcion sea correcta, pide dos numeros, calcula y muestra los resultados.
 *
 * \return 0 si esta todo ok.
 *
 */

int menuPrincipal();

#endif // FUNCIONES_H_INCLUDED
