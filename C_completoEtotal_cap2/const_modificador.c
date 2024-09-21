#include <stdio.h>


void recebe_const_mod(const int valor_1)
{


        printf("%d\n",valor_1);

        //Codigo apresentera erros na linha
        valor_1 = 20;

        printf("%d\n",valor_1);
        

}


int main()
{


        int valor = 10;

        recebe_const_mod(valor);


}