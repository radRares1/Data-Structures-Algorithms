#include "Matrix.h"
#include <assert.h>

using namespace std;

void testAll() {
	Matrix m(4, 4);
	assert(m.nrLines() == 4);
	assert(m.nrCols() == 4);
 	m.modify(1, 1, 5);
	assert(m.element(1, 1) == 5);
	m.modify(1, 1, 6);
	assert(m.element(1, 2) == 0);
}

int main()
{
	testAll();
}