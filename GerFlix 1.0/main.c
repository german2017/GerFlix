#include <stdio.h>
#include <stdlib.h>
#include "Usuario.h"
#define TAMSERIE 20
#define TAMUSUARIO 100

int main()
{
    char seguir = 's';
    int opcion=0;
    int lugar;

    eSerie listaDeSeries[TAMSERIE];
    eUsuario listaDeUsuarios[TAMUSUARIO];

    inicializarSeriesEstado(listaDeSeries, TAMSERIE);
    inicializarSeriesHardCode(listaDeSeries);

    inicializarUsuariosEstado(listaDeUsuarios,TAMUSUARIO);
    inicializarUsuariosHardCode(listaDeUsuarios);

    while(seguir == 's')
    {
        printf("1. Mostrar el listado de series.\n");
        printf("2. Mostrar el listado de usuarios\n");
        printf("3. Mostrar el listado de Usuarios con el nombre de la serie que ve.\n");
        printf("4. Mostrar por cada serie, el nombre de los usuarios que la ven.\n");
        printf("5. Alta de nuevo usuario.\n");
        printf("6. Modificar usuario.\n");
        printf("7. Dar de baja a un usuario.\n");
        printf("9. Salir\n");
        //printf("\n");
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
                mostrarUsuarioConSuSerie(listaDeUsuarios,TAMUSUARIO, listaDeSeries, TAMSERIE);
                break;
            case 4:
                mostrarSerieConSusEspectadores(listaDeSeries,TAMSERIE, listaDeUsuarios, TAMUSUARIO);
                break;
            case 5:
                lugar = buscarEspacio(listaDeUsuarios,TAMUSUARIO);
                if(lugar > -1)
                {
                    altaUsuario(listaDeUsuarios, TAMUSUARIO, lugar);
                }
                else
                {
                    printf("No quedan espacios libres.\n");
                }
                break;
            case 6:
                modificarUsuario(listaDeUsuarios, TAMUSUARIO, listaDeSeries, TAMSERIE);
                break;
            case 7:
                bajaUsuario(listaDeUsuarios, TAMUSUARIO);
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
