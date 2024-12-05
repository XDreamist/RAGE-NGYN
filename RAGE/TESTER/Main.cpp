
#pragma comment(lib, "NGYN.lib")

#define NTT_COMP_TEST 1

#if NTT_COMP_TEST
#include "NttCompTest.h"

#else
#error One of the tests need to be enabled

#endif

int main()
{

#if _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	new float[4];
	NGYN_Test Test{};

	if (Test.initialize())
	{
		Test.run();
	}

	Test.shutDown();
}