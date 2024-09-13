#ifndef EMPLOYE_H
#define EMPLOYE_H

#include "Personne.h"

class Employe : public Personne
{
public:
  Employe(const std::string& p_prenom, const std::string& p_nom, int p_age, const std::string& p_company, const std::string& p_position);
  Employe(Personne& p_personne, const std::string& p_company, const std::string& p_position);
  const std::string& reqCompany() const;
  const std::string& reqPosition() const;
  int reqID() const;
  friend std::ostream& operator<<(std::ostream& os, const Employe& e);
  std::string reqEmployeFormate(Personne p);
  void operator()(int p_newAge, const std::string& p_newPosition);
private:
  std::string m_company;
  std::string m_position;
  int m_ID;
};

#endif // --Employe