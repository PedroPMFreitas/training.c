#include <stdio.h>
#include <stdlib.h>

struct mem_block {
int index;
char file_name[64];
int allocated_flag;
struct mem_block* next;
};
typedef struct mem_block Mem_block; 

Mem_block* disk_mount(int size);
Mem_block* disk_allocate(Mem_block *m, char *name, int size);
int disk_search_by_name(Mem_block *m, char* name);
Mem_block* disk_delete(Mem_block *m, char* name);
int disk_allocated(Mem_block *m);
void disk_status(Mem_block *m);
Mem_block* disk_defrag(Mem_block *m);
Mem_block* disk_format(Mem_block *m);
void disk_unmount(Mem_block *m);
void disk_print(Mem_block *m);
