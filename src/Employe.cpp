#include "Employe.h"

#include <iostream>

Employe::Employe(const std::string& p_prenom, const std::string& p_nom, int p_age, const std::string& p_company, const std::string& p_position):
  Personne(p_age, p_prenom, p_nom), m_company(p_company), m_position(p_position)
{
  std::cout << "Cette personne est un employe\n";
  m_ID = reqNombrePersonnes();
}

Employe::Employe(Personne& p_personne, const std::string& p_company, const std::string& p_position):
  Personne(p_personne.reqAge(), p_personne.reqPrenom(), p_personne.reqNom()),
  m_company(p_company), m_position(p_position)
{
  std::cout << "Cette personne est un employe\n";
  m_ID = reqNombrePersonnes();
}

const std::string& Employe::reqCompany() const
{
  return m_company;
}

const std::string& Employe::reqPosition() const
{
  return m_position;
}

int Employe::reqID() const
{
  return m_ID;
}

std::ostream& operator<<(std::ostream& os, const Employe& e)
{
  os << e.reqPrenom() << ' ' << e.reqNom() << ", " << e.reqAge() << " ans\n";
  os << e.reqCompany() << ", " << e.reqPosition() << ", ID: " << e.reqID();
  return os;
}

std::string Employe::reqEmployeFormate(Personne p)
{
  std::ostringstream os;
  os << p.reqPersonneFormate();
  os << "company: " << m_company << ", position: " << m_position << '\n';
  os << "ID: " << m_ID << '\n';
  return os.str();
}

void Employe::operator()(int p_newAge, const std::string& p_newPosition)
{
  asgAge(p_newAge);
  m_position = p_newPosition;
}
