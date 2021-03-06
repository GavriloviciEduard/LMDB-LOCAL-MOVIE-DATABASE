#include <Windows.h>
#include "UI.h"
#include "Test.h"

int main()
{
	system("color 02");
	Repository r{};
	WatchList w{};

	Test t{};

	t.start();



	Movie m1{ "The Godfather","Crime",1972,0,"https://www.youtube.com/watch?v=ktEkl-MUHJI&ab_channel=UniversalMarkets",120 };
	Movie m2{ "The Shawshank Redemption","Crime",1994,0,"https://www.youtube.com/watch?v=NmzuHjWmXOc&ab_channel=MovieclipsTrailerVault",120 };
	Movie m3{ "The Exorcist","Horror",1973,0,"https://www.youtube.com/watch?v=iAlv-M6vpjY&ab_channel=SupernaturalEarth",156 };
	Movie m4{ "A Clockwork Orange","Crime",1971,0,"https://www.youtube.com/watch?v=xHFPi_3kc1U&ab_channel=thecineastHQ",136 };
	Movie m5{ "Gladiator","Action",2000,0,"https://www.youtube.com/watch?v=owK1qxDselE&ab_channel=nathansmoviereviews",122 };
	Movie m6{ "The Silence of the Lambs","Thriller",1991,0,"https://www.youtube.com/watch?v=RuX2MQeb8UM&ab_channel=Mark%27sMovieTrailers",133 };
	Movie m7{ "Forrest Gump","Drama",1994,0,"https://www.youtube.com/watch?v=uPIEn0M8su0&ab_channel=HolasPhilosophy",121 };
	Movie m8{ "Schindler's List","History",1993,0,"https://www.youtube.com/watch?v=JdRGC-w9syA",234 };
	Movie m9{ "The Dark Knight","Action",2008,0,"https://www.youtube.com/watch?v=EXeTwQWrcwY&ab_channel=MovieclipsTrailerVault",234 };
	Movie m10{ "Fight Club","Drama",1999,0,"https://www.youtube.com/watch?v=_XgQA9Ab0Gw&ab_channel=JoBloMovieTrailers",90 };

	r.add_repo(m1);
	r.add_repo(m2);
	r.add_repo(m3);
	r.add_repo(m4);
	r.add_repo(m5);
	r.add_repo(m6);
	r.add_repo(m7);
	r.add_repo(m8);
	r.add_repo(m9);
	r.add_repo(m10);


	Controller cr{ r,w };
	UI ui{ cr };

	ui.start();


	return 0;
}

