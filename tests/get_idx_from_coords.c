#include "navy.h"
#include "./include/signals_testing.h"
#include "./include/unit_testing.h"

Test(coords_to_idx, coords_to_idx1)
{
	int	idx = 0;
	
	idx = get_idx_from_coords("B1");
	cr_assert_eq(idx, 1);
}

Test(coords_to_idx, coords_to_idx2)
{
	int	idx = 0;
	
	idx = get_idx_from_coords("G5");
	cr_assert_eq(idx, 38);
}

Test(coords_to_idx, coords_to_idx3)
{
	int	idx = 0;
	
	idx = get_idx_from_coords("H8");
	cr_assert_eq(idx, 63);
}

Test(coords_to_idx, coords_to_idx4)
{
	int	idx = 0;
	
	idx = get_idx_from_coords("F3");
	cr_assert_eq(idx, 21);
}

Test(coords_to_idx, coords_to_idx5)
{
	int	idx = 0;
	
	idx = get_idx_from_coords("D6");
	cr_assert_eq(idx, 43);
}
