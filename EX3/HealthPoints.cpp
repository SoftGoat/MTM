#include "HealthPoints.h"

HealthPoints::HealthPoints(int health) {
    try {
        if (health <= MINIMUM_MAX_HEALTH) {
            throw HealthPoints::InvalidArgument();
        }
        m_health = health;
        m_maxHealth = health;
    } catch (const std::invalid_argument& e) {
        m_health = DEFAULT_HEALTH;
        m_maxHealth = DEFAULT_HEALTH;
    }
}

HealthPoints::HealthPoints() {
    m_health = DEFAULT_HEALTH;
    m_maxHealth = DEFAULT_HEALTH;
}

HealthPoints::HealthPoints(const HealthPoints& health) {
    m_health = health.m_health;
    m_maxHealth = health.m_maxHealth;
}


HealthPoints HealthPoints::operator+(const int health){
    HealthPoints newHealth = *this;
    newHealth.m_health += health;
    if (newHealth.m_health > newHealth.m_maxHealth) {
        newHealth.m_health = newHealth.m_maxHealth;
    }
    if (newHealth.m_health < newHealth.MINIMUM_MAX_HEALTH) {
        newHealth.m_health = newHealth.MINIMUM_MAX_HEALTH;
    }
    return newHealth;
}

HealthPoints HealthPoints::operator-(const int health){
    HealthPoints newHealth = *this;
    newHealth.m_health -= health;
    if (newHealth.m_health > newHealth.m_maxHealth) {
        newHealth.m_health = newHealth.m_maxHealth;
    }
    if (newHealth.m_health < newHealth.MINIMUM_MAX_HEALTH) {
        newHealth.m_health = newHealth.MINIMUM_MAX_HEALTH;
    }
    return newHealth;
}





HealthPoints& HealthPoints::operator=(const HealthPoints& health) {
    m_health = health.m_health;
    m_maxHealth = health.m_maxHealth;
    return *this;
}


HealthPoints& HealthPoints::operator+=(const int health) {
    m_health += health;
    if (m_health > m_maxHealth) {
        m_health = m_maxHealth;
    }
    if (m_health < MINIMUM_MAX_HEALTH) {
        m_health = MINIMUM_MAX_HEALTH;
    }
    return *this;
}



HealthPoints& HealthPoints::operator-=(const int health) {
    m_health -= health;
    if (m_health < MINIMUM_MAX_HEALTH) {
        m_health = MINIMUM_MAX_HEALTH;
    }
    if (m_health > m_maxHealth) {
        m_health = m_maxHealth;
    }
    return *this;
}

const bool HealthPoints::operator==(const HealthPoints& health) const {
    return m_health == health.m_health;
}

const bool HealthPoints::operator!=(const int health) const {
    return m_health != health;
}

const bool HealthPoints::operator!=(const HealthPoints& health) {
    return m_health != health.m_health;
}

const bool HealthPoints::operator<(const int health) const {
    return m_health < health;
}

const bool HealthPoints::operator<(const HealthPoints& health) const {
    return m_health < health.m_health;
}

const bool HealthPoints::operator>(const int health) const {
    return m_health > health;
}

const bool HealthPoints::operator>(const HealthPoints& health) const {
    return m_health > health.m_health;
}

const bool HealthPoints::operator<=(const int health) const {
    return m_health <= health;
}

const bool HealthPoints::operator<=(const HealthPoints& health) const {
    return m_health <= health.m_health;
}

const bool HealthPoints::operator>=(const int health) const {
    return m_health >= health;
}

const bool HealthPoints::operator>=(const HealthPoints& health) const {
    return m_health >= health.m_health;
}

HealthPoints operator+(const int health, const HealthPoints& healthPoints) {
    HealthPoints newHealth = healthPoints;
    newHealth.m_health += health;
    if (newHealth.m_health > newHealth.m_maxHealth) {
        newHealth.m_health = newHealth.m_maxHealth;
    }
    if (newHealth.m_health < newHealth.MINIMUM_MAX_HEALTH) {
        newHealth.m_health = newHealth.MINIMUM_MAX_HEALTH;
    }
    return newHealth;
}



bool operator==(const int health, const HealthPoints& healthPoints) {
    return health == healthPoints.m_health;
}

std::ostream& operator<<(std::ostream& os, const HealthPoints& health) {
    os << health.m_health << "(" << health.m_maxHealth << ")";
    return os;
}

bool operator>(const int health1, const HealthPoints& health2) {
    return health1 > health2.m_health;
}

bool operator<(const int health1, const HealthPoints& health2) {
    return health1 < health2.m_health;
}
