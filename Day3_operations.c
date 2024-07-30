#include<stdio.h>
#include "Day3_header.h"

int convert_binary_to_decimal(int num)
{
        int temp=num, lastdigit;
        int digitval=0,base=1;
        while(temp>0)
        {
            lastdigit=temp%10;
            digitval+=lastdigit*base;
            temp=temp/10;
            base=base*2;
        }
     return digitval;

}


int convert_decimal_to_binary(int num)
{
    int temp=num,digitval=0;
    int base=1,lastdigit;
    while(temp>0)
    {
        lastdigit=temp%2;
        digitval+=lastdigit*base;
        temp=temp/2;
        base=base*10;
    }
    return digitval;
}

void generate_sequence_of_numbers(int n)
{
    int n1=0,n2=0,n3=1,sum=0;
    printf("%d,%d,%d",n1,n2,n3);
    for(int i=3;i<=n;i++)
    {
        sum=n1+n2+n3;
        printf(",%d",sum);
        n1=n2;
        n2=n3;
        n3=sum;
    }

}

void generate_inverted_pattern(int n)
{
    for(int i=n;i>=1;i--)
    {
        for(int space=0;space<n-i;space++)
        {
            printf(" ");
        }
        for(int j=i;j<=2*i-1;j++)
        {
            printf("*");
        }
        printf("\n");
    }
}

void generate_pattren_using_single_loop(int n)
{
    int curr_star=0;
    for(int i=1;i<=n;)
    {
        if(curr_star<i)
        {
            printf("*");
            curr_star++;
            continue;
        }
        if(curr_star==i)
        {
            printf("\n");
            i++;
            curr_star=0;
        }
    }
}


void print_two_digit_number_sum_is_9()
{
    int rem1,rem2;
    for(int i=10;i<=99;i++)
    {
        rem1=i%10;
        rem2=i/10;
        if((rem1+rem2)==9)
            printf("%d\t",i);
    }
}


float print_power_of_number(int base,int number)
{
    if(number==0)
        return 1;
    else
        return(base*print_power_of_number(base,number-1));
}

float factorial(int n)
{
    if(n==1)
        return 1;
    else
        return(n*factorial(n-1));
}

float evaluation_of_expression(int x,int n)
{
    float sum;
    if(x!=0)
    {
        for(int i=1;i<=n;i+=2)
        {
            sum=sum+(print_power_of_number(x,i)/factorial(i));
        }
        return sum;
    }
    return 0;
}

