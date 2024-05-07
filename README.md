Robot Line Follower
PL
Do mikrokontrolera przesyłany jest sygnał z czujników odbiciowych KAmodQTR8A (w tym przypadku użyte zostało 6 czujników),
na tej podstawie jest w stanie określić uchyb położeniowy e [cm] i odpowiednią wysterować różnicą prędkości silnika lewego i prawego.

W kodzie również został zaimplementowany prosty regulator PD, który bierze pod uwagę obecny uchyb oraz poprzedni uchyb.


