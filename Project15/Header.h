#pragma once

class A
{
public:
    int publiczny;  // Mozna uzyskac dostep z dowolnego miejsca
    void methodA(); // Metoda publiczna, dostepna z dowolnego miejsca
private:
    int prywatny;   // Dostepny tylko wewnatrz klasy A
protected:
    int chroniony;  // Dostepny w klasie A oraz jej klasach pochodnych

};

class B : private A
{
public:
    int publicznyB; // Dostepny jako publiczny czlonek B
    void methodB(); // Metoda publiczna klasy B
private:
    int prywatnyB;  // Prywatny czlonek B, dostepny tylko wewnatrz B
protected:
    int chronionyB; // Chroniony czlonek B, dostepny w B i klasach pochodzacych od B

};

class C : private B
{
public:
    int publicznyC; // Dostepny jako publiczny czlonek C
    void methodC(); // Metoda publiczna klasy C
private:
    int prywatnyC;  // Prywatny czlonek C, dostepny tylko wewnatrz C
protected:
    int chronionyC; // Chroniony czlonek C, dostepny w C i klasach pochodzacych od C

};
