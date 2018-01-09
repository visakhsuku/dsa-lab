#include<stdio.h>

struct Ratio
{
	int x, y;
};

int checkRatio(struct Ratio r)
{
	if(r.y == 0)
		return 1;
	return 0;
}

struct Ratio simplestForm(struct Ratio r)
{
	int i, sign = 1;
	int x = r.x, y = r.y;
	if(x < 0)
	{
		sign *= -1;
		x *= -1;
	}
	if(y < 0)
	{
		sign *= -1;
		y *= -1;
	}
	for(i = 2; (i <= x) && (i <= y); i++)
	{
		while((x % i == 0) && (y % i == 0))
		{
			x = x / i;
			y = y / i;
		}
	}
	r.x = sign*x;
	r.y = y;
	return r;
}

int compRatio(struct Ratio r1, struct Ratio r2)
{
	if(r1.y * r2.y > 0)
	{
		if(r1.x*r2.y - r2.x*r1.y >= 0)
			return 1;
		return 0;
	}
	else
	{
		if(r1.x * r2.y - r2.x * r1.y > 0)
			return 0;
		return 1;
	}
}

void printRatio(struct Ratio r)
{
	printf("%d/%d", r.x, r.y);
}

struct Ratio addRatio(struct Ratio r1, struct Ratio r2)
{
	struct Ratio r;
	r.x = r1.x*r2.y + r2.x*r1.y;
	r.y = r1.y*r2.y;
	return simplestForm(r);
}

struct Ratio product(struct Ratio r1, struct Ratio r2)
{
	struct Ratio r;
	r.x = r1.x*r2.x;
	r.y = r1.y*r2.y;
	return simplestForm(r);
}

int main()
{
	struct Ratio r1, r2;
	int ch;
	scanf("%d", &ch);
	if(ch == 1)
	{
		scanf("%d %d", &r1.x, &r1.y);
		if(checkRatio(r1))
		{
			printf("Denominator cannot be zero\n");
			return 0;
		}
		printRatio(simplestForm(r1));
		printf("\n");
	}
	else if(ch == 2)
	{
		scanf("%d %d", &r1.x, &r1.y);
		if(checkRatio(r1))
		{
			printf("Denominator cannot be zero\n");
			return 0;
		}
		scanf("%d %d", &r2.x, &r2.y);
		if(checkRatio(r2))
		{
			printf("Denominator cannot be zero\n");
			return 0;
		}
		printRatio(addRatio(r1, r2));
		printf("\n");
	}
	else if(ch == 3)
	{
		scanf("%d %d", &r1.x, &r1.y);
		if(checkRatio(r1))
		{
			printf("Denominator cannot be zero\n");
			return 0;
		}
		scanf("%d %d", &r2.x, &r2.y);
		if(checkRatio(r2))
		{
			printf("Denominator cannot be zero\n");
			return 0;
		}
		printRatio(product(r1, r2));
		printf("\n");
	}
	else if(ch == 4)
	{
		int n;
		scanf("%d", &n);
		struct Ratio r[n];
		int i;
		for(i = 0; (i < n); i++)
		{
			scanf("%d %d", &r[i].x, &r[i].y);
			if(checkRatio(r[i]))
			{
				printf("Denominator cannot be zero\n");
				return 0;
			}
		}
		for(i = 0; i < n; i++)
		{
			int j;
			for(j = 0; j < n - 1; j++)
			{
				if(compRatio(r[j], r[j + 1]))
				{
					int t1 = r[j].x;
					int t2 = r[j].y;
					r[j].x = r[j + 1].x;
					r[j].y = r[j + 1].y;
					r[j + 1].x = t1;
					r[j + 1].y = t2;
				}
			}
		}
		for(i = 0; i < n; i++)
		{
			printRatio(r[i]);
			printf(" ");
		}
		printf("\n");
	}
	else if(ch == 5)
	{
		struct Ratio r;
		scanf("%d %d", &r.x, &r.y);
		if(checkRatio(r))
		{
			printf("Denominator cannot be zero\n");
			return 0;
		}
		printRatio(simplestForm(r));
		printf("\n");
	}
	return 0;
}
