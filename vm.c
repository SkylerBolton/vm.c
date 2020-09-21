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

	// This is a weird way to code this. I've probably forgotten the cooler way.
	char opArray[23][4] =
	{
		"000",
		"LIT", // 1
		"RTN", // 2
		"LOD", // 3
		"STO", // 4
		"CAL", // 5
		"INC", // 6
		"JMP", // 7
		"JPC", // 8
		"SYS", // 9
		"NEG", // 10
		"ADD", // 11
		"SUB", // 12
		"MUL", // 13
		"DIV", // 14
		"ODD", // 15
		"MOD", // 16
		"EQL", // 17
		"NEQ", // 18
		"LSS", // 19
		"LEQ", // 20
		"GTR", // 21
		"GEQ"  // 22
	};

	for(int i = 0; fscanf(fp, "%d", &ins.op) != EOF; i++)
	{
		// Print i and the operation code.
		printf("%d %s", i, opArray[ins.op]);

		// Print line of instructions.
		fscanf(fp, "%d %d %d", &ins.r, &ins.l, &ins.m);
		printf(" %d %d %d\n", ins.r, ins.l, ins.m);

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
