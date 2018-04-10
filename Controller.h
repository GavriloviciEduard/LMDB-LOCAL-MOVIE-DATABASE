#pragma once
#include "Repository.h"
#include "WatchList.h"

class Controller
{
	private:
		Repository repo;
		WatchList watch_list;
		

	public:
		
		Controller(const Repository& r, const WatchList& w) : repo{ r }, watch_list { w } {}

		int add_controller(const std::string& title, const std::string& genre, const int& year_release, const int& nr_likes, const std::string& trailer,const int& duration);
		int remove_controller(const std::string& title, const int& year_release);
		int update_controller(const std::string& title, const int& year_release,const std::string& new_title,const std::string& new_genre,const int& new_year_release,const int& new_nr_likes,const std::string& new_trailer,const int& duration);
		Movie* get_all() {return this->repo.get_repo();}
		int get_size_all() { return this->repo.get_size_repo(); }

		int add_controller_wlst(const Movie& mv);
		int remove_controller_wlst(const std::string& title, const int& year_release);
		Movie* get_wlst() { return this->watch_list.get_wlist(); }
		int get_size_wlst() { return this->watch_list.get_size_wlist(); }
		void increment_likes_cn(const std::string& title, const int& year_release);

		DynamicVector<Movie> filter_genre(const std::string& genre);
		DynamicVector<Movie> filter_duration_cn(const int& dr);
};