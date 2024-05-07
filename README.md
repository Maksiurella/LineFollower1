Robot Line Follower
PL
Do mikrokontrolera przesyłany jest sygnał z czujników odbiciowych KAmodQTR8A (w tym przypadku użyte zostało 6 czujników),
na tej podstawie jest w stanie określić uchyb położeniowy e [cm] i odpowiednią wysterować różnicą prędkości silnika lewego i prawego.

W kodzie również został zaimplementowany prosty regulator PD, który bierze pod uwagę obecny uchyb oraz poprzedni uchyb.

https://www.youtube.com/watch?v=1As9Hy4g7cI - przejazd toru próbnego robota podczas konkursu Rumble Robots 2024 w Malechowie.

Problemem robota jest prawdopodobnie konstrukcja mechaniczna - robot ma za mało czasu na poprawną reakcję, silniki powinny znajdować się po drugiej stronie konstrukcji.

