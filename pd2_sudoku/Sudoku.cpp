#include<iostream>
#include"Sudoku.h"

using namespace std;

Sudoku::Sudoku()
{
	int i ;
	for(i=0;i<size;i++)
		map[i]=0;
}
Sudoku::Sudoku(int *sm)
{
	int i ;
	for(i=0;i<size;i++)
		map[i]=sm[i];
}
void GiveQuestion(){};





void ReadIn()
{
	int i ;
	for (i = 0;i<144;i++)
	{
		cin >> map[i];
	}
}





void Solve()
{
	int fail;
	int pos[150];
	int posindex = 0;
	for(int x=0;x<144;x++)
        {
		if(map[x]==0)
                {
			for(int y=1;y<=9;y++)
                        {
				if((checkcolumn(x)==0)&&(checkrow(x)==0)&&(checkgrid(x)==0))
				{
					map[x]=y;
					pos[posindex]=x;
					posindex++;
					break;
                                }
				else{fail++;}
				
					if(fail==9)
					{
						x=pos[posindex];
						map[x]=map[x]+1;
						fail=map[x];
						for(int a=map[x];a<=9;a++)
						{
						 	if((checkcolumn(x)==0)&&(checkrow(x)==0)&&(checkgrid(x)==0))
							{
								map[x]=a;
								pos[posindex]=x;
								posindex++;
								fail=0;
								break;
							}
							else
							{
								fail++;
							}
								if(fail==9)
								{
									x=pos[posindex-1];
								}
						}	
					}
                        }

                }
  
        }
	

	 
}

int getzero()
{
	int i ;
	for(i = 0 ;i < size;i++)
	{
		if(map[i]==0)
			return i;
	}
	return -1;
}

void push(int *pos,int posindex,int index)
{
	pos[posindex]=index;
	posindex++;

}

int pop(int *pos,int posindex)
{
	posindex--;
	return pos[posindex];
}


bool checkcolumn(int index)
{
	int i , j;
	i = index % 12 ;
	j = map[index];

	for (;i<144;i = i +12)
	{
		if((map[i]==j)&&(i!=index))
			return 1 ;
	}

	return 0 ;
}






bool checkrow(int index)
{

	int i , j ;
	i = index /12 *12 ;
	j = map[index];
	
	for (;i<i+12;i++)
	{
		if ((map[i]==j)&&(i!=index))
			return 1 ;
	}
	
	return 0 ;
}







bool checkgrid(int index)
{

	int i , j , k , l;
	i = index % 12 / 3 * 3 + index / 12 / 3 * 3 * 12;
	j = map[index];
	
	for(k = 0 ;k<9;k++)
	{
		l = i + k % 3 + k / 3 * 12 ;
		if ((map[l]==j)&&(l!=index))
			return 1 ; 
	}

	return 0 ;
}


















