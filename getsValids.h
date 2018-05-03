#ifndef GETSVALIDS_H_INCLUDED
#define GETSVALIDS_H_INCLUDED

int get_Int(char* mensaje, int *input);
int get_Float(char* mensaje, float *input);
int get_Long(char* mensaje, long *input);
int get_Char(char* mensaje, char *input);
int get_String(char* mensaje, char *input);
int val_numero(char *str);
int val_flotante(char *str);
int val_letras(char *str);
int val_alfaNumerico(char *str);
int val_email(char *str);
int val_telefono(char *str);
int get_stringLetras(char *mensaje,char *input);
int get_stringNumeros(char *mensaje,char *input);
int get_stringFlotantes(char *mensaje,char *input);

int get_validInt(char *requestMessage,char *errorMessage, int* input,int lowLimit, int hiLimit,int attemps);
int get_validString(char *requestMessage,char *errorMessage, char *errorMessageLenght,char *input, int maxLenght,int attemps);

#endif // GETSVALIDS_H_INCLUDED