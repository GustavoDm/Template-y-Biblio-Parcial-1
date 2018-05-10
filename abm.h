#ifndef ABM_H_INCLUDED
#define ABM_H_INCLUDED

typedef struct{

int idAbm;
int isEmpty;
char datoString[50];
int datoInt;
float datoFloat;

}Abm;


int abm_init(Abm *array, int size);
int abm_alta(Abm *array,int size);
int abm_mostrarDebug(Abm* array,int size);
int abm_mostrar(Abm *array,int size);
int abm_baja(Abm *array,int size, int id);
int abm_modificacion(Abm* array, int size, int id);
int abm_ordenarAlfabeticamente(Abm *array,int size, int orden);
int abm_ordenarNumericamente(Abm *array,int size, int orden);
int abm_buscarPorId(Abm* array,int size, int id);

#endif // ABM_H_INCLUDED
