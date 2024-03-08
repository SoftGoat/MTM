#include <iostream>
#include <string>

class HealthPoints {
public:
    HealthPoints();
    HealthPoints(const int health);
    HealthPoints(const HealthPoints& health); // copy constructor
    /*
   HealthPoints& operator+(const int health);
    HealthPoints& operator+(const HealthPoints& health);
    HealthPoints& operator-(const int health);
    HealthPoints& operator-(const HealthPoints& health);  */
    HealthPoints& operator=(const HealthPoints& health);
    HealthPoints& operator+=(const int health);
    HealthPoints& operator+=(const HealthPoints& health);
    HealthPoints& operator-=(const int health);
    HealthPoints& operator-=(const HealthPoints& health);
    const bool operator==(const HealthPoints& health) const;
    const bool operator!=(const int health) const;
    const bool operator!=(const HealthPoints& health);
    const bool operator<(const int health) const;
    const bool operator<(const HealthPoints& health) const;
    const bool operator>(const int health) const;
    const bool operator>(const HealthPoints& health) const;
    const bool operator<=(const int health) const;
    const bool operator<=(const HealthPoints& health) const;
    const bool operator>=(const int health) const;
    const bool operator>=(const HealthPoints& health) const;

    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& health);
    friend bool operator>(const int health1, const HealthPoints& health2);
    friend bool operator<(const int health1, const HealthPoints& health2);
    friend HealthPoints operator+(const int health1, const HealthPoints& health2);
    friend HealthPoints operator+(const HealthPoints& health1, const int health2);
    friend HealthPoints operator-(const int health1, const HealthPoints& health2);
    friend HealthPoints operator-(const HealthPoints& health1, const int health2);
    friend bool operator==(const int health1, const HealthPoints& health2);

    class InvalidArgument {};

private:
    int m_health;
    int m_maxHealth;
    const int MINIMUM_MAX_HEALTH = 0;
    const int DEFAULT_HEALTH = 100;
};
