#include <stdio.h>

typedef struct Instructions
{
	int op;
	int r;
	int l;
	int m;
} instructions;

// This function will:
// 1. Print the assembly code of the program
// 2. Store the program somehow for later reference.
void createAssemblyProgram(FILE *fp, instructions ins)
{
	printf("Line	OP	R	L	M\n");
	for(int i = 0; fscanf(fp, "%d", &ins.op) != EOF; i++)
	{
		// Print line of instructions.
		fscanf(fp, "%d", &ins.r);
		fscanf(fp, "%d", &ins.l);
		fscanf(fp, "%d", &ins.m);
		printf("%d %d %d %d %d\n", i, ins.op, ins.r, ins.l, ins.m);

		// Put it into the thing for reference.
	}
	printf("\n\n\n");
	return; // idk what to return yet
}

// Takes a thing.
void createExecution()
{
	printf("Second part would go here.\n");
	return;
}

int main(int argc, char *argv[])
{
	FILE *fp;
	instructions ins;
	if((fp = fopen(argv[1], "r")) == NULL)
	{
		printf("Unable to open file :(\n");
		return 0;
	}
	createAssemblyProgram(fp, ins);
	createExecution();
	return 0;
}
