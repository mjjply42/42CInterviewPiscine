#include "header.h"
#include "math.h"

int			carPosition(unsigned int parkingRow)
{
	int		ret;

	ret = -1;
	if (parkingRow != 0 && ((parkingRow & (parkingRow - 1)) == 0))
	{
		ret = (int)log2(parkingRow);
	}
	return (ret);
}