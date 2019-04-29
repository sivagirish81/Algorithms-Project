#ifndef STATE_H
#define STATE_H
struct state
{
	//let's say all women are on the left of the bridge and their goal is to be on the right of the bridge
	int one;  // whether the woman who can cross bridge in 1 minute is on left or not
	int two;  // whether the woman who can cross bridge in 2 minute is on left or not
	int five; // whether the woman who can cross bridge in 5 minute is on left or not
	int ten;  // whether the woman who can cross bridge in 10 minute is on left or not

	int flash; //1 - flashlight is on left side  0 - on right
	
	int fn_index;
};
typedef struct state state_t;
void init_state(state_t *ptr_state);
void disp_state(const state_t *ptr_state);
void set_state(state_t *ptr_state, int one, int two, int five, int ten, int flash);

void move_one(const state_t *src, state_t *dst);	//only woman who walks in 1 minute moves
void move_two(const state_t *src, state_t *dst);	//only woman who walks in 2 minute moves
void move_five(const state_t *src, state_t *dst);	//only woman who walks in 5 minute moves
void move_ten(const state_t *src, state_t *dst);	//only woman who walks in 10 minute moves
void move_onetwo(const state_t *src, state_t *dst);	//women who walk in 1 and 2 minute move
void move_onefive(const state_t *src, state_t *dst);//women who walk in 1 and 5 minute move
void move_oneten(const state_t *src, state_t *dst);//women who walk in 1 and 10 minute move
void move_twofive(const state_t *src, state_t *dst);//women who walk in 2 and 5 minute move
void move_twoten(const state_t *src, state_t *dst);//women who walk in 2 and 10 minute move
void move_fiveten(const state_t *src, state_t *dst);//women who walk in 5 and 10 minute move

int is_safe(const state_t* ptr_state);
int are_same(const state_t *lhs, const state_t *rhs);
#endif

