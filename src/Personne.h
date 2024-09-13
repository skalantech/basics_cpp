#ifndef PERSONNE_H
#define PERSONNE_H

#include <sstream>

class Personne
{
public:
  Personne(int p_age=0, const std::string& p_prenom="", const std::string& p_nom="");
  Personne(const Personne& personne);
  ~Personne();
  std::string reqPersonneFormate();
  int reqAge() const;
  const std::string& reqPrenom() const;
  const std::string& reqNom() const;
  void asgAge(int p_age);
  void asgPrenom(const std::string& p_prenom);
  void asgNom(const std::string& p_nom);
  static int reqNombrePersonnes();
  friend std::ostream& operator<<(std::ostream& os, const Personne& p);
  friend std::istream& operator>>(std::istream& is, Personne& p);
  bool operator==(Personne& personne);
  bool operator>(Personne& persone);
  bool operator<(Personne& persone);
  
private:
  int m_age;
  std::string m_prenom;
  std::string m_nom;
  static int nombrePersonnes;
};

#endif  // --Personne