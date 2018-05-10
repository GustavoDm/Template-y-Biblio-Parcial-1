#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "usuarioAbm.h"
#include "getsValids.h"


static int proximoId(void);
static int buscarLugarLibre(Usuario* array,int size);

int usuario_init(Usuario *array, int size)
{
    int i;
    int retorno=-1;
    if(size>0&& array !=NULL)
    {
        for(i=0; i<size; i++)
        {
            array[i].isEmpty=1;
            retorno=0;
        }
    }
    return retorno;
}

/** \brief La Funcion da de alta datos de distintos tipos
 *
 * \param array Usuario*
 * \param size int
 * \return (0) si todo ok, (-1) si array es NULL o size es 0 o <, (-2)Si no hay lugar libre, (-3) si el usuario carga mal algo.
 *
 */
int usuario_alta(Usuario *array,int size)
{
    int retorno = -1;
    int i;
    char nombre[50];
    char pass[50];

    if(size > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,size);
        if(i >= 0)
        {
            if(!get_validLetras("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!get_validAlfaNumerico("Password: ","Error", "Demasiado larga la password vieja",pass,40,2))
                {

                        retorno = 0;
                        strcpy(array[i].nombre,nombre);
                        strcpy(array[i].pass,pass);
                        array[i].idUsuario = proximoId();
                        array[i].isEmpty = 0;

                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int usuario_mostrarDebug(Usuario* array,int size)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<size;i++)
        {
            printf("[DEBUG] - %d - %s - %s - %d\n",array[i].idUsuario, array[i].nombre,array[i].pass, array[i].isEmpty);
        }
    }
    return retorno;
}

int usuario_mostrar(Usuario *array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %s - %d\n",array[i].idUsuario, array[i].nombre,array[i].pass, array[i].isEmpty);
        }
    }
    return retorno;
}

int usuario_buscarPorId(Usuario *array,int size, int id)
//static int buscarPorId(Pantalla* array,int size, int id)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].idUsuario==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int usuario_baja(Usuario *array,int size, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = usuario_buscarPorId(array,size,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int usuario_modificacion(Usuario* array, int size, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char nombre[50];
    char pass[50];

    indiceAModificar = usuario_buscarPorId(array, size, id);

    if(size > 0 && array != NULL)
    {
        if(indiceAModificar>=0)
        {
          if(!get_validLetras("\nNombre? ","\nEso no es un nombre","El maximo es 40",nombre,40,2))
            {
                if(!get_validAlfaNumerico("\nPassword? ","\nSolo numeros y letras",pass,0,9999999,2))
                {

                        retorno = 0;
                        strcpy(array[indiceAModificar].nombre,nombre);
                        strcpy(array[indiceAModificar].pass,pass);
                        array[indiceAModificar].idUsuario = proximoId();
                        array[indiceAModificar].isEmpty = 0;

                }

            }
            else
            {
                retorno = -3;
            }
        }
        else
        {
            retorno = -2;
        }

    }
    return retorno;
}


int usuario_ordenarAlfabeticamente(Usuario *array,int size, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Usuario auxiliarEstructura;

    if(size > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<size-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].nombre,array[i+1].nombre) > 0 && orden) || (strcmp(array[i].nombre,array[i+1].nombre) < 0 && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}



int usuario_ordenarNumericamente(Usuario *array,int size, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Usuario auxiliarEstructura;

    if(size > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<size-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if(((array[i].idUsuario > array[i+1].idUsuario)  && orden) || ((array[i].idUsuario < array[i+1].idUsuario) && !orden))
                    {
                        auxiliarEstructura = array[i];
                        array[i] = array[i+1];
                        array[i+1] = auxiliarEstructura;
                        flagSwap = 1;
                    }
                }
            }
        }while(flagSwap);
    }
    return retorno;
}



static int buscarLugarLibre(Usuario *array,int size)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        for(i=0;i<size;i++)
        {
            if(array[i].isEmpty==1)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

static int proximoId(void)
{
    static int proximoId = -1;
    proximoId++;
    return proximoId;
}



