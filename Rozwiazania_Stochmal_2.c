#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
	2.29	Dysponujemy zestawem dowolnej ilo�ci banknotow o nomina�ach: 1, 2, 5, 10, 20, 50 i 100 z�.
			Poda�, jak wyp�aci� n z� bior�c najmniejsz� ilo�� banknot�w.
			
			Pewnie mo�na to zrobi� lepiej, ja to zrobi�am �opatologicznie.
			
*/
void zad_2_29() {
	int n, pomocnicza, suma=0;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	pomocnicza = n;
	while(suma != n){
		if(pomocnicza >= 100){
			suma+=100;
			pomocnicza-=100;
			printf("100, ");
			continue;
		} 
		if(pomocnicza >= 50){
			suma+=50;
			pomocnicza-=50;
			printf("50, ");
			continue;
		}
		if(pomocnicza >= 20){
			suma+=20;
			pomocnicza-=20;
			printf("20, ");
			continue;
		}
		if(pomocnicza >= 10){
			suma+=10;
			pomocnicza-=10;
			printf("10, ");
			continue;
		}
		if(pomocnicza >= 5){
			suma+=5;
			pomocnicza-=5;
			printf("5, ");
			continue;
		}
		if(pomocnicza >= 2){
			suma+=2;
			pomocnicza-=2;
			printf("2, ");
			continue;
		} else {
			suma+=1;
			pomocnicza-=1;
			printf("1, ");
			continue;
		}
	}	
}

/*
	2.28	Wyznacz pierwiastek kwadratowy z zadanej liczby A, stosuj�c algorytm Herona.
			W pierwszym kroku przybli�amy warto�� sqrt(A) liczb� a1. Je�li a1< sqrtA), to A/a1 > sqrt(A),
			i na odwr�t: je�li a1 > sqrt(A), to A/a1 < sqrt(A). Zatem dok�adna warto�� pierwiastka le�y mi�dzy warto�ciami
			a1 i A/a1, wi�c kolejne przybli�enie piarwiastka mo�e by� wzi�te jako �rednia arytmetyczna obu kra�c�w przedzia�u:
			a2=(a1+A/a1)/2. Kolejne przybli�enia mo�emy zapisa� jako an+1=(an+A/an)/2. W obliczeniach przyjmij dok�adno�� e np 10^(-6)
			rozumian� jako r�nic� mi�dzy liczbami an i A/an.
			
*/
void zad_2_28() {
	double a, x, alternatywa, blad, epsilon; 
	printf("Podaj liczbe rzeczywista, z ktorej chcesz obliczyc pierwiastek kwadratowy: \n");
	scanf("%lf",&a);
	/*epsilon to bardzo mala liczba, im mniejsza tym dokladniejszy wynik uzyskujemy
	zapis 1e-15 jest rownoznaczny z 
	*/
	epsilon = 1e-15;
	x=1.0;
	do {
		x=(x+(a/x))/2.0;
	} while (fabs((x-(a/x))) >= x*epsilon);
	
	printf("Pierwiastek kwadratowy z liczby %lf wynosi %lf.\n",a,x);
	alternatywa=sqrt(a);
	blad=(fabs(alternatywa-x))/alternatywa;
	printf("Blad wzgledny wynosi %lf.\n",blad);	
}


int sumaDzielnikowWlasciwych(int liczba){
	int i, suma = 0;
	if(liczba == 1){
		return 1;
	}
	for(i=1; i<liczba; i++){
		if(liczba % i ==0){
			suma+=i;
		}
	}
	return suma;
}


/*
	2.27	Dana jest liczba naturana n. Znale�� wszystkie liczby naturalne k mniejsze od n,
			dla kt�rych suma podzielnik�w k jest r�wna danej liczbie k.
			
			Liczba doskona�a � liczba naturalna, kt�ra jest sum� wszystkich swych dzielnik�w w�a�ciwych 
			(to znaczy od niej mniejszych). Najmniejsz� liczb� doskona�� jest 6, poniewa� 6 = 3 + 2 + 1. 
			Nast�pn� jest 28 (28 = 14 + 7 + 4 + 2 + 1), a kolejne to 496, 8128, 33550336, 8589869056 i 137438691328.
			
*/
void zad_2_27() {
	int n, k, suma;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Liczby mniejsze od n=%d, kt�rych suma podzielnik�w jest r�wna samej tej liczbie to:\n",n);
	for(k=1; k<n; k++){
		suma = sumaDzielnikowWlasciwych(k);
		if(suma == k){
			printf("Liczba: %d.\n", k);
		}
	}	
}


//Je�li liczba jest pierwsza to zwracamy 1, w przeciwnym wypadku 0
int jestPierwsza(int liczba){
	int i;
	for(i=2;i<liczba;i++){
		if(liczba % i == 0){
			return 0;
		}
	}
	return 1;
}

/*
	2.26	Dane s� 2 liczby naturalne a i b (b > a). Znale�� wszystkie liczby pierwsze mi�dzy a i b.
			
*/
void zad_2_26() {
	int i, a, b;
	printf("Podaj liczbe naturalna a:\n");
	scanf("%d", &a);
	printf("Podaj liczbe naturalna b > a:\n");
	scanf("%d", &b);
	printf("Mi�dzy liczbami a=%d i b=%d wyst�puj� nast�puj�ce liczby pierwsze:\n",a,b);
	for(i=a+1; i<b; i++){
		if(jestPierwsza(i) == 1){
			printf("%d, ",i);
		}
	}	
}

/*
	2.25	Twierdzenie lagrange'a m�wi, �e ka�d� naturaln� liczb� n mo�na zapisa� za pomoc� sumy kwadrat�w
			4 liczb naturalnych (wraz z zerem): n = x^2 + y^2 + z^2 + t^2. Znale�� takie liczby dla zadanego n. 
			
*/
void zad_2_25() {
	int n, x=0, y=0, z=0, t=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(x=0; x<=n; x++){
		for(y=0; y<=n; y++){
			for(z=0; z<=n; z++){
				for(t=0; t<=n; t++){
					if((x*x)+(y*y)+(z*z)+(t*t) == n){
						printf("n = %d = %d^2 + %d^2 + %d^2 + %d^2..\n", n, x, y, z, t);
						czyZnaleziono = 't';
						break;
					}
				}
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}

/*
	2.24	Dana jest liczba naturalna n. Czy mo�na j� przedstawi� za pomoc� sumy kwadrat�w 3 liczb naturalnych:
			n = x^2 + y^2 + z^2, Je�li mo�na to:
	a)		znale�� takie liczby x, y, z
	b)		znale�� wszystkie takie tr�jki
	
	Uwaga: Program od razu znajduje wszystkie tr�jki liczb i na bie��co wypisuje je na ekran
			
*/
void zad_2_24_ab() {
	int i, j, k, n, x=0, y=0, z=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		x=i;
		for(j=0; j<=n; j++){
			y=j;
			for(k=0; k<=n; k++){
				if((x*x)+(y*y)+(z*z) == n){
					printf("n = %d = %d^2 + %d^2 + %d^2.\n", n, x, y, z);
					czyZnaleziono = 't';
					break;
				}
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}

/*
	2.23	Dan� liczb� naturaln� n przedstawi� w postaci sumy sze�cian�w 2 liczb naturalnych x i y (x, y): n = x^3+y^3
			
*/
void zad_2_23() {
	int i, j, n, x=0, y=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		x=i;
		for(j=0; j<=n; j++){
			y=j;
			if((x*x*x)+(y*y*y) == n){
				printf("n = %d = %d^3 + %d^3.\n", n, x, y);
				czyZnaleziono = 't';
				break;
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}

/*
	2.22	Dana jest liczba naturalna n. Czy mozna j� zapisa� za pomoc� sumy kwadrat�w 2 liczb naturalnych: n = x^2 + y^2?
			Je�li mo�na to:
	a)		znale�� tak� par� liczb x i y
	b)		znale�� wszystkie pary takich liczb
	
	Uwaga: Program od razu znajduje wszystkie pary liczb i na bie��co wypisuje je na ekran
*/
void zad_2_22_ab() {
	int i, j, n, x=0, y=0;
	char czyZnaleziono = 'n';
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	for(i=0; i<=n; i++){
		x=i;
		for(j=0; j<=n; j++){
			y=j;
			if((x*x)+(y*y) == n){
				printf("Dla liczby n=%d znaleziono x=%d i y=%d.\n", n, x, y);
				czyZnaleziono = 't';
				break;
			}
			
		}
	}
	if(czyZnaleziono == 'n'){
		printf("Nie znaleziono takiej liczby.\n");
	}	
}


/*
	2.21	Oblicz przybli�on� warto�� niesko�czonych szereg�w. Obliczenia przerwij w momencie,
			gdy warto�� bezwzgl�dna kolejnego wyrazu szeregu b�dzie mniejsza od zadanej dok�adno�ci e=10^(-7)
	d)		suma od i=1 do niesko�czono�ci (-2)^i/i! - w tym zadaniu nalezy zauwa�y�,
			ze kazdy kolejny wyraz to poprzedni wyraz pomno�ony przez (-2/i) czyli np. i1=(-2.0)/i to i2=i1*((-2)/i)
*/
void zad_2_21_d() {
	int i = 1;
	double wyraz = 0, suma = 0, e=(1.0/pow(10,7));
	wyraz=pow(-2, i)/i;
	while(fabs(wyraz) > e){
		i++;
		wyraz = wyraz*((-2.0)/i);
		suma += wyraz;
		printf("suma %lf, wyraz %lf\n", suma, wyraz);

	}
	printf("Przybli�ona suma to: %lf.\n", suma);
}

/*
	2.21	Oblicz przybli�on� warto�� niesko�czonych szereg�w. Obliczenia przerwij w momencie,
			gdy warto�� bezwzgl�dna kolejnego wyrazu szeregu b�dzie mniejsza od zadanej dok�adno�ci e=10^(-7)
	c)		suma od i=1 do niesko�czono�ci 1/i(i+1)
*/
void zad_2_21_c() {
	int i = 1;
	double mianownik, suma = 0, wyraz = 1, e=(1.0/pow(10,7));
	while(fabs(wyraz) > e){
		mianownik = i*(i+1);
		wyraz = 1.0/mianownik;
		suma += wyraz;
		i++;
	}
	printf("Przybli�ona suma to: %lf.\n", suma);
}

//Program pomocniczy licz�cy silni� z liczby
int silnia(int n) {
	int i, silnia = 1;
	for(i = 1; i <= n; i++){
		silnia*=i;
	}
	return silnia;	
}

/*
	2.21	Oblicz przybli�on� warto�� niesko�czonych szereg�w. Obliczenia przerwij w momencie,
			gdy warto�� bezwzgl�dna kolejnego wyrazu szeregu b�dzie mniejsza od zadanej dok�adno�ci e=10^(-7)
	b)		suma od i=1 do niesko�czono�ci (-1)^i/i!
*/
void zad_2_21_b() {
	int i = 1;
	double licznik, mianownik, suma = 0, wyraz = 1, e=(1.0/pow(10,7));
	while(fabs(wyraz) > e){
		licznik = pow((-1.0), i);
		mianownik = silnia(i);
		wyraz = licznik/mianownik;
		suma += wyraz;
		i++;
	}
	printf("Przybli�ona suma to: %lf.\n", suma);
}

/*
	2.21	Oblicz przybli�on� warto�� niesko�czonych szereg�w. Obliczenia przerwij w momencie,
			gdy warto�� bezwzgl�dna kolejnego wyrazu szeregu b�dzie mniejsza od zadanej dok�adno�ci e=10^(-7)
	a)		suma od i=1 do niesko�czono�ci 1/i^2
*/
void zad_2_21_a() {
	int i = 1;
	double suma = 0, wyraz = 1, e=(1.0/pow(10,7));
	while(fabs(wyraz) > e){
		wyraz = 1.0/(i*i);
		suma += wyraz;
		i++;
	}
	printf("Przybli�ona suma to: %lf.\n", suma);
}

/*
	2.20 	Dana jest naturalna liczba n. Znajd�:
	a)		liczb� jej cyfr
	b)		sum� jej cyfr
	c)		pierwsz� (najbardziej znacz�c�) cyfr� tej liczby
*/
void zad_2_20_abc() {
	int n, liczbaCyfr = 0, sumaCyfr=0, ostatnia;
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &n);
	
	printf("Dla danej liczby n=%d.\n", n);
	if(n == 0){
		printf("Podana liczba to 0. Suma cyfr to 0, liczba cyfr to 1, najbardziej znacz�ca to 0.\n");
	} else {
		while(n != 0){				// jak wykonujemy operacje na typie int, to je�li zostanie nam ostatnia liczba z zakresu 0-9, po podzieleniu przez 10 bedzie rowna zero
			liczbaCyfr++;			// przy ka�dym obrocie p�tli zwi�kszamy ilo�� cyfr
			ostatnia = n % 10;		// ze wst�pu do programowania wiemy, �e aby uzyska� skrajnie praw� cyfr� nale�y zwr�ci� reszt� z dzielenia przez 10
			sumaCyfr += ostatnia;	// skoro zwr�cili�my skrajnie praw�, to teraz dodajemy j� do sumy cyfr
			n = n / 10;				// nasze "n" dzielimy przez 10, by w nast�pnej iteracji sprawdzi� co zosta�o
		}
		printf("Liczba cyfr to: %d, suma cyfr to: %d, najbardziej znacz�ca cyfra to: %d.\n",liczbaCyfr,sumaCyfr,ostatnia);
	}
}

/*
	2.18/2.19  Znajd� wszystkie dzielniki/dzielniki pierwsza podanej liczby naturalnej
	
*/
void zad_2_18() {
	int i, n;
	printf("Podaj pierwsz� liczb� naturaln� n:\n");
	scanf("%d", &n);
	printf("Kolejne podzielniki danej liczby n=%d to: \n", n);
	i = 2;
	while(n != 1){
		if(n % i == 0){
			n = n / i;
			printf("%d\n", i);
		} else {
			i++;
		}	
	}
}


// Jest to funkcja pomocnicza u�ywana w zadaniu 2_17 w celu obliczenia NWD
int NWD(int a, int b){
	int i, max, nwd = 1;
	max = a < b ? a : b; 		// zapis ten oznacza, �e je�eli a<b to do zmiennej max podstawiamy "a", w przeciwnym wypadku "b"
	for(i=1; i<=max; i++){		// iteracj� rozpoczynami od 1 poniewa� 0 nie interesuje nas jako dzielnik
		if(a%i==0 && b%i==0){	// je�eli obie liczby dziel� si� przez "i" bez reszty, to znaczy, �e "i" jest ich dzielnikiem
			nwd=i;
		}
	}
	return nwd;	
}

/*
	2.17  	Wczytaj dwie liczby naturalne i znajdz:
	a)		najwiekszy wspolny dzielnik tych liczb (NWD)
	b)		najmniejsz� wsp�ln� wielokrotno�� tych liczb (NWW)
	
	Znaj�c NWD mo�na �atwo obliczy� NWW ze wzoru NWW(a,b)=a*b/NWD(a,b)
	
*/
void zad_2_17_ab() {
	int i, a, b, nww=0, nwd=1, pomocznicza;
	printf("Podaj pierwsz� liczb� naturln� a:\n");
	scanf("%d", &a);
	printf("Podaj drug� liczb� naturaln� b:\n");
	scanf("%d", &b);
	if(a == b){
		printf("Liczby a=%d i b=%d s� sobie r�wne wi�c ich s� ich w�asnymi NWW i NWD.\n",a,b);
	} else if (a==0 || b==0){
		printf("Co najmniej jedna z podanych liczb jest r�wna 0, wi�c nie maj� ani NWW ani NWD.\n");
	} else {
		nwd=NWD(a,b);
		nww=a*b/nwd;
		printf("Liczby a=%d i b=%d maj� NWD=%d i NWW=%d.\n",a,b,nwd,nww);
	}
	
}



/*
	2.16  Sprawd� czy wczytane trzy liczby rzeczywise, dodatnie a,b,c mog� tworzy� tr�jk�t, tzn. czy spe�nione s� jednocze�nie relacje:
		a<b+c, b<c+a, c<b+a
	
*/
void zad_2_16() {
	double a, b, c;
	printf("Podaj pierwsz� liczb� rzeczywist� a:\n");
	scanf("%lf", &a);
	printf("Podaj drug� liczb� rzeczywist� b:\n");
	scanf("%lf", &b);
	printf("Podaj trzeci� liczb� rzeczywist� c:\n");
	scanf("%lf", &c);
	if(a<b+c && b<c+a && c<b+a){
		printf("Podane liczby mog� utworzyc tr�jk�t.\n");
	} else {
		printf("Nie da rady.\n");
	}
}


// Jest to funkcja pomocnicza u�ywana w zadaniu 2_15 w celu obliczenia sumy dzielnik�w danej liczby
int suma_dzielnikow(int liczba){
	int i, suma = 0;
	if(liczba == 1){
		return 1;
	}
	i = 2;
	while(liczba != 1){
		if(liczba % i == 0){
			suma+=i;
			liczba/=i;
		} else {
			i++;
		}
	}
	return suma;
}
		


/*
	2.15  	Znajd� naturaln� liczb� nale��c� do przedzia�u 1-10000, kt�rej suma podzielnik�w jest maksymalna - co to s� podzielniki?
			W matematyce s� tylko dzielniki.
			
			UWAGA! 1 nie jest uznawana ani za liczb� pierwsz�, ani z�o�on� - nie wyst�puje w rozk�adzie na czynniki pierwsze
	
			Sprawdzator liczb pierwszych: https://calculla.pl/liczba_pierwsza
	
*/
void zad_2_15() {
	int i, min = 1, max = 10000, pomocnicza = 0, maksymalna = 0, liczba;
	for(i = min; i <= max; i++){
		pomocnicza = suma_dzielnikow(i);		// w tym wierszu wo�amy dodatkow� funkcj� "suma_dzielnikow", kt�ra oblicza nam sum� dzielnik�w dla podanej liczby
		if(pomocnicza > maksymalna){			// je�eli obliczona suma jest wi�ksza ni� dotyczasowa,
			maksymalna = pomocnicza;			// to zast�uj�my dotychczasow� sum�
			liczba = i;							// a do zmiennej"liczba" przypisujemy aktualnie sprawdzan� liczb�: i
		}
	}
	printf("Liczba, kt�ra ma najwi�ksz� sum� podzielnik�w r�wn� %d to %d.\n", maksymalna, liczba);
}

/*
	2.14  Sprawd� podzielno�� wczytanej liczby naturalnej n przez zadan� liczb� naturaln� k
	
*/
void zad_2_14() {
	int n, k;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe naturalna k:\n");
	scanf("%d", &k);
	if(n % k == 0){
		printf("n=%d jest podzielne przez k=%d bez reszty.\n",n,k);
	} else {
		printf("n=%d nie jest podzielne przez k=%d bez reszty.\n",n,k);
	}
}

/*
	2.13 	Okre�l ilo�� setek w zadanej liczbie naturalnej n > 99
	
*/
void zad_2_13() {
	int liczba, pomocnicza;
	printf("Podaj liczbe naturalna n > 99:\n");
	scanf("%d", &liczba);
	pomocnicza = liczba/100;	// dzielimy liczb� przez 100 aby pozbyc sie dziesiatek i jednosci
	printf("Ilo�� setek w liczbie n=%d wynosi %d.\n",liczba, pomocnicza % 10); //aby uzyskac ilosc setek zwracamy reszte z dzielenia liczby pomocniczej / 10
}

/*
	2.12 	Sprawd� czy wczytana liczba naturalna jest:
	a)		dodatnia
	b)		parzysta
	c)		podzielna przez 3
*/
void zad_2_12_abc() {
	int liczba;
	printf("Podaj liczbe naturalna:\n");
	scanf("%d", &liczba);
	
	// podpunkt a
	if(liczba > 0){
		printf("Liczba %d jest dodatnia.\n", liczba);
	} else {
		printf("Liczba %d nie jest dodatnia.\n", liczba);
	}
	
	//podpunkt b
	if(liczba % 2 == 0){
		printf("Liczba %d jest parzysta.\n", liczba);
	} else {
		printf("Liczba %d nie jest parzysta.\n", liczba);
	}
	
	//podpunkt c
	if(liczba % 3 == 0){
		printf("Liczba %d jest podzielna przez 3 bez reszty.\n", liczba);
	} else {
		printf("Liczba %d nie jest podzielna przez 3 bez reszty.\n", liczba);
	}
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	g)		1*2 + 2*3*4 + ... + n*(n-1)*...*2n	nie kumam tego zapisu

*/
void zad_2_11_g() {
	printf("Chwa�a �mia�kom co to zrobi�.\n");
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	f)		sin x + sin^2 x + ... + sin^n x	
	
	aby rozwi�za� to zadanie nale�y u�y� do�� mocno rozbudowanej sumy szeregu, wi�c sobie podaruj� =)
	wi�cej informacji tutaj: http://mathworld.wolfram.com/TrigonometricPowerFormulas.html
*/
void zad_2_11_f() {
	printf("Chwa�a �mia�kom co to zrobi�.\n");
}


/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	e)		1/x + 1/x^2 + 1/x^4 + ... + 1/x^2n	
	
	Biblioteka <math.h> udost�pnia nam funkcj� pow(), kt�ra umo�liwia podniesienie liczby do dowolnej pot�go
	double pow (double x, double y);  x - liczba podnoszona do pot�gi, y - wyk�adnik pot�gi, typ przyjmowanych/zwracanych danych to double.
*/
void zad_2_11_e() {
	int i, n;
	double x, wynik;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe rzeczywista x:\n");
	scanf("%lf", &x);
	wynik = 1.0/x;
	for(i=1; i <= n; i++){
		wynik+=1.0/(pow(x,2*i));
	}
	printf("Dla n=%d oraz x=%lf wynikiem dzia�ania 1/x + 1/x^2 + 1/x^4 + ... + 1/x^2n jest %lf.\n",n,x,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	d)		x(x+1)...(x+n-1)	 
*/
void zad_2_11_d() {
	int i, n;
	double x, wynik = 1;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe rzeczywista x:\n");
	scanf("%lf", &x);
	for(i=0;i<n;i++){
		wynik*=(x+i);
	}
	printf("Dla n=%d oraz x=%lf wynikiem dzia�ania x(x+1)...(x+n-1) jest %lf.\n",n,x,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	c)		n!	 
*/
void zad_2_11_c() {
	int i, n, wynik = 1;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	for(i=1; i<=n; i++){
		wynik=wynik*i;
	}
	printf("Dla n=%d n!=%d.\n",n,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	b)		x^n	 
*/
void zad_2_11_b() {
	int i, n;
	double x, wynik;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	printf("Podaj liczbe rzeczywista x:\n");
	scanf("%lf", &x);
	wynik = x;
	if(n==0){
		wynik=1;
	} else {
		for(i=1; i<n; i++){
		wynik*=x;
		}
	}
	printf("Dla n=%d i x=%lf, x^n=%lf.\n",n,x,wynik);
}

/*
	2.11 	Dana jest liczba naturalna n i rzeczywista x(jedna z nich lub obie w zale�no�ci od podpunktu). Oblicz:
	a)		2^n	 
*/
void zad_2_11_a() {
	int i, n, wynik = 2;
	printf("Podaj liczbe naturalna n:\n");
	scanf("%d", &n);
	if(n==0){
		wynik=1;
	} else {
		for(i=1; i<n; i++){
		wynik*=2;
		}
	}
	printf("Dla n=%d, 2^n=%d.\n",n,wynik);
}

/*
	2.10 	Wyznacz pierwiastki dowolnego r�wnania kwadratowego
	
			R�wnanie kwadratowe ma posta�: ax^2 + bx + c = 0; a,b,c znane, x1, x2 - szukane
			
			delta = b^2 - 4ac
			x1 =(-b - sqrt(delta))/2a
			x2 =(-b + sqrt(delta))/2a		 
*/
void zad_2_10() {
	double a,b,c, delta,x1,x2;
	printf("Podaj wsp�czynnik a:\n");	
	scanf("%lf", &a);
	printf("Podaj wsp�czynnik b:\n");	
	scanf("%lf", &b);
	printf("Podaj wsp�czynnik c:\n");
	scanf("%lf", &c);
	delta=b*b-4*a*c;
	if(delta < 0){
		printf("Delta mniejsza od 0, sprzeczno�� - r�wnanie nie posiada pierwastk�w.\n");
	} else if (delta == 0){
		x1=x2=(-b*1.0)/(2*a);
		printf("Delta = 0, r�wnanie ma jeden pierwiastek podw�jny x1=x2=%lf.\n",x1);
	} else {
		x1=(-b-sqrt(delta))*1.0/(2*a);
		x2=(-b+sqrt(delta))*1.0/(2*a);
		printf("Delta > 0, r�wnanie ma dwa pierwiastki x1=%lf, x2=%lf.\n",x1,x2);
	}
}

/*
	2.9 	Napisz program realizuj�cy:
	b)		dzielenie 2 liczb naturalnych
			je�li na komputerze mo�liwe jest tylko dodawanie, odejmowanie i operacje logiczne typu sprawdzenia czy a=b, a>b lub a<b

			Liczby naturalne - liczby ca�kowite i dodatnie liczone od 0
			
			Zak�adamy, �e dzielimy pierwsz� liczb� przez drug�: a/b
			Je�eli operujemy na typach ca�kowitoliczbowych, to z g�ry mo�emy za�o�y�, �e je�li a=1 a b=2, a zatem a<b to wynikiem dzielenia a/b b�dzie 0
			
*/
void zad_2_9_b() {
	int i, a, b, pomocnicza, wynik = 0;				
	printf("Podaj pierwsz� liczb�:\n");	
	scanf("%d", &a);
	printf("Podaj drug� liczb�:\n");	
	scanf("%d", &b);
	if(a < b){
		printf("Wynikiem dzielenia a=%d / b=%d jest 0.\n",a,b);
	} else if(a==b){
		printf("Wynikiem dzielenia a=%d / b=%d jest 1, bo liczby s� sobie r�wne.\n",a,b);

	} else {
		pomocnicza = b;				// W zmiennej "pomocnicza" dodajemy do siebie kolejno "b" przez kt�re dzielimy, dop�ki jest ono mniejsze od "a"
		while(pomocnicza < a){
			pomocnicza+=b;			// w ka�dym kolejnym obrocie p�tli do pomocniczej dodajemy b
			wynik++;				// wynik m�wi nam o tym ile razy dodali�my do siebie "b" zanim przekroczyli�my warto�� "a"
		}
		printf("Wynik dzielenia a=%d / b=%d = %d.\n",a,b,wynik);
	}	
}

/*
	2.9 	Napisz program realizuj�cy:
	a)		mno�enie 2 liczb naturalnych
			je�li na komputerze mo�liwe jest tylko dodawanie, odejmowanie i operacje logiczne typu sprawdzenia czy a=b, a>b lub a<b

			Liczby naturalne - liczby ca�kowite i dodatnie liczone od 0
			
			Mno�enie liczb to inaczej ich dodawanie, np. 3*4 = 3+3+3+3, 2*5 = 2+2+2+2+2, mo�emy wi�c za�o�y�,
			�e druga z liczb b�dzie licznikiem p�tli.
			
*/
void zad_2_9_a() {
	int i,a,b, wynik = 0;				// Dobr� praktyk� jest inicjalizowa� licznik/wynik konkretn� liczb� - w tym przypadku 0, unikniemy inicjalizacji losow� liczb�
	printf("Podaj pierwsz� liczb�:\n");	
	scanf("%d", &a);
	printf("Podaj pierwsz� liczb�:\n");	
	scanf("%d", &b);
	for(i = 0; i < b; i++){
		wynik+=a;
	}
	printf("a=%d * b=%d = %d.\n",a,b,wynik);	
}

/*
	2.8 	Napisz program realizuj�cy odejmowanie 2 liczb naturalnych, przy czym odjemnik jest mniejszy od odjemnej,
			je�li na komputerze mo�liwe jest tylko dodawanie i operacje logiczne typu sprawdzenia czy a=b, a>b lub a<b
			
			odjemna - liczba, od kt�rej odejmujemy liczb�
			odjemnik - liczba, kt�r� odejmujemy od odjemnej
			
			Liczby naturalne - liczby ca�kowite i dodatnie liczone od 0
			
			W tym zadaniu aby obliczy� r�nic� wykorystamy p�tl� for i zmienn� r�nica,
			kt�rej warto�� b�dzie si� zwi�ksza� o 1 za ka�dym obrotem p�tli,
			dop�ki mniejsza z liczb nie zr�wna si� z wi�ksz�.
			
			W ten spos�b przy wykorzystaniu dodawania obliczymy r�nic� 2 liczb.
			 
*/
void zad_2_8() {
	int i,a,b,roznica = 0;
	printf("Podaj pierwsz� liczb� naturaln� a:\n");	
	scanf("%d", &a);
	printf("Podaj drug� liczb� naturaln� b:\n");	
	scanf("%d", &b);
	if(a < b){
		for(i = a; i < b; i++){
			roznica++;
		}
		printf("Roznica w odejmowaniu b-a=%d, gdzie a=%d, a b=%d.\n",roznica,a,b);
	} else if (b < a){
			for(i = b; i < a; i++){
			roznica++;
		}
		printf("Roznica w odejmowaniu a-b=%d, gdzie a=%d, a b=%d.\n",roznica,a,b);
	} else {
		printf("Liczby s� sobie r�wne a=%d, b=%d.\n",a,b);
	}
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	d)		sum� kwadrat�w tych liczb
		
*/
void zad_2_7_d() {
	int i, iloscLiczb;
	double liczba, sumaKwadratow = 0;
	printf("Podaj ile chcialby� wczyta� liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczb� z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		sumaKwadratow+=(liczba*liczba);
	}
	printf("Suma odwrotno�ci podanych liczb to: %lf.\n", sumaKwadratow);
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	c)		sum� odwrotno�ci
	
	Dla pewno�ci, �e nie zgubimy cz�ci dziesi�tnej przy obliczaniu odwrotno�ci dzielimy 1.0/liczb� a nie 1/liczb�
	
*/
void zad_2_7_c() {
	int i, iloscLiczb;
	double liczba, sumaOdwrotnosci = 0;
	printf("Podaj ile chcialby� wczyta� liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczb� z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		sumaOdwrotnosci+=1.0/liczba;
	}
	printf("Suma odwrotno�ci podanych liczb to: %lf.\n", sumaOdwrotnosci);
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	b)		ich �redni� arytmetyczn�
	
*/
void zad_2_7_b() {
	int i, iloscLiczb;
	double liczba, suma = 0;
	printf("Podaj ile chcialby� wczyta� liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczb� z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		suma+=liczba;
	}
	printf("�rednia arytmetyczna podanych liczb to: %lf.\n", suma/iloscLiczb);
}

/*
	2.7 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i oblicz:
	a)		ich sum�
	
*/
void zad_2_7_a() {
	int i, iloscLiczb;
	double liczba, suma = 0;
	printf("Podaj ile chcialby� wczyta� liczb:\n");	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczb� z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		suma+=liczba;
	}
	printf("Suma podanych liczb to: %lf.\n", suma);
}

/*
	2.6 	Wydrukuj tabliczk� mno�enia w zakresie od 1 do 100
	
			Polecenie jest nie�cis�e, zak�adamy, �e b�dzie to tabliczka mno�enia od 1 - 10 
			z warto�ciami ko�cz�cymi si� na 100.
			
			i - wiersz, j - kolumna
			
*/
void zad_2_6() {
	unsigned int i, j, min = 1, max = 10;
	for(i = 1; i <= 10; i++){				// Iterowanie po wierszach zaczynamy od 1, poniewa� nie interesuje nas 0
		for(j = 1; j <= 10; j++){			// z iterowaniem po kolumnach jest dok�adnie tak samo
			if(i == 1){						// je�eli jeste�my w 1-wszym wierszu, to nie chcemy mno�yc, chcemy tylko wydrukowa� kolejne liczby
				printf(" %d ", j);
			} else if (j == 1){				// je�eli jeste�my w 1-wszej kolumnie, to r�wnie� nie chcemy mno�y�, tylko drukowa� liczby
				printf(" %d ", i);
			} else {						// je�eli jeste�my w ka�dym innym polu, to wykonujemy mno�enie
				printf(" %d ", i*j);
			}
		}
		printf("\n");						// po przej�ciu przez wszystkie kolumny w wierszu przechodzimy do nowej linii
	}
}

/*
	2.5 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i wybierz spo�r�d nich:
	b)		najmniejsz�
	
	Biblioteka <math.h> umo�liwia nam u�ycie sta�ej +niesko�czono�� lub -niesko�czono��,
	zapisujemy j� jako INFINITY (lub odpowiednio -INFINITY) i jest typu double
	
*/
void zad_2_5_b() {
	int i, iloscLiczb;
	double liczba, najmniejsza = INFINITY;				// pocz�tkowo do zmiennej najmniejsza przypisujemy warto�� niesko�czono��, 
	printf("Podaj ile chcialby� wczyta� liczb:\n");		// by mie� z czym por�wna� pierwsz� odczytan� liczb�	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczb� z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		if(liczba  < najmniejsza){
			najmniejsza = liczba;
		}
	}
	printf("Najmniejsza liczba ze zbioru podanych liczb to %lf.\n", najmniejsza);
}

/*
	2.5 	Wczytaj n kolejnych liczb rzeczywistych (double lub float) i wybierz spo�r�d nich:
	a)		najwi�ksz�
	
	Biblioteka <math.h> umo�liwia nam u�ycie sta�ej +niesko�czono�� lub -niesko�czono��,
	zapisujemy j� jako INFINITY (lub odpowiednio -INFINITY) i jest typu double
	
*/
void zad_2_5_a() {
	int i, iloscLiczb;
	double liczba, najwieksza = -INFINITY;				// pocz�tkowo do zmiennej najwi�ksza przypisujemy warto�� minus niesko�czono��, 
	printf("Podaj ile chcialby� wczyta� liczb:\n");		// by mie� z czym por�wna� pierwsz� odczytan� liczb�	
	scanf("%d", &iloscLiczb);
	for(i = 0; i < iloscLiczb; i++){
		printf("Podaj %d liczb� z %d liczb:\n", i+1, iloscLiczb);		
		scanf("%lf", &liczba);
		if(liczba  > najwieksza){
			najwieksza = liczba;
		}
	}
	printf("Najwi�ksza liczba ze zbioru podanych liczb to %lf.\n", najwieksza);
}

/*
	2.4 	Oblicz przebyt� drog� w ruchu jednostajnym, je�li znane s� warto�ci czasu (t) i pr�dko�ci(v)
	
	droga - S = v * t, zak�adaj�c kompatybilne jednostki


*/
void zad_2_4() {
	double t, v, S;
	printf("Podaj czas w sekundach t:\n");		
	scanf("%lf", &t);
	printf("Podaj pr�dko�� w m/s v:\n");		
	scanf("%lf", &v);
	S = v * t;
	printf("Poruszaj�c si� z pr�dko�ci� v=%lf m/s przez t=%lf sekund przeb�dziemy drog� S=%lf metr�w.\n", v, t, S);
}

/*
	2.3 	Oblicz obj�to��:
	d) 		kuli
	
	Obj�to�� kuli maj�c dane r - promie�: (4/3)*PI*r^3

*/
void zad_2_3_d() {
	double r, objetosc;
	printf("Podaj promie� kuli r:\n");		
	scanf("%lf", &r);
	objetosc = (4.0/3)*M_PI*r*r*r;
	printf("Objeto�� kuli o promieniu r=%lf jednostek wynosi %lf jednostek.\n", r, objetosc);
}

/*
	2.3 	Oblicz obj�to��:
	c) 		sto�ka
	
	Obj�to�� sto�ka maj�c dane r - promie� podstawy i H - wysoko��: (1/3)*PI*r^2*H
	
	UWAGA! Je�li wykonuj�c dzielenie 1/3 nie napiszemy 1.0/3 to wynik z tego dzielenia b�dzie r�wny 0, gdy� potraktujemy liczby jako typ int
	1/3 = 0 reszta 3 -> 0

*/
void zad_2_3_c() {
	double r, H, objetosc;
	printf("Podaj promie� podstawy sto�ka r:\n");		
	scanf("%lf", &r);
	printf("Podaj wysokosc sto�ka H:\n");		
	scanf("%lf", &H);
	objetosc = (1.0/3)*M_PI*r*r*H;			// 
	printf("Objeto�� sto�ka o promieniu r=%lf, wysoko�ci H=%lf jednostek wynosi %lf jednostek.\n", r, H, objetosc);
}

/*
	2.3 	Oblicz obj�to��:
	b) 		prostopadloscianu
	
	Obj�to�� prostopad�o�cianu: a*b*H

*/
void zad_2_3_b() {
	double a, b, H, objetosc;
	printf("Podaj d�ugo�� krawedzi podstawy prostopadloscianu a:\n");		
	scanf("%lf", &a); 								// przypisanie do zmiennej "a" warto�ci podanej przez u�ytkownika
	printf("Podaj d�ugo�� krawedzi podstawy prostopadloscianu b:\n");		
	scanf("%lf", &b); 								// przypisanie do zmiennej "b" warto�ci podanej przez u�ytkownika,
	printf("Podaj wysokosc prostopadloscianu H:\n");		
	scanf("%lf", &H); 								// przypisanie do zmiennej "b" warto�ci podanej przez u�ytkownika,
	objetosc = a*b*H;										// obliczenie pola
	printf("Objeto�� prostopadloscianu o bokach a=%lf, b=%lf, H=%lf jednostek wynosi %lf jednostek.\n", a, b, H, objetosc);
}

/*
	2.3 	Oblicz obj�to��:
	a) 		sze�cianu - dane jest d�ugo�� boku

*/
void zad_2_3_a() {
	double a, objetosc;
	printf("Podaj d�ugo�� boku sze�cianu a:\n");		
	scanf("%lf", &a); 								
	objetosc = a*a*a;			// obliczenie objetosci szescianu
	printf("Objetosc szescianu o boku a=%lf jednostek wynosi %lf jednostek.\n", a, objetosc);
}

/*
	2.2 	Oblicz pole powierzchni:
	d) 		okr�gu, gdy znany jest jego promie�
	
	Pole ko�a - znaj�c jego promien r  wynosi PI*r^2
	
	Dodanie biblioteki <math.h> umo�liwi nam skorzystanie ze sta�ej PI, aby z niej skorzysta� u�ywamy sta�ej M_PI

*/
void zad_2_2_d() {
	double r, pole;								// u�ywamy double, bo przyblizenie liczby PI jest zmiennoprzecinkowe
	printf("Podaj promie� okr�gu r:\n");		
	scanf("%lf", &r); 								// przypisanie do zmiennej "r" warto�ci podanej przez u�ytkownika
	pole = M_PI*r*r;								// obliczenie pola
	printf("Pole ko�a o promieniu r=%lf jednostek wynosi %lf jednostek.\n", r, pole);
}

/*
	2.2 	Oblicz pole powierzchni:
	c) 		prostok�ta
	
	Pole prostok�ta - znaj�c jego d�ugo�� boku 'a' oraz 'b' wynosi a*b

*/
void zad_2_2_c() {
	double a, b, pole;
	printf("Podaj d�ugo�� boku a prostok�ta:\n");		
	scanf("%lf", &a); 								// przypisanie do zmiennej "a" warto�ci podanej przez u�ytkownika
	printf("Podaj d�ugo�� boku b prostok�ta:\n");		
	scanf("%lf", &b); 								// przypisanie do zmiennej "b" warto�ci podanej przez u�ytkownika,
	pole = a*b;										// obliczenie pola
	printf("Pole prostok�ta o bokach a=%lf, b=%lf jednostek wynosi %lf jednostek.\n", a, b, pole);
}

/*
	2.2 	Oblicz pole powierzchni:
	b) 		kwadratu - dana jest d�ugo�� boku a
	
	Pole tr�jk�ta - znaj�c jego d�ugo�ci bok�w 'a', 'b' i 'c', gdzie p - polowa obwodu tego� tr�jk�ta p = (a + b + c)\2 wynosi:
	P = sqrt(p(p-a)(p-b)(p-c)) (wz�r Herona), gdzie sqrt oznacza pierwiastek kwadratowt z wyra�enia w nawiasie
	
	Dzi�ki u�yciu biblioteki <math.h> mo�emy u�y� funkcji sqrt(), kt�ra oblicza pierwiastek kwadratowy z danej liczby
	double sqrt(double x) - funkcja sqrt przyjmuje jako argument liczb� typu double i zwraca jako wynik liczb� typu double

*/
void zad_2_2_b() {
	double a, pole;								// u�ywamy double, tak po prostu
	printf("Podaj d�ugo�� boku kwadratu a:\n");		
	scanf("%lf", &a); 								
	pole = a*a;			// obliczenie pola dowolnego tr�jk�ta
	printf("Pole kwadratu o boku a=%lf jednostek wynosi %lf jednostek.\n", a, pole);
}

/*
	2.2 	Oblicz pole powierzchni:
	a) 		dowolnego tr�jk�ta - dane s� jego d�ugo�ci bok�w
	
	Pole tr�jk�ta - znaj�c jego d�ugo�ci bok�w 'a', 'b' i 'c', gdzie p - polowa obwodu tego� tr�jk�ta p = (a + b + c)\2 wynosi:
	P = sqrt(p(p-a)(p-b)(p-c)) (wz�r Herona), gdzie sqrt oznacza pierwiastek kwadratowt z wyra�enia w nawiasie
	
	Dzi�ki u�yciu biblioteki <math.h> mo�emy u�y� funkcji sqrt(), kt�ra oblicza pierwiastek kwadratowy z danej liczby
	double sqrt(double x) - funkcja sqrt przyjmuje jako argument liczb� typu double i zwraca jako wynik liczb� typu double

*/
void zad_2_2_a() {
	double a, b, c, p, pole;						// u�ywamy double, bo w operacji pierwiastkowania spodziewamy si� wynik�w zmiennoprzecinkowych
	printf("Podaj d�ugo�� boku tr�jk�ta a:\n");		
	scanf("%lf", &a); 								
	printf("Podaj d�ugo�� boku tr�jk�ta b:\n");		
	scanf("%lf", &b); 
	printf("Podaj d�ugo�� boku tr�jk�ta c:\n");		
	scanf("%lf", &c); 
	p = (a+b+c)/2;								// definiujemy sobie zmienn� pomocnicz� p r�wn� po�owie obwodu tr�jk�ta, w celu wi�kszej czytelno�ci dzia�a�
	pole = sqrt(p*(p-a)*(p-b)*(p-c));			// obliczenie pola dowolnego tr�jk�ta
	printf("Pole dowolnego tr�jk�ta o bokach a=%lf, b=%lf, c=%lf jednostek wynosi %lf jednostek.\n", a, b, c, pole);
}


/*
	2.1 	Oblicz obw�d:
	d) 		okr�gu, gdy znany jest jego promie�
	
	Obw�d okr�gu - znaj�c jego promien r  wynosi 2*PI*r
	
	Dodanie biblioteki <math.h> umo�liwi nam skorzystanie ze sta�ej PI, aby z niej skorzysta� u�ywamy sta�ej M_PI

*/
void zad_2_1_d() {
	double r, obwod;								// u�ywamy double, bo przyblizenie liczby PI jest zmiennoprzecinkowe
	printf("Podaj promie� okr�gu r:\n");		
	scanf("%lf", &r); 								// przypisanie do zmiennej "r" warto�ci podanej przez u�ytkownika
	obwod = 2*M_PI*r;								// obliczenie obwodu
	printf("Obw�d okr�gu o promieniu r=%lf jednostek wynosi %lf jednostek.\n", r, obwod);
}

/*
	2.1 	Oblicz obw�d:
	c) 		prostok�ta
	
	Obw�d prostok�ta - znaj�c jego d�ugo�� boku 'a' oraz 'b' wynosi 2*(a+b)

*/
void zad_2_1_c() {
	unsigned int a, b, obwod;						// u�ywamy unsigned int, bo d�ugo�� boku ani obw�d nie mog� by� ujemne
	printf("Podaj d�ugo�� boku a prostok�ta:\n");		
	scanf("%u", &a); 								// przypisanie do zmiennej "a" warto�ci podanej przez u�ytkownika
	printf("Podaj d�ugo�� boku b prostok�ta:\n");		
	scanf("%u", &b); 								// przypisanie do zmiennej "b" warto�ci podanej przez u�ytkownika,
	obwod = 2*(a+b);								// obliczenie obwodu
	printf("Obw�d prostok�ta o bokach a=%u, b=%u jednostek wynosi %u jednostek.\n", a, b, obwod);
}

/*
	2.1 	Oblicz obw�d:
	b) 		kwadratu
	
	Obw�d kwadratu - znaj�c jego d�ugo�� boku 'a' wynosi  4*a

*/
void zad_2_1_b() {
	unsigned int a, obwod;							// u�ywamy unsigned int, bo d�ugo�� boku ani obw�d nie mog� by� ujemne
	printf("Podaj d�ugo�� kwadratu a:\n");		
	scanf("%u", &a); 								// przypisanie do zmiennej "a" warto�ci podanej przez u�ytkownika,
	obwod = 4*a;									// obliczenie obwodu
	printf("Obw�d kwadratu o boku a=%u jednostek wynosi %u jednostek.\n", a, obwod);
}


/*
	2.1 	Oblicz obw�d:
	a) 		tr�jk�ta r�wnobocznego
	
	Obw�d tr�jk�ta r�wnobocznego - znaj�c jego d�ugo�� boku 'a' wynosi 3*a

*/
void zad_2_1_a() {
	unsigned int a, obwod;							// u�ywamy unsigned int, bo d�ugo�� boku ani obw�d nie mog� by� ujemne
	printf("Podaj d�ugo�� boku tr�jk�ta a:\n");		
	scanf("%u", &a); 								// przypisanie do zmiennej "a" warto�ci podanej przez u�ytkownika,
	obwod = 3*a;									// obliczenie obwodu
	printf("Obw�d tr�jk�ta r�wnobocznego o boku a=%u jednostek wynosi %u jednostek.\n", a, obwod);
}

int main(int argc, char *argv[]) {
	//zad_2_1_a();
	//zad_2_1_b();
	//zad_2_1_c();
	//zad_2_1_d();
	//zad_2_2_a();
	//zad_2_2_b();
	//zad_2_2_c();
	//zad_2_2_d();
	//zad_2_3_a();
	//zad_2_3_b();
	//zad_2_3_c();
	//zad_2_3_d();
	//zad_2_4();
	//zad_2_5_a();
	//zad_2_5_b();
	//zad_2_6();
	//zad_2_7_a();
	//zad_2_7_b();
	//zad_2_7_c();
	//zad_2_7_d();
	//zad_2_8();
	//zad_2_9_a();
	//zad_2_9_b();
	//zad_2_10();
	//zad_2_11_a();
	//zad_2_11_b();
	//zad_2_11_c();
	//zad_2_11_d();
	//zad_2_11_e();
	//zad_2_11_f();
	//zad_2_11_g();
	//zad_2_12_abc();
	//zad_2_13();
	//zad_2_14();
	//zad_2_15();
	//zad_2_16();
	//zad_2_17_ab();
	//zad_2_18(); // zadanie 2.19 zostaje pomini�te, w zwi�zku z brakiem jasnej definicji jaka jest r�nica mi�dzy podzielnikiem, a podzielnikiem pierwszym
	//zad_2_20_abc();
	//zad_2_21_a();
	//zad_2_21_b();
	//zad_2_21_c();
	//zad_2_21_d();
	//zad_2_22_ab();
	//zad_2_23();
	//zad_2_24_ab();
	//zad_2_25();
	//zad_2_26();
	//zad_2_27();
	//zad_2_28();
	zad_2_29();



	return 0;
}
