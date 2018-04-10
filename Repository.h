#pragma once
#include "DataStruct.h"

class Repository
{
	
	private:
		DynamicVector<Movie> list;


	public:
		Repository() {}

		int add_repo(const Movie& mv);
		int remove_repo(const std::string& title,const int& year_ofr);
		int update_repo(const std::string& title,const int& year_ofr, const Movie& new_mv);
		int find_repo(const std::string& title, const int& year_ofr);
		Movie* get_repo() { return this->list.get_all_elements(); }
		int get_size_repo() { return this->list.get_size(); }

		void increment_likes_repo(const std::string& title, const int& year_ofr);
		DynamicVector<Movie> filter_genre_repo(const std::string& genre);
		DynamicVector<Movie> filter_duration_repo(const int& dur);



};