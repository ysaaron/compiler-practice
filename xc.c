#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include <fcntl.h>

int pool_size;
int line;
char *src, *old_src;
int token;

// virtual machine registers
int *pc,
    *bp,
    *sp,
    ax,
    cycle;

// instructions
enum { LEA, IMM, JMP, CALL, JZ, JNZ, ENT, ADJ, LEV, LI, LC, SI, SC, PUSH,
    OR, XOR, AND, EQ, NE, LT, GT, LE, GE, SHL, SHR, ADD, SUB, MUL, DIV, MOD,
    OPEN, READ, CLOS, PRTF, MALC, MSET, MCMP, EXIT 
};


static inline long get_file_size(FILE *);
static inline void free_global_var();
static inline int eval(void);
static inline void expression(int);
static inline void program(void);
static inline void next(void);

int main(int argc, char **argv) {
    int i, fd;
    FILE *fp;
    long fsize;
    line = 1;
    pool_size = 1 << 18;

    if (!(fp = fopen("hello.c", "r"))) {
        printf("could not open(hello.c)\n\n");
        return -1;
    }

    fsize = get_file_size(fp);

    if (!(src = old_src = (char*) malloc(sizeof(char) * fsize))) {
        printf("cound not malloc memory\n\n");
        return -1;
    }

    fread(src, 1, fsize, fp);

    fclose(fp);
    free_global_var();
    return 0;
}

static inline long get_file_size(FILE *fp) {
    long fsize = 0;

    if (!fp) {
        fseek(fp, 0, SEEK_END);
        fsize = ftell(fp);
        fseek(fp , SEEK_SET, 0);
    }

    return fsize;
}

static inline void free_global_var() {
    if (!src) {
        free(src);
    }
}

static inline int eval() {
    int op, *tmp;

    while (1) {
        if (op == IMM) {

        } else if (op == LC) {

        }
    }

    return op;
}

static inline void program(void) {

}

static inline void next(void) {
    token = *src++;
    return;
}