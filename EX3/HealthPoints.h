#include <iostream>
#include <string>

class HealthPoints {
public:
    // Constructors
    HealthPoints(); // Default constructor
    HealthPoints(const int health); // Parameterized constructor
    HealthPoints(const HealthPoints& health); // Copy constructor

    // Arithmetic operators
    HealthPoints operator+(const int health);
    HealthPoints operator-(const int health);
    HealthPoints& operator=(const HealthPoints& health);
    HealthPoints& operator+=(const int health);
    HealthPoints& operator-=(const int health);

    // Comparison operators
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

    // Friend functions for non-member operators
    friend std::ostream& operator<<(std::ostream& os, const HealthPoints& health);
    friend bool operator>(const int health1, const HealthPoints& health2);
    friend bool operator<(const int health1, const HealthPoints& health2);
    friend HealthPoints operator+(const int health1, const HealthPoints& health2);
    friend bool operator==(const int health1, const HealthPoints& health2);

    // Exception class for invalid arguments
    class InvalidArgument {};

private:
    // Private member variables
    int m_health;
    int m_maxHealth;
    static const int MINIMUM_MAX_HEALTH = 0;
    static const int DEFAULT_HEALTH = 100;
};
