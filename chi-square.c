#include <stdio.h>
#include <math.h> 

#define	half 0.5
#define	one  1.0
#define	fpf  5.5
#define	zero 0.0
#define EXP 2.7183

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

//Factorial Function
int factorial(int f)
{
	int fact=1;
	for(int j=f;j>0;j--)
		{
			fact = fact * j;
		}
	return fact;
}

//Chi-Square Funtions
double chi_part1(double v)
{
	double gamma_value = gamma(v/2);
	double power = (v/2);
	double first_part = pow(2,power);
	double ans = (1/(first_part*gamma_value));
	return ans;
}

double chi_part2 (double chi_value)
{
	double power_cal = (chi_value/2);
	double part2 = pow(EXP,-power_cal);
	return part2;
}

double chi_part3(double chi_value, double v)
{
	double power_cal = ((v/2)-1);
	double ans = pow(chi_value, power_cal);
	return ans;
}

//Main Functions
int main()
{
double v;
printf("Enter the value of v: ");
scanf("%lf",&v);
int n;
printf("Enter the number of iterations: ");
scanf("%d",&n);

for(double i=0.1;i<=n;i=i+0.1)
{
double ans = chi_part1(v)*chi_part2(i)*chi_part3(i, v);
printf("%f\n",ans);
}


return 0;
}
