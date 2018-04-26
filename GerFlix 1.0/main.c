#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

int main()
{
    char seguir = 's';
    int opcion=0;

    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    while(seguir == 's')
    {
        printf("1. Mostrar el listado de series\n");
        printf("2. Mostrar el listado de usuarios\n");
        printf("3. Mostrar el listado de Usuarios con el nombre de la serie que ve\n");
        printf("4. Mostrar por cada serie, el nombre de los usuarios que la ven.\n");
        printf("9. Salir\n");
        printf("\n");
        scanf("%i",&opcion);
        switch(opcion)
        {
            case 1:
                mostrarListaSeries(listaDeSeries, TAMSERIE);
                break;
            case 2:
                mostrarListaUsuarios(listaDeUsuarios,TAMUSUARIO);
                break;
            case 3:
                //mostrarUsuarioConSuSerie();
                break;
            case 9:
                seguir = 'n';
                break;
        }
    }


/*  1. Mostrar el listado de series
    2. Mostrar el listado de usuarios
    3. Mostrar el listado de Usuarios con el nombre de la serie que ve
    4. Mostrar por cada serie, el nombre de los usuarios que la ven.
*/





    return 0;
}
