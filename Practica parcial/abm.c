#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abm.h"
#include "getsValids.h"

static int proximoId(void);
static int buscarLugarLibre(Abm* array,int size);

int abm_init(Abm *array, int size)
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
 * \param array Abm*
 * \param size int
 * \return (0) si todo ok, (-1) si array es NULL o size es 0 o <, (-2)Si no hay lugar libre, (-3) si el usuario carga mal algo.
 *
 */
int abm_alta(Abm *array,int size)
{
    int retorno = -1;
    int i;
    char datoString[40];
    int datoInt;
    float datoFloat;

    if(size > 0 && array != NULL)
    {
        i = buscarLugarLibre(array,size);
        if(i >= 0)
        {
            if(!get_validLetras("\nString? ","\nEso no es un string","El maximo es 40",datoString,40,2))
            {
                if(!get_validFloat("\nFloat? ","\nEso no es un float",&datoFloat,0,9999999,2))
                {
                    if(!get_validInt("\nInt? ","\nEso no es un int",&datoInt,0,100,2))
                    {
                        retorno = 0;
                        strcpy(array[i].datoString,datoString);
                        array[i].datoFloat = datoFloat;
                        array[i].datoInt = datoInt;
                        array[i].idAbm = proximoId();
                        array[i].isEmpty = 0;
                    }
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


int abm_mostrarDebug(Abm* array,int size)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<size;i++)
        {
            printf("[DEBUG] - %d - %s - %f - %d - %d\n",array[i].idAbm, array[i].datoString,array[i].datoFloat,array[i].datoInt, array[i].isEmpty);
        }
    }
    return retorno;
}

int abm_mostrar(Abm *array,int limite)
{
    int retorno = -1;
    int i;
    if(limite > 0 && array != NULL)
    {
        retorno = 0;
        for(i=0;i<limite;i++)
        {
            if(!array[i].isEmpty)
                printf("[RELEASE] - %d - %s - %f - %d - %d\n",array[i].idAbm, array[i].datoString,array[i].datoFloat,array[i].datoInt, array[i].isEmpty);
        }
    }
    return retorno;
}

int abm_buscarPorId(Abm *array,int size, int id)
//static int buscarPorId(Pantalla* array,int size, int id)
{
    int retorno = -1;
    int i;
    if(size > 0 && array != NULL)
    {
        retorno = -2;
        for(i=0;i<size;i++)
        {
            if(!array[i].isEmpty && array[i].idAbm==id)
            {
                retorno = i;
                break;
            }
        }
    }
    return retorno;
}

int abm_baja(Abm *array,int size, int id)
{
    int indiceAEliminar;
    int retorno=-1;
    indiceAEliminar = abm_buscarPorId(array,size,id);
    if(indiceAEliminar>=0)
    {
        array[indiceAEliminar].isEmpty=1;
        retorno=0;
    }
    return retorno;
}

int abm_modificacion(Abm* array, int size, int id)
{
    int retorno = -1;
    int indiceAModificar;
    char datoString[40];
    int datoInt;
    float datoFloat;

    indiceAModificar = abm_buscarPorId(array, size, id);

    if(size > 0 && array != NULL)
    {
        if(indiceAModificar>=0)
        {
            if(!get_validLetras("\nString? ","\nEso no es un string","El maximo es 40",datoString,40,2))
            {
                if(!get_validFloat("\nFloat? ","\nEso no es un float",&datoFloat,0,9999999,2))
                {
                    if(!get_validInt("\nInt? ","\nEso no es un int",&datoInt,0,100,2))
                    {
                        retorno = 0;
                        strcpy(array[indiceAModificar].datoString,datoString);
                        array[indiceAModificar].datoFloat = datoFloat;
                        array[indiceAModificar].datoInt = datoInt;

                    }
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

int abm_ordenarAlfabeticamente(Abm *array,int size, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Abm auxiliarEstructura;

    if(size > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<size-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if((strcmp(array[i].datoString,array[i+1].datoString) > 0 && orden) || (strcmp(array[i].datoString,array[i+1].datoString) < 0 && !orden))
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



int abm_ordenarNumericamente(Abm *array,int size, int orden)
{
    int retorno = -1;
    int i;
    int flagSwap;
    Abm auxiliarEstructura;

    if(size > 0 && array != NULL)
    {
        do
        {
            flagSwap = 0;
            for(i=0;i<size-1;i++)
            {
                if(!array[i].isEmpty && !array[i+1].isEmpty)
                {
                    if(((array[i].datoInt > array[i+1].datoInt)  && orden) || ((array[i].datoInt < array[i+1].datoInt) && !orden))
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



static int buscarLugarLibre(Abm *array,int size)
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



