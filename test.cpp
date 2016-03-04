#include <iostream>
#include <fstream>
#include <string>
#include <time.h>
#include <stdlib.h>

int main()
{
	std::cout << "Please enter the name to create the file with" << std::endl;
		std::string file_name;
			std::cin >> file_name;
				file_name.append(".txt");
					std::ofstream ofs (file_name.c_str());
						srand(time(NULL));
							int temp;
								for(int i = 0; i < 100000001; ++i)
									{
											ofs << rand() % 1000 << std::endl;
													
														}
														}
