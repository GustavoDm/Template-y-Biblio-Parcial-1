#ifndef USUARIOABM_H_INCLUDED
#define USUARIOABM_H_INCLUDED

typedef struct{

char nombre[50];
char pass[50];
int idUsuario;
int sumaCalificaciones;
int cantidadCalificaciones;
int isEmpty;
}Usuario;

#endif // USUARIOABM_H_INCLUDED

int usuario_init(Usuario *array, int size);
int usuario_alta(Usuario *array,int size);
int usuario_mostrarDebug(Usuario* array,int size);
int usuario_mostrar(Usuario *array,int size);
int usuario_baja(Usuario *array,int size, int id);
int usuario_modificacion(Usuario* array, int size, int id);
int usuario_ordenarAlfabeticamente(Usuario *array,int size, int orden);
int usuario_ordenarNumericamente(Usuario *array,int size, int orden);
int usuario_buscarPorId(Usuario* array,int size, int id);
