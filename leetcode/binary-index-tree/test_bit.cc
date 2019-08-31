#include <stdio.h>

int BIT[1000], a[1000], n;

void update(int pos, int val)
{
    while(pos <= n){
	BIT[pos] += val;
	pos += pos&(-pos);
    }
}

int query(int pos)
{
    int sum = 0;
    while(pos > 0){
	sum += BIT[pos];
	pos -= pos&(-pos);
    }
    return sum;
}

int main()
{
    scanf("%d", &n);
    int i;
    for(i = 1; i<= n; i++)
    {
	scanf("%d", &a[i]);
	update(i, a[i]);
    }
    printf("done with BIT tree building\n");
    int pos1, pos2;
    scanf("%d", &pos1);
    scanf("%d", &pos2);
    while(pos1 < n && pos2 < n && pos1 < pos2 ){
	printf("sum of first %d elements is %d\n", pos1, query(pos1));
	printf("sum of all elemetns in range [%d, %d] is %d\n", pos1, pos2, query(pos2) - query(pos1 - 1));
    
	scanf("%d", &pos1);
	scanf("%d", &pos2);
    }
}
