//Nombre: Bryan Roldán

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxArreglo 5000

struct AFP{
    char *nombreGerente;
    struct Retiro **retiros;
};

struct Retiro{
    char *rut;
    char *nombre;
    char *nombreAFP;
    int montoRetirado;
};

//Creamos un arreglo de punteros a la estructura de retiros
struct Retiro ** crearArreglo(int tam){

    struct Retiro **arregloNuevo;

    //Verificamos que la cantidad de retiros ingresados esté dentro del rango correcto
    if(tam>0 && tam<5000){

        //Reservamos la memoria para el arreglo de punteros
        arregloNuevo=(struct Retiro **)malloc(tam*sizeof(struct Retiro *));

        //Retornamos el arreglo
        return arregloNuevo;
    }

    //Si la cantidad de retiros no es valida, retornamos NULL
    return NULL;
};

struct Retiro * crearRetiro(char *rut, char *nombre, char *nombreAFP, int montoRetirado){

    struct Retiro *nuevoRetiro;

    //Reservamos memoria para el arreglo de la estructura Retiro
    nuevoRetiro=(struct Retiro *)malloc(sizeof(struct Retiro));

    //Reservamos memoria y copiamos el nombre del dato correspondiente
    nuevoRetiro->rut=(char *)malloc(strlen(rut)* sizeof(char));
    strcpy(nuevoRetiro->rut,rut);
    nuevoRetiro->nombre=(char *)malloc(strlen(nombre)* sizeof(char));
    strcpy(nuevoRetiro->rut,rut);
    nuevoRetiro->nombreAFP=(char *)malloc(strlen(nombre)* sizeof(char));
    strcpy(nuevoRetiro->rut,rut);

    //Asignamos el monto retirado
    nuevoRetiro->montoRetirado=montoRetirado;

    return nuevoRetiro;
};

//Creamos la funcion para contar cuantos retiros realizo cada afiliado
int cantidadRetirosAfiliado(struct Retiro **retiros, int tam, char *rut){
    int cantidadRetiros=0;

    //Recorremos el arreglo de retiros
    for(int i=0; i<tam; i++){

        //Verificamos que la posicion no sea NULL y se compara el rut buscado con el rut de la posicion
        if(retiros[i]!=NULL && strcmp(retiros[i]->rut, rut==0)){

            //De haber coincidencia de ruts se incrementa el valor a la cantidad de retiros
            cantidadRetiros++;
        }
    }

    //Retornamos la cantidad de retiros del afiliado con el rut buscado
    return cantidadRetiros;
}

int main(){

    int cantidad, montoRetirado;
    char rut[100], nombre[100], nombreAFP[100], rutBuscado[100];
    struct AFP *afp;
    struct Retiro **retiros;
    struct Retiro *retiroNuevo;

    printf("Ingrese la cantidad de retiros:\n");
    cantidad= scanf("%d",&cantidad);

    retiros=crearArreglo(cantidad);

    if(retiros!=NULL){
        printf("Arreglo creado correctamente\n");
    }
    else{
        printf("Arreglo no pudo ser creado correctamente\n");
    }

    if(retiros!=NULL){
        printf("Ingrese los datos del retiro:\n");
        printf("RUT: \n");
        scanf("%s" ,rut);
        printf("Nombre: \n");
        scanf("%s" ,nombre);
        printf("Nombre AFP: \n");
        scanf("%s" ,nombreAFP);
        printf("Monto retirado: \n");
        scanf("%d" ,&montoRetirado);
        retiroNuevo=crearRetiro(rut, nombre, nombreAFP, montoRetirado);
    }

    printf("Ingrese el rut a buscar: \n");
    scanf("%s" ,rutBuscado);


    int cantidadRetiros=cantidadRetirosAfiliado(retiros, cantidad, rutBuscado);
    printf("Cantidad de retiros para el rut %s: %d\n", rutBuscado, cantidadRetiros);

    return 0;
}
