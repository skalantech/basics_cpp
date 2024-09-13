#include "Personne.h"

#include <iostream>

int Personne::nombrePersonnes = 0;

Personne::Personne(int p_age, const std::string& p_prenom, const std::string& p_nom):
  m_age(p_age), m_prenom(p_prenom), m_nom(p_nom)
{
  ++Personne::nombrePersonnes;
  std::cout << "Objet " << reqNombrePersonnes() << " construit" << '\n';
}

Personne::Personne(const Personne& personne): 
  m_age(personne.m_age), m_prenom(personne.m_prenom), m_nom(personne.m_nom)
{
  ++Personne::nombrePersonnes;
  std::cout << "Objet " << reqNombrePersonnes() << " COPIE construit" << '\n';
}

Personne::~Personne()
{
  std::cout << "Objet " << reqNombrePersonnes() << " detruit" << '\n';
  --Personne::nombrePersonnes;
}

std::string Personne::reqPersonneFormate()
{
  std::ostringstream os;
  os << "nom: " << m_nom << ", prenom: " << m_prenom << '\n';
  os << "age: " << m_age << '\n';
  return os.str();
}

int Personne::reqAge() const
{
  return m_age;
}

const std::string& Personne::reqPrenom() const
{
  return m_prenom;
}

const std::string& Personne::reqNom() const
{
  return m_nom;
}

void Personne::asgAge(int p_age)
{
  m_age = p_age;
}

void Personne::asgPrenom(const std::string& p_prenom)
{
  m_prenom = p_prenom;
}

void Personne::asgNom(const std::string& p_nom)
{
  m_nom = p_nom;
}

int Personne::reqNombrePersonnes()
{
  return Personne::nombrePersonnes;
}

std::ostream& operator<<(std::ostream& os, const Personne& p)
{
  os << p.reqPrenom() << ' ' << p.reqNom() << ", " << p.reqAge() << " ans";
  return os;
}

std::istream& operator>>(std::istream& is, Personne& p)
{
  is >> p.m_prenom >> p.m_nom >> p.m_age;
  return is;
}

bool Personne::operator==(Personne& personne)
{
  return m_age==personne.m_age && m_prenom==personne.m_prenom && m_nom==personne.m_nom;
}

bool Personne::operator>(Personne& personne)
{
  return m_age>personne.m_age;
}

bool Personne::operator<(Personne& personne)
{
  return !operator>(personne);
}