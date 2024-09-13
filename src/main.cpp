#include "Employe.h"

#include <iostream>

using namespace std;

int main()
{
  Personne p0;
  cout << p0.reqPersonneFormate();
  
  p0.asgPrenom("John");
  p0.asgNom("Wick");
  p0.asgAge(42);
  cout << "Apres initialisation: "<< '\n';
  cout << p0.reqPersonneFormate();
  
  cout << "Nombre de personnes: " << Personne::reqNombrePersonnes() << '\n';
  
  Personne p1=p0;
  cout << "Personne p1=p0" << '\n';
  cout << p1.reqPersonneFormate();
  
  cout << "Nombre de personnes: " << Personne::reqNombrePersonnes() << '\n';
  
  Personne p2(50, "Keanu", "Reaves");
  cout << p2.reqPrenom() << ' ' << p2.reqNom() << ", " << p2.reqAge() << " ans\n";
  
  cout << "Nombre de personnes: " << Personne::reqNombrePersonnes() << '\n';
  
  Personne p3;
  string input("Jack Reacher 51");
  istringstream in(input);
  in >> p3;  // si "cin" utilisé il faut entrer prenom, nom et age.
  cout << p3 << '\n';
  
  cout << "Nombre de personnes: " << Personne::reqNombrePersonnes() << '\n';
  
  Employe e0("Ethan", "Hunt", 61, "MIF", "Field Agent");
  cout << e0 << '\n';
  cout << e0.reqEmployeFormate((Personne)e0);
  
  cout << (p0 == p1) << '\n';
  cout << (p2 < p3) << '\n';
  
  Employe e1(p3, "Special Forces", "Seargent" );
  cout << e1 << '\n';
  
  e0(55, "Undercover Spy");
  cout << e0 << '\n';
  
  return 0;
}