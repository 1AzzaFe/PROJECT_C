#include <stdio.h>

//
void recebe_const_mod(const int valor_1)
{

        printf("%d\n",valor_1);

        valor_1 == 20;

        /*Nao condigo alterar o valor_1 devido ao const*/
        //valor_1 == 20;
        
        printf("%d\n",valor_1);
        

}


int main()
{

        int valor = 10;

        recebe_const_mod(valor);

      
}