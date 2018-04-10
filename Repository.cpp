#include "Repository.h"

int Repository::add_repo(const Movie& mv)
{
	int indx = find_repo(mv.get_title(),mv.get_year());

	if (indx == -1)
	{
		this->list = list + mv;
		return 1;
	}

	return 0;
}

int Repository::remove_repo(const std::string& title,const int& year_r)
{
	int indx = find_repo(title,year_r);

	if (indx != -1)
	{
		this->list.remove(indx);
		return 1;
	}

	return 0;
}

int Repository::update_repo(const std::string& title, const int& year_ofr, const Movie& new_mv)
{
	int indx = find_repo(title,year_ofr);

	if (indx != -1)
	{
		this->list.update(indx, new_mv);
		return 1;
	}

	return 0;

}

int Repository::find_repo(const std::string& title,const int& year)
{
	Movie* srch = this->get_repo();

	for (int i = 0; i < this->get_size_repo(); i++)
		if (srch[i].get_title()==title && srch[i].get_year()==year)
			return i;

	return -1;
}

void Repository::increment_likes_repo(const std::string& title, const int& year)
{
	int indx = find_repo(title, year);

	if (indx != -1)
	{
		this->list.movies[indx].increment_likes();
	}
}

DynamicVector<Movie> Repository::filter_genre_repo(const std::string& genre)
{
	DynamicVector<Movie> mv_genre;

	if (genre.empty())
		for (int i = 0; i < this->get_size_repo(); i++)
			mv_genre = this->list.movies[i] + mv_genre;

	else
		for(int i=0;i<this->get_size_repo();i++)
			if(this->list.movies[i].get_genre()==genre)
				mv_genre = this->list.movies[i] + mv_genre;

	return mv_genre;

}

DynamicVector<Movie> Repository::filter_duration_repo(const int& dur)
{
	DynamicVector<Movie> mv_duration;

	for (int i = 0; i<this->get_size_repo(); i++)
		if (this->list.movies[i] < dur)
			mv_duration = this->list.movies[i] + mv_duration;

	return mv_duration;
}
