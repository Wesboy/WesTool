#include <stdio.h>


int main(int argc, char **argv)
{
    int i;
    if(argc > 1)
    {
        i = 1;
        printf("argc:%d\r\n", argc);   
        while(i < argc)
        {
            printf("%s", argv[i]);
            i++;
        }
        printf("\r\n");
    }
    return 0;
}
