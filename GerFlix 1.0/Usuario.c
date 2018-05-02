#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuario.h"


void inicializarUsuariosEstado(eUsuario usuarios[], int cant)
{
    int i;

    for(i=0; i<cant; i++)
    {
        usuarios[i].estado = 0;
    }
}
void inicializarUsuariosHardCode(eUsuario usuarios[])
{


    int id[15] = {1000,1001,1002,1003,1004,1005,1006,1007,1008,1009, 1010,1011,1012,1013,1014};
    char nombre[][50]= {"Juan","Maria","Pedro","Vanesa","Jose","Luisa","Laura","Marcelo","German","Victoria","Dafne","Antonela","Gisele","Dario","Pedro"};

    int serie[15] = {100,100,101,101,102,100,100,103,101,102,103,101,100,100,101};



    int i;

    for(i=0; i<15; i++)
    {
        usuarios[i].idUsuario=id[i];
        usuarios[i].idSerie=serie[i];
        usuarios[i].estado = 1;
        strcpy(usuarios[i].nombre, nombre[i]);

    }
}

void mostrarListaUsuarios(eUsuario usuarios[], int TAMUSUARIO)
{
    int i;
    for(i=0; i<TAMUSUARIO; i++)
    {
        if(usuarios[i].estado != 0)
        {
            printf("ID de usuario: %d | %s\n", usuarios[i].idUsuario, usuarios[i].nombre);
        }
    }
    printf("\n");
}

void mostrarUsuarioConSuSerie(eUsuario usuarios[], int TAMUSUARIO, eSerie series[], int TAMSERIE)
{
    int i;
    int j;
    for(i=0; i<TAMUSUARIO; i++)
    {
        if(usuarios[i].estado == 1)
        {
            printf("\nID de usuario: %d | %s. ",usuarios[i].idUsuario, usuarios[i].nombre);
            for(j=0; j<TAMSERIE; j++)
            {
                if(series[j].estado == 1 && usuarios[i].idSerie == series[j].idSerie)
                {
                    printf(" La serie que mira es: %s",series[j].nombre);
                    break;
                }
            }
        }
    }
    printf("\n");
    printf("\n");
}

void mostrarSerieConSusEspectadores(eSerie series[], int TAMSERIE, eUsuario usuarios[], int TAMUSUARIO)
{
    int i;
    int j;
    for(i=0; i<TAMSERIE; i++)
    {
        if(series[i].estado == 1)
        {
            printf("\nLa serie: %s es vista por:\n", series[i].nombre);
            for(j=0; j<TAMUSUARIO; j++)
            {
                if(usuarios[j].estado == 1 && series[i].idSerie == usuarios[j].idSerie)
                {
                    printf("-%s ID: %d- ", usuarios[j].nombre, usuarios[j].idUsuario);
                }
            }
        }
    }
    printf("\n");
}

int buscarEspacio(eUsuario alumnos[], int TAMUSUARIO)
{
    int i;
    int lugar=-1;
    for(i = 0; i<TAMUSUARIO; i++)
    {
        if(alumnos[i].estado == 0)
        {
            lugar = i;
            break;
        }
    }
    return lugar;
}

void altaUsuario(eUsuario nuevoUsuario[], int TAMUSUARIO, int lugar)
{
    int idEnUso;
    printf("Ingrese el ID del nuevo usuario: \n");
    scanf("%d", &nuevoUsuario[lugar].idUsuario);
    idEnUso = validarIdUsuario(nuevoUsuario, TAMUSUARIO, nuevoUsuario[lugar].idUsuario);
    while(idEnUso == -1)
    {
        printf("El ID ingresado ya esta en uso, ingrese otro: \n");
        scanf("%d", &nuevoUsuario[lugar].idUsuario);
        idEnUso = validarIdUsuario(nuevoUsuario, TAMUSUARIO, nuevoUsuario[lugar].idUsuario);
    }
    printf("Ingrese el nombre del nuevo usuario: \n");
    fflush(stdin);
    gets(nuevoUsuario[lugar].nombre);
    printf("Ingrese el ID de la serie elegida por el nuevo usuario: \n");
    /*for(i=0;i<TAMSERIE;i++)
    {
        if(series[i].estado == 1)
        {
            printf("(%d: %s - )",series[i].idSerie, series[i].nombre);
        }
    }*/
    scanf("%d", &nuevoUsuario[lugar].idSerie);
    nuevoUsuario[lugar].estado = 1;
    printf("Usuario dado de alta correctamente.\n");

}

int validarIdUsuario(eUsuario usuarios[], int TAMUSUARIO, int idABuscar)
{
    int i;
    for(i=0; i<TAMUSUARIO; i++)
    {
        if(usuarios[i].estado == 1 && idABuscar == usuarios[i].idUsuario)
        {
            idABuscar = -1;
            break;
        }
    }
    return idABuscar;
}

void modificarUsuario(eUsuario usuarios[], int TAMUSUARIO, eSerie series[], int TAMSERIE)
{
    int i;
    int idTemp;
    int aBuscar;
    printf("ingrese el ID del usuario a modificar: ");
    scanf("%d", &idTemp);
    aBuscar = buscarIdUsuario(usuarios, TAMUSUARIO, idTemp);
    while(aBuscar == -1)
    {
        printf("El ID no es valido. Ingrese el ID del usuario a modificar: ");
        scanf("%d", &idTemp);
        aBuscar = buscarIdUsuario(usuarios, TAMUSUARIO, idTemp);
    }
    printf("Ingrese el nuevo nombre de usuario: \n");
    fflush(stdin);
    gets(usuarios[aBuscar].nombre);
    printf("Ingrese el ID de la nueva serie elegida: \n");
    printf("( ");
    for(i=0;i<TAMSERIE;i++)
    {
        if(series[i].estado == 1)
        {
            printf("%d: %s ",series[i].idSerie, series[i].nombre);
        }
    }
    printf(")\n");
    scanf("%d", &usuarios[aBuscar].idSerie);
    printf("Usuario modificado correctamente.\n");
}

int buscarIdUsuario(eUsuario usuarios[], int TAMUSUARIO, int idTemp)
{
    int i;
    int aBuscar=-1;
    for(i=0; i<TAMUSUARIO; i++)
    {
        if(usuarios[i].idUsuario == idTemp)
        {
            aBuscar = i;
            break;
        }
    }
    return aBuscar;
}

void bajaUsuario(eUsuario usuarios[], int TAMUSUARIO)
{
    int idTemp;
    int aBuscar;
    printf("ingrese el ID del usuario a dar de baja: ");
    scanf("%d", &idTemp);
    aBuscar = buscarIdUsuario(usuarios, TAMUSUARIO, idTemp);
    while(aBuscar == -1)
    {
        printf("El ID no es valido. Ingrese el ID del usuario a dar de baja: ");
        scanf("%d", &idTemp);
        aBuscar = buscarIdUsuario(usuarios, TAMUSUARIO, idTemp);
    }
    //usuarios[aBuscar].idUsuario=0; No hace falta destruir los demàs campos. Sòlo cambiar estado de 1 a 0.
    //usuarios[aBuscar].idSerie=0;   Por si se quisiera recuperar informaciòn.
    usuarios[aBuscar].estado = 0;
    //strcpy(usuarios[aBuscar].nombre, "");
    printf("Usuario dado de baja correctamente.\n");
}
