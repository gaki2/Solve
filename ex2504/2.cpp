#include <iostream>
#include <stack>

stack<int> bras;
int bra_count[2];

bool Is_ValidPos(void)
{
	if (bra_count[0] < 0 || bra_count[1] < 0)
		return (false);
	else
		return (true);
}



void Input(void)
{
	while (true)
	{
		char bra;
		scanf("%c", bra);
		if (bra == '\n') break;

		if (bra == '(')
		{
			bra_count[0]++;
			bras.push(-1);
		}
		else if (bra == ')')
		{
			bra_count[0]--;
			bras.push(-2);
		}
		else if (bra == '[')
		{
			bra_count[1]++;
			bras.push(-3);
		}
		else if (bra == ']')
		{
			bra_count[1]--;
			bras.push(-4);
		}

		if (!Is_Valid_Pos()








