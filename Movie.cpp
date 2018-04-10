#include "Movie.h"
#include <Windows.h>
#include <shellapi.h>

Movie::Movie() :title{ "" }, genre{ "" }, year_release{ 0 }, nr_likes{ 0 }, trailer{ "" }, duration{0} {}

Movie::Movie(const std::string& title, const std::string& genre, const int& year_release, const int& nr_likes, const std::string& trailer,const int& duration)
{
	this->title = title;
	this->genre = genre;
	this->year_release = year_release;
	this->nr_likes = nr_likes;
	this->trailer = trailer;
	this->duration = duration;
}



bool Movie::operator==(const Movie& mv)
{
	return this->title == mv.title && this->genre == mv.genre && this->year_release == mv.year_release && this->trailer == mv.trailer && mv.nr_likes == this->nr_likes;
}



bool Movie::operator<(const int& nr)
{
	return this->duration < nr;
}


void Movie::to_string()
{
	std::cout << "Title: " << this->title << " ----- " << "Genre: " << this->genre << " ----- " << "Year of release: " << this->year_release << " ----- "
		<< "Number of likes: " << this->nr_likes << " ----- " << "Duration: " << this->duration << " minutes";
}


void Movie::play()
{
	ShellExecuteA(NULL, NULL, "chrome.exe", this->get_trailer().c_str(), NULL, SW_SHOWMAXIMIZED);
}


