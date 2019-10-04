#include <stdio.h>
#include <stdlib.h>

float sumarDosNumeros(float *resultadoSuma,float numeroA,float numeroB)
{
    *resultadoSuma = numeroA + numeroB;
    return 0;
}

float restarDosNumeros(float *resultadoResta,float numeroA,float numeroB)
{
    *resultadoResta = numeroA - numeroB;
    return 0;
}

float multiplicacionDosNumeros(float* resultadoMult,float numeroA,float numeroB)
{
    *resultadoMult = numeroA * numeroB;
    return 0;
}

int dividirDosNumeros(float *resultadoDiv, float numeroA,float numeroB)
{
    int ret;
    *resultadoDiv = numeroA/numeroB;
    if(numeroB == 0)
    {
        ret = -1;
    }
    else
    {
        ret = 0;
    }
    return ret;
}

int sacarFactorial(int numeroIngresado)
{
    int resultado;
    if(numeroIngresado == 0)
    {
        return 1;
    }
    resultado = numeroIngresado*sacarFactorial(numeroIngresado-1);
    return resultado;
}

int pedirNumero()
{
    int number;
    printf("Ingrese numero: ");
    scanf("%d",&number);
    return number;
}

int mostrarOpciones()
{
    int numero;
    printf("\n------CALCULADORA------\n");
    printf("\n1.Ingresar numero uno");
    printf("\n2.Ingresar numero dos");
    printf("\n3.Calcular todas las operaciones");
    printf("\n4.Informar resultados");
    printf("\n5.Salir\n");
    fflush(stdin);
    scanf("%d",&numero);
    return numero;
}

int validarFactorial(float numero,int resultado)
{
    int ret = -1;
    if(numero <0  || numero > 12)
    {
        printf("ERROR: El factorial de (%.2f) no se puede calcular.El minimo es 0 y el maximo 12.\n",numero);
    }
    else
    {
        printf("El factorial de B(%.2f) es: %d\n",numero,resultado);
        ret = 0;
    }
    return ret;
}

int menuPrincipal()
{
    float numeroUno,numeroDos,resultadoSuma,resultadoResta,resultadoMult,resultadoDiv;
    int factorialUno;
    int factorialDos;
    int opcion;
    do
    {
        opcion = mostrarOpciones();
        if((opcion != 1 && opcion == 2))
        {
            printf("Error, falta cargar numeros\n");
            continue;
        }
        else if((opcion != 1 && opcion == 3) || opcion == 4)
        {
            printf("Error\n");
            continue;
        }
        switch(opcion)
        {
        case 1:
            numeroUno = pedirNumero();
        case 2:
            numeroDos = pedirNumero();
            printf("-----------------------\n\n");
        case 3:
            sumarDosNumeros(&resultadoSuma,numeroUno,numeroDos);
            restarDosNumeros(&resultadoResta,numeroUno,numeroDos);
            multiplicacionDosNumeros(&resultadoMult,numeroUno,numeroDos);
            dividirDosNumeros(&resultadoDiv,numeroUno,numeroDos);
            factorialUno = sacarFactorial(numeroUno);
            factorialDos = sacarFactorial(numeroDos);
        case 4:
            printf("El resultado de la SUMA (%.2f+%.2f)es: %.2f\n",numeroUno,numeroDos,resultadoSuma);
            printf("El resultado de la RESTA (%.2f-%.2f) es: %.2f\n",numeroUno,numeroDos,resultadoResta);
            printf("El resultado de la MULTIPLICACION (%.2f*%.2f) es: %.2f\n",numeroUno,numeroDos,resultadoMult);
            if(dividirDosNumeros(&resultadoDiv,numeroUno,numeroDos)!=0)
            {
                 printf("El resultado de DIVISION (%.2f/%.2f) es: Error no se puede dividir entre cero(0)\n",numeroUno,numeroDos);
            }
            else
            {
                printf("El resultado de la DIVISION (%.2f/%.2f) es: %.2f\n",numeroUno,numeroDos,resultadoDiv);
            }
            validarFactorial(numeroUno,factorialUno);
            validarFactorial(numeroDos,factorialDos);
            break;
        case 5:
            break;
        default:
            printf("\nNo es una opcion");
            break;
        }
    }
    while(opcion != 5);
    return 0;
}
