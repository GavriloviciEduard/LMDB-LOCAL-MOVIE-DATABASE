#include "WatchList.h"

int WatchList::find_wlist(const std::string title, const int& year)
{
	Movie* srch = this->get_wlist();

	for (int i = 0; i < this->get_size_wlist(); i++)
		if (srch[i].get_title() == title && srch[i].get_year() == year)
			return i;

	return -1;
}

int WatchList::add_wlist(const Movie& mv)
{
	int indx = find_wlist(mv.get_title(), mv.get_year());

	if (indx == -1)
	{
		this->wlist = wlist + mv;
		return 1;
	}

	return 0;
}

int WatchList::remove_wlist(const std::string title, const int& year)
{
	int indx = find_wlist(title, year);

	if (indx != -1)
	{
		this->wlist.remove(indx);
		return 1;
	}

	return 0;
}

