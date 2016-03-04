#ifndef A4_HPP
#define A4_HPP

#include "Maze.hpp"
// implement your function distance
int length = 0;
int distance(Maze& maze, int sx, int sy, int fx, int fy){
	maze.mark(sx,sy);	
	if(sx!=fx || sy!=fy){
		
		if((sx<fx && sy<fy)){
			if(maze.is_open(sx+1,sy)==true){
				if(maze.is_visited(sx+1,sy)==false){
					maze.mark(sx+1,sy);
					return length = 1+distance(maze,sx+1,sy,fx,fy);
				}
			}	
			if(maze.is_open(sx,sy+1)==true){
				if(maze.is_visited(sx,sy+1)==false){
					maze.mark(sx,sy+1);
					return length = 1+distance(maze,sx,sy+1,fx,fy);
				}
			}
			if(maze.is_open(sx-1,sy)==true){
				if(maze.is_visited(sx-1,sy)==false){
					maze.mark(sx-1,sy);
					return length = 1+distance(maze,sx-1,sy,fx,fy);
				}	
			}
			if(maze.is_open(sx,sy-1)==true){
				if(maze.is_visited(sx,sy-1)==false){
					maze.mark(sx,sy-1);
					return length = 1+distance(maze,sx,sy-1,fx,fy);
				}
			}
		}
		else if((sx>fx && sy>fy)){
			if(maze.is_open(sx-1,sy)==true){
				if(maze.is_visited(sx-1,sy)==false){
					maze.mark(sx-1,sy);
					return length = 1+distance(maze,sx-1,sy,fx,fy);
				}	
			}
			if(maze.is_open(sx,sy-1)==true){
				if(maze.is_visited(sx,sy-1)==false){
					maze.mark(sx,sy-1);
					return length = 1+distance(maze,sx,sy-1,fx,fy);
				}
			}
			if(maze.is_open(sx+1,sy)==true){
				if(maze.is_visited(sx+1,sy)==false){
					maze.mark(sx+1,sy);
					return length = 1+distance(maze,sx+1,sy,fx,fy);
				}
			}	
			if(maze.is_open(sx,sy+1)==true){
				if(maze.is_visited(sx,sy+1)==false){
					maze.mark(sx,sy+1);
					return length = 1+distance(maze,sx,sy+1,fx,fy);
				}
			}
		}
	
		else{
			if((sx==fx && sy>fy) || (!maze.is_open(sx,sy+1) && !maze.is_open(sx-1,sy) && !maze.is_open(sx+1,sy))){	
				if(maze.is_open(sx,sy-1)==true){
					if(maze.is_visited(sx,sy-1)==false){
						maze.mark(sx,sy-1);
						return length = 1+distance(maze,sx,sy-1,fx,fy);
					}
				}
			}
			if((sx==fx && sy<fy) || (!maze.is_open(sx,sy-1) && !maze.is_open(sx-1,sy) && !maze.is_open(sx+1,sy) )){ 
				if(maze.is_open(sx,sy+1)==true){
					if(maze.is_visited(sx,sy+1)==false){
						maze.mark(sx,sy+1);
						return length = 1+distance(maze,sx,sy+1,fx,fy);
					}	
				}
			}
			if((sx>fx&& sy==fy) || (!maze.is_open(sx,sy-1) && !maze.is_open(sx+1,sy) && !maze.is_open(sx,sy+1))){
				if(maze.is_open(sx-1,sy)==true){
					if(maze.is_visited(sx-1,sy)==false){
						maze.mark(sx-1,sy);
						return length = 1+distance(maze,sx-1,sy,fx,fy);
					}	
				}
			}
			if((sx<fx && sy==fy) || (!maze.is_open(sx,sy-1) && !maze.is_open(sx-1,sy) && !maze.is_open(sx,sy+1))){
				if(maze.is_open(sx+1,sy)==true){
					if(maze.is_visited(sx+1,sy)==false){
						maze.mark(sx+1,sy);
						return length = 1+distance(maze,sx+1,sy,fx,fy);
					}
				}	
			}

			if(maze.is_open(sx,sy+1)==true){
				if(maze.is_visited(sx,sy+1)==false){
					maze.mark(sx,sy+1);
					return length = 1+distance(maze,sx,sy+1,fx,fy);
				}
			}

			if(maze.is_open(sx,sy-1)==true){
				if(maze.is_visited(sx,sy-1)==false){
					maze.mark(sx,sy-1);
					return length = 1+distance(maze,sx,sy-1,fx,fy);
				}	
			}
			if(maze.is_open(sx+1,sy)==true){
				if(maze.is_visited(sx+1,sy)==false){
					maze.mark(sx+1,sy);
					return length = 1+distance(maze,sx+1,sy,fx,fy);
				}	
			}
			if(maze.is_open(sx-1,sy)==true){
				if(maze.is_visited(sx-1,sy)==false){
					maze.mark(sx-1,sy);
					return length = 1+distance(maze,sx-1,sy,fx,fy);
				}
			}	
			
		}

		if(maze.is_visited(sx-1,sy)==true && !maze.is_open(sx+1,sy) && !maze.is_open(sx,sy+1) && !maze.is_open(sx,sy-1)){
			maze.unmark(sx-1,sy);
			return length=distance(maze,sx-1,sy,fx,fy)-1;
		}

		if(maze.is_visited(sx+1,sy)==true && !maze.is_open(sx-1,sy) && !maze.is_open(sx,sy+1) && !maze.is_open(sx,sy-1)){
			maze.unmark(sx+1,sy);
			return length=distance(maze,sx+1,sy,fx,fy)-1;
		}

		if(maze.is_visited(sx,sy-1)==true && !maze.is_open(sx+1,sy) && !maze.is_open(sx,sy+1) && !maze.is_open(sx-1,sy)){
			maze.unmark(sx,sy-1);
			return length=distance(maze,sx,sy-1,fx,fy)-1;
		}

		if(maze.is_visited(sx,sy+1)==true && !maze.is_open(sx+1,sy) && !maze.is_open(sx-1,sy) && !maze.is_open(sx,sy-1)){
			maze.unmark(sx,sy+1);
			return length=distance(maze,sx,sy+1,fx,fy)-1;
		}


	}
	return length;
} //distance

#endif // A4_HPP
