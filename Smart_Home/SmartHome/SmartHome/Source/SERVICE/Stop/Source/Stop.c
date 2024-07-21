

#include "Stop.h"

boolean System_Stop_Status = FALSE;

boolean System_Stop()
{
	return System_Stop_Status;
}

void Set_System_Stop()
{
	System_Stop_Status = TRUE;
}