#include <stdio.h>
#include <stdlib.h>
#include <math.h>

double mean(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0;

fp = fopen(str,"r");
//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
}
fclose(fp);
temp = temp/(i-1);
return temp;

}

double variance(char *str)
{
int i=0,c;
FILE *fp;
double x, temp=0.0,sumsq=0,mu,var;

fp = fopen(str,"r");


//get numbers from file
while(fscanf(fp,"%lf",&x)!=EOF)
{
//Count numbers in file
i=i+1;
//Add all numbers in file
temp = temp+x;
sumsq=sumsq+(x*x);
}
fclose(fp);
mu = temp/(i-1);
var = sumsq -( mu*mu);
return var;

}

int  main(void) //main function begins
{
 void gaussian(char *str, int len)
{
int i,j;
double temp;
FILE *fp;

fp = fopen(str,"w");
//Generate numbers
for (i = 0; i < len; i++)
{
temp = 0;
for (j = 0; j < 12; j++)
{
temp += (double)rand()/RAND_MAX;
}
temp-=6;
fprintf(fp,"%lf\n",temp);
}
fclose(fp);

}

 
 
//Uniform random numbers
//uniform("uni.dat", 100);

//Gaussian random numbers
gaussian("gau.dat", 100);

//Mean of uniform
printf("mean=%lf",mean("uni.dat"));
printf("var=%lf",variance("uni.dat"));
return 0;
}
