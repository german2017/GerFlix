#include "Serie.h"

typedef struct
{
    int idUsuario;
    char nombre[50];
    int idSerie;
    int estado;
}eUsuario;

void inicializarUsuariosEstado(eUsuario[], int);
void inicializarUsuariosHardCode(eUsuario[]);
void mostrarListaUsuarios(eUsuario[], int);
void mostrarUsuarioConSuSerie(eUsuario[], int, eSerie[], int);
void mostrarSerieConSusEspectadores(eSerie[], int, eUsuario[], int);


int buscarEspacio(eUsuario[], int);
void altaUsuario(eUsuario[], int, int);
int validarIdUsuario(eUsuario[], int, int);
void modificarUsuario(eUsuario[], int, eSerie[], int);
int buscarIdUsuario(eUsuario[], int, int);
void bajaUsuario(eUsuario[], int);
