#pragma once
#include "Controller.h"

class UI
{
	private:
		
		Controller contr;

	public:
		
		UI(const Controller& c):contr{c} {}

		void print_menu_admin();
		void print_menu();
		void print_menu_user();
		std::string read_string();
		int read_nr();
		void start();
		void add_ui();
		void remove_ui();
		void update_ui();
		void print_movies();
		void filter_duration_ui();

		void peruse_database();
		void remove_ui_wlst();
		void print_watchlist();
		std::string read_pass();





};
