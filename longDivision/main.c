#include "stdio.h"
#include "stdlib.h"
#include "conio.h"

void readArray(float numerator[], int n)
{
    int i;
    for(i=n;i>=0;i--)
    {
        printf("coef of X^%d: ",i);
        scanf("%f",&numerator[i]);
    }
}

void printArray(float arr[] , int n)
{
    int i;
    for(i=n; i>=0; i--)
        {
           if(arr[i]!=0)
            {
                if(i==0)
                    printf("%.2f ",arr[i]);
                else if(i==1)
                    printf("%.2fX + ",arr[i]);
                else
                    printf("%.2fX^%d + ",arr[i],i);
            }
        }
}


void longDivision(float numerator[], float denominator[],int sizeNum, int sizeDen, float quotient[],float remainder[])
{



        float subLine[25]={0};          //quotient*denominator
        float newNumerator[25]={0};    //   numerator-subLine
        int maxNumDeg =sizeNum;
        int maxDenoDeg = sizeDen;
        int numIndex =sizeNum;     //sizeNum doesn't change while numIndex changes
        int denIndex =sizeDen;     //sizeDem doesn't change while denIndex changes
        int quotientPow = numIndex-sizeDen;
        int firstEntry=0;

        quotient[quotientPow]= numerator[numIndex]/ denominator[sizeDen];
        int subLinePow =quotientPow +denIndex;

    if(sizeNum>=sizeDen)
    {
        for(numIndex=sizeNum ;numIndex>=sizeDen ;numIndex--)
        {
            quotientPow = numIndex-sizeDen;
            denIndex =sizeDen;
            subLinePow = quotientPow +denIndex;

            if(numIndex!=sizeNum)
            {
                quotient[quotientPow]= newNumerator[numIndex] / denominator[sizeDen];
            }

            for(sizeNum=numIndex ;sizeNum>=0 ;sizeNum--)
            {
                if(denIndex>=0)
                {
                    subLine[subLinePow]=quotient[quotientPow] * denominator[denIndex--];
                }
                if(firstEntry==0)
                    newNumerator[subLinePow]=numerator[subLinePow] -subLine[subLinePow];
                else
                    newNumerator[subLinePow]=newNumerator[subLinePow] -subLine[subLinePow];

                subLinePow--;
            }


                firstEntry++;
        }

        printf("\n=============== The Result ===============\n\n");
            //print the quotient
            printArray(quotient , maxNumDeg);

            //store the remainder
            for(subLinePow=maxDenoDeg; subLinePow>=0; subLinePow--)
            {
                remainder[subLinePow]=newNumerator[subLinePow];
            }
            int checkRemainder=0;
            for(subLinePow=maxDenoDeg; subLinePow>=0; subLinePow--)
            {
                if(remainder[subLinePow]!=0)
                    checkRemainder=1;
            }
            if(checkRemainder==1)
            {
                //print remainder
                printf("+(");
                printArray(remainder , maxDenoDeg);
                printf(")/(");
                printArray(denominator , maxDenoDeg);
                printf(")");
            }
    }
    else
    {
        printf("\n=============== The Result ===============\n\n");
            printf("(");
            printArray(numerator , maxDenoDeg);
            printf(")/(");
            printArray(denominator , maxDenoDeg);
            printf(")");
    }


}
void main()
{
   float numerator[25]={0};
   float denominator[25]={0};
   float quotient[25]={0};
   float remainder[25]={0};
   int sizeNum=30 ,sizeDen=30;
   int i;

   int x=1  ;//to check the degree entered not bigger than x^24


   printf("         the degree of the numerator and denominator must be less than 25\n");
   printf("enter highest degree for numerator and denominator in form: Numerator,denominator\n");
   scanf("%d,%d",&sizeNum,&sizeDen);

    if(sizeDen>=25 || sizeNum>=25) x=0;
    while(x==0)
    {
        printf("                       ERROR!!\n");
        printf("enter degree less than 25 in form:  Numerator,denominator\n");
        scanf("%d,%d",&sizeNum,&sizeDen);
        if(sizeDen<25 && sizeNum<25) x=1;
    }
    printf("\n");


   printf("Numerator Coefficients:\n");
   readArray(numerator,sizeNum);

   printf("Denominator Coefficients:\n");
   readArray(denominator,sizeDen);


   printf("\n============= The Polynomial =============\n\n");
            printf("(");
            printArray(numerator , sizeNum);

            printf(")/(");
            printArray(denominator , sizeDen);

            printf(")\n");
   longDivision(numerator,denominator,sizeNum,sizeDen,quotient,remainder);
   printf("\n");
   getch();
}
