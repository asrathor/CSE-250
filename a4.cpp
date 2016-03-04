#include "Maze.hpp"
#include "a4.hpp"

#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[]) {
    if (argc != 8) {
	        std::cout << "usage: " << argv[0] << " n m sx sy fx fy file" << std::endl;
			        return -1;
					    }
						
						    // get input parameters
							    int n = std::atoi(argv[1]);
								    int m = std::atoi(argv[2]);
									
									    int sx = std::atoi(argv[3]);
										    int sy = std::atoi(argv[4]);
											    int fx = std::atoi(argv[5]);
												    int fy = std::atoi(argv[6]);
													
													    std::string name = argv[7];
														
														    if ((n < 1) && (m < 1)) return -1;
															    if ((sx < 0) && (sy < 0)) return -1;
																    if ((fx < 0) && (fy < 0)) return -1;
																	
																	    // ream the maze
																		    Maze M(n, m);
																			
																			    if (!M.read(name)) {
																				        std::cout << "incorrect map" << std::endl;
																						        return -1;
																								    }
																									
																									    // HERE YOUR FUNCTION IS INVOKED
																										    int d = distance(M, sx, sy, fx, fy);
																											
																											    // print result
																												    std::cout << d << std::endl;
																													
																													    return 0;
																														} // main}}}
