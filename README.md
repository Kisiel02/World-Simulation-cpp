# Język polski użyty w opisie oraz w kodzie spowodowany jest wymaganiami na uczelni.

### Symulacja świata
 Prosta symulacja świata w c++ (projekt na studia)  
Projekt ten wykonałem w czasie drugiego semestru studiów, czyli w pierwszej części 2020 roku  
Niektóre rozwiązania musiały być napisane specjalnie pod wymagania projektu
### Krótki opis projektu
Projekt ten jest prostą symulacją świata. Ma ona charakter turowej rozgrywki, gdzie możemy poruszać się strzałkami postacią człowieka posród zwierząt i roślin.
### Dokładny opis
#### Ogólne
* Kazdy znak na planszy oznacza inny organizm. Organizmy przy pojawieniu się na tym samym polu kolidują ze sobą
* W każdej turze zwierzę porusza się w określony sposób, a roślina ma szansę na rozmnożenie się
* Przy kolizji zwierząt tego samego gatunku rozmnażają się one
* Przy kolizji wygrywa zwierzę z większą siła, a słabsze ginie
* Przy równej sile atakujący staje na innej pozycji
* O kolejności akcji decyduje _inicjatywa_ (tym wieksza tym szybciej podejmie akcje dany organizm)
* W przypadku równej _inicjatywy_, decyduje kolejność pojawienia się na planszy
* Akcją zwierząt jest ruch, a roślin próba rozmożenia
#### Intefejs
* Aby zapisać grę do pliku, należy wcisnąc _z_
* Aby wczytać zapisany stan gry, należy wcisnąć na początku gry _wczytaj świat z pliku_
* Kliknięcie strzałki powoduje zasymulowanie nowej tury oraz ruch człowieka w wybranym kierunku
* Przycisk _Moc specjalna_ aktywuje moc specjalna człowieka, ktorą jest poruszanie się o 2 pola naraz przez 5 tur
* Wszystkie wydarzenia z gry umieszczane są w dolnej części konsoli
#### Poruszanie
* Aby poruszyć się postacią człowieka, oznaczonego '**H**' na planszy, należy za pomocą strzałki wybrać kierunek ruchu.  
#### Właściwości organizów
* Właściwości poszczególnych zwierząt:
  * Człowiek **C**
    * Sterowany przez gracza
    * Siła 5
    *  Inicjatywa 4
  * Wilk **W**
    * Siła 9
    * Inicjatywa 5
  * Owca **O**
    * Siła 4
    * Inicjatywa 4 
  * Lis **L**
    * Siła 3
    * Inicjatywa 7
    * Nigdy nie poruszy się na pole, na którym stoi silniejszy organizm
  * Zółw **Z**
    * Siła 2
    * Inicjatywa 1
    * Ma 75% szansy na pozostanie w miejscu
    * Odbija ataki zwierząt o sile mniejszej niż 5
  * Antylopa **A**
    * Siła 4
    * Inicjatywa 4 
    * Poruszą a się o dwa pola naraz
    * Ma 50% szansy na ucieczkę od walki. Staje wtedy na losowym, sąsiednim polu
   
  **Inicjatywa wszystkich roślin wynosi 0. W czasie akcji rośliyn podejmują próbę rozmnożenia na sąsiednie, wolne pole**
* Właściwości roślin
  * Trawa **T**
    * Siła 0
  * Mlecz **N**
    * Siła 0
    * Podejmuje 3 próby rozmnożenia w jednej turze
  * Guarana **G**
    * Siła 0
    * Siła zwierzęcia, które zje guaranę, pernamentnie wzrasta o 3
  * Wilcze jagody **J**
    * Siła 99
    * Zabija każde zwierzę, które je zje
  * Barszcz Sosnowskiego **B**
    * Siła 10
    * Zabija każde zwierzę, które stoi obok 
    * Zabije każde zwierzę, które je zje
