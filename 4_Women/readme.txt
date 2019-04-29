Understanding the problem:

There are 4 women who want to cross a bridge. They all begin on the same
side. You have 17 minutes to get all of them across to the other side. It is
night. There is one flashlight. A maximum of two people can cross at one time.
Any party who crosses, either 1 or 2 people, must have the flashlight with
them. The flashlight must be walked back and forth, it cannot be thrown, etc.
Each woman walks at a different speed. A pair must walk together at the rate
of the slower woman. Crossing times taken by the 4 women are 1, 2, 5, and
10 minutes.

Approach:
	Clearly we need to go through all combinations but try to avoid those combinations which 
	are invalid under the given constraints. This problem can be solved using backtracking. 

	We build a state space search tree for it and backtrack if the state obtained violated the
	constraints.

	I will first introduce all the concepts needed to udnerstand this state space search tree
	and then we will move to the solution.

	struct state
	{
		//let's say all women are on the left of the bridge and their goal is to be on the right of the bridge
		int one;  // whether the woman who can cross bridge in 1 minute is on left or not
		int two;  // whether the woman who can cross bridge in 2 minute is on left or not
		int five; // whether the woman who can cross bridge in 5 minute is on left or not
		int ten;  // whether the woman who can cross bridge in 10 minute is on left or not

		int flash; //1 - flashlight is on left side  0 - on right
		
		int fn_index;//The index of transition to take.
	};

	This is the structure we will use to depict a state. For brevity, while explanation I will
	use a tuple (one,two,five,ten,flash). The last field is just to store the next transition to take.

	What do we mean by a transition?
	All possible moves from a state.
	These are the transitions we use

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

	The indexes of these functions are:
	0:	move_one,
	1:	move_two,
	2:	move_five,
	3:	move_ten,
	4:	move_onetwo,
	5:	move_onefive,
	6:	move_oneten,
	7:	move_twofive,
	8:	move_twoten,
	9:	move_fiveten

	That's it!. We have all the solutions. Let's go to the solution.

	Initial state: (1,1,1,1,1) 	//as explained earlier, this depicts everything on left
								//(one,two,five,ten,flash)
								//(1,1,1,1,1) means women who walk in 1,2,5,10 and flash are on 
								//left side

	Final state: (0,0,0,0,0)	//we want everything on right at the end.


	How do we find out if it is under 17 minutes?
		We maintain a list which stores the solution. That is on going to a state, that state
		is added to the list and on backtracking, that state is removed from the list. 
				

	How do we know if a state is safe or not. We define some constraints:
	i) all values of one,two,five,ten can only be 1 or 0(left or right)
	ii) there should not exist a case such that all women are on one side and flashlight on other
	iii) state should not be repeated as it make everything done till that point redundant and 
		results in infinite loop
	iv) Cost of the list is <= 17.

	Consider the initial state (1,1,1,1,1)
	On transition 0 , it becomes (0,1,1,1,0) which is safe
	On transition 0 , it becomes (1,1,1,1,1) which is repeated, threfore we backtrack and use the next index
	which is transition 1
	On transition 1, it becomes (0,2,1,1,1) which is not safe. 
	We try all transitions in the same way until we exhaust all indices for the start state.

	The output at the end is;

	(1,1,1,1,1)
	(0,0,1,1,0)
	(1,0,1,1,1)
	(1,0,0,0,0)
	(1,1,0,0,1)
	(0,0,0,0,0)

	(1,1,1,1,1)
	(0,0,1,1,0)
	(0,1,1,1,1)
	(0,1,0,0,0)
	(1,1,0,0,1)
	(0,0,0,0,0)

	We have 2 solutions to this problem. 

Time complexity:
	Worst case is O(n!).