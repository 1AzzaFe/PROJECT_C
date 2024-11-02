#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//usar tempo de execução
#include <unistd.h> 

#define tamanho_i_j 20

// Reset (para retornar à cor padrão do terminal)
#define RESET "\033[0m"

// Cores de texto
#define BLACK "\033[0;30m"
#define RED "\033[0;31m"
#define GREEN "\033[0;32m"
#define YELLOW "\033[0;33m"
#define BLUE "\033[0;34m"
#define MAGENTA "\033[0;35m"
#define CYAN "\033[0;36m"
#define WHITE "\033[0;37m"

// Cores de texto em negrito
#define BOLD_BLACK "\033[1;30m"
#define BOLD_RED "\033[1;31m"
#define BOLD_GREEN "\033[1;32m"
#define BOLD_YELLOW "\033[1;33m"
#define BOLD_BLUE "\033[1;34m"
#define BOLD_MAGENTA "\033[1;35m"
#define BOLD_CYAN "\033[1;36m"
#define BOLD_WHITE "\033[1;37m"

 
typedef struct coordenadas_ataque
{

    int cord_atk_X;
    int cord_atk_Y;

}estrutura_ataque;


typedef struct posicao_navios
{

    char tipo_nav[2];
    char oriente[2];

    int  posicao_X;
    int  posicao_Y;
     

    estrutura_ataque *atk;
    
}navios_jogador;



typedef struct nome_jogadores{

    navios_jogador  *navios1;

    navios_jogador *navios2;

}jogadores;




char **posicao_navio_jg1(jogadores entrada_jg, int n_navios)
{


    /*nao consigui passar a matriz por referencia (não sei se é possivel, então alocar foi a opição), nunca esquecer de liberar
    acho que irei liberar tudo em uma mesma função*/


            char **tab_jg1 = (char**)malloc(tamanho_i_j*sizeof(char*));

            for(int i = 0 ; i < tamanho_i_j ; i++)
            {

                tab_jg1[i] = (char*)malloc(tamanho_i_j*(sizeof(char)));

            }


            //inicializa o tabuleiro do jogador 
            for(int i = 0; i < tamanho_i_j ; i++)
            {

                for(int j = 0; j < tamanho_i_j ;j++)
                {

                tab_jg1[i][j] = '~';

                }   
            }



            /*decidi por fazer isso em uma funçao so, justamente para nao ter que usar um for, é isso
            prequiçao de colocar o printf, mas vou mostrar meus primos mais novos, então tem que ficar organizado*/
            for(int b = 0; b < n_navios; b++)
            {

                printf(BOLD_WHITE"Jogador 1 esse \xC3\xA9 o navio %d/%d\n\n", b+1, n_navios);
            
                printf("Tipos de navios C/E/P\n");
                fgets(entrada_jg.navios1[b].tipo_nav , 2 , stdin);
                entrada_jg.navios1[b].tipo_nav[strcspn(entrada_jg.navios1[b].tipo_nav, "\n")] = '\0';

                //ainda não entendo a necessidade disso, se voce tirar o essa parte do codigo vai pular algum fgets ou scanf apos o loop...
                getchar();
        

                printf("Orienta\303\247\303\243o no tabuleiro\n");

                fgets(entrada_jg.navios1[b].oriente, 2 , stdin);
                entrada_jg.navios1[b].oriente[strcspn(entrada_jg.navios1[b].oriente, "\n")] = '\0';

                printf("Posi\xC3\xA7\xC3\xA3o no tabuleiro\n");

                scanf("%d %d", &entrada_jg.navios1[b].posicao_X, &entrada_jg.navios1[b].posicao_Y);
            
                getchar();
            

            }
            
     
            for(int navio_C = 0 ; navio_C < n_navios ; navio_C++)
            {

            /*COLOCANDO NAVIOS C NO TABULEIRO*/
                if(strcmp(entrada_jg.navios1[navio_C].oriente,"H") == 0 && strcmp(entrada_jg.navios1[navio_C].tipo_nav,"C") == 0)
                {

                for(int u_C_horizontal = -1; u_C_horizontal <= 1; u_C_horizontal++ )
                {
         
                //coloca os navios de fato na horizontal
                tab_jg1[entrada_jg.navios1[navio_C].posicao_X][entrada_jg.navios1[navio_C].posicao_Y + u_C_horizontal] = 'C';

                } 

                }

            }


            //POSICIONAMENTO VERTICAL PARA NAVIO C, não coloquei esforço no else if (parece trabalhoso)
            for(int navio_C = 0 ; navio_C < n_navios ; navio_C++)
            {

                if(strcmp(entrada_jg.navios1[navio_C].oriente,"V") == 0 && strcmp(entrada_jg.navios1[navio_C].tipo_nav,"C") == 0 )
                {

                for(int u_C_vertical = -1; u_C_vertical <= 1; u_C_vertical++ )
                {

                //coloca os navios de fato na vertical
                tab_jg1[entrada_jg.navios1[navio_C].posicao_X + u_C_vertical][entrada_jg.navios1[navio_C].posicao_Y] = 'C';

                }

                }

            }


            //POSICIONAMENTO HORIZONTAL NAVIO P
            for(int navio_P = 0 ; navio_P < n_navios ; navio_P++)
            {

                if(strcmp(entrada_jg.navios1[navio_P].oriente,"H") == 0 && strcmp(entrada_jg.navios1[navio_P].tipo_nav,"P") == 0 )
                {

                for(int u_P_horizontal = -2; u_P_horizontal <= 2; u_P_horizontal++ )
                {

                //coloca os navios de fato na horizontal
                tab_jg1[entrada_jg.navios1[navio_P].posicao_X  + u_P_horizontal ][entrada_jg.navios1[navio_P].posicao_Y] = 'P';

                }

                }

            }


            //POSICIONAMENTO VERTICAL NAVIO P
            for(int navio_P = 0 ; navio_P < n_navios ; navio_P++)   {

                if(strcmp(entrada_jg.navios1[navio_P].oriente,"V") == 0 && strcmp(entrada_jg.navios1[navio_P].tipo_nav,"P") == 0 )  
                {

                for(int u_P_vertical = -2; u_P_vertical <= 2; u_P_vertical++ )
                {

                //coloca os navios de fato na vertical
                tab_jg1[entrada_jg.navios1[navio_P].posicao_X][entrada_jg.navios1[navio_P].posicao_Y + u_P_vertical] = 'P';

                }

                }

            }


            //POSICIONAMENTO VERTICAL NAVIO E
            for(int navio_E = 0 ; navio_E < n_navios ; navio_E++)
            {

                if(strcmp(entrada_jg.navios1[navio_E].oriente,"V") == 0 && strcmp(entrada_jg.navios1[navio_E].tipo_nav,"E") == 0 ){

                for(int u_E_horizontal = -3; u_E_horizontal <= 3; u_E_horizontal++ )
                {

                //coloca os navios de fato na vertical
                tab_jg1[entrada_jg.navios1[navio_E].posicao_X  + u_E_horizontal][entrada_jg.navios1[navio_E].posicao_Y ] = 'E';

                }

                }

            }


            //POSICIONAMENTO HORIZONTAL NAVIO E
            for(int navio_E = 0 ; navio_E < n_navios ; navio_E++)
            {

                if(strcmp(entrada_jg .navios1[navio_E].oriente,"H") == 0 && strcmp(entrada_jg .navios1[navio_E].tipo_nav,"E") == 0 )
                {

                for(int u_E_vertical = -3; u_E_vertical <= 3; u_E_vertical++ )
                {

                //coloca os navios de fato na vertical
                tab_jg1[entrada_jg .navios1[navio_E].posicao_X][entrada_jg .navios1[navio_E].posicao_Y + u_E_vertical] = 'E';

                }

                }

            }


            /*retorna o tabuleiro, dessa forma posso utliza-lo em qualquer lugar do programa, ja que NÃO encontei uma forma de 
            passar a matriz por referencia '&tabuleiro_jg1'->não consegui*/
            return tab_jg1;

}


         
         


//segua a mesma lógica da função acima, pouparemos comentarios
char **posicao_navio_jg2(jogadores entrada_jg2, int n_navios){



            //aloca memoria para o tabuleiro do jogador2, o foco e retornar esse tabuleiro com os navios na posição
            char **tab_jg2 = (char**)malloc(tamanho_i_j*sizeof(char*));

            for(int i = 0 ; i < tamanho_i_j ; i++){

            tab_jg2[i] = (char*)malloc(tamanho_i_j*(sizeof(char)));

            }

            for(int i = 0; i < tamanho_i_j ; i++)
            {
                for(int j = 0; j < tamanho_i_j ;j++)
                {

                tab_jg2[i][j] = '~';

                }
            }


            for(int b = 0; b < n_navios; b++)
            {

                printf("Jogador 2 esse \xC3\xA9 o navio %d/%d\n\n", b+1, n_navios);
            

                printf("Tipos de navios C/E/P\n");
                fgets(entrada_jg2 .navios2[b].tipo_nav , 2 , stdin);
                entrada_jg2 .navios2[b].tipo_nav[strcspn(entrada_jg2 .navios2[b].tipo_nav, "\n")] = '\0';

                getchar();
        

                printf("Orienta\303\247\303\243o no tabuleiro\n");

                fgets(entrada_jg2 .navios2[b].oriente, 2 , stdin);
                entrada_jg2 .navios2[b].oriente[strcspn(entrada_jg2 .navios2[b].oriente, "\n")] = '\0';

                printf("Posi\xC3\xA7\xC3\xA3o no tabuleiro\n");

                scanf("%d %d", &entrada_jg2 .navios2[b].posicao_X, &entrada_jg2 .navios2[b].posicao_Y);
            
                getchar();
            

            }

            
            for(int navio_C = 0 ; navio_C < n_navios ; navio_C++)
            {

                /*COLOCANDO NAVIOS C NO TABULEIRO*/
                if(strcmp(entrada_jg2 .navios2[navio_C].oriente,"H") == 0 && strcmp(entrada_jg2 .navios2[navio_C].tipo_nav,"C") == 0)
                {

                for(int u_C_horizontal = -1; u_C_horizontal <= 1; u_C_horizontal++ )
                {
         
                //coloca os navios de fato na horizontal
                tab_jg2[entrada_jg2 .navios2[navio_C].posicao_X][entrada_jg2 .navios2[navio_C].posicao_Y + u_C_horizontal] = 'C';

                } 

                }

            }


            //POSICIONAMENTO VERTICAL PARA NAVIO C, não coloquei esforço no else if (parece trabalhoso)
            for(int navio_C = 0 ; navio_C < n_navios ; navio_C++)
            {

                if(strcmp(entrada_jg2 .navios2[navio_C].oriente,"V") == 0 && strcmp(entrada_jg2 .navios2[navio_C].tipo_nav,"C") == 0 )
                {

                for(int u_C_vertical = -1; u_C_vertical <= 1; u_C_vertical++ )
                {

                //coloca os navios de fato na vertical
                tab_jg2[entrada_jg2 .navios2[navio_C].posicao_X + u_C_vertical][entrada_jg2 .navios2[navio_C].posicao_Y] = 'C';

                }


                }

            }


            //POSICIONAMENTO HORIZONTAL NAVIO P
            for(int navio_P = 0 ; navio_P < n_navios ; navio_P++)
            {

                if(strcmp(entrada_jg2 .navios2[navio_P].oriente,"H") == 0 && strcmp(entrada_jg2 .navios2[navio_P].tipo_nav,"P") == 0)
                {

                for(int u_P_horizontal = -2; u_P_horizontal <= 2; u_P_horizontal++ )

                {

                //coloca os navios de fato na horizontal
                tab_jg2[entrada_jg2 .navios2[navio_P].posicao_X][entrada_jg2 .navios2[navio_P].posicao_Y + u_P_horizontal] = 'P';

                }

                }

            }

            //POSICIONAMENTO VERTICAL NAVIO P
            for(int navio_P = 0 ; navio_P < n_navios ; navio_P++)
            {

                if(strcmp(entrada_jg2 .navios2[navio_P].oriente,"V") == 0 && strcmp(entrada_jg2 .navios2[navio_P].tipo_nav,"P") == 0 )
                {

                for(int u_P_vertical = -2; u_P_vertical <= 2; u_P_vertical++ )
                {

                //coloca os navios de fato na vertical
                tab_jg2[entrada_jg2 .navios2[navio_P].posicao_X + u_P_vertical][entrada_jg2 .navios2[navio_P].posicao_Y] = 'P';

                }

                }

            }


            //POSICIONAMENTO HORIZONTAL NAVIO E
            for(int navio_E = 0 ; navio_E < n_navios ; navio_E++)
            {

                if(strcmp(entrada_jg2 .navios2[navio_E].oriente,"H") == 0 && strcmp(entrada_jg2 .navios2[navio_E].tipo_nav,"E") == 0 )
                {

                for(int u_E_horizontal = -3; u_E_horizontal <= 3; u_E_horizontal++ )
                {

                //coloca os navios de fato na vertical
                tab_jg2[entrada_jg2 .navios2[navio_E].posicao_X ][entrada_jg2 .navios2[navio_E].posicao_Y + u_E_horizontal] = 'E';

                }

                }

            }


            //POSICIONAMENTO VERTICAL NAVIO E
            for(int navio_E = 0 ; navio_E < n_navios ; navio_E++)
            {

                if(strcmp(entrada_jg2 .navios2[navio_E].oriente,"V") == 0 && strcmp(entrada_jg2 .navios2[navio_E].tipo_nav,"E") == 0 )
                {

                for(int u_E_vertical = -3; u_E_vertical <= 3; u_E_vertical++ )
                {

                //coloca os navios de fato na vertical
                tab_jg2[entrada_jg2 .navios2[navio_E].posicao_X + u_E_vertical ][entrada_jg2 .navios2[navio_E].posicao_Y] = 'E';

                }

                }

            }
    
            //returna tabuleiro com as os respectivos navios
            return tab_jg2;
        
}



/*parte bem tanquila, mas perceba que essa função recebe o tabuleiro do jogador 2, uma vez que o ataque as coordenas
de ataque devem ser colocadas no tabuleiro do jogador 2*/
char **ataque_jogador1(jogadores atk_jg1,int n_ataques,char **tabuleiro_coor_ataques2)
{


                printf(BOLD_WHITE"Jogador 1 escolha as coordenadas de ataque\n");
    
            for(int i = 0 ; i < n_ataques ;i++)
            {

                printf("Esse \xC3\xA9 o ataque %d/%d \n",i+1,n_ataques);

                //aqui nos apemas atribuimos esses valores das coordenas (muito importante definir pontuação)
                scanf("%d %d", &atk_jg1 .navios1->atk[i].cord_atk_X, &atk_jg1.navios1->atk[i].cord_atk_Y);

                //como dito, colocamos as coordenas de ataque no tabuleiro 2
                tabuleiro_coor_ataques2[atk_jg1.navios1->atk[i].cord_atk_X][atk_jg1 .navios1->atk[i].cord_atk_Y] = 'O';

                //tenho que usar se não quando voltar pra cima o scanf é de uma certa forma, ignorado... C sendo C...
                getchar();


            }

            /*returna a o tabuleiro do jogador 2 com navios que foram posicionados anteriormente e junto
            esta as coordenas de ataque (como eu disse muuito importante, funciona que eu sei...)*/
            return tabuleiro_coor_ataques2;

}
        

/*calculamos os pontos que o jogador 1 obteve, se acerta o navios E ganha 2 pontos...
temos claremente de usar 2 for's, for1( quantidade de navios jogador 2), for2(quantidade de ataques jogador 1)
tem que pensar que X.Y é o centro do navios, entao o if tem que considerar as bordas tadas as unidades
isso significa um for pra cara navios...*/
int  calculo_pontos_jg1(jogadores n_pontos_jg1, jogadores navios_jg2,int n_navios, int n_ataques)
{


    int pontuacao_total_jg1 = 0;


            for(int i = 0 ; i < n_navios ; i++)
            {
                if(strcmp(navios_jg2 .navios2[i].tipo_nav,"C") == 0 && strcmp(navios_jg2.navios2[i].oriente,"H") == 0){
                
                    for(int j = 0 ; j < n_ataques ; j++)
                    {
        

                        //olhando se os ataques do jogador 1 acertam alguma coordenada do navios C do jogador 2
                        for(int u_C_horizontal = -1; u_C_horizontal <= 1 ; u_C_horizontal++)
                        {

                        if( navios_jg2.navios2[i].posicao_X == n_pontos_jg1 .navios1->atk[j].cord_atk_X 
                        && navios_jg2.navios2[i].posicao_Y + u_C_horizontal == n_pontos_jg1 .navios1->atk[j].cord_atk_Y)
                        {
        
                        pontuacao_total_jg1+=2;

                        }

                        }
                    }
                }
            }



            for(int i = 0 ; i < n_navios ; i++)
            {
                if(strcmp(navios_jg2 .navios2[i].tipo_nav,"C") == 0 && strcmp(navios_jg2 .navios2[i].oriente,"V") == 0)
                {

                    for(int j = 0 ; j < n_ataques ; j++)
                    {

                        for(int u_C_vertical = -1; u_C_vertical <= 1 ; u_C_vertical++)
                        {

        
                        if(navios_jg2.navios2[i].posicao_X + u_C_vertical == n_pontos_jg1 .navios1->atk[j].cord_atk_X  
                        && navios_jg2.navios2[i].posicao_Y == n_pontos_jg1 .navios1->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg1+=2;
         
                        }

                        }
                    }
                }
            }



            for(int i = 0 ; i < n_navios ; i++)
            {
                if(strcmp(navios_jg2 .navios2[i].tipo_nav,"P") == 0 && strcmp(navios_jg2 .navios2[i].oriente,"H") == 0)
                {
                    for(int j = 0 ; j < n_ataques ; j++)
                    {

                        
                        for(int u_P_horizontal = -2; u_P_horizontal <= 2 ; u_P_horizontal++)
                        {

        
                        if(navios_jg2 .navios2[i].posicao_X  == n_pontos_jg1 .navios1->atk[j].cord_atk_X  
                        && navios_jg2 .navios2[i].posicao_Y  + u_P_horizontal == n_pontos_jg1 .navios1->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg1+=5;
         
                        }

                        }

                    }
                }
            }



            for(int i = 0 ; i < n_navios ; i++)
            {

                if(strcmp(navios_jg2 .navios2[i].tipo_nav,"P") == 0 && strcmp(navios_jg2 .navios2[i].oriente,"V") == 0)
                {
                        
                    for(int j = 0 ; j < n_ataques ; j++){

                        for(int u_P_vertical = -2; u_P_vertical <= 2 ; u_P_vertical++)
                        {

        
                        if(navios_jg2 .navios2[i].posicao_X + u_P_vertical  == n_pontos_jg1 .navios1->atk[j].cord_atk_X  
                        && navios_jg2 .navios2[i].posicao_Y  == n_pontos_jg1 .navios1->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg1+=5;
         
                        }

                        }
                    }
                }
            }
        


            for(int i = 0 ; i < n_navios ; i++)
            {

                if(strcmp(navios_jg2 .navios2[i].tipo_nav,"E") == 0 && strcmp(navios_jg2 .navios2[i].oriente,"H") == 0)
                {
                    for(int j = 0 ; j < n_ataques ; j++)
                    {
         

                        for(int u_E_horizontal = -3 ; u_E_horizontal <= 3 ; u_E_horizontal++)
                        {

        
                        if(navios_jg2 .navios2[i].posicao_X   == n_pontos_jg1 .navios1->atk[j].cord_atk_X  
                        && navios_jg2 .navios2[i].posicao_Y +  u_E_horizontal == n_pontos_jg1 .navios1->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg1+=10;
         
                        }

                        }
                    }
                }
            }
        

    
            for(int i = 0 ; i < n_navios ; i++)
            {

                if(strcmp(navios_jg2 .navios2[i].tipo_nav,"E") == 0 && strcmp(navios_jg2 .navios2[i].oriente,"V") == 0)
                {

                    for(int j = 0 ; j < n_ataques ; j++)
                    {

                        for(int u_E_vertical = -3 ; u_E_vertical <= 3 ; u_E_vertical++)
                        {

        
                        if(navios_jg2 .navios2[i].posicao_X + u_E_vertical  == n_pontos_jg1 .navios1->atk[j].cord_atk_X  
                        && navios_jg2 .navios2[i].posicao_Y  == n_pontos_jg1 .navios1->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg1+=10;

                        }

                        }
                    }
                }
            }
    
            //função retorna os pontos do jogador
            return pontuacao_total_jg1;
}



 //mesma lógca do ataque_jogador2, poupe-mos tempo...
 char **ataque_jogador2(jogadores atk_jg2, int n_ataques, char **tabuleiro_coor_ataques1)
{

    

            printf("Jogador 2 escolha as coordenadas de ataque\n");
    
        for(int i = 0 ; i < n_ataques ;i++){

    
            printf("Esse \xC3\xA9 o ataque %d/%d \n",i+1,n_ataques);

            //aqui nos apemas atribuimos esses valores das coordenas (muito importante definir pontuação)
            scanf("%d %d"RESET,&atk_jg2 .navios2->atk[i].cord_atk_X, &atk_jg2 .navios2->atk[i].cord_atk_Y);

            //como dito, colocamos as coordenas de ataque no tabuleiro 2
            tabuleiro_coor_ataques1[atk_jg2 .navios2->atk[i].cord_atk_X][atk_jg2 .navios2->atk[i].cord_atk_Y] = 'O';

            //tenho que usar se não quando voltar pra cima o scanf é de uma certa forma, ignorado... C sendo C...
            getchar();


        }       

        /*returna a o tabuleiro do jogador 2 com navios que foram posicionados anteriormente e junto
        esta as coordenas de ataque (como eu disse muuito importante, funciona que eu sei...)*/
        return tabuleiro_coor_ataques1;

}


int calculo_pontos_jg2(jogadores navios_jg1, jogadores n_pontos_jg2, int n_navios, int n_ataques)
{


    int pontuacao_total_jg2 = 0;

            for(int i = 0 ; i < n_navios ; i++)
            {
                if(strcmp(navios_jg1 .navios1[i].tipo_nav,"C") == 0 && strcmp(navios_jg1 .navios1[i].oriente,"H") == 0)
                {
                    for(int j = 0 ; j < n_ataques ; j++)
                    {
        
                        //olhando se os ataques do jogador 1 acertam alguma coordenada do navios C do jogador 2
                        for(int u_C_horizontal = -1; u_C_horizontal <= 1 ; u_C_horizontal++)
                        {

                        if( navios_jg1 .navios1[i].posicao_X == n_pontos_jg2 .navios2->atk[j].cord_atk_X  
                        && navios_jg1 .navios1[i].posicao_Y + u_C_horizontal == n_pontos_jg2 .navios2->atk[j].cord_atk_Y)
                        {
        
                        pontuacao_total_jg2+=2;

                        }

                        }
                    }
                }
            }

     

            for(int i = 0 ; i < n_navios ; i++)
            {

                if(strcmp(navios_jg1 .navios1[i].tipo_nav,"C") == 0 && strcmp(navios_jg1 .navios1[i].oriente,"V") == 0)
                {

                    for(int j = 0 ; j < n_ataques ; j++)
                    {

                        for(int u_C_vertical = -1; u_C_vertical <= 1 ; u_C_vertical++)
                        {

        
                        if(navios_jg1.navios1[i].posicao_X + u_C_vertical == n_pontos_jg2.navios2->atk[j].cord_atk_X  
                        && navios_jg1 .navios1[i].posicao_Y == n_pontos_jg2 .navios2->atk[j].cord_atk_Y){

                        pontuacao_total_jg2+=2;
         
                        }
                        }
                    }
                }
            }


            for(int i = 0 ; i < n_navios ; i++)
            {
                for(int j = 0 ; j < n_ataques ; j++)
                {
                    if(strcmp(navios_jg1 .navios1[i].tipo_nav,"P") == 0 && strcmp(navios_jg1 .navios1[i].oriente,"H") == 0)
                    {

                        for(int u_P_horizontal = -2; u_P_horizontal <= 2 ; u_P_horizontal++)
                        {

        
                        if(navios_jg1 .navios1[i].posicao_X  == n_pontos_jg2 .navios2->atk[j].cord_atk_X  
                        && navios_jg1 .navios1[i].posicao_Y  + u_P_horizontal == n_pontos_jg2 .navios2->atk[j].cord_atk_Y){

                        pontuacao_total_jg2+=5;
         
                        }

                        }
                    }
                }
            }
        


            for(int i = 0 ; i < n_navios ; i++)
            {

                if(strcmp(navios_jg1 .navios1[i].tipo_nav,"P") == 0 && strcmp(navios_jg1 .navios1[i].oriente,"V") == 0)
                {

                    for(int j = 0 ; j < n_ataques ; j++)
                    {

                        for(int u_P_vertical = -2; u_P_vertical <= 2 ; u_P_vertical++)
                        {

        
                        if(navios_jg1.navios1[i].posicao_X + u_P_vertical  == n_pontos_jg2 .navios2->atk[j].cord_atk_X  
                        && navios_jg1 .navios1[i].posicao_Y  == n_pontos_jg2 .navios2->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg2+=5;
         
                        }

                        }

                    }
                }
            }


            for(int i = 0 ; i < n_navios ; i++)
            {

                for(int j = 0 ; j < n_ataques ; j++)
                {

                    if(strcmp(navios_jg1 .navios1[i].tipo_nav,"E") == 0 && strcmp(navios_jg1.navios1[i].oriente,"H") == 0)
                    {

                        for(int u_E_horizontal = -3 ; u_E_horizontal <= 3 ; u_E_horizontal++)
                        {

        
                        if(navios_jg1 .navios1[i].posicao_X   == n_pontos_jg2 .navios2->atk[j].cord_atk_X  
                        && navios_jg1.navios1[i].posicao_Y +  u_E_horizontal == n_pontos_jg2 .navios2->atk[j].cord_atk_Y){

                        pontuacao_total_jg2+=10;
         
                        }

                        }
                    }
                }
            }


            for(int i = 0 ; i < n_ataques ; i++)
            {
                if(strcmp(navios_jg1 .navios1[i].tipo_nav,"E") == 0 && strcmp(navios_jg1 .navios1[i].oriente,"V") == 0)
                {
                    for(int j = 0 ; j < n_ataques ; j++)
                    {
        

                        for(int u_E_vertical = -3 ; u_E_vertical <= 3 ; u_E_vertical++)
                        {

        
                        if(navios_jg1 .navios1[i].posicao_X + u_E_vertical  == n_pontos_jg2 .navios2->atk[j].cord_atk_X  
                        && navios_jg1 .navios1[i].posicao_Y  == n_pontos_jg2 .navios2->atk[j].cord_atk_Y)
                        {

                        pontuacao_total_jg2+=10;


                        }

                        }

                    }
                }
            }

    
            //returna pontuação do jogador 2
            return pontuacao_total_jg2;
}


//essa função é a mais importante, valos liberar toda a memoria que nossa codido armazenou
void libera_mallocs(int quantidade_ataques, int quantidade_navios, int quantidade_jogadores,jogadores libera_estrutura, char **libera_tabuleiro_jg1, char **libera_tabuleiro_jg2){


            //libera quantidade de elementos por linha
            for(int i = 0; i < tamanho_i_j; i++)
            {

                free(libera_tabuleiro_jg1[i]);

                free(libera_tabuleiro_jg2[i]);

            }

                //libera "colula"
                free(libera_tabuleiro_jg1);

                free(libera_tabuleiro_jg2);

                //libera estruturas
                free(libera_estrutura.navios2->atk);

                free(libera_estrutura.navios1->atk);

                free(libera_estrutura.navios2);

                free(libera_estrutura.navios1);
            
            
}


int main()
{   


    int quantidade_navios;

    int quantidade_ataques;

    int quantidade_jogadores = 2;


                jogadores j;

                printf(BOLD_RED"            ____       _   _   \n"RESET);
                printf(BOLD_BLUE"           | __ )     | \\ | |  \n"RESET);
                printf(BOLD_MAGENTA"           |  _ \\     |  \\| |  \n"RESET);
                printf(BOLD_GREEN"           | |_) |    | |\\  |  \n"RESET);
                printf(BOLD_CYAN"           |____/     |_| \\_|  \n"RESET);

                //escolha da quantidade de navios e ataques
                printf(BOLD_WHITE"\nEscolha o numero de navios por jogador:\n");
    
                scanf("%d",&quantidade_navios);


                printf("Escolha a quantidade de ataques por jogador:\n");
    
                scanf("%d",&quantidade_ataques);

                getchar();


            
                //alocaçao para quantidade de navios por jogador
                j.navios1 = malloc(quantidade_navios * sizeof(struct posicao_navios));

                j.navios2 = malloc(quantidade_navios * sizeof(struct posicao_navios ));

                j.navios1->atk = malloc(quantidade_ataques * sizeof(struct  coordenadas_ataque));

                j.navios2->atk = malloc(quantidade_ataques * sizeof(struct  coordenadas_ataque));


                //chamar funçao para definiar as coordenas do navio jogador 1
                char **tab_jogador1 = posicao_navio_jg1(j,quantidade_navios);


                //chamar funçao para definir as coordenadas do navios jogador 2
                char **tab_jogador2 = posicao_navio_jg2(j,quantidade_navios);


                /*define as coordenas de ataque e implementa no tabuleiro do jogador 2 as mesma coordenas inserindo o caracter 'O', sendo necessario
                passar a tabuleiro do jogador 2 (muito importante, no inicio pareceu confuso, mas a lógica é essa)*/
                char **tabuleiro_final_jg2 = ataque_jogador1(j,quantidade_ataques,tab_jogador2);


                /*como temos definido as coordenas dos navios do jg2 e o ataque do jg1 podemos definir a pontuação direto */
                int p_total_jg1 = calculo_pontos_jg1(j,j,quantidade_navios, quantidade_ataques);


                /*define as coordenas de ataque e implementa no tabuleiro do jogador 1 as mesma coordenas inserindo o caracter 'O', sendo necessario
                passar a tabuleiro do jogador 1 (muito importante, no inicio pareceu confuso, mas a lógica é essa)*/
                char **tabuleiro_final_jg1 = ataque_jogador2(j,quantidade_ataques,tab_jogador1);


                /*como temos definido as coordenas dos navios do jg1 e o ataque do jg2 podemos definir a pontuação direto*/
                int p_total_jg2 = calculo_pontos_jg2(j,j,quantidade_navios,quantidade_ataques);


                //impressão do navios do jogaodr 1, com os respectivos navios e a coordenas de ataque do jogador 1
                for(int i = 0; i < tamanho_i_j ; i++)
                {
                    for(int j = 0; j < tamanho_i_j ;j++)
                    {
                        
                        if(tabuleiro_final_jg1[i][j] == '~')
                        {
                    

                            printf(BOLD_CYAN"%c "RESET,tabuleiro_final_jg1[i][j]);


                        }else if(tabuleiro_final_jg1[i][j] == 'O'){

                            printf(BOLD_RED"%c "RESET,tabuleiro_final_jg1[i][j]);

                        }else if(tabuleiro_final_jg1[i][j] == 'C'){

                            printf(BOLD_YELLOW"%c "RESET,tabuleiro_final_jg1[i][j]);

                        }else if(tabuleiro_final_jg1[i][j] == 'P'){

                            printf(BOLD_GREEN"%c "RESET,tabuleiro_final_jg1[i][j]);

                        }else if(tabuleiro_final_jg1[i][j] == 'E'){

                            printf(BOLD_MAGENTA"%c "RESET,tabuleiro_final_jg1[i][j]);

                        }

                    }

                    printf("\n");
                }


                printf("\n");
                //impressão do navios do jogaodr 1, com os respectivos navios e a coordenas de ataque do jogador 2
                for(int i = 0; i < tamanho_i_j ; i++)
                {
                    for(int j = 0; j < tamanho_i_j ;j++)
                    {
                        
                        if(tabuleiro_final_jg2[i][j] == '~')
                        {
                    

                            printf(BOLD_CYAN"%c "RESET,tabuleiro_final_jg2[i][j]);


                        }else if(tabuleiro_final_jg2[i][j] == 'O'){

                            printf(BOLD_RED"%c "RESET,tabuleiro_final_jg2[i][j]);

                        }else if(tabuleiro_final_jg2[i][j] == 'C'){

                            printf(BOLD_YELLOW"%c "RESET,tabuleiro_final_jg2[i][j]);

                        }else if(tabuleiro_final_jg2[i][j] == 'P'){

                            printf(BOLD_GREEN"%c "RESET,tabuleiro_final_jg2[i][j]);

                        }else if(tabuleiro_final_jg2[i][j] == 'E'){

                            printf(BOLD_MAGENTA"%c "RESET,tabuleiro_final_jg2[i][j]);

                        }

                    }

                    printf("\n");
                }


                printf("\n");
                //imprime o ganhador, caso contrario imprime os pontos de empate
                //printf("Calculando pontua\xC3\xA7\xC3\xA3 em: ");
    
                for (int i = 5; i > 0; i--)
                {
                    printf("%d\r", i);
                    fflush(stdout);
                    sleep(1); // Atraso de 1 segundo
                }
                if(p_total_jg1 > p_total_jg2){


                    printf(BOLD_RED"O jogador 1 venceu por %d por %d pontos do jogador 2\n",p_total_jg1,p_total_jg2);


                }else if(p_total_jg2 > p_total_jg1){

                    printf("O jogador 2 venceu por %d por %d pontos do jogador 1\n",p_total_jg2,p_total_jg1);        

                }else 

                    printf("O jogo terminou em empate por %d\n"RESET,p_total_jg1);


                    //chama funçao para liberar memorias alocadas
                    libera_mallocs(quantidade_ataques,quantidade_navios,quantidade_jogadores,j,tab_jogador1,tab_jogador2);

}