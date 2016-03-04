#ifndef MAZE_HPP
#define MAZE_HPP

#include <algorithm>
#include <fstream>
#include <string>
#include <vector>

class Maze {
public:
    explicit Maze(int n = 0, int m = 0) : n_(n), m_(m), board_(n * m) { }
	
	    /** Returns number of rows.
		     */
			     int nrow() const { return n_; }
				 
				     /** Returns number of columns.
					      */
						      int ncol() const { return m_; }
							  
							      /** Returns true if position (x,y) has been marked as visited before.
								       */
									       bool is_visited(int x, int y) const {
										           if ((x > -1) && (x < n_) && (y > -1) && (y < m_)) return (board_[x * m_ + y] == 2);
												           return true;
														       } // is_visited
															   
															       /** Returns true if position (x,y) is open and can be visited.
																        */
																		    bool is_open(int x, int y) const {
																			        if ((x > -1) && (x < n_) && (y > -1) && (y < m_)) return (board_[x * m_ + y] != 1);
																					        return false;
																							    } // is_open
																								
																								    /** Marks position (x,y) as visited.
																									     */
																										     void mark(int x, int y) {
																											         if ((x > -1) && (x < n_) && (y > -1) && (y < m_)) {
																													             if (board_[x * m_ + y] == 0) board_[x * m_ + y] = 2;
																																         }
																																		     } // mark
																																			 
																																			     /** Marks position (x,y) as not visited.
																																				      */
																																					      void unmark(int x, int y) {
																																						          if ((x > -1) && (x < n_) && (y > -1) && (y < m_)) {
																																								              if (board_[x * m_ + y] == 2) board_[x * m_ + y] = 0;
																																											          }
																																													      } // unmark
																																														  
																																														      /** Reads maze map from a file "name".
																																															       *  Returns true on success.
																																																        */
																																																		    bool read(const std::string& name) {
																																																			        std::ifstream f(name.c_str());
																																																					        if (!f) return false;
																																																							
																																																							        std::fill(board_.begin(), board_.end(), 0);
																																																									        std::string buf;
																																																											
																																																											        for (int i = 0; i < n_; ++i) {
																																																													            buf = "";
																																																																            std::getline(f, buf);
																																																																			            if (buf.size() != m_) return false;
																																																																						            for (int j = 0; j < m_; ++j) {
																																																																									                if (buf[j] == '1') board_[i * m_ + j] = 1;
																																																																													            }
																																																																																        } // for i
																																																																																		
																																																																																		        return true;
																																																																																				    } // read
																																																																																					
																																																																																					private:
																																																																																					    int n_;
																																																																																						    int m_;
																																																																																							    std::vector<short int> board_;
																																																																																								
																																																																																								}; // class Maze
																																																																																								
																																																																																								#endif // MAZE_HPP}}}}}}}}}}}}}
