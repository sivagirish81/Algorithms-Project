#include <stdio.h>
#include "list.h"

int main()
{


	state_t start_state;
	set_state(&start_state, 1, 1, 1, 1, 1);
	state_t goal_state;
	set_state(&goal_state, 0, 0,0,0, 0);
	list_t l;
	init_list(&l);
	state_t temp;
	int soln = 0;
	add_at_end(&l, &start_state);
	int index;
	int found=0;

	void (*move[])(const state_t *src, state_t *dst) = {
		move_one,
		move_two,
		move_five,
		move_ten,
		move_onetwo,
		move_onefive,
		move_oneten,
		move_twofive,
		move_twoten,
		move_fiveten
	};

	int cost = 0;

	while(l.tail!=NULL)
	{
		index = l.tail->st.fn_index;
		//printf("index:%d\n",index);
		move[index](&l.tail->st , &temp);

		if(index==0) cost+=1;
		else if(index==1) cost+=2;
		else if(index==2) cost+=5;
		else if(index==3) cost+=10;
		else if(index==4) cost+=2;
		else if(index==5) cost+=5;
		else if(index==6) cost+=10;
		else if(index==7) cost+=5;
		else if(index==8) cost+=10;
		else if(index==9) cost+=10;


		if(is_safe(&temp) && ! is_repeated(&l, &temp) && cost<=17)
		{
			//printf("adding\n");
			add_at_end(&l, &temp);

			//disp_state(&temp);
			found = are_same(&temp, &goal_state);

			if(found)
			{
				disp_list(&l);					//display solution if found
				printf("\n");
				soln += 1;						//increment number of solutions
				found = 0;						//make found flag zero again.
			}

		}
		else
		{
			// list empty not checked
			//printf("in else\n");

			if(index==0) cost-=1;
			else if(index==1) cost-=2;
			else if(index==2) cost-=5;
			else if(index==3) cost-=10;
			else if(index==4) cost-=2;
			else if(index==5) cost-=5;
			else if(index==6) cost-=10;
			else if(index==7) cost-=5;
			else if(index==8) cost-=10;
			else if(index==9) cost-=10;


			while(l.tail!=NULL && ++l.tail->st.fn_index == 10 )
			{
				//printf("back tracking\n");
				remove_at_end(&l);
				if(l.tail!=NULL)
				{
					if(l.tail->st.fn_index==0) cost-=1;
					else if(l.tail->st.fn_index==1) cost-=2;
					else if(l.tail->st.fn_index==2) cost-=5;
					else if(l.tail->st.fn_index==3) cost-=10;
					else if(l.tail->st.fn_index==4) cost-=2;
					else if(l.tail->st.fn_index==5) cost-=5;
					else if(l.tail->st.fn_index==6) cost-=10;
					else if(l.tail->st.fn_index==7) cost-=5;
					else if(l.tail->st.fn_index==8) cost-=10;
					else if(l.tail->st.fn_index==9) cost-=10;		
				}
			}
			
		}

		//disp_state(&temp);
		//printf("%d %d\n",cost,l.tail->st.fn_index);

	}
	//disp_list(&l);


	printf("%d\n",soln);
}


