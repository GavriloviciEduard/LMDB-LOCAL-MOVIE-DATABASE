#include "Test.h"

Movie M1{ "The Godfather","Crime",1972,0,"https://www.youtube.com/watch?v=ktEkl-MUHJI&ab_channel=UniversalMarkets",120 };
Movie M2{ "The Shawshank Redemption","Crime",1994,0,"https://www.youtube.com/watch?v=NmzuHjWmXOc&ab_channel=MovieclipsTrailerVault",120 };
Movie M3{ "The Exorcist","Horror",1973,0,"https://www.youtube.com/watch?v=iAlv-M6vpjY&ab_channel=SupernaturalEarth",156 };
Movie M4{ "A Clockwork Orange","Crime",1971,0,"https://www.youtube.com/watch?v=xHFPi_3kc1U&ab_channel=thecineastHQ",136 };
Movie M5{ "Gladiator","Action",2000,0,"https://www.youtube.com/watch?v=owK1qxDselE&ab_channel=nathansmoviereviews",122 };
Movie M6{ "The Silence of the Lambs","Thriller",1991,0,"https://www.youtube.com/watch?v=RuX2MQeb8UM&ab_channel=Mark%27sMovieTrailers",133 };
Movie M7{ "Forrest Gump","Drama",1994,0,"https://www.youtube.com/watch?v=uPIEn0M8su0&ab_channel=HolasPhilosophy",121 };
Movie M8{ "Schindler's List","History",1993,0,"https://www.youtube.com/watch?v=JdRGC-w9syA",234 };
Movie M9{ "The Dark Knight","Action",2008,0,"https://www.youtube.com/watch?v=EXeTwQWrcwY&ab_channel=MovieclipsTrailerVault",234 };
Movie M10{ "Fight Club","Drama",1999,0,"https://www.youtube.com/watch?v=_XgQA9Ab0Gw&ab_channel=JoBloMovieTrailers",90 };


void Test::test_Data()
{
	DynamicVector<int> V(2);
	assert(V.capacity==2);

	V = V + 2;
	V = V + 3;
	V = V + 4;
	V = V + 5;
	V = 6 + V;
	assert(V.get_size() == 5);

	V.remove(0);
	V.remove(0);
	assert(V.get_size() == 3);
	assert(V.movies[0] == 4);

	V.update(0, 99);
	assert(V.movies[0] == 99);
	

	DynamicVector<Movie> W;

	W = W + M1;
	W = W + M2;
	W = M3 + W;
	W = M4 + W;
	assert(W.get_size() == 4);
	
	W.remove(0);
	assert(W.get_size() == 3);
	assert(W.movies[0] == M2);

	W.update(0, M5);
	assert(W.movies[0] == M5);

}

void Test::test_Movie()
{
	assert(M1.get_genre() == "Crime");
	assert(M1.get_likes() == 0 );
	assert(M1.get_title() == "The Godfather");
	assert(M1.get_trailer() =="https://www.youtube.com/watch?v=ktEkl-MUHJI&ab_channel=UniversalMarkets" );
	assert(M1.get_year() == 1972 );

	M1.increment_likes();
	M1.increment_likes();
	M1.increment_likes();
	assert(M1.get_likes() == 3);
	assert(M1 == M1);
	

	assert(M2.get_genre() == "Crime");
	assert(M2.get_likes() == 0);
	assert(M2.get_title() == "The Shawshank Redemption");
	assert(M2.get_trailer() == "https://www.youtube.com/watch?v=NmzuHjWmXOc&ab_channel=MovieclipsTrailerVault");
	assert(M2.get_year() == 1994);

	M2.increment_likes();
	M2.increment_likes();
	M2.increment_likes();
	assert(M2.get_likes() == 3);
	assert(M2 == M2);
	


	assert(M3.get_genre() == "Horror");
	assert(M3.get_likes() == 0);
	assert(M3.get_title() == "The Exorcist");
	assert(M3.get_trailer() == "https://www.youtube.com/watch?v=iAlv-M6vpjY&ab_channel=SupernaturalEarth");
	assert(M3.get_year() == 1973);

	M3.increment_likes();
	M3.increment_likes();
	M3.increment_likes();
	assert(M3.get_likes() == 3);
	assert(M3 == M3);

	assert(M3 < 400);
	assert(M5 < 400);
	assert(M6 < 400);
	assert(M7 < 400);


}

void Test::test_Repo()
{
	Repository R{};

	R.add_repo(M4);
	R.add_repo(M5);
	R.add_repo(M6);
	R.add_repo(M7);
	assert(R.get_size_repo() == 4);

	R.remove_repo("asdasd", 321312);
	assert(R.get_size_repo() == 4);

	R.remove_repo("A Clockwork Orange", 1971);
	assert(R.get_size_repo() == 3);

	assert(R.find_repo("A Clockwork Orange", 1971) == -1);
	assert(R.find_repo("Gladiator", 2000) == 0);

	


	R.update_repo("Gladiator", 2000,M1);
	assert(R.update_repo("43434", 12312,M10) == 0);
	assert(R.find_repo("The Godfather", 1972) == 0);

	DynamicVector<Movie> V;

	V = R.filter_genre_repo("");


	
	assert(V.movies[0] == M1);
	assert(V.movies[1] == M6);
	assert(V.movies[2] == M7);

	V = R.filter_genre_repo("Crime");
	assert(V.movies[0] == M1);
}


void Test::test_Watch()
{
	WatchList W{};

	assert(W.get_size_wlist() == 0);

	W.add_wlist(M1);
	W.add_wlist(M2);
	W.add_wlist(M3);
	W.add_wlist(M4);

	assert(W.get_size_wlist() == 4);
	assert(W.find_wlist("423423", 1943) == -1);
	assert(W.find_wlist("423432323", 111943) == -1);

	assert(W.find_wlist("The Godfather", 1972) == 0);
	assert(W.find_wlist("The Shawshank Redemption", 1994) == 1);
	assert(W.find_wlist("The Exorcist", 1973) == 2);
	assert(W.find_wlist("A Clockwork Orange", 1971) == 3);

	W.remove_wlist("dsdsd", 32443);
	W.remove_wlist("dsdsdewe", 32122443);
	assert(W.get_size_wlist() == 4);

	W.remove_wlist("The Godfather", 1972);
	W.remove_wlist("The Shawshank Redemption", 1994);
	assert(W.get_size_wlist() == 2);
	

	assert(W.find_wlist("The Godfather", 1972) == -1);
	assert(W.find_wlist("The Shawshank Redemption", 1994) == -1);

}

void Test::test_Contr()
{
	Repository R{};
	R.add_repo(M4);
	R.add_repo(M5);
	R.add_repo(M6);
	R.add_repo(M7);

	WatchList W{};
	W.add_wlist(M4);
	W.add_wlist(M5);
	W.add_wlist(M6);
	W.add_wlist(M7);

	Controller C{R,W};
	assert(C.get_size_all() == 4);
	assert(C.get_size_wlst() == 4);

	C.add_controller("A", "AA", 1900, 11, "AAA",133);
	C.add_controller("B", "BB", 1900, 11, "BBB",122);
	C.add_controller("C", "CC", 1900, 11, "CCC",111);
	C.add_controller("A", "AA", 1900, 11, "AAA",99);
	assert(C.get_size_all() == 7);

	C.add_controller_wlst(M1);
	C.add_controller_wlst(M2);
	C.add_controller_wlst(M3);
	C.add_controller_wlst(M3);
	assert(C.get_size_wlst() == 7);

	C.remove_controller("A", 1900);
	C.remove_controller("B", 1900);
	C.remove_controller("C", 1900);
	assert(C.get_size_all() == 4);

	C.remove_controller_wlst(M1.get_title(), M1.get_year());
	C.remove_controller_wlst(M2.get_title(), M2.get_year());
	C.remove_controller_wlst(M3.get_title(), M3.get_year());
	assert(C.get_size_wlst() == 4);

	C.increment_likes_cn(M7.get_title(), M7.get_year());
	assert(M7.get_likes() == 0);


	DynamicVector<Movie> V;

	V = C.filter_genre("");
	V = C.filter_duration_cn(900);


	assert(V.movies[0] == M4);
	assert(V.movies[1] == M5);
	assert(V.movies[2] == M6);
	



	

	C.update_controller(M4.get_title(), M4.get_year(), M10.get_title(), M10.get_genre(), M10.get_year(), M10.get_likes(), M10.get_trailer(),M1.get_duration());
	C.update_controller(M5.get_title(), M5.get_year(), M9.get_title(), M9.get_genre(), M9.get_year(), M9.get_likes(), M9.get_trailer(),M9.get_duration());
	C.update_controller(M6.get_title(), M6.get_year(), M8.get_title(), M8.get_genre(), M8.get_year(), M8.get_likes(), M8.get_trailer(),M8.get_duration());
	assert(C.get_size_all() == 4);

	
	V=C.filter_genre("");


	assert(V.movies[0] == M10);
	assert(V.movies[1] == M9);
	assert(V.movies[2] == M8);

	Movie* X = C.get_wlst();
	 X = C.get_all();
	
}

void Test::start()
{
	test_Data();
	test_Contr();
	test_Movie();
	test_Repo();
	test_Watch();
}