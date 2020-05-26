#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

#define INF 215451515
#define N 10000
struct node
{
	double x;
	double y;
}point[N];

int cmp(const void* a, const void* b)
{
	struct node ac = *(struct node*)a;
	struct node bd = *(struct node*)b;
	if (ac.x != bd.x)
		return ac.x - bd.x;
	else return ac.y - bd.y;
}

double mindistance(double left, double right)
{
	return left < right ? left : right;
}
double distance(int left, int right)
{
	return sqrt((point[left].x - point[right].x) * (point[left].x - point[right].x) + (point[left].y - point[right].y) * (point[left].y - point[right].y));
}

double Closest_Pair(int left, int right)
{
	double End_dis = INF;
	int i = 0, j = 0, k = 0;
	if (left = right)
		return End_dis;

	if (right - left == 1)
		return distance(left, right);

	int mid = (left + right) / 2;
	double distanceleft = Closest_Pair(left, mid);
	double distanceright = Closest_Pair(mid + 1, right);
	End_dis = mindistance(distanceleft, distanceright);
	int temp[N] = { 0 };
	for (i = left; i <= right; i++)
	{
		if (fabs(point[mid].x - point[i].x) <= End_dis)
			temp[k++] = i;
	}
	for (i = 0; i <= k - 1; i++)
		for (j = i + 1; j <= k - 1; j++)
			if (point[temp[j]].y - point[temp[i]].y < End_dis)
				End_dis = mindistance(End_dis, distance(temp[i], temp[j]));
	return End_dis;
}

int main()
{
	int n = 1;
	while (scanf("%d", &n) == 1 && n)
	{
		for (int i = 0; i < n; i++)
			scanf("%lf %lf", &point[i].x, &point[i].y);
		qsort(point, n, sizeof(point[0]), cmp);
		printf("%.2lf\n", Closest_Pair(0, n - 1));
	}
	return 0;
}
