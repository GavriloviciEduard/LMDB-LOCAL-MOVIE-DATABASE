#pragma once
#include "DataStruct.h"

class WatchList
{
	
	private:
		DynamicVector<Movie> wlist;

	public:

		WatchList() {}

		int add_wlist(const Movie& mv);
		int remove_wlist(const std::string title, const int& year);
		int find_wlist(const std::string title, const int& year);

		Movie* get_wlist() { return this->wlist.get_all_elements(); }
		int get_size_wlist() { return this->wlist.get_size(); }




};
