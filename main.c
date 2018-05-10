#include <stdio.h>
#include <stdlib.h>
#include "getsValids.h"
#include "abm.h"
#define QTY 9

int main()
{
    int menu,id;
    Abm abms[QTY];
    abm_init(abms, QTY);

    do
    {
       get_validInt("MENU\n\n1:Alta\n2:Baja\n3:Modificacion\n4:Informes\n5:Ordenar alfabeticamente y Mostrar\n6:Ordenar Numericamente y mostrar\n","Ingrese una opcion correcta",&menu,0,9,2);
       fflush(stdin);
       printf("%d",menu);

        switch(menu)
        {

        case 1:
            abm_alta(abms, QTY);
            break;
        case 2:
            printf("Ingrese un ID: ");
            scanf("%d", &id);
            abm_baja(abms, QTY,id);
            break;
        case 3:
            printf("Ingrese un ID: ");
            scanf("%d", &id);
            abm_modificacion(abms, QTY,id);
            break;
        case 4:
            abm_mostrar(abms, QTY);
            break;
        case 5:
            abm_ordenarAlfabeticamente(abms, QTY, 0);
            abm_mostrar(abms, QTY);
            break;
        case 6:
            abm_ordenarNumericamente(abms, QTY, 0);
            abm_mostrar(abms, QTY);
            break;
        }
    }while(menu !=9);

        return 0;
    }
