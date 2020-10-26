typedef struct Element
{
	int i, j, num, Check;

}Element;

int CheckProblem(int);

void GetNum(int&);

int AddElem(int&, int&, Element**, int, int, int , int );

int GetNumI(int, int&);

int GetNumJ(int, int&, Element*, int, int);

int SearchJ(Element*, int, int, int);

void Sorting(Element*, int);

void Printing(Element*, int);

void PrintingREADY(Element*, int);

int NumTheSameI(Element*, int, int);
