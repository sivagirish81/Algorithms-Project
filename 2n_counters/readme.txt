
Understanding the problem:

For a value of n, we are given a line of 2n counters with no spaces between adjacent counters.
The counters alternate between Black and White.
eg: for n = 3
	BWBWBW
	for n = 4
	BWBWBWBW

The objective is to rearrange the counters so that all the white counters are before all the
black ones with no gaps between the counters.
eg: for n = 3
	WWWBBB
	for n = 4
	WWWWBBBB

Constraints:
	The counters are to be moved in pairs only. On each move, a pair of adjacent counters can be 
	moved without changing their order, into a vacant location(We can use as many spaces as needed
	on either ends of string).
	The algorithm designed should solved the problem in n moves for n>=3

Approach:

	Let us trace the code for some early numbers and try to find a pattern so that we can produce
	the solution for larger values of n.

	For n=3:
		1 2 3 4 5 6 (positions of characters to trace. Note that the spaces are just for sake
					of clarity. There are no spaces between adjacent counters)
		B W B W B W 
	W B B _ _ W B W 	//move 2,3 to before the start of string(underscore represents characters have been removed from that position)
	W B B B W W _ _		//move 5,6 to 2,3
W W W B B B _ _ _ _		//move 3,4 to start of string

	This took 3 moves which is correct solution for n=3

	For n=4:
		1 2 3 4 5 6 7 8
		B W B W B W B W
	W B B W B W B _ _ W 	//move 6,7 to start of string
	W B B W _ _ B B W W		//move 3,4 to 6,7
	W _ _ W B B B B W W		//move 1,2 to 3,4
	W W W W B B B B _ _		//move 7,8 to 1,2

	This took 4 moves which is correct solution for n=4

	For n=5:
		1 2 3 4 5 6 7 8 9 10
		B W B W B W B W B W
	W B B W B W B W B _ _ W 	//move 8,9 to start of string
	W B B W _ _ B W B B W W		//move 3,4 to 8,9
	W B B W W B B _ _ B W W		//move 6,7 to 3,4
	W _ _ W W B B B B B W W		//move -1,1 to 6,7		where -1 is 1 position before start
								//of string, -2 is 2 positions before and so on...
	W W W W W B B B B B _ _		//move 9,10 to -1,1

	This took 5 moves which is correct solution for n=5

	For n=6:
		1 2 3 4 5 6 7 8 9 10 11 12
		B W B W B W B W B W  B  W
	W B B W B W B W B W B _  _  W 		//move 10,11 to start of string
	W B B W B W B W _ _ B B  W  W		//move 7,8 to 10,11
	W B B _ _ W B W W B B B  W  W		//move 2,3 to 7,8
	W B B W W W B _ _ B B B  W  W		//move 6,7 to 2,3 
	W _ _ W W W B B B B B B  W  W		//move -1,1 to 2,3		
	W W W W W W B B B B B B  _  _		//move 11,12 to -1,1

	This took 6 moves which is correct solution for n=6

	For n=7:
		1 2 3 4 5 6 7 8 9 10 11 12 13 14
		B W B W B W B W B W  B  W  B  W
	W B B W B W B W B W B W  B  _  _  W 		//move 12,13 to start of string
	W B B W B W _ _ B W B W  B  B  W  W			//move 5,6 to 12,13
	W B B W B W W B B _ _ W  B  B  W  W			//move 8,9 to 5,6
	W B B W _ _ W B B B W W  B  B  W  W			//move 3,4 to 8,9
	W B B W W W W B B B _ _  B  B  W  W			//move 9,10 to 3,4
	W _ _ W W W W B B B B B  B  B  W  W			//move -1,1 to 9,10		
	W W W W W W W B B B B B  B  B  _  _			//move 13,14 to -1,1

	This took 7 moves which is correct solution for n=7

	For n = 8:

		1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16
		B W B W B W B W B W  B  W  B  W  B  W 
	W B B W B W B W B W B W  B  W  B  _  _  W

	W B B W 				_ _ B W B W B W  B  W 				B  B  W  W
	W B B W					W B B W B W B _  _  W 				B  B  W  W 	
	W B B W					W B B W _ _ B B  W  W				B  B  W  W		
	W B B W					W _ _ W B B B B  W  W				B  B  W  W		
	W B B W					W W W W B B B B  _  _				B  B  W  W	

	W _ _ W W W W W B B B B  B  B  B  B  W  W	
	W W W W W W W W B B B B  B  B  B  B  _  _

	Finally, a pattern is visible!. As can be seen, after first two moves for n = 8 , 
	the problem is reduce to W B B W _ _ (problem of size 4, i.e, B W B W B W B) B B W W.
	After solving the sub problem we get
	W B B W _ _ W W W W B B B B B B B W
	From here , two moves unified to any value of n, gets us the final solution. 


	After seeing these patterns we can establish a recursive relation depiciting
	number of moves for n>=8
	C(n) = C(n-4) + 4	//2 initial + sub-problem + 2 final

	Let us solve this recursive relation:
	For an iteration i,
	C(n) = C(n-4i) + 4i.
	Assume n is multiple of 4. We know that C(4) = 4.
	n-4i = 4 implies i = (n-4)/4
	Substituting we get,
	C(n) = C(4) + n - 4 = 4 + n - 4 = n.

	Therefore problem of n size can be solved n moves. 


Complexity:
	As proved earlier, the algorithm is linear in nature. C(n) belongs to theta(n).