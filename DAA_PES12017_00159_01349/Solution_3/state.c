#include <stdio.h>
#include "state.h"

void init_state(state_t *ptr_state)
{
	ptr_state->one = 1;
	ptr_state->two = 1;
	ptr_state->five = 1;
	ptr_state->ten = 1;
	ptr_state->flash = 1;
	ptr_state->fn_index = 0;
}
void disp_state(const state_t *ptr_state)
{
	printf("One : %d, Two : %d, Five : %d, Ten : %d, Flash : %d, fn_index:%d\n", ptr_state->one, ptr_state->two, ptr_state->five, ptr_state->ten, ptr_state->flash, ptr_state->fn_index);
}

void move_one(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->one = src->one - 1;
	}
	else
	// right to left
	{
		dst->one = src->one + 1;
	}
	dst->two = src->two;
	dst->five = src->five;
	dst->ten = src->ten;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void move_two(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->two = src->two - 1;
	}
	else
	// right to left
	{
		dst->two = src->two + 1;
	}
	dst->one = src->one;
	dst->five = src->five;
	dst->ten = src->ten;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}
void move_five(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->five = src->five - 1;
	}
	else
	// right to left
	{
		dst->five = src->five + 1;
	}
	dst->two = src->two;
	dst->one = src->one;
	dst->ten = src->ten;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}
void move_ten(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->ten = src->ten - 1;
	}
	else
	// right to left
	{
		dst->ten = src->ten + 1;
	}
	dst->two = src->two;
	dst->five = src->five;
	dst->one = src->one;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}
void move_onetwo(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->one = src->one - 1;
		dst->two = src->two - 1;
	}
	else
	// right to left
	{
		dst->one = src->one + 1;
		dst->two = src->two + 1;
	}

	dst->five = src->five;
	dst->ten = src->ten;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void move_onefive(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->one = src->one - 1;
		dst->five = src->five - 1;
	}
	else
	// right to left
	{
		dst->one = src->one + 1;
		dst->five = src->five + 1;
	}
	dst->two = src->two;

	dst->ten = src->ten;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void move_oneten(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->one = src->one - 1;
		dst->ten = src->ten - 1;
	}
	else
	// right to left
	{
		dst->one = src->one + 1;
		dst->ten = src->ten + 1;
	}
	dst->two = src->two;
	dst->five = src->five;

	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void move_twofive(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->five = src->five - 1;
		dst->two = src->two - 1;
	}
	else
	// right to left
	{
		dst->five = src->five + 1;
		dst->two = src->two + 1;
	}
	dst->one = src->one;

	dst->ten = src->ten;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void move_twoten(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->five = src->five - 1;
		dst->two = src->two - 1;
	}
	else
	// right to left
	{
		dst->five = src->five + 1;
		dst->two = src->two + 1;
	}
	dst->one = src->one;
	dst->five = src->five;

	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void move_fiveten(const state_t *src, state_t *dst)
{
	if(src->flash == 1)
	// left to right
	{
		dst->five = src->five - 1;
		dst->ten = src->ten - 1;
	}
	else
	// right to left
	{
		dst->five = src->five + 1;
		dst->ten = src->ten + 1;
	}
	dst->two = src->two;
	dst->one = src->one;
	dst->flash = ! src->flash;
	dst->fn_index = 0;
}

void set_state(state_t *ptr_state, int one, int two, int five, int ten, int flash)
{
	ptr_state->one = one;
	ptr_state->two = two;
	ptr_state->five = five;
	ptr_state->ten = ten;
	ptr_state->flash = flash;
}

int is_safe(const state_t* ptr_state)
//all one's , two's, five's and ten's should be either 1 or 0 and
//there should not be a case that flash light is on the other side and all people are on the other
{
	return (((ptr_state->one==0 || ptr_state->one==1) && ( ptr_state->two==0 || ptr_state->two==1 )&&
			 (ptr_state->five==0 || ptr_state->five==1) && (ptr_state->ten==0 || ptr_state->ten==1)) &&
			 !(ptr_state->one==1 && ptr_state->two==1 && ptr_state->five==1 && ptr_state->ten==1 &&
			 ptr_state->flash==0));

}

int are_same(const state_t *lhs, const state_t *rhs)
//same fields but fn_index
{
	return lhs->one == rhs->one && lhs->two == rhs->two && lhs->five == rhs->five && lhs->ten == rhs->ten && lhs->flash == rhs->flash;
}






