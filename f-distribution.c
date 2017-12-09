#include <stdio.h>
#include <math.h> 

#define	half 0.5
#define	one  1.0
#define	fpf  5.5
#define	zero 0.0

//Gamma Function
double gamma(double xx)
{
	double cof[7],stp,x,tmp,ser;
	int j;
	cof[1]=76.18009173;
	cof[2]=-86.50532033;
	cof[3]=24.01409822;
	cof[4]=-1.231739516;
	cof[5]=0.120858003e-2;
	cof[6]=-0.536382e-5;
	stp=2.50662827465;

	x=xx-one;
	tmp=x+fpf;
	tmp=(x+half)*log(tmp)-tmp;
	ser=one;
	for (j=1; j<7; j++)
	{
		x=x+one;
		ser=ser+cof[j]/x;
	}
	return (exp(tmp+log(stp*ser)));
}

//F-Distribution Functions
double part1(double n1, double n2)
{
double power = (n1/2), num = (n1/n2);
double upper = pow(num, power);
double first=(n1/2), second=(n2/2), add=first+second;
double B = (gamma(first)*gamma(second))/gamma(add);
double ans = upper/B;
return ans;
}

double part2(double n1,double n2, double f)
{
double power = ((n1/2)-1);
double upper = pow(f, power);
double power2 = ((n1+n2)/2);
double part = (1+((n1*f)/n2));
double lower  = pow(part, power2);
double ans = upper/lower;
return ans;
}

//Main Functions
int main()
{
double n1, n2;
printf("Enter the value of n1: ");
scanf("%lf",&n1);
printf("Enter the value of n2: ");
scanf("%lf",&n2);
int n;
printf("Enter the number of iterations: ");
scanf("%d",&n);

for(double f=0.1;f<=n;f=f+0.1)
{
double ans = part1(n1,n2) * part2(n1,n2,f);
printf("%f\n",ans);
}

return 0;
}
