#include<stdio.h>

// FUNCTION TO PRINT BITS OF INTEGER
void printBits(int n)
{
    printf("\nBits of Integer:\n");

    for(int i=31;i>=0;i--)
    {
        int bit=(n>>i)&1;

        printf("%d",bit);
    }

    printf("\n");
}

// FUNCTION TO COUNT NUMBER OF 1 BITS
int countOneBits(int n)
{
    int count=0;

    while(n!=0)
    {
        if(n&1)
        {
            count++;
        }

        n=n>>1;
    }

    return count;
}

// FUNCTION TO CHECK LITTLE/BIG ENDIAN
void checkEndian()
{
    int n=1;

    char *p=(char*)&n;

    printf("\nEndian Check:\n");

    if(*p==1)
    {
        printf("System is Little Endian\n");
    }
    else
    {
        printf("System is Big Endian\n");
    }
}

// FUNCTION TO PRINT FLOAT BITS
void printFloatBits(float f)
{
    int *p=(int*)&f;

    printf("\nBits of Float:\n");

    for(int i=31;i>=0;i--)
    {
        int bit=((*p)>>i)&1;

        printf("%d",bit);
    }

    printf("\n");
}

int main()
{
    int n;
    float f;

    // INPUT INTEGER
    printf("Enter an integer: ");
    scanf("%d",&n);

    // PRINT INTEGER BITS
    printBits(n);

    // COUNT 1 BITS
    printf("\nNumber of 1 bits = %d\n",countOneBits(n));

    // CHECK ENDIAN
    checkEndian();

    // INPUT FLOAT
    printf("\nEnter a float value: ");
    scanf("%f",&f);

    // PRINT FLOAT BITS
    printFloatBits(f);

    return 0;
}