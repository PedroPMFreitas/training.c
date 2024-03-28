#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TrabFinal.h"

Mem_block* disk_mount(int size){

Mem_block* head = NULL;
Mem_block* atual = NULL;

for(int i = 0; i < size; i++){
    Mem_block* novo_bloco = (Mem_block*)malloc(1024*1024);
    novo_bloco->index = i;
    strcpy(novo_bloco->file_name,"");
    novo_bloco->allocated_flag = 0;
    novo_bloco->next = NULL;

    if(head == NULL){
        head = novo_bloco;
        atual = novo_bloco;

    }else{  
        atual->next = novo_bloco;
        atual = novo_bloco;
    }
    
}
return head;
}
Mem_block* disk_allocate(Mem_block *m, char *name, int size){
    Mem_block* atual = m;
    Mem_block* inicio = NULL;
    int count =0;
    while(atual != NULL){
        if(strcmp(atual->file_name,name)==0){
            printf("Arquivo com o mesmo nome já existe. \n");
            return m;
        }
        atual = atual->next;
    }

    atual = m;

    while(atual != NULL){

        if(atual->allocated_flag==0){

            if(count==0){
                inicio = atual;
            }

            count++;

            if(count == size){
                break;
            }

        }else{
            count = 0;
        }
        atual = atual->next;
    }
    if(count == size){
        atual =inicio;
        strcpy(atual->file_name,name);
        for(int i = 0; i < size; i++){
            atual->allocated_flag=1;
            atual=atual->next;
        }
        return m;
    }else{
        printf("Espaço insuficiente. \n");
        return m;
    }
}
int disk_search_by_name(Mem_block *m, char* name){
    while(m!=NULL){
        if(strcmp(m->file_name,name)==0){
            return m->index;
        }
        m = m->next;
    }
    return -1;
}
Mem_block* disk_delete(Mem_block *m, char* name){
    Mem_block* atual = m;
        while(atual != NULL) {
        if(strcmp(atual->file_name,name)==0){
            Mem_block* aux = atual->next;
            while(aux!=NULL && strcmp(aux->file_name,"")==0){
                aux->allocated_flag = 0;
                strcpy(aux->file_name,"");
                aux = aux->next;
            }
            atual->allocated_flag = 0;
            strcpy(atual->file_name, "");            
        }
        atual = atual->next;
    }
    return m;
}
int disk_allocated(Mem_block *m){ 
    int count = 0;
    while(m != NULL){
        if(m->allocated_flag == 1){
            count++;
        }
        m = m->next;
    }
    return count;
}
void disk_status(Mem_block *m){
    int blocos = 0;
    printf("Total de arquivos alocados: %d MB\n",disk_allocated(m));
    int count = 0,x=0;
    printf("Total de blocos livres:\n");
    while(m != NULL){
        if(m->allocated_flag == 0){
            x++;
            count++;
        }
        if(m-> allocated_flag == 1 || m->next == NULL){
            if(count !=0){
                blocos++;
                printf("bloco %d = %d MB livres\n",blocos,count);
                count = 0;
            }
        }        m = m->next;
    }
    if(x == 0){
        printf("Nenhum bloco livre\n");
    }
}
Mem_block* disk_defrag(Mem_block *m){
    Mem_block* atual = m;
    while(atual!=NULL){
        if(atual->allocated_flag == 0){
        Mem_block* aux = atual;
        while(aux != NULL && aux->allocated_flag==0){
            aux=aux->next;
        }
        if(aux != NULL){
            strcpy(atual->file_name,aux->file_name);
            atual->allocated_flag = aux->allocated_flag;
            strcpy(aux->file_name,"");
            aux->allocated_flag = 0;
        }
        }
        atual = atual->next;
    }
return m;
}
Mem_block* disk_format(Mem_block *m){
    Mem_block* atual = m;
    while(atual != NULL){
        if(atual->file_name!=NULL){
            strcpy(atual->file_name,"");
        }   
        atual->allocated_flag = 0;

        atual = atual->next;
    }
    return m;
}
void disk_unmount(Mem_block *m){
    Mem_block* aux = NULL;
    while(m != NULL){
        aux = m;
        m = m->next;
        free(aux);
    }
}
void disk_print(Mem_block *m){
    while(m != NULL){
        if(m->allocated_flag == 1){
        printf("Bloco %d: %s\n",m->index,m->file_name);
        }
        m = m->next;
    }
}

int main() {
    int x=-1,y;
    Mem_block* disco = NULL;
    printf("\nDigite o tamanho do disco em MB:\n");
    scanf("%d",&y);
    disco = disk_mount(y);

    while(x!=0){
        printf("___________________________________________\n");
        printf("|Alocar um arquivo no disco(1).           |\n");
        printf("|Indice do arquivo(2).                    |\n");
        printf("|Delete um arquivo(3).                    |\n");
        printf("|Quantas celulas estao alocadas(4).       |\n");
        printf("|Status(5).                               |\n");
        printf("|Defrag(6).                               |\n");
        printf("|Formata(7).                              |\n");
        printf("|Imprima todos os blocos alocados(8).     |\n");
        printf("|Teste 3(9)                               |\n");
        printf("|sair e desalocar a memoria utilizada(0). |\n");
        printf("|_________________________________________|\n");

        scanf("%d",&x);

        switch (x)
        {
        case 1:
        {
            int n;
            char c[64];
            printf("Digite o nome do arquivo:");
            scanf("%s",c);
            printf("Digite o tamanho do arquivo em MB:");
            scanf("%d",&n);
            disco = disk_allocate(disco,c,n);
            break;
        }
        case 2:
        {
            char c[64];
            printf("\nDigite o nome do arquivo:");
            scanf("%s",c);
            int s = disk_search_by_name(disco,c);
            printf("\nO indice do arquivo %s e %d.",c,s);
            break;
        }
        case 3:
        {   
            char c[64];
            printf("\nDigite o nome do arquivo:");
            scanf("%s",c);
            disco = disk_delete(disco,c);
            break;
        }
        case 4:
        {
            int a = disk_allocated(disco);
            printf("\nA quantidade de celulas alocadas e : %d.\n",a);
            break;
        }
        case 5:
        {
            disk_status(disco);
            break;
        }
        case 6:
        {
            disco = disk_defrag(disco);       
            break;
        }
        case 7:
        {
            disco = disk_format(disco);
            break;
        }
        case 8:
        {
            disk_print(disco);
            break;
        }
        case 9:
        {
            int z=0;
            z=y+1;
            z=z-disk_allocated(disco);
            for(int i =0;i<z;i++){
                char nome[64];
                sprintf(nome,"arq%d",i);
                disco=disk_allocate(disco,nome,1);
            }
            break;
        }
        default:{
            break;
        }
    }
    }
    disk_unmount(disco);

    return 0;
}




